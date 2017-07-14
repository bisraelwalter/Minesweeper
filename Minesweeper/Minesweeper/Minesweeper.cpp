#include "Minesweeper.h"


Minesweeper::Minesweeper()
{
	this->m_gameStatus = false;
	this->m_gameWinner = false;
	this->m_cheatCode = false;
}

void Minesweeper::startGame()
{
	char choice;
	char cheat = 'N';
	bool runningLoop = false;

	cout << "                    <<<<<<<<<<< MINESWEEPER >>>>>>>>>>>" << endl << endl << endl;

	while (!runningLoop)
	{
		cout << "Choose a level: (B) for beginner, (I) for intermediate, (E) for expert: ";
		cin >> choice;
		cout << endl;

		if (toupper(choice) == 'C')
		{
			this->m_cheatCode = true;
			cout << "Cheat Code Initialized" << endl;
			cout << "Choose a level: (B) for beginner, (I) for intermediate, (E) for expert: ";
			cin >> choice;
			cout << endl;
		}

		runningLoop = checkChar(choice);
		if (!runningLoop)
			cout << "Selection needs to be a (B), (I), or (E)" << endl;
	}
	gameInstructions();
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

void Minesweeper::gameInstructions() 
{
	bool instructionLoop = false;
	char endInstructions;

	while (!instructionLoop)
	{
		cout << "Try to clear the minefield without opening a mine" << endl;
		cout << endl;
		cout << "How to play?" << endl;
		cout << endl;
		cout << "You will have three inputs with spaces in between each input" << endl;
		cout << "The first input is a letter. There are three letter choices." << endl;
		cout << "Uncover a cell, the input letter is 'U'. (sidenote: letters can be upper or lowercase)" << endl;
		cout << "Flag a cell to mark as a bomb, the input letter is 'F'." << endl;
		cout << "Remove a flag that was previously marked, the input letter is 'R'." << endl;
		cout << endl;
		cout << "The next two inputs are your coordinates" << endl;
		cout << endl;
		cout << "Examples of proper input:" << endl;
		cout << "F 4 5 - This will flag a cell at row 4 column 5." << endl;
		cout << "U 6 9 - This will uncover a cell at row 6 column 9." << endl;
		cout << "R 9 3 - This will remove a flag at row 9 column 3." << endl;
		cout << endl;
		cout << "If you uncover a cell that does not have a bomb in the adjacent cells," << endl;
		cout << "those adjacent cell will be uncovered too." << endl;
		cout << endl;
		cout << "How to win.....Flag all the bombs and uncover all the cells!!!!!!" << endl;
		

		cout << "Enter (Y) to play: ";
		cin >> endInstructions;
		if (toupper(endInstructions) == 'Y')
			instructionLoop = true;
	}
}

void Minesweeper::gameStatusCheck()
{
	int spacesWithoutBombs = this->m_gameboard.getRow() * this->m_gameboard.getColumn()
	- this->m_gameboard.getAmountOfBombs();

	if (this->m_gameboard.getFlaggedCells() == this->m_gameboard.getAmountOfBombs()
		&& this->m_gameboard.getUncoveredCells() == spacesWithoutBombs)
	{
		this->m_gameWinner = true;
		this->m_gameStatus = true;
	}
}

void Minesweeper::runningGameLoop()
{
	while (!this->m_gameStatus)
	{
		system("cls");
		printBoard();
		
		if(this->m_cheatCode)
		this->m_gameboard.printBombMap(); 

		promptUserToEnterLocation();
		gameStatusCheck();
		if (this->m_gameboard.getGameStatus())
			gameOver();
		if(this->m_gameWinner)
			gameWinner();
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

		this->m_gameboard.playerMoveParameterCheck(row - 1, column - 1, flagUncoverRemove);
		if (!this->m_gameboard.getPlayerBoardEntry())
			cout << "That is not a valid entry, please re-enter" << endl;
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
