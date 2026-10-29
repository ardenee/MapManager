//---------------------------------------------------------------------------
#ifndef TLogs_ArchivesH
#define TLogs_ArchivesH
#include "TLogs_Archives.h"
#include "TMMLogs.h"
//---------------------------------------------------------------------------
class TLogs_Archives : public TMMLogs
{
private:
    AnsiString FSection;
    void __fastcall SetStringValue(const int Index, const AnsiString Value);
public:
    __fastcall TLogs_Archives();   //default constructor
    __fastcall ~TLogs_Archives();   //default constructor
    int __fastcall GetArchiveList(TStrings *FileList);
    int __fastcall GetLogStrings(TStrings *StringsList);
__published:
    __property AnsiString Section = {read=FSection,  write=SetStringValue, index=0};
};
#endif
