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

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    static int R=128, G=255, B=0;
    static int Ri=1, Gi=0, Bi=1;

    if (R > 250)        Ri = 0;
    else if (R < 5)     Ri = 1;
    if (Ri == 1)        R += 5;
    else if (Ri == 0)   R -= 5;

    if (G > 250)        Gi = 0;
    else if (G < 5)     Gi = 1;
    if (Gi == 1)        G += 5;
    else if (Gi == 0)   G -= 5;

    if (B > 250)        Bi = 0;
    else if (B < 5)     Bi = 1;
    if (Bi == 1)        B += 5;
    else if (Bi == 0)   B -= 5;

    HWND hWnd;

    hWnd = FindWindow("Shell_TrayWnd", NULL);
    hWnd = FindWindowEx(hWnd, NULL, "BUTTON", NULL);

    ShowWindow(Handle, SW_HIDE);

    HDC hDC = GetDC(hWnd);

    for (int i=0; i<70; ++i)
        SetPixel(hDC,random(50),random(20),RGB(R,G,B));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
HWND hWnd = CreateWindowEx
(
    WS_EX_TOOLWINDOW,        // Задаём нужный стиль.
    szWindowClass,
    szTitle,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    NULL,
    NULL,
    hInstance,
    NULL
);
}
//---------------------------------------------------------------------------
