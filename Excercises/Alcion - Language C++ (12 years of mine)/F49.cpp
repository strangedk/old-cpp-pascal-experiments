#include<iostream>
#include<string>

using namespace std;

template <class T>
const T& max(const T& a, const T& b)
{
	return a>b ? a: b;
}

char* max(char* str1, char* str2)
{
	return strcmp(str1,str2)>=0 ? str1: str2;
}

int
main()
{
	int m=9, n=12;
	char* str1="B";
	char* str2="A";

	cout<<"Max int = " <<max(m,n) <<endl;
	cout<<"Max str = " <<max(str1,str2) <<endl;

	return 0;
}