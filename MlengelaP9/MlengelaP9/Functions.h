/*************************************************************************
* Program: Game Of Life
* programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: November 18th , 2022
* Purpose: To implement the game of life using a variety of
* different cell types.
**************************************************************************/

#include<iostream>
#include<Windows.h>
#include"LifeCell.h"

using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
class Functions
{
	void WriteInstructions();
	int UserChoosesAnImplementation();
	string UserChoosesInitialPattern();

};
void WriteHeader();      // Writing header of the game of life
void GoodBye();          // saying goodbye to a user
bool DoAnother();         // Ask the user to do another
#endif // !FUNCTION_H

