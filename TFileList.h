//---------------------------------------------------------------------------
#ifndef TFileListH
#define TFileListH
//---------------------------------------------------------------------------
#include "MMTypes.h"

class TFileList : public TList
{
    typedef TList inherited;
private:
    PFileInfo __fastcall GetFile(int Index);
protected:
    virtual void __fastcall Notify(void* Ptr, TListNotification Action);
public:
    __fastcall TFileList();
    __fastcall ~TFileList();
    PFileInfo __fastcall AddFile();
	bool __fastcall AddFile(TMM_FileInfo aFile);
    bool __fastcall AddFile(AnsiString aFileName, AnsiString aFileSize, AnsiString aFileDate, AnsiString aInstalled, int aNum=0, int aBelongsTo=0, unsigned long aCRC32=0);
    int  __fastcall AddFiles(TFileList* aNewList);
    int  __fastcall Copy(TFileList* aOldList);
    bool __fastcall CopyFileTo(PFileInfo aSrcFile, PFileInfo aNewFile);
	TMM_FileInfo __fastcall GetFileStruct(int Index);
    TMM_FileInfo __fastcall ToStruct(PFileInfo aFile);
    HIDESBASE int __fastcall Add(PFileInfo aFile);
    __property PFileInfo Files[int Index] = {read=GetFile};
};
#endif
 
