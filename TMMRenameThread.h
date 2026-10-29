//---------------------------------------------------------------------------
#ifndef TMMRenameThreadH
#define TMMRenameThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
//#include "MMTypes.h"
#include "TMMLogs.h"
//#include "TFileList.h"
//---------------------------------------------------------------------------

class TMMRenameThread : public TThread
{
private:
    int              fTotal,   fNum;
    AnsiString       fGameTag, fMapName;
    PFileList        fFileList;
    TStrings*        fFileTypes;
    TMMLogs*         fLog;
    TMMFileRenEvent  fOnFileRenamed;
    TMMFilesRenEvent fOnFilesRenamed;
    void __fastcall  OnFileRenamedEvent ();
    void __fastcall  OnFilesRenamedEvent();
    void __fastcall  RenameInLog        ();
    bool __fastcall  Rename             (); 
protected:
    void __fastcall Execute();
    void __fastcall DoTerminate();
public:
		 __fastcall TMMRenameThread(bool CreateSuspended, PFileList pFileList, TStrings* pFileTypes, AnsiString pgameTag, TMMLogs* pFiles);
         __fastcall ~TMMRenameThread();
    void __fastcall GetFileTypes();
    __property TMMFileRenEvent  OnFileRenamed  = {read=fOnFileRenamed,  write=fOnFileRenamed};
    __property TMMFilesRenEvent OnFilesRenamed = {read=fOnFilesRenamed, write=fOnFilesRenamed};
};
//---------------------------------------------------------------------------
#endif
 
