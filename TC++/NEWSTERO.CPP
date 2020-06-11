#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>


class CPoint
{
public:
  // 2D coordinates, a float so we can store fractional values
  float x, y;
};

class CShape
{
public:
  int	 NumPoints;	// Three is enough for now but will have to make
  CPoint Point[3];	// this more flexible later.
};

class CObject
{
public:
  CPoint Loc;           // Location on the screen
  int    ViewAngle;     // Angle at which the object is facing
  CPoint Direction;     // Direction which the object is moving, in pixels
  CShape Shape;         // The shape of the object
  CShape Screen;        // Actual points it occupies on the screen
};

class CPlayer
{
public:
  CObject Ship;		// The players spaceship

  CPlayer()
  {
	Ship.Shape.NumPoints = 3;

	Ship.Shape.Point[0].x =   0;
	Ship.Shape.Point[1].x =  -10;
	Ship.Shape.Point[2].x =  +10;

	Ship.Shape.Point[0].y =  -10;
	Ship.Shape.Point[1].y =  +10;
	Ship.Shape.Point[2].y =  +10;

	Ship.ViewAngle = 0;

	Ship.Loc.x = 320;
	Ship.Loc.y = 240;

	Ship.Direction.x = 0;
	Ship.Direction.y = 0;
  }

  ~CPlayer(){};

  void TranslatePoint(CPoint*,CPoint*, int);
  void TranslateObject(CObject*);
  void DrawObject(CObject*);
  void MoveObject(CObject*);
} Player;


// Translates a point by rotating it (using simple trig).

void
CPlayer::TranslatePoint(CPoint *Dest, CPoint *Src, int Angle)
{
	double Radians;

	Radians = Angle * 0.01745;
	Dest->x = Src->x * cos(Radians) - Src->y * sin(Radians);
	Dest->y = Src->x * sin(Radians) + Src->y * cos(Radians);
}

// Translates an object's relative coordinates to actual
// screen coordinates.

void
CPlayer::TranslateObject(CObject *Object)
{
	int i;
	for (i=0; i<Object->Shape.NumPoints; ++i)
	{
		// First, account for rotation
		TranslatePoint(&Object->Screen.Point[i],
			&Object->Shape.Point[i],
			Object->ViewAngle);

		// Now make it relative to the screen location
		Object->Screen.Point[i].x += Object->Loc.x;
		Object->Screen.Point[i].y += Object->Loc.y;
	}
}


// Goes through the list of points in an object
// and connects them all with lines.

void
CPlayer::DrawObject(CObject *Object)
{
	int i;

	for(i = 1; i<Object->Shape.NumPoints; ++i)
	{

	line(
	     Object->Screen.Point[ i-1 ].x,
	     Object->Screen.Point[ i-1 ].y,
	     Object->Screen.Point[ i   ].x,
	     Object->Screen.Point[ i   ].y
	    );
	}
	line(
	     Object->Screen.Point[ i-1 ].x,
	     Object->Screen.Point[ i-1 ].y,
	     Object->Screen.Point[ 0   ].x,
	     Object->Screen.Point[ 0   ].y
	    );
}


// Moves an object along its direction.

void
CPlayer::MoveObject(CObject *Object)
{
	Object->Loc.x += Object->Direction.x;
	Object->Loc.y += Object->Direction.y;

	// Handle screen wrap-around

	if( Object->Loc.x < 0 )    Object->Loc.x = 639;
	if( Object->Loc.x > 640 )  Object->Loc.x = 1;
	if( Object->Loc.y < 0 )    Object->Loc.y = 479;
	if( Object->Loc.y > 480 )  Object->Loc.y = 0;
}


// This routine just waits until the display is
// in a vertical retrace cycle.  This is useful
// for two things: to perform drawing during retrace
// when it can't be seen and (more importantly)
// to provide a method of synchronizing the animation
// with the game play so that it runs at a constant
// speed on virtually every machine.

void
SyncToVerticalRetrace()
{
	// If we happen to be in the middle of a vertical retrace
	// period wait until its over.

	while(inp(0x3da) & 8 );

	// Wait until we begin vertical retrace.

	while(!(inp(0x3da) & 8));
}

const double ROTATE_STEP = 6;	// Number of degrees to rotate
const double SPEED = 0.12;	// Speed control

void
Supervisor()
{
	unsigned short KeyboardStatus;

	int c = 0;

  while(c != 27)
  {
	// If a real keystroke is waiting get it

	if(kbhit()) c = getch();

	Player.TranslateObject(&Player.Ship);

	Player.DrawObject(&Player.Ship);   // Draw the ship

	// Get the keyboard status bits from the BIOS data area

	KeyboardStatus = *(unsigned short far *)MK_FP( 0x40, 0x17 );

	Player.MoveObject(&Player.Ship);

	if(KeyboardStatus & 0x0002)    // left shift, rotate left
	{
		Player.Ship.ViewAngle -= ROTATE_STEP;

		if(Player.Ship.ViewAngle<0)
			Player.Ship.ViewAngle = 360 - ROTATE_STEP;
	}
	if(KeyboardStatus & 0x0001)    // right shift, rotate right
	{
		Player.Ship.ViewAngle += ROTATE_STEP;
		if(Player.Ship.ViewAngle>359)
			Player.Ship.ViewAngle = 0 + ROTATE_STEP;
	}

	if( KeyboardStatus & 0x0008 )    // alt, thrust
	{
		double Radians;

		Radians = Player.Ship.ViewAngle * 0.01745;

		Player.Ship.Direction.x += sin(Radians) * SPEED;
		Player.Ship.Direction.y -= cos(Radians) * SPEED;
	}
	if( KeyboardStatus & 0x0004 )    // ctrl, brake
	{
		double Radians;

		Radians = Player.Ship.ViewAngle * 0.01745;

		if (Player.Ship.Direction.x > 1)
			Player.Ship.Direction.x -= sin(Radians) * SPEED;

		if (Player.Ship.Direction.y > 1)
			Player.Ship.Direction.y += cos(Radians) * SPEED;
	}

	SyncToVerticalRetrace(); // Pause until vertical retrace

	Player.DrawObject(&Player.Ship);    // Erase the ship
  }
}


// Initialization code.

void
Init()
{
	int GraphicsDriver;
	int GraphicsMode;

	detectgraph(&GraphicsDriver, &GraphicsMode);

	initgraph(&GraphicsDriver, &GraphicsMode, NULL);

	setwritemode(XOR_PUT);
}

int
main()
{
	Init();

	Supervisor();

	closegraph();

	return 0;
}
