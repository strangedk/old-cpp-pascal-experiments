#include<iostream>

using namespace std;

const int DefaultSize = 10;

class Animal
{
public:
	Animal(int);
	Animal();
	~Animal(){ }
	int GetWeight() const{ return m_Weight; }
	void Display() const{ cout<<m_Weight; }
private:
	int m_Weight;
};

Animal::Animal(int weight):
m_Weight(weight)
{ }

Animal::Animal():
m_Weight(0)
{ }

template <class T>
class Array
{
public:
	Array(int size = DefaultSize);
	Array(const Array& rhs);
	~Array(){ delete[] pType; }

	Array& operator=(const Array&);
	T& operator[](int offset){ return pType[offset]; }
	const T& operator[](int offset) const{ return m_Size; }

	int GetSize() const{ return m_Size; }

	friend ostream& operator<<(ostream&, Array<T>&);

private:
	T* pType;
	int m_Size;
};

template <class T>
ostream&
operator<<(ostream& output, Array<T>& theArray)
{
	for(int i=0; i<theArray.GetSize(); i++)
		output<<"[" <<i <<"]" <<theArray[i] <<endl;
	return output;
}

template <class T>
Array<T>::Array(int size):
m_Size(size)
{
	pType = new T[size];
	for(int i=0; i<size; i++)
		pType[i] = 0;
}

template <class T>
Array<T>::Array(const Array& rhs)
{
	m_Size = rhs.GetSize();
	pType = new T[m_Size];
	for(int i=0; i<m_Size; i++)
		pType[i] = rhs[i];
}

template <class T>
Array<T>&
Array<T>::operator=(const Array &rhs)
{
	if(this == &rhs)
		return *this;
	delete[] pType;
	m_Size = rhs.GetSize();
	pType = new T[m_Size];
	for(int i=0; i<m_Size; i++)
		pType[i] = rhs[i];
	return *this;
}

int
main()
{
	bool Stop = false;
	int offset, value;
	Array<int> theArray;

	while(!Stop)
	{
		cout<<"Enter an offset (0-9) ";
		cout<<"and a value. (-1 to stop): ";
		cin>>offset >>value;

		if(offset<0)
			break;
		if(offset>9)
		{
			cout<<"*** Please use values between 0 and 9 ***\n\a";
			continue;
		}
		theArray[offset] = value;
	}
	cout<<theArray <<endl;

	return 0;
}
