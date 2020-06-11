
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

	while(inp(0x3da) & 8);

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

double x1, y1, x2, y2;
double j, delta;
double pixels = 1;
double radius = 10;
int i;
double k;
int c=0;

///////////////////////////////////////////

int
main()
{
	Prepare();

	j = 0;

//	setwritemode(1);

	while(!kbhit())
	{
		k += 0.04;
		pixels += 0.005;

		j = 0;
		while(j < 200)
		{
			j += 15;
			for(i = 0; i<pixels; ++i)
			{
				delta = (2*M_PI*i/pixels) + k;

				x1 = 320 + (j) * sin(delta);
				y1 = 240 + (j) * cos(delta);

				x2 = 320 + (j+10) * sin(delta);
				y2 = 240 + (j+10) * cos(delta);

				line(x1,y1,x2,y2);
			}
			if (++c > 15) c = 0;
			setcolor(c);
		}
		STVR();
//		cleardevice();
		clearviewport();
		setcolor(GREEN);
		circle(320,240,220);
	}

	cout << "Press any key." << endl;

	getch();
	getch();


	return 0;
}

///////////////////////////////////////////