#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "Array2D.h"
#include "Cell.h"
#endif

class Cell;

class Board
{
private:
	Array2D<Cell> m_boardArray;
	int m_amountOfBombs;
	int m_inCellAmoungOfBombs;
	int m_row;
	int m_column;
	int m_uncoveredCells = 0;
	int m_flaggedCells = 0;
	bool m_gameStatus = false;
	bool m_playersBoardEntry = false;

public:
	Board();
	Board(int row, int column, int bombs);
	Board(Board & copy);
	Board & operator=(const Board & rhs);
	void playerMove(int row, int column, char moveType);
	void playerMoveParameterCheck(int row, int column, char moveType);
	bool getPlayerBoardEntry() const;
	bool checkMove(int row, int column);
	void perimeterCheck(int row, int column);
	void checkPerimeterCellLoop(int &row, int &column, int &countRow, int &countCol);
	void checkCellsOfPerimeterLoop(int row, int column, int countRow, int countCol);
	void checkForTheEdgeOfBoard(int &rows, int &columns, int & countRow, int & countCol) const;
	void cellIsClearCheckPerimeterCells(int row, int column, int &countRow, int &countCol);
	void loadBombsOnBoard();
	void checkForDuplicateNumbers(int * data, int size) const;
	void gameOver();
	int getRow() const;
	int getColumn() const;
	void setRow(int row);
	void setColumn(int column);
	int getAmountOfBombs() const;
	int getUncoveredCells() const;
	int getFlaggedCells() const;
	bool getGameStatus();
	void printBoard();
	void printBombMap();
};