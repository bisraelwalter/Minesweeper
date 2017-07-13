#include "Board.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Board::Board()
{
	this->m_amountOfBombs = 0;
	this->m_boardArray.setRow(this->m_row = 0);
	this->m_boardArray.setColumn(this->m_column = 0);

}

Board::Board(int row, int column, int bombs)
{
	this->m_boardArray.setRow(row);
	this->m_boardArray.setColumn(column);
	this->m_row = m_boardArray.getRow();
	this->m_column = m_boardArray.getColumn();
	this->m_amountOfBombs = bombs;
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

void Board::playerMove(int row, int column,char moveType)
{
	if (toupper(moveType) == 'F')
	{
		this->m_boardArray[row][column].setStatus('F');
		printBoard();
	}
	if (toupper(moveType) == 'U')
		checkMove(row, column);

}

void Board::checkMove(int row, int column)
{
	if (this->m_boardArray[row][column].getBombStatus())
		gameOver();
	else
	{
		this->m_boardArray[row][column].setStatus(' ');
		perimeterCheck(row, column);
		if (this->m_boardArray[row][column].getNumberOfBombs() > 0)
			this->m_boardArray[row][column].setStatus('0' + this->m_boardArray[row][column].getNumberOfBombs());
	}
}

void Board::perimeterCheck(int row, int column)
{
	//need to create method to check against walls, adjusting row and column in nested loop accordingly

	int numberOfBombs = 0;
	for(int i = (row - 1); i < (row - 1) + 3; i++)
	{
		for (int j = (column - 1); j < (column - 1) + 3; j++)
		{
			
			if (this->m_boardArray[i][j].getBombStatus())
				numberOfBombs++;
		}
	}
	this->m_boardArray[row][column].setNumberOfBombs(numberOfBombs);
	
}

void Board::loadBombsOnBoard()
{
	int * randomNumberHolder = new int[this->m_amountOfBombs];

	srand(time(NULL));
	for (int i = 0; i < this->m_amountOfBombs; i++)
	{
		randomNumberHolder[i] = rand() % (this->m_row * this->m_column) - 1;
		cout << randomNumberHolder[i] << " ";
	}
	cout << endl;
	checkForDuplicateNumbers(randomNumberHolder, this->m_amountOfBombs);

	for (int l = 0; l < this->m_amountOfBombs; l++)
	{
		int row = randomNumberHolder[l] / this->m_column;
		int column = abs((randomNumberHolder[l] - this->m_amountOfBombs) % this->m_column);
		this->m_boardArray[row][column].setBomb();
	}

	delete[] randomNumberHolder;
}

void Board::checkForDuplicateNumbers(int * data, int size)
{
	int duplicateAmount = 0;
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (data[i] == data[j])
				{
					if (data[i] == (this->m_row * this->m_column) - 1)
						data[i] = data[i] - 1;

					data[i] = data[i] + 1;
					duplicateAmount++;
				}
			}
		}
	if (duplicateAmount > 0)
		checkForDuplicateNumbers(data, size);
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

int Board::getAmountOfBombs() const
{
	return this->m_amountOfBombs;
}

void Board::printBoard()
{
	cout << "    ";
	for (int h = 0; h < m_boardArray.getColumn(); h++)
			cout << setw(3) << h + 1;
	cout << endl;

		for (int i = 0; i < m_boardArray.getRow(); i++)
	{
			cout << "[" << i + 1 << "]";
		{
				for (int j = 0; j < m_boardArray.getColumn(); j++)
				{
					if (i < 9 && j == 0)
						cout << " ";
					cout << setw(3) << m_boardArray[i][j].getStatus();
				}
				
		}
		cout << endl;
	}

		cout << "    ";
		for (int h = 0; h < m_boardArray.getColumn(); h++)
			cout << setw(3) << h + 1;
		cout << endl;

		for (int i = 0; i < m_boardArray.getRow(); i++)
		{
			cout << "[" << i + 1 << "]";
			{
				for (int j = 0; j < m_boardArray.getColumn(); j++)
				{
					if (i < 9 && j == 0)
						cout << " ";
					if (m_boardArray[i][j].getBombStatus())
						cout << setw(3) << "B";
					else
					cout << setw(3) << " ";
				}
			}
			cout << endl;
		}
}
