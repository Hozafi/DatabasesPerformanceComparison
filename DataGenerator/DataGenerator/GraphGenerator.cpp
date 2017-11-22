#include "GraphGenerator.h"

using namespace std;
GraphGenerator::GraphGenerator()
{
}


GraphGenerator::~GraphGenerator()
{
}

void GraphGenerator::generatePerson(const std::vector<int>& tabAge, const std::vector<std::string>& tabName, int nb_person, char* separator)
{
	ofstream file("../../DataGenerated/GraphPerson.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphPerson.txt" << endl;
		return;
	}
	for (int i = 0; i < nb_person; i++) {
		file << "{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"PersonNode\",\"id\":" << i << "}" << separator << i << separator << tabName[i % tabName.size()].c_str() << separator << tabAge[i] << endl;
	}
	file.close();
}

void GraphGenerator::generateCity(const std::vector<std::string>& tabCity, char* separator)
{
	ofstream file("../../DataGenerated/GraphCity.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphCity.txt" << endl;
		return;
	}
	for (int i = 0; i < NB_VILLE; i++) {
		file << "{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"CityNode\",\"id\":" << i << "}" << separator << i << separator << tabCity[i % tabCity.size()] << endl;
	}
	file.close();
}

void GraphGenerator::generateIsFriend(int nb_person, char* separator)
{
	ofstream file("../../DataGenerated/GraphIsFriend.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphIsFriend.txt" << endl;
		return;
	}
	for (int i = 0; i < nb_person - 1; i++) {
		file << "{\"type\":\"edge\",\"schema\":\"dbo\",\"table\":\"FriendWithEdge\",\"id\":" << i << "}" << separator << 
			"{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"PersonNode\",\"id\":" << i << "}" << separator << 
			"{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"PersonNode\",\"id\":" << i + 1 << "}" << endl;
	}
	file.close();
}

void GraphGenerator::generateLiveIn(int nb_person, int nbVille, char* separator)
{
	ofstream file("../../DataGenerated/GraphLiveIn.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphLiveIn.txt" << endl;
		return;
	}
	int idVille = 0;
	for (int i = 0; i < nb_person; i++) {
		file << "{\"type\":\"edge\",\"schema\":\"dbo\",\"table\":\"LiveInEdge\",\"id\":" << i << "}" << separator <<
			"{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"PersonNode\",\"id\":" << i << "}" << separator <<
			"{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"PersonNode\",\"id\":" << idVille % nbVille << "}" << endl;
		idVille++;
	}
	file.close();
}
