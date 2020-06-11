#include<iostream>

using namespace std;

void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);

int
main()
{
	int val1=1, val2=2;
	int choice, i;
	const int MaxArray = 5;
	void (*pFuncArr[MaxArray])(int&, int&);

	for(i=0; i<MaxArray; i++)
	{
		cout<<"(1)Change Values (2)Squalre (3)Cube (4)Swap: ";
		cin>>choice;

		switch(choice)
		{
		case 1: pFuncArr[i] = GetVals; break;
		case 2: pFuncArr[i] = Square; break;
		case 3: pFuncArr[i] = Cube; break;
		case 4: pFuncArr[i] = Swap; break;
		default: pFuncArr[i] = 0;
		}
	}

	for(i=0; i<MaxArray; i++)
	{
		if(pFuncArr[i]==0)
			continue;
		pFuncArr[i](val1, val2);
		PrintVals(val1, val2);
	}

	return 0;
}

void PrintVals(int x, int y)
{
	cout<<"x: " <<x <<"y: " <<y <<endl;
}

void Square(int& rX, int& rY)
{
	rX *= rX;
	rY *= rY;
}

void Cube(int& rX, int& rY)
{
	int temp;

	temp = rX;
	rX *= rX;
	rX *= temp;

	temp = rY;
	rY *= rY;
	rY *= temp;
}

void Swap(int& rX, int& rY)
{
	int temp = rX;
	rX = rY;
	rY = temp;
}

void GetVals(int& rVal1, int& rVal2)
{
	cout<<"New value of rVal1: ";
	cin>>rVal1;
	cout<<"New value of rVal2: ";
	cin>>rVal2;
}
