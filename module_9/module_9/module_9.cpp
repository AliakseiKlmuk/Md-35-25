
#include <iostream>
#include "Tree.h"
#include "Forest.h"
#include <cassert>

int main()
{
	Forest forest1;
	Forest forest2;
	Forest forest3;
	
	for (int i = 0; i < 6; ++i) {
		Tree tree("Pine", TypeTree::Coniferous);
		forest1.growUp(tree);
	}
	forest1.displayAll();
	std::cout << "Size forest1:\t" << forest1.getTreesNumber() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; ++i) {
		Tree tree("Cherry", TypeTree::Fruit);
		forest2.growUp(tree);
	}
	forest2.displayAll();
	std::cout << "Size forest1:\t" << forest2.getTreesNumber() << std::endl;
	std::cout << std::endl;

	changeID(forest2, 1, 10);
	forest2.displayAll();
	std::cout << std::endl;

	forest3 = forest2;
	forest3.displayAll();
	std::cout << std::endl;

	Forest combinedForest = forest1 + forest2;
	std::cout << "Combinet forest:\t" << combinedForest.getTreesNumber() << std::endl;
;	combinedForest.displayAll();
	std::cout << std::endl;

	combinedForest.cutAll();
	combinedForest.displayAll();
	std::cout << std::endl;

}
