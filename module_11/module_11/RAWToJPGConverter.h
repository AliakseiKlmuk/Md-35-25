#pragma once

#include "ImageConverterBase.h"
#include "IConverter.h"

class RAWToJPGConverter :public ImageConverterBase
{
public:
	RAWToJPGConverter();
	virtual Image convert(const Image& image) override;
	void printInfo();

public:
	~RAWToJPGConverter();
 
};

