#include<iostream>
#include<vector>

using namespace std;

int
main()
{
	vector<int> v;
	int i;

	for(i=0; i<5; i++)
		v.push_back(i);
	cout<<"Vector v size = " <<v.size() <<endl;
	cout<<"Kept in repair:\n";
	vector<int>::iterator p=v.begin();
	while(p!=v.end())
	{
		cout<<*p <<' ';
		p++;
	}
	cout<<endl;

	return 0;
}