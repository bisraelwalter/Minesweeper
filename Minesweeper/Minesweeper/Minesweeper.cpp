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

void Minesweeper::printBoard(Board & board)
{
		board.printBoard();
}

void Minesweeper::printRandomTester(Board & board)
{
	m_gameboard.loadBombsOnBoard(board);
}

void Minesweeper::promptUserToEnterLocation(Board & board)
{	
	int row;
	int column;
	char flagOrUncover;
	cout << "Enter location on board: ";
	cin >> flagOrUncover >> row >> column;
	cout << endl;

	board.playerMove(board, row - 1, column - 1, flagOrUncover);

}

bool Minesweeper::gameEnd()
{
	return false;
}
