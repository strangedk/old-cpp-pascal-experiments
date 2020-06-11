#include <iostream.h>
#include <typeinfo.h>

class Base1
{
public:
	virtual void vFunc(){cout<<"Call function vFunc()\n"; };
};

class Bcast{};
class Base2{};
class Derived: public Base1, public Base2 {};

int
main()
{
	try
	{
		Derived derOb, *pderOb;
		Base1* pBase1;

		pBase1=&derOb;
		pderOb=(Derived*)pBase1;
		pderOb->vFunc();
		if((pderOb=dynamic_cast<Derived*>(pBase1))!=0)
		{
			cout<<"Result pointer has type " <<typeid(pderOb).name() <<endl;
			pderOb->vFunc();
		}
		else
			throw Bcast();
		
		Base2* pBase2;
		//pBase1=NULL;
		if((pBase2=dynamic_cast<Base2*>(pBase1))!=0)
		{
			cout<<"Result pointer has type " <<typeid(pBase2).name() <<endl;
		}
		else
			throw throw Bcast();
	}
	catch(Bcast)
	{
		cout<<"Failure in dynamic_cast!\n";
		return 1;
	}
	return 0;
};