#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<time.h>

using namespace std;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int currentX, currentY;
//int randX[10] = { 0, };
//int randY[10] = { 0, };
int a = 0;
int b = 0;
int ch;
char ShowMap[20][21] =
{
	"++++++++++++++++++++",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"++++++++++++++++++++"
};
void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void displayScreen()
{
	for (int a = 0; a < 10; a++)
	{
		//gotoXY(randX[a], randY[a]);
		//ShowMap[randY[a]][randX[a]] = '@';
	}
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gotoXY(x, y);
			_putch(ShowMap[y][x]);
		}

	}


	gotoXY(currentX, currentY);
	_putch(',');
	gotoXY(30, 2);
	cout << "Q:Á¾·á";
}

void move(int dir)
{
	int dir_x = 0;
	int dir_y = 0;
	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	default:
		break;
	}
	if (ShowMap[currentY + dir_y][currentX + dir_x] != '+' && ShowMap[currentY + dir_y][currentX + dir_x] != '@')
	{
		currentX += dir_x;
		currentY += dir_y;
	}



}

int main()
{
	int sameNum = 0;
	bool bSame;
	srand((unsigned)time(NULL));

	currentX = 1;
	currentY = 1;

	for (int i = 0; i < 10; i++)
	{
		a = rand() % 20;
		b = rand() % 20;
		if (ShowMap[a][b] == '+')
		{
			i--;
			continue;
		}
		ShowMap[a][b] = '+';
	}


	while (true)
	{

		displayScreen();


		ch = _getch();
		if (ch == 0xE0 || ch == 0)
		{
			ch = _getch();
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				move(ch);

				break;
			default:
				break;
			}
		}
		else
		{
			ch = tolower(ch);
			if (ch == 'q')
			{
				exit(0);
			}
			else if (ch == 'z')
			{
				ShowMap[currentY][currentX] = 'X';
			}
			else if(ch == 'a')
			{
				if (currentX + 1 != 19)
				{
					ShowMap[currentY][currentX + 1] = '.';
				}
				if (currentX - 1 != 0)
				{
					ShowMap[currentY][currentX-1] = '.';
				}
				if (currentY + 1 != 19)
				{
					ShowMap[currentY+1][currentX] = '.';
				}
				if (currentY - 1 != 0)
				{
					ShowMap[currentY-1][currentX] = '.';
				}
			}
		}
		/*else if (ch == 'q')
		{
			break;
		}*/

		//if()
	}
	return(0);
}