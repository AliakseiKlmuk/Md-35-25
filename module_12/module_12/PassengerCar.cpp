#include "PassengerCar.h"
#include "Car.h"

std::ostream& operator<<(std::ostream& os, const PassengerCar& car){
	os <<  car.getName() << " status: " << (car.IsRepaired() ? "Don't need to repair" : "Need to repair");
	return os;
}
