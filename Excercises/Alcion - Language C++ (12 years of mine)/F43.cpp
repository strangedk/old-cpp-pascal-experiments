#include<iostream>
#include<fstream>

using namespace std;

int
main(int argc, char* argv[])
{
	int size=0;
	if(argc>1)
	{
		const char* FileName=argv[1];
		ifstream file;
		file.open(FileName, ios::in | ios::binary);

		if(file)
		{
			file.seekg(0,ios::end);
			size=file.tellg();
			if(size<0)
			{
				cerr <<FileName <<" is not found!";
			}
			cout <<FileName <<"size = " <<size;
		}
	}
	else cout <<"You is not select file. ";

	return 0;
}
