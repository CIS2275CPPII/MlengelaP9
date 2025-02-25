/*************************************************************************
* Program: Game Of Life
* programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: November 18th , 2022
* Purpose: To implement the game of life using a variety of
* different cell types.
**************************************************************************/
#include <iostream>
#include <windows.h>

#include "ModifiedFredkinCell.h"
#include "MlengelaCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "SeedsCell.h"
#include"Functions.h"

int main()
{
    WriteHeader();

    LifeCell* pLife[5];

    ConwayCell          con;
    FredkinCell         fred;
    ModifiedFredkinCell modFred;
    SeedsCell           seed;
    MlengelaCell        mc;

    pLife[0] = &con;
    pLife[1] = &fred;
    pLife[2] = &modFred;
    pLife[3] = &seed;
    pLife[4] = &mc;

    do
    {
        std::cout << "Cell types:\n";
        std::cout << "   1) Conway\n";
        std::cout << "   2) Fredkin\n";
        std::cout << "   3) ModifiedFredkin\n";
        std::cout << "   4) Seeds\n";
        std::cout << "   5) Mlengela\n";

        int config = 0;
        std::cin >> config;

        if (config < 1 || config > 5)
        {
            std::cout << "Please enter a number from 1 to 5!\n";
            continue;
        }

        // Config is 1-based, our array is 0-based
        --config;

        std::cout << "Patterns:\n";
        std::cout << "   pulsar.txt\n";
        std::cout << "   cross.txt\n";
        std::cout << "   x.txt\n";
        std::cout << "   blinker.txt\n";
        std::cout << "   glider.txt\n";

        string pattern;
        std::cin >> pattern;

        pLife[config]->SetPattern(pattern);

        if (pLife[config]->FileOpen())
        {
            int lifeCount = 0;

            do
            {
                pLife[config]->UpdateBoard();
                std::cout << pLife[config]->PrintBoard();
                Sleep(150);
                system("cls");
                lifeCount++;

            } while (lifeCount < 200);
        }
    } while (DoAnother());
    GoodBye();
	return 0;
}