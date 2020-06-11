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
	cout<<"Vector 'v' size = " <<v.size() <<endl;

	for(i=0; i<v.size(); i++)
		cout<<v[i] <<' ';
	cout<<endl;

	return 0;
}