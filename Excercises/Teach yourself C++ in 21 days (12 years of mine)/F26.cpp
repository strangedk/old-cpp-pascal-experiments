#include<iostream>

using namespace std;

class Horse
{
public:
	Horse(){ cout<<"Horse constructor . "; }
	virtual ~Horse(){ cout<<"Horse Destructor . "; }
	virtual void Whinny() const{ cout<<"Whinny . "; }
private:
	int m_age;
};

class Bird
{
public:
	Bird(){ cout<<"Bird Constructor . "; }
	virtual ~Bird(){ cout<<"Bird Destructor . "; }
	virtual void Chirp() const{ cout<<"Chirp . "; }
	virtual void Fly() const{ cout<<"I can Fly! I can Fly!\n"; }
private:
	int m_weight;
};

class Pegasus: public Horse, public Bird
{
public:
	void Chirp() const{ Whinny(); }
	Pegasus(){ cout<<"Pegasus Constructor . "; }
	~Pegasus(){ cout<<"Pegasus Destructor . "; }
};

const int MagicNumber = 2;

int
main()
{
	Horse* Ranch[MagicNumber];
	Bird* Aviary[MagicNumber];
	Horse* pHorse;
	Bird* pBird;
	int choice, i;

	for(i=0; i<MagicNumber; i++)
	{
		cout<<"\n(1)Horse (2)Pegasus: ";
		cin>>choice;
		if(choice==2)
			pHorse = new Pegasus;
		else
			pHorse = new Horse;
		Ranch[i] = pHorse;
	}
	for(i=0; i<MagicNumber; i++)
	{
		cout<<"\n(1)Bird (2)Pegasus: ";
		cin>>choice;
		if(choice==2)
			pBird = new Pegasus;
		else
			pBird = new Bird;
		Aviary[i] = pBird;
	}
	cout<<endl;
	for(i=0; i<MagicNumber; i++)
	{
		cout<<"\nRanch[" <<i <<"]: \n\t";
		Ranch[i]->Whinny();
		delete Ranch[i];
	}
	for(i=0; i<MagicNumber; i++)
	{
		cout<<"\nAviary[" <<i <<"]: \n\t";
		Aviary[i]->Chirp();
		Aviary[i]->Fly();
		delete Aviary[i];
	}
	cout<<"\n\n";
	return 0;
}
