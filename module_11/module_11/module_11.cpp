#include <iostream>

#include "Image.h"
#include "ImageConverterBase.h"

#include "RAWToJPGConverter.h"
#include "RAWToPNGConverter.h"

#include "IConverter.h"
#include "IPrintInfo.h"

int main()
{
 
    IConverter* converter = nullptr;
    std::string converterType;
    std::cin >> converterType;

    if (converterType == "jpg")
    {
        converter = new RAWToJPGConverter();
    }
    else
    {
        converter = new RAWToPNGConverter();
    }

    if (auto printable = dynamic_cast<IPrintInfo*>(converter))
    {
        printable->printInfo();
    }

    if (auto jpgConverter = dynamic_cast<RAWToJPGConverter*>(converter))
    {
        jpgConverter->printInfo();
    }

    if (auto pngConverter = dynamic_cast<RAWToPNGConverter*>(converter))
    {
        pngConverter->printInfo();
    }
    
    delete converter;

    //std::cout << converter->name() << std::endl;

    //Image image{ "/etc/images/1.gpg" };
    //converter->convert(image);
    ////converter->printInfo();
}
