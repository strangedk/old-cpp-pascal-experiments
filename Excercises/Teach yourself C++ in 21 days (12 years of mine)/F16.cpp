#include<iostream>

using namespace std;

enum Breed { golden=1, cairn, dandie, shetland, doberman, lab };

class Mammal
{
public:
	Mammal();
	Mammal(int);
	~Mammal();

	int GetAge() const { return m_age; }
	void SetAge(int age) { m_age = age; }
	int GetWeight() const { return m_weight; }
	void SetWeight(int weight) { m_weight = weight; }

	void Speak() const { cout<<"Mammal sound!\n"; }
	void Sleep() const { cout<<"shhh. I'm sleeping.\n"; }
protected:
	int m_age;
	int m_weight;
};

class Dog: public Mammal
{
public:
	Dog();
	Dog(int);
	Dog(int, int);
	Dog(int, Breed);
	Dog(int, int, Breed);
	~Dog();
	Breed GetBreed() const { return m_breed; }
	void SetBreed(Breed breed) { m_breed = breed; }

	void WagTail() const { cout<<"Tail wagging...\n"; }
	void BegForGood() const { cout<<"Begging for food...\n"; }
protected:
	Breed m_breed;
};

Mammal::Mammal():
m_age(1),
m_weight(5)
{
	cout<<"\tMammal constructor...\n";
}

Mammal::Mammal(int age):
m_age(age),
m_weight(5)
{ 
	cout<<"\tMammal(int) constructor...\n";
}

Mammal::~Mammal()
{
	cout<<"\tMammal destructor...\n";
}

Dog::Dog():
Mammal(),
m_breed(golden)
{
	cout<<"\t\tDog constructor...\n";
}

Dog::Dog(int age):
Mammal(age),
m_breed(golden)
{
	cout<<"\t\tDog(int) constructor...\n";
}

Dog::Dog(int age, int weight):
Mammal(age),
m_breed(golden)
{
	m_weight = weight;
	cout<<"\t\tDog(int, int) constructor...\n";
}

Dog::Dog(int age, int weight, Breed breed):
Mammal(age),
m_breed(breed)
{
	m_weight = weight;
	cout<<"\t\tDog(int, int, Breed constructor...\n";
}

Dog::Dog(int age, Breed breed):
Mammal(age),
m_breed(breed)
{
	cout<<"\t\tDog(int, Breed) constructor...\n";
}

Dog::~Dog()
{
	cout<<"\t\tDog destructor...\n";
}

int
main()
{
	Dog fido;
	Dog rover(5);
	Dog buster(6,8);
	Dog yourkie(3,golden);
	Dog dobbie(4,20,doberman);

	cout<<"Fido is " <<fido.GetAge() <<" years old. " <<"fido weight - "
		<<fido.GetWeight() <<". fido breed - " <<fido.GetBreed() <<endl;

	cout<<"Rover is " <<rover.GetAge() <<" years old. " <<"Rover weight - "
		<<rover.GetWeight() <<". Rover breed - " <<rover.GetBreed() <<endl;

	cout<<"Buster is " <<buster.GetAge() <<" years old. " <<"Buster weight - "
		<<buster.GetWeight() <<". Buster breed - " <<buster.GetBreed() <<endl;

	cout<<"Youkie is " <<yourkie.GetAge() <<" years old. " <<"Yourkie weight - "
		<<yourkie.GetWeight() <<". Yourkie breed - " <<yourkie.GetBreed() <<endl;

	cout<<"Dobbie is " <<dobbie.GetAge() <<" years old. " <<"Dobbie weight - "
		<<dobbie.GetWeight() <<". Dobbie breed - " <<dobbie.GetBreed() <<endl;

	return 0;
}