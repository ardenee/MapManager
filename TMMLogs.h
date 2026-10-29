//---------------------------------------------------------------------------
#ifndef TMMLogsH
#define TMMLogsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <XMLDoc.hpp>
//---------------------------------------------------------------------------
#include "TMMSettings.h"
#include "TMMFileList.h" 
//---------------------------------------------------------------------------
class TMMLogs : public TMMXML
{
private:
// new
    AnsiString       fLogFile;

    int              fLogType;
    PFileList        fLogList;
    TMMLogListEvent  fOnGotLogEntrys;
    _di_IXMLDocument fXMLLogFile;
    _di_IXMLNode     fXMLRootNode; // root node
    void __fastcall LoadDB              ();
    int  __fastcall GetLogNum           ();
    void __fastcall SetIntValue         (const int pindex, int pvalue);
    void __fastcall AddLogEntry         (PFileList pLogList);
    bool __fastcall MainArchiveLogExits (PFileInfo parchiveData);
public:
    __fastcall TMMLogs();
    __fastcall ~TMMLogs();
    //void       __fastcall Add                   (PFileList  pLogList);
    void         __fastcall AddCacheLogEntry      (PFileList  pLogList);
    void         __fastcall AddArchiveLogEntry    (PFileList  pLogList);
    void         __fastcall AddSmartBackupLogEntry(PFileList  pLogList);
    bool         __fastcall DeleteLogEntry        (int        precordNumber);
    bool         __fastcall DeleteSubLogEntry     (PFileInfo  pLogEntry);
    void         __fastcall UninstallEntry        (PFileInfo  pLogEntry);
    void         __fastcall UninstallEntrys       (PFileInfo  pLogEntry);
    void         __fastcall GetLogEntrys          ();
    TMM_FileInfo __fastcall GetLogEntry           (int        plogNum);
    void         __fastcall GetArchiveFile        (PFileInfo  pFileData,    PFileInfo parchiveData);
    TMM_FileInfo __fastcall GetArchiveInfo        (PFileInfo  parchiveData);
    bool         __fastcall GetFullLogEntry       (PFileInfo  plogEntry);
    void         __fastcall GetFilesInArchive     (PFileInfo  parchiveData, PFileList pFilesInArchive);
    void         __fastcall GetLogsDisplayFilters (TStrings*  pFilterList);
    bool         __fastcall IsDouble              (PFileInfo  parchiveData);
    bool         __fastcall FileInLog             (PFileInfo  plogEntry);
    bool         __fastcall FindInLog             (PFileInfo  plogEntry);   // not all fields required
    bool         __fastcall FileIsInLogs          (PFileInfo  parchiveData);
    bool         __fastcall FileIsInSBLogs        (PFileInfo  parchiveData);
    bool         __fastcall EditLogEnrty          (PFileInfo  poldLogEntry, PFileInfo pnewLogEntry);
    void         __fastcall EditLogEntry          (PFileInfo  plogEntry);
    void         __fastcall UpdateLogs            ();
    void         __fastcall LoadFromFile          (AnsiString pnewLogFile);
__published:
    __property int              LogType        = {read=fLogType,        write=SetIntValue, index=0};
    __property TMMLogListEvent  OnGotLogEntrys = {read=fOnGotLogEntrys, write=fOnGotLogEntrys};
    __property _di_IXMLDocument XMLLogFile      = {read=fXMLLogFile,     write=fXMLLogFile};
    __property AnsiString       LogFile         = {read=fLogFile,     write=fLogFile};
};
#endif
