#include "Console.h"
#include"console.h"
#include<Windows.h>
#include<conio.h>

void Console::gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x * 2;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}
void Console:: clrscr()
{
	system("cls");
}

void Console:: setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Console::beep(int tone, int delay)
{
	Beep(tone, delay);
}
int Console::input()
{
	if (_kbhit() != 0)
	{
		return _getch() - '0';
	}
}