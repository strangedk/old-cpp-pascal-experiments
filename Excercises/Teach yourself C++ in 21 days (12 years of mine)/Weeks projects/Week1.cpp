#include<iostream>

using namespace std;

enum CHOICE{DrawRect=1, GetArea, GetPerim, GhangeDimensions, Quit};

class Rectangle
{
	int itsWidth;
	int itsHeight;
public:
	Rectangle(int width, int height);
	~Rectangle(){};

	int GetHeight() const {return itsHeight; }
	int GetWidth() const {return itsWidth; }
	int GetArea() const {return itsHeight*itsWidth; }
	int GetPerim() const {return 2*itsHeight+2*itsWidth; }
	void SetSize(int newWidth, int newHeight);
};

Rectangle::Rectangle(int width, int height)
{
	itsWidth=width;
	itsHeight=height;
}

void
Rectangle::SetSize(int newWidth, int newHeight)
{
	itsWidth=newWidth;
	itsHeight=newHeight;
}

int DoMenu();
void DoDrawRect(Rectangle);
void DoGetArea(Rectangle);
void DoGetPerim(Rectangle);

int
main()
{
	Rectangle theRect(30, 5);

	int choice=DrawRect;
	int fQuit=false;

	while(!fQuit)
	{
		choice=DoMenu();
		if(choice<DrawRect || choice>Quit)
		{
			cout<<"\n Invalid choice, please try again.\n\n";
			break;
		}
		switch(choice)
		{
		case DrawRect:
			DoDrawRect(theRect);
			break;
		case GetArea:
			DoGetArea(theRect);
			break;
		case GetPerim:
			DoGetPerim(theRect);
			break;
		case GhangeDimensions:
			int newLength, newWidth;
			cout<<"\nNew width: ";
			cin>>newWidth;
			cout<<"New height: ";
			cin>>newLength;
			theRect.SetSize(newWidth, newLength);
			DoDrawRect(theRect);
			break;
		case Quit:
			fQuit=true;
			cout<<"\nExiting...\n\n";
			break;
		default:
			cout<<"Error in choice!\n";
			fQuit=true;
			break;
		}
	}

	return 0;
}

int DoMenu()
{
	int choice;

	cout<<"\n\n  *** Menu *** \n";
	cout<<"(1) Draw Rectangle\n";
	cout<<"(2) Area\n";
	cout<<"(3) Perimeter\n";
	cout<<"(4) Resize\n";
	cout<<"(5) Quit\n";

	cin>>choice;
	return choice;
}

void DoDrawRect(Rectangle theRect)
{
	int height=theRect.GetHeight();
	int width=theRect.GetWidth();

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
			cout<<"*";
		cout<<endl;
	}
}

void DoGetArea(Rectangle theRect)
{
	cout<<"Area: " <<theRect.GetArea() <<endl;
}

void DoGetPerim(Rectangle theRect)
{
	cout<<"Perimeter: " <<theRect.GetPerim() <<endl;
}

// END OF RROGRAM .
