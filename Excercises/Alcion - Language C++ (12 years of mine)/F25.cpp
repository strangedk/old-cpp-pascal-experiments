#include <iostream.h>

class Base{};
class Derived: public Base{};

void FuncExDerived()
{
	Derived derOb;
	throw derOb;
}

void FuncExErr()
{
	throw "Error in function FuncExErr()\n ";
}

int
main()
{
	try
	{
		FuncExDerived();
	}
	catch(Derived)
	{
		cout <<"Exception in Derived\n";
	}
	catch(Base)
	{
		cout <<"Exception in Base\n";
	}
	catch(const char*)
	{
		cout <<"Exception in const char*\n";
	}
	catch(void*)
	{
		cout <<"Exception in void*\n";
	}
	return 0;
}