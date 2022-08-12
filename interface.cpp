#include "Console.h"
#include "function.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <windows.h>


/*
* Black 0
* Blue 1
* Green 2
* Cyan 3
* Red 4
* Magenta 5
* Yellow 6
* White 7
* Gray 8
* Light Blue 9
* Light Green 10
* Light Cyan 11
* Light Red 12
* Light Magenta 13
* Light Yellow 14
* Bright White 15
*/


void veTieuDeTuDien()
{
	short i;
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 95);
	}

	setColorBGTextXY((ConsoleWidth / 2) - 6, 1, 14, 0, "Dictionary\n");
	setColorBGTextXY((ConsoleWidth / 2) - 13, 2, 14, 0, "Made by Group 11\n");
	setColor(7);
	for (i = 0; i < ConsoleWidth; ++i)
	{
		printf("%c", 95);
	}
}

void veMenuChinh(short SIndex)
{
	//Cap nhat lai vi tri dang chon va tong muc cua menu
	SViTriChon = SIndex;
	STongMuc = 2;

	//Ve menu
	const char* STRNewGame = "Select language";
	setColorBGTextXY(5, 8, 15, ((SIndex == 0) ? 2 : 0), STRNewGame);
	STRNewGame = "Exit";
	setColorBGTextXY(5, 9, 15, ((SIndex == 1) ? 2 : 0), STRNewGame);
}

void veMenuNgonNgu(short SIndex)
{
	//Cap nhat lai vi tri dang chon va tong muc cua menu
	SViTriChon = SIndex;
	STongMuc = 4;

	//Ve menu
	const char* STRNewGame = "English to English";
	setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRNewGame) / 2), 6, 15, ((SIndex == 0) ? 2 : 0), STRNewGame);
	STRNewGame = "English to Vietnamese";
	setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRNewGame) / 2), 7, 15, ((SIndex == 0) ? 2 : 0), STRNewGame);
	STRNewGame = "Vietnamese to English";
	setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRNewGame) / 2), 8, 15, ((SIndex == 0) ? 2 : 0), STRNewGame);
	STRNewGame = "Return";
	setColorBGTextXY((ConsoleWidth / 2) - (strlen(STRNewGame) / 2), 9, 15, ((SIndex == 0) ? 2 : 0), STRNewGame);



}

void xuLyPhim(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown) // Co nhan phim
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_UP: // mui ten len
			std::cout << "Up" << std::endl;
			//switch (STrang)
			//{
			//case 1: //menu chinh
			//	if (STongMuc == 2)
			//	{
			//		if (SViTriChon == 0)
			//			SViTriChon = STongMuc - 1;
			//		else
			//			SViTriChon -= 1;
			//		veMenuChinh(SViTriChon);
			//	}
			//	break;
			//case 2: // language
			//	if (STongMuc == 4)
			//	{
			//		if (SViTriChon == 0)
			//			SViTriChon = STongMuc - 1;
			//		else
			//			SViTriChon -= 1;
			//		veMenuNgonNgu(SViTriChon);
			//	}
			//	break;
			//case 3: //game
			//	break;
			//}
			break;
		case VK_DOWN: // mui ten xuong
			std::cout << "Down" << std::endl;
			break;
		//case VK_LEFT: //mui ten trai
		//	std::cout << "Left" << std::endl;
		//	if (BTrangThaiChoiGame)
		//	{
		//		BSuDungPhim = true;
		//		CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot - 1 : CViTriConTro.X - 1);
		//		veBang();
		//	}
		//	break;
		//case VK_RIGHT: // mui ten phai
		//	std::cout << "Right" << std::endl;
		//	if (BTrangThaiChoiGame)
		//	{
		//		BSuDungPhim = true;
		//		CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot - 1) ? 0 : CViTriConTro.X + 1);
		//		veBang();
		//	}
		//	break;
		case VK_RETURN: // phim enter
			std::cout << "Enter" << std::endl;
			break;
		//case ClickTrai: //Phim Z - Mo o
		//	std::cout << "Z" << std::endl;
		//	if (BTrangThaiChoiGame)
		//		clickTrai(CViTriConTro.Y, CViTriConTro.X);
		//case ClickPhai: //Phim X - Cam co
		//	std::cout << "X" << std::endl;
		//	if (BTrangThaiChoiGame)
		//		clickPhai(CViTriConTro.Y, CViTriConTro.X);
		}
	}
}

void xuLySuKien()
{
	while (1)
	{
		DWORD DWNumberOfEvents = 0; //Luu lai su kien tai
		DWORD DWNumberOfEventsRead = 0; //Luu lai so luong su kien da duoc loc

		HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE); //Thiet bi dau vao
		GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOfEvents); // Dat su kien dau vao cua giao dien cho bien DWNumberOfEvents

		if (DWNumberOfEvents)
		{
			INPUT_RECORD* IREventBuffer = new INPUT_RECORD[DWNumberOfEvents];//Con tro EventBuffer
			ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOfEvents, &DWNumberOfEventsRead); //Dat cac su kien duoc luu tru vao con tro

			//chay vong lap de doc su kien
			for (DWORD i = 0; i < DWNumberOfEvents; ++i)
			{
				if (IREventBuffer[i].EventType == KEY_EVENT) //Neu la su kien phim
				{
					xuLyPhim(IREventBuffer[i].Event.KeyEvent);
				}
				//else if (IREventBuffer[i].EventType == MOUSE_EVENT) // Su kien chuot
			}
		}
	}

}


