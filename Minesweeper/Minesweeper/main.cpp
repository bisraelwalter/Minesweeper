//****Brandon Walter*****
#define _CRTDBG_MAP_ALLOC
#include <stdexcept>
#include <iostream>
#include "Minesweeper.h"
#include "Board.h"

bool checkChar(char choice);
void startGame(Board & board);
void chooseGame(char choice);
void beginnerGame();
void intermediateGame();
void expertGame();

void main()
{
	try
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
	}
	catch (out_of_range & ex)
	{
		cerr << "Out of range error: " << ex.what();
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
		
}

bool checkChar(char choice)
{
	char upperChoice = toupper(choice);
	if(upperChoice == 'B' || upperChoice == 'I' ||upperChoice == 'E')
	return true;

	return false;
}

void startGame(Board & board)
{
	Minesweeper game(board);
	game.printBoard();

}

void chooseGame(char choice)
{
	char upperChoice = toupper(choice);
	if(upperChoice == 'B') beginnerGame();
	if(upperChoice == 'I') intermediateGame();
	if(upperChoice == 'E') expertGame();	
}

void beginnerGame()
{
	Board beginnerBoard(10, 10, 10);
	startGame(beginnerBoard);
}

void intermediateGame()
{
	Board intermediateBoard(16, 16, 40);
	startGame(intermediateBoard);
}

void expertGame()
{
	Board expertBoard(16, 30, 100);
	startGame(expertBoard);
}
