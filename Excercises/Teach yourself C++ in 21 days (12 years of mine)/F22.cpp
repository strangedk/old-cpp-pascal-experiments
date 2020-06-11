#include<iostream>

using namespace std;

class Cat
{
public:
	Cat(){ m_age = 1; m_weight = 5; }
	~Cat(){ }
	
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
	Cat* Family[500];
	Cat* pCat;

	for(int i=0; i<500; i++)
	{
		pCat = new Cat;
		pCat->SetAge(2*i + 1);
		Family[i] = pCat;
	}
	for(i=0; i<500; i++)
	{
		cout<<"Cat #" <<i+1 <<": ";
		cout<<Family[i]->GetAge() <<endl;
	}

	return 0;
}