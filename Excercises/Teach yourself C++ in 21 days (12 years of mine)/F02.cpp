#include<iostream>

using namespace std;

class SimpleCat
{
public:
	SimpleCat(){cout<<"Simple Cat Constructor ...\n"; }
	SimpleCat(SimpleCat&){cout<<"Simple Cat Copy Constructor ...\n"; }
	~SimpleCat(){cout<<"Simple Cat Destructor ...\n"; }
};

SimpleCat Func1(SimpleCat Cat);
SimpleCat* Func2(SimpleCat* Cat);

int
main()
{
	cout<<"Making a cat ...\n";
	SimpleCat Frisky;
	cout<<"Calling Func1 ...\n";
	Func1(Frisky);
	cout<<"Calling Func2 ...\n";
	Func2(&Frisky);

	return 0;
}

SimpleCat
Func1(SimpleCat theCat)
{
	cout<<"Func1. Returning ...\n";
	return theCat;
}

SimpleCat*
Func2(SimpleCat *theCat)
{
	cout<<"Func2. Returning ...\n";
	return theCat;
}