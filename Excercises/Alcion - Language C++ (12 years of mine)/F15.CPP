#include <iostream.h>
#include <conio.h>


class Base{

public:
	virtual void VirtFunc(){cout <<"Base::VirtFunc\n"; }
	void NonVirtFunc(){cout <<"Base::NonVirtFunc\n"; }
};


class Derived: public Base{

public:
	void VirtFunc(){cout <<"Derived::VirtFunc\n"; }
	void NonVirtFunc(){cout <<"Derived::NonVirtFunc\n"; }
};


int
main()
{
	Base* pBase = new Derived;

	clrscr();
	pBase->VirtFunc();
	pBase->NonVirtFunc();

	return 0;
};