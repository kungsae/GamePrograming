//#include<iostream>
//#include<time.h>
//
//using namespace std;
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	int answer[3] = { 0, };
//
//	answer[0] = rand() % 9 + 1;
//
//	do 
//	{
//		answer[1] = rand() % 9 + 1;
//	} 
//	while (answer[0] ==answer[1]);
//	
//	do
//	{
//		answer[2] = rand() % 9 + 1;
//	} while (answer[0] == answer[2] ||  answer[1] == answer[2]);
//
//	cout << answer[0]<<" " << answer[1] << " "<<answer[2]<<endl;;
//
//
//	
//	int S = 0;
//	int B = 0;
//	int O = 0;
//	
//	while (S != 3)
//	{
//		int num[3] = { 0, };
//		cin >> num[0] >> num[1] >> num[2];
//
//		//cout << answer[0] << " " << answer[1] << " " << answer[2] << endl;;
//
//		 S = 0;
//		 B = 0;
//		 O = 0;
//
//		 for (int i = 0; i < 3; i++)
//		 {
//			 if (num[i] == answer[i])
//			 {
//				 S++;
//			 }
//			 else if (num[i] == answer[0]|| num[i] == answer[1]|| num[i] == answer[2])
//			 {
//				 B++;
//			 }
//			 else
//			 {
//				 O++;
//			 }
//		 }
//		cout << "S : " << S << " B : " << B << " O : " << O << endl;
//		
//	}
//	
//
//
//	return (0);
//}
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

using namespace std;

const int Tone[8] = { 523, 587, 659, 698, 784, 880, 988, 1046 };
const string name[8] = { "도", "레", "미", "파", "솔", "라", "시", "도" };

int main()
{
	srand((unsigned)time(NULL));

	int selectTone = 0;
	int select = 0;

	_getch();

	while (true)
	{
		//for (int i = 0; i < 8; i++)
		//{
		//	cout << name[i] << "(" << i + 1 << ") ";
		//	Beep(Tone[i], 500);
		//}

		//Sleep(1000);

		selectTone = rand() % 8;

		Beep(Tone[selectTone], 1000);
		select = _getch() - '1';

		if (selectTone == select)
		{
			cout << "GOOD" << endl;
			break;
		}
		else
		{
			cout << "NO : ";

			cout << name[selectTone] << endl;
			Beep(Tone[selectTone], 500);
		}

		//_getch();
		

	}

	return 0;
}