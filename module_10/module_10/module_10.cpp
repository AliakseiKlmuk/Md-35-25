#include "module_10.h"

void prontToTreeType(Coniferous& coniferousForest, Deciduous& deciduousForest);

int main()
{
	Coniferous coniferousForest;
	Deciduous deciduousForest;

	prontToTreeType(coniferousForest, deciduousForest);

	coniferousForest.displayTrees();
	std::cout << std::endl;

	deciduousForest.displayTrees();
	std::cout << std::endl;

	std::cout << "Oak: " << Oak::getCountOak() << std::endl;
	std::cout << "Maple: " << Maple::getCountMaple() << std::endl;
	std::cout << "Birch: " << Birch::getCountBirch() << std::endl;
	std::cout << "Fir: " << Fir::getCountFir() << std::endl;
	std::cout << "Pine: " << Pine::getCountPine() << std::endl;

	
}

void prontToTreeType(Coniferous& coniferousForest, Deciduous& deciduousForest) {
	std::string str;
	char continueInput;

	do {
		std::cout << "Enter name tree: ";
		std::getline(std::cin, str);

		TypeTree treeType = Tree::getTypeTree(str);

		Tree* newTree = nullptr;

		switch (treeType) {
		case TypeTree::Oak:
			deciduousForest.addTree(new Oak());
			break;

		case TypeTree::Maple:
			deciduousForest.addTree(new Maple());
			break;

		case TypeTree::Birch:
			deciduousForest.addTree(new Birch());
			break;

		case TypeTree::Fir:
			coniferousForest.addTree(new Fir());
			break;

		case TypeTree::Pine:
			coniferousForest.addTree(new Pine());
			break;

		default:
			std::cout << "The tree don't add.";
			break;
		}

		if (newTree) {
			newTree->wind();
		}

		std::cout << "Do you want continue? (Y or N)" << std::endl;
		std::cin >> continueInput;
		std::cin.ignore();

	} while (continueInput == 'y' || continueInput == 'Y');
}