/*************************************************************************
* Program: Game Of Life
* programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: November 18th , 2022
* Purpose: To implement the game of life using a variety of
* different cell types.
**************************************************************************/
#ifndef MODIFIEDFREDKINCELL_H
#define MODIFIEDFREDKINCELL_H
#include "FredkinCell.h"

class ModifiedFredkinCell : public FredkinCell
{
public:
    ModifiedFredkinCell();
    void UpdateCells();
private:
    int age[ROWS][COLS];

};
#endif // !MODIFIEDFREDKINCELL_H

