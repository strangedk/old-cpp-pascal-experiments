#include<iostream>
#include<string>

using namespace std;

int
main()
{
	string str;

	while(str.empty() || str.size() <=5)
	{
		cout <<"Input string from 5 up to 20 symbols.\n";
		cin >>str;
	}

	cout<<"Replace thirth symbol with '"
		<<str[2] <<"' to '*' \n";
	str[2]='*';

	cout<<"Now: \n" <<str <<endl <<endl;
	cout<<"Find center symbol: \n";
	str.insert(str.size()/2,"(ceredina here!)");

	cout <<str <<endl <<endl;
	cout <<"Eh, I don't like word 'ceredina', and instead of him, I say:\n";
	str.replace(str.find("ceredina",0),8,"center");
	cout <<str <<endl;

	return 0;
}