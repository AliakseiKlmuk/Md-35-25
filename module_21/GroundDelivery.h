#pragma once

#include "IDeliveryStrategy.h"

class GroundDelivery : public IDeliveryStrategy
{
public:
	float calculateCoast(const DeliveryRequest& req) const override {

		return static_cast<float>(req.distance) * 1.0f + static_cast<float>(req.weight) * 2.0f;
	}
};

