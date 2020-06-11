#include <iostream.h>
#include <conio.h>

/*

	Virtual function overloading Example

*/


class Base{

	int x;
public:
	virtual void SetValue(int _x)
	{
		x=_x;
		cout <<"Base::x = " <<x <<endl;
	};
	virtual void Show(Base *pOB){SetValue(10); };
};


class Derived: public Base{

	int x, y;
public:
	virtual void SetValue(int _x, int _y)
	{
		x=_x;
		y=_y;
		cout <<"Derived::x= " <<x <<"  Derived::y= " <<y <<endl;
	};
	void Show(Base *pOB){SetValue(15, 20); };
};


int
main()
{
	Base* Pob1=new Base;
	Base* Pob2=new Derived;

	clrscr();
	Pob1->Show(Pob1);
	Pob2->Show(Pob1);
	Pob2->Show(Pob2);

	return 0;
};