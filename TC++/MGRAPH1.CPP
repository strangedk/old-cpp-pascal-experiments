#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

class Shape
{
public:
	Shape();
	Shape(int, int, int, int);
   ~Shape(){	};

	void Draw();
	void Move(int, int);

	void SetRadius(int R){ m_Radius = R; }
	void SetColor(int c){ m_Color = c; }
	void SetX(int cX) { m_x = cX; }
	void SetY(int cY) { m_y = cY; }

	int GetRadius() const{ return m_Radius; }
	int GetColor() const{ return m_Color; }
	int GetX() const { return m_x; }
	int GetY() const { return m_x; }
private:
	int m_Radius;
	int m_Color;
	int m_x, m_y;
};

// Constructors

Shape::Shape():
m_x(320),
m_y(240),
m_Radius(15),
m_Color(WHITE)
{
}

Shape::Shape(int x, int y, int R, int c):
m_x(x),
m_y(y),
m_Radius(R),
m_Color(c)
{
}

// end of constructors

void
Shape::Draw()
{
	setcolor(m_Color);
	circle(m_x, m_y, m_Radius);
}

void
Shape::Move(int x, int y)
{
	setcolor(BLACK);
	circle(m_x, m_y, m_Radius);

	setcolor(m_Color);

	SetX(x);
	SetY(y);

	circle(m_x, m_y, m_Radius);
}

int
main()
{
	{ // initialize graphics mode

		int gd = DETECT, gm;
		initgraph(&gd, &gm, "");
	}

	Shape sh1, sh2;

	sh1.SetColor(GREEN);
	sh2.SetColor(YELLOW);

	for (int i=0, j=460; i<420; i++, j--)
	{
		delay(60);
		sh1.Move(i,i);
		sh2.Move(j,j);
	}

	getch();

	return 0;
}