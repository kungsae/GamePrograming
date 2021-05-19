#include<iostream>
#include"Console.h"
#include<Windows.h>
#include<vector>

using namespace std;

Console con;
vector<int> v;
int indexX = 0;

void test(int a,int b)
{
	v[a] ++;
	con.gotoXY(v[a], b);
	cout << "@";
	if (v[a] >= 20)
	{
		v[a] = 0;
	}
	//con.gotoXY(v[a],b);
	//cout << "@";
}
void Creat()
{
	srand((unsigned)time(NULL));


}
int main()
{
	
	v.assign(10,0);
	for (int i = 0; i < 8; i++)
	{
		v[i] = i;
	}
	
	while (true)
	{
		for (int i = 0; i < 7; i++)
		{
			test(0, 0);
			test(1, 1);
			test(2, 2);
			test(3, 3);
			test(4, 4);
			test(5, 5);
			test(6, 6);
			test(7, 7);
		}



		//Creat();
		Sleep(50);
		system("cls");

		
	}
	return(0);
}
