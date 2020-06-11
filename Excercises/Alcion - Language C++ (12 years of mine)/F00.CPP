
/**** Experiment Program ****/


#include <iostream.h>
#include <string.h>
#include <conio.h>
#define e '\n'


class Coord{

	int x, y;
public:
	Coord(int _x, int _y) {x=_x; y=_y;}
	Coord() {x=0; y=0;}
	int GetX() {return x;}
	int GetY() {return y;}
	void SetX(int _x) {x=_x;}
	void SetY(int _y) {y=_y;}
};


class SaveMsg{

	char Message[80];
public:
	SaveMsg(char* msg) {SetMsg(msg);}
	void SetMsg(char* msg) {strcpy(Message, msg);}
	void ShowMsg() {cout <<Message;}
};


class PrintMsg: virtual public Coord, virtual public SaveMsg{

public:
	PrintMsg(int _x, int _y, char* msg): Coord(_x, _y),SaveMsg(msg) {}
	void Show();
};


void
PrintMsg::Show()
{
	gotoxy(GetX(), GetY());
	ShowMsg();
}


main()
{
	clrscr();
	PrintMsg ob(30, 13, " Classes Hiearhy");
	ob.Show();
};

