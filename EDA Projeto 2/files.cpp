#include <iostream>
#include <fstream>
#include <string>

#include "Header.h"

using namespace std;

void name_parsing(string file_path, Names* names) {

    ifstream file(file_path);

    if (file.is_open()) {

        string line = "";
        
        Node* temp_node = names->names;
        
        while (getline(file, line)) {
            names->quantity++;
            temp_node->node = line;
            temp_node->next = new Node;
            temp_node = temp_node->next;
        }
        
        file.close();
        
    }

    else {
        cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl << "O ficheiro não existe, ou está a ser usado por outro processo." << endl << endl;
    }

}