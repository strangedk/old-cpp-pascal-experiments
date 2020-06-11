#include "Circle.h"

#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

void Prepare();
void Win();

const int RLuna = 55; // Radius of Luna

int Acc = 0; 	// number of pushing on border
int Goal = 0;	// number of "goals" in lunas

int x = 55;
int y = 55;

Circle sh(x,y,10);

int
main()
{
	int Up    = 0 ; // if 1 then move up
	int Down  = 1 ; // if 1 then move down
	int Left  = 0 ; // if 1 then move left
	int Right = 1 ; // if 1 then move right

	Prepare();

	while(Goal != 5) // if pushing on border = x: break
	{
		delay(5);

		if (
			(sh.GetX() < 35  && sh.GetY() < 35)  ||
			(sh.GetX() > 605 && sh.GetY() < 35)  ||
			(sh.GetX() < 35  && sh.GetY() > 445) ||
			(sh.GetX() > 605 && sh.GetY() > 445)
		   ) // then
		{
			Win();
		}


		if (sh.GetX() > 640)
		{
			Left  = 1;
			Right = 0;
			Acc++;
		}
		if (sh.GetX() < 0)
		{
			Left  = 0;
			Right = 1;
			Acc++;
		}
		if (sh.GetY() > 480)
		{
			Down  = 0;
			Up    = 1;
			Acc++;
		}
		if (sh.GetY() < 0)
		{
			Down  = 1;
			Up    = 0;
			Acc++;
		}

		if (Up    == 1)	y -= 2 ; // ghange for accelerate
		if (Down  == 1)	y += 2 ;
		if (Left  == 1)	x -= 2 ;
		if (Right == 1)	x += 2 ;

		setcolor(WHITE);
		sh.Move(x,y);

		setcolor(BROWN);
		rectangle(0,0,639,479);

		// Lunes
		setcolor(GREEN);
		circle(1,1,RLuna); 		//  left up
		circle(639,1,RLuna);	//  right up
		circle(1,479,RLuna);	//  left down
		circle(639,479,RLuna);	//  right down
	}
	return 0;
}

void
Prepare()
{
	int gm, gd = DETECT;

	initgraph(&gd, &gm, "d:\tc3\bin");
}

void
Win()
{
	Goal++;
	randomize();
	x = random(600);
	y = random(440);
	sh.Move(x, y);
	outtextxy(300,200,"Good !");
	delay(500);
	cleardevice();
}