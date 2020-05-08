#include <iostream>

#include "files.h"

using namespace std;

struct Name {

	string name = "";
	Name* next = NULL;

};

struct Names {

	Name* names = NULL;
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
	int quantity = 0;

};

struct Bus_driver {

	string first_name = "";
	string last_name = "";

};

struct Bus {

	Passenger* passengers = NULL;
	int capacity = 0;
	Bus_driver bus_driver;
	string licence_plate = "";
	Bus* next = NULL;

};




void name_parsing(string file_path, Names* names);

void print_nodes(Names* names);

void initialize_passenger(Passenger* passenger, Names* first_names, Names* last_names);

void initialize_queue(Queue* queue, Names* first_names, Names* last_names);

void print_queue(Queue* queue);