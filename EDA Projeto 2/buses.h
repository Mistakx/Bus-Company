#include <iostream>

#include "passengers.h"

using namespace std;

struct Bus_driver {

	wstring first_name = L"";
	wstring last_name = L"";

};

struct Bus {

	Passengers* passengers = NULL;
	int capacity = 0;
	Bus_driver driver;
	int licence_plate = 0;
	Bus* next = NULL;

};

struct Buses {

	Bus* buses = NULL;
	int amount = 0; // The amount of buses

};

bool ticket_number_already_exists_in_buses(int ticket_number, Buses* buses);

void initialize_bus(Bus* bus, Passengers* queue, Names* first_names, Names* last_names);

void print_buses(Buses* buses);

