object Form1: TForm1
  Left = 555
  Top = 371
  BorderStyle = bsNone
  Caption = 'Form'
  ClientHeight = 273
  ClientWidth = 292
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnMouseDown = FormMouseDown
  PixelsPerInch = 96
  TextHeight = 13
  object Timer: TTimer
    Interval = 1
    OnTimer = TimerTimer
  end
end
