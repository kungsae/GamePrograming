#include "Console.h"

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x * 2;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}
void clrscr()
{
	system("cls");
}

void beep(int note, int delay)
{
	switch (note)
	{
	case 1:
		Beep(262, delay);
		break;
	case 2:
		Beep(294, delay);
		break;
	case 3:
		Beep(330, delay);
		break;
	case 4:
		Beep(349, delay);
		break;
	case 5:
		Beep(392, delay);
		break;
	case 6:
		Beep(440, delay);
		break;
	case 7:
		Beep(494, delay);
		break;
	case 8:
		Beep(523, delay);
		break;
	}
}
double sleepDelay(int bit)
{
	switch (bit)
	{
	case B1:
		return 1000;
		break;
	case B2:
		return 500;
		break;
	case DB2:
		return 750;
		break;
	case B4:
		return 250;
		break;
	case DB4:
		return 375;
		break;
	case B8:
		return 125;
		break;
	case DB8:
		return 187;
		break;
	case B16:
		return 62;
		break;
	case B32:
		return 31;
		break;
	case STOP:
		return 62;
		break;
	default:
		break;
	}
}
int input()
{
	if (_kbhit() != 0&& _getch() == 224)
	{
		return _getch();
	}
}
void textColor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gameOver(int score)
{
	system("cls");
	cout << "게임 오바";
	cout << "최고 점수 : " << score << endl;
}


//What the Fuck??
