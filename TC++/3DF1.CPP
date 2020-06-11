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
	double r=1, p=2;
	double i;

	Prepare();

	unsigned KeyboardStatus;

	for (double j=1; j<500; j+=0.005)
	{
		KeyboardStatus = *(unsigned far*)MK_FP( 0x40, 0x17 );

		r = 1;

		for (i = 1; r<140; r += 0.1, ++i)
		{
			delta_v = (2 * M_PI * i / p) + sin(r/24);

//			x = 320 + r * cos(delta_v-j*r+j);
//			y = 240 + r * sin(delta_v+j*r+j*2);

//			x = 320 + r * cos(delta_v-j*r+j);
//			y = 240 + r * sin(delta_v+j*r+j);

			x = 320 + r * cos(delta_v+r/r-r);
			y = 240 + r * sin(delta_v+j*j+r);


			putpixel(x, y, 14);
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