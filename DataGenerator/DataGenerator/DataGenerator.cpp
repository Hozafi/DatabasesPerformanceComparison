#pragma once

#include <time.h>

#include "GraphGenerator.h"
#include "RelationnalGenerator.h"
#include <algorithm>
using namespace std;

int main(int argn, char* argv[]) {

	ifstream file("../DataGenerator/Ressource/Name.txt", ios::in);
	vector<int> tabAge;
	vector<string> tabCity;
	vector<string> tabName;
	vector<vector<int>> tabAmi;
	srand(time(NULL));
	int nb_person = NB_PERSON;
	int nbVille = NB_VILLE;
	char* separator = SEPARATOR;

	if (argn == 4) {
		nb_person = atoi(argv[1]);
		nbVille = atoi(argv[2]);
		separator = argv[3];
	}
	else if (argn != 1) {
		cerr << "There is a problem with your argument" << endl << "Put either no argument or DataGenerator.exe NB_PERSON SEPARATOR" << endl;
		return 1;
	}
	
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
	
	file = ifstream("../DataGenerator/Ressource/City.txt", ios::in);
	if (!file) {
		cerr << "Error opening Ressource/Name.txt" << endl;
		return 1;
	}
	// Push some city name in the tabtabCity.push_back("Paris");
	while (!file.eof()) {
		string tmpCity;
		getline(file, tmpCity);
		tmpCity.resize(tmpCity.length() - 1);
		tabCity.push_back(tmpCity);
	}
	// Create the Age of the different person
	for (int i = 0; i < nb_person; i++) {
		tabAge.push_back((rand() % 100) + 1);
	}
	
	for (int i = 0; i < nb_person; i++) {
		vector<int> tabTmp;
		for (int j = 0; j < 100; j++) {
			int random;
			do {
				random = rand() % nb_person;
			} while (random == i || (std::find(tabTmp.begin(), tabTmp.end(), random) != tabTmp.end()));
			tabTmp.push_back(random);
		}
		tabAmi.push_back(tabTmp);
	}

	RelationnalGenerator::generatePerson(tabAge, tabName, nb_person, nbVille, separator);
	RelationnalGenerator::generateCity(tabCity, nbVille, separator);
	RelationnalGenerator::generateIsFriend(nb_person, tabAmi, separator);

	GraphGenerator::generatePerson(tabAge,tabName, nb_person, separator);
	GraphGenerator::generateCity(tabCity, nbVille, separator);
	GraphGenerator::generateIsFriend(nb_person, tabAmi, separator);
	GraphGenerator::generateLiveIn(nb_person, nbVille, separator);
	

	return 0;
}