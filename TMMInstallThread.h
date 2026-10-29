//---------------------------------------------------------------------------
#ifndef TMMInstallThreadH
#define TMMInstallThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "TMMLogs.h"
#include "DFUnRar.hpp"
#include "ZipBuilder.h"
#include "TMMFileList.h"
#include "ut_umods.hpp"
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
    TZipBuilder*       fZipBuilder1;
    TDFUnRar*          fDFUnRar1;
    TUMOD*             fUmod;
    void __fastcall SetSettings();
    void __fastcall AddLog();
    void __fastcall AddsbLog();
    __int64 __fastcall GetFileSize(AnsiString pfileName);
    void __fastcall Test();     // used for debugging ;)
protected:
    void       __fastcall Execute                 ();
    void       __fastcall DoTerminate             ();
    void       __fastcall InstallZip              ();
    void       __fastcall InstallRar              ();
    void       __fastcall InstallUmod             ();
    void       __fastcall InstallUz               ();
    void       __fastcall InstallMap              ();
    AnsiString __fastcall GetFileFolder           (AnsiString parchiveExt);
    int        __fastcall GetArchiveType          (AnsiString parchiveExt);
    void       __fastcall InstallError            (TObject*   Sender, int                    perrCode,  UnicodeString pmessage);
    void       __fastcall DFUnRar1FileProcessing  (TObject*   Sender, const TDFRARHeaderData &hdrData, int status); // event for get info function on rar files
    void       __fastcall DFUnRar1Override        (TObject*   Sender, AnsiString             FileName, bool &CanOverride, const Untunrar::TRARHeaderData &hdrData);
    void       __fastcall OnZipExtFileExistsEvent (TObject*   Sender, String                 ForFile,  bool IsOlder,      bool                           &DoOverwrite, int DirIndex);
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
