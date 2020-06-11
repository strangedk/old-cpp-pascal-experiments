#include<iostream>
#include<string>

using namespace std;

int
main()
{
	char One[] = "One man Only";

	int fullLength = strlen(One);
	int tooShort = fullLength - 4;
	int tooLong = fullLength + 4;

	cout.write(One,fullLength) <<"\n";
	cout.write(One,tooShort) <<"\n";
	cout.write(One,tooLong) <<"\n";

	return 0;
}