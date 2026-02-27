#pragma once
#include <iostream>

#include "Employee.h"

class Manager : public Employee
{
public:
	void manageTeam() override  { std::cout << "Managing." << std::endl; };
	
public: // distructor
	~Manager() override = default;
};

