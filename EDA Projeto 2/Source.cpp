#include <iostream>

#include "Header.h"

using namespace std;


void print_nodes(Names* names) {
	
	Node* temp_node = names->names;

	cout << "Linked List" << endl << endl;

	while (temp_node != NULL) {

		cout << temp_node->node << endl;
		temp_node = temp_node->next;

	}
	
}