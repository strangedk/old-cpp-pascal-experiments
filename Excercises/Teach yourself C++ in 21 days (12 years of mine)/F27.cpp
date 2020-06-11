#include<iostream>

using namespace std;

typedef int Hands;
enum Color { Red, Green, Blue, Yellow, White, Black, Brown };

class Horse
{
public:
	Horse(Color, Hands);
	virtual ~Horse(){ cout<<"Horse Destructor...\n"; }
	virtual void Whinny() const{ cout<<"Whinny!... "; }
	virtual Hands GetHeight() const{ return m_height; }
	virtual Color GetColor() const{ return m_color; }
private:
	Hands m_height;
	Color m_color;
};

Horse::Horse(Color color, Hands height):
m_color(color), m_height(height)
{
	cout<<"Horse Constructor...\n";
}

class Bird
{
public:
	Bird(Color, bool);
	virtual ~Bird(){ cout<<"Bird Destructor...\n"; }
	virtual void Chrip() const{ cout<<"Chrip... "; }
	virtual void Fly() const{ cout<<"I can Fly! I can Fly! I can Fly! "; }
	virtual Color GetColor() const{ return m_color; }
	virtual bool GetMigration() const{ return m_migration; }
private:
	Color m_color;
	bool m_migration;
};

Bird::Bird(Color color, bool migrates):
m_color(color), m_migration(migrates)
{
	cout<<"Bird Constructor...\n";
}

class Pegasus: public Horse, public Bird
{
public:
	void Chirp() const{ Whinny(); }
	Pegasus(Color, Hands, bool, long);
	~Pegasus(){ cout<<"Pegasus destructor...\n"; }
	virtual long GetNumBel() const{ return m_numBelievers; }
private:
	long m_numBelievers;
};

Pegasus::Pegasus(Color aColor, Hands height, bool migrates, long numBelieve):
Horse(aColor, height),
Bird(aColor, migrates),
m_numBelievers(numBelieve)
{
	cout<<"Pegasus Constructor...\n";
}

int
main()
{
	Pegasus* pPeg = new Pegasus(Red, 5, true, 10);

	pPeg->Fly();
	pPeg->Whinny();
	cout<<"\nYour Pegasus is " <<pPeg->GetHeight() <<" hands tall and ";
	if(pPeg->GetMigration())
		cout<<"it does migrate. ";
	else
		cout<<"it does not migrate. ";
	cout<<"\nA total of " <<pPeg->GetNumBel() <<" people believe it exists.\n";

	delete pPeg;
	return 0;
}