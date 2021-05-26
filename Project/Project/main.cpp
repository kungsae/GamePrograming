#include<iostream>
#include"Console.h"
#include<vector>
#include"Note.h"


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
bool bSound = false;
int _input[4];
int score = 0;
int accuracy = 4;
int hp = 10;
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
	switch (accuracy)
	{
	case 0:
		cout << "Perfact"<<endl;
		break;
	case 1:
		cout << "Good"<<endl;
		break;
	case 2:
		cout << "Bad"<<endl;
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

	while (true)
	{
		bSound = false;
		SetSceen();
		for(int i = 0; i <4; i++)
		_input[i] = InputNote(input());;
		if (rand() % 100 < 10)
		{
			Note _note;
			_note.setNote(STARTX);

			note.push_back(_note);
		}
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
				beep(note[i].note * (rand() % 2 + 1), 50);
				i--;
				score+=2;
				accuracy = 0;
			
				bSound = true;
			}
			else if (checkInput(i,1,UP,LEFT))
			{
				note.erase(note.begin() + i);
				beep(note[i].note * (rand() % 2 + 1), 50);
				i--;
				score += 2;
				accuracy = 0;
			
				bSound = true;
			}
			//授
			else if (checkInput(i,0,2, UP, LEFT))
			{
				note.erase(note.begin() + i);
				beep(note[i].note * (rand() % 2 + 1), 50);
				i--;
				score++;
				accuracy = 1;
				
				bSound = true;
			}
			else if (checkInput(i,2,4, RIGHT, DOWN))
			{
				note.erase(note.begin() + i);
				beep(note[i].note * (rand() % 2 + 1), 50);
				i--;
				score++;
				accuracy = 1;
				
				bSound = true;
			}
			//寡萄
			else if (note[i].checkEnd())
			{
				 note.erase(note.begin() + i);
				 Beep(1000, 50);
				 i--;
				 hp--;
				 accuracy = 2;
				 bSound = true;
			}
		}
		if(!bSound)
		Sleep(50);
		system("cls");
	}
	return(0);
}

//int main()
//{
//	while (true)
//	{
//		cout << input();
//		Sleep(100);
//		system("cls");
//		
//	}
//	
//}