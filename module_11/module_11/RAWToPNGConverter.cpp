#include <iostream>

#include "RAWToPNGConverter.h"

RAWToPNGConverter::RAWToPNGConverter()
{
	_name = "PNG";
}

Image RAWToPNGConverter::convert(const Image& image)
{
	std::cout << "RAWToPNGConverter::convert" << std::endl;
	return Image(image.path());
}

void RAWToPNGConverter::printInfo()
{
	std::cout << "RAWToPNGConverter::printInfo" << std::endl;
}

RAWToPNGConverter::~RAWToPNGConverter()
{
	std::cout << "~RAWToPNGConverter::printInfo" << std::endl;
}
