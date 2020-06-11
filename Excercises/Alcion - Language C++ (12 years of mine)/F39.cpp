#include<iostream>
#include<fstream>

using namespace std;

int
main()
{
	int x=255;
	char str[80]="Testing binary input-output.";

	ofstream ofs("Test.dat");
	if(!ofs)
	{
		cout <<"File is not open!";
		return 1;
	}
	ofs.write((char*)&x, sizeof(int));
	ofs.write((char*)&str, sizeof(str));

	ifstream ifs("Test.dat");
	if(!ifs)
	{
		cout <<"File is not open!";
		return 1;
	}
	ifs.read((char*)&x, sizeof(int));
	ifs.read((char*)&str, sizeof(str));
	cout <<x <<'\n' <<str <<'\n';
	
	return 0;
}
