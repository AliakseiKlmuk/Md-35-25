#pragma once
#include <iostream>

#include "Tree.h"

class Fir : public Tree
{
	static unsigned int countFir;

public:
	Fir() { countFir++; }

	void wind() override{std::cout << "This is an Fir tree." << std::endl;}
	static unsigned getCountFir() { return countFir; };

public:
	~Fir(){ countFir--; }

private:

};

