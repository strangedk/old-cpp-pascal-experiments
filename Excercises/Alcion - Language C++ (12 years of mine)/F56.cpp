#include<iostream>
#include<deque>

using namespace std;

int
main()
{
	deque<int> dq;
	int x;

	cout<<"Enter positive ints, followed by zero:\n";
	while(cin>>x, x!=0)
	{
		if(x%2==0)
			dq.push_back(x);
		else
			dq.push_front(x);
	}
	deque<int>::iterator i;
	cout<<"The deque containts:\n";
	for(i=dq.begin(); i!=dq.end(); i++)
		cout<<*i <<' ';
	cout<<endl;

	return 0;
}