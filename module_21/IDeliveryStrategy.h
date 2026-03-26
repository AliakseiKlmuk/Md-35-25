#pragma once

struct DeliveryRequest {
	float weight;
	float distance;
};

class IDeliveryStrategy
{
public:
	virtual ~IDeliveryStrategy() = default;
	virtual float calculateCoast(const DeliveryRequest& req) const = 0;
};

