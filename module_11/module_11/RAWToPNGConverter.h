#pragma once

#include "ImageConverterBase.h"
#include "IConverter.h"

class RAWToPNGConverter :public ImageConverterBase
{
public:
	RAWToPNGConverter();
	virtual Image convert(const Image& image) override;
	void printInfo();

public:
	~RAWToPNGConverter();

};

