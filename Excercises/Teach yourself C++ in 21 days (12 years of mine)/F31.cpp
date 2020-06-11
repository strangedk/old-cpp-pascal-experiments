#include<iostream>

using namespace std;

class Cat
{
public:
	Cat(int age): m_age(age){ ++m_Cats; }
	~Cat(){ HowManyCats--; }
	
	int GetAge() const{ return m_age; }
	void SetAge(int age){ m_age = age; }

	static int GetHowMany(){ return m_Cats; }
private:
	int m_age;
	static int m_Cats;
};

void TeleFunc()
{
	cout<<"There are " <<Cat::GetHowMany <<" cats alive!\n";
}

int Cat::m_Cats = 0;

int
main()
{
	const int MaxCats = 5;
	Cat* CatHouse[MaxCats];
	
	for(int i=0; i<MaxCats; i++)
	{
		CatHouse[i] = new Cat(i);
		TeleFunc();
	}

	for(i=0; i<MaxCats; i++)
	{
		delete CatHouse[i];
		TeleFunc();
	}

	return 0;
}
