#include<iostream>

using namespace std;

typedef unsigned short int ushort;

enum err_code {success, error};

err_code Factor(ushort, ushort&, ushort&);

int
main()
{
	ushort number, squared, cubed;
	err_code result;

	cout<<"Enter number (0-100): ";
	cin>>number;

	result=Factor(number, squared, cubed);

	if(result==success)
	{
		cout<<"Number = " <<number <<endl;
		cout<<"Squared = " <<squared <<endl;
		cout<<"Cubed = " <<cubed <<endl;
	}
	else
		cout<<"Error: Out of range \n";
	return 0;
}

err_code
Factor(ushort n, ushort &squared, ushort &cubed)
{
	if(n>100)
		return error;
	squared=n*n;
	cubed=n*n*n;
	return success;
}