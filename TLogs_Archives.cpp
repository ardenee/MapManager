//---------------------------------------------------------------------------
#pragma hdrstop
#include <IniFiles.hpp>
#include <Registry.hpp>
#include "TLogs_Archives.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TLogs_Archives::TLogs_Archives()
	: TMMLogs()
{
    Section = "";
}
//----------------------------------------------------------------------------
__fastcall TLogs_Archives::~TLogs_Archives()
{
}
//----------------------------------------------------------------------------
void __fastcall TLogs_Archives::SetStringValue(const int Index, const AnsiString Value)
{
    switch(Index)
    {
        case 0 : FSection  = Value; break;
    }
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
int __fastcall GetArchiveList(TStrings *FileList)
{

    return FileList->Count;
}
//----------------------------------------------------------------------------
int __fastcall GetLogStrings(TStrings *StringsList)
{

     return 0;//FileList->Count;
}
//----------------------------------------------------------------------------
