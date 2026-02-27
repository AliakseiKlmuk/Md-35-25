#pragma once
#include <string>
#include <iostream>

class Forest;

enum class TypeTree {Unknow = -1, Coniferous, Deciduous, Fruit};

class Tree
{
public:  // constructors
	Tree(const std::string& name, TypeTree type)
		: _typeTree(type), _idTree(_nextID++)
	{
		setName(name);
		_countTree++;
		//std::cout << "user constructor tree" << std::endl;
	}

	Tree(const Tree& other) : _typeTree(other._typeTree), _idTree(other._idTree)
	{
		if (other._nameTree) {
			_nameTree = new std::string(*other._nameTree);
		}
		else {
			_nameTree = nullptr;
		}
		//std::cout << "copy constructor tree" << std::endl;
	}

public:  // getters
	std::string getName() const;
	unsigned int getID() const { return _idTree; };

	static unsigned int getCount() { return _countTree; }

public:  // setters
	void setName(const std::string& name);
	void setID(unsigned int id) { _idTree = id; };

	void setType(TypeTree type);
	
public:  // other function
	void wind() const; // display

	static std::string typeTreeToString(TypeTree type); // modification enum

public:  // disstructor
	~Tree()
	{
		delete _nameTree;
		_countTree--;
		//std::cout << "distructor tree" << std::endl;
	}

private:
	std::string* _nameTree;
	TypeTree _typeTree;

private:
	static unsigned int _countTree;
	static unsigned int _nextID;
	unsigned int _idTree = 1;
		
};

