//----------------------------------------------

#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

//----------------------------------------------

void Prepare();
void Ornament(int, int, int, int, int);
void Draw(int, int, int);

//----------------------------------------------

const int HEIGHT = 50;
const int WIDTH = 50;

//----------------------------------------------

int
main()
{
	Prepare();

	Ornament(1, 1, 12, 9, GREEN);

	while(!kbhit());

	return 0;
}

//----------------------------------------------

void
Prepare()
{
	int gd=DETECT, gm=0;
	initgraph(&gd, &gm, "");
}

//----------------------------------------------

void
Ornament(int xStartup, int yStartup, int row, int col, int color)
{
	int RealRows = WIDTH * row;
	int RealCols = HEIGHT * col;

	for (int cols=1; cols<RealCols; cols += HEIGHT)
	{
		for(int rows=1; rows<RealRows; rows += WIDTH)
		{
			Draw(xStartup+rows,yStartup+cols,color);
		}

		for(rows=1; rows<RealRows; rows += WIDTH)
		{
			Draw(xStartup+rows+HEIGHT/2,yStartup+cols+HEIGHT/2,color);
		}
	}
}

//----------------------------------------------

void
Draw(int left, int top, int color)
{
	setcolor(color);

	// LEFT PART

	line(left, top+HEIGHT/2, left+WIDTH/8,
		top+(HEIGHT/2)-(HEIGHT/8));

	line(left+WIDTH/8, top+(HEIGHT/2)-(HEIGHT/8),
		left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8));

	line(left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8),
		left+WIDTH/2, top+HEIGHT/2);

	line(left+WIDTH/2, top+HEIGHT/2,
		left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8));

	line(left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8),
		left+WIDTH/8, top+(HEIGHT/2)+(HEIGHT/8));

	line(left+WIDTH/8, top+(HEIGHT/2)+(HEIGHT/8),
		left, top+HEIGHT/2);

	// TOP PART

	line(left+WIDTH/2, top+HEIGHT/2,
		left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8));

	line(left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8),
		left+(WIDTH/2)-(WIDTH/8), top+HEIGHT/8);

	line(left+(WIDTH/2)-(WIDTH/8), top+HEIGHT/8,
		left+WIDTH/2, top);

	line(left+WIDTH/2, top,
		left+(WIDTH/2)+(WIDTH/8), top+HEIGHT/8);

	line(left+(WIDTH/2)+(WIDTH/8), top+HEIGHT/8,
		left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8));

	line(left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8),
		left+WIDTH/2, top+HEIGHT/2);

	// RIGHT PART

	line(left+WIDTH/2, top+HEIGHT/2,
		left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8));

	line(left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)-(HEIGHT/8),
		left+WIDTH-WIDTH/8, top+(HEIGHT/2)-(HEIGHT/8));

	line(left+WIDTH-WIDTH/8, top+(HEIGHT/2)-(HEIGHT/8),
		left+WIDTH, top+HEIGHT/2);

	line(left+WIDTH, top+HEIGHT/2,
		left+WIDTH-WIDTH/8, top+(HEIGHT/2)+(HEIGHT/8));

	line(left+WIDTH-WIDTH/8, top+(HEIGHT/2)+(HEIGHT/8),
		left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8));

	line(left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8),
		left+WIDTH/2, top+HEIGHT/2);

	// BOTTOM PART

	line(left+WIDTH/2, top+HEIGHT/2,
		left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8));

	line(left+(WIDTH/2)+(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8),
		left+(WIDTH/2)+(WIDTH/8), top+HEIGHT-HEIGHT/8);

	line(left+(WIDTH/2)+(WIDTH/8), top+HEIGHT-HEIGHT/8,
		left+WIDTH/2, top+HEIGHT);

	line(left+WIDTH/2, top+HEIGHT,
		left+(WIDTH/2)-(WIDTH/8), top+HEIGHT-HEIGHT/8);

	line(left+(WIDTH/2)-(WIDTH/8), top+HEIGHT-HEIGHT/8,
		left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8));

	line(left+(WIDTH/2)-(WIDTH/8), top+(HEIGHT/2)+(HEIGHT/8),
		left+WIDTH/2, top+HEIGHT/2);
}

//----------------------------------------------