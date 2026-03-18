#pragma once
class Car
{
public:
	virtual ~Car() = default;
	virtual void Repair() = 0;
	virtual bool IsRepaired() const = 0;
};

