#include <iostream>

#include "passengers.h"

using namespace std;

struct Passenger_number {

	int number = 0;
	Passenger_number* next = NULL;

};

struct Ticket_number {

	int root = 0;
	Ticket_number* left = NULL;
	Ticket_number* right = NULL;

};

struct Bus_stop {

	wstring name = L"";
	Passenger_number* ticket_numbers = NULL;
	Bus_stop* next = NULL;

};

struct Bus_stops {

	Bus_stop* bus_stops = NULL;
	int amount = 0; // The amount of bus stops
};

void initialize_bus_stops(Bus_stops* bus_stops, Names* bus_stop_names);

void print_bus_stops(Bus_stops* bus_stops);

