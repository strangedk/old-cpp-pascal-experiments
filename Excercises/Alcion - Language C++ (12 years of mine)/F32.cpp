#include<iostream.h>
#include<typeinfo.h>

class PMorClass
{
	virtual void vFunc(){};
};

class Derived: public PMorClass{};

int
main()
{
	Derived DerOb;
	PMorClass* POb;

	POb=&DerOb;
	if(typeid(*POb)==typeid(Derived)) cout<<"Type name is " <<typeid(*POb).name();
	if(typeid(*POb)!=typeid(PMorClass)) cout<<"\nPointer is not PMorClass type!";

	return 0;
};
