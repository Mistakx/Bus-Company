#include <iostream>

#include "files.h"

using namespace std;

struct Passenger {

	wstring first_name = L"";
	wstring last_name = L"";
	int ticket_number = 0;
	Passenger* next = NULL;

};

struct Passengers {

	Passenger* passengers = NULL;
	int quantity = 0;

};

bool ticket_number_already_exists_in_queue(int ticket_number, Passengers* queue);

void initialize_passenger(Passenger* passenger, Names* first_names, Names* last_names, int ticket_number);

void initialize_queue(Passengers* queue, Names* first_names, Names* last_names);

Passengers* remove_amount_from_queue(Passengers* queue, int amount);

void print_passengers(Passengers* passengers);
