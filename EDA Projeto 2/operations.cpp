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
	bool first_passenger_was_removed = false; 
	int passengers_removed = 0;


	// First passenger

	cout << "Passageiro: " << temp_node->ticket_number << endl;

	if ((rand() % 4) == 0) {

		

		bus_stop->bus->passengers->passengers = bus_stop->bus->passengers->passengers->next;
		bus_stop->ticket_numbers = add_ticket_to_bus_stop(bus_stop->ticket_numbers, temp_node->ticket_number);
		passengers_removed++;
		wcout << "O passageiro com o nº " << temp_node->ticket_number << " saiu do autocarro." << endl << endl;

		delete temp_node;
		
		// Since the first passenger was removed
		first_passenger_was_removed = true;
		temp_node = bus_stop->bus->passengers->passengers;

	}

	else {
		first_passenger_was_removed = false; // This code is redundant, but makes it easier to understand what is happening
		wcout << "O passageiro com o nº " << temp_node->ticket_number << " não saiu do autocarro." << endl << endl;
	}

	// Second passenger and beyond
	for (int i = 1; i < bus_stop->bus->passengers->quantity; i++) {

		// DEBUG
		//cout << "I: " << i << endl;
		//cout << "Quantity: " << bus_stop->bus->passengers->quantity << endl;

		if (first_passenger_was_removed) {

			cout << "Passageiro: " << temp_node->ticket_number << endl; // DEBUG

			if ((rand() % 4) == 0) {

				bus_stop->bus->passengers->passengers = bus_stop->bus->passengers->passengers->next;
				bus_stop->ticket_numbers = add_ticket_to_bus_stop(bus_stop->ticket_numbers, temp_node->ticket_number);
				passengers_removed++;
				wcout << "O passageiro com o nº " << temp_node->ticket_number << " saiu do autocarro." << endl << endl;

				delete temp_node;


				// Since the first passenger was removed again
				first_passenger_was_removed = true;
				temp_node = bus_stop->bus->passengers->passengers;
			}

			else {
				first_passenger_was_removed = false;
				wcout << "O passageiro com o nº " << temp_node->ticket_number << " não saiu do autocarro." << endl << endl;
			}
		}			

		else {
			
			// DEBUG
			cout << "Passageiro: " << temp_node->next->ticket_number << endl;
			//cout << "Não é o primeiro passageiro" << endl;
			//cout << "Passageiro seguinte: " << temp_node->next->next->ticket_number << endl;

			if ((rand() % 4) == 0) {
				Passenger* node_to_delete = temp_node->next;
				temp_node->next = temp_node->next->next;
				passengers_removed++;
				bus_stop->ticket_numbers = add_ticket_to_bus_stop(bus_stop->ticket_numbers, node_to_delete->ticket_number);
				wcout << "O passageiro com o nº " << node_to_delete->ticket_number << " saiu do autocarro." << endl << endl;

				delete node_to_delete;
				
				// DEBUG
				//if (temp_node->next != NULL){ cout << "Passageiro mudado para: " << temp_node->next->ticket_number << endl; }
				//else { cout << "Passageiro mudado para: NULL" << endl; }
				
			}

			else {
				wcout << "O passageiro com o nº " << temp_node->next->ticket_number << " não saiu do autocarro." << endl << endl;
				temp_node = temp_node->next;
			}
		}

	

		

	}

	bus_stop->bus->passengers->quantity -= passengers_removed; // If the bus passenger quantity was changed as the passengers were removed the for loop would run into problems

}

void passengers_exit_buses(Bus_stops* bus_stops, Buses* buses, Passengers* queue) {

	Bus_stop* temp_node = bus_stops->bus_stops;

	for (int i = 0; i < buses->amount; i++) {

		refresh_console(queue, bus_stops);

		wcout << L"Autocarro: " << i << endl << endl; // DEBUG

		if (temp_node->bus->passengers->quantity > 0) {
			passengers_exit_bus(temp_node, queue, bus_stops);
		}

		else { 
			cout << "O autocarro " << i << " encontra-se vazio." << endl; 
		}

		system("Pause");
		temp_node = temp_node->next;

		

	}

}

void create_new_passengers(Passengers* queue, Names* first_names, Names* last_names, Buses* buses, Bus_stops* bus_stops) {

	//! If queue isn't empty
	if (queue->quantity > 0) {

		Passenger* temp_node = queue->passengers;

		// Reaches the end of the linked list so it can start adding nodes
		while (temp_node->next != NULL) {

			temp_node = temp_node->next;

		}

		// Creates 15 new passengers and puts them in the passenger waiting queue.
		for (int i = 0; i < 15 ; i++) { 

			Passenger* new_node = new Passenger;

			// Generate non existing random number
			int ticket_number = 0;
			while (true) {
				ticket_number = rand() % 9000 + 1000; // Generates a random number between 1000 and 9999 (including both)			

				// If ticket doesn't already exist in the waiting queue, any bus, or in any bus stop
				if ((ticket_number_already_exists_in_queue(ticket_number, queue) == false)
					&& (ticket_number_already_exists_in_buses(ticket_number, buses) == false)
					&& (ticket_number_already_exists_in_bus_stops(ticket_number, bus_stops) == false)) {

					break;
				}

			}

			initialize_passenger(new_node, first_names, last_names, ticket_number);

			temp_node->next = new_node;
			queue->quantity++;
			temp_node = temp_node->next;

		}

	}

	//! If queue is empty
	if (queue->quantity == 0) {

		int ticket_number = 0;

		// Create first passenger
		queue->passengers = new Passenger;

		// Generate non existing random number
		while (true) {

			ticket_number = rand() % 9000 + 1000; // Generates a random number between 1000 and 9999 (including both)

			// If ticket doesn't already exist in the waiting queue, any bus, or in any bus stop
			if ((ticket_number_already_exists_in_queue(ticket_number, queue) == false)
				&& (ticket_number_already_exists_in_buses(ticket_number, buses) == false)
				&& (ticket_number_already_exists_in_bus_stops(ticket_number, bus_stops) == false)) {

				break;
			}

		}

		initialize_passenger(queue->passengers, first_names, last_names, ticket_number);
		queue->quantity++;

		// Create second passenger and beyond
		Passenger* temp_node = queue->passengers;
		for (int i = 1; i < 15; i++) {

			Passenger* new_node = new Passenger; 

			// Generate non existing random number
			while (true) {
				ticket_number = rand() % 9000 + 1000; // Generates a random number between 1000 and 9999 (including both)

				// If ticket doesn't already exist in the waiting queue, any bus, or in any bus stop
				if ((ticket_number_already_exists_in_queue(ticket_number, queue) == false)
					&& (ticket_number_already_exists_in_buses(ticket_number, buses) == false)
					&& (ticket_number_already_exists_in_bus_stops(ticket_number, bus_stops) == false)) {

					break;
				}

			}

			initialize_passenger(new_node, first_names, last_names, ticket_number);
			temp_node->next = new_node;
			queue->quantity++;

			temp_node = temp_node->next;

		}


	}
	

}

void next_step(Buses* buses, Bus_stops* bus_stops, Passengers* queue, Names* first_names, Names* last_names) {

	//! Adds 15 passengers to the waiting queue
	create_new_passengers(queue, first_names, last_names, buses, bus_stops);

	//! Moves all buses to the next stop
	move_buses_to_next_stop(bus_stops, buses);

	//! Adds bus to first stop
	add_bus(buses, bus_stops, queue, first_names, last_names);

	//! Random passagengers from each bus leave at the bus stop
	passengers_exit_buses(bus_stops, buses, queue);



}	