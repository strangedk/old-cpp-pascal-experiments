//---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include "Tango.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMbSettings : public TForm
{
__published:	// IDE-managed Components
    TTango *Ok;
    TTango *Cancel;
    TGroupBox *SettingsBox;
    TCSpinEdit *SpinMaxShips;
    TLabel *lblMaxShips;
    TGroupBox *radioLanguage;
    TCheckBox *rbRussianLang;
    TCheckBox *rbEnglishLang;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TCheckBox *isMusic;
    TCheckBox *isSounds;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall CancelClick(TObject *Sender);
    void __fastcall OkClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall rbRussianLangClick(TObject *Sender);
    void __fastcall rbEnglishLangClick(TObject *Sender);
    void __fastcall SpinMaxShipsChange(TObject *Sender);
    void __fastcall Label1Click(TObject *Sender);
    void __fastcall Label2Click(TObject *Sender);
    void __fastcall Label3Click(TObject *Sender);
    void __fastcall Label4Click(TObject *Sender);
    void __fastcall SpinMaxShipsClick(TObject *Sender);
private:
    bool restoreLang; // Переменная для восстановления флажка в случае отмены
public:
    __fastcall TMbSettings(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMbSettings *MbSettings;
//---------------------------------------------------------------------------
#endif
