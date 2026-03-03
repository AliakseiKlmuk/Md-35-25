#pragma once

#include "Forest.h"
#include <iostream>

class Coniferous : public Forest
{
public:
	void addTree(Tree* tree) override {
		if (tree) { trees.push_back(tree); }
	};

	void displayTrees() override {
		if (trees.empty()) {
			std::cout << "No coniferous trees in the forest." << std::endl;
		}
		else {
			std::cout << "Confiderous trees in the forest." << std::endl;
			for (Tree* tree : trees) {
				tree->wind();
			}
		}
	}

public:
	~Coniferous() {
		for (Tree* tree : trees) {
			delete tree;
		}
	}

private:

};

