//---------------------------------------------------------------------------
#ifndef TMMCache_UT2003H
#define TMMCache_UT2003H
#include "TMMCache.h"
//---------------------------------------------------------------------------
class TMMCache_UT2003 : public TMMCache
{
private:
    AnsiString FCacheFileName;
    void __fastcall SetStringValue(const int Index, const AnsiString Value);
public:
    __fastcall TMMCache_UT2003();   //default constructor
    // default functions
    int __fastcall GetCacheFileList(TStrings* CacheFolderFiles);
    int __fastcall ConvertFiles(TStrings* FileList);
    int __fastcall RemoveInvalidCacheFiles(void);
    int __fastcall RemoveInstalledCacheFiles(void);
    // secondary functions, used by default functions
    int __fastcall GetInstalledCacheFiles(TStrings* CacheFileList);
    int __fastcall GetInvaledCacheFiles(TStrings* FileList);
    int __fastcall ClearCache(void);
	int __fastcall GetCacheFileFileList(TStrings* FileList);
__published:
    __property AnsiString CacheFileName = {read=FCacheFileName,  write=SetStringValue, index=0};
};
#endif
