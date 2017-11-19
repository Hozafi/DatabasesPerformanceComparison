#pragma once
#include "Parameter.h"

class GraphGenerator
{
public:
	GraphGenerator();
	~GraphGenerator();
	static void generatePerson(const std::vector<int>& tabAge, const std::vector<std::string>& tabName, int nb_person, char* separator);
	static void generateCity(const std::vector<char*>& tabCity, char* separator);
	static void generateIsFriend(int nb_person, char* separator);
	static void generateLiveIn(int nb_person, char* separator);
};

