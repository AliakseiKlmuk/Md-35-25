
#include <iostream>
#include <vector>
#include <memory>

#include "Employee.h"
#include "Manager.h"
#include "Developer.h"

int main()
{
	std::vector<std::unique_ptr<Employee>> employees;

	employees.push_back(std::make_unique<Manager>());
	employees.push_back(std::make_unique<Developer>());

	for (const auto& emp : employees) {

		if (Manager* managerPtr = dynamic_cast<Manager*>(emp.get())) {
			managerPtr->manageTeam();
		}
		else {
			std::cout << "Not a manager" << std::endl;
		}

		if (Developer* developerPtr = dynamic_cast<Developer*>(emp.get())) {
			developerPtr->writeCode();
		}
		else {
			std::cout << "Not a developer" << std::endl;
		}

	}
}
