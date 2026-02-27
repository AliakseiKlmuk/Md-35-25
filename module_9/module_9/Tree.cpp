#include "Tree.h"
#include <unordered_map>

unsigned int Tree::_countTree = 0;
unsigned int Tree::_nextID = 1;

std::string Tree::getName() const
{
	return _nameTree ? *_nameTree : "No name";
}

void Tree::setType(TypeTree type)
{
	_typeTree = type;
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
		<< "\tType tree: " << typeTreeToString(_typeTree)
		<< "\tid: " << _idTree << std::endl;
}

std::string Tree::typeTreeToString(TypeTree type) {
	switch (type) {
	case TypeTree::Coniferous: return "Coniferous";
	case TypeTree::Deciduous: return "Deciduous";
	case TypeTree::Fruit: return "Fruit";
	default: return "Unknow";
	}
}
