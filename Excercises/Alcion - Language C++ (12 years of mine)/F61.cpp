#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int
main()
{
	int d1[4]={1,2,3,4};
	vector<int> v1(d1,d1+4),v2(d1,d1+4);
	vector<int> v3;

	fill(v2.begin(),v1.end(),9);
	fill_n(v2.begin(),3,7);
	fill_n(back_inserter(v3),5,11);
	ostream_iterator<int,char> out(cout," ");
	copy(v1.begin(),v1.end(),out);
	cout<<endl;
	copy(v2.begin(),v2.end(),out);
	cout<<endl;
	copy(v3.begin(),v3.end(),out);
	cout<<endl;

	return 0;
}
