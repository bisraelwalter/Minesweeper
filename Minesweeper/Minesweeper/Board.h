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
	int m_row;
	int m_column;

public:
	Board();
	Board(int row, int column, int bombs);
	Board(Board & copy);
	Board & operator=(const Board & rhs);
	void playerMove(Board & board, int row, int column, char moveType);
	void checkMove(Board & board, int row, int column);
	void perimeterCheck(Board & board, int row, int column);
	void gameOver();
	int getRow() const;
	int getColumn() const;
	void setRow(int row);
	void setColumn(int column);
	void printBoard();
};