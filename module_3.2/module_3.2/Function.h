#pragma once

// константные переменные
const int WIN_SCORE = 50;
const int WIN_STEP = 100;

// функция счетчика генерации случайных чисел для игрока
int playerRandom(int min, int max);

// проверяет знак числа и меняет его на противоположный
bool checkSigns(int numberOld, int numberNew);

// проверка выигрыша при достижении summ
bool checkWin(int summ);