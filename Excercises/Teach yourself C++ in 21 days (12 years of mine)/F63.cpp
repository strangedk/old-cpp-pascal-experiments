#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <class T>
class Print
{
public:
	void operator() (const T& t)
	{
		cout<<t <<" ";
	}
};

int
main()
{
	Print<int> DoPrint;
	vector<int> vInt(10);

	fill(vInt.begin(), vInt.begin() +5, 1);
	fill(vInt.begin() +5, vInt.end(), 0);

	cout<<"for_each()\n";
	for_each(vInt.begin(), vInt.end(), DoPrint);
	cout<<endl;

	return 0;
}