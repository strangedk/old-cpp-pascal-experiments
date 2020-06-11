//---------------------------------------------------------------------------
/*
        "ПЕРЕКРЕСТИ СЧЕТЧИК":
        
             3
          2[|||]1
             4

        Нужно кликнуть на правой Label(1)
        На Левой Label(2)
        На верхней Label(3)
        На нижней Label(4)
        И получить CHEAT!

        !- Язык должен быть АНГЛИЙСКИМ!
        -- Если перепутать порядок (1,2,3,4)
        -- то придется начать все с начала!
*/
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Settings.h"
#include "Mb3.h"
#include "Cheat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "Tango"
#pragma resource "*.dfm"
TMbSettings *MbSettings;
//---------------------------------------------------------------------------
int Cheat1=0; // Нужно )))
int Cheat2=0; // Тоже Нужно )))
int Cheat3=0; // В программе лишнего нету !!!
//---------------------------------------------------------------------------
__fastcall TMbSettings::TMbSettings(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::FormCreate(TObject *Sender)
{
    // Если при загрузке язык по умолчанию
    // Русский - то здесь тоже должно быть "ПО РУССКИ"
    rbRussianLang->Checked = true;
    // --Нужно установить соответствующий флажок
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::FormShow(TObject *Sender)
{
    // Обновляем значение счетчика
    SpinMaxShips->Value = MbForm->MB3_GameRulesAndData.MaxShips;
    // Сохраняем значение счетчика(см. ниже)
    SpinMaxShips->Tag = SpinMaxShips->Value;

    // Сохраняем текущее состояние флажка "Русский" (Язык Интерфейса)
    restoreLang = rbRussianLang->Checked;

    // Обновляем и Сохраняем текущее состояние флажка "Музыка"
    isMusic->Tag = (int)isMusic->Checked;
    isMusic->Checked = MbForm->MB3_GameRulesAndData.isMusic;
    // Обновляем и Сохраняем текущее состояние флажка "Звуки"
    isSounds->Checked = MbForm->MB3_GameRulesAndData.isSounds;
    isSounds->Tag = (int)isSounds->Checked;

    // Устанавливаем язык интерфейса
    MbSettings->Caption     = MbForm->MB3_Interface.SeaBottle;
    lblMaxShips->Caption    = MbForm->MB3_Interface.MaxShips;
    radioLanguage->Caption  = MbForm->MB3_Interface.Language;
    rbRussianLang->Caption  = MbForm->MB3_Interface.Russian;
    rbEnglishLang->Caption  = MbForm->MB3_Interface.English;
    Cancel->Caption         = MbForm->MB3_Interface.Cancel;
    isMusic->Caption        = MbForm->MB3_Interface.Music;
    isSounds->Caption       = MbForm->MB3_Interface.Sounds;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    // При показывании этой формы главная блокируется
    // В коде вызова, здесь же её нужно разблокировать
    MbForm->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::CancelClick(TObject *Sender)
{
    // Восстанавливаем сохраненное значение счетчика
    SpinMaxShips->Value = SpinMaxShips->Tag;

    // Восстанавливаем сохраненное состояние флажка "Русский"
    rbRussianLang->Checked = restoreLang;
    // Восстанавливаем сохраненное состояние флажка "Музыка"
    isMusic->Checked = (bool)isMusic->Tag;
    // Восстанавливаем сохраненное состояние флажка "Звуки"
    isSounds->Checked = (bool)isSounds->Tag;

    // Восстанавливает сохраненное значение флажка "Русский" - наоборот
    // --Если сохр. состояние равно 1 то это будет 0
    // --И наоборот
    rbEnglishLang->Checked = !restoreLang;

    // типа Выход
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::OkClick(TObject *Sender)
{
    /* TODO: Применить настройку */
    
    if (rbRussianLang->Checked)
    // Если выбран русский
    {
        // Применить русский язык
        MbForm->SetInterfaceLanguage("russian");
    }
    else
    if (rbEnglishLang->Checked)
    // Если выбран английский
    {
        // Применить английский язык
        MbForm->SetInterfaceLanguage("english");
    }

    // Применение - музыка
    MbForm->MB3_GameRulesAndData.isMusic = isMusic->Checked;
    // Сразу после закрытия окна, нужно включить/выключить музыку
    if (isMusic->Checked)
    {
        MbForm->MediaBackSound->Play();
    }
    else
    {
        // Чтобы при следующем включении, музыка начиналась с начала
        MbForm->MediaBackSound->Pause();
        MbForm->MediaBackSound->Position = 0;        
    }
        
    // Применение - звуки
    MbForm->MB3_GameRulesAndData.isSounds = isSounds->Checked;

    // Если игра не начата
    if (MbForm->MB3_GameRulesAndData.isGameStarted == false)
    {
        MbForm->Reset();
        // Сохранить новое значение счетчика
        MbForm->MB3_GameRulesAndData.MaxShips = SpinMaxShips->Value;
    }

    // типа Выход
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::rbRussianLangClick(TObject *Sender)
{
    // Установка/Снятие одного флажка должна Снимать/Устанавливать другой
    rbEnglishLang->Checked = !rbRussianLang->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::rbEnglishLangClick(TObject *Sender)
{
    // Установка/Снятие одного флажка должна Снимать/Устанавливать другой
    rbRussianLang->Checked = !rbEnglishLang->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::SpinMaxShipsClick(TObject *Sender)
{
    // Я знаю, что при Enabled == false этот код не сработает
    // Но почему он здесь ? А просто так !
    if (!SpinMaxShips->Enabled)
        Beep(1000,100); // Крикнуть :)))
}
//---------------------------------------------------------------------------
void __fastcall TMbSettings::SpinMaxShipsChange(TObject *Sender)
{
// На тот случай если какой-нить думер Захочет вводить НЕ цифры.
try
{
    // На тот случай если хто-нить будет хитрить
    if (SpinMaxShips->Value > SpinMaxShips->MaxValue)
        SpinMaxShips->Value = SpinMaxShips->MaxValue;
    else
    if (SpinMaxShips->Value < SpinMaxShips->MinValue)
        SpinMaxShips->Value = SpinMaxShips->MinValue;
}
// Если все же думер ввел НЕ цифры
catch(...) // Обломать его :)-)-)-))
{
    SpinMaxShips->Value = SpinMaxShips->MinValue;
}
}
//---------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////
////----------------------- C H E A T -----------------------------------////
/////////////////////////////////////////////////////////////////////////////
void __fastcall TMbSettings::Label1Click(TObject *Sender)
{
    Cheat1 = 1; Cheat2 = 0; Cheat3 = 0;
}
void __fastcall TMbSettings::Label2Click(TObject *Sender)
{
    if (Cheat1 == 1){ Cheat1 = 0; Cheat2 = 1; Cheat3 = 0; }
    else { Cheat1 = 0; Cheat2 = 0; Cheat3 = 0; }
}
void __fastcall TMbSettings::Label3Click(TObject *Sender)
{
    if (Cheat2 == 1){ Cheat1 = 0; Cheat2 = 0; Cheat3 = 1; }
    else { Cheat1 = 0; Cheat2 = 0; Cheat3 = 0; }
}
void __fastcall TMbSettings::Label4Click(TObject *Sender)
{
    // CheatForm->Show - Вот настоящий СНЕАТ!
    if (rbEnglishLang->Checked && Cheat3 == 1){ CheatForm->Show(); }
    Cheat1 = 0; Cheat2 = 0; Cheat3 = 0;
}
/////////////////////////////////////////////////////////////////////////////
////--------------End of--- C H E A T -----------------------------------////
/////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
