#include<iostream>
#include<fstream>

using namespace std;

class Animal
{
public:
	Animal(int weight, long days):
	m_Weight(weight),
	m_DayLive(days)
	{ }

	~Animal()
	{ }

	int GetWeight() const{ return m_Weight; }
	void SetWeight(int weight){ m_Weight = weight; }

	long GetDay() const{ return m_DayLive; }
	void SetDay(long days){ m_DayLive = days; }
private:
	int m_Weight;
	long m_DayLive;
};

int
main()
{
	char fName[80];

	cout<<"Please enter the file name: ";
	cin>>fName;

	ofstream fout(fName,ios::binary);
	if(!fout)
	{
		cout<<"Unable to open " <<fName <<" for writing.\n";
		return 1;
	}

	Animal Bear(50,100);

	fout.write((char*)&Bear, sizeof Bear);
	fout.close();

	ifstream fin(fName,ios::binary);
	if(!fin)
	{
		cout<<"Unable to open " <<fName <<" for reading.\n";
		return 1;
	}

	Animal Bear2(1,1);

	cout<<"Bear2 weight: " <<Bear2.GetWeight() <<endl;
	cout<<"Bear2 days: " <<Bear2.GetDay() <<endl;

	fin.read((char*)&Bear2, sizeof Bear2);
	fin.close();

	cout<<"Bear2 weight: " <<Bear2.GetWeight() <<endl;
	cout<<"Bear2 days: " <<Bear2.GetDay() <<endl;

	return 0;
}
