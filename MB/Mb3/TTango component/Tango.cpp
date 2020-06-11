//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Tango.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TTango *)
{
    new TTango(NULL);
}
//---------------------------------------------------------------------------
__fastcall TTango::TTango(TComponent* Owner) : TGraphicControl(Owner)
{
// Events:
    mClick = 0;
    mState = tsUp;
    mMouseIn = false;
// Properties:
    mFaceColor = clBtnFace;
    mOverColor = clWhite;
    mCaption = "Tango";

    Width = 75;
    Height = 25;
}
//---------------------------------------------------------------------------
namespace Tango
{
    void __fastcall PACKAGE Register()
    {
         TComponentClass classes[1] = {__classid(TTango)};
         RegisterComponents("Myp", classes, 0);
    }
}
//---------------------------------------------------------------------------
void __fastcall
TTango::Paint()
{
    TRect TextRect;
    int TextHeight = Canvas->TextHeight(mCaption);
    int TextWidth  = Canvas->TextWidth(mCaption);

    TextRect.Left    = (ClientWidth/2) - (TextWidth/2);
    TextRect.Top     = (ClientHeight/2) - (TextHeight/2);
    TextRect.Bottom  = (TextRect.Top + TextHeight);
    TextRect.Right   = (ClientWidth/2) - (TextWidth/2) + TextWidth;

    Canvas->Brush->Color = mFaceColor;
    Canvas->FillRect(ClientRect);

    mFrameTColor = (mState==tsUp)   ? clBtnHighlight : clBtnShadow;
    mFrameBColor = (mState==tsDown) ? clBtnHighlight : clBtnShadow;
    Frame3D(Canvas, ClientRect, mFrameTColor, mFrameBColor, 2);
    Canvas->TextRect(TextRect, TextRect.Left, TextRect.Top, mCaption);
}
//---------------------------------------------------------------------------
void __fastcall
TTango::SetCaption(AnsiString value)
{
    mCaption = value;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall
TTango::SetColor(TColor value)
{
    mFaceColor = value;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall
TTango::CMMouseEnter(TMessage& Msg)
{
    if (Enabled)
    {
        mTemp = Color;
        Color = OverColor;
        mMouseIn = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall
TTango::CMMouseLeave(TMessage& Msg)
{
    if (Enabled)
    {
        mMouseIn = false;
        Color = mTemp;
        mState = tsUp;
    }
}
//---------------------------------------------------------------------------
void __fastcall
TTango::MouseDown(TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbLeft)
    {
        if (Enabled && mMouseIn)
        {
            mState = tsDown;
            Invalidate();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall
TTango::MouseUp(TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbLeft)
    {
        mMouseIn = true;
        if (Enabled)
        {
            Invalidate();
            mState = tsUp;
            if (mClick)
                mClick(this);
        }
    }
}
//---------------------------------------------------------------------------
