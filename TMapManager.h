//---------------------------------------------------------------------------
#ifndef TMapManagerH
#define TMapManagerH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "TMMSettings.h"

#include "MMTypes.h"
#include "TMMMaps.h"
#include "TMMMusic.h"
#include "TMMCache.h"
#include "TMMFiles.h"
#include "TMMDemos.h"
#include "TMMArchives.h"
#include "TMMTextures.h"
#include "TMMScreenShots.h"
#include "TMMDisplayFiles.h"
//---------------------------------------------------------------------------
class PACKAGE TMapManager : public TComponent
{
private:
    TMMSettings*        fSettings;
    TMMLogs*            fXMLLogs;
    TMMEventManager*    fEventManager;
    TMMMaps*            fMaps;
    TMMMusic*           fMusic;
    TMMCache*           fCache;
    TMMArchives*        fArchives;
    TMMTextures*        fTextures;
    TMMDemos*           fDemos;
    TMMScreenShots*     fScreenShots;
    TMMDisplayFiles*    fDisplayFiles;
    TMM_FileInfo        AStruct;
    PFileList           fLogList;
    TMMFileDelEvent     FOnFileDeleted;
    TMMFilesDelEvent    FOnFilesDeleted;
    TMMFileUniEvent     FOnFileUninstalled;
    TMMFilesUniEvent    FOnFilesUninstalled;
    TMMFileInsEvent     FOnFileInstalled;
    TMMStrEvent         FOnArchiveInstalled;
    TMMFilesInsEvent    FOnFilesInstalled;
    TMMStrEvent         FOnError;
    TMMGotInfoEvent     FOnGotFileInfo;
    TMMGotPicEvent      FOnGotPicture;
    TMMGotDataListEvent FOnGotDataList;

    TMMLogListEvent     fOnGotLogEntrys;

    TMMFilesRenEvent    FOnFilesRenamed;
    TMMFileRenEvent     FOnFileRenamed;
    AnsiString __fastcall LogSafeNameFromFile (AnsiString      FileName);
    AnsiString __fastcall LogSafeNameToFile   (AnsiString      FileName);
    void       __fastcall SetFileList         (PFileList       Value);
    void       __fastcall SetLogList          (PFileList       Value);
    void       __fastcall SetMaps             (TMMMaps*        Value);
    void       __fastcall SetArchives         (TMMArchives*    Value);
    void       __fastcall SetCache            (TMMCache*       Value);
    void       __fastcall SetFiles            (TMMFiles*       Value);
    void       __fastcall SetMusic            (TMMMusic*       Value);
    void       __fastcall SetTextures         (TMMTextures*    Value);
    void       __fastcall SetDemos            (TMMDemos*       Value);
    void       __fastcall SetScreenShots      (TMMScreenShots* Value);
    void       __fastcall SetSettings         (TMMSettings*    Value);
protected:
public:
    __fastcall TMapManager(TComponent* Owner);
    __fastcall ~TMapManager();
    void __fastcall MakeListMenu(TStrings* MenuItems, int MenuType);
    AnsiString  __fastcall GetMenuType             (const int  Value);
    AnsiString  __fastcall GetFileType             (AnsiString FileDescription, AnsiString RegSection);
    bool        __fastcall GetFileDataFromString   (AnsiString FileDataString);
    bool        __fastcall ValidDataString         (AnsiString DataString,      TMM_StringType value);
    bool        __fastcall GetRegistryValueData    (const int  MenuType,        TStrings*      MenuItems,   bool       DelDoubles,  AnsiString ExtraSection);
    bool        __fastcall GetRegistryValues       (const int  MenuType,        TStrings*      MenuItems,   AnsiString ExtraSection);
    bool        __fastcall MakeListViewTable       (TListView* TmpListView,     const int      TableType);
    void        __fastcall OnFileDeletedEvent      (TObject*   Sender,          AnsiString     Value);
    void        __fastcall OnFilesDeletedEvent     (TObject*   Sender,          PFileList      List);
    void        __fastcall OnFilesUninstalledEvent (TObject*   Sender,          PFileList      List);
    void        __fastcall OnFileUninstalledEvent  (TObject*   Sender,          AnsiString     FileName,    AnsiString ArchiveName);
    void        __fastcall OnFileInstalledEvent    (TObject*   Sender,          AnsiString     ArchiveName, AnsiString FileName);
    void        __fastcall OnFilesInstalledEvent   (TObject*   Sender,          PFileList      List,        int        Installed);
    void        __fastcall OnErrorEvent            (TObject*   Sender,          AnsiString     Value);
    void        __fastcall OnArchiveInstalledEvent (TObject*   Sender,          AnsiString     Value);
    void        __fastcall OnGotFileInfoEvent      (TObject*   Sender,          PFileList      List);
    void        __fastcall OnGotPicEvent           (TObject*   Sender,          TPicture*      Picture);
    void        __fastcall OnGotLogEntrysEvent     (TObject*   Sender,          PFileList      LogList);
    TMM_ColInfo __fastcall GetColInfo              (AnsiString pColName,        AnsiString     pTableName);
    AnsiString  __fastcall GetDisplayFilters       (TStrings*  pFilterList, int MenuType);
    void        __fastcall OnFilesRenamedEvent     (TObject *Sender);
    void        __fastcall OnFileRenamedEvent      (TObject *Sender, AnsiString OldName, AnsiString NewName);
    void        __fastcall OnGotFielDataEvent      (TObject *Sender, TStrings* pFileData);

