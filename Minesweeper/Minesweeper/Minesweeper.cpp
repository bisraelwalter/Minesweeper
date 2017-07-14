#include "Minesweeper.h"


Minesweeper::Minesweeper()
{
	this->m_gameStatus = false;
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
	int spacesWithoutBombs = (this->m_gameboard.getRow() * this->m_gameboard.getColumn())
	- this->m_gameboard.getAmountOfBombs();

	if (this->m_gameboard.getFlaggedCells() == this->m_gameboard.getAmountOfBombs())
		if(this->m_gameboard.getUncoveredCells() == spacesWithoutBombs)
		this->m_gameStatus = true;	
}

void Minesweeper::runningGameLoop()
{
	while (!this->m_gameStatus)
	{
		//system("cls");
		printBoard();
		this->m_gameboard.printBombMap(); //put in cheat code
		promptUserToEnterLocation();
		gameStatusCheck();
		if (this->m_gameboard.getGameStatus())
			gameOver();
	}
}

void Minesweeper::gameWinner()
{
	cout << "CONGRATULATIONS. YOU'VE WON!!!!!!!!" << endl;
	this->m_gameStatus = true;
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
	char flagUncoverRemove;
	while (!this->m_gameboard.getPlayerBoardEntry())
	{
	cout << "Enter location on board: ";
	cin >> flagUncoverRemove >> row >> column;
	cout << endl;

		if (!this->m_gameboard.getPlayerBoardEntry())
			cout << "That is not a valid entry, please re-enter" << endl;
		this->m_gameboard.playerMoveParameterCheck(row - 1, column - 1, flagUncoverRemove);
		//this->m_gameboard.playerMove(row - 1, column - 1, flagUncoverRemove);
	}
	this->m_gameboard.playerMove(row - 1, column - 1, flagUncoverRemove);
}

void Minesweeper::gameOver()
{
	this->m_gameboard.gameOver();
	this->m_gameStatus = true;
}

bool Minesweeper::gameEnd()
{
	char choice;
	cout << "Want to play another game? (Y) or any key to exit: ";
	cin >> choice;
	
	if (toupper(choice) == 'Y')
		return true;

	return false;
}
