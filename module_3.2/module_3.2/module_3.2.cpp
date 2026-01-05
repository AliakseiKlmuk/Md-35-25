
#include <iostream>
#include <random>

int generation_random(int min, int max);
int first_gamer();
int second_gamer();
bool checkDifferentSigns(int a, int b);

int main()
{
    int valueFirstGamerOld = first_gamer();
    int valueSecondGamerOld = second_gamer();

    int summ{ 0 };
    int step{ 0 };

    while (true) {

        int valueFirstGamerNew = first_gamer();
        int valueSecondGamerNew = second_gamer();

        if (step % 2 == 0) {     //выбор хода игрока (проверка на четность)

            while (checkDifferentSigns(valueFirstGamerOld, valueFirstGamerNew)) {  //перебираем числа пока не поменяеться знак
                valueFirstGamerNew = first_gamer();
            }

            /*if (checkDifferentSigns(valueFirstGamerOld, valueFirstGamerNew)) {   //меняем знак числа
                valueFirstGamerNew = valueFirstGamerNew * -1;
            }*/

            valueFirstGamerOld = valueFirstGamerNew;
            summ += valueFirstGamerOld;

            if (summ >= 50) {      //оканчиваем игру при достижения значения общего счетчика 
                std::cout << "The first player won!" << std::endl;
                break;
            }
        }

        else {
            while (checkDifferentSigns(valueSecondGamerOld, valueSecondGamerNew)) {  //перебираем числа пока не поменяеться знак
                valueSecondGamerNew = second_gamer();
            }

            /*if (checkDifferentSigns(valueSecondGamerOld, valueSecondGamerNew)) {   //меняем знак числа
                 valueSecondGamerNew = valueSecondGamerNew * -1;
            }*/

            valueSecondGamerOld = valueSecondGamerNew;
            summ += valueSecondGamerOld;

            if (summ >= 50) {  //оканчиваем игру при достижения значения общего счетчика
                std::cout << "The second player won!" << std::endl;
                break;
            }
        }

        if (step == 100) {     //оканчиваем игру при достижении числа ходов
            std::cout << "The game ended in a draw!" << std::endl;
            break;
        }

        /*std::cout << "step: " << step << " first: "
            << valueFirstGamerOld << " second : " << valueSecondGamerOld
            << " summ : " << summ << std::endl;*/
        step += 1;
    }
}

/// <summary>
/// Генератор случайной последовательности
/// </summary>
/// <param name="min"> нижняя граница случайных числел </param>
/// <param name="max"> верхняя граница случайных числел </param>
/// <returns> выводит знанчение случайных чисел </returns>
int generation_random(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

/// <summary>
/// Функци которая генерирует случайные числа для первого игрока
/// </summary>
/// <returns> выводи значения чисел в промежутке от -5 до 5 </returns>
int first_gamer() {
    int min{ -5 };
    int max{ 5 };

    return generation_random(min, max);
}

/// <summary>
/// Функци которая генерирует случайные числа для второго игрока
/// </summary>
/// <returns> выводи значения чисел в промежутке от -5 до 5 </returns>
int second_gamer() {
    int min{ -5 };
    int max{ 5 };

    return generation_random(min, max);
}

/// <summary>
/// Функция которая производит сравнение числел по знаку
/// </summary>
/// <param name="numberOld"> новое число </param>
/// <param name="numberNew"> старое число </param>
/// <returns> выводит true или false, принимаем ноль за положительное число</returns>
bool checkDifferentSigns(int numberOld, int numberNew) {
    return ((numberOld >= 0 && numberNew >= 0) || (numberOld < 0 && numberNew < 0));
}