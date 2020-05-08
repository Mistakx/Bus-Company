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

    Names* first_names = new Names;
    Names* last_names = new Names;

    name_parsing(fist_name_location, first_names);
    name_parsing(last_name_location, last_names);

    Queue* waiting_queue = new Queue;


    //print_nodes(last_names); //! Debug
    
    cout << last_names->quantity;

}

