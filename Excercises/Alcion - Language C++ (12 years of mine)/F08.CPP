#include <iostream.h>
#include <conio.h>

/****   Overload operator ->   ****/


class Coord{

	int x, y;
public:
	Coord(int _x, int _y){x=_x; y=_y; }

	int GetX() {return x; }
	int GetY() {return y; }

	Coord* operator->();
};


Coord*
Coord::operator->()
{
	cout <<"Access to member : ";
	return this;
};


int
main()
{
	Coord ob(3,5);

	clrscr();

	cout <<"ob->x = " <<ob->GetX() <<endl;
	cout <<"ob->y = " <<ob->GetY() <<endl;

	return 0;
};