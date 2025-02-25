#include<iostream>
#include<fstream>
#include "LifeCell.h"

void LifeCell::InitializeBoard()
{
    std::ifstream in(pattern);

    if (!in)
    {
        std::cout << "Could not open pattern file: [" << pattern << "]\n";
        bOpen = false;
        return;
    }

    bOpen = true;
    in >> rows >> cols;

    string line;
    getline(in, line);

    for (int i = 0; i < rows; i++)
    {
        getline(in, line);

        for (int j = 0; j < cols; j++)
            cell[i][j] = line[j];
    }
}

void LifeCell::SetNextState()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cell[i][j] = nextCellState[i][j];
}

LifeCell::LifeCell()
{
    // Set all cells to '.' initially (dead)
    Clear();
}

void LifeCell::SetPattern(string pat)
{
    pattern = pat;
    InitializeBoard();
}

void LifeCell::UpdateBoard()
{
    UpdateCells();
    SetNextState();
}

string LifeCell::PrintBoard()
{
    string theString;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            theString += cell[i][j];

        theString += "\n";
    }
    return(theString);
}

void LifeCell::Clear()
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cell[i][j] = '.';
}

bool LifeCell::FileOpen()
{
    return (bOpen);
}
