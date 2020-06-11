#include <iostream.h>
#include <string.h>
#include <conio.h>


class String
{
	union
	{
		char ch;
		char buf[80];
	};
public:
	String(char c='\0'): ch(c)
	 {cout <<"Symbol Constructor class String\n"; }
	String(char *s)
	 {cout <<"String Constructor class String\n"; strcpy(buf,s); }
	~String(){cout <<"String::~String();\n"; }

	void* operator new(size_t, void* buffer){return buffer; }
};

char str[sizeof(String)];

void
main()
{
	clrscr();
	String* ptr=new(str) String("c++");
	cout <<"str = " <<str <<'\n';
	ptr->String::~String();
	ptr=new(str) String('C');
	cout <<"str[0] = " <<str[0] <<'\n';
	cout <<"New buffer :\n";
	cout <<"str = " <<str <<'\n';
	ptr->String::~String();
};