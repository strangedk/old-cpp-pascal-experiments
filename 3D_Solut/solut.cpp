//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "solut.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Tango"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
    double PI = 3.14159;
    double R=120, V;
    double DeltaV=0;
    double Angle=0;
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TShape *lbl, *lbl2, *lbl3;

    DeltaV = (Form1->Height/2) + (Form1->Height/3);

    for(int i=0;i<24;i++)
    {
        lbl=new TShape(this);
        lbl->Parent=this;
        lbl->Shape=stCircle;
        lbl->Brush->Color = clRed;
        lbl->Width = 6;
        lbl2=new TShape(this);
        lbl2->Parent=this;
        lbl2->Shape=stCircle;
        lbl2->Brush->Color = clGreen;
        lbl2->Width = 6;
        lbl3=new TShape(this);
        lbl3->Parent=this;
        lbl3->Shape=stCircle;
        lbl3->Brush->Color = clBlue;
        lbl3->Width = 6;

        solut.push_back(lbl);
        solut2.push_back(lbl2);
        solut3.push_back(lbl3);
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    for (int i=0; i<solut.size(); ++i)
    {
        Angle += 000000000.1; // Для Эффекта Трехмерного вращения
        DeltaV += 000.1;    // Для Вращения
        V = 2*(PI*i) / solut.size() + DeltaV; // Вычисляется V

       	solut .at(i)->Top = Height/2 + R * sin(Angle/100-V);
       	solut2.at(i)->Top = Height/2 + R/2 * sin(Angle/100-V);
       	solut3.at(i)->Top = Height/2 + R/4 * sin(Angle/100-V);
       	solut .at(i)->Left = Width/2 + R * cos(Angle/100+V);
       	solut2.at(i)->Left = Width/2 + R/2 * cos(Angle/100+V);
       	solut3.at(i)->Left = Width/2 + R/4 * cos(Angle/100+V);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
    Timer1->Enabled = !Timer1->Enabled;    
}
//---------------------------------------------------------------------------

