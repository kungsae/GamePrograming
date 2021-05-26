#include"Note.h"
#include"Console.h"
#include<iostream>

using namespace std;

void Note::setNote(int MaxX)
{
	x = MaxX;
	note = rand() % 4+1;

}
void Note::moveNote()
{
	x--;
}
void Note::drawNote()
{
	gotoXY(x, y);
	switch (note)
	{
	case 1:
		y = 5;
		textColor(WHITE, BLACK);
		cout << "¡â";
		textColor(WHITE, BLACK);
		break;
	case 2:
		y = 7;
		textColor(WHITE, BLACK);
		cout << "¢·";
		textColor(WHITE, BLACK);
		break;
	case 3:
		y = 7;
		textColor(WHITE, BLACK);
		cout << "¢¹";
		textColor(WHITE, BLACK);
		break;
	case 4:
		y = 5;
		textColor(WHITE, BLACK);
		cout << "¡ä";
		textColor(WHITE, BLACK);
		break;
	default:
		break;
	}
}
bool Note::checkEnd()
{
	if (x < 1)
		return true;
	else
		return false;
}
int Note::getNote()
{
	return x;
}