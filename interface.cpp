#include "functions.h"
#include "main.h"
#include "Console.h"
#include <iostream>
#include <fstream>
#include <windows.h>
void veTieuDeGame()
{
	short i;
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 95);
	}

	setColorBGTextXY((ConsoleWidth / 2) - 6, 1, 14, 0, "Minesweeper\n");
	setColorBGTextXY((ConsoleWidth / 2) - 13, 2, 14, 0, "Made by Nguyen Hoang Phuc\n");
	setColor(7);
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 95);
	}
}