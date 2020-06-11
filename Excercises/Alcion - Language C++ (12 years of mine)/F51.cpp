#include<iostream>
#include<string>

using namespace std;

template <class T>
void qSort(T* item, int left, int right)
{
	register int i,j;
	T x,y;
	i=left;
	j=right;
	x=item[(left+right)/2];
	do
	{
		while(item[i]<x && i<right) i++;
		while(x<item[j] && j>left) j--;
		if(i<=j)
		{
			y=item[i];
			item[i]=item[j];
			item[j]=y;
			i++; j--;
		}
	}
	while(i<=j);
	if(left<j) qSort(item, left, j);
	if(i<right) qSort(item, i, right);
}

template <class T>
void quickSort(T* item, int count)
{
	qSort(item, 0, count-1);
}

int
main()
{
	char str[]="qwertyuiopasdfghjklzxcvbnm";
	quickSort(str,(int)strlen(str));

	int IntArr[]={1,0,2,9,3,8,4,7,5,6};
	int acount=sizeof(IntArr)/sizeof(int);
	quickSort(IntArr, acount);
	cout<<"Sorted string: " <<str <<endl;
	for(int i=0; i<acount; i++)
		cout<<IntArr[i] <<' ';
	cout<<endl;

	return 0;
}