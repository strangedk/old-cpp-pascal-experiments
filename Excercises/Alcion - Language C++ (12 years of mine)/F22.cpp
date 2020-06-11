#include <stdio.h>

bool test;
class ForExcep{};

void Func(bool Bvar)
{
	if(Bvar) throw ForExcep(); 
}

int
main()
{
	try
	{
		test=true;
		Func(test);
	}
	catch(ForExcep &e)
	{
		test=false;
	}
	return test ? (puts("test=true.\n"),1): (puts("test=false"),0);
}
