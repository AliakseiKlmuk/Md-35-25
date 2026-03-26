#pragma once

#include "IDeliveryStrategy.h"

class AirDelivery : public IDeliveryStrategy
{
public:
	float calculateCoast(const DeliveryRequest& req) const override {

		return static_cast<float>(req.distance) * 1.5f + static_cast<float>(req.weight) * 3.0f;
	}
};

