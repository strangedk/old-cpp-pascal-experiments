//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "infs.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Canvas->Brush->Color = clBlue;

    pixels = 60;
    radius = 1;

    r=0;
    g=255;
    b=128;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if (r > 250)        ri = 0;
    else if (r < 5)     ri = 1;
    if (ri == 1)        r += 5;
    else if (ri == 0)   r -= 5;

    if (g > 150)        gi = 0;
    else if (g < 5)     gi = 1;
    if (gi == 1)        g += 5;
    else if (gi == 0)   g -= 5;

    if (b > 250)        bi = 0;
    else if (b < 5)     bi = 1;
    if (bi == 1)        b += 5;
    else if (bi == 0)   b -= 5;

    radius = 1;
    i = 0;

    ++k;

    for (int m=0; m<2000; ++m)
    {
        radius += 0.4;
        ++i;

        if (radius > 200 && radius < 400)
        {
            delta = (2*M_PI*i/pixels) - (k-radius);
//          Canvas->Pen->Color = (TColor)RGB(r,g,b);
//          Canvas->Brush->Color = (TColor)RGB(r,g,b);
            Canvas->Pen->Color = clBlack;
            Canvas->Brush->Color = clWhite;
        }
        else
        {
            delta = (2*M_PI*i/pixels) + (k+radius);
//          Canvas->Pen->Color = (TColor)RGB(r,g,b);
//          Canvas->Brush->Color = (TColor)RGB(r,g,b);
            Canvas->Pen->Color = clWhite;
            Canvas->Brush->Color = clBlack;
        }

        x = Width/2 + radius * sin(delta);
        y = Height/2 + radius * cos(delta);

        Canvas->Rectangle(x,y,x+10,y+10);
    }
}
//---------------------------------------------------------------------------
