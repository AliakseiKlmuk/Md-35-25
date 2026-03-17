#pragma once

#include <vector>
#include <iostream>
#include <memory>

#include "PassengerCar.h"
#include "CargoCar.h"


class Garage
{
public:
	void AddToGaragePassengerCar(std::unique_ptr<PassengerCar> car);
	void AddToGarageCargoCar(std::unique_ptr<CargoCar> car);
	void DisplayAll() const;

public:
	std::vector <Car*> getAllCars();
	
private:
	std::vector<std::unique_ptr<PassengerCar>> _passengerCars;
	std::vector<std::unique_ptr<CargoCar>> _cargoCars;

	
};

