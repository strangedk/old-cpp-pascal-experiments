#include<iostream>
#include<string>
#include<vector>

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

	Student& operator= (const Student& ths);
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

template <class T>
void
ShowVector(const vector<T>& v);

typedef vector<Student>  SchoolClass;

int
main()
{
	Student Harry;
	Student Sally("Sally", 15);
	Student Bill("Bill", 17);
	Student Peter("Peter", 16);

	SchoolClass EmptyClass;

	cout<<"EmptyClass:\n";
	ShowVector(EmptyClass);

	SchoolClass GrowlingClass(3);
	
	cout<<"GrowlingClass(3):\n";
	ShowVector(GrowlingClass);

	GrowlingClass[0] = Harry;
	GrowlingClass[1] = Sally;
	GrowlingClass[2] = Bill;

	cout<<"GrowlingClass(3) after assigning students:\n";
	ShowVector(GrowlingClass);

	GrowlingClass.push_back(Peter);
	cout<<"GrowlingClass after added 4th student:\n";
	ShowVector(GrowlingClass);

	GrowlingClass[0].SetName("Harry");
	GrowlingClass[0].SetAge(18);
	cout<<"GrowlingClass after set\n:";
	ShowVector(GrowlingClass);

	return 0;
}

template <class T>
void
ShowVector(const vector<T>& v)
{
	cout<<"max_size() = " <<v.max_size();
	cout<<"\tsize() = " <<v.size();
	cout<<"\tcapacity() = " <<v.capacity();
	cout<<"\t" <<(v.empty()? "empty": "not empty");
	cout<<"\n";

	for(int i=0; i<v.size(); i++)
		cout<<v[i] <<"\n";
	cout<<endl;
}
