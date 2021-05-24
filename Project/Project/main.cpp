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
vector <int> note(10);
float speed = 100;

int Note(int x,int y,int _note)
{
	x--;
	if(x != 2&& x != 4)
		switch (_note)
		{
		case 1:
			con.gotoXY(x, 5);
			cout << "﹦";
			break;
		case 2:
			con.gotoXY(x, 7);
			cout << "８";
			break;
		case 3:
			con.gotoXY(x, 7);
			cout << "Ⅰ";
			break;
		case 4:
			con.gotoXY(x, 5);
			cout << "∩";
			break;
		default:
			break;
		}
	/*cout << "﹦";*/
	return x;
}

void StartNote()
{
	for (int i = 0; i < NOTEINDEX; i++)
	{
		v[i] = Note(v[i],y[i],note[i]);
		if (v[i] <= 1)
		{
			v[i] = STARTX + 9;
			y[i] = rand() % 2;
			note[i] = rand() % 4+1;
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
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式 " << endl;
	cout << "弛   弛   弛                                                                                         " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式 " << endl;
	cout << "弛   弛   弛                                                                                         " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式 " << endl;
	cout << "  ８  Ⅰ" << endl;
}
void InputNote(int input)
{
	switch (input)
	{
	case 72:					//嬪
		con.gotoXY(1, 3);
		con.textColor(RED, BLACK);
		cout << "﹦";
		con.textColor(WHITE, BLACK);
		break;
	case 75:					//豭
		con.gotoXY(1, 9);
		con.textColor(RED, BLACK);
		cout << "８";
		con.textColor(WHITE, BLACK);
		con.gotoXY(1, 7);
		break;
	case 77:					//螃
		con.gotoXY(3,9);
		con.textColor(RED, BLACK);
		cout << "Ⅰ";
		con.textColor(WHITE, BLACK);
		con.gotoXY(3, 7);
		break;
	case 80:					//嬴
		con.gotoXY(3, 3);
		con.textColor(RED, BLACK);
		cout << "∩";
		con.textColor(WHITE, BLACK);
		con.gotoXY(3, 5);
		break;
	default:
		break;
	}
}


int main()
{
	int input;

	SetConsoleView();
	SetSceen();
	
	con.gotoXY(STARTX, 5);
	srand((unsigned)time(NULL));
	for (int i = 0; i < NOTEINDEX; i++)
	{

		v[i] = STARTX + i;
		y[i] = rand() % 2;
		note[i] = rand() % 4 + 1;
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
		for(int i = 0; i<4; i++)
		InputNote(con.input());
		StartNote();	
		Sleep(500);
		system("cls");
	}
	return(0);
}

//int main()
//{
//	while (true)
//	{
//		cout << con.input();
//		Sleep(100);
//		system("cls");
//		
//	}
//	
//}