#pragma once

#include <string>
#include <iostream>

#include "Car.h"

class PassengerCar : public Car
{
public:
	PassengerCar(const std::string& name) : _name(name), _isRepaired(false){}

public:
	void Repair() override { _isRepaired = true; };

public:
	std::string getName() const { return _name; };
	bool IsRepaired() const override { return _isRepaired; };

public:
	friend std::ostream& operator<<(std::ostream& os, const PassengerCar& car);

private:
	std::string _name;
	bool _isRepaired;
};

