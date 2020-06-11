#include <iostream.h>
#include <conio.h>

/*
	 Overloading operators increment and decrement
	 with class member functions.
*/


class Coord{

	int x, y;
public:
	Coord() {x=0; y=0; }
	Coord(int X, int Y) {x=X; y=Y; }

	void SetCoord(int& X, int& Y) {X=x; Y=y;}

	Coord& operator++();
	Coord operator++(int);
	Coord& operator--();
	Coord operator--(int);
};


Coord&
Coord::operator++()
{
	x++;
	y++;
	return *this;
};


Coord
Coord::operator++(int)
{
	Coord temp= *this;
	++*this;
	return temp;
};


Coord&
Coord::operator--()
{
	x--;
	y--;
	return *this;
};


Coord
Coord::operator--(int)
{
	Coord temp= *this;
	--*this;
	return temp;
};


int
main()
{
	int x,y;
	Coord obA(10,20), obB(5,0), obC;

	clrscr();
	obA.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	++obA;
	obA.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	obA++;
	obA.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	--obA;
	obA.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	obA--;
	obA.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	obC=obB++;

	obC.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	obB.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	obC=obB--;

	obC.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	obB.SetCoord(x,y);
	cout <<x <<"  " <<y <<endl;

	return 0;
};