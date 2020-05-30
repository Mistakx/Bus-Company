#include <iostream>
#include <iomanip> 
#include <concepts>

#include "passengers.h"

using namespace std;

void initialize_passenger(Passenger* passenger, Names* first_names, Names* last_names) {

	//! Initialize First Name
	Name* temp_node = first_names->names;

	for (int i = 0; i < (rand() % first_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	passenger->first_name = temp_node->name;


	//! Initialize Last Name
	temp_node = last_names->names;

	for (int i = 0; i < (rand() % last_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	passenger->last_name = temp_node->name;

	//TODO: Check if ticket number is non repeating
	 passenger->ticket_number = rand() % 9000 + 1000; // Generates a random number between 4 and 9 (including both)

}

void initialize_queue(Passengers* queue, Names* first_names, Names* last_names) {

	// First Passenger
	queue->passengers = new Passenger; // Create new passenger from scratch.
	Passenger* temp_node = queue->passengers;
	initialize_passenger(temp_node, first_names, last_names);
	queue->quantity++;

	// Second Passenger and Beyond
	for (int i = 1; i < 30; i++) {

		Passenger* new_node = new Passenger;
		initialize_passenger(new_node, first_names, last_names);
		temp_node->next = new_node;
		queue->quantity++;

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
	int position_in_row = 0;

	while (temp_node != NULL) {

		wstring name_to_print = L""; // Concatenates both names to a single string so setw() can easily be used.

		// First and second elements in row
		if ((position_in_row == 0) || (position_in_row == 1)) {

			name_to_print = temp_node->first_name + L" " + temp_node->last_name;
			wcout << left << setw(22) << name_to_print << setw(6) <<  temp_node->ticket_number << L" | ";
			position_in_row++;

		}

		// Third element in row
		else {
			name_to_print = temp_node->first_name + L" " + temp_node->last_name;
			wcout << left << setw(22) << name_to_print << setw(6)  << temp_node->ticket_number << L" | " << endl;
			position_in_row = 0; // Resets position for the next row

		}

		temp_node = temp_node->next;
	}

}