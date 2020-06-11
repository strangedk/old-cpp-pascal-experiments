#include <exception>
#include <iostream>

using namespace std;

void My_Term_Func()
{
	cout <<"My_Term_Func() been called Terminate().\n";
	exit(-1);
}

int
main()
{
	int i=10, j=0, res;
	set_terminate(My_Term_Func);
	try
	{
		if(j==0)
			throw "Division by zero!\n";
		else
			res=i/j;
	}
	catch(int)
	{
		cout <<"Integer Exception\n";
	}
	cout <<"This line is can't printing\n";
	return 0;
}