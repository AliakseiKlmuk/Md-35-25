#pragma once
#include <string>
#include <iostream>

//#include "Forest.h"

enum class TypeTree {Unknow = -1, Coniferous, Deciduous, Fruit};

class Forest;
class Tree
{
public:  // constructors
	Tree(const std::string& name, const std::string& type)
		: _nameTree(name), _typeTree(stringToTypeTree(type)), _idTree(_nextID++)
	{
		_countTree++;
		//std::cout << "user constructor tree" << std::endl;
	}

	Tree(const Tree& other) : _nameTree(other._nameTree), _typeTree(other._typeTree), _idTree(other._idTree)
	{
		//std::cout << "copy constructor tree" << std::endl;
	}
		
public:  // getters
	unsigned int getID() const { return _idTree; };
	std::string getName() const { return _nameTree; };
	static unsigned int getCount() { return _countTree; }

public:  // setters

	void setID(unsigned int id) { _idTree = id; };
	void setType(const std::string& type);
	void setName(const std::string& name);

public:  // other
	void wind() const; // display
	static TypeTree stringToTypeTree(const std::string& str); // modification
	static std::string typeTreeToString(TypeTree type); // modification

public:  // disstructor
	~Tree()
	{
		_countTree--;
		//std::cout << "distructor tree" << std::endl;
	}

private:
	static unsigned int _countTree;
	static unsigned int _nextID;
	unsigned int _idTree;
	std::string _nameTree;
	TypeTree _typeTree;
	
};

