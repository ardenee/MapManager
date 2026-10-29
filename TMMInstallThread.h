//---------------------------------------------------------------------------
#ifndef TMMInstallThreadH
#define TMMInstallThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "TMMLogs.h"
#include "TMMFileList.h"
#include "ut_umods.hpp"
#include "MMArchiveEngine.hpp"
//---------------------------------------------------------------------------
class TMMInstallThread : public TThread
{
private:
    TMMLogs*           fLogs;    // access to logs ;)
    PFileInfo          fStruct;  // not sure if i still need this, could make in block?!?
    PFileList          fLogList;  // used for adding logs
    PFileList          fFileList; // used for getting files from archive list
    PFileList          fSBLogList; // SmartBackup LogList
    int                fTotal, fNum;
    AnsiString         fFileName, fGameTag, fGameFolder, fTmpFileName, fLogString, fArchiveName, fN;
    TMM_SmartBackup    fSmartBackup;
    TMM_InstallMode    fInstallMode;
    TMM_InstallType    fInstallType;
    TMMFileInsEvent    fOnFileInstalled;
    TMMArchiveInsEvent fOnArchiveInstalled;
    TUMOD*             fUmod;
    void __fastcall SetSettings();
    void __fastcall AddLog();
    void __fastcall AddsbLog();
    __int64 __fastcall GetFileSize(AnsiString pfileName);
    void __fastcall Test();     // used for debugging ;)
protected:
    void       __fastcall Execute                 ();
    void       __fastcall DoTerminate             ();
    void       __fastcall InstallPacked           ();
    void       __fastcall InstallZip              ();
    void       __fastcall InstallRar              ();
    void       __fastcall InstallUmod             ();
    void       __fastcall InstallUz               ();
    void       __fastcall InstallMap              ();
    AnsiString __fastcall GetFileFolder           (AnsiString parchiveExt);
    int        __fastcall GetArchiveType          (AnsiString parchiveExt);
    void       __fastcall InstallError            (TObject*   Sender, int                    perrCode,  UnicodeString pmessage);
    void       __fastcall MessageError             ();
public:
         __fastcall TMMInstallThread        (bool CreateSuspended, TMMLogs* pOwner, PFileList pFileList);
         __fastcall ~TMMInstallThread       ();
    void __fastcall OnFileInstalledEvent    ();
    void __fastcall OnArchiveInstalledEvent ();
    void __fastcall OnLogEntryEvent         ();
    __property TMMFileInsEvent     OnFileInstalled    = {read=fOnFileInstalled,    write=fOnFileInstalled};
    __property TMMArchiveInsEvent  OnArchiveInstalled = {read=fOnArchiveInstalled, write=fOnArchiveInstalled};
};
//---------------------------------------------------------------------------
#endif
