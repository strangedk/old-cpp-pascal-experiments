//---------------------------------------------------------------------------

#ifndef TangoH
#define TangoH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
enum TTangoState { tsUp, tsDown };

class PACKAGE TTango : public TGraphicControl
{
private:
    TTangoState mState;
    AnsiString mCaption;
    TColor mOverColor, mFaceColor;
    TColor mTemp;
    TColor mFrameTColor; // Top
    TColor mFrameBColor; // Bottom

    bool mMouseIn;
    TNotifyEvent mClick;
protected:
    void __fastcall Paint();
	DYNAMIC void __fastcall MouseDown(TMouseButton, TShiftState, int, int);
	DYNAMIC void __fastcall MouseUp(TMouseButton, TShiftState, int, int);
public:
    __fastcall TTango(TComponent* Owner);
    void __fastcall SetCaption(AnsiString);
    void __fastcall SetColor(TColor);
    void __fastcall SwapColors();

    void __fastcall CMMouseEnter(TMessage&);
    void __fastcall CMMouseLeave(TMessage&);
__published:
    __property AnsiString Caption = { read=mCaption, write=SetCaption };
    __property TColor Color = { read=mFaceColor, write=SetColor };
    __property TColor OverColor = { read=mOverColor, write=mOverColor };
    __property TNotifyEvent OnClick = { read=mClick, write=mClick };

BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(CM_MOUSEENTER, TMessage, CMMouseEnter)
    MESSAGE_HANDLER(CM_MOUSELEAVE, TMessage, CMMouseLeave)
END_MESSAGE_MAP(TGraphicControl)
};
//---------------------------------------------------------------------------
#endif
