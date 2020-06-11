#include <graphics.h>
#include <math.h>

const double MAX_R 	= 200;	// Max Radius
const double MIN_R 	= 1;	// Min Radius
const double FANGLE 	= 3;	// Forward Angle border
const double BANGLE 	= -3;	// Backward Angle border
const double POINTS	= 5;	// Points

void
Prepare() // Prepare Screen
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");

	randomize();
}

void
Rotate3D(double j) // Rotate Con
{
	double r = MIN_R;
	double p = POINTS;
	double delta_v, x, y;

	for (int i = 0; r<MAX_R; r += 0.02, ++i)
	{
		delta_v = (2 * M_PI * i / p) + sin(r/4);
		x = 320 + r * cos(delta_v);
		y = 240 + r * sin(delta_v);
		putpixel(x+(r*j), y+(r*j/4), 2);
	}
}

int
main()
{
	Prepare(); // Prepare Screen

	double i;

	// Rotate Right
	for (i=BANGLE; i<FANGLE; i += 0.02)
	{
		Rotate3D(i);
		cleardevice();
		// cleardevice function is very slow
		// replace it more quickly function
	}

	// Rotate Left
	for (i=FANGLE; i>BANGLE; i -= 0.02)
	{
		Rotate3D(i);
		cleardevice();
		// cleardevice function is very slow
		// replace it more quickly function
	}

	return 0;
}