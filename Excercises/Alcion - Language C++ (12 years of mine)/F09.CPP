#include <iostream.h>
#include <conio.h>


inline void* operator new(size_t size, void* ptr)
{
	cout <<"Create Double object ...\n";
	return ptr;
};


void CheckSys()
{
	cout <<"Checking system ...\n";
};


class Coord{

	int x, y;
public:
	Coord(int _x, int _y){x=_x; y=_y; cout <<"Object initalizing\n"; }
	Coord(){x=0; y=0; cout <<"Object default initalizing\n"; }
	~Coord(){cout <<"Coord::~Coord()\n"; }
};


Coord Global;


main()
{
	clrscr();
	CheckSys();
	Coord* ptr=new(&Global) Coord(10, 20);
	ptr->Coord::~Coord();
	return 0;
};
