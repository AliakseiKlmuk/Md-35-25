
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

	int currentCarIndex = 0;
	int currentRepaierCarIndex = 0;

	int limitCarsInGarage = 5;// Лимит машин в гараже

	int countPassengerCar = 0;
	int countCargoCar = 0;
	
	bool work = true;
		
	while (work) {
		if (currentCarIndex < carList.size()) {
			if (carList[currentCarIndex].isPassenger) {
				serviceStation.AddCar(std::make_unique<PassengerCar>(carList[currentCarIndex].name));
				countPassengerCar++;
				std::cout << "add passenger" << std::endl;
			}
			else {
				serviceStation.AddCar(std::make_unique<CargoCar>(carList[currentCarIndex].name));
				countCargoCar++;
				std::cout << "add cargo" << std::endl;
			}
			currentCarIndex++;
		}


		if (currentRepaierCarIndex < carList.size()) {
			serviceStation.RepairAll(currentRepaierCarIndex);
			currentRepaierCarIndex++;
			std::cout << "rep passendger" << std::endl;
		}
			
	
		if (currentCarIndex >= carList.size() && currentRepaierCarIndex >= carList.size()) {
			work = false;
		}

		std::cout << "Add: " << currentCarIndex << " repair: " << currentRepaierCarIndex << std::endl;
	}
		
	serviceStation.DisplayGarage();

	return 0;
}

