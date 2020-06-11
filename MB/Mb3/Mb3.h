//---------------------------------------------------------------------------
#ifndef Mb3H
#define Mb3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "Ship.h"
#include "Tango.h"
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <Graphics.hpp>
#include <MPlayer.hpp>
#include <jpeg.hpp>
#include <vector>

using namespace std;

//---------------------------------------------------------------------------
class TMbForm : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu;
    TMenuItem *mnuGame;
    TMenuItem *mnuNewGame;
    TMenuItem *mnuExitGame;
    TMenuItem *mnuHelp;
    TMenuItem *mnuAbout;
    TTango *btnExitGame;
    TTango *btnNewGame;
    TShip *MShip1;
    TShip *MShip2;
    TShip *MShip3;
    TShip *MShip4;
    TShip *MShip5;
    TShip *MShip6;
    TShip *MShip7;
    TShip *MShip8;
    TShip *MShip9;
    TShip *MShip10;
    TShip *MShip11;
    TShip *MShip12;
    TShip *MShip13;
    TShip *MShip14;
    TShip *MShip15;
    TShip *MShip16;
    TShip *MShip17;
    TShip *MShip18;
    TShip *MShip19;
    TShip *MShip20;
    TShip *MShip21;
    TShip *MShip22;
    TShip *MShip23;
    TShip *MShip24;
    TShip *MShip25;
    TShip *MShip26;
    TShip *MShip27;
    TShip *MShip28;
    TShip *MShip29;
    TShip *MShip30;
    TShip *MShip31;
    TShip *MShip32;
    TShip *MShip33;
    TShip *MShip34;
    TShip *MShip35;
    TShip *MShip36;
    TLabel *lblScore;
    TShip *FShip1;
    TShip *FShip2;
    TShip *FShip3;
    TShip *FShip4;
    TShip *FShip5;
    TShip *FShip6;
    TShip *FShip7;
    TShip *FShip8;
    TShip *FShip9;
    TShip *FShip10;
    TShip *FShip11;
    TShip *FShip12;
    TShip *FShip13;
    TShip *FShip14;
    TShip *FShip15;
    TShip *FShip16;
    TShip *FShip17;
    TShip *FShip18;
    TShip *FShip19;
    TShip *FShip20;
    TShip *FShip21;
    TShip *FShip22;
    TShip *FShip23;
    TShip *FShip24;
    TShip *FShip25;
    TShip *FShip26;
    TShip *FShip27;
    TShip *FShip28;
    TShip *FShip29;
    TShip *FShip30;
    TShip *FShip31;
    TShip *FShip32;
    TShip *FShip33;
    TShip *FShip34;
    TShip *FShip35;
    TShip *FShip36;
    TLabel *ScoreMan;
    TLabel *ScoreComputer;
    TLabel *lblYourShips;
    TLabel *lblMyShips;
    TImage *BgImage;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *mnuSettingsGame;
    TMediaPlayer *MediaBackSound;
    TMediaPlayer *MediaShotSound;
    TMediaPlayer *MediaExplodeSound;
    TMediaPlayer *MediaWinSound;
    TMediaPlayer *MediaLoseSound;
    void __fastcall mnuAboutClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnExitGameClick(TObject *Sender);
    void __fastcall mnuExitGameClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall btnNewGameClick(TObject *Sender);
    void __fastcall mnuNewGameClick(TObject *Sender);
    void __fastcall MShip36Click(TObject *Sender);
    void __fastcall FShip36Click(TObject *Sender);
    void __fastcall mnuSettingsGameClick(TObject *Sender);
    void __fastcall MediaBackSoundNotify(TObject *Sender);
private:
    // Контейнер содержащий корабли компьютера
    vector<TShip*> ComputerShips;
    // Контейнер содержащий корабли человека
    vector<TShip*> ManShips;
public:
    // Класс, содержащий данные о языке интерфейса
    class Interface
    {
    public:
        AnsiString
        SeaBottle,
        Game,
        ExitGame,
        NewGame,
        Settings,
        Language,
        Russian,
        English,
        About,
        Score,
        YourShips,
        MyShips,
        MaxShips,
        Cancel,
        SeaBottleV3,
        CitySchool,
        NovkoMichael,
        Info1, Info2,
        YouWin,
        YouLose,
        Music,
        Sounds
        ;
    } MB3_Interface;

    // Класс, Содержащий данные об игре
    class GameRulesAndData
    {
    public:
    GameRulesAndData()
    {
        // Количество ячеек на поле (человека или компьютера)
        GlobalShipsQuantity = 36;
        MaxShips = 12;          // Начальное значение - Макс. Кораблей
        isMusic = true;         // Начальное значение - Музыка
        isSounds = true;        // Начальное значение - Звуки
        Reset();                // Общий сброс
    }
    // Полный сброс
    void Reset()
    {
        CurrentManShips = 0;      // Сброс текущего количества кораблей человека
        CurrentComputerShips = 0; // Сброс текущего количества кораблей компьютера
        ScoreMan = 0;           // Сброс счета человека
        ScoreComputer = 0;      // Сброс счета компьютера
        isGameStarted = false;  // Сброс состояния игры (не начата)
    }
        int
        MaxShips,               // Максимальное количество кораблей
        CurrentManShips,           // Текущее количество кораблей человека
        CurrentComputerShips,   // Текущее количество кораблей компьютера
        ScoreMan,               // Счет человека
        ScoreComputer;          // Счет компьютера
        // Количество ячеек на поле одного игрока
        int GlobalShipsQuantity;
        bool
        isMusic,                // Музыка
        isSounds,               // Звуки
        isGameStarted;          // Игра начата или нет

        // TODO: Продолжение Следует.
    } MB3_GameRulesAndData;

    __fastcall TMbForm(TComponent* Owner);
    // Изменяет язык интерфейса (русский/английский)
    void __fastcall SetInterfaceLanguage(AnsiString="english");
    // Сбрасывает игру
    void __fastcall Reset();
    // Сбрасывает игру с подтверждением (использует Reset())
    void __fastcall NewGame();
    // Расставляет корабли компьютера
    void __fastcall ComputerPrepare();
    // Обрабатывает ход человека (аргумент - корабль, на котором щелкнули)
    void __fastcall ManStep(TShip*);
    // Ход компьютера
    void __fastcall ComputerStep();
    // Ничья
    void __fastcall Tie();
    // Выигрыш человека
    void __fastcall ManWin();
    // Выигрыш компьютера
    void __fastcall ComputerWin();
    // Проверка, на выигрыш/проигрыш
    // Возвращает 1 если кто-то выиграл, или ничья, else 0
    int __fastcall CheckWinOrLose();
    // Обновляет счет
    void __fastcall UpdateScore();
};
//---------------------------------------------------------------------------
extern PACKAGE TMbForm *MbForm;
//---------------------------------------------------------------------------
#endif
