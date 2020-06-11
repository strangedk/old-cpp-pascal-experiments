#include <iostream.h>
#include <conio.h>

/*

 Type transformation Function Example

*/

class Coord{

	int x, y;
public:
	Coord(int _x, int _y){x=_x; y=_y; }
	operator int(){return x*y; }
};


int
main()
{
	Coord OB(10,10);
	int n;

	clrscr();
	cout <<"int(OB) = " <<int(OB) <<endl;
	n=OB+10;
	cout <<"n = OB + 10 = " <<n;

	return 0;
};