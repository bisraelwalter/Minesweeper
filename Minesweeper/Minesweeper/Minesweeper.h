#pragma once
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "board.h"



#endif

class Minesweeper
{
private:
	Board m_gameboard;
	int amountOfBombs;

public:
	Minesweeper(Board & board);
	bool gameStatusCheck();
	bool gameOver();
	void printBoard(Board & board);
	void printRandomTester(Board & board);
	void promptUserToEnterLocation(Board & board);
	bool gameEnd();

};