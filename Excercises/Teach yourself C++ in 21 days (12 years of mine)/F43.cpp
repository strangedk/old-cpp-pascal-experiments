#include<iostream>

using namespace std;

int
main()
{
	char string1[255];
	char string2[255];

	cout<<"Enter stirng one: ";
	cin.get(string1,255);
	cout<<"String one: " <<string1 <<endl;

	cout<<"Enter string two: ";
	cin.getline(string2,255);
	cout<<"String two: " <<string2 <<endl;

	cout<<"\n\nNow try again...\n";

	cout<<"Enter string one: ";
	cin>>string1;//.get(string1,255);
	cout<<"String one: " <<string1 <<endl;

	cin.ignore(255,'\n');

	cout<<"Enter string two: ";
	cin.getline(string2,255);
	cout<<"String two: " <<string2 <<endl;

	return 0;
}