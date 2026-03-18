
#include <iostream>
#include <memory>
#include <vector>

#include "CargoCar.h"
#include "PassengerCar.h"
#include "ServiceStation.h"
#include "Garage.h"

struct CarInfo {
	std::string name;
	bool isPassenger;
};

int main() {

	int currentCarIndex = 0;
	int currentRepaierCarIndex = 0;

	int limitCarsInGarage = 5;

	int countPassengerCar = 0;
	int countCargoCar = 0;

	bool work = true;

	Garage garage;
	ServiceStation serviceStation(garage);

	std::vector<CarInfo> carList = {
		{"Tesla Model X", true},
		{"Ford F-150", false},
		{"Opel Astra", true},
		{"Chevrolet Silverado", false},
		{"BMW X5", true },
		{"Mercedes-Benz Sprinter", false},
		{"Toyota Camry", true},
		{"Nissan Titan", false},
		{"Hyundai Elantra", true},
		{"Ram 1500", false},
		{"Volkswagen Golf", true},
		{"Honda Ridgeline", false},
		{"Kia Soul", true},
		{"GMC Sierra", false},
		{"Subaru Legacy", true},
		{"Toyota Tacoma", false},
	};

	for (int i = 0; i < carList.size(); ++i) {
		std::cout << i+1 << ". " << carList[i].name << " (" 
			<< (carList[i].isPassenger ? "Passenger" : "Cargo") << ") " << std::endl;
	}
	std::cout << std::endl;
	
	while (work) {
		if (currentCarIndex < carList.size()) {
			if (carList[currentCarIndex].isPassenger) {
				serviceStation.AddCar(std::make_unique<PassengerCar>(carList[currentCarIndex].name));
				countPassengerCar++;
			}
			else if (!carList[currentCarIndex].isPassenger) {
				serviceStation.AddCar(std::make_unique<CargoCar>(carList[currentCarIndex].name));
				countCargoCar++;
			}
			currentCarIndex++;
		}

		if (currentRepaierCarIndex < carList.size()) {
			if (((currentCarIndex - countPassengerCar) > limitCarsInGarage) || ((currentCarIndex - countCargoCar) > limitCarsInGarage)) {
				serviceStation.RepairAll(currentRepaierCarIndex);
				currentRepaierCarIndex++;
			}
		};

		if (currentCarIndex >= carList.size() && currentRepaierCarIndex >= carList.size()) {
			work = false;
		}
	}

	serviceStation.DisplayGarage();

	return 0;
}

