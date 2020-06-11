#include <iostream.h>
#include <typeinfo>

class Base{};
class Derived: public Base{};

int
main()
{
	Derived derOb, *pderOb;
	Base* pBase;

	pBase=&derOb;
	if((pderOb=static_cast<Derived*>(pBase))!=0)
	{
		cout<<"Result pointer has type " <<typeid(pderOb).name() <<endl;
	}
	return 0;
}