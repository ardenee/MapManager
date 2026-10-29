object Form4: TForm4
  Left = 1472
  Top = 462
  Caption = 'Settings'
  ClientHeight = 355
  ClientWidth = 529
  Color = clBtnFace
  Constraints.MaxHeight = 394
  Constraints.MaxWidth = 545
  Constraints.MinHeight = 394
  Constraints.MinWidth = 545
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 521
    Height = 313
    ActivePage = TabSheet4
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = '  General  '
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox1: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label1: TLabel
          Left = 16
          Top = 20
          Width = 34
          Height = 13
          Caption = 'Game :'
        end
        object Label2: TLabel
          Left = 16
          Top = 52
          Width = 66
          Height = 13
          Caption = 'Game Folder :'
        end
        object Label3: TLabel
          Left = 16
          Top = 84
          Width = 58
          Height = 13
          Caption = 'Game EXE :'
        end
        object Label4: TLabel
          Left = 16
          Top = 212
          Width = 64
          Height = 13
          Caption = 'Game Mode :'
        end
        object Label5: TLabel
          Left = 16
          Top = 116
          Width = 61
          Height = 13
          Caption = 'Server EXE :'
        end
        object Label6: TLabel
          Left = 16
          Top = 148
          Width = 47
          Height = 13
          Caption = 'User File :'
        end
        object Label7: TLabel
          Left = 16
          Top = 180
          Width = 64
          Height = 13
          Caption = 'Game String :'
        end
        object ComboBox1: TComboBox
          Left = 104
          Top = 16
          Width = 377
          Height = 21
          Style = csDropDownList
          TabOrder = 0
          OnChange = ComboBox1Change
        end
        object Edit1: TEdit
          Left = 104
          Top = 48
          Width = 257
          Height = 21
          TabOrder = 1
        end
        object Button1: TButton
          Left = 456
          Top = 48
          Width = 25
          Height = 25
          Caption = '...'
          TabOrder = 2
          OnClick = Button1Click
        end
        object Button6: TButton
          Left = 376
          Top = 48
          Width = 75
          Height = 25
          Caption = 'Auto Load'
          TabOrder = 3
          OnClick = Button6Click
        end
        object CheckBox1: TCheckBox
          Left = 16
          Top = 240
          Width = 97
          Height = 17
          Caption = 'Color Code Text'
          TabOrder = 4
          OnClick = CheckBox1Click
        end
        object CheckBox2: TCheckBox
          Left = 224
          Top = 240
          Width = 97
          Height = 17
          Caption = 'Colume Arrange'
          TabOrder = 5
          OnClick = CheckBox2Click
        end
        object CheckBox3: TCheckBox
          Left = 392
          Top = 240
          Width = 97
          Height = 17
          Caption = 'Filter Required'
          TabOrder = 6
          OnClick = CheckBox3Click
        end
        object Edit2: TEdit
          Left = 104
          Top = 80
          Width = 337
          Height = 21
          TabOrder = 7
        end
        object ComboBox2: TComboBox
          Left = 104
          Top = 208
          Width = 137
          Height = 21
          Style = csDropDownList
          TabOrder = 8
          OnChange = ComboBox2Change
          Items.Strings = (
            'MM_GM_Game'
            'MM_GM_Server')
        end
        object Edit3: TEdit
          Left = 104
          Top = 112
          Width = 337
          Height = 21
          TabOrder = 9
        end
        object Edit4: TEdit
          Left = 104
          Top = 144
          Width = 337
          Height = 21
          TabOrder = 10
        end
        object Edit5: TEdit
          Left = 104
          Top = 176
          Width = 377
          Height = 21
          TabOrder = 11
        end
        object Button2: TButton
          Left = 456
          Top = 80
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 12
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 456
          Top = 112
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 13
          OnClick = Button3Click
        end
        object Button8: TButton
          Left = 456
          Top = 144
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 14
          OnClick = Button8Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = '  Maps  '
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox2: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label8: TLabel
          Left = 16
          Top = 20
          Width = 59
          Height = 13
          Caption = 'Map Folder :'
        end
        object Label20: TLabel
          Left = 16
          Top = 52
          Width = 32
          Height = 13
          Caption = 'Maps :'
        end
        object Edit6: TEdit
          Left = 104
          Top = 16
          Width = 337
          Height = 21
          TabOrder = 0
        end
        object CheckBox4: TCheckBox
          Left = 16
          Top = 80
          Width = 121
          Height = 17
          Caption = 'Search SubFolders'
          TabOrder = 1
          OnClick = CheckBox4Click
        end
        object Button5: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 2
          OnClick = Button5Click
        end
        object Edit13: TEdit
          Left = 104
          Top = 48
          Width = 337
          Height = 21
          TabOrder = 3
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = '  Archives  '
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox3: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label9: TLabel
          Left = 16
          Top = 20
          Width = 74
          Height = 13
          Caption = 'Archive Folder :'
        end
        object Label10: TLabel
          Left = 16
          Top = 52
          Width = 63
          Height = 13
          Caption = 'Install Mode :'
        end
        object Label11: TLabel
          Left = 16
          Top = 84
          Width = 60
          Height = 13
          Caption = 'Install Type :'
        end
        object Label14: TLabel
          Left = 16
          Top = 116
          Width = 73
          Height = 13
          Caption = 'Smart Backup :'
        end
        object Label15: TLabel
          Left = 16
          Top = 148
          Width = 88
          Height = 13
          Caption = 'Archives Loading :'
        end
        object Edit7: TEdit
          Left = 104
          Top = 16
          Width = 337
          Height = 21
          TabOrder = 0
        end
        object CheckBox5: TCheckBox
          Left = 16
          Top = 200
          Width = 121
          Height = 17
          Caption = 'Search SubFolders'
          TabOrder = 1
          OnClick = CheckBox5Click
        end
        object ComboBox3: TComboBox
          Left = 112
          Top = 48
          Width = 145
          Height = 21
          Style = csDropDownList
          TabOrder = 2
          OnChange = ComboBox3Change
          Items.Strings = (
            'MM_IM_None'
            'MM_IM_Smart'
            'MM_IM_Force')
        end
        object ComboBox4: TComboBox
          Left = 112
          Top = 80
          Width = 145
          Height = 21
          Style = csDropDownList
          TabOrder = 3
          OnChange = ComboBox4Change
          Items.Strings = (
            'MM_IT_KeepFolders'
            'MM_IT_DropFolders'
            'MM_IT_CleaverKeepFolders'
            'MM_IT_CleaverDropFolders')
        end
        object CheckBox9: TCheckBox
          Left = 16
          Top = 224
          Width = 97
          Height = 17
          Caption = 'Smart Uninstall'
          TabOrder = 4
          OnClick = CheckBox9Click
        end
        object ComboBox6: TComboBox
          Left = 112
          Top = 112
          Width = 145
          Height = 21
          Style = csDropDownList
          TabOrder = 5
          OnChange = ComboBox6Change
          Items.Strings = (
            'MM_SB_DoNothing'
            'MM_SB_RenameFile')
        end
        object ComboBox7: TComboBox
          Left = 112
          Top = 144
          Width = 145
          Height = 21
          Style = csDropDownList
          TabOrder = 6
          OnChange = ComboBox7Change
          Items.Strings = (
            'MM_LAT_None'
            'MM_LAT_Validate'
            'MM_LAT_Filter'
            'MM_LAT_ValidateAndFilter')
        end
        object Button4: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 7
          OnClick = Button4Click
        end
        object CheckBox6: TCheckBox
          Left = 16
          Top = 176
          Width = 153
          Height = 17
          Caption = 'Smart Game Type Install'
          TabOrder = 8
          OnClick = CheckBox6Click
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = '  Cache  '
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox4: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label12: TLabel
          Left = 16
          Top = 20
          Width = 69
          Height = 13
          Caption = 'Cache Folder :'
        end
        object Label13: TLabel
          Left = 16
          Top = 84
          Width = 67
          Height = 13
          Caption = 'Cache Mode :'
        end
        object Label24: TLabel
          Left = 16
          Top = 52
          Width = 56
          Height = 13
          Caption = 'Cache File :'
        end
        object Edit8: TEdit
          Left = 104
          Top = 16
          Width = 337
          Height = 21
          TabOrder = 0
        end
        object ComboBox5: TComboBox
          Left = 104
          Top = 80
          Width = 145
          Height = 21
          Style = csDropDownList
          TabOrder = 1
          OnChange = ComboBox5Change
          Items.Strings = (
            'MM_CM_None'
            'MM_CM_Smart'
            'MM_CM_Force'
            'MM_CM_Remove'
            'MM_CM_SmartAndRemove'
            'MM_CM_ForceAndRemove')
        end
        object Button7: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 2
          OnClick = Button7Click
        end
        object Edit17: TEdit
          Left = 104
          Top = 48
          Width = 337
          Height = 21
          TabOrder = 3
        end
        object Button14: TButton
          Left = 456
          Top = 48
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 4
          OnClick = Button14Click
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = '  Demos  '
      ImageIndex = 4
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox5: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label16: TLabel
          Left = 16
          Top = 20
          Width = 71
          Height = 13
          Caption = 'Demos Folder :'
        end
        object Label25: TLabel
          Left = 16
          Top = 52
          Width = 54
          Height = 13
          Caption = 'Demos Ext:'
        end
        object Edit9: TEdit
          Left = 104
          Top = 16
          Width = 337
          Height = 21
          TabOrder = 0
        end
        object Button9: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = Button9Click
        end
        object Edit18: TEdit
          Left = 104
          Top = 48
          Width = 337
          Height = 21
          TabOrder = 2
        end
      end
    end
    object TabSheet6: TTabSheet
      Caption = '  Screen Shots  '
      ImageIndex = 5
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox6: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label17: TLabel
          Left = 16
          Top = 20
          Width = 99
          Height = 13
          Caption = 'ScreenShots Folder :'
        end
        object Label26: TLabel
          Left = 16
          Top = 52
          Width = 80
          Height = 13
          Caption = 'ScreenShot Ext :'
        end
        object Edit10: TEdit
          Left = 120
          Top = 16
          Width = 321
          Height = 21
          TabOrder = 0
        end
        object Button10: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = Button10Click
        end
        object Edit19: TEdit
          Left = 120
          Top = 48
          Width = 321
          Height = 21
          TabOrder = 2
        end
      end
    end
    object TabSheet7: TTabSheet
      Caption = '  Music  '
      ImageIndex = 6
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox7: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label18: TLabel
          Left = 16
          Top = 20
          Width = 66
          Height = 13
          Caption = 'Music Folder :'
        end
        object Label27: TLabel
          Left = 16
          Top = 52
          Width = 52
          Height = 13
          Caption = 'Music Ext :'
        end
        object Edit11: TEdit
          Left = 104
          Top = 16
          Width = 337
          Height = 21
          TabOrder = 0
        end
        object Button11: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = Button11Click
        end
        object Edit20: TEdit
          Left = 104
          Top = 48
          Width = 337
          Height = 21
          TabOrder = 2
        end
      end
    end
    object TabSheet8: TTabSheet
      Caption = '  Textures  '
      ImageIndex = 7
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox8: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label19: TLabel
          Left = 16
          Top = 20
          Width = 79
          Height = 13
          Caption = 'Textures Folder :'
        end
        object Label28: TLabel
          Left = 16
          Top = 52
          Width = 65
          Height = 13
          Caption = 'Textures Ext :'
        end
        object Edit12: TEdit
          Left = 104
          Top = 16
          Width = 337
          Height = 21
          TabOrder = 0
        end
        object Button12: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = Button12Click
        end
        object Edit21: TEdit
          Left = 104
          Top = 48
          Width = 337
          Height = 21
          TabOrder = 2
        end
      end
    end
    object TabSheet9: TTabSheet
      Caption = '  Logs  '
      ImageIndex = 8
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox9: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label21: TLabel
          Left = 16
          Top = 20
          Width = 48
          Height = 13
          Caption = 'Logs File :'
        end
        object Edit14: TEdit
          Left = 104
          Top = 16
          Width = 337
          Height = 21
          TabOrder = 0
        end
        object Button13: TButton
          Left = 456
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = Button13Click
        end
      end
    end
    object TabSheet10: TTabSheet
      Caption = '  More General  '
      ImageIndex = 9
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox10: TGroupBox
        Left = 8
        Top = 8
        Width = 497
        Height = 273
        TabOrder = 0
        object Label22: TLabel
          Left = 16
          Top = 20
          Width = 47
          Height = 13
          Caption = 'Reg Key :'
        end
        object Label23: TLabel
          Left = 16
          Top = 52
          Width = 56
          Height = 13
          Caption = 'Game Tag :'
        end
        object Edit15: TEdit
          Left = 104
          Top = 16
          Width = 377
          Height = 21
          ReadOnly = True
          TabOrder = 0
        end
        object Edit16: TEdit
          Left = 104
          Top = 48
          Width = 377
          Height = 21
          ReadOnly = True
          TabOrder = 1
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 336
    Width = 529
    Height = 19
    Panels = <>
    ExplicitTop = 321
    ExplicitWidth = 537
  end
  object MainMenu1: TMainMenu
    Left = 416
    Top = 248
    object File1: TMenuItem
      Caption = 'File'
      object Save1: TMenuItem
        Caption = 'Save'
        object ToFile1: TMenuItem
          Caption = 'To File'
          OnClick = ToFile1Click
        end
      end
      object Load1: TMenuItem
        Caption = 'Load'
        object FromFile1: TMenuItem
          Caption = 'From File'
          OnClick = FromFile1Click
        end
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Close1: TMenuItem
        Caption = 'Close'
        OnClick = Close1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 480
    Top = 248
  end
  object SaveDialog1: TSaveDialog
    Left = 448
    Top = 248
  end
end
