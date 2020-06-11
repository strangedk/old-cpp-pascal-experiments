#include<iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle(int, int);
	~Rectangle(){ };

	void DrawShape() const;
	void DrawShape(int, int) const;
private:
	int m_width;
	int m_height;
};

Rectangle::Rectangle(int width, int height)
{
	m_width = width;
	m_height = height;
}

void
Rectangle::DrawShape() const
{
	DrawShape(m_width,m_height);
}

void
Rectangle::DrawShape(int width, int height) const
{
	for (int i=0; i<height; i++)
	{
		for (int j=0; j<width; j++)
			cout<<'*';
		cout<<endl;
	}
}

int
main()
{
	Rectangle Rect(40,12);

	cout<<"DrawShape(): \n";
	Rect.DrawShape();
	cout<<"\nDrawShape(30,4): \n";
	Rect.DrawShape(30,4);

	return 0;
}
