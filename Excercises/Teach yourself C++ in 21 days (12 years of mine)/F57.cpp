#include<iostream>

using namespace std;

const int DefaultSize = 3;

class Animal
{
public:
	Animal(int);
	Animal();
	~Animal();

	int GetWeight() const{ return m_Weight; }
	void SetWeight(int weight){ m_Weight = weight; }

	friend ostream& operator<< (ostream&, const Animal&);

private:
	int m_Weight;
};

ostream&
operator<< (ostream& theStream, const Animal& theAnimal)
{
	theStream<<theAnimal.GetWeight();
	return theStream;
}

Animal::Animal(int weight):
m_Weight(weight)
{
	// cout<<"Animal(int) ";
}

Animal::Animal():
m_Weight(0)
{
	// cout<<"Animal() ";
}

Animal::~Animal()
{
	// cout<<"Destroyed an animal... ";
}

template <class T>
class Array
{
public:
	Array(int size = DefaultSize);
	Array(const Array& rhs);
	~Array(){ delete[] pType; st_NumberArrays--; }

	Array& operator= (const Array&);
	T& operator[](int offset){ return pType[offset]; }
	const T& operator[](int offset) const{ return pType[offset]; }

	int GetSize() const{ return m_Size; }
	static int GetNumberArrays(){ return st_NumberArrays; }

	friend ostream& operator<< (ostream&, const Array<T>&);

private:
	T* pType;
	int m_Size;
	static int st_NumberArrays;
};

template <class T>
int Array<T>::st_NumberArrays = 0;

template <class T>
Array<T>::Array(int size = DefaultSize):
m_Size(size)
{
	pType = new T[size];
	for(int i=0; i<size; i++)
		pType[i] = (T)0;
	st_NumberArrays++;
}

template <class T>
Array<T>&
Array<T>::operator= (const Array &rhs)
{
	if(this == &rhs)
		return *this;
	delete[] pType;
	m_Size = rhs.GetSize();
	pType = new T[m_Size];

	for(int i=0; i<m_Size; i++)
		pType[i] = rhs[i];
}

template <class T>
Array<T>::Array(const Array& rhs)
{
	m_Size = rhs.GetSize();
	pType = new T[m_Size];

	for(int i=0; i<m_Size; i++)
		pType[i] = rhs[i];

	st_NumberArrays++;
}

template <class T>
ostream&
operator<< (ostream& output, const Array<T>& theArray)
{
	for(int i=0; i<theArray.GetSize(); i++)
		output<<"[" <<i <<"]" <<theArray[i] <<endl;
	return output;
}

int
main()
{
	cout<<Array<int>::GetNumberArrays() <<" integer arrays\n";
	cout<<Array<Animal>::GetNumberArrays() <<" animal arrays\n\n";

	Array<int> intArray;
	Array<Animal> animalArray;

	cout<<intArray.GetNumberArrays() <<" integer arrays\n";
	cout<<animalArray.GetNumberArrays() <<" animal arrays\n\n";

	Array<int> *pIntArray = new Array<int>;

	cout<<Array<int>::GetNumberArrays() <<" integer arrays\n";
	cout<<Array<Animal>::GetNumberArrays() <<" animal arrays\n\n";

	delete pIntArray;

	cout<<Array<int>::GetNumberArrays() <<" integer arrays\n";
	cout<<Array<Animal>::GetNumberArrays() <<" animal arrays\n\n";

	return 0;
}