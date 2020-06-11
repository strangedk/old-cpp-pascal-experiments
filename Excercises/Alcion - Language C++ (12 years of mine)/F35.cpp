#include <iostream>

using namespace std;

int
main()
{
	int n;
	double d=209.999;

	n=static_cast<int>(d);
	cout<<"Value n=" <<n <<endl;

	int* pi;
	pi=static_cast<int*>(NULL);
	cout<<"Value pi=" <<pi <<endl;

	int day;
	enum Weekend {Saturday, Sunday};
	Weekend WE;
	day=static_cast<int>(Sunday);
	day+=3;
	cout<<"Value day=" <<day <<endl;

	return 0;
};