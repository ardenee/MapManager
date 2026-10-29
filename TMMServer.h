#ifndef TMMServerH
#define TMMServerH
#include <vcl.h>
//---------------------------------------------------------------------------

class TMMServer : public TPersistent
{
private:
        AnsiString FQueryString;
        AnsiString FReturnedQueryString;
        int FTotalQuerys;
        void __fastcall SetQureyString(const int QueryType);
        void __fastcall SetIntValue(const int Value, const int Index);
public:
    __fastcall TMMServer();    //default constructor
    __fastcall ~TMMServer();   //default deconstructor
    bool __fastcall QueryServer();
    void __fastcall DecodeQueryString();
__published:
    __property AnsiString QueryString         = {read=FQueryString};
    __property AnsiString ReturnedQueryString = {read=FReturnedQueryString};
    __property int TotalQuerys                = {read=FTotalQuerys, write=SetIntValue, index=0};
};
#endif
