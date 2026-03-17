#include "Garage.h"

void Garage::AddToGaragePassengerCar(std::unique_ptr<PassengerCar> car){
	_passengerCars.push_back(std::move(car));
}

void Garage::AddToGarageCargoCar(std::unique_ptr<CargoCar> car){
	_cargoCars.push_back(std::move(car));
}

void Garage::DisplayAll() const
{
	std::cout << "Passenger Cars: \n";
	for (const auto& car : _passengerCars) {
		std::cout << *car << std::endl;
	}

	std::cout << "Cargo Cars: \n";
	for (const auto& car : _cargoCars) {
		std::cout << *car << std::endl;
	}
}

std::vector<Car*> Garage::getAllCars()
{
	std::vector<Car*> allCars;
	for (const auto& car : _passengerCars) {
		allCars.push_back(car.get());
	}
	for (const auto& car : _cargoCars) {
		allCars.push_back(car.get());
	}
	return allCars;
}



