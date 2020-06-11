#include <iostream.h>
#include <typeinfo>

class Base{};
class Derived: public Base{};

int
main()
{
	char C;
	float X;
	Derived DerOb;
	Base* pBase = &DerOb;

	if(typeid(C)==typeid(X))
		cout <<"C and X has same type.\n";
	else
		cout <<"C and X has don't same type.\n";

	cout <<typeid(int).name() <<" Before " <<typeid(double).name() <<": "
		 <<(typeid(int).before(typeid(double))? true: false) <<endl;

	cout <<typeid(double).name() <<" Before " <<typeid(int).name() <<": "
		 <<(typeid(double).before(typeid(int))? true: false) <<endl;

	if(typeid(pBase)==typeid(DerOb))
		cout <<"Base and Derived has same type \n";
	else
		cout <<"Base and Derived has don't same type \n";

	cout <<typeid(pBase).name() <<" Before " <<typeid(DerOb).name() <<": "
	     <<(typeid(pBase).before(typeid(DerOb))? true: false) <<endl;

	return 0;

};