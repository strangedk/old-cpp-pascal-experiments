#include<iostream>

using namespace std;

template <class Te>
Te Sqr(Te x)
{
	return x*x;
}

template <class Te>
Te* Swap(Te* t, int ind1, int ind2)
{
	Te tmp=t[ind1];
	t[ind1]=t[ind2];
	t[ind2]=tmp;

	return t;
}

template <typename T1, typename T2>
void Display(T1 x, T2 y)
{
	cout.width(8);
	cout <<x <<' ';
	cout.width(8);
	cout <<y <<endl;
}

template <class Te, int offset>
void GetAddress(Te* obj, unsigned int *pAddr)
{
	*pAddr=(unsigned int)&obj[0] +offset*sizeof(Te);
}

int
main()
{
	int n=10, sq_n, i=2, j=5;
	double d=10.21, sq_d;
	char* str="Template";

	sq_n=Sqr(n);
	sq_d=Sqr(d);
	int Arr[100];
	unsigned int addr=0;

	cout<<"Value n = " <<n <<endl <<"Him square = " <<sq_n <<endl;
	cout<<"Value d = " <<d <<endl <<"Him square = " <<sq_d <<endl;
	cout<<"Initial string = '" <<str <<"'\n";
	cout<<"Modified string = '" <<Swap(str, i, j) <<"'\n";
	cout<<"Value her square\n";

	Display(n, d);
	Display(sq_n, sq_d);
	GetAddress<int,5>(Arr, &addr);
	
	cout<<"Address of Arr[5] = " <<hex <<showbase <<uppercase <<addr;

	return 0;
}
