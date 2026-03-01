#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Tree.h"

class Tree;
class Forest
{
	friend void changeID(Forest& forest, size_t index, unsigned int newID);
	
public:  // constructor
	Forest() = default;
	
public:  // functions
	size_t getTreesNumber() const;
	void growUp(const Tree& tree);
	void cutAll();
	
public:  // other function
	void displayAll() const;
	
public:  // operator
	Forest operator+(const Forest& other) const;
		
public: // distructor
	~Forest() = default;
	
private:
	std::vector<Tree> _trees;

};


