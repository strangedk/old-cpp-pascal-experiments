#include <iostream.h>
#include <conio.h>


class Base{

	int x;
public:
	Base(){x=0; cout <<"Base::Base()\n";}
	Base(int _x){x=_x; cout <<"Base::Base(int)\n"; }
	virtual ~Base(){cout <<"Base::~Base()\n"; } // Memory free
};


class Derived: public Base{

public:

	Derived(){cout <<"Derived::Derived()\n";};
	Derived(int _x): Base(_x){cout <<"Derived::Derived(int)\n"; }
	~Derived(){cout <<"Derived::~Derived()\n"; } // Memory free
};


main()
{
	clrscr();
	Base *pBase=new Derived;

	//...

	delete pBase;

	return 0;
};