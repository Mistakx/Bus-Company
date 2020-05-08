#include <iostream>
#include <fstream>
#include <string>

#include "Header.h"

using namespace std;

void name_parsing(string file_path, Names* names) {

    ifstream file(file_path);

    if (file.is_open()) {

        string line = "";


        // First Node
        names->names = new Name; // Create new node from scratch.
        Name* temp_node = names->names;

        getline(file, line);
        temp_node->name = line;
        names->quantity++;
        

        // Second Node and Beyond
        while (getline(file, line)) {

            temp_node->next = new Name; // Create new node, linked with the previous.

            temp_node->next->name = line;
            names->quantity++;

            temp_node = temp_node->next;


        }
        
        file.close();
        
    }

    else {
        cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro não existe, ou está a ser usado por outro processo." << endl << endl;
    }

}