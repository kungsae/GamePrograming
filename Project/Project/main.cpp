#include<iostream>
#include"Console.h"
#include<Windows.h>
#include<vector>

using namespace std;

Console con;
vector <int> v(10);
vector <int> y(10);
float speed = 100;

int Note(int x,int y)
{
	x+=2;
	con.gotoXY(x,y);
	cout << "@";
	return x;
}

void StratNote()
{
	for (int i = 0; i < 7; i++)
	{
		v[i] = Note(v[i],y[i]);
		if (v[i] >= 20)
		{
			v[i] = 0;
			y[i] = rand() % 2;
			if(speed>10)
			speed-=0.5f;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 7; i++)
	{

		v[i] = -i;
		y[i] = rand() % 2;
	}

	while (true)
	{

		StratNote();
		Sleep(20);

		system("cls");
	}
	return(0);
}