#include <iostream>

#include "Header.h"

using namespace std;


void print_nodes(Names* names) {
	
	Node* temp_node = names->names;

	cout << "Linked List" << endl << endl;

	while (temp_node != NULL) {

		cout << temp_node->data << endl;
		temp_node = temp_node->next;

	}
	
}

void initialize_queue(Queue* queue) {
	

	for (int i = 0; i < 30; i++) {



	}

}

void initialize_passenger(Passenger* passenger, Names* first_names, Names* last_names) {

	// Initialize First Name
	Node* temp_node = first_names->names;

	for (int i = 0; i < (rand() % first_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	passenger->first_name = temp_node->data;


	// Initialize Last Name
	temp_node = last_names->names;

	for (int i = 0; i < (rand() % last_names->quantity); i++) {
		temp_node = temp_node->next;
	}
	passenger->last_name = temp_node->data;


}