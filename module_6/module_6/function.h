#pragma once

// заполнение массива
void buildArray(int* array, int coin);

// поиск максимального значения массива и его позицию в массиве
int findMax(const int* arr, std::vector<int>& position, int size); 

// смена мест элементов массива
void swap(int* a, int* b); 

// вычисление среднего арифметического из всех элементов массива
double arithmeticMean(std::vector<double>& average); 

// 
void consume(std::unique_ptr<int> p);

// помощь

// вывод элементов массива
void displayArray(int* array, int coin);
