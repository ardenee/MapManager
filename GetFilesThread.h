//---------------------------------------------------------------------------
#ifndef GetFilesThreadH
#define GetFilesThreadH
//---------------------------------------------------------------------------
#include "TMMFileList.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class GetFilesThread : public TThread
{
private:
    PFileInfo         AStruct;
    PFileList         FileList;
    TStrings*         DirList;
    TStrings*         FileTypes;
    TStrings*         FileFilters;
    bool              SubFolders;
    AnsiString        Location, N;
    TMMFileListEvent  FOnBeforeEnd;
    TMMStrEvent       FOnFileAdded;
    TMM_LoadFilesType LoadingType;
    void __fastcall BeforeEnd();
    void __fastcall FileAdded();
    void __fastcall GetFiles();
    void __fastcall GetFilesByType();
    void __fastcall GetFilesByFilter();
    void __fastcall GetFilesByTypeAndFilter();
protected:
    void __fastcall Execute();
    void __fastcall DoTerminate();
public:
    __fastcall GetFilesThread(bool CreateSuspended, AnsiString ALocation, bool ASubFolders, TMM_LoadFilesType AFilterType, TStrings* AFilter, TStrings* AFileType);
    __fastcall ~GetFilesThread();
    __property TMMFileListEvent OnBeforeEnd = {read=FOnBeforeEnd, write=FOnBeforeEnd};
    __property TMMStrEvent      OnFileAdded = {read=FOnFileAdded, write=FOnFileAdded};
};
//---------------------------------------------------------------------------
#endif

