#pragma once
#include <iostream>

#include "Tree.h"

class Pine : public Tree
{
	static unsigned int countPine;

public:
	Pine() { countPine++; }

	void wind() override{std::cout << "This is an Pine tree." << std::endl;}
	static unsigned getCountPine() { return countPine; };

public:
	~Pine() { countPine--; }

private:

};

