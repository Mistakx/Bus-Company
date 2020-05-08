#include <iostream>

#include "files.h"

using namespace std;

struct Node {

	string node = "";
	Node* next = NULL;

};

struct Names {

	Node* names = new Node;
	int quantity = 0;

};


struct Passanger {

	string first_name = "";
	string last_name = "";
	int ticket_number = 0;

};

void name_parsing(string file_path, Names* names);

void print_nodes(Names* names);