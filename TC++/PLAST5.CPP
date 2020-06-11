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
double tx1, ty1, tx2, ty2;

double j, delta;
double pixels = 6;
double radius = 50;
int i;
double k;
int c=2;

int arx1[6];
int ary1[6];
int arx2[6];
int ary2[6];

///////////////////////////////////////////

int
main()
{
	Prepare();

	j = 0;

//	setwritemode(1);

	while(!kbhit())
	{
		j = 0;
		k += 0.04;
////////////////////////////////////////////////////////////////////////////
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels)+k;

			tx1 = x1;
			ty1 = y1;

			x1 = 280 + radius * sin(delta*2);
			y1 = 180 + radius * cos(delta);

			line(tx1,ty1,x1,y1);

			arx1[i] = x1;
			ary1[i] = y1;
		}
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels)+k;

			tx2 = x2;
			ty2 = y2;

			x2 = 280 + radius * sin(delta*2);
			y2 = 260 + radius * cos(delta);

			line(tx2,ty2,x2,y2);

			arx2[i] = x2;
			ary2[i] = y2;
		}
		for(i = 0; i<pixels; ++i)
		{
			line(arx1[i],ary1[i],arx2[i],ary2[i]);
		}
////////////////////////////////////////////////////////////////////////////
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels)+k;

			tx1 = x1;
			ty1 = y1;

			x1 = 280 + radius * sin(delta*2);
			y1 = 180 + radius * cos(delta);

			line(640-tx1,ty1,640-x1,y1);

			arx1[i] = x1;
			ary1[i] = y1;
		}
		for(i = 0; i<pixels; ++i)
		{
			delta = (2 * M_PI * i / pixels)+k;

			tx2 = x2;
			ty2 = y2;

			x2 = 280 + radius * sin(delta*2);
			y2 = 260 + radius * cos(delta);

			line(640-tx2,ty2,640-x2,y2);

			arx2[i] = x2;
			ary2[i] = y2;
		}
		for(i = 0; i<pixels; ++i)
		{
			line(640-arx1[i],ary1[i],640-arx2[i],ary2[i]);
		}
////////////////////////////////////////////////////////////////////////////




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