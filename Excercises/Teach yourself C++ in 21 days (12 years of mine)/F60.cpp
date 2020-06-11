#include<iostream>
#include<string>
#include<map>

using namespace std;

class Student
{
public:
	Student();
	Student(const string& name, const int age);
	Student(const Student& rhs);
	~Student();

	void	SetName(const string& name);
	string	GetName() const;
	void	SetAge(const int age);
	int		GetAge() const;

	Student& operator= (const Student& rhs);
private:
	string	m_Name;
	int		m_Age;
};

Student::Student():
m_Name("New Student"),
m_Age(16)
{	}

Student::Student(const string& name, const int age):
m_Name(name),
m_Age(age)
{	}

Student::Student(const Student& rhs):
m_Name(rhs.GetName()),
m_Age(rhs.GetAge())
{	}

Student::~Student()
{	}

void
Student::SetName(const string& name)
{
	m_Name = name;
}

string
Student::GetName() const
{
	return m_Name;
}

void
Student::SetAge(int age)
{
	m_Age = age;
}

int
Student::GetAge() const
{
	return m_Age;
}

Student&
Student::operator= (const Student& rhs)
{
	m_Name = rhs.GetName();
	m_Age = rhs.GetAge();
	return *this;
}

ostream&
operator<< (ostream& os, const Student& rhs)
{
	os<<rhs.GetName() <<" is "  <<rhs.GetAge() <<" years old";
	return os;
}

template <class T, class A>
void ShowMap(const map<T, A>& v);

typedef map<string, Student> SchoolClass;

int
main()
{
	Student Harry("Harry", 18);
	Student Sally("Sally", 15);
	Student Billy("Billy", 17);
	Student Peter("Peter", 16);

	SchoolClass MathClass;

	MathClass[Harry.GetName()] = Harry;
	MathClass[Sally.GetName()] = Sally;
	MathClass[Billy.GetName()] = Billy;
	MathClass[Peter.GetName()] = Peter;

	cout<<"MathClass:\n";
	ShowMap(MathClass);

	cout<<"We know what " <<MathClass["Billy"].GetName()
		<<" is " <<MathClass["Billy"].GetAge() <<" years old\n";

	return 0;
}

template <class T, class A>
void ShowMap(const map<T, A>& v)
{
	map<T, A>::const_iterator ci;

	for(ci = v.begin(); ci != v.end(); ++ci)
		cout<<ci->first <<": " <<ci->second <<endl;
	cout<<endl;
}