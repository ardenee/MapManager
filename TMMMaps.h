//---------------------------------------------------------------------------
#ifndef TMMMapsH
#define TMMMapsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <comctrls.hpp>
#include <Datasnap.DBClient.hpp>
//---------------------------------------------------------------------------
#include "TMMFiles.h"
#include <list>
//---------------------------------------------------------------------------
class TMMMaps : public TMMFiles
{
private:
    bool              fEpicPackageActive;
    bool              fSubFolders;
    AnsiString        fFolder;
    AnsiString        fGameFolder;
    TStrings*         fFileTypes;
    TStrings*         fFileFilters;
    TStrings*         fFileDiscriptions;
    TNotifyEvent      fOnGotFileInfo;
    TMM_FileIconType  fLastIconInfo;
    TMM_LoadFilesType fLoadFilesType;
    TMMFileListEvent  fOnGotFileList;
    void __fastcall SetLoadFilesType(TMM_LoadFilesType pValue);
    void __fastcall SetStringLists (const int Index, TStrings* pValue);
    std::list<TMM_FileInfo> List;
	//TList* MyList;
	TClientDataSet *ClientDataSet1;
public:
    __fastcall TMMMaps(TMMEventManager* pEventManager);
    __fastcall ~TMMMaps();
    AnsiString __fastcall GetFileGameType         (AnsiString   pFileName);
    AnsiString __fastcall GetFileType             (AnsiString   pFileFilter);
    AnsiString __fastcall GetFilterFromDiscription(AnsiString pDiscription);
    void       __fastcall GetFileInfo             (AnsiString   pFile);
    // wrapers for the TMMFiles class
    void       __fastcall MakeListViewTable(TListColumns* pCols);
    void       __fastcall UninstallFiles          (PFileList    pFileList);
    void       __fastcall RenameFiles             (PFileList    pFileList);
    void       __fastcall DeleteFiles             (PFileList    pFileList);
    void       __fastcall GetFiles                ();
    void       __fastcall GetFileTypes            ();
    void       __fastcall GetFileFilters          ();
    void       __fastcall GetFileDiscriptions     ();
    void       __fastcall RefreshSettings         ();
    void       __fastcall GetFileData             (AnsiString pFileName);
    // virtual in TFiles
    int        __fastcall GetFileIcon             (AnsiString pFileExt);
    // Events
    void       __fastcall OnGotFileListEvent      (TObject *Sender, PFileList pFileList, TMM_FilesListType plistType);
__published:
    __property bool              SubFolders       = {read=fSubFolders,          write=fSubFolders};
    __property AnsiString        Folder           = {read=fFolder,              write=fFolder};
    __property AnsiString        GameFolder       = {read=fGameFolder,          write=fGameFolder};
    __property TMM_LoadFilesType LoadFilesType    = {read=fLoadFilesType,       write=SetLoadFilesType};
    __property TStrings*         FileTypes        = {read=fFileTypes,           write=SetStringLists, index=0};
    __property TStrings*         FileFilters      = {read=fFileFilters,         write=SetStringLists, index=1};
    __property TStrings*         FileDiscriptions = {read=fFileDiscriptions,    write=SetStringLists, index=2};
    // Events
    __property TNotifyEvent      OnGotFileInfo    = {read=fOnGotFileInfo,       write=fOnGotFileInfo};
    __property TMMFileListEvent  OnGotFileList    = {read=fOnGotFileList,       write=fOnGotFileList};
};
//---------------------------------------------------------------------------
#endif
