//---------------------------------------------------------------------------
#ifndef TMMGetFilesThreadH
#define TMMGetFilesThreadH
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "TMMFileList.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TMMGetFilesThread : public TThread
{
private:
    PFileInfo         fStruct;
    PFileList         fFileList;
    TStrings*         fDirList;
    TStrings*         fFileTypes;
    TStrings*         fFileFilters;
    bool              fSubFolders;
    TMM_FilesListType fListType;
    AnsiString        fLocation, fN;
    TMMFileListEvent  fOnBeforeEnd;
    TMMStrEvent       fOnFileAdded;
    TMM_LoadFilesType fLoadingType;
    void __fastcall BeforeEnd              ();
    void __fastcall FileAdded              ();
    void __fastcall GetFiles               ();
    void __fastcall GetFilesByType         ();
    void __fastcall GetFilesByFilter       ();
    void __fastcall GetFilesByTypeAndFilter();
protected:
    void __fastcall Execute();
    void __fastcall DoTerminate();
public:
    __fastcall TMMGetFilesThread(bool CreateSuspended, AnsiString plocation, bool psubFolders, TMM_LoadFilesType pfilterType, TStrings* pFilter, TStrings* pFileType, TMM_FilesListType plistType);
    __fastcall ~TMMGetFilesThread();
    __property TMMFileListEvent OnBeforeEnd = {read=fOnBeforeEnd, write=fOnBeforeEnd};
    __property TMMStrEvent      OnFileAdded = {read=fOnFileAdded, write=fOnFileAdded};
};
//---------------------------------------------------------------------------
#endif

