#include <iostream.h>
#include <exception>

class Data
{
	public:
	Data(){cout <<"Data::Data()\n Throw exception\n"; throw "Error."; }
	~Data(){cout <<"Data::Data()\n"; }
};

class Base
{
public:
	Base(){cout <<"Base::Base()\n"; }
	~Base(){cout <<"Base::~Base()\n"; }
};

class Derived: public Base
{
	Data data;
public:
	Derived(){cout <<"Derved::Derived()\n"; }
	~Derived(){cout <<"Derived::~Derived()\n"; }

	void* operator new(size_t size)
	{
		cout <<"Calling operator new for Derived\n";
		return ::operator new(size); 
	}
	void operator delete(void* p)
	{
		cout <<"Derived::delete\n";
		::delete p;
	}
};

int
main()
{
	try
	{
		Derived* pDerOb=new Derived;
		delete pDerOb;
	}
	catch(const char* s)
	{
		cout <<s <<endl;
	}
	return 0;
};