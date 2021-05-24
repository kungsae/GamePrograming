#pragma once
class Console
{
public:
	 void gotoXY(int x, int y);
	 void clrscr();
	 void beep(int tone, int delay);
	 int input();
	 void textColor(int foreground, int background);
};

