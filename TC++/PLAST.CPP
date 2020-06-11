///////////////////////////////////////////

	#include <iostream.h>
	#include <graphics.h>
	#include <stdlib.h>
	#include <conio.h>
	#include <math.h>
	#include <dos.h>

///////////////////////////////////////////

void
STVR()
{
	// If we happen to be in the middle of a vertical retrace
	// period wait until its over.

	while(inp(0x3da) & 8 );

	// Wait until we begin vertical retrace.

	while(!(inp(0x3da) & 8));
}

///////////////////////////////////////////

void
Prepare()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	cleardevice();
}

///////////////////////////////////////////

double x, y;
double i, j;

///////////////////////////////////////////

int
main()
{
	Prepare();

	j = 0;

	int c=0;

	while(!kbhit())
	{
		j += 0.05;

		for(x = 1, i = 0; x<640; ++x, i += 0.01)
		{
			y = 340 + 100 * cos(tan(i)+j);

			if (i>3.195)
			{
				c = YELLOW;
			}
			else
			if (j>10)
			{
				c = j;
			}

			putpixel(x,y,c);
			putpixel(x,480-y,c);
		}
		STVR();
		clearviewport();
//		cleardevice();
	}

	cout << "Press any key." << endl;

	getch();
	getch();


	return 0;
}

///////////////////////////////////////////