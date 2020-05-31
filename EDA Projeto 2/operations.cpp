#include <iostream>

#include "operations.h"

using namespace std;

void move_buses_to_next_stop(Bus_stops* bus_stops, Buses* buses) {

	Bus_stop* temp_bus_stop_node = bus_stops->bus_stops->next;
	Bus* temp_bus_node = buses->buses;

	for (int i = 1; (i < bus_stops->amount); i++) {

		temp_bus_stop_node->bus = temp_bus_node;

		temp_bus_stop_node = temp_bus_stop_node->next;
		
		// In the first iteration, the first node won't have any next nodes
		if (temp_bus_node != NULL) {
			temp_bus_node = temp_bus_node->next;

		}
	}

	// Delete last bus if necessary
	if (buses->amount == bus_stops->amount) {

		temp_bus_node = buses->buses;

		while (temp_bus_node->next->next != NULL) {
			temp_bus_node = temp_bus_node->next;
		}

		delete temp_bus_node->next;
		temp_bus_node->next = NULL;


	}

}

void add_bus(Buses* buses, Bus_stops* bus_stops, Passengers* queue, Names* first_names, Names* last_names) {

	// Adds bus to buses
	Bus* new_node = new Bus;
	initialize_bus(new_node, queue, first_names, last_names);
	new_node->next = buses->buses;
	buses->buses = new_node;

	if (buses->amount < bus_stops->amount) {
		buses->amount++;
	}

	// Adds bus to bus stop
	bus_stops->bus_stops->bus = new_node;

}

Ticket_number* add_ticket_to_bus_stop(Ticket_number* root, int ticket_number) {

	if (root == NULL) {

		Ticket_number* new_node = new Ticket_number;
		new_node->ticket_number = ticket_number;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;


	}

	if (ticket_number < root->ticket_number) {

		root->left = add_ticket_to_bus_stop(root->left, ticket_number);
		
	}

	else {

		root->right = add_ticket_to_bus_stop(root->right, ticket_number);

	}

	return root;
}

void passengers_exit_bus(Bus_stop* bus_stop, Passengers* queue, Bus_stops* bus_stops) {

	Passenger* temp_node = bus_stop->bus->passengers->passengers;

	// First passenger
	if ((rand() % 4) == 0) {

		bus_stop->bus->passengers->passengers = bus_stop->bus->passengers->passengers->next;
		bus_stop->bus->passengers->quantity--;
		bus_stop->ticket_numbers = add_ticket_to_bus_stop(bus_stop->ticket_numbers, temp_node->ticket_number);
		wcout << "O passageiro " << temp_node->ticket_number << " saiu do autocarro." << endl;

		delete temp_node;
	}

	temp_node = bus_stop->bus->passengers->passengers; // Needs to be defined again in case the first passenger is removed

	// Second passenger and beyond
	for (int i = 1; i < bus_stop->bus->passengers->quantity; i++) {

		if ((rand() % 4) == 0) {

			Passenger* node_to_delete = temp_node->next;
			temp_node->next = temp_node->next->next;
			bus_stop->bus->passengers->quantity--;
			bus_stop->ticket_numbers = add_ticket_to_bus_stop(bus_stop->ticket_numbers, node_to_delete->ticket_number);
			wcout << "O passageiro " << node_to_delete->ticket_number << " saiu do autocarro." << endl;

			delete node_to_delete;
		}
		
		temp_node = temp_node->next;

	}

}

void passengers_exit_buses(Bus_stops* bus_stops, Buses* buses, Passengers* queue) {

	Bus_stop* temp_node = bus_stops->bus_stops;

	for (int i = 0; i < buses->amount; i++) {

		refresh_console(queue, bus_stops);

		wcout << L"Trying to remove passengers from bus number: " << i << endl << endl; // DEBUG

		// DEBUG
		wcout << "Antes da remoção" << endl;
		print_passengers(temp_node->bus->passengers);
		wcout << endl << endl;

		passengers_exit_bus(temp_node, queue, bus_stops);

		// DEBUG
		wcout << endl;
		wcout << "Após a remoção" << endl;
		print_passengers(temp_node->bus->passengers);
		system("Pause");

		temp_node = temp_node->next;

	}

}

void create_new_passengers(Passengers* queue, Names* first_names, Names* last_names) {

	Passenger* temp_node = queue->passengers;

	while (temp_node->next != NULL) { // If there was no passengers in the queue, this would throw an exception, but it's garanteed that the queue is always growing

		temp_node = temp_node->next;

	}

	// TODO: Check implementation


	// Creates 15 new passengers and puts them in the passenger waiting queue.
	for (int i = 0; i < 15; i++) {

		Passenger* new_node = new Passenger;
		initialize_passenger(new_node, first_names, last_names);
		temp_node->next = new_node;
		queue->quantity++;
		temp_node = temp_node->next;

	}

}

void next_step(Buses* buses, Bus_stops* bus_stops, Passengers* queue, Names* first_names, Names* last_names) {

	//! Moves all buses to the next stop
	move_buses_to_next_stop(bus_stops, buses);

	//! Adds bus to first stop
	add_bus(buses, bus_stops, queue, first_names, last_names);

	//! Random passagengers from each bus leave at the bus stop
	passengers_exit_buses(bus_stops, buses, queue);

	//! Adds 15 passengers to the waiting queue
	create_new_passengers(queue, first_names, last_names);


}	