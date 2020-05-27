#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

#include "operations.h"


using namespace std;

string fist_name_location = "C:\\Users\\Mistakx\\Desktop\\primeiro_nome.txt";
string last_name_location = "C:\\Users\\Mistakx\\Desktop\\ultimo_nome.txt";
string bus_stop_names_location = "C:\\Users\\Mistakx\\Desktop\\paragens.txt";

int main() {

    locale::global(locale("pt-PT.utf8"));

    srand(time(NULL));
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);


    //! Initialize Names.
    Names* first_names = new Names;
    Names* last_names = new Names;
    Names* bus_stop_names = new Names;

    parse_names_file(fist_name_location, first_names);
    parse_names_file(last_name_location, last_names);
    parse_names_file(bus_stop_names_location, bus_stop_names);

    
    //cout << "Parsed files." << endl << endl;
    //cout << "Parsed first names:" << endl;
    //print_names(first_names); //! Debug
    //cout << "Parsed first names amount: " << first_names->quantity << endl; //!Debug
    //cout << endl;

    //! Initialize Passengers
    Passengers* passenger_queue = new Passengers;
    initialize_queue(passenger_queue, first_names, last_names);
    cout << "Waiting queue:" << endl << endl;
    print_passengers(passenger_queue);
    cout << "Waiting queue amount: " << passenger_queue->quantity << endl; //!Debug
    cout << endl;

    


    //! Initialize Bus Stops
    Bus_stops* bus_stops = new Bus_stops;
    initialize_bus_stops(bus_stops, bus_stop_names);
    //print_bus_stops(bus_stops); //!DEBUG
    
    /*
    //! Initialize Buses
    Buses* buses = new Buses;
    buses->buses = new Bus;
    buses->amount++;

    initialize_bus(buses->buses, passenger_queue, first_names, last_names);
    */

}

