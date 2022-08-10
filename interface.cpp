#include "main.h"
#include "Console.h"
#include "function.h"
#include <iostream>
#include <fstream>
#include <windows.h>
void veTieuDeTuDien()
{
	short i;
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 95);
	}

	setColorBGTextXY((ConsoleWidth / 2) - 6, 1, 14, 0, "Dictionary\n");
	setColorBGTextXY((ConsoleWidth / 2) - 13, 2, 14, 0, "Made by Group ...\n");
	setColor(7);
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 95);
	}
}