#include <iostream>

#include "bus_stops.h"

using namespace std;

void initialize_bus_stop(Bus_stop* bus_stop, Names* bus_stop_names) {

	int position_of_bus_stop_name = rand() % (bus_stop_names->quantity); // Chooses the position of a random name to give to the bus stop

	Name* temp_node = bus_stop_names->names;

	// If bus stop name is the first node
	if (position_of_bus_stop_name == 0) {

		bus_stop->name = bus_stop_names->names->name;

		bus_stop_names->names = bus_stop_names->names->next;
		delete temp_node;
		bus_stop_names->quantity--;

	}


	//TODO: Check if implementation is correct
		// If bus stop name isn't the first node
	else {

		for (int i = 0; i < (position_of_bus_stop_name); i++) {
			temp_node = temp_node->next;
		}
		bus_stop->name = temp_node->next->name;
		temp_node->next = temp_node->next->next;
		bus_stop_names->quantity--;

	}
	/*
	// DEBUG
	cout << "Last names after passenger initialization (Removed node " << position_of_last_name << ")" << endl << endl;
	print_names(last_names);
	cout << endl << endl;
	*/

}

void initialize_bus_stops(Bus_stops* bus_stops, Names* bus_stop_names) {

	bus_stops->amount = rand() % 6 + 4; // Generates a random number between 4 and 9 (including both)
	cout << "Bus stops to initialize: " << bus_stops->amount << "." << endl; // DEBUG

	//! Initialize first bus stop
	bus_stops->bus_stops = new Bus_stop;
	initialize_bus_stop(bus_stops->bus_stops, bus_stop_names);
	cout << "Initialized bus stop 0 !" << endl; // DEBUG


	// TODO: Check implementation

	// ! Initialize second bus stop and beyond
	for (int i = 1; i < bus_stops->amount; i++) {

		Bus_stop* temp_node = new Bus_stop;
		initialize_bus_stop(temp_node, bus_stop_names);
		temp_node->next = bus_stops->bus_stops;
		bus_stops->bus_stops = temp_node;

		cout << "Initialized bus stop " << i << " !" << endl; // DEBUG

	}

	cout << "Initialized all bus stops." << endl << endl; // DEBUG







	

}

void print_bus_stops(Bus_stops* bus_stops) {

	Bus_stop* temp_node = bus_stops->bus_stops;

	// TODO: Redo with a for loop
	while (temp_node != NULL) {

		wcout << temp_node->name << endl;
		temp_node = temp_node->next;

	}

}