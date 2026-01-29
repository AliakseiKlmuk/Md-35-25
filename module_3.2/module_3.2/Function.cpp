#include <random>
#include "Function.h"

int playerRandom(int min, int max)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

bool checkSigns(int numberOld, int numberNew)
{
    return ((numberOld >= 0 && numberNew >= 0) || (numberOld < 0 && numberNew < 0));
}

bool checkWin(int summ)
{
    return summ >= WIN_SCORE;
}