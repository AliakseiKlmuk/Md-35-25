#pragma once
#include <vector>

#include "Tree.h"

class Forest
{
public:
	//virtual void grow() = 0;

	virtual void addTree(Tree* tree) = 0;
	virtual void displayTrees() = 0;

public:
	virtual ~Forest() {}

protected:
	std::vector<Tree*> trees;
};

