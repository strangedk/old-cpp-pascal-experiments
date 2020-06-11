#include<iostream>

using namespace std;

enum BREED { GOLDEN=1, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal
{
public:
	Mammal(){ cout<<"Mammal constructor ...\n"; }
	~Mammal(){ cout<<"Mammal destructor ...\n"; }

	void Speak() const{ cout<<"Mammal sound!\n"; }
	void Sleep() const{ cout<<"Shhh. I'm sleeping.\n"; }
protected:
	int m_age;
	int m_weight;
};

class Dog: public Mammal
{
public:
	Dog(){ cout<<"Dog constructor ...\n"; }
	~Dog(){ cout<<"Dog destructor ...\n"; }

	void WagTail() const { cout<<"Tail wagging ...\n"; }
	void BegForFood() const { cout<<"Begging for food ...\n"; }
	void Speak() const { cout<<"Woof!\n"; }
private:
	BREED m_breed;
};

int
main()
{
	Mammal BigAnimal;
	Dog fido;

	BigAnimal.Speak();
	fido.Speak();

	return 0;
}
