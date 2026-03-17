#include "CargoCar.h"
#include "Car.h"

std::ostream& operator<<(std::ostream& os, const CargoCar car){
	os <<  car.getName() << " status: " << (car.IsRepaired() ? "Don't need to repair" : "Need to repair");
	return os;
}
