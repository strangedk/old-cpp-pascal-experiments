//////////// Machine Graphic by Michael //////////////////////////////////

#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>


/////////// ADT class Shape //////////////////////////////////////////////

class Shape
{
public:
// Constructors
	Shape();
	Shape(int, int, int);
	virtual ~Shape(){ };

	virtual void Draw() =0;
//	virtual void Move(int, int) =0;

	void SetColor(int c) { m_Color = c; }
	void SetX(int cX) { m_x = cX; }
	void SetY(int cY) { m_y = cY; }

	int GetColor() const { return m_Color; }
	int GetX() const { return m_x; }
	int GetY() const { return m_y; }
protected:
	int m_Color;
	int m_x, m_y;
};

///////// Shape functions ////////////////

Shape::Shape():
m_x(320),
m_y(240),
m_Color(WHITE)
{ }

Shape::Shape(int x, int y, int c):
m_x(x),
m_y(y),
m_Color(c)
{ }


/////////// class Circle, derived from Shape /////////////////////////////

class Circle: public Shape
{
public:
// Constructors
	Circle();
	Circle(int, int, int, int);
	virtual ~Circle() { }

	virtual void Draw();
	virtual void Move(int, int);

	void SetRadius(int R){ m_Radius = R; }
	int GetRadius() const{ return m_Radius; }
private:
	int m_Radius;
};

///////// Circle functions ///////////////

Circle::Circle():
Shape(),
m_Radius(15)
{ }

Circle::Circle(int x, int y, int r, int c):
Shape(x, y, c),
m_Radius(r)
{ }

void
Circle::Draw()
{
	setcolor(m_Color);
	circle(m_x, m_y, m_Radius);
}

void
Circle::Move(int x, int y)
{
	setcolor(BLACK);
	circle(m_x, m_y, m_Radius);

	setcolor(m_Color);

	SetX(x);
	SetY(y);

	circle(m_x, m_y, m_Radius);
}


/////////// class Rect, derived from Shape ///////////////////////////////

class Rect: public Shape
{
public:
// Constructors
	Rect();
	Rect(int, int, int, int, int);
	virtual ~Rect() { }

	virtual void Draw();
	virtual void Move(int, int, int, int);

	void SetX2(int x2) { m_x2 = x2; }
	void SetY2(int y2) { m_y2 = y2; }

	int GetX2() const { return m_x2; }
	int GetY2() const { return m_y2; }

private:
	int m_x2, m_y2; // m_x(1) and m_y(1) defined in ADT class Shape

};
/////////  Rect functions  /////////////////

Rect::Rect():
Shape(),
m_x2(m_x + 35),
m_y2(m_y + 30)
{ }

Rect::Rect(int x1, int y1, int x2, int y2, int col):
Shape(x1, y1, col),
m_x2(x2),
m_y2(y2)
{ }

void
Rect::Draw()
{
	setcolor(m_Color);
	rectangle(m_x, m_y, m_x2, m_y2);
}

void
Rect::Move(int x1, int y1, int x2, int y2)
{
	setcolor(BLACK);
	rectangle(m_x, m_y, m_x2, m_y2);

	setcolor(m_Color);

	SetX(x1);
	SetY(y1);

	SetX2(x2);
	SetY2(y2);

	rectangle(m_x, m_y, m_x2, m_y2);
}


//     Main  function

int
main()
{
	// initialize graphics mode

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");

	Circle* cr1 = new Circle;
	Circle* cr2 = new Circle;
	Rect* rc1 = new Rect;
	Rect* rc2 = new Rect;
	Rect* P = new Rect(1, 1, 460, 460, WHITE);

	cr1->SetColor(GREEN);
	cr2->SetColor(YELLOW);
	rc1->SetColor(BLUE);
	rc2->SetColor(RED);

	P->Draw();
	delete P;

	for (int i=0, j=460; i<=440; i++, j--)
	{

		cr1->Move(i, 230);
		cr2->Move(j, 230);

		cr2->SetColor(random(256));

		if (i>200 && i<250)
			delay(150);
		else
			delay(32);

		rc1->Move(225, i-20, 235, i+20);
		rc2->Move(225, j-20, 235, j+20);

	}

	delete rc2;
	delete rc1;
	delete cr2;
	delete cr1;

	getch();

	return 0;
}

/***************************  Happy End !  ***************************/