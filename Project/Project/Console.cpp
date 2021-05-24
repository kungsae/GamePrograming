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

void Console::beep(int tone, int delay)
{
	Beep(tone, delay);
}
int Console::input()
{
	if (_kbhit() != 0&& _getch() == 224)
	{
		return _getch();
	}
}
void Console::textColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
