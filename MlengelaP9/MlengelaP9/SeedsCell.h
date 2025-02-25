#ifndef SEEDSCELL_H
#define SEEDSCELL_H
#include "LifeCell.h"
class SeedsCell: public LifeCell
{
public:
    void GetLivingNeighbors(int r, int c); // row, column
    void UpdateCells();
};
#endif // !SEEDSCELL_H

