#include <iostream.h>
#include <conio.h>

/*

OVERLOAD OPERATORS UNARY


if operator function define as Class member

left parameter is pointer "this"

<return_type> operatorX ();


if operator function define as Global or Friend

left parameter is PAR.

<return_type> operatorX (<TYPE_PAR1> PAR );

*/


class Coord{

	int x, y;
public:
	Coord() {x=0; y=0; }
	Coord(int _x, int _y) {x=_x; y=_y; }
	void SetCoord(int& Px, int& Py) {Px=x; Py=y; }
	Coord operator+();
	Coord operator-();
};


Coord
Coord::operator+()
{
	x= ++x;
	y= ++y;
	return *this;
};


Coord
Coord::operator-()
{
	x= --x;
	y= --y;
	return *this;
};


int
main()
{
	int x, y;
	Coord obA(0,10), obB(10,20), obC;

	clrscr();
	-obA;
	obA.SetCoord(x,y);
	cout <<x <<endl <<y <<endl;

	+obA;
	obA.SetCoord(x,y);
	cout <<x <<endl <<y <<endl;
	getch();

	return 0;
};
