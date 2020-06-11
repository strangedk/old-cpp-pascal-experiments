//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Ship.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TShip *)
{
    new TShip(NULL);
}
//---------------------------------------------------------------------------
__fastcall TShip::TShip(TComponent* Owner) : TGraphicControl(Owner)
{
    Width = 33;
    Height = 33;

    mSide = sdMan;
    mState = ssInvisible;

    mClick = 0;
}
//---------------------------------------------------------------------------
/*
TShip*
TShip::operator=(TShip* rhs)
{
    mIndex  = rhs->mIndex;
    mState  = rhs->mState;
    mSide   = rhs->mSide;
    mClick  = rhs->mClick;

    return this;
}
*/
//---------------------------------------------------------------------------
void __fastcall
TShip::SetState(ShipState value)
{
    mState = value;
    Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall
TShip::MouseDown(TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if (Button == mbLeft)
    {
        Invalidate();

        if (mClick)
            mClick(this);
    }
}
//---------------------------------------------------------------------------
void __fastcall
TShip::DrawShipState()
{
    Graphics::TBitmap* Glyph = new Graphics::TBitmap;

    Glyph->Width = Width;
    Glyph->Height = Height;

    Glyph->Transparent = true;

    switch (mState) // Проверить состояние корабля
    {
        case ssInvisible: // Если Корабль Невидимый
            Frame3D(Canvas, ClientRect, clBlack, clWhite, 1);
        break;
        case ssLive: // Если Корабль Живой
            Glyph->LoadFromFile("images\\Ship.bmp");
            Canvas->Draw(0,0,Glyph);
        break;
        case ssDied: // Если Корабль убит
            Glyph->LoadFromFile("images\\Crash.bmp");
            Canvas->Draw(0,0,Glyph);
        break;
        case ssHidden: // Если Корабль спрятаный
        // Сделать его таким же как и невидимый
            Frame3D(Canvas, ClientRect, clBlack, clWhite, 1);
        break;
        case ssWater: // Если компьютер выстрелил, но корабля не было
            Glyph->LoadFromFile("images\\Void.bmp");
            Canvas->Draw(0,0,Glyph);
        break;
     }
     delete Glyph;
}
//---------------------------------------------------------------------------
void __fastcall
TShip::Paint()
{
    DrawShipState();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

namespace Ship
{
    void __fastcall PACKAGE Register()
    {
         TComponentClass classes[1] = {__classid(TShip)};
         RegisterComponents("Myp", classes, 0);
    }
}
//---------------------------------------------------------------------------
