#include<iostream>

using namespace std;

int
main(int argc, char* argv[])
{
	cout<<"Received " <<argc <<" arguments...\n";

	for(int i=0; i<argc; i++)
		cout<<"argument " <<i <<": " <<argv[i] <<endl;

	return 0;
}