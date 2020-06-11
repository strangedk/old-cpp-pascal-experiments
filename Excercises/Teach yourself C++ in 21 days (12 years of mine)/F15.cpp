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
	operator unsigned short();
private:
	int m_val;
};

Counter::Counter():
m_val(0)
{ }

Counter::Counter(int val):
m_val(val)
{ }

Counter::operator unsigned short()
{
	return (int(m_val));
}

int
main()
{
	Counter ctr(5);

	int theShort = ctr;
	cout<<"theShort " <<theShort <<endl;

	return 0;
}

