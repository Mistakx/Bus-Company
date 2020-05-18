#include <iostream>

#include "files.h"

using namespace std;

struct Passenger {

	string first_name = "";
	string last_name = "";
	int ticket_number = 0;
	Passenger* next = NULL;

};

struct Passengers {

	Passenger* passengers = NULL;
	Passenger* last_passenger = NULL;
	int quantity = 0;

};

void initialize_passenger(Passenger* passenger, Names* first_names, Names* passenger_last_names);

void initialize_queue(Passengers* queue, Names* first_names, Names* passenger_last_names);

Passengers* remove_amount_from_queue(Passengers* queue, int amount);

void print_passengers(Passengers* passengers);