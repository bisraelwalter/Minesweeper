#include "Cell.h"




Cell::Cell()
{
	this->m_cellStatus = '?';
	this->m_covered = true;
	this->m_empty = false;
	this->m_flagged = false;
	this->m_bomb = false;
	this->m_numberOfBombs = 0;
}

char Cell::getStatus() const
{
	return this->m_cellStatus;
}

void Cell::setStatus(char status)
{
	this->m_cellStatus = status;
}

bool Cell::getCovered() const
{
	return this->m_covered;
}

void Cell::setCovered(char state)
{
	this->m_covered = state;
}

bool Cell::getEmpty() const
{
	return this->getEmpty();
}

void Cell::setEmpty(char state)
{
	this->m_empty = state;
}

bool Cell::getFlagged() const
{
	return this->getFlagged();
}

void Cell::setFlagged(char state)
{
	this->m_flagged = state;
}

bool Cell::getBombStatus() const
{
	return this->m_bomb;
}

void Cell::setBomb()
{
	this->m_bomb = true;
}

const int Cell::getNumberOfBombs() const
{
	return this->m_numberOfBombs;
}

void Cell::setNumberOfBombs(int numberOfBombs)
{
	this->m_numberOfBombs = numberOfBombs;
}
