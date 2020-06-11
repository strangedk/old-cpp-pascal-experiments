#include<iostream>

using namespace std;
typedef int Hands;
enum Color { Red, Green, Blue, Yellow, White, Black, Brown };

class Animal
{
public:
	Animal(int);
	virtual ~Animal(){ cout<<"Animal Destructor...\n"; }
	virtual int GetAge() const{ return m_age; }
	virtual void SetAge(int age){ m_age = age; }
private:
	int m_age;
};

Animal::Animal(int age):
m_age(age)
{
	cout<<"Animal Constructor...\n";
}

class Horse: public Animal
{
public:
	Horse(Color, Hands, int);
	virtual ~Horse(){ cout<<"Horse Destructor...\n"; }
	virtual void Whinny() const{ cout<<"Whinny!...\n"; }
	virtual Hands GetHeight() const{ return m_height; }
	virtual Color GetColor() const{ return m_color; }
protected:
	Hands m_height;
	Color m_color;
};

Horse::Horse(Color color, Hands height, int age):
Animal(age),
m_color(color),
m_height(height)
{
	cout<<"Horse Constructor...\n";
}

class Bird: public Animal
{
public:
	Bird(Color color, bool migrates, int age);
	virtual ~Bird(){ cout<<"Bird Destructor...\n"; }
	virtual void Chirp() const{ cout<<"Chirp!...\n"; }
	virtual void Fly() const{ cout<<"I can Fly! I can Fly! I can Fly!"; }
	virtual Color GetColor() const{ return m_color; }
	virtual bool GetMigration() const{ return m_migration; }
protected:
	Color m_color;
	bool m_migration;
};

Bird::Bird(Color color, bool migrates, int age):
Animal(age),
m_color(color),
m_migration(migrates)
{
	cout<<"Bird Constructor...\n";
}

class Pegasus: public Horse, public Bird
{
public:
	Pegasus(Color, Hands, bool, long, int);
	virtual ~Pegasus(){ cout<<"Pegasus Destructor...\n"; }
	virtual long GetNumBelievers() const{ return m_numBelievers; }
	virtual void Chrip() const{ Whinny(); }
	virtual Color GetColor() const{ return Horse::m_color; }
	virtual int GetAge() const{ return Horse::GetAge(); }
private:
	long m_numBelievers;
};

Pegasus::Pegasus(
	 Color aColor,
	 Hands height,
	 bool migrates,
	 long NumBelieve,
	 int age):
Horse(aColor, height, age),
Bird(aColor, migrates, age),
m_numBelievers(NumBelieve)
{
	cout<<"Pegasus Constructor...\n";
}

int
main()
{
	Pegasus* pPeg = new Pegasus(Red, 5, true, 10, 2);
	int age = pPeg->GetAge();
	cout<<"This pegasus is " <<age <<" years old.\n";
	delete pPeg;
	return 0;
}