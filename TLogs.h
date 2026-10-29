//---------------------------------------------------------------------------
#ifndef TLogsH
#define TLogsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <DB.hpp>
#include <DBClient.hpp>
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "TMMFileList.h"
#include "TSettings.h"
#include "TFileList.h"

//---------------------------------------------------------------------------
class TLogs : public TSettings
{
private:
    int             FLogType;
    //PFileInfo       FFileData;
	TMMFileList*    FLogList;
    TDataSource*    FDataSource;
    TClientDataSet* FClientDataSet;
    TMMLogListEvent FOnGotLogEntrys;
    void __fastcall CreateDB            ();
    void __fastcall LoadDB              ();
    int  __fastcall GetLogNum           ();
    void __fastcall SetIntValue         (const int Index, int Value);
    void __fastcall AddLogEntry         (PFileList pLogList);
    bool __fastcall MainArchiveLogExits (PFileInfo archiveData);
public:
    __fastcall TLogs();
    __fastcall ~TLogs();
    //void     __fastcall Add                    (PFileList  pLogList);
    void     __fastcall AddCacheLogEntry       (PFileList  pLogList);
    void     __fastcall AddArchiveLogEntry     (PFileList  pLogList);
    void     __fastcall AddSmartBackupLogEntry (PFileList  pLogList);
    bool     __fastcall DeleteLogEntry         (int        RecordNumber);
    bool     __fastcall DeleteSubLogEntry      (PFileInfo  LogEntry);
    void     __fastcall UninstallEntry         (PFileInfo  LogEntry);
    void     __fastcall UninstallEntrys        (PFileInfo  LogEntry);
    void     __fastcall GetLogEntrys           ();
    TMM_FileInfo __fastcall GetLogEntry            (int        LogNum);
    void     __fastcall GetArchiveFile         (PFileInfo  FileData,    PFileInfo ArchiveData);
    TMM_FileInfo __fastcall GetArchiveInfo         (TMM_FileInfo   archiveData);
    //int      __fastcall GetFileLogNumE         (PFileInfo  LogEntry);
    //int      __fastcall GetFileLogNumP         (PFileInfo  LogEntry);
    bool     __fastcall GetFullLogEntry        (PFileInfo  LogEntry);
    void     __fastcall GetFilesInArchive      (PFileInfo  archiveData, PFileList FilesInArchive);
    void     __fastcall GetLogsDisplayFilters  (TStrings*  pFilterList);
    bool     __fastcall IsDouble               (TMM_FileInfo   archiveData);
    bool     __fastcall FileInLog              (PFileInfo  LogEntry);
    bool     __fastcall FindInLog              (PFileInfo  LogEntry);   // not all fields required
    bool     __fastcall FileIsInLogs           (PFileInfo  archiveData);
    bool     __fastcall FileIsInSBLogs         (PFileInfo  archiveData);
    bool     __fastcall EditLogEnrty           (PFileInfo  OldLogEntry, PFileInfo NewLogEntry);
    void     __fastcall EditLogEntry           (PFileInfo  LogEntry);
    void     __fastcall UpdateLogs             ();
    void     __fastcall LoadFromFile           (AnsiString NewLogFile);
__published:
    __property int             LogType        = {read=FLogType,          write=SetIntValue, index=0};
    __property TMMLogListEvent OnGotLogEntrys = {read=FOnGotLogEntrys,   write=FOnGotLogEntrys};
    __property TDataSource*    DataSource     = {read=FDataSource};
};
#endif
