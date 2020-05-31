#include <iostream>

#include "bus_stops.h"

using namespace std;

void initialize_bus_stop(Bus_stop* bus_stop, Names* bus_stop_names) {

	// ! Position to remove
	//wcout << "Bus stop names left: " << bus_stop_names->quantity; // DEBUG
	int position_of_bus_stop_name = rand() % (bus_stop_names->quantity); // Chooses the position of a random name to give to the bus stop
	//wcout << "      Chosen bus stop name position: " << position_of_bus_stop_name << endl; // DEBUG


	//// DEBUG
	//wcout << "Bus stop names before passenger initialization." << endl << endl;
	//print_names(bus_stop_names);
	//wcout << endl << endl;

	//! Removing the node
	Name* temp_node = bus_stop_names->names;

		// If bus stop name is the first node
	if (position_of_bus_stop_name == 0) {

		// Sets the bus stop name
		bus_stop->name = bus_stop_names->names->name;

		// Deletes the first node
		bus_stop_names->names = bus_stop_names->names->next;
		delete temp_node;
		bus_stop_names->quantity--;

	}

		//TODO: Check if implementation is correct
		// If bus stop name isn't the first node
	else {

		for (int i = 1; i < position_of_bus_stop_name; i++) {
			temp_node = temp_node->next;
		}
		bus_stop->name = temp_node->next->name;
		temp_node->next = temp_node->next->next;
		bus_stop_names->quantity--;
		// TODO: DELETE NODE

	}
	

	//// DEBUG
	//wcout << "Bus stop names after passenger initialization (Removed node " << position_of_bus_stop_name << ")" << endl << endl;
	//print_names(bus_stop_names);
	//wcout << endl << endl;
	

}

void initialize_bus_stops(Bus_stops* bus_stops, Names* bus_stop_names) {

	bus_stops->amount = rand() % 6 + 4; // Generates a random number between 4 and 9 (including both)
	wcout << "Bus stops to initialize: " << bus_stops->amount << "." << endl << endl; // DEBUG

	//! Initialize first bus stop
	bus_stops->bus_stops = new Bus_stop;
	initialize_bus_stop(bus_stops->bus_stops, bus_stop_names);
	//wcout << "Initialized bus stop 0 !" << endl; // DEBUG


	// TODO: Check implementation

	// ! Initialize second bus stop and beyond
	for (int i = 1; i < bus_stops->amount; i++) {

		Bus_stop* temp_node = new Bus_stop;
		initialize_bus_stop(temp_node, bus_stop_names);
		temp_node->next = bus_stops->bus_stops;
		bus_stops->bus_stops = temp_node;

		//wcout << "Initialized bus stop " << i << " !" << endl; // DEBUG

	}

	//wcout << "Initialized all bus stops." << endl << endl; // DEBUG







	

}

void print_bus_passangers(Bus* bus) {

	Passenger* temp_node = bus->passengers->passengers;

	while (temp_node != NULL) {

		wcout << temp_node->first_name << " " << temp_node->ticket_number << ", ";
		temp_node = temp_node->next;

	}

	if (bus->passengers->quantity > 0) { wcout << '\b' << '\b' << '.'; } // Replaces the ',' at the end of the last name with a '.'

	else { wcout << "Não existem passageiros."; }

}

void print_bus_stops(Bus_stops* bus_stops) {

	Bus_stop* temp_node = bus_stops->bus_stops;

	while (temp_node != NULL) {

		wcout << "Paragem: " << temp_node->name << endl;

		// If there's a bus at the stop
		if (temp_node->bus != NULL) {
			wcout << "Autocarro: " << hex << temp_node->bus->licence_plate << " Motorista: " << temp_node->bus->driver.first_name << " " << temp_node->bus->driver.last_name << endl << dec;
			wcout << "Passageiros: ";
			print_bus_passangers(temp_node->bus);
			wcout << endl;
			
		}

		// If there isn't a bus at the stop
		else {

			wcout << "Autocarro: " << "Não existe nenhum autocarro nesta paragem." << endl;

		}

		temp_node = temp_node->next;
		wcout << endl;
	}

}

