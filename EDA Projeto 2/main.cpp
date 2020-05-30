#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <windows.h>
#include <iomanip>

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

    // If all files opened successfully
    if ( (first_names->quantity != 0) && (last_names->quantity != 0) && (bus_stop_names->quantity != 0) ) {

        //! Initialize passengers
        Passengers* passenger_queue = new Passengers;
        initialize_queue(passenger_queue, first_names, last_names);


        //! Initialize bus stops
        Bus_stops* bus_stops = new Bus_stops;
        initialize_bus_stops(bus_stops, bus_stop_names);

        //! Allocate memory for buses
        Buses* buses = new Buses;


        while (true) {

            refresh_console(passenger_queue, bus_stops);

            // Buses
            //print_buses(buses); // DEBUG

            wcout << "1 - Próximo passo" << endl
                << "2 - Opções" << endl;
            int option = 0;
            cin >> option;
            switch (option)
            {

            case 1: next_step(buses, bus_stops, passenger_queue, first_names, last_names);
                break;

            case 2: options_menu(passenger_queue, bus_stops, buses);
                break;

            default:
                break;
            }

        }
    }

    else { wcout << "Os ficheiros de inicialização não abriram de forma correta." << endl; }
}

// TODO: Not enough bus stop names in file
// TODO: Check if any bus stop names repeat