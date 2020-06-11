//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Mb3.h"
#include "About.h"
#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Ship"
#pragma link "Tango"
#pragma resource "*.dfm"
TMbForm *MbForm;
//---------------------------------------------------------------------------
__fastcall TMbForm::TMbForm(TComponent* Owner)
    : TForm(Owner)
{
    // Заполняется контейнер кораблей человека
    ManShips.push_back(MShip1);
    ManShips.push_back(MShip2);
    ManShips.push_back(MShip3);
    ManShips.push_back(MShip4);
    ManShips.push_back(MShip5);
    ManShips.push_back(MShip6);
    ManShips.push_back(MShip7);
    ManShips.push_back(MShip8);
    ManShips.push_back(MShip9);
    ManShips.push_back(MShip10);
    ManShips.push_back(MShip11);
    ManShips.push_back(MShip12);
    ManShips.push_back(MShip13);
    ManShips.push_back(MShip14);
    ManShips.push_back(MShip15);
    ManShips.push_back(MShip16);
    ManShips.push_back(MShip17);
    ManShips.push_back(MShip18);
    ManShips.push_back(MShip19);
    ManShips.push_back(MShip20);
    ManShips.push_back(MShip21);
    ManShips.push_back(MShip22);
    ManShips.push_back(MShip23);
    ManShips.push_back(MShip24);
    ManShips.push_back(MShip25);
    ManShips.push_back(MShip26);
    ManShips.push_back(MShip27);
    ManShips.push_back(MShip28);
    ManShips.push_back(MShip29);
    ManShips.push_back(MShip30);
    ManShips.push_back(MShip31);
    ManShips.push_back(MShip32);
    ManShips.push_back(MShip33);
    ManShips.push_back(MShip34);
    ManShips.push_back(MShip35);
    ManShips.push_back(MShip36);

    // Заполняется контейнер кораблей компьютера
    ComputerShips.push_back(FShip1);
    ComputerShips.push_back(FShip2);
    ComputerShips.push_back(FShip3);
    ComputerShips.push_back(FShip4);
    ComputerShips.push_back(FShip5);
    ComputerShips.push_back(FShip6);
    ComputerShips.push_back(FShip7);
    ComputerShips.push_back(FShip8);
    ComputerShips.push_back(FShip9);
    ComputerShips.push_back(FShip10);
    ComputerShips.push_back(FShip11);
    ComputerShips.push_back(FShip12);
    ComputerShips.push_back(FShip13);
    ComputerShips.push_back(FShip14);
    ComputerShips.push_back(FShip15);
    ComputerShips.push_back(FShip16);
    ComputerShips.push_back(FShip17);
    ComputerShips.push_back(FShip18);
    ComputerShips.push_back(FShip19);
    ComputerShips.push_back(FShip20);
    ComputerShips.push_back(FShip21);
    ComputerShips.push_back(FShip22);
    ComputerShips.push_back(FShip23);
    ComputerShips.push_back(FShip24);
    ComputerShips.push_back(FShip25);
    ComputerShips.push_back(FShip26);
    ComputerShips.push_back(FShip27);
    ComputerShips.push_back(FShip28);
    ComputerShips.push_back(FShip29);
    ComputerShips.push_back(FShip30);
    ComputerShips.push_back(FShip31);
    ComputerShips.push_back(FShip32);
    ComputerShips.push_back(FShip33);
    ComputerShips.push_back(FShip34);
    ComputerShips.push_back(FShip35);
    ComputerShips.push_back(FShip36);
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::FormCreate(TObject *Sender)
{
    SetInterfaceLanguage("russian");
    // Открываем фоновую музыку
    MediaBackSound->FileName = "Sounds\\Bg.wma";
    MediaBackSound->Open();
    // Проигрываем фоновую музыку 
    MediaBackSound->Play();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::SetInterfaceLanguage(AnsiString value)
{
    bool is = (value == "english");

    MB3_Interface.SeaBottle     = is ? ("Sea Bottle"        ):("Морской бой"       );
    MB3_Interface.Game          = is ? ("Game"              ):("Игра"              );
    MB3_Interface.ExitGame      = is ? ("Exit"              ):("Выход"             );
    MB3_Interface.NewGame       = is ? ("New Game"          ):("Новая Игра"        );
    MB3_Interface.Settings      = is ? ("Settings ..."      ):("Настройки ..."     );
    MB3_Interface.Language      = is ? ("Language"          ):("Язык"              );
    MB3_Interface.Russian       = is ? ("Russian"           ):("Русский"           );
    MB3_Interface.English       = is ? ("English"           ):("Английский"        );
    MB3_Interface.About         = is ? ("About ..."         ):("О программе ..."   );
    MB3_Interface.Score         = is ? ("Score"             ):("Счет"              );
    MB3_Interface.YourShips     = is ? ("Man"               ):("Человек"           );
    MB3_Interface.MyShips       = is ? ("Computer"          ):("Компьютер"         );
    MB3_Interface.MaxShips      = is ? ("Max Ships"         ):("Макс. Кораблей"    );
    MB3_Interface.Cancel        = is ? ("Cancel"            ):("Отмена"            );
    MB3_Interface.SeaBottleV3   = is ? ("Sea Bottle v3.0"   ):("Морской Бой v3.0"  );
    MB3_Interface.CitySchool    = is ? ("c.Kharkov"         ):("г.Харьков"         );
    MB3_Interface.NovkoMichael  = is ? ("Novko Michael"     ):("Новко Михаил"      );
    MB3_Interface.Info1         = is ? ("If you have some suggestions, wishes"):
                                       ("Ваши предложения, вопросы и пожелания");
    MB3_Interface.Info2         = is ? ("and questions email to: "):
                                       ("Пишите мне, на e-mail: ");
    MB3_Interface.YouWin        = is ? ("You Win !!!"       ):("Ты Выиграл !!!"    );
    MB3_Interface.YouLose       = is ? ("You Lose !!!"      ):("Ты Проиграл !!!"   );
    MB3_Interface.Music         = is ? ("Music"             ):("Музыка"            );
    MB3_Interface.Sounds        = is ? ("Sounds"            ):("Звуки"             ); 

    MbForm->Caption             = MB3_Interface.SeaBottle;
    btnNewGame->Caption         = MB3_Interface.NewGame;
    btnExitGame->Caption        = MB3_Interface.ExitGame;
    mnuGame->Caption            = MB3_Interface.Game;
    mnuNewGame->Caption         = MB3_Interface.NewGame;
    mnuExitGame->Caption        = MB3_Interface.ExitGame;
    mnuSettingsGame->Caption    = MB3_Interface.Settings;
    mnuAbout->Caption           = MB3_Interface.About;
    lblScore->Caption           = MB3_Interface.Score;
    lblYourShips->Caption       = MB3_Interface.YourShips;
    lblMyShips->Caption         = MB3_Interface.MyShips;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuNewGameClick(TObject *Sender)
{
    NewGame();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::btnNewGameClick(TObject *Sender)
{
    NewGame();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuSettingsGameClick(TObject *Sender)
{
    MbSettings->Show();
    MbForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuAboutClick(TObject *Sender)
{
    AboutForm->Show();
    MbForm->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::btnExitGameClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::mnuExitGameClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    if (Application->MessageBox(MB3_Interface.ExitGame.c_str(),
    MB3_Interface.SeaBottle.c_str(), MB_OKCANCEL)== IDCANCEL)
        CanClose = false;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::Reset()
{
    ///////////////////////////////////////////////////////////
    // TODO: Оформить код, обеспечивающий полный сброс игры. //
    ///////////////////////////////////////////////////////////

    // Сброс состояния игры (счет, текущее кол-во кораблей, ...)
    MB3_GameRulesAndData.Reset();
    // Сброс состояния счетчика в настройках
    // --При старте игры, счетчик "Максимальное количество кораблей"
    // --нельзя изменить
    MbSettings->SpinMaxShips->Enabled = true;

    // Сбрасываются состояния кораблей человека
    for (int i=0; i<MB3_GameRulesAndData.GlobalShipsQuantity; ++i)
        ManShips.at(i)->State = ssInvisible;

    // Сбрасываются состояния кораблей компьютера
    for (int i=0; i<MB3_GameRulesAndData.GlobalShipsQuantity; ++i)
        ComputerShips.at(i)->State = ssInvisible;
        
    UpdateScore();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::NewGame()
{
    if(Application->MessageBox(MB3_Interface.NewGame.c_str(),
    MB3_Interface.SeaBottle.c_str(), MB_OKCANCEL)== IDCANCEL)
        return;

    Reset();
}
//---------------------------------------------------------------------------
// Расстановка кораблей компьютера
void __fastcall TMbForm::ComputerPrepare()
{
    Randomize();
    int Place;  // Место, куда будет поставлен корабль

        // Ниже, я специально пропускаю последний парамета цикла
        // Для того чтобы в случае повторного выбора корабля
        // не пропустить итерацию
    for (MB3_GameRulesAndData.CurrentComputerShips = 0;
         MB3_GameRulesAndData.CurrentComputerShips < MB3_GameRulesAndData.MaxShips;)
    {
        if (ComputerShips.at(Place = random(MB3_GameRulesAndData.GlobalShipsQuantity))
            ->State != ssHidden)
        // Если это место ещё не было выбрано
        {
            // Поставить корабль здесь
            ComputerShips.at(Place)->State = ssHidden;
            // Перейти к следующей итерации
            ++MB3_GameRulesAndData.CurrentComputerShips;
            // continue;
        }
        else
        // Если это место уже было выбрано
        {
            // Начать итерацию сначала
            continue;
        }
    }
}
//---------------------------------------------------------------------------
// Ничья
void __fastcall TMbForm::Tie()
{
    AnsiString WMes = "Ничья!\nTie!";
    WMes += "\n\n";
    WMes += MB3_Interface.Score;
    WMes += " - ";
    WMes += MB3_GameRulesAndData.ScoreMan;
    WMes += ":";
    WMes += MB3_GameRulesAndData.ScoreComputer;

    Application->MessageBox(WMes.c_str(), MB3_Interface.SeaBottle.c_str(), 0);
    Reset();
}
//---------------------------------------------------------------------------
// Победа человека
void __fastcall TMbForm::ManWin()
{
    AnsiString WMes = MB3_Interface.YouWin;
    WMes += "\n\n";
    WMes += MB3_Interface.Score;
    WMes += " - ";
    WMes += MB3_GameRulesAndData.ScoreMan;
    WMes += ":";
    WMes += MB3_GameRulesAndData.ScoreComputer;

    Application->MessageBox(WMes.c_str(), MB3_Interface.SeaBottle.c_str(), 0);
    Reset();
}
//---------------------------------------------------------------------------
// Победа компьютера
void __fastcall TMbForm::ComputerWin()
{
    AnsiString WMes = MB3_Interface.YouLose;
    WMes += "\n\n";
    WMes += MB3_Interface.Score;
    WMes += " - ";
    WMes += MB3_GameRulesAndData.ScoreComputer;
    WMes += ":";
    WMes += MB3_GameRulesAndData.ScoreMan;

    Application->MessageBox(WMes.c_str(), MB3_Interface.SeaBottle.c_str(), 0);
    Reset();
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::MShip36Click(TObject *Sender)
// Общая функция обработки событий от кораблей человека
{
    // Создается новый обьект, который будет
    // Использоваться в качестве управляющего.
    static TShip* _ship_;

    // Sender приводится к типу TShip*
    // Теперь можно использовать _ship_
    // как Sender в типе TShip.
    _ship_ = dynamic_cast<TShip*>(Sender);
    // Теперь можно использовать _ship_
    // в качестве управляющего

    if (MB3_GameRulesAndData.isGameStarted) // Если игра начата
    {
        Beep(1000,100); // Крикнуть :)))
    }
    else // Если игра не начата
    {
        // Если этот корабль невидимый
        if (_ship_->State != ssLive)
        { // Если ещё можно ставить корабли

            // Увеличить текущее количество кораблей человека
            ++MB3_GameRulesAndData.CurrentManShips;
            _ship_->State = ssLive;

        }
        else
        {
            // В принципе здесь CurrentShips никогда не станет 0.
            --MB3_GameRulesAndData.CurrentManShips;
            _ship_->State = ssInvisible;
        }
        if (MB3_GameRulesAndData.CurrentManShips == MB3_GameRulesAndData.MaxShips)
        { // Если кораблей Максимум
            // Начать игру
            MB3_GameRulesAndData.isGameStarted = true;
            // Запретить изменение счетчика в настройках
            MbSettings->SpinMaxShips->Enabled = false;
            Beep(1000,100); // Крикнуть :)))
            ComputerPrepare();
        }
    }
//    delete _ship_; // Возможно, его нельзя удалять (static)
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::FShip36Click(TObject *Sender)
// Общая функция обработки событий от кораблей компьютера
{
    // Создается новый обьект, который будет
    // Использоваться в качестве управляющего.
    static TShip* _ship_;

    // Sender приводится к типу TShip*
    // Теперь можно использовать _ship_
    // как Sender в типе TShip.
    _ship_ = dynamic_cast<TShip*>(Sender);
    // Теперь можно использовать _ship_
    // в качестве управляющего

    if (MB3_GameRulesAndData.isGameStarted) // Если игра начата
    {
        ManStep(_ship_);    // Обработать ход человека
        ComputerStep();     // Походить компьютеру
    }
    else // Если игра не начата
    {
        Beep(1000,100); // Крикнуть :)))
    }

//    delete _ship_; // Возможно, его нельзя удалять (static)
}
//---------------------------------------------------------------------------
void __fastcall
TMbForm::ManStep(TShip* Target)
{
    // TODO: ОБРАБОТАТЬ ХОД ЧЕЛОВЕКА,

    if (Target->State == ssHidden) // Если цель поражена
    {
        if (MB3_GameRulesAndData.isSounds)
        // Если звуки разрешены
        {
            // Перемотать звуки на начало файла
            MediaShotSound->Position = 0;
            MediaExplodeSound->Position = 0;
            // Проиграть звук выстрела, и взрыва
            MediaShotSound->Play();
            MediaExplodeSound->Play();
        }
        else // Если звуки отключены
        {
            // Промолчать )))
        }
        Target->State = ssDied; // Показать пораженный корабль
        ++MB3_GameRulesAndData.ScoreMan;
        UpdateScore();
    }
    else // Если цель не поражена
    {
        if (MB3_GameRulesAndData.isSounds)
        // Если звуки разрешены        
        {
            // Перемотать звуки на начало файла
            MediaShotSound->Position = 0;            
            // Проиграть звук выстрела, [и промаха]
            MediaShotSound->Play();
        }
        else // Если звуки отключены
        {
            // Промолчать )))
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall
TMbForm::ComputerStep()
{
    // TODO: ОБРАБОТАТЬ ХОД КОМПЬЮТЕРА,

    Randomize();
    int Place; // Цель

    for (;;)  //// Бесконечный цикл НАМНОГО лучше goto
    {
        Place = random(MB3_GameRulesAndData.GlobalShipsQuantity); // Цель

        if (ManShips.at(Place)->State == ssLive)
        // Если здесь живой корабль
        {
            // Убить его
            ManShips.at(Place)->State = ssDied;
            // Прибавить счет
            ++MB3_GameRulesAndData.ScoreComputer;
            UpdateScore();
            CheckWinOrLose(); //// Проверить, выиграл ли кто нибудь
            break;
        }
        else
        if (ManShips.at(Place)->State == ssInvisible)
        // Если здесь нет корабля
        {
            // Показать воду
            ManShips.at(Place)->State = ssWater;
            CheckWinOrLose(); //// Проверить, выиграл ли кто нибудь            
            break;
        }
        else
        if (ManShips.at(Place)->State == ssDied)
        // Если здесь убитый корабль
        {
            // Выбрать другую цель
            if (CheckWinOrLose()) break; //// Защита от бесконечного цикла
            continue;
        }
        else
        if (ManShips.at(Place)->State == ssWater)
        // Если в это место уже стреляли
        {
            // Выбрать другую цель
            if (CheckWinOrLose()) break; //// Защита от бесконечного цикла
            continue;
        }
    }
}
//---------------------------------------------------------------------------
int __fastcall
TMbForm::CheckWinOrLose()
{
    // TODO: Проверить, выиграл ли кто нибудь

    if ((MB3_GameRulesAndData.ScoreMan == MB3_GameRulesAndData.MaxShips) &&
        (MB3_GameRulesAndData.ScoreComputer == MB3_GameRulesAndData.MaxShips))
        {   // Если ничья
            // Перемотать звуковоые файлы на начало
            MediaWinSound->Position = 0;
            MediaLoseSound->Position = 0;
            // Проиграть звуки
            MediaWinSound->Play();
            MediaLoseSound->Play();
            
            Tie();
            return 1;
        }
    else
    if (MB3_GameRulesAndData.ScoreMan == MB3_GameRulesAndData.MaxShips)
    {
        // Выиграл Человек
        // Перемотать звуковой файл на начало
        MediaWinSound->Position = 0;
        // Проиграть звук
        MediaWinSound->Play();

        ManWin();
        return 1;
    }
    else
    if (MB3_GameRulesAndData.ScoreComputer == MB3_GameRulesAndData.MaxShips)
    {
        // Выиграл Компьютер
        // Перемотать звуковой файл на начало
        MediaLoseSound->Position = 0;
        // Проиграть звук
        MediaLoseSound->Play();

        ComputerWin();
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall
TMbForm::UpdateScore()
{
    // Обновить счет, на Label'ах
    ScoreMan->Caption = MB3_GameRulesAndData.ScoreMan;
    ScoreComputer->Caption = MB3_GameRulesAndData.ScoreComputer;
}
//---------------------------------------------------------------------------
void __fastcall TMbForm::MediaBackSoundNotify(TObject *Sender)
{// Если музыка закончилась, начать с начала
    // Перекрутить на начало файла (музыка)
    if (MediaBackSound->Position == MediaBackSound->Length)
    {
        MediaBackSound->Position = 0;
        MediaBackSound->Play(); // Проигрывать
    }
}
//---------------------------------------------------------------------------
