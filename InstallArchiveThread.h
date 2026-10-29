//---------------------------------------------------------------------------
#ifndef InstallArchiveThreadH
#define InstallArchiveThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "TLogs.h"
#include "TMMFileList.h"
#include "ut_umods.hpp"
#include "MMArchiveEngine.hpp"
//---------------------------------------------------------------------------
class InstallArchiveThread : public TThread
{
private:
    TLogs*             fLogs;    // access to logs ;)
    PFileInfo         AStruct;  // not sure if i still need this, could make in block?!?
	TMMFileList*         LogList;  // used for adding logs
	TMMFileList*         FileList; // used for getting files from archive list
    TMMFileList*         sbLogList; // SmartBackup LogList
    int                Total, Num;
    AnsiString         FileName, GameTag, GameFolder, tmpFileName, LogString, ArchiveName, N;
    TMM_SmartBackup    SmartBackup;
    TMM_InstallMode    InstallMode;
    TMM_InstallType    InstallType;
    TMMFileInsEvent    FOnFileInstalled;
    TMMArchiveInsEvent FOnArchiveInstalled;
    TUMOD*             umod;
    void __fastcall SetSettings();
    void __fastcall AddLog();
    void __fastcall AddsbLog();
    //AnsiString __fastcall GetFileSize(AnsiString FileName);
	__int64 __fastcall GetFileSize(AnsiString FileName);
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
    AnsiString __fastcall GetFileFolder           (AnsiString ArchiveExt);
    int        __fastcall GetArchiveType          (AnsiString ArchiveExt);
    void       __fastcall InstallError            (TObject*   Sender, int                    ErrCode,  UnicodeString Message);
    void       __fastcall MessageError             ();
public:
    __fastcall InstallArchiveThread(bool CreateSuspended, TLogs* AOwner, PFileList AFileList);
    __fastcall ~InstallArchiveThread();
    void __fastcall OnFileInstalledEvent    ();
    void __fastcall OnArchiveInstalledEvent ();
    void __fastcall OnLogEntryEvent         ();   
    __property TMMFileInsEvent     OnFileInstalled    = {read=FOnFileInstalled,    write=FOnFileInstalled};
    __property TMMArchiveInsEvent  OnArchiveInstalled = {read=FOnArchiveInstalled, write=FOnArchiveInstalled};
};
//---------------------------------------------------------------------------
#endif
