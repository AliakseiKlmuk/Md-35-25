#include "Forest.h"

void Forest::growUp(const Tree& tree)
{
	_trees.push_back(tree);
}

size_t Forest::getTreesNumber() const
{
	return _trees.size();
}

void Forest::cutAll()
{
	_trees.clear();
}

Forest Forest::operator+(const Forest& other) const
{
	Forest combinedForest = *this;

	for (const auto& tree : other._trees)
	{
		combinedForest.growUp(tree);
	}
	return combinedForest;
}

void Forest::displayAll() const
{
	if (_trees.empty()) {
		std::cout << "No trees in the forest." << std::endl;
	}
	for (const auto& tree : _trees) {
		tree.wind();
	}
}

void changeID(Forest& forest, size_t index, unsigned int newID)
{
	auto size = forest._trees.size();
	if (index < size) {
		forest._trees[index].setID(newID); // Использование метода setID
	}
	else {
		std::cout << "Index out of range." << std::endl;
	}
}
