#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>


void
Prepare()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
}

const double RADIUS = 35;
const double PIXELS = 100;

int
main()
{
	double delta_v, x, y;
	double r=RADIUS, p=PIXELS;
	double i;

	Prepare();

	unsigned KeyboardStatus;

	for (double j=1; j<500; j+=0.009)
	{
		KeyboardStatus = *(unsigned far*)MK_FP( 0x40, 0x17 );

		for (i = 1; i<p; ++i)
		{ // Circle
			delta_v = (2 * M_PI * i / p) + j;
			x = 320 + r * cos(delta_v+j);
			y = 240 + r * sin(delta_v);
			putpixel(x, y, 15);
		}
		for (i = 1; i<5; ++i)
		{ // Triangle
			setcolor(GREEN);

			static int tX, tY;

			delta_v = (2 * M_PI * i / 3) - j;

			x = 320 + (r+50) * cos(delta_v-j);
			y = 240 + (r+50) * sin(delta_v);

			line(tX, tY, x, y);
			tX = x;
			tY = y;
		}
		for (i = 0; i<6; ++i)
		{ // Rectangle
			setcolor(LIGHTBLUE);

			static int tX, tY;

			delta_v = (2 * M_PI * i / 4) + j;

			x = 320 + (r+100) * cos(delta_v+j);
			y = 240 + (r+100) * sin(delta_v);

			line(tX, tY, x, y);
			tX = x;
			tY = y;
		}
		for (i = 0; i<6; ++i)
		{ // FIVEANGLE
			setcolor(LIGHTRED);

			static int tX, tY;

			delta_v = (2 * M_PI * i / 5) - j;

			x = 320 + (r+150) * cos(delta_v-j);
			y = 240 + (r+150) * sin(delta_v);

			line(tX, tY, x, y);
			tX = x;
			tY = y;
		}
		for (i = 0; i<6; ++i)
		{ // SIXANGLE
			setcolor(LIGHTGREEN);

			static int tX, tY;

			delta_v = (2 * M_PI * i / 6) + j;

			x = 320 + (r+200) * cos(delta_v+j);
			y = 240 + (r+200) * sin(delta_v);

			line(tX, tY, x, y);
			tX = x;
			tY = y;
		}
		if( KeyboardStatus & 0x0008)
		{
			return 0;
		}

		clearviewport();
	}

	cout << "Press any key." << endl;
	getch();
	getch();

	return 0;
}