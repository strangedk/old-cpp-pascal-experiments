object MbSettings: TMbSettings
  Left = 607
  Top = 177
  BorderStyle = bsDialog
  Caption = 'Морской Бой'
  ClientHeight = 235
  ClientWidth = 193
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Ok: TTango
    Left = 8
    Top = 208
    Width = 89
    Height = 25
    Caption = 'Ok'
    Color = clBtnFace
    OverColor = clWhite
    OnClick = OkClick
  end
  object Cancel: TTango
    Left = 104
    Top = 208
    Width = 89
    Height = 25
    Caption = 'Cancel'
    Color = clBtnFace
    OverColor = clWhite
    OnClick = CancelClick
  end
  object SettingsBox: TGroupBox
    Left = 0
    Top = 0
    Width = 193
    Height = 121
    TabOrder = 0
    object Label1: TLabel
      Left = 152
      Top = 21
      Width = 17
      Height = 22
      AutoSize = False
      Caption = ' '
      Color = clBtnFace
      ParentColor = False
      OnClick = Label1Click
    end
    object Label2: TLabel
      Left = 88
      Top = 21
      Width = 17
      Height = 22
      AutoSize = False
      Caption = ' '
      Color = clBtnFace
      ParentColor = False
      OnClick = Label2Click
    end
    object Label3: TLabel
      Left = 104
      Top = 8
      Width = 49
      Height = 17
      AutoSize = False
      Caption = ' '
      Color = clBtnFace
      ParentColor = False
      OnClick = Label3Click
    end
    object Label4: TLabel
      Left = 104
      Top = 40
      Width = 49
      Height = 17
      AutoSize = False
      Caption = ' '
      Color = clBtnFace
      ParentColor = False
      OnClick = Label4Click
    end
    object lblMaxShips: TLabel
      Left = 8
      Top = 24
      Width = 82
      Height = 13
      Caption = 'Макс. Кораблей'
    end
    object SpinMaxShips: TCSpinEdit
      Left = 104
      Top = 21
      Width = 49
      Height = 22
      TabStop = True
      MaxValue = 35
      MinValue = 1
      ParentColor = False
      TabOrder = 0
      OnChange = SpinMaxShipsChange
      OnClick = SpinMaxShipsClick
    end
    object isMusic: TCheckBox
      Left = 16
      Top = 64
      Width = 97
      Height = 17
      Caption = 'isMusic'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
    object isSounds: TCheckBox
      Left = 16
      Top = 88
      Width = 97
      Height = 17
      Caption = 'isSounds'
      Checked = True
      State = cbChecked
      TabOrder = 2
    end
  end
  object radioLanguage: TGroupBox
    Left = 0
    Top = 120
    Width = 193
    Height = 81
    Caption = 'Язык интерфейса'
    TabOrder = 1
    object rbRussianLang: TCheckBox
      Left = 16
      Top = 24
      Width = 105
      Height = 17
      Caption = 'Russian'
      TabOrder = 0
      OnClick = rbRussianLangClick
    end
    object rbEnglishLang: TCheckBox
      Left = 16
      Top = 48
      Width = 105
      Height = 17
      Caption = 'English'
      TabOrder = 1
      OnClick = rbEnglishLangClick
    end
  end
end
