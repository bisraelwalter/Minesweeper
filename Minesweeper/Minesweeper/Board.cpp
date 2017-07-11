#include "Board.h"
#include <iomanip>
#include <iostream>

Board::Board()
{
	this->m_amountOfBombs = 0;
	this->m_boardArray.setRow(this->m_row = 0);
	this->m_boardArray.setColumn(this->m_column = 0);

}

Board::Board(int row, int column, int bombs)
{
	this->m_amountOfBombs = bombs;
	this->m_boardArray.setRow(row);
	this->m_boardArray.setColumn(column);
	this->m_row = m_boardArray.getRow();
	this->m_column = m_boardArray.getColumn();
	
}

Board::Board(Board & copy)
{
	this->m_boardArray = copy.m_boardArray;
	this->m_row = copy.m_row;
	this->m_column = copy.m_column;
}

Board & Board::operator=(const Board & rhs)
{
	this->m_boardArray = rhs.m_boardArray;
	this->m_row = rhs.m_row;
	this->m_column = rhs.m_column;
	return *this;
}

void Board::playerMove(Board & board, int row, int column, char moveType)
{
	if (moveType == 'F')
		board.m_boardArray[row][column].setStatus('F');
	if (moveType == 'U')
		checkMove(board, row, column);
}

void Board::checkMove(Board & board, int row, int column)
{
	if (board.m_boardArray[row][column].getBomb())
		gameOver();
	else
		board.m_boardArray[row][column].setStatus('.');
		perimeterCheck(board, row, column);
}

void Board::perimeterCheck(Board & board, int row, int column)
{
	int numberOfBombs = 0;
	for(int i = (row - 1); i < 3; i++)
	{
		for (int j = (column - 1); j < 3; j++)
		{
			if (board.m_boardArray[i][j].getBomb())
				numberOfBombs++;
		}
	}
	board.m_boardArray[row][column].setNumberOfBombs(numberOfBombs);
	
}

void Board::gameOver()
{
	cout << "BOOM!!!!!!!!" << endl;
	cout << "GAME OVER" << endl;
}

int Board::getRow() const
{
	return this->m_row;
}

int Board::getColumn() const
{
	return this->m_column;
}

void Board::setRow(int row)
{
	this->m_boardArray.setRow(row);
	this->m_row = m_boardArray.getRow();
}

void Board::setColumn(int column)
{
	this->m_boardArray.setColumn(column);
	this->m_column = m_boardArray.getColumn();
}

void Board::printBoard()
{
		for (int i = 0; i < m_boardArray.getRow(); i++)
	{
		for (int j = 0; j < m_boardArray.getColumn(); j++)
			cout << setw(2) << m_boardArray[i][j].getStatus();
		cout << endl;
	}
}
