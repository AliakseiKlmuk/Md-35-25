#include "RAWToJPGConverter.h"
#include <iostream>

RAWToJPGConverter::RAWToJPGConverter()
{
	_name = "JPG";
}

Image RAWToJPGConverter::convert(const Image& image)
{
	std::cout << "RAWToJPGConverter::convert" << std::endl;
	return Image(image.path());
}

void RAWToJPGConverter::printInfo()
{
	std::cout << "RAWToJPGConverter::printInfo" << std::endl;
}

RAWToJPGConverter::~RAWToJPGConverter()
{
	std::cout << "~RAWToJPGConverter::printInfo" << std::endl;
}
