#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Tree.h"

class Forest
{
public:  // constructor
	Forest() = default;
	
public:  // functions
	size_t getTreesNumber() const;
	void growUp(const Tree& tree);
	void cutAll();
	void changeID(size_t index, unsigned int newID);

public:  // other function
	void displayAll() const;
	
public:  // operator
	Forest operator+(const Forest& other) const;
		
public: // distructor
	~Forest() = default;
	

private:
	std::vector<Tree> _trees;

};


