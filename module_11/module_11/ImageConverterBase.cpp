#include "ImageConverterBase.h"
#include <iostream>

//Image ImageConverterBase::convert(const Image& image)
//{
//	std::cout << "ImageConverterBase::convert" << std::endl;
//	return Image(image.path());
//}

void ImageConverterBase::printInfo()
{
	std::cout << "ImageConverterBase::printInfo" << std::endl;
}

ImageConverterBase::~ImageConverterBase()
{
	std::cout << "~ImageConverterBase" << std::endl;
}
