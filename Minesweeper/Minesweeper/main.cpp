//****Brandon Walter*****
#define _CRTDBG_MAP_ALLOC
#include <stdexcept>
#include <iostream>
#include "Minesweeper.h"

bool gameContinue = true;
void gameEnd();

void main()
{
	try
	{
		while (gameContinue)
		{
			Minesweeper game;
			game.startGame();
			gameEnd();
		}
	}
	catch (out_of_range & ex)
	{
		cerr << "Out of range error: " << ex.what();
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
		
}


void gameEnd()
{
	char choice;
	cout << "Want to play another game? (Y) or any key to exit: ";
	cin >> choice;

	if (toupper(choice) == 'Y')
		 gameContinue = true;
	else
	gameContinue = false;
}


