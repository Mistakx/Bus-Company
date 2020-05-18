#include <iostream>

#include "buses.h"

using namespace std;


void initialize_bus(Bus* bus, Passengers* queue, Names* first_names, Names* last_names) {

	//! Initializing capacity
	bus->capacity = rand() % 6 + 5; // Generates a random number between 5 and 10 (including both)
	cout << "Initialized bus capacity: " << bus->capacity << endl
		 << "Remaining number of passengers in queue: " << queue->quantity << endl;


	//! Placing passengers from waiting queue

		// If the bus capacity is smaller or equal to the number of waiting passengers
	if (bus->capacity <= queue->quantity) {

		/*/
		// !DEBUG
		cout << "Queue before entering bus:" << endl;
		print_passengers(queue);
		cout << endl;
		*/

		// Fill bus with passengers 
		bus->passengers = remove_amount_from_queue(queue, bus->capacity);

		/*
		// !DEBUG
		cout << "Initialized Bus Passengers:" << endl;
		print_passengers(bus->passengers);
		cout << endl;
		cout << "Queue after entering bus:" << endl;
		print_passengers(queue);
		cout << endl;
		*/
	}

		// If this was the last bus needed, and the bus capacity is higher than the number of waiting passengers
	else {

		bus->capacity = queue->quantity;
		
		/*
		// !DEBUG
		cout << "Queue before entering bus:" << endl;
		print_passengers(queue);
		cout << endl;
		*/

		// Fill bus with passengers 
		bus->passengers = remove_amount_from_queue(queue, queue->quantity);

		/*
		// !DEBUG
		cout << "Initialized Bus Passengers:" << endl;
		print_passengers(bus->passengers);
		cout << endl;
		cout << "Queue after entering bus:" << endl;
		print_passengers(queue);
		cout << endl;
		*/
	}

	
	//! Initializing driver

		// Initialize First Name
	Name* temp_node = first_names->names;

	for (int i = 0; i < (rand() % first_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	bus->driver.first_name = temp_node->name;


	// Initialize Last Name
	temp_node = last_names->names;

	for (int i = 0; i < (rand() % last_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	bus->driver.last_name = temp_node->name;

	
}

void print_bus(Bus* bus) {

	cout << "Capacity: " << bus->capacity << endl;
	cout << "Driver: " << bus->driver.first_name << " " << bus->driver.last_name << endl;
	cout << "Passengers:" << endl;
	print_passengers(bus->passengers);

}

void initialize_buses(Buses* buses, Passengers* queue, Names* first_names, Names* last_names) {

	int bus_number = 1;

	// Initializes the first bus
	buses->buses = new Bus;
	Bus* temp_node = buses->buses;
	
	cout << "Initializing bus number: " << bus_number << endl << endl;
	initialize_bus(temp_node, queue, first_names, last_names);
	print_bus(temp_node); //! DEBUG

	while (queue->quantity > 0) {

		temp_node->next = new Bus;
		bus_number++;
		cout << "Initializing bus number: " << bus_number << endl << endl;
		initialize_bus(temp_node->next, queue, first_names, last_names);
		print_bus(temp_node->next); //! DEBUG
		temp_node = temp_node->next;

	}

}

	