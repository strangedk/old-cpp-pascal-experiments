#include<iostream>

using namespace std;

class Counter
{
public:
	// Constructors
	Counter(); // Default constructor
	~Counter(){ }; // Destructor
	// Member functions
	int GetVal() const { return m_val; } // get number
	void SetVal(int v) { m_val = v; } // set number
	void Increment() { ++m_val; } // increment number
	// Operators
	const Counter& operator++();
private:
	int m_val; // number
}; // End of class Counter

// default constructor
Counter::Counter():
// initalization
m_val(0)
{ }

const Counter& // operator ++
Counter::operator++()
{
	++m_val; // ++ number
	return *this; // return object who has number
}

int
main()
{
	Counter i; // new number i

	cout<<"The value of i is " <<i.GetVal() <<endl;
	i.Increment();
	cout<<"The value of i is " <<i.GetVal() <<endl;
	++i;
	cout<<"The value of i is " <<i.GetVal() <<endl;

	Counter a = ++i; // new number a, with value i
	cout<<"The value of a: " <<a.GetVal() <<" and i: " <<i.GetVal() <<endl;

	return 0;
}
