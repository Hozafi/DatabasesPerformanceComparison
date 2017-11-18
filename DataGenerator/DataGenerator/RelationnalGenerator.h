#pragma once
#include "Parameter.h"

class RelationnalGenerator
{
public:
	RelationnalGenerator();
	~RelationnalGenerator();
	static void generatePerson(const std::vector<int>& tabAge, const std::vector<std::string>& tabName);
	static void generateCity(const std::vector<char*>& tabCity);
	static void generateIsFriend();
};

