#include "Tree.h"
#include <unordered_map>

unsigned int Tree::_countTree = 0;
unsigned int Tree::_nextID = 1;

void Tree::setType(const std::string& type)
{
	_typeTree = stringToTypeTree(type);
}

void Tree::setName(const std::string& name)
{
	_nameTree = name;
}

void Tree::wind() const {
	std::cout << "Tree: " << _nameTree << "\tType: " << typeTreeToString(_typeTree) << "\tid: " << _idTree << std::endl;
}

TypeTree Tree::stringToTypeTree(const std::string& str)
{
	static const std::unordered_map<std::string, TypeTree> mapping = {
		{"coniferous", TypeTree::Coniferous},
		{"deciduous", TypeTree::Deciduous},
		{"fruit", TypeTree::Fruit} };
	auto it = mapping.find(str);

	return it !=mapping.end()? it->second: TypeTree::Unknow;
}

std::string Tree::typeTreeToString(TypeTree type) {
	switch (type) {
	case TypeTree::Coniferous: return "Coniferous";
	case TypeTree::Deciduous: return "Deciduous";
	case TypeTree::Fruit: return "Fruit";
	default: return "Unknow";
	}
}
