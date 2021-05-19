#pragma once
class Console
{
public:
	 void gotoXY(int x, int y);
	 void setTextColor(int color);
	 void clrscr();
	 void beep(int tone, int delay);
	 int input();
};

