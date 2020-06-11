#include <stdio.h>

bool test;
class ExClass{};

void ExThrowFunc(bool Bvar) throw(ExClass)
{
	if(Bvar) throw ExClass();
}

void TestFunc() throw()
{
	try
	{
		ExThrowFunc(true);
	}
	catch(ExClass &e)
	{
		test=true;
	}
}

int
main()
{
	test=false;
	TestFunc();
	return test ? (puts("Exception TestFunc() "),1): (puts("Exception Nope! "),0);
}
