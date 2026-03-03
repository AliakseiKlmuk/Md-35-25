#pragma once
#include <string>
#include <algorithm>
#include <iostream>

enum class TypeTree{
	Unknown = -1,	Oak,	Maple,	Birch,	Fir,	Pine
};

class Tree
{
public:
	virtual void wind() = 0;
	static TypeTree getTypeTree(const std::string& treeName);
	void displayEnam(TypeTree type);

public:
	virtual ~Tree() {}

private:
	TypeTree _typeTree;
};