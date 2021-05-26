#pragma once
#include<Windows.h>
#include<conio.h>

	extern void gotoXY(int x, int y);
	extern void clrscr();
	extern void beep(int tone, int delay);
	extern int input();
	extern void textColor(int foreground, int background);
	extern enum Color
	{
		BLACK,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN,
		LIGHTGRAY,
		DARKGRAY,
		LIGHTBLUE,
		LIGHTGREEN,
		LIGHTCYAN,
		LIGHTRED,
		LIGHTMAGENTA,
		YELLOW,
		WHITE
	};


