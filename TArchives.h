//---------------------------------------------------------------------------
#ifndef TArchivesH
#define TArchivesH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "TFiles.h"
#include "InstallArchiveThread.h"
//---------------------------------------------------------------------------
class TArchives : public TPersistent
{
private:
    TFiles*               FFiles;
    TMMFileList*            FFileList;
    TStrings*             FArchiveTypes;
    TStrings*             FArchiveFilters;
    InstallArchiveThread* FInstallFiles;
    TMMFileInsEvent       FOnFileInstalled;
    TMMArchiveInsEvent    FOnArchiveInstalled;
    TMMGotInfoEvent       FOnGotFileInfo;
    TMM_LoadFilesType     FLoadArchivesType;
    void __fastcall SetArchives                   (TArchives*        Value);
    void __fastcall SetLoadArchivesType           (TMM_LoadFilesType Value);
    void __fastcall SetStringLists                (const int         Index,       TStrings*               Value);
    int  __fastcall GetArchiveFuncType            (AnsiString        ArchiveExt);
    void __fastcall GetZipInfo                    (AnsiString        FileName);
    void __fastcall GetRarInfo                    (AnsiString        FileName);
    void __fastcall GetUmodInfo                   (AnsiString        FileName);
    void __fastcall GetUzInfo                     (AnsiString        FileName);
    void __fastcall DFUnRar1FileProcessing        (TObject*          Sender,       const TDFRARHeaderData &hdrData, int status); // event for get info function on rar files
public:
    __fastcall TArchives(TFiles* Owner);
    __fastcall ~TArchives();
    void       __fastcall Install                 (PFileList         pFileList);
    void       __fastcall StopInstalling          ();
    void       __fastcall GetArchiveInfo          (AnsiString        FileName);
    void       __fastcall OnFileInstalledEvent    (TObject*          Sender,       AnsiString             FileName, AnsiString ArchiveName);
    void       __fastcall OnArchiveInstalledEvent (TObject*          Sender,       AnsiString             Archive);
    // wrapers for the TFiles class
    void       __fastcall UninstallArchives       (PFileList         pArchiveList);
    void       __fastcall RenameArchives          (PFileList         pArchiveList);
    void       __fastcall DeleteArchives          (PFileList         pArchiveList);
    void       __fastcall FindArchives            (PFileList         pArchiveList, AnsiString             pSubString);
    AnsiString __fastcall GetArchiveType          (AnsiString        pMapFilter);
    void       __fastcall GetArchives             ();
    void       __fastcall GetArchiveTypes         ();
    void       __fastcall GetArchiveFilters       ();
__published:
    __property TMMFileInsEvent    OnFileInstalled    = {read=FOnFileInstalled,    write=FOnFileInstalled};
    __property TMMArchiveInsEvent OnArchiveInstalled = {read=FOnArchiveInstalled, write=FOnArchiveInstalled};
    __property TMMGotInfoEvent    OnGotFileInfo      = {read=FOnGotFileInfo,      write=FOnGotFileInfo};
    __property TMM_LoadFilesType  LoadArchivesType   = {read=FLoadArchivesType,   write=SetLoadArchivesType};
    __property TStrings*          ArchiveTypes       = {read=FArchiveTypes,       write=SetStringLists, index=0};
    __property TStrings*          ArchiveFilters     = {read=FArchiveFilters,     write=SetStringLists, index=1};
};
#endif
