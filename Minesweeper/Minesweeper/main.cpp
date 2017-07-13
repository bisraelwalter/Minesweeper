//****Brandon Walter*****
#define _CRTDBG_MAP_ALLOC
#include <stdexcept>
#include <iostream>
#include "Minesweeper.h"




void main()
{
	try
	{
		Minesweeper game;
		game.startGame();
		
	}
	catch (out_of_range & ex)
	{
		cerr << "Out of range error: " << ex.what();
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
		
}




