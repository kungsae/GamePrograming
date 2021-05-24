#include<iostream>
#include"Console.h"
#include<Windows.h>
#include<vector>
#include <conio.h>

#define STARTX 40
#define NOTEINDEX 10

using namespace std;

enum Color
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
Console con;
vector <int> v(10);
vector <int> y(10);
float speed = 100;

int Note(int x,int y)
{
	x--;
	con.gotoXY(x,y);
	if(x != 2&& x != 4)
	cout << "﹦";
	return x;
}

void StartNote()
{
	for (int i = 0; i < NOTEINDEX; i++)
	{
		v[i] = Note(v[i],y[i]);
		if (v[i] <= 1)
		{
			v[i] = STARTX + 9;
			y[i] = rand() % 2;
			if (y[i] == 0)
			{
				y[i] = 5;
			}
			else if (y[i] == 1)
			{
				y[i] = 7;
			}
			if(speed>10)
			speed-=0.5f;
		}
	}
}
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title 葬蛟 啪歜");
}
void SetSceen()
{
	con.gotoXY(0, 3);
	cout << "  ﹦  ∩" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;
	cout << "弛   弛   弛                                                                                        弛" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式弛" << endl;
	cout << "弛   弛   弛                                                                                        弛" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	cout << "  ８  Ⅰ" << endl;
}


int main()
{
	SetConsoleView();
	SetSceen();
	con.gotoXY(STARTX, 5);
	srand((unsigned)time(NULL));
	for (int i = 0; i < NOTEINDEX; i++)
	{

		v[i] = STARTX + i;
		y[i] = rand() % 2;
		if (y[i] == 0)
		{
			y[i] = 5;
		}
		else if (y[i] == 1)
		{
			y[i] = 7;
		}
	}

	while (true)
	{
		SetSceen();
		StartNote();
		Sleep(300);

		system("cls");
	}
	return(0);
}
