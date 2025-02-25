#include "ModifiedFredkinCell.h"

ModifiedFredkinCell::ModifiedFredkinCell()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            age[i][j] = 0;
}

void ModifiedFredkinCell::UpdateCells()
{
    // Populate 'nextCellState' appropriately given 'cell'

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cell[i][j] == '*' && age[i][j] >= 2)
            {
                // This cell is alive and has been for
                // at least two generations, treat it as a conway cell

                int liveCount = 0;

                for (int k = -1; k <= 1; k++)
                {
                    for (int m = -1; m <= 1; m++)
                    {
                        if (k || m)
                        {
                            int rValue = i + k;
                            int cValue = j + m;

                            if (rValue >= 0 && rValue < rows &&
                                cValue >= 0 && cValue < cols)
                            {
                                if (cell[rValue][cValue] == '*')
                                    liveCount++;
                            }
                        }
                    }
                }
                if (liveCount == 2 || liveCount == 3)
                {
                    nextCellState[i][j] = '*';
                    age[i][j]++;
                }
                else
                {
                    nextCellState[i][j] = '.';
                    age[i][j] = 0;
                }
            }
            else
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

                    else
                        age[i][j]++;
                }

                if (next)
                    nextCellState[i][j] = next;

                else
                    nextCellState[i][j] = cell[i][j];

                if (nextCellState[i][j] == '.')
                    age[i][j] = 0;
            }
        }
    }

}

