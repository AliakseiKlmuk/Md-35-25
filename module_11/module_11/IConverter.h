#pragma once
#include "Image.h"

class IConverter
{
public:
	virtual Image convert(const Image& image) = 0;
	virtual std::string name() const = 0;

	virtual ~IConverter() {};
};

