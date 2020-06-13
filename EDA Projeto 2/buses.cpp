#include <iostream>
#include <iomanip>

#include "buses.h"

using namespace std;

bool ticket_number_already_exists_in_buses(int ticket_number, Buses* buses) {

	//! Check buses
	Bus* temp_bus = buses->buses;

	while (temp_bus != NULL) {

		Passenger* temp_passenger = temp_bus->passengers->passengers;

		while (temp_passenger != NULL) {

			if (ticket_number == temp_passenger->ticket_number) {
				return true;
			}

			temp_passenger = temp_passenger->next;

		}

		temp_bus = temp_bus->next;

	}

	return false;

}

void initialize_bus(Bus* bus, Passengers* queue, Names* first_names, Names* last_names) {

	//! Initializing capacity
	bus->capacity = rand() % 6 + 5; // Generates a random number between 5 and 10 (including both)

	/*
	// DEBUG
	cout << "Autocarro inicializado" << endl;
	cout << endl << "Capacidade do autocarro: " << bus->capacity << endl; // DEBUG
	system("Pause"); 
	cout << endl;
	*/

	//! Placing passengers from waiting queue
	if (queue->quantity > 0) {
		bus->passengers = remove_amount_from_queue(queue, bus->capacity);
		// Sets the bus capacity to the number of passengers removed, if every passenger was removed from the queue
		if (queue->quantity == 0) {
			bus->capacity = bus->passengers->quantity;
		}
	}
	else {
		bus->passengers = new Passengers;
		
		cout << "Não existem passageiros na fila de espera para inicializar corretamente o autocarro." << endl;
		system("Pause");
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

	//! Initialize license plate
	
	bus->licence_plate = rand() % 65535 + 4096;
	//wcout << "Initializing Licence Plate Int: " <<  bus->licence_plate << endl; // DEBUG
	//wcout << "Initializing Licence Plate Hex: " << hex << bus->licence_plate << endl << dec; // DEBUG
	
	
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

// DEBUG
void print_buses(Buses* buses) {

	Bus* temp_node = buses->buses;

	while (temp_node != NULL) {

		wcout << hex << temp_node->licence_plate << "->" << dec;

		temp_node = temp_node->next;

	}

	wcout << endl;

}

