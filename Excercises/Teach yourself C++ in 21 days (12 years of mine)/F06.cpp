#include<iostream>

using namespace std;

// Class Cat
class Cat
{
public:
	// Constructors
	Cat();
	Cat(const Cat&);
	~Cat();
	//Member functions
	int GetAge() const {return *m_age; } // Return age
	int GetWeight() const {return *m_weight; } //Return weight
	void SetAge(int age) {*m_age = age; } // Set age
private:
	// Member variables
	int* m_weight; // weight
	int* m_age; // age
}; // End of constructor

Cat::Cat() // Default constructor
{
	m_age = new int; // Set new memory for age
	m_weight = new int; // Set new memory for weight

	*m_age = 5; // age = 5
	*m_weight = 9; // weight = 9

	cout<<"\n   Constructor   \n";
}

Cat::Cat(const Cat & rhs) // Copy constructor
{
	m_age = new int; // Set new memory, for age of new object
	m_weight = new int; // Set new memory, for weight of new object

	*m_age = rhs.GetAge(); // new age nas be as old 
	*m_weight = rhs.GetWeight(); // new weight nas be as old

	cout<<"\n   Copy constructor   \n";
}

Cat::~Cat() // Destructor
{
	delete m_age; // delete memory of age
	m_age = 0; // set pointer zero
	delete m_weight; // delete memory of weight
	m_weight = 0; // set pointer zero

	cout<<"\n   Destructor   \n";
}

int
main()
{
	Cat frisky; // new cat (frisky)

	cout<<"frisky's age: " <<frisky.GetAge() <<endl;
	cout<<"Setting frisky age to 6 ...\n";
	frisky.SetAge(6);
	cout<<"Creating boots from frisky ...\n";
	
	Cat boots(frisky); // new (copy) cat from frisky (boots)

	cout<<"frisky's age: " <<frisky.GetAge() <<endl;
	cout<<"boots age: " <<boots.GetAge() <<endl;
	cout<<"setting frisky age to 7 ...\n";
	frisky.SetAge(7);
	
	cout<<"frisky age: " <<frisky.GetAge() <<endl;
	cout<<"boots age: " <<boots.GetAge() <<endl;

	return 0;
}
