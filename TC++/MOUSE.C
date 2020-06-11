#include <dos.h>

//----------------------------------------------------------------------//

int mouse_status;
int mouse_x;
int mouse_y;

//----------------------------------------------------------------------//

int  mouse_reset();
void mouse_enable();
void mouse_disable();
void mouse_read_cursor();
void mouse_horizontal_range(int, int);
void mouse_vertical_range(int, int);

//----------------------------------------------------------------------//

int
mouse_reset()
{
   _AX=0;
   geninterrupt(0x33);
   return(_AX);
}

//----------------------------------------------------------------------//

void
mouse_enable()
{
   _AX=1;
   geninterrupt(0x33);
}

//----------------------------------------------------------------------//

void
mouse_disable()
{
   _AX=2;
   geninterrupt(0x33);
}

//----------------------------------------------------------------------//

void
mouse_read_cursor()
{
   _AX=3;
   geninterrupt(0x33);
   mouse_status=_BX;
   mouse_x=_CX;
   mouse_y=_DX;
}

//----------------------------------------------------------------------//

void
mouse_horizontal_range(int xmin, int xmax)
{
   _AX=7;
   _CX=xmin;
   _DX=xmax;
   geninterrupt(0x33);
}

//----------------------------------------------------------------------//

void
mouse_vertical_range(int ymin, int ymax)
{
   _AX=8;
   _CX=ymin;
   _DX=ymax;
   geninterrupt(0x33);
}

//----------------------------------------------------------------------//