#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
        cout << "Ocorreu um erro ao tentar abrir \"" << file_path << "\"." << endl;
        wcout << "O ficheiro não existe, ou está a ser usado por outro processo." << endl << endl;
    }

}

// DEBUG
void print_names(Names* names) {

    Name* temp_node = names->names;
    int position_in_row = 0; 

    while (temp_node != NULL) {

        // First and second elements in row
        if ( (position_in_row == 0) || (position_in_row == 1)) {
            
            wcout << left << setw(40) << temp_node->name;
            position_in_row++;

        }

        // Third element in row
        else {
            wcout << left << temp_node->name << endl;
            position_in_row = 0; // Resets position for the next row

        }


        temp_node = temp_node->next;
        
        

    }



}
