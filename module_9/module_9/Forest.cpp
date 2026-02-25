#include "Forest.h"

void Forest::growUp(const Tree& tree)
{
	_trees.push_back(tree);
}

unsigned int Forest::getTreesNumber() const
{
	return _trees.size();
}

void Forest::cutAll()
{
	_trees.clear();
	std::cout << "Delete all" << std::endl;
}

void Forest::changeID(size_t index, unsigned int newID)
{
	if (index < _trees.size())
	{
		_trees[index].setID(newID);
	}
	else {
		std::cout << "Index out of range." << std::endl;
	}
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
	for (const auto& tree : _trees) {
		tree.wind();
	}
}

