#pragma once
#include <iostream>
#include <string>

#include "Image.h"
#include "IConverter.h"
#include "IPrintInfo.h"

class ImageConverterBase : public IConverter, public IPrintInfo
{
public:
	std::string name() const { return _name; }
	
public:
  	void printInfo() override;

public:
	~ImageConverterBase();

protected:
	std::string _name;
};

