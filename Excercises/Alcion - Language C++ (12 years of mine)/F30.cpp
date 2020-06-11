#include <new>
#include <iostream.h>

using namespace std;

// WARNING: this code is not supported in Visual C++ 6.0 and lowest.

class BigClass
{
public:
	BigClass(){};
	~BigClass(){};

	long BigArray[100000000];
};

int
main()
{
	try
	{
		BigClass* p=new BigClass;
	}
	catch(bad_alloc a)
	{
		const char* temp=a.what();
		cout <<temp <<endl;
		cout <<"Exception bad_alloc\n";
	}
	
	BigClass* q=new(nothrow) BigClass;
	if(q==NULL) cout <<"Return pointer NULL\n";

	try
	{
		BigClass* arr=new BigClass[3];
	}
	catch(bad_alloc a)
	{
		const char* temp=a.what();
		cout <<temp <<endl;
		cout <<"Exception bad_alloc\n";
	}
	return 0;
};
