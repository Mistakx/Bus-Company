#include <iostream>

#include "passengers.h"

using namespace std;

struct Passenger_number {

	int number = 0;
	Passenger_number* next = NULL;

};

struct Bus_stop {

	string name = "";
	Passenger_number* passenger_numbers = NULL;
	Bus_stop* next = NULL;

};

struct Bus_stops {

	Bus_stop* bus_stops = NULL;
	int amount = 0; // The amount of bus stops
};

void initialize_bus_stops(Bus_stops* bus_stops, Names* bus_stop_names);

void print_bus_stops(Bus_stops* bus_stops);