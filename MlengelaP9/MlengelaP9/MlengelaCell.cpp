#include "MlengelaCell.h"

void MlengelaCell::UpdateCells()
{
    // Populate 'nextCellState' appropriately given 'cell'

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            GetLivingNeighbors(i, j);

            // Our rules are simple:
            //
            //    1) A live cell remains alive if it has 3 or more neighbors
            //    2) A dead cell becomes alive if it has 2 or more neighbors

            bool deadCell = true;

            if (cell[i][j] == '*')
            {
                if (count >= 3)
                    deadCell = false;
            }
            else
            {
                if (count >= 2)
                    deadCell = false;
            }

            nextCellState[i][j] = (deadCell ? '.' : '*');
        }
    }
}
