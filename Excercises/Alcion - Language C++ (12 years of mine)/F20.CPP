#include <iostream.h>
#include <conio.h>


class Base{

public:
	Base(){cout <<"Base::Base()\n"; }
	virtual ~Base()=0;
};


Base::~Base(){cout <<"Base::~Base()\n\n"; };


class Derived: public Base{

public:
	Derived(){cout <<"Derived::Derived()\n"; }
	~Derived(){cout <<"Derived::~Derived()\n"; }
};


void
main()
{
	clrscr();

	Derived *pDerived=new Derived;
	delete pDerived;
	Derived OB;
};