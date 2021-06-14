#include<iostream>
#include"Console.h"
#include<vector>
#include"Note.h"
#include<time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")


#define STARTX 50
#define NOTEINDEX 10

using namespace std;

vector<Note> note;
enum
{
	null,
	UP,
	LEFT,
	RIGHT,
	DOWN
};
int BGM[999] =
//{
//	DB8,B16,B8,B8,B8,B8,STOP,B4,B8,B8,B4,B8,B8,B4
//};
{ B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
	B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16,
B16,B16,B8,DB8,B8,B8,B8,B16,B16,B16, };

int BGMIndex = 0;
bool bSound = false;
int noteLevel = 50;
int _input[4];
int score = 0;
int accuracy = 4;
int hp = 10;
int delay = 1000;
void SetConsoleView()
{
	system("mode con:cols=100 lines=20");
	system("title 葬蛟 啪歜");
}
void SetSceen()
{
	gotoXY(0, 3);

	
	cout << "  ﹦  ∩" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "弛   弛   弛                                                                                         " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "弛   弛   弛                                                                                         " << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "  ８  Ⅰ" << endl;
	cout << endl;
	cout << "score : " << score << endl;
	cout << delay<<endl;
	switch (accuracy)
	{
	case 0:
		cout << "Perfact"<<endl;
		break;
	case 1:
		cout << "Good"<<endl;
		break;
	case 2:
		cout << "Miss"<<endl;
		break;
	default:
		cout << endl;
		break;
	}
	cout << "hp : ";
	for (int i = 0; i < hp; i++)
	{
		cout << "﹥";
	}
}
int InputNote(int input)
{
	switch (input)
	{
	case 72:					//嬪
		gotoXY(1, 3);
		textColor(RED, BLACK);
		cout << "﹦";
		textColor(WHITE, BLACK);
		return UP;
		break;
	case 75:					//豭
		gotoXY(1, 9);
		textColor(RED, BLACK);
		cout << "８";
		textColor(WHITE, BLACK);
		gotoXY(1, 7);
		return LEFT;
		break;
	case 77:					//螃
		gotoXY(3,9);
		textColor(RED, BLACK);
		cout << "Ⅰ";
		textColor(WHITE, BLACK);
		gotoXY(3, 7);
		return RIGHT;
		break;
	case 80:					//嬴
		gotoXY(3, 3);
		textColor(RED, BLACK);
		cout << "∩";
		textColor(WHITE, BLACK);
		gotoXY(3, 5);
		return DOWN;
		break;
	default:
		break;
	}
}
bool checkNoteInput(int i)
{
	bool a;
	for (int j = 0; j < 4; j++)
	{
		if (note[i].note == _input[j])
		{
			a = true;
			break;
		}
		a = false;
	}
	return a;
}
bool checkInput(int i,int xPos,int note1,int note2)
{
	return note[i].getNote() == xPos && checkNoteInput(i) && (note[i].note == note1 || note[i].note == note2);
}
bool checkInput(int i, int xPos,int xPos2, int note1, int note2)
{
	return (note[i].getNote() == xPos|| note[i].getNote() == xPos2)&& checkNoteInput(i) && (note[i].note == note1 || note[i].note == note2);
}

int main()
{
	
	SetConsoleView();
	SetSceen();
	

	srand((unsigned)time(NULL));
	note.clear();

	float checkBit = 0;
	int a = 0;
	int b = 0;

	while (true)
	{
		b++;
		if (b == 50)
		{
			PlaySound("Megalovania.wav", 0, SND_FILENAME | SND_ASYNC);
		}
		a+=10;
		SetSceen();
		if (checkBit <= a)
		{
			a = 0;
			checkBit = sleepDelay(BGM[BGMIndex]);

			if (BGM[BGMIndex] != STOP)
			{
				//score++;
				Note _note;
				_note.setNote(STARTX);

				note.push_back(_note);
			}
			if (BGMIndex % 16 == 0)
			{
				
			}
			BGMIndex++;
		}
		for(int i = 0; i <4; i++)
		_input[i] = InputNote(input());;
		//if (rand() % 100 < noteLevel)
		//{
		//	Note _note;
		//	_note.setNote(STARTX);

		//	note.push_back(_note);
		//}
		for (int i = 0; i < note.size(); i++)
		{
			note[i].moveNote();
			note[i].drawNote();
		}

		for (int i = 0; i < note.size(); i++)
		{
			//ぷねお
			if (checkInput(i,3,RIGHT,DOWN))
			{
				note.erase(note.begin() + i);
				i--;
				score+=2;
				accuracy = 0;
			
				bSound = true;
			}
			else if (checkInput(i,1,UP,LEFT))
			{
				note.erase(note.begin() + i);
				i--;
				score += 2;
				accuracy = 0;
			
				bSound = true;
			}
			//授
			else if (checkInput(i,0,2, UP, LEFT))
			{
				note.erase(note.begin() + i);
				i--;
				score++;
				accuracy = 1;
				
				bSound = true;
			}
			else if (checkInput(i,2,4, RIGHT, DOWN))
			{
				note.erase(note.begin() + i);
				i--;
				score++;
				accuracy = 1;
				
				bSound = true;
			}
			//寡萄
			else if (note[i].checkEnd())
			{
				
				 note.erase(note.begin() + i);
				 i--;
				 hp--;
				 accuracy = 2;
				 bSound = true;

				 //if (hp <= 0)
				 //{
					// gameOver(score);
					// return(0);
				 //}
			}
		}
	/*	if(!bSound)*/
		//Sleep(1);
		system("cls");
	}
	return(0);
}


