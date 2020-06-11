#include <iostream.h>
#include <string>

void
Func(const char* s)
{
	char* str;
	str=const_cast<char*>(s);
	strcpy(str,"And it - other line.");
};

int
main()
{
	char* source="It - inital string.";

	cout<<"Before Func() call source = " <<source <<endl;
	Func(source);
	cout<<"After Func() call souce = " <<source <<endl;

	return 0;
};