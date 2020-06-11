#include<iostream>

using namespace std;

enum HorseClass { _horse, _pegasus };

class Horse
{
public:
	virtual void Gallop(){ cout<<"Galloping ...\n"; }
private:
	int m_age;
};

class Pegasus: public Horse
{
public:
	virtual void Fly(){ cout<<"I can Fly! I can Fly!\n"; }
};

const int NumHorse = 5;

int
main()
{
	Horse* Ranch[NumHorse];
	Horse* pHorse;

	int choice, i;

	for(i=0; i<NumHorse; i++)
	{
		cout<<"(1)Horse (2)Pegasus: ";
		cin>>choice;

		if(choice==2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}
	cout<<endl;
	for(i=0; i<NumHorse; i++)
	{
		Pegasus* pPeg = dynamic_cast<Pegasus*>(Ranch[i]);

		if(pPeg)
			pPeg->Fly();
		else
			cout<<"Just a horse\n";
		delete Ranch[i];
	}
	return 0;
}
