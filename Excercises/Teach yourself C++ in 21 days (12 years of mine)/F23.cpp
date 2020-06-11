#include<iostream>

using namespace std;

class Cat
{
public:
	Cat(): m_age(1), m_weight(5){ cout<<"Constructor called ...\n"; }
	~Cat(){ cout<<"Destructor called ...\n"; }

	int GetAge() const{ return m_age; }
	int GetWeight() const{ return m_weight; }
	void SetAge(int age){ m_age = age; }
protected:
	int m_age;
	int m_weight;
};

int
main()
{
	Cat* Family = new Cat[500];
	
	for(int i=0; i<500; i++)
		Family[i].SetAge(2*i + 1);

	for(i=0; i<500; i++)
	{
		cout<<"Cat #" <<i+1 <<": ";
		cout<<Family[i].GetAge() <<endl;
	}

	delete[] Family;

	return 0;
}