    int  __fastcall GetFileIcon            (AnsiString FileExt); // virtual in TFiles
__published:
    __property TMMMaps*         Maps               = {read=fMaps,               write=SetMaps};
    __property TMMMusic*        Music              = {read=fMusic,              write=SetMusic};
    __property TMMDemos*        Demos              = {read=fDemos,              write=SetDemos};
    __property TMMCache*        Cache              = {read=fCache,              write=SetCache};
    __property TMMArchives*     Archives           = {read=fArchives,           write=SetArchives};
    __property TMMTextures*     Textures           = {read=fTextures,           write=SetTextures};
    __property TMMScreenShots*  ScreenShots        = {read=fScreenShots,        write=SetScreenShots};
  //  __property PFileList        LogList            = {read=fLogList,            write=SetLogList};
    __property TMMFileDelEvent  OnFileDeleted      = {read=FOnFileDeleted,      write=FOnFileDeleted};
    __property TMMFilesDelEvent OnFilesDeleted     = {read=FOnFilesDeleted,     write=FOnFilesDeleted};
    __property TMMFileUniEvent  OnFileUninstalled  = {read=FOnFileUninstalled,  write=FOnFileUninstalled};
    __property TMMFilesUniEvent OnFilesUninstalled = {read=FOnFilesUninstalled, write=FOnFilesUninstalled};
    __property TMMFilesInsEvent OnFilesInstalled   = {read=FOnFilesInstalled,   write=FOnFilesInstalled};
    __property TMMFileInsEvent  OnFileInstalled    = {read=FOnFileInstalled,    write=FOnFileInstalled};
    __property TMMStrEvent      OnArchiveInstalled = {read=FOnArchiveInstalled, write=FOnArchiveInstalled};
    __property TMMStrEvent      OnError            = {read=FOnError,            write=FOnError};
    __property TMMGotInfoEvent  OnGotFileInfo      = {read=FOnGotFileInfo,      write=FOnGotFileInfo};
    __property TMMGotPicEvent   OnGotPicture       = {read=FOnGotPicture,       write=FOnGotPicture};
    __property TMMLogListEvent  OnGotLogEntrys     = {read=fOnGotLogEntrys,     write=fOnGotLogEntrys};
    __property TMMEventManager* EventManager       = {read=fEventManager,       write=fEventManager};
    __property TMMSettings*     Settings           = {read=fSettings,           write=SetSettings};
    __property TMMDisplayFiles* DisplayFiles       = {read=fDisplayFiles,       write=fDisplayFiles};
    __property TMMFilesRenEvent OnFilesRenamed     = {read=FOnFilesRenamed,     write=FOnFilesRenamed};
    __property TMMFileRenEvent  OnFileRenamed      = {read=FOnFileRenamed,      write=FOnFileRenamed};
    __property TMMGotDataListEvent OnGotDataList   = {read=FOnGotDataList,      write=FOnGotDataList};

};
//---------------------------------------------------------------------------
#endif

