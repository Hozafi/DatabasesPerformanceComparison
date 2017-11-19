#pragma once

#include <time.h>

#include "GraphGenerator.h"
#include "RelationnalGenerator.h"

using namespace std;

int main(int argn, char* argv[]) {

	ifstream file("../DataGenerator/Ressource/Name.txt", ios::in);
	vector<int> tabAge;
	vector<char*> tabCity;
	vector<string> tabName;
	srand(time(NULL));
	int nb_person = NB_PERSON;
	char* separator = SEPARATOR;

	if (argn == 3) {
		nb_person = atoi(argv[1]);
		separator = argv[2];
	}
	else if (argn != 1) {
		cerr << "There is a problem with your argument" << endl << "Put either no argument or DataGenerator.exe NB_PERSON SEPARATOR" << endl;
		return 1;
	}
	// Push some city name in the tab
	tabCity.push_back("Paris");
	tabCity.push_back("Vannes");
	tabCity.push_back("Dublin");
	tabCity.push_back("Lorient");
	tabCity.push_back("Arras");
	tabCity.push_back("Cambrai");
	tabCity.push_back("Lille");
	
	//Push some name in the tab
	if (!file) {
		cerr << "Error opening Ressource/Name.txt" << endl;
		return 1;
	}
	while (!file.eof()) {
		string tmpName;
		getline(file, tmpName);
		tabName.push_back(tmpName);
	}
	file.close();
	
	// Create the Age of the different person
	for (int i = 0; i < nb_person; i++) {
		tabAge.push_back((rand() % 100) + 1);
	}
	
	RelationnalGenerator::generatePerson(tabAge, tabName, nb_person, separator);
	RelationnalGenerator::generateCity(tabCity, separator);
	RelationnalGenerator::generateIsFriend(nb_person, separator);

	GraphGenerator::generatePerson(tabAge,tabName, nb_person, separator);
	GraphGenerator::generateCity(tabCity, separator);
	GraphGenerator::generateIsFriend(nb_person, separator);
	GraphGenerator::generateLiveIn(nb_person, separator);
	
	return 0;
}