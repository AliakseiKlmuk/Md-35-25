#pragma once
#include <iostream>

#include "Tree.h"

class Birch : public Tree
{
	static unsigned int countBirch;

public:
	Birch() { countBirch++; }

	void wind() override{std::cout << "This is an Birch tree." << std::endl;}
	static unsigned getCountBirch() { return countBirch; };

public:
	~Birch(){ countBirch--; }

private:

};

