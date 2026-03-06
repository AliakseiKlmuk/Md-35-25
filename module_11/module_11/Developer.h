#pragma once
#include <iostream>

#include "Employee.h"

class Developer : public Employee
{
public:
	void writeCode() override { std::cout << "Developing." << std::endl; };

public: // distructor
	 ~Developer() override = default;
};

