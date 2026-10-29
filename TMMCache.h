//---------------------------------------------------------------------------
#ifndef TMMCacheH
#define TMMCacheH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <comctrls.hpp>
#include <IniFiles.hpp>
// SQLite
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
#include "TMMFiles.h"
//---------------------------------------------------------------------------
class TMMCache : public TMMFiles
{
private:
	bool              fEpicPackageActive;
	bool 			  fCacheOverRide;
	bool              fCacheRemove;
    AnsiString        fFolder;
    AnsiString        fGameFolder;
	AnsiString        fINIFile;
	UnicodeString     fGameRootFolder;
    TStrings*         fFileTypes;
    TStrings*         fFileFilters;
	TStringList*      fFileDiscriptions;
    TIniFile* 		  pif;
    TNotifyEvent      fOnGotFileInfo;
    TMM_FileIconType  fLastIconInfo;
    TMM_LoadFilesType fLoadFilesType;
	TMMFileListEvent  fOnGotFileList;
	TMM_SmartBackup   fSmartBackup;
    void __fastcall SetLoadFilesType(TMM_LoadFilesType pValue);
    void __fastcall SetStringLists (const int Index, TStrings* pValue);
	void __fastcall FormatFileList(PFileList pFileList);
	TSQLConnection *SQLConnection1;
	TSQLQuery *SQLQuery1;
	//TSQLDataSet *SQLDataSet1;
public:
	__fastcall TMMCache(TMMEventManager* pEventManager);   //default constructor
	__fastcall TMMCache();   //default constructor
    __fastcall ~TMMCache();
    AnsiString __fastcall GetFileType             (AnsiString   pFileFilter);
    void       __fastcall GetAllFileTypesFor      (TStrings* pData, AnsiString   pFileFilter);
    AnsiString __fastcall GetFilterFromDiscription(AnsiString pDiscription);
	void       __fastcall GetFileInfo             (AnsiString   pFile);

	void __fastcall GetCacheFolderFileList(TStrings* FileList);
	UnicodeString __fastcall GetStr1FromCacheString(UnicodeString FileName);
    UnicodeString __fastcall GetStr2FromCacheString(UnicodeString FileName);
	UnicodeString __fastcall GetStr3FromCacheString(UnicodeString FileName);
	UnicodeString __fastcall GetFilesFolder(UnicodeString FileName);


    // wrapers for the TMMFiles class
    void __fastcall MakeListViewTable(TListColumns* pCols);
    void       __fastcall UninstallFiles          (PFileList    pFileList);
    void       __fastcall RenameFiles             (PFileList    pFileList);
    void       __fastcall DeleteFiles             (PFileList    pFileList);
    void       __fastcall GetFiles                ();
    void       __fastcall GetFileTypes            ();
    void       __fastcall GetFileFilters          ();
    void       __fastcall GetFileDiscriptions     ();
    void       __fastcall RefreshSettings         ();
	void       __fastcall GetFileData             (AnsiString pFileName);
	UnicodeString       __fastcall GetINIFileName          (AnsiString pFileName);
    // virtual in TFiles
    int        __fastcall GetFileIcon             (AnsiString pFileExt);
    // Events
    void       __fastcall OnGotFileListEvent      (TObject *Sender, PFileList pFileList, TMM_FilesListType plistType);
__published:
	__property bool			     CacheOverRide    = {read=fCacheOverRide,       write=fCacheOverRide};
	__property bool			     CacheRemove      = {read=fCacheRemove,         write=fCacheRemove};
	__property UnicodeString     GameRootFolder   = {read=fGameRootFolder,      write=fGameRootFolder};
	__property AnsiString        Folder           = {read=fFolder,              write=fFolder};
    __property AnsiString        GameFolder       = {read=fGameFolder,          write=fGameFolder};
    __property AnsiString        INIFile          = {read=fINIFile,             write=fINIFile};
	__property TMM_SmartBackup   SmartBackup      = {read=fSmartBackup,         write=fSmartBackup};
	__property TMM_LoadFilesType LoadFilesType    = {read=fLoadFilesType,       write=SetLoadFilesType};
    __property TStrings*         FileTypes        = {read=fFileTypes,           write=SetStringLists, index=0};
    __property TStrings*         FileFilters      = {read=fFileFilters,         write=SetStringLists, index=1};
    __property TStringList*      FileDiscriptions = {read=fFileDiscriptions,    write=SetStringLists, index=2};
    // Events
    __property TNotifyEvent      OnGotFileInfo    = {read=fOnGotFileInfo,       write=fOnGotFileInfo};
    __property TMMFileListEvent  OnGotFileList    = {read=fOnGotFileList,       write=fOnGotFileList};
};
#endif

