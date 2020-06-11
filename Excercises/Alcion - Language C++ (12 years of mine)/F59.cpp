#include<iostream>
#include<deque>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

template<class Arg>
class factorial: public unary_function<Arg,Arg>
{
	public:
		Arg operator()(const Arg& arg)
		{
			Arg a=1;
			for(Arg i=2; i<=arg; i++)
				a*=i;
			return a;
		}
};

int
main()
{
	int init[7]={1,2,3,4,5,6,7};
	deque<int> d(init, init+7);
	vector<int> v(size_t)7);

	transform(d.begin(), d.end(), v.begin(), factorial<int>());

	cout<<"Next numbers: " <<endl;
	copy(d.begin(),d.end(),ostream_iterator<int,char>(cout," "));
	cout<<endl <<endl;
	cout<<"Have next factorials: " <<endl;
	copy(v.begin(),v.end(),ostream_oterator<int,char>(cout," "));

	return 0;
}

