#include <iostream.h>
#include <conio.h>


int
Func(int number)
{
	return number;
};


double
Func(double number)
{
	return number;
};


float
Func(float number)
{
	return number;
};


int
main()
{
	clrscr();

	cout <<Func(44) <<endl;
	cout <<Func(100.65) <<endl;
	cout <<Func(8069689000.129000000) <<endl;

	getch();
return 0;
};

