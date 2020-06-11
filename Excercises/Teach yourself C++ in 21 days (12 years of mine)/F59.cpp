#include<iostream>
#include<list>

using namespace std;

typedef list<int> IntegerList;

int
main()
{
	IntegerList IntList;

	for(int i=0; i<17; i++)
		IntList.push_back(i * 2);

	IntegerList::const_iterator cont;

	for(cont=IntList.begin(); cont != IntList.end(); ++cont)
		cout<<*cont <<" ";
	cout<<endl <<endl;;

	return 0;
}