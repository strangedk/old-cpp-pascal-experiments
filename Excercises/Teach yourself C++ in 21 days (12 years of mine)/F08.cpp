#include<iostream>

using namespace std;

// Counter class
class Counter
{
public:
	// Constructors
	Counter();
	Counter(int val);
	~Counter(){ };
	// Member functions
	int GetVal() const { return m_val; }
	void SetVal(int v) { m_val = v; }
	void Increment() { ++m_val; }
	// operators
	Counter operator++();
private:
	// Member variables
	int m_val;
};

// default constructor
Counter::Counter():
// initalization
m_val(0)
{ }

// constructor with one argument
Counter::Counter(int val):
// initalization
m_val(val)
{ }

Counter // operator increment for class Counter
Counter::operator++()
{
	++m_val;
	return Counter(m_val); // return number
}

int
main()
{
	Counter i; // new object i
	cout<<"The value of i is " <<i.GetVal() <<endl;
	i.Increment();
	cout<<"The value of i is " <<i.GetVal() <<endl;
	++i;
	cout<<"The value of i is " <<i.GetVal() <<endl;

	Counter a = ++i; // new object a from value i
	cout<<"The value of a: " <<a.GetVal() <<" and i: " <<i.GetVal() <<endl;

	return 0;
}
