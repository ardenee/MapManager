object Form2: TForm2
  Left = 1482
  Top = 786
  Caption = 'Search'
  ClientHeight = 272
  ClientWidth = 522
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 530
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
    522
    272)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 505
    Height = 257
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = '  Search Results  '
    TabOrder = 0
    DesignSize = (
      505
      257)
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 70
      Height = 13
      Caption = 'Searched For :'
    end
    object Label2: TLabel
      Left = 8
      Top = 240
      Width = 58
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = 'Total Finds :'
    end
    object Label3: TLabel
      Left = 80
      Top = 24
      Width = 3
      Height = 13
    end
    object Label4: TLabel
      Left = 72
      Top = 240
      Width = 3
      Height = 13
      Anchors = [akLeft, akBottom]
    end
    object ListView1: TListView
      Left = 8
      Top = 40
      Width = 489
      Height = 193
      Anchors = [akLeft, akTop, akRight, akBottom]
      Columns = <>
      GridLines = True
      MultiSelect = True
      OwnerData = True
      ReadOnly = True
      RowSelect = True
      ParentShowHint = False
      PopupMenu = PopupMenu1
      ShowWorkAreas = True
      ShowHint = True
      SmallImages = Form1.ImageList1
      TabOrder = 0
      ViewStyle = vsReport
      OnData = ListView1Data
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 480
    Top = 16
    object DisplayInfo1: TMenuItem
      Caption = '&Display Info'
      OnClick = DisplayInfo1Click
    end
    object SaveToFile1: TMenuItem
      Caption = '&Save To File'
      OnClick = SaveToFile1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object RemoveSelected1: TMenuItem
      Caption = '&Remove Selected'
      OnClick = RemoveSelected1Click
    end
    object UninstallSelected1: TMenuItem
      Caption = '&Uninstall Selected'
    end
    object DeleteSelected1: TMenuItem
      Caption = '&Delete Selected'
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 448
    Top = 16
  end
end
