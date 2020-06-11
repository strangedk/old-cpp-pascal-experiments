#include <iostream.h>
#include <conio.h>

/*

	Virtual Function Example

*/


class Base{

	int x;
public:
	Base(int _x){x=_x; }
	int GetX(){return x; }
	virtual void OutX();
};


void
Base::OutX()
{
	cout <<"Error. This function have not access for type Base.\n";
};


class Derived1: public Base{

public:
	Derived1(int _x): Base(_x){}
	void OutX();
};



void
Derived1::OutX()
{
	cout <<"Derived1::x = " <<GetX() <<endl;
};



class Derived2: public Base{

public:
	Derived2(int _x): Base(_x){}
	void OutX();
};


void
Derived2::OutX()
{
	cout <<"Derived2::x = " <<GetX() <<endl;
};


int
main()
{
	Derived1 *pDer1=new Derived1(10);
	Derived2 *pDer2=new Derived2(20);
	Base *pBase=pDer1;

	clrscr();
	pBase->OutX();
	pBase=pDer2;
	pBase->OutX();

	return 0;
};