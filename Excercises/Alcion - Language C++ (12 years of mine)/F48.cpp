#include<iostream>

using namespace std;

template <class T>
const T& max(const T& a, const T& b)
{
	return a>b ? a: b;
}

template <class T>
const T max(T* a, size_t size)
{
	T* tmp=a;

	for(int i=0; i<size; i++)
	{
		if(a[i]>*tmp)
			*tmp=a[i];
	}
	return *tmp;
}

int
main()
{
	int m=9, n=12;
	int arr[]={3,5,7,9};

	cout<<"max int = " <<max(m,n) <<endl;
	cout<<"max in arr = " <<max(arr,sizeof(arr)/sizeof(int)) <<endl;

	return 0;
}
