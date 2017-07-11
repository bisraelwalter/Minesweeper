#pragma once
#ifndef CELL_H
#define CELL_H
#include "Board.h"

class Board;

class Cell
{
private:
	char m_cellStatus;
	bool m_covered;
	bool m_empty;
	bool m_flagged;
	bool m_bomb;
	int m_numberOfBombs;

public:
	Cell();
	char getStatus() const;
	void setStatus(char status);
	bool getCovered() const;
	void setCovered(char state);
	bool getEmpty() const;
	void setEmpty(char state);
	bool getFlagged() const;
	void setFlagged(char state);
	bool getBomb() const;
	void setBomb(char state);
	int getNumberOfBombs() const;
	void setNumberOfBombs(int numberOfBombs);

};

#endif
