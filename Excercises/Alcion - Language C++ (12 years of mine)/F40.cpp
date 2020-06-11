#include<iostream>

using namespace std;
using std::cout;

int
main()
{
	char ch;
	cout <<"Input number, for terminate program press <ENTER>: ";
	while(cin.get(ch))
	{
		if(ch=='\n')
			break;
	}
	return 0;
}

