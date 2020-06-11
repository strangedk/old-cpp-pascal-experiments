#include <iostream.h>
#include <conio.h>

/*

OVERLOAD OPERATORS BINARY


if operator function define as Class member

right parameter is "PAR" , left parameter is pointer "this" :

<return_type> operatorX ( <type_par> PAR );


if operator function define as Global or Friend

right parameter is PAR1 , left parameter is PAR2 :

<return_type> operatorX ( <TYPE_PAR1> PAR1, <TYPE_PAR2> PAR2 );

*/


class Coord{

	int x, y;
public:
	Coord() {x=0; y=0; }
	Coord(int _x, int _y) {x=_x; y=_y; }
	void SetCoord(int& Px, int& Py) {Px=x; Py=y; }

	Coord& operator=(Coord& rhs);

	friend Coord operator+(Coord& ob1, Coord& ob2);
	friend Coord operator+(int ob1, Coord& ob2);
	friend Coord operator+(Coord& ob1, int ob2);

	friend Coord operator-(Coord& ob1, Coord& ob2);
	friend Coord operator-(int ob1, Coord& ob2);
	friend Coord operator-(Coord& ob1, int ob2);
};


Coord&
Coord::operator=(Coord& rhs)
{
	if (this==&rhs) return *this;
	this->x=rhs.x;
	this->y=rhs.y;
	return *this;
};


Coord
operator+(Coord& ob1, Coord& ob2)
{
	Coord temp;
	temp.x=ob1.x+ob2.x;
	temp.y=ob1.y+ob2.y;
	return temp;
};


Coord
operator+(int ob1, Coord& ob2)
{
	Coord temp;
	temp.x=ob1+ob2.x;
	temp.y=ob1+ob2.y;
	return temp;
};


Coord
operator+(Coord& ob1, int ob2)
{
	Coord temp;
	temp.x=ob1.x+ob2;
	temp.y=ob1.y+ob2;
	return temp;
};


Coord
operator-(Coord& ob1, Coord& ob2)
{
	Coord temp;
	temp.x=ob1.x-ob2.x;
	temp.y=ob1.y-ob2.y;
	return temp;
};


Coord
operator-(int ob1, Coord& ob2)
{
	Coord temp;
	temp.x=ob1-ob2.x;
	temp.y=ob1-ob2.y;
	return temp;
};


Coord
operator-(Coord& ob1, int ob2)
{
	Coord temp;
	temp.x=ob1.x-ob2;
	temp.y=ob1.y-ob2;
	return temp;
};


int
main()
{
	int x, y;
	Coord obA(50,30), obB(10,20), obC;

	clrscr();

	obC=obA+obB;
	obC.SetCoord(x,y);
	cout <<" obC.x = " <<x <<" obC.y = " <<y <<endl;

	obC=obA-obB;
	obC.SetCoord(x,y);
	cout <<" obC.x = " <<x <<" obC.y = " <<y <<endl;

	obC=obA+5;
	obC.SetCoord(x,y);
	cout <<" obC.x = " <<x <<" obC.y = " <<y <<endl;

	obC=obA-5;
	obC.SetCoord(x,y);
	cout <<" obC.x = " <<x <<" obC.y = " <<y <<endl;

	obC=5+obA;
	obC.SetCoord(x,y);
	cout <<" obC.x = " <<x <<" obC.y = " <<y <<endl;

	obC=100-obA;
	obC.SetCoord(x,y);
	cout <<" obC.x = " <<x <<" obC.y = " <<y <<endl;

	return 0;
};