#include<iostream>
#include<map>

using namespace std;

int
main()
{
	char c;
	map<char, int> m;
	for(int i=0; i<10; i++)
		m.insert(pair<char, int>('A'+i, i));
	cout<<"Input key: ";
	cin>>c;

	map<char, int>::iterator iter;
	iter=m.find(c);
	if(iter!=m.end())
		cout<<iter->second;
	else
		cout<<"Element is not visible\n";
	return 0;
}
