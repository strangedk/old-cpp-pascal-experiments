#include<iostream>

using namespace std;

int
main()
{
	char* name;
	int len=100;
	int count=0;
	name=new char[len];
	cout <<"Input your name: ";
	cin.getline(name,len);
	count=cin.gcount();
	cout <<"\nNumber of symbols: " <<count-1;

	return 0;
}