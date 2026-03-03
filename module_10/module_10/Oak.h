#pragma once
#include <iostream>

#include "Tree.h"

class Oak : public Tree
{
	static unsigned int countOak;

public:
	Oak() { countOak++; }

	void wind() override{std::cout << "This is an Oak tree." << std::endl;}
	static int getCountOak() { return countOak; };

public:
	~Oak() { countOak--; }
	
private:

};

