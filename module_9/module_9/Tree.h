#pragma once
#include <string>
#include <iostream>

enum class TypeTree {Unknown = -1, Coniferous, Deciduous, Fruit};

class Forest;
class Tree
{
	static unsigned int nextID;
	
public:  // constructors
	Tree(const std::string& name, TypeTree type)
		: _typeTree(type), _idTree(nextID++)
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

public:
	friend void changeID(Forest& forest, size_t index, unsigned int newID);

public:  // getters
	std::string getName() const;
	unsigned int getID() const { return _idTree; };

	static unsigned int getCount() { return _countTree; }

public:  // setters
	void setName(const std::string& name);
	void setID(unsigned int id) { _idTree = id; };
	
public:  // other function
	void wind() const; 

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
	unsigned int _idTree = 1;
	
};

