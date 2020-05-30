#include <iostream>

#include "options.h"

using namespace std;

void refresh_console(Passengers* queue, Bus_stops* bus_stops) {

	system("cls");

	// Waiting queue
	cout << "Lista de espera:" << endl << endl;
	print_passengers(queue);
	cout << endl
		<< "Quantidade de passageiros na lista de espera: " << queue->quantity << endl //!Debug
		<< endl << endl;


	// Bus stops
	print_bus_stops(bus_stops); //!DEBUG
	cout << endl;

}

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
		system("Pause");

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
			system("Pause");
			break;

		}

		temp_node = temp_node->next;

	}

	if (passenger_was_removed == false) {

		wcout << "Não existe nenhum passageiro com o número " << ticket_number << " em nenhum autocarro." << endl;
		system("Pause");

	}

	// TODO: Add last name back to linked list

}

void delete_passenger_from_queue(Passengers* queue, Bus_stops* bus_stops) {

	refresh_console(queue, bus_stops);

	wcout << "Nº do passageiro a remover: ";
	int ticket_number = 0;
	cin >> ticket_number;

	bool passenger_exists = false;

	Passenger* temp_node = queue->passengers;

	// If the chosen passenger is the first passenger in the queue
	if (ticket_number == temp_node->ticket_number) {

		passenger_exists = true;

		queue->passengers = queue->passengers->next;
		queue->quantity--;
		cout << "O passageiro " << temp_node->ticket_number << " foi removido." << endl;
		delete temp_node;
		
		system("Pause");

	}

	// If the chosen passenger is not the first passenger in the queue
	else {

		for (int i = 1; i < queue->quantity; i++) {

			if (ticket_number == temp_node->next->ticket_number) {

				passenger_exists = true;
				Passenger* node_to_delete = temp_node->next;
				temp_node->next = temp_node->next->next;
				queue->quantity--;
				cout << "O passageiro " << node_to_delete->ticket_number << " foi removido." << endl;
				delete node_to_delete;

				system("Pause");
			}

			temp_node = temp_node->next;
			
		}

	}

	// If the chosen passenger doesn't exist in the queue
	if (passenger_exists == false) {

		wcout << "Não existe nenhum passageiro com o nº " << ticket_number << "." << endl;
		system("Pause");

	}

}

void change_driver_name(Buses* buses, Passengers* queue, Bus_stops* bus_stops) {

	refresh_console(queue, bus_stops);

	//! If there exists atleast one bus
	if (buses->buses != NULL) {
	
		wcout << "Número da matrícula do autocarro: ";
		int licence_plate = 0;
		cin >> hex >> licence_plate >> dec;

		bool bus_exists = false;

		Bus* temp_node = buses->buses;

		if (licence_plate == temp_node->licence_plate) {

			bus_exists = true;

			wstring name = L"";

			cout << "Primeiro nome: ";
			wcin >> name;
			temp_node->driver.first_name = name;

			wcout << "Último nome: ";
			wcin >> name;
			temp_node->driver.last_name = name;

		}

		for (int i = 1; i < buses->amount; i++) {

			if (licence_plate == temp_node->next->licence_plate) {

				bus_exists = true;

				wstring name = L"";

				cout << "Primeiro nome: ";
				wcin >> name;
				temp_node->next->driver.first_name = name;

				wcout << "Último nome: ";
				wcin >> name;
				temp_node->next->driver.last_name = name;

			}

			temp_node = temp_node->next;


		}

		if (bus_exists == false) {

			wcout << hex << "Não existe nenhum autocarro com a matrícula " << licence_plate << "." << endl << dec;
			system("Pause");

		}
	
	}

	//! If no buses exist
	else {
		wcout << "Não existe nenhum autocarro." << endl;
		system("Pause");
	}


}

void options_menu(Passengers* queue, Bus_stops* bus_stops, Buses* buses) {

	refresh_console(queue, bus_stops);

	cout << "1 - Remover passageiros dos autocarros" << endl
		<< "2 - Remover passageiros da fila de espera" << endl
		<< "3 - Apresentar bilhetes por paragem" << endl
		<< "4 - Alterar motorista" << endl
		<< "5 - Remover bilhete da paragem" << endl
		<< "0 - Voltar" << endl;

	int option = 0;
	cin >> option;

	switch (option)
	{
	case 2:
		delete_passenger_from_queue(queue, bus_stops);
		options_menu(queue, bus_stops, buses);
		break;

	case 4:
		change_driver_name(buses, queue, bus_stops);
		options_menu(queue, bus_stops, buses);
		break;
	
	case 0:
		break;

	default:
		wcout << "A opção introduzida não existe." << endl;
		system("Pause");
		options_menu(queue, bus_stops, buses);
		break;
	}


}