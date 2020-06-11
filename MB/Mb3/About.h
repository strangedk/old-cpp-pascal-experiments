//---------------------------------------------------------------------------

#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Tango.h"
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:
    TTango *btnCloseAbout;
    TLabel *lblAuthor;
    TLabel *lblCitySchool;
    TLabel *lblMBv3;
    TLabel *lblADD1;
    TLabel *lblADD2;
    TLabel *lblEMail;
    TLabel *lblCopyright;
    TPanel *Panel1;
    TImage *BGImage;
    TTimer *Timer1;
    TLabel *GlowLine;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall btnCloseAboutClick(TObject *Sender);
    void __fastcall Panel1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
private:
    TColor mFormColor; // Главный цвет
public:
    __fastcall TAboutForm(TComponent* Owner);
    // Подготавливает форму - цвет, регионы e.t.c.
    void __fastcall PrepareForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
