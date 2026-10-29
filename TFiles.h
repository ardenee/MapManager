//---------------------------------------------------------------------------
#ifndef TFilesH
#define TFilesH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "TLogs.h"
#include "GetFilesThread.h"
#include "RenameFilesThread.h"
//---------------------------------------------------------------------------
class TFiles : public TLogs
{
private:
    PFileList        FFileList;
    TMMFileListEvent FOnGotFileList;
    TMMFileListEvent FOnGotCacheFileList;
    TMMFileRenEvent  FOnFileRenamed;
    TMMFilesRenEvent FOnFilesRenamed;
    TMMFileDelEvent  FOnFileDeleted;
    TMMFilesDelEvent FOnFilesDeleted;
    TMMSFileUniEvent FOnSFileUninstalled;
    TMMFileUniEvent  FOnFileUninstalled;
    TMMFilesUniEvent FOnFilesUninstalled;
    TMMStrEvent      FOnFileAdded;
    void       __fastcall PlayMap        (AnsiString FileName);
    int        __fastcall GetFileType    (AnsiString pFileExtension);
    AnsiString __fastcall GetMapGameType (AnsiString FileName);
public:
    __fastcall TFiles();
    __fastcall ~TFiles();
    void       __fastcall UninstallFiles          (PFileList  pList);
    void       __fastcall SmartInstallUninstall   (PFileInfo  fileData);
    void       __fastcall DeleteFiles             (PFileList  List);
    int        __fastcall GetFileIcon             (AnsiString ArchiveExt);
    AnsiString __fastcall GetFileSize             (AnsiString fileName);
    void       __fastcall GetFileList             (AnsiString pFileFolder, bool       pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings*  pFileFilters, TStrings*  pFileTypes);
    void       __fastcall GetFileInfo             (AnsiString pFileName,   PFileInfo  &fileData);
    TMM_FileInfo   __fastcall GetFileInfo             (AnsiString pFileName,   TMM_FileInfo   fileData);
    AnsiString __fastcall GetFileFolder           (AnsiString ArchiveExt);
    void       __fastcall GetCacheFileList        (AnsiString pFileFolder, bool       pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings*  pFileFilters, TStrings*  pFileTypes);
    AnsiString __fastcall GetFileTypeFromFilter   (AnsiString pFilter,     AnsiString RegKey);
    bool       __fastcall IsArchive               (AnsiString FileExt);
    bool       __fastcall IsSameFile              (PFileInfo  fileData,    AnsiString fileName);
    bool       __fastcall CompareFiles            (AnsiString pFileDate,   AnsiString pFileSize,   AnsiString        pFileName);
    bool       __fastcall CompareFiles            (AnsiString pFileDate,   AnsiString pFileSize,   AnsiString        pFileName,      AnsiString pFileDate2,   AnsiString pFileSize2);
    bool       __fastcall ManuallyRenameFile      (AnsiString pOldName,    AnsiString pNewName);
    void       __fastcall FindFile                (PFileList  List,        AnsiString SubString);
    void       __fastcall OpenFile                (AnsiString FileName);
    void       __fastcall RenameFiles             (PFileList  pFileList);
    void       __fastcall OnGotFileListEvent      (TObject*   Sender,      PFileList pFileList);
    void       __fastcall OnGotCacheFileListEvent (TObject*   Sender,      PFileList pFileList);
    void       __fastcall OnFilesRenamedEvent     (TObject*   Sender);
    void       __fastcall OnFileRenamedEvent      (TObject*   Sender,      AnsiString OldName,     AnsiString NewName);
    void       __fastcall OnFilesDeletedEvent     (TObject*   Sender);
    void       __fastcall OnFileDeletedEvent      (TObject*   Sender,      AnsiString FileName);
    void       __fastcall OnFileUninstalledEvent  (TObject*   Sender,      AnsiString FileName,    AnsiString ArchiveName);
    void       __fastcall OnFilesUninstalledEvent (TObject*   Sender,      PFileList  List);
    void       __fastcall OnFileAddedEvent        (TObject*   Sender,      AnsiString FileName);
__published:
    __property TMMFileListEvent     OnGotFileList      = {read=FOnGotFileList,      write=FOnGotFileList};
    __property TMMFileListEvent     OnGotCacheFileList = {read=FOnGotCacheFileList, write=FOnGotCacheFileList};
    __property TMMFilesRenEvent     OnFilesRenamed     = {read=FOnFilesRenamed,     write=FOnFilesRenamed};
    __property TMMFileRenEvent      OnFileRenamed      = {read=FOnFileRenamed,      write=FOnFileRenamed};
    __property TMMFilesDelEvent     OnFilesDeleted     = {read=FOnFilesDeleted,     write=FOnFilesDeleted};
    __property TMMFileDelEvent      OnFileDeleted      = {read=FOnFileDeleted,      write=FOnFileDeleted};
    __property TMMFilesUniEvent     OnFilesUninstalled = {read=FOnFilesUninstalled, write=FOnFilesUninstalled};
    __property TMMFileUniEvent      OnFileUninstalled  = {read=FOnFileUninstalled,  write=FOnFileUninstalled};
    __property TMMSFileUniEvent     OnSFileUninstalled = {read=FOnSFileUninstalled, write=FOnSFileUninstalled};
    __property TMMStrEvent          OnFileAdded        = {read=FOnFileAdded,        write=FOnFileAdded };
};
#endif
