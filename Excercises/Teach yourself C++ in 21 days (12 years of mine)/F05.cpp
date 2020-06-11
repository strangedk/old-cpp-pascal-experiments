#include<iostream>

using namespace std;

// class Rectangle
class Rectangle
{
public:
	// Constructors 
	Rectangle(int, int);
	~Rectangle(){ }

	// Member Functions
	void DrawShape(int width, int height, bool UseCur = false) const;
private:
	// Member Variables
	int m_width;
	int m_height;
};
// End of Rectangle class

Rectangle::Rectangle(int width, int height):

m_width(width), m_height(height) // Initalization
{ } // Empty body of constructor

void // The third parameter is default = false
Rectangle::DrawShape(int width, int height, bool UseCur) const
{
	int PrintWidth;
	int PrintHeight;

	if (UseCur == true) //  if not default (true)
	{
		PrintWidth = m_width; // Use old values (object), ignore arguments
		PrintHeight = m_height;
	}
	else // if default (false)
	{
		PrintWidth = width; // Use new values (arguments)
		PrintHeight = height;
	}

	for (int i=0; i<PrintHeight; i++) // New line cycle
	{
		for (int j=0; j<PrintWidth; j++) // New symbol cycle
			cout<<"*";
		cout<<endl; // new line, and cycle repeat
	}
}

int
main()
{
	Rectangle Rect(30,5); // new object of Rectangle class (Rect)

	cout<<"DrawShape(0,0,true)...\n";
	Rect.DrawShape(0,0,true); // not use parameters
	cout<<"DrawShape(40,3)...\n";
	Rect.DrawShape(40,3); // use parameters (third is default (false))

	return 0;
}