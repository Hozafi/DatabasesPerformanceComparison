#pragma once

#include <time.h>

#include "GraphGenerator.h"
#include "RelationnalGenerator.h"

using namespace std;

int main(int argn, char* argv[]) {

	ifstream file("Ressource/Name.txt", ios::in);
	vector<int> tabAge;
	vector<char*> tabCity;
	vector<string> tabName;
	srand(time(NULL));

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
	for (int i = 0; i < NB_PERSON; i++) {
		tabAge.push_back((rand() % 100) + 1);
	}
	
	RelationnalGenerator::generatePerson(tabAge, tabName);
	RelationnalGenerator::generateCity(tabCity);
	RelationnalGenerator::generateIsFriend();

	GraphGenerator::generatePerson(tabAge,tabName);
	GraphGenerator::generateCity(tabCity);
	GraphGenerator::generateIsFriend();
	GraphGenerator::generateLiveIn();
	
	return 0;
}