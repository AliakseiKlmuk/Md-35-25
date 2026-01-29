
#include <iostream>
#include "Function.h"

int main()
{
    int valueFirstGamerOld = 0;
    int valueSecondGamerOld = 0;
    
    int summ = 0;
    int step = 0;

    while (true) {

        int valueFirstGamerNew = playerRandom(0, 5);
        int valueSecondGamerNew = playerRandom(0, 5);

        // последовательное включение игроков
        switch (step%2)
        {
        case 0:
            if (checkSigns(valueFirstGamerOld, valueFirstGamerNew)) 
            {   
                valueFirstGamerNew *= -1;
            }
            valueFirstGamerOld = valueFirstGamerNew;
            summ += valueFirstGamerOld;
            break;

        default:
            if (checkSigns(valueSecondGamerOld, valueSecondGamerNew)) 
            {   
                valueSecondGamerNew *= -1;
            }
            valueSecondGamerOld = valueSecondGamerNew;
            summ += valueSecondGamerOld;
            break;

        }

        // проверка выигрыша и вывод победителя
        if (checkWin(summ))
        {
            std::cout << "The " << (step % 2 == 0 ? "first" : "second") << " player is won!" << std::endl;
            break;
        }

        step++;

        // проверка окончания игры
        if (summ < WIN_SCORE && step >= WIN_STEP) {
            std::cout << "The game ended in a draw!" << std::endl;
            break;
        }
         
        // отображение хода игры
        std::cout << "step: " << step << " first: "
              << valueFirstGamerOld << " second : " 
              << valueSecondGamerOld
              << " summ : " << summ << std::endl;
    
    }
}
