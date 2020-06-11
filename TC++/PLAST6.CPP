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

const int PIX = 24;
const int RAD = 100;

int x, y;

int pixels = PIX;
int radius = RAD;

double i, j;
double delta;


///////////////////////////////////////////

int
main()
{
	Prepare();

	j = 0;

	while(!kbhit())
	{
		j += 0.03;

		setcolor(YELLOW);
		circle(320,240,10);
		circle(320,240,160);

		setcolor(LIGHTBLUE);
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels) + j;

			x = 320 + radius * sin(delta);
			y = 240 + radius * cos(delta+j);

			circle(x,y,(int)i%12);
		}
		setcolor(LIGHTGREEN);
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels) - j;

			x = 320 + (radius-30) * sin(delta);
			y = 240 + (radius-30) * cos(delta-j);

			circle(x,y,((int)i%12)/2);
		}
		setcolor(WHITE);
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels) + j;

			x = 320 + (radius-70) * sin(delta);
			y = 240 + (radius-70) * cos(delta+j);

			circle(x,y,((int)i%12)/3);
		}
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels) + j;

			x = 320 + (radius+50) * sin(delta);
			y = 240 + (radius+50) * cos(delta);

			putpixel(x,y,LIGHTRED);
		}
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels) - j;

			x = 320 + (radius+70) * sin(delta);
			y = 240 + (radius+70) * cos(delta);

			putpixel(x,y,LIGHTRED);
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