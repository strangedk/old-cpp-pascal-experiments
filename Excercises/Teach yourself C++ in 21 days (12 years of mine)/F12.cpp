#include<iostream>

using namespace std;

class Counter
{
public:
	Counter();
	Counter(int val);
	~Counter(){ };

	int GetVal() const { return m_val; }
	void SetVal(int v) { m_val = v; }

	Counter operator+(const Counter&);
private:
	int m_val;
};

Counter::Counter():
m_val(0)
{ }

Counter::Counter(int val):
m_val(val)
{ }

Counter
Counter::operator+(const Counter & rhs)
{
	return Counter(m_val + rhs.GetVal());
}

int
main()
{
	Counter var1(2), var2(4), var3;

	var3 = var1 + var2;
	cout<<"var1 : " <<var1.GetVal() <<endl;
	cout<<"var2 : " <<var2.GetVal() <<endl;
	cout<<"var3 : " <<var3.GetVal() <<endl;

	return 0;
}
