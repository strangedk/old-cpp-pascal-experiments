#include <iostream.h>
#include <conio.h>

/*

	Virtual and Not_Virtual function

*/


class Base{

public:
	virtual void VirtFunc(){cout <<"Base::VirtFunc() \n"; };
	void NonVirtFunc(){cout <<"Base::NonVirtFunc() \n"; };

};



class Derived: public Base{

public:
	void VirtFunc(){cout <<"Derived::VirtFunc()\n"; };
	void NonVirtFunc(){cout <<"Derived::NonVirtFunc() \n"; };
};


int
main()
{
	Derived* ob1=new Derived;
	Base* ob2=new Derived;

	clrscr();
	ob2->VirtFunc();
	ob2->NonVirtFunc();
	ob1->VirtFunc();
	ob1->NonVirtFunc();

	return 0;
};