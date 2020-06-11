#include<iostream>

using namespace std;

class Mammal
{
public:
	Mammal(): m_age(1){ cout<<"Mammal constructor ...\n"; }
	virtual ~Mammal(){ cout<<"Mammal destructor ...\n"; }

	void Move() const{ cout<<"Mammal move one step.\n"; }
	virtual void Speak() const{ cout<<"Mammal speak!"; }
protected:
	int m_age;
};

class Dog: public Mammal
{
public:
	Dog(){ cout<<"Dog constructor ...\n"; }
	virtual ~Dog(){ cout<<"Dog destructor ...\n"; }

	void WagTail(){ cout<<"Wagging Tail ...\n"; }
	void Speak() const{ cout<<"Woof!\n"; }
	void Move() const{ cout<<"Dog moves 5 steps ...\n"; }
};

int
main()
{
	Mammal *pDog = new Dog;

	pDog->Move();
	pDog->Speak();

	delete pDog;

	return 0;
}

