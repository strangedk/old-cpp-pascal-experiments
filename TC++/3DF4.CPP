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

	setwritemode(XOR_PUT);

	for (double j=1; j<500; j+=0.005)
	{
		KeyboardStatus = *(unsigned far*)MK_FP( 0x40, 0x17 );

		for (i = 1; i<p+1; ++i)
		{ // Triangle

			delta_v = (2 * M_PI * i / p)+sin(j);

			x = 320 + (r+(j)) * cos(delta_v);
			y = 240 + (r+(j)) * sin(delta_v*3);

			putpixel(x,y,14);
		}
		setcolor(BLUE);
		for (i = 1; i<6; ++i)
		{
			delta_v = (2 * M_PI * i / 5)+j;

			x = 320 + (r+200) * cos(delta_v);
			y = 240 + (r+200) * sin(delta_v);

			line(320,240,x,y);
		}
		for (i = 1; i<6; ++i)
		{
			delta_v = (2 * M_PI * i / 5)+j;

			x = 320 + (r+200) * cos(delta_v);
			y = 240 + (r+200) * sin(delta_v);

			line(320,240,x,y);
		}


		if( KeyboardStatus & 0x0008)
		{
			return 0;
		}

//		clearviewport();
	}

	cout << "Press any key." << endl;
	getch();
	getch();

	return 0;
}