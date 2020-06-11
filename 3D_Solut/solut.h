//---------------------------------------------------------------------------

#ifndef solutH
#define solutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Tango.h"
#include <Buttons.hpp>
#include <vector>
#include <math>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    TSpeedButton *SpeedButton1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
private:
public:
    vector<TShape*> solut;
    vector<TShape*> solut2;
    vector<TShape*> solut3;        

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
