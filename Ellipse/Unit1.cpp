//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    randomize();

    Ri = 1;
    Gi = 0;
    Bi = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTimer(TObject *Sender)
{
    static int x1 = 0;
    static int y1 = 0;
    static int x2 = Width;
    static int y2 = Height;

    static int R=random(255), G=random(255), B=random(255);

    if (R > 250)        Ri = 0;
    else if (R < 5)     Ri = 1;
    if (Ri == 1)        R += 1;
    else if (Ri == 0)   R -= 1;

    if (G > 250)        Gi = 0;
    else if (G < 5)     Gi = 1;
    if (Gi == 1)        G += 1;
    else if (Gi == 0)   G -= 1;

    if (B > 250)        Bi = 0;
    else if (B < 5)     Bi = 1;
    if (Bi == 1)        B += 1;
    else if (Bi == 0)   B -= 1;

    static int ix1 = 0;
    static int iy1 = 0;
    static int ix2 = 1;
    static int iy2 = 1;

         if ( x1 < 0      ) ix1 = 1;
    else if ( x1 > Width  ) ix1 = 0;

         if ( y1 < 0      ) iy1 = 1;
    else if ( y1 > Height ) iy1 = 0;

         if ( x2 < 0      ) ix2 = 1;
    else if ( x2 > Width  ) ix2 = 0;

         if ( y2 < 0      ) iy2 = 1;
    else if ( y2 > Height ) iy2 = 0;


    if (ix1)        ++x1;
    else            --x1;
    if (iy1)        ++y1;
    else            --y1;
    if (ix2)        ++x2;
    else            --x2;
    if (iy2)        ++y2;
    else            --y2;


//    HRGN rg = CreateEllipticRgn(x1,y1,x2,y2);

//    SetWindowRgn(Handle,rg,1);

    Canvas->Brush->Color = (TColor)RGB(R,G,B);
    Canvas->Pen->Color = (TColor)RGB(R,G,B);

    Canvas->Ellipse(x1,y1,x2,y2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    if (Button == mbLeft)
    {
        Timer->Enabled = !Timer->Enabled;
    }
    else
    if (Button == mbRight)
    {
        Invalidate();
    }
    else
    if (Button == mbMiddle)
    {
        Ri = 255-Ri;
        Gi = 255-Gi;
        Bi = 255-Bi;
    }
}
//---------------------------------------------------------------------------
