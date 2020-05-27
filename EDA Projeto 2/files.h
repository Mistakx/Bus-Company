#include <iostream>

using namespace std;

struct Name {

	wstring name = L"";
	Name* next = NULL;

};

struct Names {

	Name* names = NULL;
	int quantity = 0;

};

void parse_names_file(string file_path, Names* names);

void print_names(Names* names);

