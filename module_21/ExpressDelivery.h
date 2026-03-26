#pragma once

#include "IDeliveryStrategy.h"

class ExpressDelivery : public IDeliveryStrategy
{
public:
	float calculateCoast(const DeliveryRequest& req) const override {

		return static_cast<float>(req.distance) * 2.0f + static_cast<float>(req.weight) * 4.0f + 10.0f;
	}
};

