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

int
main()
{
	double delta_v, x, y;
	double r=1, p=1;
	double i;

	Prepare();

	unsigned KeyboardStatus;

	for (double j=1; j<500; j+=0.005)
	{
		KeyboardStatus = *(unsigned far*)MK_FP( 0x40, 0x17 );

		r = 1;

		setcolor(LIGHTGREEN);
		circle(320,240,2);
		circle(320,240,4);
		circle(320,240,6);

		for (i = 1; r<140; r += 0.1, ++i)
		{
			delta_v = (2 * M_PI * i / p) + sin(r/24);

			x = 320 + r * cos(delta_v+(r*sin(j)));
			y = 240 + r * sin(delta_v+(j*sin(j)));

			putpixel(x, y, LIGHTRED);
			putpixel(x, 480-y, LIGHTRED);

			x = 320 + r * cos(delta_v+(r*sin(j)));
			y = 240 + r * sin(delta_v+(r*sin(j)));
			putpixel(x, y, LIGHTBLUE);
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