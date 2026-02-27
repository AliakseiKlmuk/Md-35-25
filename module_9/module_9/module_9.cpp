
#include <iostream>
#include "Tree.h"
#include "Forest.h"
#include <cassert>

int main()
{

	Forest forest1;
	Forest forest2;
	Forest forest3;

	Tree pine("Pine", TypeTree::Coniferous);
	Tree oak("Oak", TypeTree::Deciduous);
	Tree cherry("Cherry", TypeTree::Fruit);

	forest1.growUp(pine);
	forest1.growUp(cherry);
	forest1.displayAll();
	std::cout << "Size forest1:\t" << forest1.getTreesNumber() << std::endl;
	std::cout << std::endl;

	forest2.growUp(oak);
	forest2.displayAll();
	forest2.changeID(0, 21);
	forest2.displayAll();

	forest3 = forest2;
	forest2.displayAll();

	Forest combinedForest = forest1 + forest2;
	combinedForest.displayAll();

	combinedForest.cutAll();
	combinedForest.displayAll();


}
