//---------------------------------------------------------------------------

#ifndef CheatH
#define CheatH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TCheatForm : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    void __fastcall Image1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TCheatForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCheatForm *CheatForm;
//---------------------------------------------------------------------------
#endif
