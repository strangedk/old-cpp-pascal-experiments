#include<iostream>

using namespace std;

// The class Counter for storage of the meter
class Counter
{
public:
	// constructors
	Counter();
	~Counter(){ }
	// Functions members
	int GetVal() const { return m_val; } // get meter value
	void SetVal(int v) { m_val = v; } // set meter value
	const Counter& operator++(); // PreIncrement operator
	const Counter operator++(int); // PostIncrement operator
private:
	int m_val; // meter 
};
// end of Counter class

// default constructor
Counter::Counter():
// Initalization
m_val(0)
{ }

// PreIncrement operator
const Counter&
Counter::operator++()
{
	++m_val; // meter ++
	return *this; // return this object
}

// PostIncrement operator
const Counter
Counter::operator++(int x)
{
	Counter temp(*this); // new temp object, with value of *this
	++m_val; // meter ++
	return temp; // return temp object
}

int 
main()
{
	Counter i; // new counter
	cout<<"The value of i is " <<i.GetVal() <<endl;
	i++;
	cout<<"The value of i is " <<i.GetVal() <<endl;
	++i;
	cout<<"The value of i is " <<i.GetVal() <<endl;

	Counter a = ++i; // new counter, with meter as i
	cout<<"The value of a: " <<a.GetVal() <<" and i: " <<i.GetVal() <<endl;
	a = i++;
	cout<<"The value of a: " <<a.GetVal() <<" and i: " <<i.GetVal() <<endl;

	return 0;
}
