#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <mouse.c>

/*
	int  mouse_reset(void);
	void mouse_enable(void);
	void mouse_disable(void);
	void mouse_read_cursor(void);
	void mouse_horizontal_range(int xmin, int xmax);
	void mouse_vertical_range(int ymin, int ymax);
*/

int
main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);

	mouse_enable();

	mouse_horizontal_range(10,320);
	mouse_vertical_range(10,470);

	rectangle(1,1,639,479);
	line(318,0,318,480);
	line(320,0,320,480);
	line(322,0,322,480);

	while(!kbhit())
	{
		mouse_read_cursor();

		if (mouse_status == 1)
		{
			putpixel(mouse_x-5, mouse_y-5, 14);
			putpixel(640-mouse_x+5, mouse_y-5, 14);
		}

		mouse_read_cursor();
	}
	mouse_reset();

	return 0;
}