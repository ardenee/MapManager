//---------------------------------------------------------------------------
#pragma hdrstop
#include <IniFiles.hpp>
#include <Registry.hpp>
#include "TMMLogs_Archives.h"
#include "TMMCache_UT2003.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TMMLogs_Archives::TMMLogs_Archives()
    : TMMLogs()
{
    Section = "";
}
//----------------------------------------------------------------------------
__fastcall TMMLogs_Archives::~TMMLogs_Archives()
{
}
//----------------------------------------------------------------------------
void __fastcall TMMLogs_Archives::SetStringValue(const int Index, const AnsiString Value)
{
    switch(Index)
    {
        case 0 : FSection  = Value; break;
    }
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
int __fastcall TMMLogs_Archives::GetArchiveList(TStrings *FileList)
{

    return FileList->Count;
}
//----------------------------------------------------------------------------
int __fastcall TMMLogs_Archives::GetLogStrings(TStrings *StringsList)
{

     return 0;//FileList->Count;
}
//----------------------------------------------------------------------------
