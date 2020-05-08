#include <iostream>
#include <stdlib.h> 
#include <time.h>

#include "Header.h"


using namespace std;

string fist_name_location = "C:\\Users\\Mistakx\\Desktop\\primeiro_nome.txt";
string last_name_location = "C:\\Users\\Mistakx\\Desktop\\ultimo_nome.txt";

int main() {

    locale::global(locale("Portuguese"));
    srand(time(NULL));


    // Initialize Names
    Names* first_names = new Names;
    Names* last_names = new Names;

    name_parsing(fist_name_location, first_names);
    name_parsing(last_name_location, last_names);
    //print_nodes(last_names); //! Debug
    //cout << last_names->quantity; //!Debug


    // Initialize Queue
    Queue* waiting_queue = new Queue;
    initialize_queue(waiting_queue, first_names, last_names);
    //print_queue(waiting_queue); //!Debug
    //cout << waiting_queue->quantity; //!Debug
    
    // Initialize Buses

    /*
    while (waiting_queue->queue != NULL) {

        Bus* bus = new Bus;
        bus->capacity = rand() % 4 + 9; // Generates a random number between 9 and 12 (including both)
        
    }
    */
    

}

