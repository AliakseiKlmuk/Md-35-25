#pragma once

#include "Forest.h"
#include <iostream>

class Deciduous : public Forest
{
public:
	void addTree(Tree* tree) override {
		if (tree) { trees.push_back(tree); };
	}

	void displayTrees() override {
		if (trees.empty()) {
			std::cout << "No deciduous trees in the forest." << std::endl;
		}
		else {
			std::cout << "Deciduous trees in the forest." << std::endl;
			for (Tree* tree : trees) {
				tree->wind();
			}
		}
	}

public:
	~Deciduous() {
		for (Tree* tree : trees) {
			delete tree;
		}
	}

private:

};

