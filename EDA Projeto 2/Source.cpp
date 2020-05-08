#include <iostream>

#include "Header.h"

using namespace std;


void print_nodes(Names* names) {
	
	Name* temp_node = names->names;

	cout << "Linked List" << endl << endl;

	while (temp_node != NULL) {

		cout << temp_node->name << endl;
		temp_node = temp_node->next;

	}
	
}

void print_queue(Queue* queue) {

	Passenger* temp_node = queue->queue;

	while (temp_node != 0) {

		cout << temp_node->first_name << " " << temp_node->last_name << " - " << temp_node->ticket_number <<endl;
		temp_node = temp_node->next;
	}

}

void initialize_queue(Queue* queue, Names* first_names, Names* last_names) {
	



	// First Passenger
	queue->queue = new Passenger; // Create new passenger from scratch.
	Passenger* temp_node = queue->queue;

	initialize_passenger(temp_node, first_names, last_names);
	queue->quantity++;

	// Second Passenger and Beyond
	for (int i = 0; i < 29; i++) {

		temp_node->next = new Passenger; // Create new node, linked with the previous.

		initialize_passenger(temp_node->next, first_names, last_names);
		queue->quantity++;

		temp_node = temp_node->next;

	}

}

void initialize_passenger(Passenger* passenger, Names* first_names, Names* last_names) {

	// Initialize First Name
	Name* temp_node = first_names->names;

	for (int i = 0; i < (rand() % first_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	passenger->first_name = temp_node->name;


	// Initialize Last Name
	temp_node = last_names->names;

	for (int i = 0; i < (rand() % last_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	passenger->last_name = temp_node->name;

	//TODO: Initialize Ticket Number
	

}