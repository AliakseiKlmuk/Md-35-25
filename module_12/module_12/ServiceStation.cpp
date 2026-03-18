#include "ServiceStation.h"

void ServiceStation::AddCar(std::unique_ptr<PassengerCar> car) {
	_garage.AddToGaragePassengerCar(std::move(car));
}

void ServiceStation::AddCar(std::unique_ptr<CargoCar> car) {
	_garage.AddToGarageCargoCar(std::move(car));
}

void ServiceStation::RepairAll(int num) {

	auto allCars = _garage.getAllCars();
	if (num < 0 || num >= static_cast<int>(allCars.size())) return;

	auto carPtr = allCars[num];
	if (!carPtr) { return; }
	if (carPtr->IsRepaired()) { return; }

	carPtr->Repair();

	if (!carPtr->IsRepaired()) { return; }

	if (num < allCars.size() && allCars[num] && !allCars[num]->IsRepaired()) {
		allCars[num]->Repair();
		if (auto passengerCar = dynamic_cast<PassengerCar*>(allCars[num])) {
			_garage.AddToGaragePassengerCar(std::make_unique<PassengerCar>(*passengerCar));
		}
		else if (auto cargoCar = dynamic_cast<CargoCar*>(allCars[num])) {
			_garage.AddToGarageCargoCar(std::make_unique<CargoCar>(*cargoCar));
		}
	}
}

void ServiceStation::DisplayGarage() const {
	_garage.DisplayAll();
}
