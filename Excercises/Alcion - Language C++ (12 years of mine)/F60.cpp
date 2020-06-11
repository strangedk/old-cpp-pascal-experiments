#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

template <class Arg>
class outt_x: private unary_function<Arg,void>
{
	private:
		Arg multip;
	public:
		outt_x(const Arg& x): multip(x){}
		void operator()(const Arg& x)
		{
			cout<<x*multip <<" " <<endl; 
		}
};

int
main()
{
	int seq[5]={1,2,3,4,5};
	vector<int> v(seq,seq+5);
	outt_x<int> fmult(2);
	for_each(v.begin(),v.end,fmult);

	return 0;
}