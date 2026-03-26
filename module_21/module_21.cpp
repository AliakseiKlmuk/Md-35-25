
#include <iostream>
#include <memory>

#include "IDeliveryStrategy.h"
#include "DeliveryContext.h"

#include "GroundDelivery.h"
#include "ExpressDelivery.h"
#include "AirDelivery.h"

int main()
{
	DeliveryRequest req{ 0.0f, 0.0f };

	std::cout << "Enter weight (kg): "; std::cin >> req.weight;
	std::cout << "Enter distance (km): "; std::cin >> req.distance;

	DeliveryContext ctxGround(std::make_unique<GroundDelivery>());
	DeliveryContext ctxAir(std::make_unique<AirDelivery>());
	DeliveryContext ctxExpress(std::make_unique<ExpressDelivery>());

	std::cout << "Ground delivery: " << ctxGround.getCoast(req) << "\n"
		<< "Air delivery: " << ctxAir.getCoast(req) << "\n"
		<< "ExpressDelivery: " << ctxExpress.getCoast(req) << "\n";

}