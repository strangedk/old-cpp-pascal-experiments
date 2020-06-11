#include<iostream>

using namespace std;

enum { klsSmaller, klsLarger, klsSame };

class Data
{
public:
	Data(int val): m_value(val){ }
	~Data(){ }

	int Compare(const Data&);
	void Show(){ cout<<m_value <<endl; }
protected:
	int m_value;
};

int
Data::Compare(const Data& theOthDat)
{
	if(m_value<theOthDat.m_value)
		return klsSmaller;
	if(m_value>theOthDat.m_value)
		return klsLarger;
	else
		return klsSame;
}

class Node;
class HeadNode;
class TailNode;
class InternalNode;

class Node
{
public:
	Node(){ }
	virtual ~Node(){ }
	virtual Node* Insert(Data* theData) =0;
	virtual void Show() =0;
};

class InternalNode: public Node
{
public:
	InternalNode(Data* theData, Node* next);
	~InternalNode(){ delete m_next; delete m_data; }

	virtual Node* Insert(Data* hteData);
	virtual void Show(){ m_data->Show(); m_next->Show(); }
protected:
	Data* m_data;
	Node* m_next;
};

InternalNode::InternalNode(Data* theData, Node* next):
m_data(theData), m_next(next)
{ }

Node* InternalNode::Insert(Data* theData)
{
	int result = m_data->Compare(*theData);

	switch(result)
	{
	case klsSame:
	case klsLarger:
		{
			InternalNode* dataNode = new InternalNode(theData, this);
			return dataNode;
		}
	case klsSmaller:
		m_next->Insert(theData);
		return this;
	}
	return this;
}

class TailNode: public Node
{
public:
	TailNode(){ }
	~TailNode(){ }
	virtual Node* Insert(Data* theData);
	virtual void Show(){ }
};

Node* TailNode::Insert(Data* theData)
{
	InternalNode* dataNode = new InternalNode(theData, this);
	return dataNode;
}

class HeadNode: public Node
{
public:
	HeadNode();
	~HeadNode(){ delete m_next; }
	virtual Node* Insert(Data* theData);
	virtual void Show(){ m_next->Show(); }
protected:
	Node* m_next;
};

HeadNode::HeadNode()
{
	m_next = new TailNode;
}

Node* HeadNode::Insert(Data* theData)
{
	m_next = m_next->Insert(theData);
	return this;
}

class LinkedList
{
public:
	LinkedList();
	~LinkedList(){ delete m_head; }

	void Insert(Data* theData);
	void ShowAll(){ m_head->Show(); }
protected:
	HeadNode* m_head;
};

LinkedList::LinkedList()
{
	m_head = new HeadNode;
}

void LinkedList::Insert(Data* pData)
{
	m_head->Insert(pData);
}

int
main()
{
	Data* pData;
	int val;
	LinkedList ll;

	for(;;)
	{
		cout<<"What Value? (0 to stop): ";
		cin>>val;
		if(!val)
			break;
		pData = new Data(val);
		ll.Insert(pData);
	}
	ll.ShowAll();

	return 0;
}

