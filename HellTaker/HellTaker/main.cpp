#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

char Stage[10][16] =
{
	//"+++++++++++++++",
	//"+++++++++++++++",
	//"++++&  ++++++++",
	//"++++ OO++++++++",
	//"++++ O ++++.+++",
	//"++++++ ++++.+++",
	//"++++++  @  .+++",
	//"+++++ @  +  +++",
	//"+++++    ++++++",
	//"+++++++++++++++"
	"+++++++++++++++",
	"+             +",
	"+   &         +",
	"+    OO       +",
	"+    O     .  +",
	"+          .  +",
	"+          .  +",
	"+     @       +",
	"+ @           +",
	"+++++++++++++++"
};
int portalX = 0;
int portalY = 0;
int portalX1 = 0;
int portalY1 = 0;
char backgroundMap[10][16];
int currentX, currentY;
int totalMove;
bool bPull;
int pull;

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void clrscr()
{
	system("cls");
}

void initScreen()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			gotoXY(x, y);
			_putch(backgroundMap[y][x]);
		}
	}
	//gotoXY(portalX, portalY);
	//_putch('@');
	//gotoXY(portalX1, portalY1);
	//_putch('@');
	gotoXY(currentX, currentY);
	_putch('&');
}

bool checkEnd()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (Stage[y][x] == '.' && backgroundMap[y][x] != 'O')
			{
				return false;
			}
		}
	}

	return true;
}

void move(int dir)
{
	int dir_x = 0, dir_y = 0;

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
	}

	if (backgroundMap[currentY + dir_y][currentX + dir_x] != '+'&& (backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] != '+' || !bPull))
	{
		if (backgroundMap[currentY + dir_y][currentX + dir_x] == 'O')
		{
			 if (backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == backgroundMap[portalY1][portalX1])
			{
				backgroundMap[currentY + dir_y][currentX + dir_x] = ' ';
				backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] = '@';
				backgroundMap[portalY][portalX] = 'O';
			}
			 if (backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == backgroundMap[portalY][portalX])
			{
				backgroundMap[currentY + dir_y][currentX + dir_x] = ' ';
				backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] = '@';
				backgroundMap[portalY1][portalX1] = 'O';
			}
			 if (backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == ' ' || backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == '.')
			{
				if (Stage[currentY + dir_y][currentX + dir_x] == '.')
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = '.';
				}
				else if (Stage[currentY + dir_y][currentX + dir_x] == '@')
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = '@';
				}
				else
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = ' ';
				}
				backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] = 'O';
			
			}
		
			else
			{
				return;
			}
		}
		if (bPull)
		{
			if (backgroundMap[currentY + dir_y*2][currentX + dir_x*2] != '+')
			{
				if (pull == 1)
				{
					backgroundMap[currentY - 1 + dir_y][currentX + dir_x] = '8';
					if (Stage[currentY - 1][currentX] == '.')
					{
						backgroundMap[currentY - 1][currentX] = '.';
					}
					else
					{
						backgroundMap[currentY - 1][currentX] = ' ';
					}
				}
				else if (pull == 2)
				{
					backgroundMap[currentY + 1 + dir_y][currentX + dir_x] = '8';
					if (Stage[currentY + 1][currentX] == '.')
					{
						backgroundMap[currentY + 1][currentX] = '.';
					}
					else
					{
						backgroundMap[currentY + 1][currentX] = ' ';
					}
				}
				else if (pull == 3)
				{
					backgroundMap[currentY + dir_y][currentX + 1 + dir_x] = '8';
					if (Stage[currentY][currentX + 1] == '.')
					{
						backgroundMap[currentY][currentX + 1] = '.';
					}
					else
					{
						backgroundMap[currentY][currentX + 1] = ' ';
					}
				}
				else if (pull == 4)
				{
					backgroundMap[currentY + dir_y][currentX - 1 + dir_x] = '8';
					if (Stage[currentY][currentX - 1] == '.')
					{
						backgroundMap[currentY][currentX - 1] = '.';
					}
					else
					{
						backgroundMap[currentY][currentX - 1] = ' ';
					}
			}
			
			}
			


		}
		currentX += dir_x;
		currentY += dir_y;
		totalMove++;
	}
}

int main()
{
	int ch;

	memcpy(backgroundMap, Stage, sizeof(backgroundMap));

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (backgroundMap[y][x] == '&')
			{
				currentX = x;
				currentY = y;
				backgroundMap[y][x] = ' ';
			}
			if (backgroundMap[y][x] == '@')
			{
				if (portalX == 0 && portalY == 0)
				{
					portalX = x;
					portalY = y;
				}
				else
				{
					portalX1 = x;
					portalY1 = y;
				}


				//backgroundMap[y][x] = ' ';
			}
		}
	}
	bPull = false;

	while (true)
	{
		initScreen();
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
			}
		}
		else
		{
			ch = tolower(ch);
			if (ch == 'q')
			{
				clrscr();
				exit(0);
			}
			else if (ch == 'p')
			{
				if (bPull)
				{
					if (backgroundMap[currentY - 1][currentX] == '8')
					{
						backgroundMap[currentY - 1][currentX] = 'O';
						bPull = false;
						
					}
					else if (backgroundMap[currentY + 1][currentX] == '8')
					{
						backgroundMap[currentY + 1][currentX] = 'O';
						bPull = false;
						
					}
					else if (backgroundMap[currentY][currentX - 1] == '8')
					{
						backgroundMap[currentY][currentX - 1] = 'O';
						bPull = false;
						
					}
					else if (backgroundMap[currentY][currentX + 1] == '8')
					{
						backgroundMap[currentY][currentX + 1] = 'O';
						bPull = false;
						
					}
				}
				else
				{
					if (backgroundMap[currentY - 1][currentX] == 'O')
					{
						backgroundMap[currentY - 1][currentX] = '8';
						bPull = true;
						pull = 1;
					}
					else if (backgroundMap[currentY + 1][currentX] == 'O')
					{
						backgroundMap[currentY + 1][currentX] = '8';
						bPull = true;
						pull = 2;
					}
					else if (backgroundMap[currentY][currentX + 1] == 'O')
					{
						backgroundMap[currentY][currentX + 1] = '8';
						bPull = true;
						pull = 3;
					}
					else if (backgroundMap[currentY][currentX - 1] == 'O')
					{
						backgroundMap[currentY][currentX - 1] = '8';
						bPull = true;
						pull = 4;
					}
				}
			}
		}
		if (checkEnd())
		{
			clrscr();
			gotoXY(10, 4);
			cout << "Å¬¸®¾î" << endl;
			exit(0);
		}
	}


	gotoXY(20, 20);



	return 0;
}