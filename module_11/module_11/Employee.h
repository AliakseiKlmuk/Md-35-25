#pragma once
#include <iostream>

class Employee
{
public: // constructor
	Employee() = default;

public: // function
	virtual void writeCode() { std::cout << "Managin people" << std::endl; };
	virtual void manageTeam() { std::cout << "Managin people" << std::endl; };
	
public: // distructor
	virtual ~Employee() = default;
};

