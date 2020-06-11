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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
SetWindowLong(Handle,GWL_EXSTYLE,GetWindowLong(Handle,GWL_EXSTYLE)^WS_EX_LAYERED);
// SetLayeredWindowAttributes(Handle,RGB(0,0,0),64,LWA_ALPHA);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
static int i = 0;
static int ii = 1;

if (i >= 255)
    ii = 0;
else
if (i <= 0)
    ii = 1;

if (ii)
    i += 3;
else
if (!ii)
    i -= 3;
SetLayeredWindowAttributes(Handle,RGB(0,0,0),i,LWA_ALPHA);
}
//---------------------------------------------------------------------------
