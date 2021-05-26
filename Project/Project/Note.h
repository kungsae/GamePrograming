#pragma once
class Note
{

private:
	int x;
	int y;
	

public:
	int note;
	void setNote(int MaxX);
	void moveNote();
	void drawNote();
	bool checkEnd();
	int getNote();

};
