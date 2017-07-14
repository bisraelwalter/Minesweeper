#pragma once
#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "board.h"



#endif

class Minesweeper
{
private:
	Board m_gameboard;
	bool m_gameStatus;
	bool m_gameWinner;
	bool m_cheatCode;

public:
	Minesweeper();
	void startGame();
	void beginnerGame();
	void intermediateGame();
	void expertGame();
	void chooseGame(char choice);
	bool checkChar(char choice);
	void gameInstructions();
	void gameStatusCheck();
	void runningGameLoop();
	void gameWinner();
	void printBoard();
	void printRandomTester();
	void promptUserToEnterLocation();
	void gameOver();
	bool gameEnd();

};