#include <iostream.h>
#include <string.h>
#include <conio.h>


class Base{

protected:
	char Name[22];
public:
	Base(char* name){strcpy(Name,name); }
	virtual void Func(char c)
	{
		cout <<"virtual " <<Name <<"::Func "
		<<"Accept parameter " <<c <<endl;
	}
};


class Derived1: public Base{

public:
	Derived1(char* name): Base(name){}
	void Func(const char* s)
	{
		cout <<Name <<"::Func " <<"Accept parameter "
		<<s <<endl;
	}
	void Func(int n)
	{
		cout <<Name <<"::Func " <<"Accept parameter "
		<<n <<endl;
	}
	virtual void Func(char c)
	{
		cout <<"virtual " <<Name <<"::Func "
		<<"Accept parameter " <<c <<endl;
	}
};


class Derived2: public Derived1{

public:
	Derived2(char* name): Derived1(name){}
	void Func(const char* s)
	{
		cout <<Name <<"::Func " <<"Accept parameter "
		<<s <<endl;
	}
	void Func(double d)
	{
		cout <<Name <<"::Func " <<"Accept parameter "
		<<d <<endl;
	}
	virtual void Func(char c)
	{
		cout <<"virtual " <<Name <<"::Func "
		<<"Accept parameter " <<c <<endl;
	}
};


int
main()
{
	Base obBase("Base");
	Derived1 der1("Derived1");
	Derived2 der2("Derived2");

	clrscr();
	obBase.Func('x');
	der1.Func('y');
	der1.Func(10);
	der1.Func("Der1");
	der2.Func('z');
	der2.Func(3.1415);
	der2.Func("Der2");

	return 0;
};