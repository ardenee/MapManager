//---------------------------------------------------------------------------
#ifndef TMMLogs_ArchivesH
#define TMMLogs_ArchivesH
#include "TMMLogs.h"
//---------------------------------------------------------------------------
class TMMLogs_Archives : public TMMLogs
{
private:
    AnsiString FSection;
    void __fastcall SetStringValue(const int Index, const AnsiString Value);
public:
	__fastcall TMMLogs_Archives();   //default constructor
    __fastcall ~TMMLogs_Archives();   //default constructor
    int __fastcall GetArchiveList(TStrings *FileList);
    int __fastcall GetLogStrings(TStrings *StringsList);
__published:
    __property AnsiString Section = {read=FSection,  write=SetStringValue, index=0};
};
#endif
