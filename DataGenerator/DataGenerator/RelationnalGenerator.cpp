#include "RelationnalGenerator.h"

using namespace std;

RelationnalGenerator::RelationnalGenerator()
{
}

RelationnalGenerator::~RelationnalGenerator()
{
}

void RelationnalGenerator::generatePerson(const std::vector<int>& tabAge, const std::vector<std::string>& tabName)
{
	ofstream file("../../DataGenerated/RelaPerson.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening RelaPerson.txt" << endl;
		return;
	}
	int idVille = 0;
	for (int i = 0; i < NB_PERSON; i++) {
		file << i << SEPARATOR << tabName[i % tabName.size()].c_str() << SEPARATOR << tabAge[i] << SEPARATOR << idVille % NB_VILLE << endl;
		idVille++;
	}
	file.close();
}

void RelationnalGenerator::generateCity(const std::vector<char*>& tabCity)
{
	ofstream file("../../DataGenerated/RelaCity.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening RelaCity.txt" << endl;
		return;
	}
	for (int i = 0; i < NB_VILLE; i++) {
		file << i << SEPARATOR << tabCity[i] << endl;
	}
	file.close();
}

void RelationnalGenerator::generateIsFriend()
{
	ofstream file("../../DataGenerated/RelaIsFriend.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening RelaIsFriend.txt" << endl;
		return;
	}
	for (int i = 0; i < NB_PERSON - 1; i++) {
		// Each person is friend with the next Person in the table
		// There is only the last person who don't have any friend
		file << i << SEPARATOR << i + 1 << endl;
	}
	file.close();
}
