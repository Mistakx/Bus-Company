#include <iostream>

#include "options.h"

using namespace std;

bool remove_passenger_from_bus(Bus* bus, int ticket_number) {

	bool passenger_exists = false;

	Passenger* temp_node = bus->passengers->passengers;

	// Passenger is the first node
	if (ticket_number == temp_node->ticket_number) {

		passenger_exists = true;

		bus->passengers->passengers = bus->passengers->passengers->next;
		bus->passengers->quantity--;
		delete temp_node;


	}

	// Passenger isn't the first node
	else {

		for (int i = 1; i < bus->passengers->quantity; i++) {

			if (ticket_number == temp_node->next->ticket_number) {

				temp_node->next = temp_node->next->next;
				delete temp_node->next;
				break;

			}

			temp_node = temp_node->next;

		}
	}


	if (passenger_exists == false) {

		cout << "O passangeiro escolhido não foi encontrado em nenhum autocarro." << endl;

	}

	return passenger_exists; // True if removed, false otherwise

}

void remove_passenger_from_buses(Buses* buses) {

	cout << "Nª do passageiro que pretende remover: ";
	int ticket_number = 0;
	cin >> ticket_number;

	Bus* temp_node = buses->buses;

	bool passenger_was_removed = false;

	for (int i = 0; i < buses->amount; i++) {

		if (remove_passenger_from_bus(temp_node, ticket_number) == true) {

			passenger_was_removed = true;
			cout << "Passageiro removido." << endl;
			break;

		}

		temp_node = temp_node->next;

	}

	if (passenger_was_removed == false) {

		cout << "Não existe nenhum passageiro com o número " << ticket_number << " em nenhum autocarro." << endl;

	}

	// TODO: Add last name back to linked list

}

void remove_passenger_from_queue(Passengers* queue) {

	cout << "Nª do passageiro a remover: ";
	int ticket_number = 0;
	cin >> ticket_number;

	bool passenger_exists = false;

	Passenger* temp_node = queue->passengers;

	// If the chosen passenger is the first passenger in the queue
	if (ticket_number == temp_node->ticket_number) {

		passenger_exists = true;

		queue->passengers = queue->passengers->next;
		delete temp_node;

	}

	// If the chosen passenger is not the first passenger in the queue
	else {

		for (int i = 1; i < queue->quantity; i++) {

			if (ticket_number == temp_node->next->ticket_number) {

				passenger_exists = true;

				temp_node->next = temp_node->next->next;
				delete temp_node->next;

			}

		}

	}

	// If the chosen passenger doesn't exist in the queue
	if (passenger_exists == false) {

		cout << "Não existe nenhum passageiro com o nº " << ticket_number << "." << endl;

	}

	// TODO: Add last name back to linked list

}

void change_driver_name(Buses* buses) {

	cout << "Número da matrícula do autocarro:";
	string licence_plate = 0;
	cin >> licence_plate;

	bool bus_exists = false;

	Bus* temp_node = buses->buses;

	if (licence_plate == temp_node->licence_plate) {

		bus_exists = true;

		string name = "";

		cout << "Primeiro nome: ";
		cin >> name;
		temp_node->driver.first_name = name;

		cout << "Último nome: ";
		cin >> name;
		temp_node->driver.last_name = name;

	}

	for (int i = 1; i < buses->amount; i++) {

		if (licence_plate == temp_node->next->licence_plate) {

			bus_exists = true;

			string name = "";

			cout << "Primeiro nome: ";
			cin >> name;
			temp_node->next->driver.first_name = name;

			cout << "Último nome: ";
			cin >> name;
			temp_node->next->driver.last_name = name;

		}

		temp_node = temp_node->next;


	}

	if (bus_exists == false) {

		cout << "Não existe nenhum autocarro com a matrícula " << licence_plate << "." << endl;

	}

}

void options_menu() {

	cout << "1 - Remover passageiros dos autocarros" << endl
		<< "2 - Remover passageiros da fila de espera" << endl
		<< "3 - Apresentar bilhetes por paragem" << endl
		<< "4 - Alterar motorista" << endl
		<< "5 - Remover bilhete da paragem" << endl;

	int option = 0;
	cin >> option;

	switch (option)
	{

	

	default:
		break;
	}


}