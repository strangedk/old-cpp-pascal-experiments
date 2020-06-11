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
private:
	int m_val;
};

Counter::Counter():
m_val(0)
{ }

Counter::Counter(int val):
m_val(val)
{ }

int
main()
{
	int Num = 5;
	Counter Ctr = Num;
	cout<<"Ctr " <<Ctr.GetVal() <<endl;

	return 0;
}
