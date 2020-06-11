object Form1: TForm1
  Left = 192
  Top = 107
  AutoScroll = False
  Caption = 'Form1'
  ClientHeight = 527
  ClientWidth = 776
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 112
    Top = 64
    Width = 305
    Height = 401
    Caption = 'Pause / Play'
    OnClick = SpeedButton1Click
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 8
    Top = 8
  end
end
