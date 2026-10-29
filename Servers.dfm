object Form3: TForm3
  Left = 192
  Top = 114
  Width = 435
  Height = 268
  Caption = 'Favorites Editing'
  Color = clBtnFace
  Constraints.MaxHeight = 268
  Constraints.MinHeight = 268
  Constraints.MinWidth = 273
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000010000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
    00000000FFFFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFF00
    00000000FFFFFFFFF00000FFFFFFFFFFFFFFFFFFFFFFFFFF00000FFFFFFFFFFF
    FFFFFFFFFFFFFFF00000FFFFFFFFFF0000000000FFFFFF00000FFFFFFFFFFF00
    00000000FFFFF00000FFFFFFFFFFFF0000000000FFFFF0000FFFFFFFFFFFFFFF
    FFFFFFFFFFFFF000FFFFFFFFFFFFFFFFFFFFFFFFFFFFF000FFFFFFFFFFFFFF00
    00000000FFFFF000FFFFFFFFFFFFFF0000000000FFFFF000000FFFFFFFFFFF00
    00000000FFFFF00000000FFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFF
    FFFFFFFFFFFFFFFFF00000FFFFFFFFFFFFF0000000FFFFFFFFF000FFFFFFFFFF
    FF0000000000FFFFF00000FFFFFFFFFFFF00000000000F00000000FFFFFFFFFF
    FF000FFF0000000000000FFFFFFFFFFFFF000FFFFF00000000FFFFFFFFFFFFFF
    FFF0FFFFFFF00000FFFFFFFFFFFFFFFFFFFFFFFFFFFF000FFFFFFFFFFFFFFFFF
    FFFFFFFFFFFF000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0FFFFFFFFFFFFFFFFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 409
    Height = 217
    Caption = '  Favorites  '
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 8
      Top = 16
      Width = 393
      Height = 193
      ActivePage = TabSheet1
      TabIndex = 0
      TabOrder = 1
      object TabSheet1: TTabSheet
        Caption = '  Add  '
        object Label1: TLabel
          Left = 8
          Top = 12
          Width = 68
          Height = 13
          Caption = 'Server Name :'
        end
        object Label2: TLabel
          Left = 8
          Top = 36
          Width = 50
          Height = 13
          Caption = 'Server IP :'
        end
        object Label3: TLabel
          Left = 8
          Top = 60
          Width = 59
          Height = 13
          Caption = 'Server Port :'
        end
        object Label4: TLabel
          Left = 8
          Top = 84
          Width = 90
          Height = 13
          Caption = 'Server Query Port :'
        end
        object Label5: TLabel
          Left = 8
          Top = 108
          Width = 51
          Height = 13
          Caption = 'Server ID :'
        end
        object Edit1: TEdit
          Left = 112
          Top = 8
          Width = 121
          Height = 21
          MaxLength = 100
          TabOrder = 0
          Text = 'Unknown'
        end
        object Edit2: TEdit
          Left = 112
          Top = 32
          Width = 121
          Height = 21
          MaxLength = 15
          TabOrder = 1
        end
        object Edit3: TEdit
          Left = 112
          Top = 56
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 2
        end
        object Edit4: TEdit
          Left = 112
          Top = 80
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 3
        end
        object Edit5: TEdit
          Left = 112
          Top = 104
          Width = 65
          Height = 21
          MaxLength = 10
          TabOrder = 4
          Text = '0'
        end
        object Button2: TButton
          Left = 224
          Top = 136
          Width = 75
          Height = 25
          Caption = '&Add'
          TabOrder = 5
        end
      end
      object TabSheet2: TTabSheet
        Caption = '  Delete  '
        ImageIndex = 1
        object Label6: TLabel
          Left = 176
          Top = 12
          Width = 68
          Height = 13
          Caption = 'Server Name :'
        end
        object Label7: TLabel
          Left = 176
          Top = 36
          Width = 50
          Height = 13
          Caption = 'Server IP :'
        end
        object Label8: TLabel
          Left = 176
          Top = 60
          Width = 59
          Height = 13
          Caption = 'Server Port :'
        end
        object Label9: TLabel
          Left = 176
          Top = 84
          Width = 56
          Height = 13
          Caption = 'Query Port :'
        end
        object Label10: TLabel
          Left = 176
          Top = 108
          Width = 51
          Height = 13
          Caption = 'Server ID :'
        end
        object ListBox1: TListBox
          Left = 8
          Top = 8
          Width = 161
          Height = 153
          ItemHeight = 13
          TabOrder = 0
        end
        object Edit6: TEdit
          Left = 256
          Top = 32
          Width = 121
          Height = 21
          MaxLength = 15
          TabOrder = 1
        end
        object Edit7: TEdit
          Left = 256
          Top = 56
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 2
        end
        object Edit8: TEdit
          Left = 256
          Top = 8
          Width = 121
          Height = 21
          MaxLength = 100
          TabOrder = 3
        end
        object Button4: TButton
          Left = 224
          Top = 136
          Width = 75
          Height = 25
          Caption = '&Delete'
          TabOrder = 4
        end
        object Edit9: TEdit
          Left = 256
          Top = 80
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 5
        end
        object Edit10: TEdit
          Left = 256
          Top = 104
          Width = 65
          Height = 21
          MaxLength = 10
          TabOrder = 6
        end
      end
      object TabSheet3: TTabSheet
        Caption = '  Edit  '
        ImageIndex = 2
        object Label11: TLabel
          Left = 8
          Top = 12
          Width = 68
          Height = 13
          Caption = 'Server Name :'
        end
        object Label12: TLabel
          Left = 8
          Top = 32
          Width = 50
          Height = 13
          Caption = 'Server IP :'
        end
        object Label13: TLabel
          Left = 8
          Top = 56
          Width = 59
          Height = 13
          Caption = 'Server Port :'
        end
        object Label14: TLabel
          Left = 8
          Top = 80
          Width = 90
          Height = 13
          Caption = 'Server Query Port :'
        end
        object Label15: TLabel
          Left = 8
          Top = 108
          Width = 51
          Height = 13
          Caption = 'Server ID :'
        end
        object Label16: TLabel
          Left = 232
          Top = 12
          Width = 19
          Height = 13
          Caption = 'To :'
        end
        object Label17: TLabel
          Left = 232
          Top = 36
          Width = 19
          Height = 13
          Caption = 'To :'
        end
        object Label18: TLabel
          Left = 232
          Top = 60
          Width = 19
          Height = 13
          Caption = 'To :'
        end
        object Label19: TLabel
          Left = 232
          Top = 84
          Width = 19
          Height = 13
          Caption = 'To :'
        end
        object Label20: TLabel
          Left = 232
          Top = 108
          Width = 19
          Height = 13
          Caption = 'To :'
        end
        object Edit11: TEdit
          Left = 104
          Top = 8
          Width = 121
          Height = 21
          MaxLength = 100
          TabOrder = 0
        end
        object Edit12: TEdit
          Left = 104
          Top = 32
          Width = 121
          Height = 21
          MaxLength = 15
          TabOrder = 1
        end
        object Edit13: TEdit
          Left = 104
          Top = 56
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 2
        end
        object Edit14: TEdit
          Left = 104
          Top = 80
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 3
        end
        object Edit15: TEdit
          Left = 104
          Top = 104
          Width = 65
          Height = 21
          MaxLength = 10
          TabOrder = 4
        end
        object Edit16: TEdit
          Left = 256
          Top = 8
          Width = 121
          Height = 21
          MaxLength = 100
          TabOrder = 5
        end
        object Edit17: TEdit
          Left = 256
          Top = 32
          Width = 121
          Height = 21
          MaxLength = 15
          TabOrder = 6
        end
        object Edit18: TEdit
          Left = 256
          Top = 56
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 7
        end
        object Edit19: TEdit
          Left = 256
          Top = 80
          Width = 65
          Height = 21
          MaxLength = 5
          TabOrder = 8
        end
        object Edit20: TEdit
          Left = 256
          Top = 104
          Width = 65
          Height = 21
          MaxLength = 10
          TabOrder = 9
        end
        object Button1: TButton
          Left = 224
          Top = 136
          Width = 75
          Height = 25
          Caption = '&Update'
          TabOrder = 10
        end
      end
    end
    object Button5: TButton
      Left = 320
      Top = 176
      Width = 75
      Height = 25
      Caption = '&Cancel'
      TabOrder = 0
      OnClick = Button5Click
    end
  end
end
