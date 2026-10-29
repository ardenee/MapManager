//---------------------------------------------------------------------------
#ifndef TMapsH
#define TMapsH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "TFiles.h"
#include "ut_packages.hpp"
//---------------------------------------------------------------------------
class TMaps : public TPersistent
{
private:  
    TStrings*         FMapTypes;
    TStrings*         FMapFilters;
    TFiles*           FFiles;
    TNotifyEvent      FOnGotFileInfo;
    TMMGotPicEvent    FOnGotPicture;
    TMM_LoadFilesType FLoadMapsType;
    void __fastcall SetLoadMapsType (TMM_LoadFilesType Value);
    void __fastcall SetStringLists  (const int         Index, TStrings* Value);
public:
    __fastcall TMaps(TFiles* Owner);
    __fastcall ~TMaps();
    AnsiString __fastcall GetMapGameType    (AnsiString   FileName);
    AnsiString __fastcall GetMapType        (AnsiString   pMapFilter);
    AnsiString __fastcall GetPictureClass   (TMM_GameType Type);
    bool       __fastcall GetPicture        (AnsiString   FileName);
    void       __fastcall GetMapInfo        (AnsiString   pMap);
    // wrapers for the TFiles class
    void       __fastcall UninstallMaps     (PFileList    pMapList);
    void       __fastcall RenameMaps        (PFileList    pMapList);
    void       __fastcall DeleteMaps        (PFileList    pMapList);
    void       __fastcall FindMaps          (PFileList    pMapList,   AnsiString pSubString);
    void       __fastcall GetMaps           ();
    void       __fastcall GetMapTypes       ();
    void       __fastcall GetMapFilters     ();
__published:
    __property TNotifyEvent      OnGotFileInfo = {read=FOnGotFileInfo, write=FOnGotFileInfo};
    __property TMMGotPicEvent    OnGotPicture  = {read=FOnGotPicture,  write=FOnGotPicture};
    __property TMM_LoadFilesType LoadMapsType  = {read=FLoadMapsType,  write=SetLoadMapsType};
    __property TStrings*         MapTypes      = {read=FMapTypes,      write=SetStringLists, index=0};
    __property TStrings*         MapFilters    = {read=FMapFilters,    write=SetStringLists, index=1};
};
#endif
