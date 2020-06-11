#include <iostream.h>
#include <conio.h>

/****   Overload operator ()   ****/


class Coord{

	int x, y;
public:
	Coord() {x=0; y=0; }
	Coord(int _x, int _y) {x=_x; y=_y; }

	void GetCoord(int& _x, int& _y) {_x=x; _y=y; }

	Coord& operator() (int dx, int dy) {x+=dx; y+=dy; return *this; }
};


int
main()
{
	int x, y;
	Coord ob1, ob2;

	clrscr();

	ob2=ob1(4,2);

	ob2.GetCoord(x,y);
	cout <<"X = " <<x <<" Y = " <<y <<endl;

	ob1.GetCoord(x,y);
	cout <<"X = " <<x <<" Y = " <<y <<endl;

	return 0;
};