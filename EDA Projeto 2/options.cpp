#include <iostream>
#include <string>

#include "options.h"

using namespace std;

int _print_t(Ticket_number* tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!tree) return 0;

	sprintf_s(b, "(%03d)", tree->ticket_number);

	int left = _print_t(tree->left, 1, offset, depth + 1, s);
	int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';

		s[depth - 1][offset + left + width / 2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}
#endif

	return left + width + right;
}

void print_t(Ticket_number* tree)
{
	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf_s(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);

}

//_________________________________________
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

bool buses_are_empty(Buses* buses) {

	Bus* temp_node = buses->buses;

	while (temp_node != NULL) {

		if (temp_node->passengers->quantity != 0) {
			return false;
		}

		temp_node = temp_node->next;

	}
	
	return true;

}

bool delete_passenger_from_bus(Bus* bus, int ticket_number) {

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

			//wcout << "Current Passenger Node: " << temp_node->next->ticket_number << endl; // DEBUG

			if (ticket_number == temp_node->next->ticket_number) {

				passenger_exists = true;

				Passenger* node_to_remove = temp_node->next;
				temp_node->next = temp_node->next->next;
				bus->passengers->quantity--;
				delete node_to_remove;
				break;

			}

			temp_node = temp_node->next;

		}
	}

	return passenger_exists; // True if removed, false otherwise

}

void delete_passenger_from_buses(Buses* buses, Passengers* queue, Bus_stops* bus_stops) {

	//! If there exists at least one bus
	if (buses->amount > 0) {

		// If at least one bus isn't empty
		if (buses_are_empty(buses) == false) {

			refresh_console(queue, bus_stops);
			wcout << "Nº do passageiro que pretende remover: ";
			int ticket_number = 0;
			wcin >> ticket_number;

			Bus* temp_node = buses->buses;

			bool passenger_was_removed = false;

			for (int i = 0; i < buses->amount; i++) {

				//wcout << "Searching passenger in bus number: " << i << endl; // DEBUG

				if (delete_passenger_from_bus(temp_node, ticket_number) == true) {

					passenger_was_removed = true;
					wcout << "O passageiro " << ticket_number << " foi removido." << endl;
					break;

				}

				temp_node = temp_node->next;
				system("Pause");
			}

			if (passenger_was_removed == false) {

				wcout << "Não existe nenhum passageiro com o número " << ticket_number << " em nenhum autocarro." << endl;
				system("Pause");

			}

		}

		// If all buses are empty
		else {
			refresh_console(queue, bus_stops);
			wcout << "Todos os autocarros já se encontram vazios." << endl;
			system("Pause");
		}


	}

	//! If no buses exist
	else {
		refresh_console(queue, bus_stops);
		wcout << "Não existem autocarros." << endl;
		system("Pause");
	}


}

void delete_passenger_from_queue(Passengers* queue, Bus_stops* bus_stops) {

	// If the passenger waiting queue has atleast one passenger
	if (queue->quantity > 0) {

		refresh_console(queue, bus_stops);

		wcout << "Nº do passageiro a remover: ";
		int ticket_number = 0;
		wcin >> ticket_number;

		bool passenger_exists = false;

		Passenger* temp_node = queue->passengers;

		// If the chosen passenger is the first passenger in the queue
		if (ticket_number == temp_node->ticket_number) {

			passenger_exists = true;

			queue->passengers = queue->passengers->next;
			queue->quantity--;
			wcout << "O passageiro " << ticket_number << " foi removido." << endl;
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
					wcout << "O passageiro " << node_to_delete->ticket_number << " foi removido." << endl;
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

	// If the passenger waiting queue doesn't have any passengers
	else {

		refresh_console(queue, bus_stops);
		wcout << "A fila de espera já se encontra vazia." << endl;

	}
}

void show_tickets_menu(Buses* buses,  Passengers* queue, Bus_stops* bus_stops) {

	// If a bus already exists
	if (buses->amount > 0) {
		refresh_console(queue, bus_stops);

		wcout << "Nome da paragem: "; // Has to be wcout A program should not mix input operations on wcin with input operations on wcin (or with other narrow-oriented input operations on stdin): Once an input operation has been performed on either, the standard input stream acquires an orientation (either narrow or wide) that can only be safely changed by calling freopen on stdin.
		wstring bus_stop_name = L""; 
		wcin.ignore();
		getline(wcin, bus_stop_name);
		wcout << "BUS STOP NAME: " << bus_stop_name;


		Bus_stop* temp_node = bus_stops->bus_stops;
		bool bus_stop_exists = false;

		while (temp_node != NULL) {

			// If the chosen bus stop exists
			if (bus_stop_name == temp_node->name) {

				// If the chosen bus stop has passengers
				if (temp_node->ticket_numbers != NULL) {
					bus_stop_exists = true;

					refresh_console(queue, bus_stops);
					print_t(temp_node->ticket_numbers);
					system("Pause");
				}

				// If the chosen bus stop doesn't have passengers
				else {
					wcout << "A paragem de autocarros escolhida não tem passageiros." << endl;
					system("Pause");
				}

				break;

			}

			temp_node = temp_node->next;

		}

		// If the chosen bus stop doesn't exist
		if (bus_stop_exists == false) {

			wcout << "A paragem de autocarros escolhida não existe." << endl;
			system("Pause");

		}
	}

	// If no buses exist
	else {
		refresh_console(queue, bus_stops);
		wcout << "Ainda nenhum autocarro passou por nenhuma paragem." << endl;
		system("Pause");
	}

}

void change_driver_name(Buses* buses, Passengers* queue, Bus_stops* bus_stops) {

	refresh_console(queue, bus_stops);

	//! If there exists atleast one bus
	if (buses->amount > 0) {
	
		wcout << "Número da matrícula do autocarro: ";
		int licence_plate = 0;
		wcin >> hex >> licence_plate >> dec;

		bool bus_exists = false;

		Bus* temp_node = buses->buses;

		while (temp_node != NULL) {

			if (licence_plate == temp_node->licence_plate) {

				bus_exists = true;

				wstring name = L"";

				wcout << "Primeiro nome: ";
				wcin >> name;
				temp_node->driver.first_name = name;

				wcout << "Último nome: ";
				wcin >> name;
				temp_node->driver.last_name = name;
				system("Pause");
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

	wcout << "1 - Remover passageiros dos autocarros" << endl
		<< "2 - Remover passageiros da fila de espera" << endl
		<< "3 - Apresentar bilhetes por paragem" << endl
		<< "4 - Alterar motorista" << endl
		<< "5 - Remover bilhete da paragem" << endl
		<< "0 - Voltar" << endl;

	int option = 0;
	wcin >> option;

	switch (option)
	{

	case 1: 
		delete_passenger_from_buses(buses, queue, bus_stops);
		options_menu(queue, bus_stops, buses);
		break;

	case 2:
		delete_passenger_from_queue(queue, bus_stops);
		options_menu(queue, bus_stops, buses);
		break;

	case 3:
		show_tickets_menu(buses, queue, bus_stops);
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