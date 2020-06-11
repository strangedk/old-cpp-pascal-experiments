#include<iostream>

using namespace std;

class SimpleCat
{
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();

	int GetAge() const {return itsAge; }
	void SetAge(int age) {itsAge=age; }
private:
	int itsAge;
};

SimpleCat::SimpleCat()
{
	cout<<"Simple Cat Constructor ...\n";
	itsAge=1;
}

SimpleCat::SimpleCat(SimpleCat&)
{
	cout<<"Simple Cat Copy Constructor ...\n";
}

SimpleCat::~SimpleCat()
{
	cout<<"Simple Cat Destructor ...\n";
}

const SimpleCat & Func(const SimpleCat &theCat);

int
main()
{
	cout<<"Making a cat ...\n";
	SimpleCat Frisky;
	cout<<"Frisky is ";
	cout<<Frisky.GetAge();
	cout<<" years old.\n";

	int age=5;
	Frisky.SetAge(age);
	cout<<"Frisky is ";
	cout<<Frisky.GetAge();
	cout<<" years old.\n\n";
	cout<<"Calling Func ...\n";
	Func(Frisky);
	cout<<"Frisky is ";
	cout<<Frisky.GetAge();
	cout<<" years old\n";

	return 0;
}

const SimpleCat & Func(const SimpleCat &theCat)
{
	cout<<"Func. Returning....\n";
	cout<<"Frisky is now " <<theCat.GetAge();
	cout<<" Years old\n";
	
	return theCat;
}
