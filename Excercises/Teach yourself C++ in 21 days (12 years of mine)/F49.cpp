#include<fstream>
#include<iostream>

using namespace std;

int
main()
{
	char fileName[80];
	char buffer[320];

	cout<<"File name: ";
	cin>>fileName;

	ofstream fout(fileName);
	
	fout<<"This line written dirrectly to the file...\n";
	cout<<"Enter text for the file: ";
	cin.ignore(1,'\n');
	cin.getline(buffer,320);
	
	fout<<buffer <<endl;
	fout.close();

	ifstream fin(fileName);

	cout<<"Here's the contents of the file:\n";
	char ch;

	while(fin.get(ch))
		cout<<ch;

	cout<<"\nEnd of File\n";

	fin.close();

	return 0;
}