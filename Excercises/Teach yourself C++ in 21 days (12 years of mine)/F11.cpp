#include<iostream>

using namespace std;

class Counter
{
public:
	Counter();
	Counter(int);
	~Counter(){ }
	
	int GetVal() const { return m_val; }
	void SetVal(int v) { m_val = v; }
	Counter Add(const Counter &);
private:
	int m_val;
};

Counter::Counter(int v):
m_val(v)
{ }

Counter::Counter():
m_val(0)
{ }

Counter
Counter::Add(const Counter& rhs)
{
	return Counter(m_val + rhs.GetVal());
}

int
main()
{
	Counter var1(2), var2(4), var3;

	var3 = var1.Add(var2);
	cout<<"var1: " <<var1.GetVal() <<endl;
	cout<<"var2: " <<var2.GetVal() <<endl;
	cout<<"var3: " <<var3.GetVal() <<endl;

	return 0;
}