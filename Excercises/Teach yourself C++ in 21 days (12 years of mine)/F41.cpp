#include<iostream>

using namespace std;

int
main()
{
	char stringOne[256];
	char stringTwo[256];

	cout<<"Enter string one: ";
	cin.get(stringOne,256);
	cout<<"stringOne: " <<stringOne <<endl;

	cout<<"Enter string two: ";
	cin>>stringTwo;
	cout<<"stringTwo: " <<stringTwo <<endl;

	return 0;
}