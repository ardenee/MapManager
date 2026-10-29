//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "MapManager.h"
#include "SearchForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
    Files = new TMMFileList();
    ListView1->Items->Count = Files->Count;
}
//---------------------------------------------------------------------------
__fastcall TForm2::~TForm2()
{
    delete Files;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SaveToFile1Click(TObject *Sender)
{
    SaveDialog1->Options.Clear();
    SaveDialog1->Options << ofOverwritePrompt << ofPathMustExist;
    SaveDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
    SaveDialog1->FilterIndex = 1; // start the dialog showing all files
    SaveDialog1->DefaultExt = "txt";

    if(SaveDialog1->Execute())
    {
        TStrings* Data = new TStringList;

        for(int i=0;i<ListView1->Items->Count;i++)
            Data->Add(ListView1->Items->Item[i]->SubItems->Strings[3] + "|" +
                      ListView1->Items->Item[i]->SubItems->Strings[0] + "|" +
                      ListView1->Items->Item[i]->SubItems->Strings[1] + "|" +
                      ListView1->Items->Item[i]->SubItems->Strings[2]);

        Data->SaveToFile(SaveDialog1->FileName);     
        delete Data;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DisplayInfo1Click(TObject *Sender)
{
    TItemStates selected = TItemStates() << isSelected;
    TListItem* Item      = ListView1->Selected;

    if(Item)
        Form1->MapManager1->Maps->GetFileData(Item->SubItems->Strings[3] + Item->SubItems->Strings[0]);
}
//---------------------------------------------------------------------------  
void __fastcall TForm2::RemoveSelected1Click(TObject *Sender)
{
    TStrings* NumberList = new TStringList();
    TItemStates selected = TItemStates() << isSelected;
    TListItem* Item      = ListView1->Selected;

    while(Item)
    {   // remove the items 1 by 1 so decreese their index as their being removed for valid removint of the right items
        NumberList->Add(Item->Index-NumberList->Count);
        Item = ListView1->GetNextItem(Item, sdAll, selected);
    }

    // 2-1-07
			// for(int i=0;i<NumberList->Count;i++)
    //    Files->Delete(NumberList->Strings[i].ToInt());

    ListView1->Items->Count = Files->Count;
    Label4->Caption = ListView1->Items->Count;
    ListView1->Refresh();
    delete NumberList;  
}
//---------------------------------------------------------------------------  
void __fastcall TForm2::AddFiles(TMMFileList* files)
{
    // 2-1-07
			// Files->Clear();
    Files->Copy(files);
    ListView1->Items->Count = Files->Count;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ListView1Data(TObject *Sender, TListItem *Item)
{   
    Item->Caption = (Item->Index+1);
    PFileInfo fileData = Files->Files[Item->Index];

    if(fileData)
    {
        Item->SubItems->Append(fileData->FileName);
        Item->SubItems->Append(fileData->FileSize);
        Item->SubItems->Append(fileData->FileDate);
        Item->SubItems->Append(fileData->FileLocation);
        Item->SubItemImages[0] = Form1->MapManager1->DisplayFiles->GetFileIcon(ExtractFileExt(fileData->FileName));
        Item->Indent = -1;
    }
}
//---------------------------------------------------------------------------


