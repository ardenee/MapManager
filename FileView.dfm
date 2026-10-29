object Form3: TForm3
  Left = 1483
  Top = 506
  Caption = 'File Info'
  ClientHeight = 261
  ClientWidth = 534
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 550
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
  DesignSize = (
    534
    261)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 523
    Height = 257
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = '  Info  '
    TabOrder = 0
    DesignSize = (
      523
      257)
    object Label1: TLabel
      Left = 8
      Top = 20
      Width = 53
      Height = 13
      Caption = 'File Name :'
    end
    object Label2: TLabel
      Left = 8
      Top = 36
      Width = 45
      Height = 13
      Caption = 'File Size :'
    end
    object Label3: TLabel
      Left = 8
      Top = 52
      Width = 48
      Height = 13
      Caption = 'File Date :'
    end
    object Label4: TLabel
      Left = 72
      Top = 20
      Width = 3
      Height = 13
    end
    object Label5: TLabel
      Left = 72
      Top = 36
      Width = 3
      Height = 13
    end
    object Label6: TLabel
      Left = 72
      Top = 52
      Width = 3
      Height = 13
    end
    object Label7: TLabel
      Left = 296
      Top = 40
      Width = 59
      Height = 13
      Caption = 'File CRC32 :'
    end
    object Label8: TLabel
      Left = 368
      Top = 40
      Width = 3
      Height = 13
    end
    object Label9: TLabel
      Left = 296
      Top = 56
      Width = 45
      Height = 13
      Caption = 'Installed :'
    end
    object Label10: TLabel
      Left = 368
      Top = 56
      Width = 3
      Height = 13
    end
    object Label11: TLabel
      Left = 408
      Top = 56
      Width = 56
      Height = 13
      Caption = 'Archive ID :'
    end
    object Label12: TLabel
      Left = 472
      Top = 56
      Width = 3
      Height = 13
    end
    object ListView1: TListView
      Left = 8
      Top = 72
      Width = 507
      Height = 177
      Anchors = [akLeft, akTop, akRight, akBottom]
      Columns = <
        item
          Caption = 'Num'
          Width = 38
        end
        item
          Caption = 'Name'
          Width = 250
        end
        item
          Caption = 'Value'
          Width = 200
        end>
      GridLines = True
      MultiSelect = True
      ReadOnly = True
      RowSelect = True
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
end
