#include<iostream>
#include<fstream>

using namespace std;

int
main(int argc, char* argv[])
{
	char c;
	if(argc>1)
	{
		fstream ifs(argv[1]);
		if(!ifs)
		{
			cout <<"File is not open";
			return 1;
		}
		while(!ifs.eof());
		{
			ifs.get(c);
			if(ifs.fail())
			{
				cout <<"Error!";
				break;
			}
			cout <<c;
		}
		ifs.close();
	}
	return 0;
}
