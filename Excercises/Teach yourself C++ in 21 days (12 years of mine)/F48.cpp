#include<stdio.h>

// using namespace std;

int
main()
{
	printf("%s","Hello world!\n");

	char* phrase = "Hello again!\n";
	printf("%s",phrase);

	int x = 5;
	printf("%d\n",x);

	char* phrase2 = "Here's some values: ";
	char* phrase3 = "and also these: ";

	int y = 7;
	int z = 35;
	long longVar = 98456;
	float floatVar = 8.8f;

	printf("%s %d %d %s %ld %f\n",phrase2,y,z, phrase3,longVar,floatVar);

	char* phrase4 = "Formatted: ";
	printf("%s %5d %10d %10.5f\n",phrase4,y,z,floatVar);

	return 0;
}
