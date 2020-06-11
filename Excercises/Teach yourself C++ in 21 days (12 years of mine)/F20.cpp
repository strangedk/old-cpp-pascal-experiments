#include<iostream>

using namespace std;

class Mammal
{
public:
	Mammal(): m_age(1){ }
	virtual ~Mammal(){ }
	virtual void Speak() const{ cout<<"Mammal speak!\n."; }
protected:
	int m_age;
};

class Dog: public Mammal
{
public:
	virtual void Speak() const{ cout<<"Woof!\n"; }
};

class Cat: public Mammal
{
public:
	virtual void Speak() const{ cout<<"Meow!\n"; }
};

void
ValueFunction(Mammal Mam)
{
	Mam.Speak();
}

void
PointerFunction(Mammal* pMam)
{
	pMam->Speak();
}

void
ReferenceFunction(Mammal& rMam)
{
	rMam.Speak();
}

int
main()
{
	Mammal* ptr = 0;
	int choice;

	while(1)
	{
		bool fQuit = false;

		cout<<"(1)Dog (2)Cat (0)Quit: ";
		cin>>choice;
		switch(choice)
		{
		case 0: fQuit = true;
			break;
		case 1: ptr = new Dog;
			break;
		case 2: ptr = new Cat;
			break;
		default: ptr = new Mammal;
			break;
		}
		if(fQuit)
			break;
		PointerFunction(ptr);
		ReferenceFunction(*ptr);
		ValueFunction(*ptr);
	}

	return 0;
}