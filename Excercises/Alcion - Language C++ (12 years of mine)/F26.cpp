#include <iostream.h>

class Base{};
class Derived: public Base{};

void
FuncExDerived()
{
	Derived derOb;
	throw derOb;
};

int
main()
{
	try
	{
		try
		{
			FuncExDerived();
		}
		catch(Derived&)
		{
			cout<<"Exception is intercepted in Derived&" <<endl;
		}
		Base baseOb;
		throw baseOb;
	}
	catch(Base&)
	{
		cout<<"Exception is intercepted in Base&" <<endl;
	}
	return 0;
};