//---------------------------------------------------------------------------

#ifndef ShipH
#define ShipH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
// Состояние корабля: Невидимый, Живой, Убитый
enum ShipState { ssInvisible, ssLive, ssDied , ssHidden, ssWater};
// Корабль на стороне: Человека, Компьютера
enum OnSide { sdMan, sdComputer };
//---------------------------------------------------------------------------

class PACKAGE TShip : public TGraphicControl
{
private:
    int mIndex;
    ShipState mState;
    OnSide mSide;
    TNotifyEvent mClick;
public:
    __fastcall TShip(TComponent* Owner);
//    TShip* operator=(TShip*);
    void __fastcall SetState(ShipState);

protected:
	DYNAMIC void __fastcall MouseDown(TMouseButton, TShiftState, int, int); 
    void __fastcall DrawShipState();
    void __fastcall Paint();
__published:
    __property ShipState State = { read=mState, write=SetState };
    __property OnSide Side = { read=mSide, write=mSide };
    __property int Index = { read=mIndex, write=mIndex };
    __property TNotifyEvent OnClick = { read=mClick, write=mClick };
};
//---------------------------------------------------------------------------
#endif
