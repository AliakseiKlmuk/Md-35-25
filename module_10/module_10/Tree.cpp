#include "Tree.h"

TypeTree Tree::getTypeTree(const std::string& treeName)
{
	std::string lawerName = treeName;

	for (char& c : lawerName) {
		c = tolower(c);
	}

	if (lawerName == "oak") { return TypeTree::Oak; }
	else if (lawerName == "maple") { return TypeTree::Maple; }
	else if (lawerName == "birch") { return TypeTree::Birch; }
	else if (lawerName == "fir") { return TypeTree::Fir; }
	else if (lawerName == "pine") { return TypeTree::Pine; }
	else { return TypeTree::Unknown; }
}

void Tree::displayEnam(TypeTree type)
{
	switch (type) {
	case TypeTree::Oak:
		std::cout << "Oak";
		break;

	case TypeTree::Maple:
		std::cout << "Maple";
		break;

	case TypeTree::Birch:
		std::cout << "Birch";
		break;

	case TypeTree::Fir:
		std::cout << "Fir";
		break;

	case TypeTree::Pine:
		std::cout << "Pine";
		break;

	default:
		std::cout << "Unknown";
	}
}

