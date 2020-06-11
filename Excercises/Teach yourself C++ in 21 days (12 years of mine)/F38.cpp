#include "String.hpp"

using namespace std;

class Employee
{
public:
	Employee();
	Employee(char * , char * , char * , long);
	~Employee();
	Employee(const Employee&);
	Employee& operator=(const Employee&);

	const String& GetFirstName() const
	{
		return m_FirstName; 
	}
	const String& GetLastName() const
	{
		return m_LastName;
	}
	const String& GetAddress() const
	{
		return m_Address;
	}
	const long GetSalary() const
	{
		return m_Salary;
	}
	
	void SetFirstName(const String& fName)
	{
		m_FirstName = fName;
	}
	void SetLastName(const String& lName)
	{
		m_LastName = lName;
	}
	void SetAddress(const String& address)
	{
		m_Address = address;
	}
	void SetSalary(long salary)
	{
		m_Salary = salary;
	}
private:
	String m_FirstName;
	String m_LastName;
	String m_Address;
	long m_Salary;
};

Employee::Employee():
m_FirstName(""),
m_LastName(""),
m_Address(""),
m_Salary(0)
{
}

Employee::Employee(
				   char* FirstName, char* LastName,
				   char* Address, long Salary
				   ):
m_FirstName(FirstName),
m_LastName(LastName),
m_Address(Address),
m_Salary(Salary)
{
}

Employee::Employee(const Employee& rhs):
m_FirstName(rhs.GetFirstName()),
m_LastName(rhs.GetLastName()),
m_Address(rhs.GetAddress()),
m_Salary(rhs.GetSalary())
{
}

Employee::~Employee()
{
}

Employee&
Employee::operator=(const Employee& rhs)
{
	if(this == &rhs)
		return *this;
	m_FirstName = rhs.GetFirstName();
	m_LastName = rhs.GetLastName();
	m_Address = rhs.GetAddress();
	m_Salary = rhs.GetSalary();

	return *this;
}

int
main()
{
	Employee Edie("Jane", "Doe", "1461 Shore Parkway", 20000);

	Edie.SetSalary(50000);
	String LastName("Levine");
	Edie.SetLastName(LastName);
	Edie.SetFirstName("Edythe");

	cout<<"Name: "
		<<Edie.GetFirstName().GetString()
		<<" "
		<<Edie.GetLastName().GetString()
		<<"\nAddress: "
		<<Edie.GetSalary();

	return 0;
}
