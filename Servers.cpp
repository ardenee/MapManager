//---------------------------------------------------------------------------

#include <vcl.h>
#include <winsock2.h>
#pragma hdrstop

#include "Servers.h"
#include "MapManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma warn -pck
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
/*
    TFavoriteData* TmpFavorite = new TFavoriteData;;

    TmpFavorite->ServerPort      = StrToIntDef(Edit2->Text, 0);
    TmpFavorite->ServerQueryPort = StrToIntDef(Edit3->Text, 0);
    TmpFavorite->ServerID        = StrToIntDef(Edit4->Text, 0);
    TmpFavorite->ServerName      = Edit5->Text;

    if(Form1->MapManager1->ValidIP(Edit1->Text))
    {
        TmpFavorite->ServerIP = inet_addr(Edit1->Text.c_str());

        if(Form1->MapManager1->FavoritesAdd(TmpFavorite))
            Form3->Close();
    }
    else
        ShowMessage("Invalid IP Entered");

    delete TmpFavorite;
    */
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button5Click(TObject *Sender)
{
    Form3->Close();    
}
//---------------------------------------------------------------------------







