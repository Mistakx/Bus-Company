#include <iostream>

#include "files.h"

using namespace std;

struct Node {

	string data = "";
	Node* next = NULL;

};

struct Names {

	Node* names = new Node;
	int quantity = 0;

};

struct Passenger {

	string first_name = "";
	string last_name = "";
	int ticket_number = 0;
	Passenger* next = NULL;

};

struct Queue {

	Passenger* queue = new Passenger;
	Passenger* first = NULL;
};


void name_parsing(string file_path, Names* names);

void print_nodes(Names* names);

void initialize_passenger(Passenger* passenger, Names* first_names, Names* last_names);