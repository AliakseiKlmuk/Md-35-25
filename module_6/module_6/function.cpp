#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "function.h"

void buildArray(int* array, int size) 
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % (9 - 1 + 1) + 1;
    }
}

int findMax(const int* arr, std::vector<int>& position, int size)
{
    if (size <= 0) {
        position.clear();
        return -1;
    }

    position.clear();
    position.push_back(0);

    int value = arr[0];

    // поиск максимального значения и его позиции в массиве
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > value)
        {
            value = arr[i];
            position.clear();
            position.push_back(i);
        }
        else if (arr[i] == value)
        {
            position.push_back(i);
        }
    }
    return value;
}

void swap(int* a, int* b)
{
    int value;

    value = *b;
    *b = *a;
    *a = value;
}

double arithmeticMean(std::vector<double>& average)
{
    double summ = 0.0;
    for (double value : average)
    {
        summ += value;
    }
    std::cout << std::endl;
    
    double result = static_cast<double>(summ) / average.size();
    
    return result;
}

void consume(std::unique_ptr<int> p)
{
    std::cout << *p << std::endl;
    (*p)++;
    std::cout << *p << std::endl;
}

void displayArray(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
