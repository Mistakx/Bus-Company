#include <iostream>
#include <iomanip>

#include "buses.h"

using namespace std;


void initialize_bus(Bus* bus, Passengers* queue, Names* first_names, Names* last_names) {

	//! Initializing capacity
	bus->capacity = rand() % 6 + 5; // Generates a random number between 5 and 10 (including both)
	
	
	cout << endl << "Initialized bus capacity: " << bus->capacity << endl;
	system("Pause");
	


	//! Placing passengers from waiting queue
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


	//! Initializing driver
		// Initialize First Name
	Name* temp_node = first_names->names;

	for (int i = 0; i < (rand() % first_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	bus->driver.first_name = temp_node->name;


		// Initialize Last Name
	// TODO: Check implementation
	temp_node = last_names->names;

	for (int i = 0; i < (rand() % last_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	bus->driver.last_name = temp_node->name;

	//! Initialize license plate
	
	bus->licence_plate = rand() % 65535 + 4096;
	//cout << "Initializing Licence Plate Int: " <<  bus->licence_plate << endl; // DEBUG
	//cout << "Initializing Licence Plate Hex: " << hex << bus->licence_plate << endl << dec; // DEBUG
	
	
}

void print_bus(Bus* bus) {

	cout << "Capacity: " << bus->capacity << endl;
	wcout << "Driver: " << bus->driver.first_name << " " << bus->driver.last_name << endl;
	cout << "Passengers:" << endl;
	print_passengers(bus->passengers);

}

void initialize_buses(Buses* buses, Passengers* queue, Names* first_names, Names* last_names) {

	int bus_number = 1;

	// Initializes the first bus
	buses->buses = new Bus;
	Bus* temp_node = buses->buses;
	
	//cout << "Initializing bus number: " << bus_number << endl << endl; // DEBUG
	initialize_bus(temp_node, queue, first_names, last_names);
	//print_bus(temp_node); //! DEBUG

	while (queue->quantity > 0) {

		temp_node->next = new Bus;
		bus_number++;
		cout << "Initializing bus number: " << bus_number << endl << endl;
		initialize_bus(temp_node->next, queue, first_names, last_names);
		print_bus(temp_node->next); //! DEBUG
		temp_node = temp_node->next;

	}

}

// DEBUG
void print_buses(Buses* buses) {

	Bus* temp_node = buses->buses;

	while (temp_node != NULL) {

		wcout << hex << temp_node->licence_plate << "->" << dec;

		temp_node = temp_node->next;

	}

	cout << endl;

}
