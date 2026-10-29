//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MapManager.h"
#include "FileView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::AddData(TStrings* pData)
{
    ListView1->Items->Clear();
// add map data
    TListItem  *ListItem;

    SetFile(pData->Strings[0]);
    
    for(int i=1;i<pData->Count; i++)
    {
        ListItem = ListView1->Items->Add();
        ListItem->Caption = IntToStr(i);
        ListItem->SubItems->Add(pData->Strings[i].Delete(pData->Strings[i].Pos("|"), pData->Strings[i].Length()));
        ListItem->SubItems->Add(pData->Strings[i].Delete(1, pData->Strings[i].Pos("|")));
    }

    //SetFile(ListView1->Items->Item[4]->SubItems->Strings[1]);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SetFile(AnsiString pFileName)
{
    if(FileExists(pFileName))
    {
        TMM_FileInfo file = Form1->MapManager1->DisplayFiles->GetFileInfo(pFileName);

        Label4->Caption  = file.FileLocation + file.FileName;
        Label5->Caption  = file.FileSize + " Bytes";
        Label6->Caption  = file.FileDate;
        Label8->Caption  = file.CRC32;
		Label10->Caption = file.Installed;
        Label12->Caption = file.BelongsTo;
	}
}
//---------------------------------------------------------------------------
