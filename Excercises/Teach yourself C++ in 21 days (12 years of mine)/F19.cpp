#include<iostream>

using namespace std;

class Mammal
{
public:
	Mammal(): m_age(1){ }
	virtual ~Mammal(){ }
	virtual void Speak() const{ cout<<"Mammal speak!\n"; }
protected:
	int m_age;
};

class Dog: public Mammal
{
public:
	void Speak() const{ cout<<"Woof!\n"; }
};

class Cat: public Mammal
{
public:
	void Speak() const{ cout<<"Meow!\n"; }
};

class Horse: public Mammal
{
public:
	void Speak() const{ cout<<"Whinny!\n"; }
};

class Pig: public Mammal
{
public:
	void Speak() const{ cout<<"Oink!\n"; }
};

int
main()
{
	Mammal* theArray[5];
	Mammal* ptr;
	int choice, i;

	for (i=0; i<5; i++)
	{
		cout<<"(1)Dog (2)Cat (3)Horse (4)Pig: ";
		cin>>choice;
		switch(choice)
		{
		case 1: ptr = new Dog;
			break;
		case 2: ptr = new Cat;
			break;
		case 3: ptr = new Horse;
			break;
		case 4: ptr = new Pig;
			break;
		default: ptr = new Mammal;
			break;
		}
		theArray[i] = ptr;
	}
	for(i=0; i<5; i++)
		theArray[i]->Speak();

	return 0;
}
