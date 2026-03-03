#pragma once
#include <iostream>

#include "Tree.h"

class Maple : public Tree
{
	static unsigned int countMaple;

public:
	Maple() { countMaple++; }

	void wind() override{std::cout << "This is an Maple tree." << std::endl;}
	static unsigned getCountMaple() { return countMaple; };

public:
	~Maple(){ countMaple--; }

private:

};

