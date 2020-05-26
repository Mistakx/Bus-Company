#include <iostream>
#include <fstream>
#include <string>

#include "files.h"

using namespace std;

void parse_names_file(string file_path, Names* names) {

    ifstream file(file_path);

    if (file.is_open()) {

        string line = "";

        // TODO: Check implementation

        //! First Node
        names->names = new Name;
        getline(file, line);
        names->names->name = line;
        names->quantity++;

        
        //! Second Node and Beyond
        while (getline(file, line)) {

            Name* temp_node = new Name;
            temp_node->name = line;
            temp_node->next = names->names;
            names->names = temp_node;
            names->quantity++;

        }
        
        file.close();
        
    }

    else {
        cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro não existe, ou está a ser usado por outro processo." << endl << endl;
    }

}

void print_names(Names* names) {

    Name* temp_node = names->names;

    while (temp_node != NULL) {

        cout << temp_node->name << endl;
        temp_node = temp_node->next;

    }

}
