#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

#include "options.h"


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
    Names* passenger_last_names = new Names;
    Names* bus_stop_names = new Names;

    parse_names_file(fist_name_location, first_names);
    parse_names_file(last_name_location, last_names);
    parse_names_file(last_name_location, passenger_last_names);
    parse_names_file(bus_stop_names_location, bus_stop_names);

    //print_names(bus_stop_names); //! Debug
    //cout << last_names->amount; //!Debug


    //! Initialize Passengers
    Passengers* passenger_queue = new Passengers;
    initialize_queue(passenger_queue, first_names, passenger_last_names);
    cout << "Waiting queue:" << endl << endl;
    print_passengers(passenger_queue);
    cout << endl;

    //cout << passenger_queue->amount; //!Debug


    //! Initialize Bus Stops
    Bus_stops* bus_stops = new Bus_stops;
    initialize_bus_stops(bus_stops, bus_stop_names);
    print_bus_stops(bus_stops);
    

    //! Initialize First Bus
    Buses* buses = new Buses;



    
    

}

