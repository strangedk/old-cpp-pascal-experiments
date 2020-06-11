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

	ifstream fin(fileName);
	if(fin)
	{
		cout<<"Current file contents:\n";
		char ch;

		while(fin.get(ch))
			cout<<ch;

		cout<<"\nEnd of file\n";
	}
	
	fin.close();

	cout<<"\nOpening " <<fileName <<" in append mode...\n";

	ofstream fout(fileName,ios::app);
	if(!fout)
	{
		cout<<"Unable to open " <<fileName <<"for appending.\n";
		return 1;
	}

	cout<<"\nEnter text for the file: ";
	cin.ignore(1,'\n');
	cin.getline(buffer,320);
	fout<<buffer <<endl;
	fout.close();

	fin.open(fileName);
	if(!fin)
	{
		cout<<"Unable to open " <<fileName <<" for reading.\n";
		return 1;
	}

	cout<<"Here's the contents of the file:\n";
	char ch;

	while(fin.get(ch))
		cout<<ch;

	cout<<"\nEnd of File\n";

	fin.close();

	return 0;
}