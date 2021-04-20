#include<iostream>
#include<time.h>

using namespace std;


int GetGrade(int data[])
{
	int sum = 0;
	int num = rand() % 100;

	for (int i = 0; i < 5; i++)
	{
		sum += data[i];
		if (num < sum)
		{
			return (i + 1);
		}
	}
}

int main()
{
	srand(time(NULL));

	int result = 0;
	int grade[5] = { 0, };

	int data1[5] = { 50,30,10,7,3 };


	for (int i = 0; i < 100; i++)
	{
		result = GetGrade(data1);
		grade[result - 1]++;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "¼º : " << grade[i] << endl;
	}
	
	return(0);
}