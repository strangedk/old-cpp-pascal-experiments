#include <iostream.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>


class List{

	int Num;
public:
	List(){Head=Tail=Next=0; }
	virtual void Put(int n)=0;
	virtual bool Get(int &n)=0;
	void SetValue(int n){Num=n; }
	int GetValue(){return Num; }
	List *Head;
	List *Tail;
	List *Next;
};


class Queue: public List{

public:
	void Put(int n);
	bool Get(int &n);
};


void
Queue::Put(int n)
{
	List *Item;
	Item=new Queue;
	Item->SetValue(n);
	if(Tail)Tail->Next=Item;
	Tail=Item;
	Item->Next=NULL;
	if(!Head) Head=Tail;
};


bool
Queue::Get(int &n)
{
	List *Item;
	if (!Head){n=0; return false; }
	n=Head->GetValue();
	Item=Head;
	Head=Head->Next;
	delete Item;
	return true;
};


class Stack: public List{

public:
	void Put(int n);
	bool Get(int &n);
};


void
Stack::Put(int n)
{
	List *Item;
	Item=new Stack;
	Item->SetValue(n);
	if(Head) Item->Next=Head;
	Head=Item;
	if(!Tail) Tail=Head;
};


bool
Stack::Get(int &n)
{
	List *Item;
	if(!Head){n=0; return false; }
	n=Head->GetValue();
	Item=Head;
	Head=Head->Next;
	delete Item;
	return true;
};


int
main()
{
	List *Item;
	int saved;
	Queue QueOb;
	Stack StOb;
	char symbol;

	for (int i=0; i<10; i++)
	{
		cout <<"kuda pomestit znachenie? " <<"V ochered or stek(o/c): ";
		cin >>symbol;
		symbol=tolower(symbol);
		if(symbol=='o') Item=&QueOb;
		else if(symbol=='c') Item=&StOb;
		else break;
		Item->Put(i);
	}
	cout <<"Otkuda izvlech znachenie ?\n"
		 <<"Najmite <k>, chtob zavershit rabotu\n";
	for(;;)
	{
		cin >>symbol;
		symbol=tolower(symbol);
		if(symbol=='k') break;
		if(symbol=='o') Item=&QueOb;
		else if(symbol=='c') Item=&StOb;
		else break;
		if(Item->Get(saved))
		cout <<saved<<"\n";
		else
		cout <<"spisok pust\n";
	}

	return 0;
};