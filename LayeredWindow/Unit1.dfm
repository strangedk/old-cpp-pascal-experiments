object Form1: TForm1
  Left = 371
  Top = 226
  Width = 372
  Height = 328
  Caption = 'Form1'
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 252
    Top = 272
    Width = 101
    Height = 25
  end
  object Button1: TButton
    Left = 8
    Top = 272
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
  end
  object Button2: TButton
    Left = 88
    Top = 272
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
  end
  object Button3: TButton
    Left = 168
    Top = 272
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 2
  end
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 349
    Height = 261
    Caption = 'Panel1'
    TabOrder = 3
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 8
    Top = 8
  end
end
