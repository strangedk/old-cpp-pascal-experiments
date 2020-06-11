#include<iostream>

using namespace std;

class Mammal
{
public:
	Mammal(): m_age(1){ cout<<"Mammal constructor ...\n"; }
	Mammal(const Mammal& rhs);
	virtual ~Mammal(){ cout<<"Mammal destructor ...\n"; }
	
	virtual void Speak() const{ cout<<"Mammal speak\n"; }
	virtual Mammal* Clone(){ return new Mammal(*this); }
	int GetAge() const{ return m_age; }
protected:
	int m_age;
};

Mammal::Mammal(const Mammal& rhs):
m_age(rhs.GetAge())
{
	cout<<"Mammal copy constructor ...\n";
}

class Dog: public Mammal
{
public:
	Dog(){ cout<<"Dog constructor ...\n"; }
	Dog(const Dog& rhs);
	virtual ~Dog(){ cout<<"Dog destructor ...\n"; }

	virtual void Speak() const{ cout<<"Woof\n"; }
	virtual Mammal* Clone(){ return new Dog(*this); }
};

Dog::Dog(const Dog& rhs):
Mammal(rhs)
{
	cout<<"Dog copy constructor ...\n";
}

class Cat: public Mammal
{
public:
	Cat(){ cout<<"Cat constructor ...\n"; }
	Cat(const Cat& rhs);
	virtual ~Cat(){ cout<<"Cat destructor ...\n"; }

	virtual void Speak() const{ cout<<"Meow\n"; }
	virtual Mammal* Clone(){ return new Cat(*this); }
};

Cat::Cat(const Cat& rhs):
Mammal(rhs)
{
	cout<<"Cat copy constructor ...\n";
}

enum ANIMALS { MAMMAL, DOG, CAT };

const int ATypes = 3;

int
main()
{
	Mammal* theArray[ATypes];
	Mammal* ptr;
	int choice, i;

	for(i=0; i<ATypes; i++)
	{
		cout<<"(1)Dog (2)Cat (3)Mammal: ";
		cin>>choice;
		switch(choice)
		{
		case DOG: ptr = new Dog;
			break;
		case CAT: ptr = new Cat;
			break;
		default: ptr = new Mammal;
			break;
		}
		theArray[i] = ptr;
	}
	Mammal *OthArray[ATypes];

	for(i=0; i<ATypes; i++)
	{
		theArray[i]->Speak();
		OthArray[i] = theArray[i]->Clone();
	}
	for(i=0; i<ATypes; i++)
		OthArray[i]->Speak();

	return 0;
}