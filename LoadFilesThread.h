//---------------------------------------------------------------------------

#ifndef LoadFilesThreadH
#define LoadFilesThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//#include "ztvBase.hpp"
//#include "ztvregister.hpp"
//#include "ztvRegister.hpp"
//#include "ztvziptv.hpp"
//#include "ztvZipTV.hpp"
//#include "ztvbase.hpp"

//---------------------------------------------------------------------------
class LoadFilesThread : public TThread
{

private:
    TListView    *TmpListView;
  //  ProgramData  *TmpProgramData;
    TStrings     *TmpFileTypes;
    TStrings     *TmpNames;
    TStrings     *Filters;
    TStrings     *FilesList;
    int          LoadType, Page, Total, SubTotal;
    AnsiString   TmpRegKey, Folder, TMP, ProgressMessage, NUM; 
    //TZipTV *ZipTV1;
protected:
    void __fastcall Execute();
public:
    __fastcall LoadFilesThread(bool CreateSuspended, TListView *ListView, int FileType, TStrings* FileTypes, TStrings* FiltersTypes, AnsiString Location);
    __fastcall ~LoadFilesThread();
    void __fastcall CheckUsage();
    void __fastcall FreeFlag();
    void __fastcall ProgressUpdate();
    void __fastcall ProgressSet();
    void __fastcall ProgressPoint();
    void __fastcall GetFiles(TStrings* Files, AnsiString Location, bool SubFolders);
    void __fastcall VerfyFiles(TStrings* FilesList);
    void __fastcall GetFileNames(TStrings* TmpFiles);
    void __fastcall DisplayMaps();
    void __fastcall FilterFiles(TStrings* FileStrings);
    AnsiString __fastcall LogSafeNameToFile(AnsiString FileName);
	void __fastcall Test();
    TMM_FileInfo __fastcall GetDataFromDisplayStr(AnsiString MainString);

    // new functions
    bool ValidMapDisplayString(AnsiString TmpString);
    //FileInfoData GetDataFromDisplayStr(AnsiString MainString);
};
//---------------------------------------------------------------------------
#endif
 