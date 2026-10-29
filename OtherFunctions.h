//---------------------------------------------------------------------------
#include <ComCtrls.hpp>
#include "MapManager.h"
#include "TMapManager.h"
#ifndef OtherFunctionsH
#define OtherFunctionsH

//---------------------------------------------------------------------------

AnsiString __fastcall GetTotals(TListView *TmpListView, int SubCol);
///void __fastcall MakeListViewTable(AnsiString Table, TListView *TmpListView, int ReqCols, AnsiString GameTag, bool ColArrange);
AnsiString __fastcall LoadSettings(TMapManager* TmpMM1);
//void __fastcall LoadMaps(TListView *TmpListView, AnsiString FileDiscription, ProgramData *TmpSettings);
//void __fastcall LoadArchives(TListView *TmpListView, AnsiString FileDiscription, ProgramData *TmpSettings);
//void __fastcall RenameFiles(TStrings* FileList, ProgramData *TmpSettings); 
// new and inproved functions
void __fastcall LoadRegistryData(TStringList *DataItems, AnsiString Section, AnsiString GameTag);
void __fastcall GetFiles(TStrings* Files, AnsiString Location, bool SubFolders);
AnsiString __fastcall LogSafeNameToFile(AnsiString FileName);
AnsiString __fastcall LogSafeNameFromFile(AnsiString FileName);
AnsiString __fastcall ManuallyRenameFile(AnsiString FileName);
void __fastcall FindStr(AnsiString Str, TListView *TmpListView, int Col, TStrings* FileList);
AnsiString __fastcall GetGameType(AnsiString TmpString, AnsiString MapName);
//void __fastcall DisplayMapsOnFrom(TListView *TmpListView, TStrings* FileStrings, bool LogVerfy, int Progress, AnsiString LogFile, AnsiString GameTag);
//TMM_FileInfoData GetDataFromDisplayStr(AnsiString MainString);
bool ValidMapDisplayString(AnsiString TmpString);

//---------------------------------------------------------------------------
#endif
