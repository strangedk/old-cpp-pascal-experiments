#include<iostream>

using namespace std;

class Cat
{
public:
	Cat();

	int GetAge() const { return *m_age; }
	int GetWeight() const { return *m_weight; }
	void SetAge(int age) { *m_age = age; }
	Cat& operator=(const Cat&);
private:
	int* m_age;
	int* m_weight;
};

Cat::Cat()
{
	m_age = new int;
	m_weight = new int;

	*m_age = 5;
	*m_weight = 9;
}

Cat&
Cat::operator=(const Cat& rhs)
{
	if (this==&rhs)
		return *this;
	*m_age = rhs.GetAge();
	*m_weight = rhs.GetWeight();

	return *this;
}

int
main()
{
	Cat frisky;

	cout<<"frisky's age " <<frisky.GetAge() <<endl;
	cout<<"Setting frisky age to 6 ...\n";
	frisky.SetAge(6);

	Cat whiskers;
	cout<<"whiskers age " <<whiskers.GetAge() <<endl;
	cout<<"copying frisky to whiskers ...\n";
	whiskers = frisky;
	cout<<"whiskers age " <<whiskers.GetAge() <<endl;

	return 0;
}
