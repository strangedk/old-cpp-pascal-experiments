#include <iostream>

using namespace std;

void
Func(void* Pv)
{
	int i=reinterpret_cast<int>(Pv);
	cout<<"i=" <<i <<endl;
};

int
main()
{
	int n;
	char* str="String";

	n=reinterpret_cast<int>(str);
	str=reinterpret_cast<char*>(n);
	cout<<"str=" <<str <<endl;
	Func(reinterpret_cast<void*>(1024));
	typedef void (*PFV)();
	PFV pfunc=reinterpret_cast<PFV>(Func);
	pfunc();
	return 0;
};
