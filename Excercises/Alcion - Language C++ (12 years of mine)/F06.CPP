#include <iostream.h>
#include <conio.h>

/*
	 Overloading operators increment and decrement
	 with friend functions.
*/

class Coord{

	int x, y;
public:
	Coord() {x=0; y=0; }
	Coord(int X, int Y) {x=X; y=Y;}

	void SetCoord(int& X, int& Y) {X=x; Y=y;}

	friend Coord& operator++(Coord&);
	friend Coord  operator++(Coord&, int);
	friend Coord& operator--(Coord&);
	friend Coord  operator--(Coord&, int);
};


Coord&
operator++(Coord& ob)
{
	ob.x++;
	ob.y++;
	return ob;
};


Coord
operator++(Coord& ob, int)
{
	Coord temp=ob;
	++ob;
	return temp;
};


Coord&
operator--(Coord& ob)
{
	ob.x--;
	ob.y--;
	return ob;
};


Coord
operator--(Coord& ob, int)
{
	Coord temp=ob;
	--ob;
	return temp;
};


int
main()
{
	int x, y;
	Coord obA(10,20), obB(0,5), obC;

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