#include "SeedsCell.h"

void SeedsCell::GetLivingNeighbors(int r, int c)
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
void SeedsCell::UpdateCells()
{
    // Populate 'nextCellState' appropriately given 'cell'

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            GetLivingNeighbors(i, j);

            char next = '.';

            if (cell[i][j] == '.' && count == 2)
                next = '*';

            nextCellState[i][j] = next;
        }
    }
}

