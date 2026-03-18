#pragma once

#include <memory>

#include "PassengerCar.h"
#include "CargoCar.h"
#include "Garage.h"

class ServiceStation
{
public:
	ServiceStation(Garage& garage) : _garage(garage){}

public:
	void AddCar(std::unique_ptr<PassengerCar> car);
	void AddCar(std::unique_ptr<CargoCar> car);
	void RepairAll(int num);
	void DisplayGarage() const;

private:
	Garage& _garage;

};

