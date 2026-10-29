//---------------------------------------------------------------------------
#ifndef RenameFilesThreadH
#define RenameFilesThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
//#include "MMTypes.h"
#include "TLogs.h"
//#include "TFileList.h"
//---------------------------------------------------------------------------

class RenameFilesThread : public TThread
{
private:
    int              Total, FNum;
    AnsiString       GameTag, MapName;
    TFileList*       FileList;
    TStrings*        FileTypes;
    TLogs*           Log;
    TMMFileRenEvent  FOnFileRenamed;
    TMMFilesRenEvent FOnFilesRenamed;
    void __fastcall  OnFileRenamedEvent();
    void __fastcall  OnFilesRenamedEvent();
    bool __fastcall  Rename();
    //void __fastcall Test();
    void __fastcall  RenameInLog();
protected:
    void __fastcall Execute();
    void __fastcall DoTerminate();
public:
    __fastcall RenameFilesThread(bool CreateSuspended, TFileList* AFileList, AnsiString AGameTag, TLogs* AFiles);
    __fastcall ~RenameFilesThread();
    void __fastcall GetFileTypes();
    __property TMMFileRenEvent  OnFileRenamed  = {read=FOnFileRenamed,  write=FOnFileRenamed};
    __property TMMFilesRenEvent OnFilesRenamed = {read=FOnFilesRenamed, write=FOnFilesRenamed};
};
//---------------------------------------------------------------------------
#endif
 
