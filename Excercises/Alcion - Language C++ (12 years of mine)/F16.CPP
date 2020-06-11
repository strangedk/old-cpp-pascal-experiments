#include <iostream.h>
#include <conio.h>

class Base{

public:
	virtual void VirtFunc(){cout <<"Base::VirtFunc()\n"; }
};


class Derived: public Base{

public:
	virtual void VirtFunc(){cout <<"Derived::VirtFunc()\n"; }
};


int
main()
{
	Base* pBase = new Derived;

	pBase->VirtFunc();
	pBase->Base::VirtFunc();

	return 0;
};