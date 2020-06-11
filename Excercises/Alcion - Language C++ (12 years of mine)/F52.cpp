#include<iostream>
#define SIZE 66

using namespace std;

template <typename T>
class Stack
{
	T stack[SIZE];
	int top;
public:
	Stack() {top=0; }
	void push(T item);
	T pop();
};

template <typename T>
void Stack<T>::push(T item)
{
	if(top>=SIZE)
	{
		cout<<"\nStack Owerflow\n";
		return;
	}
	stack[top]=item;
	top++;
}

template <typename T>
T Stack<T>::pop()
{
	if(top<=0)
	{
		cout<<"\nStack hollow\n";
		return 0;
	}
	top--;
	return stack[top];
}

void Stack<char>::push(char item)
{
	if(top>=SIZE-1)
	{
		cout<<"\nStack Owerflow\n";
		return;
	}
	stack[top]=item;
	top++;
}

int
main()
{
	Stack<int> st1;
	Stack<char> st2;
	int i;

	for(i=0; i<10; i++)
		st1.push(i+1);
	for(i=0; i<26; i++)
		st2.push(char('A'+i));

	cout<<"From stack st1 extracted: \n";
	for(i=0; i<10; i++)
		cout<<st1.pop() <<' ';
	cout<<endl;

	cout<<"From stack st2 extracted: \n";
	for(i=0; i<26; i++)
		cout<<st2.pop() <<' ';

	return 0;
}

