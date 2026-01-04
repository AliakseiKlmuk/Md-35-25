#include <iostream>
#include <string>
#include <algorithm> // Для std::transform
#include <cctype>    // Для tolower/toupper

enum class TrafficLight { UNKNOWN = -1,
                          RED, 
                          YELLOW, 
                          GREEN };

void printLight(TrafficLight color) {

    switch (color) {
    case TrafficLight::RED:
        std::cout << "Red" << std::endl;
        break;
    case TrafficLight::YELLOW:
        std::cout << "Yellow" << std::endl;
        break;
    case TrafficLight::GREEN:
        std::cout << "Green" << std::endl;
        break;
    default:
        std::cout << "Unknown color" << std::endl;
    }
}

int main()
{
    TrafficLight light;
    light = TrafficLight::RED;
    printLight(light);

    std::cout << "Enter color Red, Yellow, Green: " << std::endl;

    std::string color;
    std::cin >> color;
    std::transform(color.begin(), color.end(), color.begin(), ::tolower);

    if (color == "red") {
        printLight(TrafficLight::RED);
    }
    else if (color == "yellow") {
        printLight(TrafficLight::YELLOW);
    }
    else if (color == "green") {
        printLight(TrafficLight::GREEN);
    }
    else {
        printLight(TrafficLight::UNKNOWN);
    }
}
