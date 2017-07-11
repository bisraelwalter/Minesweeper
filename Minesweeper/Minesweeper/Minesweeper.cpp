#include "Minesweeper.h"


Minesweeper::Minesweeper(Board & board)
{
	this->m_gameboard = board;
}

bool Minesweeper::gameStatusCheck()
{
	int numberOfFlaggedCells = 0;
	return true;
	
}

bool Minesweeper::gameOver()
{
	this->m_gameboard.gameOver();
	return true;
}

void Minesweeper::printBoard()
{
	this->m_gameboard.printBoard();
}
