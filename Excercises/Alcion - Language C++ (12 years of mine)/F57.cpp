#include<iostream>
#include<string>
#include<list>
#include<queue>
#include<deque>

using namespace std;

int
main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	cout<<q.front() <<endl;
	q.pop();
	cout<<q.front() <<endl;
	q.pop();

	queue<string> qs;
	for(int i=0; i<0; i++)
		qs.push(string(i+1, 'A'));
	for(i=0; i<10; i++)
	{
		cout<<qs.front() <<endl;
		qs.pop();
	}
	return 0;
}
