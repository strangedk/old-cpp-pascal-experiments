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
double pixels = 3;
double radius = 10;
int i;
double k;
int c=2;

///////////////////////////////////////////

int
main()
{
	Prepare();

	j = 0;

//	setwritemode(1);

	int tx=0, ty=0;

	while(!kbhit())
	{
		j = 0;
		k += 0.04;

		while(j < 200)
		{
			j += 15;

			for(i = 0; i<pixels; ++i)
			{
				delta = (2*M_PI*i/pixels) + k;

				x1 = 320 + (j) * sin(delta);
				y1 = 240 + (j) * cos(delta);

				x2 = 320 + (j+10) * sin(delta-sin(k));
				y2 = 240 + (j+10) * cos(delta);

				line(x1,y1,x2,y2);

				circle(x1,y1,5);
				circle(x2,y2,5);

				x1 = 320 + 180 * sin(delta+k);
				y1 = 240 + 180 * cos(delta+k);

				if ((int)k % 2)
				{
					circle(x1,y1,10);
				}
				else
				{
					rectangle(x1,y1,x1+20,y1+20);
				}
			}
			if (++c > 15) c = 0;
			setcolor(c);
		}
		STVR();

		// It's good, and quick, but part of the image is hidden
//		cleardevice();
		// It's good, all of the image showed, but is not quick
		clearviewport();

	}

	cout << "Press any key." << endl;

	getch();
	getch();


	return 0;
}

///////////////////////////////////////////