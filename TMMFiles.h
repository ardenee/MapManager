//---------------------------------------------------------------------------
#ifndef TMMFilesH
#define TMMFilesH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "TMMLogs.h"
#include "TMMGetFilesThread.h"
#include "TMMRenameThread.h"
#include "TMMEventManager.h"
#include "TMMFileInfoThread.h"
//---------------------------------------------------------------------------
class TMMFiles : public TPersistent
{
private:
	TMMFileInfoThread* fFileDataThread;
	PFileList          fFileList;
	TMMEventManager*   fEventManager;
	TMMFileDelEvent    FOnFileDeleted;
	TMMFilesDelEvent   FOnFilesDeleted;
	TMMSFileUniEvent   FOnSFileUninstalled;
	TMMFileUniEvent    FOnFileUninstalled;
	TMMFilesUniEvent   FOnFilesUninstalled;
	bool               fEventManagerSet;
	void         __fastcall PlayMap        (AnsiString FileName);
	int          __fastcall GetFileType    (AnsiString pFileExtension);
	AnsiString   __fastcall GetMapGameType (AnsiString FileName);
protected:
	void         __fastcall RenameFiles            (PFileList  pFileList, AnsiString pGameTag, TStrings* pFileTypes);
	void         __fastcall GetMapData             (AnsiString pFileName, TMM_GetFileInfoType pAction);
	void         __fastcall GetMusicData           (AnsiString pFileName, TMM_GetFileInfoType pAction);
	void         __fastcall GetTexturesData        (AnsiString pFileName, TMM_GetFileInfoType pAction);
	void         __fastcall GetArchiveData         (AnsiString pFileName, TMM_GetFileInfoType pAction);
	void         __fastcall GetDemosData           (AnsiString pFileName, TMM_GetFileInfoType pAction);
	void         __fastcall GetScreenShotsData     (AnsiString pFileName, TMM_GetFileInfoType pAction);
public:
	__fastcall TMMFiles();
	__fastcall ~TMMFiles();
	bool         __fastcall SetEventManager        (TMMEventManager* pEventManager);
	void         __fastcall UninstallFiles         (PFileList  pList);
	void         __fastcall SmartInstallUninstall  (PFileInfo  fileData);
	void         __fastcall DeleteFiles            (PFileList  List);
	AnsiString   __fastcall GetFileSize            (AnsiString fileName);
	void         __fastcall GetFileList            (AnsiString pFileFolder, bool       pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings*  pFileFilters, TStrings*  pFileTypes, TMM_FilesListType plistType);
	void         __fastcall GetFileInfo            (AnsiString pFileName,   PFileInfo  &fileData);
	TMM_FileInfo __fastcall GetFileInfo            (AnsiString pFileName);
	AnsiString   __fastcall GetFileFolder          (AnsiString ArchiveExt);
	void         __fastcall GetCacheFileList       (AnsiString pFileFolder, bool       pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings*  pFileFilters, TStrings*  pFileTypes);
	AnsiString   __fastcall GetFileTypeFromFilter  (AnsiString pFilter,     AnsiString RegKey);
	bool         __fastcall IsArchive              (AnsiString FileExt);
	bool         __fastcall IsSameFile             (PFileInfo  fileData,    AnsiString fileName);
	bool         __fastcall CompareFiles           (AnsiString pFileDate,   AnsiString pFileSize,   AnsiString        pFileName);
	bool         __fastcall CompareFiles           (AnsiString pFileDate,   AnsiString pFileSize,   AnsiString        pFileName,      AnsiString pFileDate2,   AnsiString pFileSize2);
	bool         __fastcall ManuallyRenameFile     (AnsiString pOldName,    AnsiString pNewName);
	void         __fastcall FindFile               (PFileList List, AnsiString SubString);
	void         __fastcall OpenFile               (AnsiString FileName);
	void         __fastcall OnFilesDeletedEvent    (TObject*   Sender);
	void         __fastcall OnFileDeletedEvent     (TObject*   Sender,      AnsiString FileName);
	void         __fastcall OnFileUninstalledEvent (TObject*   Sender,      AnsiString FileName,    AnsiString ArchiveName);
	void         __fastcall OnFilesUninstalledEvent(TObject*   Sender,      PFileList  List);
	//void         __fastcall GetFileTypes           (TStrings* FileTypes, int FileType);
	void __fastcall GetPicture(AnsiString pFileName);
	// virtual - used in child classes
	virtual int  __fastcall GetFileIcon            (AnsiString FileExt) = 0;
	virtual void __fastcall OnGotFileListEvent     (TObject *Sender, PFileList pFileList, TMM_FilesListType plistType) = 0;
__published:
	__property TMMEventManager*     PEventManager      = {read=fEventManager,       write=fEventManager};
	__property TMMFilesDelEvent     OnFilesDeleted     = {read=FOnFilesDeleted,     write=FOnFilesDeleted};
	__property TMMFileDelEvent      OnFileDeleted      = {read=FOnFileDeleted,      write=FOnFileDeleted};
	__property TMMFilesUniEvent     OnFilesUninstalled = {read=FOnFilesUninstalled, write=FOnFilesUninstalled};
	__property TMMFileUniEvent      OnFileUninstalled  = {read=FOnFileUninstalled,  write=FOnFileUninstalled};
	__property TMMSFileUniEvent     OnSFileUninstalled = {read=FOnSFileUninstalled, write=FOnSFileUninstalled};
	__property bool                 EventManagerSet    = {read=fEventManagerSet,    write=fEventManagerSet};
	__property PFileList         	FileList           = {read=fFileList, write=fFileList};
	//__property PFileList 			FileList[int Index] = {read=GetFile};
	//__property TMMEventManager*     EventManager       = {read=fEventManager,       write=fEventManager};
};
#endif
