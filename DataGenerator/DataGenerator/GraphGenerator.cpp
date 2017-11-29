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

void GraphGenerator::generateCity(const std::vector<std::string>& tabCity, int nbVille, char* separator)
{
	ofstream file("../../DataGenerated/GraphCity.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphCity.txt" << endl;
		return;
	}
	for (int i = 0; i < nbVille; i++) {
		file << "{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"CityNode\",\"id\":" << i << "}" << separator << i << separator << tabCity[i] << endl;
	}
	file.close();
}

void GraphGenerator::generateIsFriend(int nb_person, std::vector<std::vector<int>> tabAmi, char* separator)
{
	ofstream file("../../DataGenerated/GraphIsFriend.txt", ios::out | ios::trunc);
	if (!file) {
		cerr << "Error opening GraphIsFriend.txt" << endl;
		return;
	}
	for (int i = 0; i < nb_person - 1; i++) {
		for (int j = 0; j < 100; j++) {
			file << "{\"type\":\"edge\",\"schema\":\"dbo\",\"table\":\"FriendWithEdge\",\"id\":" << i << "}" << separator <<
				"{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"PersonNode\",\"id\":" << i << "}" << separator <<
				"{\"type\":\"node\",\"schema\":\"dbo\",\"table\":\"PersonNode\",\"id\":" << tabAmi[i][j] << "}" << endl;
		}	
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
