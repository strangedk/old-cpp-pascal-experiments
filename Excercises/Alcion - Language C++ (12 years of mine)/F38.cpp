#include<iostream>
#include<fstream>

using namespace std;

int
main()
{
	int n=50;

	ofstream ofs("Test.txt");
	if(!ofs)
	{
		cout <<"File is not open !";
		return 1;
	}
	ofs <<"Hello!\n" <<n;
	ofs.close();

	ifstream ifs("Test.txt");
	if(!ifs)
	{
		cout <<"File is not open !";
		return 2;
	}
	char str[80];
	ifs >>str >>n;
	cout <<str <<' ' <<n;
	ifs.close();

	return 0;
}
