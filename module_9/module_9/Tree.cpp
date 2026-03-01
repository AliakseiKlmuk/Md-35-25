#include "Tree.h"
#include <unordered_map>

unsigned int Tree::nextID = 1;

unsigned int Tree::_countTree = 0;

std::string Tree::getName() const
{
	return _nameTree ? *_nameTree : "No name";
}

void Tree::setName(const std::string& name)
{
	if (_nameTree) {
		*_nameTree = name;
	}
	else {
		_nameTree = new std::string(name);
	}
}

void Tree::wind() const {
	std::cout << "Tree name: " << getName()
		<< "\t\tid: " << _idTree << std::endl;
}
