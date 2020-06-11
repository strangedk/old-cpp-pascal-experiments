#include<iostream>
#include<string>

using namespace std;

template <class T>
void bubbleSort(T* item, int count)
{
	register int i, j;
	T tmp;

	for(i=1; i<count; i++)
		for(j=count-1; j>=i; j--)
		{
			if(item[j-1]>item[j])
			{
				tmp=item[j-1];
				item[j-1]=item[j];
				item[j]=tmp;
			}
		}
}

int
main()
{
	char str[]="qwertyuiopasdfghjklzxcvbnm";
	int IntArr[]={1,0,2,9,3,8,4,7,5,6};
	int acount=sizeof(IntArr)/sizeof(int);
	
	bubbleSort(str,(int)strlen(str));
	bubbleSort(IntArr, acount);
	cout<<"Sort String: " <<str <<endl;
	for(int i=0; i<acount; i++)
		cout<<IntArr[i] <<' ';
	cout<<endl;

	return 0;
}
