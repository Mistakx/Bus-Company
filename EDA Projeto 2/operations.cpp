#include <iostream>

#include "operations.h"

using namespace std;

void move_bus_to_next_stop(Bus* bus, Bus_stops* bus_stops) {


	// If bus is in a stop that's not the last
	if (bus->bus_stop->next != NULL) {
		bus->bus_stop = bus_stops->bus_stops;
	}

	// If bus is not in a stop yet
	else if (bus->bus_stop == NULL) {
		bus->bus_stop = bus->bus_stop->next;
	}

	// If bus is in the last stop
	else if (bus->bus_stop->next == NULL) {
		bus->bus_stop = bus->bus_stop->next;
	}

}

void move_buses_to_next_stop(Buses* buses, Bus_stops* bus_stops) {

	// Move first bus
	Bus* temp_node = buses->buses;
	move_bus_to_next_stop(temp_node, bus_stops);

	// Move second bus and beyond
	for (int i = 1; buses->amount; i++) {

		move_bus_to_next_stop(temp_node->next, bus_stops);
		temp_node = temp_node->next;

	}



}

void create_new_passengers(Passengers* queue, Names* first_names, Names* last_names) {

	Passenger* temp_node = queue->last_passenger;

	// TODO: Check implementation

	// Creates 15 new passengers and puts them in the passenger waiting queue.
	for (int i = 0; i < 15; i++) {

		temp_node->next = new Passenger; // Create new node, linked with the previous.

		initialize_passenger(temp_node->next, first_names, last_names);
		queue->quantity++;

		temp_node = temp_node->next;


		// Saves the last passenger location in memory to speed up the process of adding new passengers to the queue later.
		if (i == 14) {

			queue->last_passenger = temp_node->next;

		}

	}

}

void remove_from_bus(Bus* bus) {

	Passenger* temp_node = bus->passengers->passengers;

	// First passanger
	// 25% chance of being removed
	if ( (rand() % 3 ) == 0) {

		// TODO: Remove passenger from bus and add it to the bus stop
		
	}

	// Second passanger and beyond
	// TODO: Check implementation
	for (int i = 1; i < bus->passengers->quantity; i++) {

	

		// Each passenger has a 25% chance of being removed
		if ( (rand() % 3) == 0) {

			// TODO: Remove passenger from bus and add it to the bus stop

		}

		temp_node = temp_node->next;

	}

}

void next_step(Buses* buses, Bus_stops* bus_stops) {

	// Moves all buses to the next stop
	move_buses_to_next_stop(buses, bus_stops);

	// Random passagengers from each bus leave at the bus stop

	// Deletes the last bus

	if (buses->amount == bus_stops->amount) {



	}
	


	// Creates a new bus at the beginning
}	