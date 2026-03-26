#pragma once
#include <memory>

#include "IDeliveryStrategy.h"

class DeliveryContext
{
	std::unique_ptr<IDeliveryStrategy> strategy;

public:
	DeliveryContext(std::unique_ptr<IDeliveryStrategy> s) : strategy(std::move(s)){}

public:
	float getCoast(const DeliveryRequest& req) const {
		return strategy->calculateCoast(req);
	}
};

