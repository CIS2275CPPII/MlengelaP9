/*************************************************************************
* Program: Game Of Life
* programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: November 18th , 2022
* Purpose: To implement the game of life using a variety of
* different cell types.
**************************************************************************/

#include "ConwayCell.h"

void ConwayCell::GetLivingNeighbors(int r, int c)
{
    count = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i || j)
            {
                int rValue = r + i;
                int cValue = c + j;

                if (rValue >= 0 && rValue < rows &&
                    cValue >= 0 && cValue < cols)
                {
                    if (cell[rValue][cValue] == '*')
                        count++;
                }
            }
        }
    }
}
void ConwayCell::UpdateCells()
{
    // Populate 'nextCellState' appropriately given 'cell'

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            GetLivingNeighbors(i, j);

            bool deadCell = true;

            if (cell[i][j] == '*')
            {
                if (count == 2 || count == 3)
                    deadCell = false;
            }
            else
            {
                if (count == 3)
                    deadCell = false;
            }
            nextCellState[i][j] = (deadCell ? '.' : '*');
        }
    }
}