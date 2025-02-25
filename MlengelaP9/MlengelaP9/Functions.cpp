#include "Functions.h"
#include <iostream>

void Functions::WriteInstructions()
{
	std::cout << "\n\n\t Here are the rules of the Game of Life:"
		<< "\n\n 1. Conway: Cells evolve depending on how many of its 8 neighbours:"
		<< "\n The rules for going from one generation to the next for Conway Cells are:"
		<< "\n ** A dead cell becomes a live cell, if exactly 3 neighbours are alive."
		<< "\n ** A live cell becomes a dead cell if less than 2 or more than 3 neigbours are: "
		<< " ** Otherwise it stays the same."
		<< "\n\n 2. Fredkin: Cells stay alive depending on how many of its 4 neighbours are a "
		<< " The rules from going from one generation to the next for Fredkin Cells are: "
		<< "\n ** A dead cell becomes a live cell if 1 or 3 neighbours are alive."
		<< "\n ** A live cell becomes a dead cell, if 0, 2, or 4 neigbours are alive."
		<< "\n ** Otherwise it stays the same. "
		<< "\n\n 3. A mixture of Fredkin and Conway: The cells begin as Fredkin cells,"
		<< "\n If a Fredkin Cell's age becomes 2, then it becomes a live Conway Cell instead. "
		<< "\n\n 4. Seeds: Seeds is a pattern of chaotic evolution. \n Cells evolve depending "
		<< "its 8 neigbours are alive."
		<< "\n The rules for going from one generation to the next for Seeds are: "
		<< "\n ** A cell becomes a live cell if it is dead but has exactly 2 neigbours that are:"
		<< "\n ** All other live cells become dead."
		<< "\n\n 5. Alex: Alex is a variant of Conway, except that death by overpopulation "
		<< "\n comes if neighbours > 7, death by underpopulation comes if neighbours < 2 "
		<< "\n and rebirth by reproduction comes if neighbours == 2.";
}

int Functions::UserChoosesAnImplementation()
{
    return 0;
}

string Functions::UserChoosesInitialPattern()
{
    return string();
}

void WriteHeader()
{
	std::cout << "----------------------------------------------------------------\n";
	std::cout << "Name: Daudi Mlengela\n";
	std::cout << "Program title: the game of life\n";
	std::cout << "Program objective: To implement the game of life using" <<
		         "variety of  different cell types\n";
	std::cout << "----------------------------------------------------------------\n";
}

void GoodBye()
{
	std::cout << "\n\n GoodBye - hope you enjoyed my Game of Life with a variety of patterns! "
		      << endl << endl;
}

bool DoAnother()
{
	string doAgain;
	std::cout << "Try Another game? yes/no    ";
	getline(cin, doAgain);
	if (doAgain == "yes") {
		return true;
	}
	return false;
}
