//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("ProjectMb3.res");
USEFORM("Mb3.cpp", MbForm);
USEFORM("About.cpp", AboutForm);
USEFORM("Settings.cpp", MbSettings);
USEFORM("Cheat.cpp", CheatForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR par, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "Морской Бой";
         Application->CreateForm(__classid(TMbForm), &MbForm);
         Application->CreateForm(__classid(TAboutForm), &AboutForm);
         Application->CreateForm(__classid(TMbSettings), &MbSettings);
         Application->CreateForm(__classid(TCheatForm), &CheatForm);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
