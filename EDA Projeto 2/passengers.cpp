#include <iostream>

#include "passengers.h"

using namespace std;

void initialize_passenger(Passenger* passenger, Names* first_names, Names* passenger_last_names) {

	//! Initialize First Name
	Name* temp_node = first_names->names;

	for (int i = 0; i < (rand() % first_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	passenger->first_name = temp_node->name;


	//! Initialize Last Name

	/*
	// DEBUG
	cout << "Last names before passenger initialization" << endl << endl;
	print_names(passenger_last_names);
	cout << endl << endl;
	*/

	int position_of_last_name = rand() % (passenger_last_names->quantity);

	temp_node = passenger_last_names->names;

		// If last name is the first node
	if (position_of_last_name == 0){
	
		passenger->last_name = temp_node->name;
		passenger_last_names->names = passenger_last_names->names->next;
		delete temp_node;
		passenger_last_names->quantity--;

	}


	//TODO: Check if implementation is correct
		// If last name isn't the first node
	else {

		for (int i = 0; i < (position_of_last_name); i++) {
			temp_node = temp_node->next;
		}
		passenger->last_name = temp_node->next->name;
		temp_node->next = temp_node->next->next;
		passenger_last_names->quantity--;

	}
	/*
	// DEBUG
	cout << "Last names after passenger initialization (Removed node " << position_of_last_name << ")" << endl << endl;
	print_names(passenger_last_names);
	cout << endl << endl;
	*/

	//TODO: Initialize Ticket Number


}

void initialize_queue(Passengers* queue, Names* first_names, Names* passenger_last_names) {

	// First Passenger
	queue->passengers = new Passenger; // Create new passenger from scratch.
	Passenger* temp_node = queue->passengers;

	initialize_passenger(temp_node, first_names, passenger_last_names);
	queue->quantity++;

	// TODO: Check implementation
	// Second Passenger and Beyond
	for (int i = 1; i < 30; i++) {

		temp_node->next = new Passenger; // Create new node, linked with the previous.

		initialize_passenger(temp_node->next, first_names, passenger_last_names);
		queue->quantity++;

		// Saves the last passenger location in memory to speed up the process of adding new passengers to the queue later.
		if (i == 29) {

			queue->last_passenger = temp_node->next;

		}

		temp_node = temp_node->next;




	}

}

Passengers* remove_amount_from_queue(Passengers* queue, int amount) { // Removes the first "amount" passengers from a queue


	Passengers* removed_passengers = new Passengers;
	removed_passengers->quantity = amount;
	removed_passengers->passengers = queue->passengers;

	Passenger* temp_node = removed_passengers->passengers;

	for (int i = 1; i < amount; i++) { // It already starts at the first node

		temp_node = temp_node->next;

	}

	queue->passengers = temp_node->next;
	queue->quantity -= amount;
	temp_node->next = NULL;

	return removed_passengers;

}

void print_passengers(Passengers* passengers) {

	Passenger* temp_node = passengers->passengers;

	// TODO: Redo with a for loop
	while (temp_node != 0) {

		cout << temp_node->first_name << " " << temp_node->last_name << " - " << temp_node->ticket_number << endl;
		temp_node = temp_node->next;
	}

}