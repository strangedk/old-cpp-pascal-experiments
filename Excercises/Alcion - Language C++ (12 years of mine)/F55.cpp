#include<iostream>
#include<list>
#include<stdlib>

using namespace std;

typedef list<char> MList;

int
main()
{
	Mlist clist;

	for(int i=0; i<10; i++)
		clist.push_back('F'+(rand()%26));
	cout<<"Initial list: ";
	MList::iterator iter=clist.begin();
	while(iter!=clist.end())
	{
		cout<<*iter;
		iter++;
	}
	cout<<endl;
	clist.sort();
	cout<<"Sorted list: ";
	iter=clist.begin();
	while(iter!=clist.end())
	{
		cout<<*iter;
		iter++;
	}
	cout<<endl;

	return 0;
}
