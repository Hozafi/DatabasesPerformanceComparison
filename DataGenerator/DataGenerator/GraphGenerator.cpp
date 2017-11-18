#include "GraphGenerator.h"

using namespace std;
GraphGenerator::GraphGenerator()
{
}


GraphGenerator::~GraphGenerator()
{
}

void GraphGenerator::generatePerson(const std::vector<int>& tabAge, const std::vector<std::string>& tabName)
{
	ofstream file("../../DataGenerated/GraphPerson.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphPerson.txt" << endl;
		return;
	}
	for (int i = 0; i < NB_PERSON; i++) {
		file << "{\"type\":\"node\", \"id\":" << i << "}" << SEPARATOR << i << SEPARATOR << tabName[i % tabName.size()].c_str() << SEPARATOR << tabAge[i] << endl;
	}
	file.close();
}

void GraphGenerator::generateCity(const std::vector<char*>& tabCity)
{
	ofstream file("../../DataGenerated/GraphCity.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphCity.txt" << endl;
		return;
	}
	for (int i = 0; i < NB_VILLE; i++) {
		file << "{\"type\":\"node\", \"id\":" << i << "}" << SEPARATOR << i << SEPARATOR << tabCity[i % NB_VILLE] << endl;
	}
	file.close();
}

void GraphGenerator::generateIsFriend()
{
	ofstream file("../../DataGenerated/GraphIsFriend.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphIsFriend.txt" << endl;
		return;
	}
	for (int i = 0; i < NB_PERSON - 1; i++) {
		file << "{\"type\":\"edge\", \"id\":" << i << "}" << SEPARATOR << i << SEPARATOR << i + 1 << endl;
	}
	file.close();
}

void GraphGenerator::generateLiveIn()
{
	ofstream file("../../DataGenerated/GraphLiveIn.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphLiveIn.txt" << endl;
		return;
	}
	int idVille = 0;
	for (int i = 0; i < NB_PERSON; i++) {
		file << "{\"type\":\"edge\", \"id\":" << i << "}" << SEPARATOR << i << SEPARATOR << idVille % NB_VILLE << endl;
		idVille++;
	}
	file.close();
}
