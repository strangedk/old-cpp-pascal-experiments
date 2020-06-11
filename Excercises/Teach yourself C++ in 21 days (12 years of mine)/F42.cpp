#include<iostream>

using namespace std;

int
main()
{
	char string1[256];
	char string2[256];
	char string3[256];

	cout<<"Enter string one: ";
	cin.getline(string1,256);
	cout<<"string1: " <<string1 <<endl;

	cout<<"Enter string two: ";
	cin>>string2;
	cout<<"string2: " <<string2 <<endl;

	cout<<"Enter string three: ";
	cin.getline(string3,256);
	cout<<"string3: " <<string3 <<endl;

	return 0;
}