#include <iostream>
using namespace std;


//과제

//과제 1
//int main()
//{
//	int star;
//	star = rand() % 5 +1;
//	cout << star << "성 카드 획득" << endl;
//
//	return(0);
//}


//과제 2

	int main()
	{
		int star;
		int one=0;
		int two=0;
		int three=0;
		int four=0;
		int five=0;

		for (int i = 0; i < 1000; i++)
		{
			star = rand() % 100;
			if (star <= 50)
			{
				cout << "1성" << endl;
				one++;
			}
			else if (star <= 80)
			{
				cout << "2성" << endl;
				two++;
			}
			else if (star <= 90)
			{
				cout << "3성" << endl;
				three++;
			}
			else if (star <= 97)
			{
				cout << "4성" << endl;
				four++;
			}
			else if (star <= 100)
			{
				cout << "5성" << endl;
				five++;
			}
		}
		cout << endl;
		cout << "1성 : " << one << endl;
		cout << "2성 : " << two << endl;
		cout << "3성 : " << three << endl;
		cout << "4성 : " << four << endl;
		cout << "5성 : " << five << endl;
	}