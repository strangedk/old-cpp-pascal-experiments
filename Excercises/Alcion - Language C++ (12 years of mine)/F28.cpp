#include <iostream.h>
#include <exception>

class Data
{
public:
	Data(){cout <<"Data::Data()\n Throw exception\n"; throw "Error."; }
	~Data(){cout <<"Data::~Data()\n"; }
};

class Base
{
public:
	Base(){cout <<"Base:Base()\n"; }
	~Base(){cout <<"~Base::Base()\n"; }
};

class Derived: public Base
{
	Data data;
public:
	Derived(){cout <<"Derived::Derived()\n"; }
	~Derived(){cout <<"Derived::~Derived()\n"; }
};

int
main()
{
	try
	{
		Derived DerOb;
	}
	catch(const char* s)
	{
		cout <<s <<endl;
	}
	return 0;
};