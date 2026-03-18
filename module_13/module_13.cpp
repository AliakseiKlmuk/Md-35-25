#include <iostream>
#include <stdexcept>
#include <cmath>

constexpr double PI = 3.1415;

enum class Operation {
	CIRCLE_AREA,
	DIVISION,
	SQUARE_ROOT,
	LOGARITHM
};

double calculate(double value1, double value2, Operation operation) {

	auto division_lambda = [](double value1, double value2) {
		if (value2 == 0.0) {
			throw std::invalid_argument("Error: Division by zero.");
		}
		return value1 / value2;
		};
	return division_lambda(value1, value2);
}

double calculate(double value1, Operation operation) {
	auto square_root_lambda = [](double value1) {
		if (value1 < 0.0) {
			throw std::domain_error("Error: Square root of negative number.");
		}
			return std::sqrt(value1);
		};

	auto logarithm_lambda = [](double value1) {
		if (value1 <= 0.0) {
			throw std::invalid_argument("Error: Logarithm of non-positive number.");
		}
			return std::log(value1);
		};

	auto calcCircleArea_lambda = [](double value1) {
		if (value1 < 0.0) {
			throw std::invalid_argument("Error: Radius cannot be negative.");
		}
			return PI * value1 * value1;
		};

	switch (operation) {
	case Operation::SQUARE_ROOT:
		return square_root_lambda(value1);
	case Operation::LOGARITHM:
		return logarithm_lambda(value1);
	case Operation::CIRCLE_AREA:
		return calcCircleArea_lambda(value1);
	default:
		throw std::invalid_argument("Error: Unknown operation");
	}
};

int main()
{
	try {

		std::cout << "Devision: " << calculate(12, 0, Operation::DIVISION) << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Caught expection: " << e.what() << std::endl;
	}


	try {
		std::cout << "Square: " << calculate(-1, Operation::SQUARE_ROOT) << std::endl;
	}
	catch (const std::domain_error& e) {
		std::cerr << "Caught domain error: " << e.what() << std::endl;
	}


	try {
		std::cout << "Logarithm: " << calculate(-1, Operation::LOGARITHM) << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Caught expection: " << e.what() << std::endl;
	}


	try {
		std::cout << "Circle Area: " << calculate(-1, Operation::CIRCLE_AREA) << std::endl;

	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Caught expection: " << e.what() << std::endl;
	}

	return 0;

}
