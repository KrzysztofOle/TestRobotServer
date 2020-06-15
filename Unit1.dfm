object RobotServer: TRobotServer
  Left = 0
  Top = 0
  Caption = 'RobotServer'
  ClientHeight = 291
  ClientWidth = 633
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 280
    Top = 16
    Width = 49
    Height = 13
    Caption = 'IP robota:'
  end
  object btnStart: TButton
    Left = 40
    Top = 240
    Width = 153
    Height = 33
    Caption = 'START'
    TabOrder = 0
    OnClick = btnStartClick
  end
  object btnStop: TButton
    Left = 199
    Top = 240
    Width = 153
    Height = 33
    Caption = 'STOP'
    TabOrder = 1
    OnClick = btnStopClick
  end
  object btnClear: TButton
    Left = 358
    Top = 240
    Width = 153
    Height = 33
    Caption = 'btnStart'
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 24
    Top = 48
    Width = 577
    Height = 177
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object EditIP: TEdit
    Left = 335
    Top = 8
    Width = 145
    Height = 21
    TabOrder = 4
    Text = '127.0.0.1'
  end
  object IdTCPServer1: TIdTCPServer
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 9200
      end
      item
        IP = '127.0.0.1'
        Port = 9200
      end>
    DefaultPort = 9200
    MaxConnections = 2
    OnConnect = IdTCPServer1Connect
    OnDisconnect = IdTCPServer1Disconnect
    ReuseSocket = rsTrue
    OnExecute = IdTCPServer1Execute
    Left = 552
    Top = 232
  end
  object TimerCommand: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerCommandTimer
    Left = 96
    Top = 8
  end
end
