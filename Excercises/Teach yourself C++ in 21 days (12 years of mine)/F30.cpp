#include<iostream>

using namespace std;

class Cat
{
public:
	Cat(int age): m_age(age){ HowManyCats++; }
	virtual ~Cat(){ HowManyCats--; }
	virtual int GetAge() const{ return m_age; }
	virtual void SetAge(int age){ m_age = age; }

	static int HowManyCats;
private:
	int m_age;
};

int Cat::HowManyCats =0;

int
main()
{
	const int MaxCats =5;
	int i;
	Cat* CatHouse[MaxCats];
	
	for(i=0; i<MaxCats; i++)
		CatHouse[i] = new Cat(i);

	for(i=0; i<MaxCats; i++)
	{
		cout<<"There are " <<Cat::HowManyCats <<" cats !\n"
			<<"Killing the one cat, who is " <<CatHouse[i]->GetAge()
			<<" years old\n";
		delete CatHouse[i];
		CatHouse[i] =0;
	}
	return 0;
}

