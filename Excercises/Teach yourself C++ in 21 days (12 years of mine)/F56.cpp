#include<iostream>

using namespace std;

const int DefaultSize = 10;

class Animal
{
public:
	Animal(int);
	Animal();
	~Animal();

	int GetWeight() const{ return m_Weight; }
	void SetWeight(int Weight){ m_Weight = Weight; }

	friend ostream& operator<< (ostream&, const Animal&);

private:
	int m_Weight;
};

ostream&
operator<< (ostream& Stream, const Animal& theAnimal)
{
	Stream<<theAnimal.GetWeight();
	return Stream;
}


Animal::Animal(int weight):
m_Weight(weight)
{
	cout<<"Animal(int)\n";
}

Animal::Animal():
m_Weight(0)
{
	cout<<"Animal()\n";
}

Animal::~Animal()
{
	cout<<"Destroyed an Animal ...\n";
}

template <class T>
class Array
{
public:
	Array(int size = DefaultSize);
	Array(const Array& rhs);
	~Array(){ delete[] pType; }

	Array& operator=(const Array&);
	T& operator[](int offset){ return pType[offset]; }
	const T& operator[](int offset) const{ return pType[offset]; }

	int GetSize() const{ return m_Size; }

	friend ostream& operator<< (ostream&, const Array<T>&);

private:
	T* pType;
	int m_Size;
};

template <class T>
Array<T>::Array(int size = DefaultSize):
m_Size(size)
{
	pType = new T[size];
	for(int i=0; i<size; i++)
		pType[i] = (T)0;
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

template <class T>
Array<T>::Array(const Array& rhs)
{
	m_Size = rhs.GetSize();
	pType = new T[m_Size];
	for(int i=0; i<m_Size; i++)
		pType[i] = rhs[i];
}

template <class T>
ostream&
operator<< (ostream& output, const Array<T>& theArray)
{
	for(int i=0; i<theArray.GetSize(); i++)
		output<<"[" <<i <<"]" <<theArray[i] <<endl;
	return output;
}

Array<Animal>::Array(int AnimalArraySize):
m_Size(AnimalArraySize)
{
	pType = new Animal[AnimalArraySize];
}

void IntFillFunction(Array<int>& theArray);
void AnimalFillFunction(Array<Animal>& theArray);

int
main()
{
	Array<int> intArray;
	Array<Animal> animalArray;

	IntFillFunction(intArray);
	AnimalFillFunction(animalArray);

	cout<<"intArray...\n" <<intArray;
	cout<<"\nAnimalArray...\n" <<animalArray <<endl;

	return 0;
}

void IntFillFunction(Array<int>& theArray)
{
	bool Stop = false;
	int offset, value;

	while(!Stop)
	{
		cout<<"Enter an offset (0-9) and a value. (-1 to stop): ";
		cin>>offset >>value;

		if(offset < 0)
			break;
		if(offset > 9)
		{
			cout<<"Use values between 0 and 9. \n";
			continue;
		}
		theArray[offset] = value;
	}
}

void AnimalFillFunction(Array<Animal>& theArray)
{
	Animal* pAnimal;
	
	for(int i=0; i<theArray.GetSize(); i++)
	{
		pAnimal = new Animal(i*10);
		theArray[i] = *pAnimal;
		delete pAnimal;
	}
}