#include<iostream>

using namespace std;

// class Counter
class Counter
{
public:
	// Constructors
	Counter();
	~Counter(){ }
	// Member functions
	int GetVal() const { return m_val; } // get number
	void SetVal(int v){ m_val = v; } // set number
	void Increment(){ ++m_val; } // increment number
	Counter operator++(); // overload operator '++' for Counter class 
private:
	// Member variables
	int m_val;
};

// default constructor
Counter::Counter():
// variable initalization
m_val(0)
{ }

Counter // increment operator for Counter class
Counter::operator++()
{
	++m_val; // increment number
	Counter temp; // create temporary object temp
	temp.SetVal(m_val); // set number of temp 
	return temp; 
}

int
main()
{
	Counter i; // new object, as integer, but in class

	cout<<"The value of number is " <<i.GetVal() <<endl;
	i.Increment();
	cout<<"The value of number is " <<i.GetVal() <<endl;
	++i;
	cout<<"The value of number is " <<i.GetVal() <<endl;

	Counter a = ++i; // new object, copy number from i to a
	cout<<"The value of a: " <<a.GetVal() <<" and i: " <<i.GetVal() <<endl;

	return 0;
}
