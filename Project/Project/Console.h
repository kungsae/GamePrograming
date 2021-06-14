#pragma once
#include<Windows.h>
#include<conio.h>
#include<iostream>

using namespace std;

	extern void gotoXY(int x, int y);
	extern void clrscr();
	extern void beep(int tone, int delay);
	extern int input();
	extern void textColor(int foreground, int background);
	extern void gameOver(int score);
	extern double sleepDelay(int bit);

	extern enum Bit
	{
		B1,
		B2,
		DB2,
		B4,
		DB4,
		B8,
		DB8,
		B16,
		B32,
		STOP
	};
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


