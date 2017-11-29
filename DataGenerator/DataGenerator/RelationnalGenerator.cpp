#include "RelationnalGenerator.h"

using namespace std;

RelationnalGenerator::RelationnalGenerator()
{
}

RelationnalGenerator::~RelationnalGenerator()
{
}

void RelationnalGenerator::generatePerson(const std::vector<int>& tabAge, const std::vector<std::string>& tabName, int nb_person, int nbVille, char* separator)
{
	ofstream file("../../DataGenerated/RelaPerson.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening RelaPerson.txt" << endl;
		return;
	}
	int idVille = 0;
	for (int i = 0; i < nb_person; i++) {
		file << i << separator << tabName[i % tabName.size()].c_str() << separator << idVille % nbVille << separator << tabAge[i] << endl;
		idVille++;
	}
	file.close();
}

void RelationnalGenerator::generateCity(const std::vector<std::string>& tabCity, int nbVille, char* separator)
{
	ofstream file("../../DataGenerated/RelaCity.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening RelaCity.txt" << endl;
		return;
	}
	for (int i = 0; i < nbVille; i++) {
		file << i << separator << tabCity[i] << endl;
	}
	file.close();
}

void RelationnalGenerator::generateIsFriend(int nb_person, std::vector<std::vector<int>> tabAmi, char* separator)
{
	ofstream file("../../DataGenerated/RelaIsFriend.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening RelaIsFriend.txt" << endl;
		return;
	}
	for (int i = 0; i < nb_person - 1; i++) {
		// Each person is friend with the next Person in the table
		// There is only the last person who don't have any friend
		for (int j = 0; j < 100; j++) {
			file << i << separator << tabAmi[i][j] << endl;
		}
		
	}
	file.close();
}
