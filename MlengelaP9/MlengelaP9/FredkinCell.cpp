#include "FredkinCell.h"

void FredkinCell::GetLivingNeighbors(int r, int c)
{
    count = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i && j)
                continue;

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
void FredkinCell::UpdateCells()
{
    // Populate 'nextCellState' appropriately given 'cell'

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            GetLivingNeighbors(i, j);

            char next = '\0';

            if (cell[i][j] == '.')
            {
                if (count == 1 || count == 3)
                    next = '*';
            }
            else
            {
                if (count == 0 || count == 2 || count == 4)
                    next = '.';
            }

            if (next)
                nextCellState[i][j] = next;

            else
                nextCellState[i][j] = cell[i][j];
        }
    }
}

