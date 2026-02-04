#include <iostream>
#include <vector>
#include "function.h"

int main()
{
    // решение задачи 6.1
    int N = 0; 
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    // проверка ввода размера массива 
    do {
        std::cout << "Enter the size of the array: "; std::cin >> N;
        if (N <= 0) std::cout << " no correct." << std::endl;
    } while (N <= 0);

    int* arr = new int[N];
    buildArray(arr, N);
    displayArray(arr, N);
   
    /********************************************************************************************/
    // решение задачи 6.2
    std::vector<int> position; // для хранения элементов массива
    int maxValue = findMax(arr, position, N);

    // проверка массива на наличие в нем значений
    if (maxValue == -1) std::cout << "Uncorrect massive"; 
    
    std::cout << "Max value: " << maxValue << std::endl;
    std::cout << "Max position value: ";
    
    for (int index : position) // вывод на экран
    {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    /********************************************************************************************/
   // решение задачи 6.3
    int value_1 = 0, value_2 = 0;
       
    do {   
        std::cout << "Enter value 1: "; std::cin >> value_1;
        std::cout << "Enter value 2: "; std::cin >> value_2;
          
        // проверка вводимых данных, попадания в диапазон имеющихся значений
        if (value_1 >= 0 && value_1 < N && value_2 >= 0 && value_2 < N)
        {
            swap(&arr[value_1], &arr[value_2]);
            break;
        }
        else std::cout << "Incorrect values. Please enter valid indices (0 to " << (N - 1) << ")." << std::endl;

    } while (true);
        
    displayArray(arr, N);

    delete[] arr;
    
    /********************************************************************************************/
    // решение задачи 6.4
    int value = 0, number = 9;
    std::vector<double> average;

    // заполнение массива, обязательный ввод хотя бы одного значения отличного от нуля
    do {
        std::cout << "Enter value (0 to stop): "; std::cin >> number;
        if (number == 0 && value == 0) 
        {
            std::cout << "You must enter a number other than 0." << std::endl;
        }
        else if (number == 0) 
        { 
            break;  
        }
        else 
        {
            average.push_back(number);
            value++;
        }
    }   while (true);
    
    // проверка что массив заполнен
    if (!average.empty()) {
        double arMean = arithmeticMean(average);
        std::cout << arMean << std::endl;
    }
        
    /********************************************************************************************/
    // решение задачи 6.5

    int num = 0;
    std::cout << "Enter number: "; std::cin >> num;
    std::unique_ptr<int> ptr = std::make_unique<int>(num);
    consume(std::move(ptr));

}

