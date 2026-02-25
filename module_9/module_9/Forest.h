#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Tree.h"

class Forest
{
public:  // constructor
	Forest() 
	{
		//std::cout << "Forest initialized." << std::endl;
	}

public:  // functions homeWork
	void growUp(const Tree& tree);
	unsigned int getTreesNumber() const;
	void cutAll();
	void changeID(size_t index, unsigned int newID);

public:  // other function
	void displayAll() const;
	
public:  // operator
	Forest operator+(const Forest& other) const;
		
public: // distructor
	~Forest()
	{
		//std::cout << "distructor forest" << std::endl;
	};

private:
	std::vector<Tree> _trees;

};


