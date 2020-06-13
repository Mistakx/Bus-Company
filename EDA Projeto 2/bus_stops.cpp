#include <iostream>

#include "bus_stops.h"

using namespace std;

void refresh_console(Passengers* queue, Bus_stops* bus_stops) {

	system("cls");

	// Waiting queue
	wcout << "Lista de espera:" << endl << endl;
	print_passengers(queue);
	wcout << endl
		<< "Quantidade de passageiros na lista de espera: " << queue->quantity << endl //!Debug
		<< endl << endl;


	// Bus stops
	print_bus_stops(bus_stops); //!DEBUG
	wcout << endl;

}

bool BST_search(Ticket_number* tree, int ticket_number)
{
	if (tree == NULL)
		return false;

	if (ticket_number == tree->ticket_number)
		return true;

	else if (ticket_number < tree->ticket_number) {
		return BST_search(tree->left, ticket_number);
	}

	else {
		return BST_search(tree->right, ticket_number);
	}
}

bool ticket_number_already_exists_in_bus_stops(int ticket_number, Bus_stops* bus_stops) {

	Bus_stop* temp_node = bus_stops->bus_stops;
	
	while (temp_node != NULL) {

		if (BST_search(temp_node->ticket_numbers, ticket_number)) {
			
			return true;

		}

		temp_node = temp_node->next;

	}

	

}

void initialize_bus_stop(Bus_stop* bus_stop, Names* bus_stop_names) {

	// ! Name node position
	int position_of_bus_stop_name = rand() % (bus_stop_names->quantity); // Chooses the position of a random name to give to the bus stop

	//! Removing the node
	Name* temp_node = bus_stop_names->names;

		// If bus stop name is the first node
	if (position_of_bus_stop_name == 0) {

		// Sets the bus stop name
		bus_stop->name = bus_stop_names->names->name;

		// Deletes the first node
		bus_stop_names->names = bus_stop_names->names->next;
		delete temp_node;
		bus_stop_names->quantity--;

	}

		// If bus stop name isn't the first node
	else {

		for (int i = 1; i < position_of_bus_stop_name; i++) {
			temp_node = temp_node->next;
		}

		Name* node_to_remove = temp_node->next;
		bus_stop->name = node_to_remove->name;
		temp_node->next = temp_node->next->next;
		bus_stop_names->quantity--;
		delete node_to_remove;

	}
	
}

void initialize_bus_stops(Bus_stops* bus_stops, Names* bus_stop_names) {

	bus_stops->amount = rand() % 6 + 4; // Generates a random number between 4 and 9 (including both)

	//! Initialize first bus stop
	bus_stops->bus_stops = new Bus_stop;
	initialize_bus_stop(bus_stops->bus_stops, bus_stop_names);

	// ! Initialize second bus stop and beyond
	for (int i = 1; i < bus_stops->amount; i++) {

		Bus_stop* temp_node = new Bus_stop;
		initialize_bus_stop(temp_node, bus_stop_names);
		temp_node->next = bus_stops->bus_stops;
		bus_stops->bus_stops = temp_node;

	}









	

}

void print_bus_stops(Bus_stops* bus_stops) {

	Bus_stop* temp_node = bus_stops->bus_stops;

	while (temp_node != NULL) {

		wcout << "Paragem: " << temp_node->name << endl;

		// If there's a bus at the stop
		if (temp_node->bus != NULL) {
			wcout << "Autocarro: " << hex << temp_node->bus->licence_plate << " Motorista: " << temp_node->bus->driver.first_name << " " << temp_node->bus->driver.last_name << endl << dec;
			cout << "Passageiros: ";
			print_bus_passangers(temp_node->bus);
			cout << endl;
			
		}

		// If there isn't a bus at the stop
		else {

			wcout << "Autocarro: " << "Não existe nenhum autocarro nesta paragem." << endl;

		}

		temp_node = temp_node->next;
		cout << endl;
	}

}

