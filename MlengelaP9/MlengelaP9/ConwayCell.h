/*************************************************************************
* Program: Game Of Life
* programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: November 18th , 2022
* Purpose: To implement the game of life using a variety of
* different cell types.
**************************************************************************/
#ifndef CONWAYCELL_H
#  define CONWAYCELL_H

#  include "LifeCell.h"
class ConwayCell : public LifeCell
{
 public:
    void GetLivingNeighbors(int r, int c);
    void UpdateCells();
};

#endif
