#include "Minesweeper.h"


Minesweeper::Minesweeper()
{
	this->m_flaggedCells = 0;
}

void Minesweeper::startGame()
{
	char choice;
	bool runningLoop = false;

	cout << "Play a game of minesweeper?" << endl;

	while (!runningLoop)
	{
		cout << "Choose a level: (B) for beginner, (I) for intermediate, (E) for expert: ";
		cin >> choice;
		cout << endl;
		runningLoop = checkChar(choice);
		if (!runningLoop)
			cout << "Selection needs to be a (B), (I), or (E)" << endl;
	}
	chooseGame(choice);
	runningGameLoop();
}

void Minesweeper::beginnerGame()
{
	Board beginnerGame(10, 10, 10);
	beginnerGame.loadBombsOnBoard();
	this->m_gameboard = beginnerGame;
}

void Minesweeper::intermediateGame()
{
	Board intermediateGame(16, 16, 40);
	intermediateGame.loadBombsOnBoard();
	this->m_gameboard = intermediateGame;
}

void Minesweeper::expertGame()
{
	Board expertGame(16, 30, 100);
	expertGame.loadBombsOnBoard();
	this->m_gameboard = expertGame;
}

void Minesweeper::chooseGame(char choice)
{
	char upperChoice = toupper(choice);
	if (upperChoice == 'B') beginnerGame();
	if (upperChoice == 'I') intermediateGame();
	if (upperChoice == 'E') expertGame();
}

bool Minesweeper::checkChar(char choice)
{
	char upperChoice = toupper(choice);
	if (upperChoice == 'B' || upperChoice == 'I' || upperChoice == 'E')
		return true;

	return false;
}

void Minesweeper::gameStatusCheck()
{
	int doesFlaggedHaveBomb = 0;
	if (this->m_flaggedCells == this->m_gameboard.getAmountOfBombs())
	{
		for(int i = 0; i < this->m_gameboard.getRow(); i++)
		{
			for(int j = 0; j < this->m_gameboard.getColumn(); j++)
			{
				if(this->m_gameboard.)
			}
		}
	}
		this->m_gameStatus = true;	
}

void Minesweeper::runningGameLoop()
{
	while (!this->m_gameStatus)
	{
		printBoard();
		promptUserToEnterLocation();
		gameStatusCheck();
	}
	gameWinner();
}

void Minesweeper::gameWinner()
{
	cout << "CONGRATULATIONS. YOU'VE WON!!!!!!!!" << endl;
}

void Minesweeper::printBoard()
{
		this->m_gameboard.printBoard();
}

void Minesweeper::printRandomTester()
{
	this->m_gameboard.loadBombsOnBoard();
}

void Minesweeper::promptUserToEnterLocation()
{	
	int row;
	int column;
	char flagOrUncover;
	cout << "Enter location on board: ";
	cin >> flagOrUncover >> row >> column;
	cout << endl;

	this->m_gameboard.playerMove(row - 1, column - 1, flagOrUncover);

}

bool Minesweeper::gameEnd()
{
	return false;
}
