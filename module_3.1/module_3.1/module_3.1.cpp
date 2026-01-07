#include <iostream>
#include <string>
#include <algorithm> // Для преобразования регистра слова
#include <cctype>    // Для преобразования в верхний/нижний регистр

enum class TrafficLight { UNKNOWN = -1,
                          RED, 
                          YELLOW, 
                          GREEN };

void printLight(TrafficLight color) { // функция выводит значение
    switch (color) {
    case TrafficLight::RED:
        std::cout << "You selected the Red color" << std::endl;
        break;
    case TrafficLight::YELLOW:
        std::cout << "You selected the Yellow color" << std::endl;
        break;
    case TrafficLight::GREEN:
        std::cout << "You selected the Green color" << std::endl;
        break;
    default:
        std::cout << "Unknown color" << std::endl;
    }
}

TrafficLight selectLight(std::string color) { // функция производит выборку цвета
    if (color == "red") {
        return TrafficLight::RED;
    }
    else if (color == "yellow") {
        return TrafficLight::YELLOW;
    }
    else if (color == "green") {
        return TrafficLight::GREEN;
    }
    else {
        return TrafficLight::UNKNOWN;
    }
}

int main() {
    std::cout << "Enter color Red, Yellow, Green: " << std::endl;

    std::string color;
    std::cin >> color;

    std::transform(color.begin(), color.end(), color.begin(), ::tolower); // преобразуем все символы в нижний регистр

    TrafficLight light = selectLight(color); // получаем значение TrafficLight
        
    printLight(light); // печатаем значение с помощью printLight

}
