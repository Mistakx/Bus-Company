#include <iostream>
#include <fstream>
#include <string>

#include "files.h"

using namespace std;

void parse_names_file(string file_path, Names* names) {

    wifstream file(file_path);

    if (file.is_open()) {

        wstring line = L"";

        // TODO: Check implementation

        //! First node
        names->names = new Name;
        getline(file, line);
        names->names->name = line;
        names->quantity++;

        
        //! Second node and beyond - add node to end 
        while (getline(file, line)) {

            Name* temp_node = names->names;

            while (temp_node->next != NULL) {
                temp_node = temp_node->next;
            }

            Name* new_node = new Name;
            new_node->next = NULL;
            new_node->name = line;
            temp_node->next = new_node;
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

        wcout << temp_node->name << endl;
        temp_node = temp_node->next;

    }

}
