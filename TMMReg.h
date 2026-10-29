//---------------------------------------------------------------------------
#ifndef TMMRegH
#define TMMRegH
#include <vcl.h>
#include <Registry.hpp>
#include "MMTypes.h"
//---------------------------------------------------------------------------

typedef void __fastcall (__closure *TMM_RegError_Event) (TObject *Sender, AnsiString ErrorMessage);

class TMMReg : public TPersistent
{
private:
    TMM_RegError_Event FOnRegError;
    AnsiString __fastcall GetDataFor(AnsiString Value);
public:
    __fastcall TMMReg();
    __fastcall ~TMMReg();
    TRegistry* Registry;
    void       __fastcall GetKeys    (AnsiString pRegKey, TStrings*  pList);
    void       __fastcall GetValues  (AnsiString pRegKey, TStrings*  pList);
    void       __fastcall GetDatas   (AnsiString pRegKey, TStrings*  pList, bool pDropDoubles);
    AnsiString __fastcall GetDataFor (AnsiString pRegKey, AnsiString Value);
    AnsiString __fastcall GetValueFor(AnsiString pRegKey, AnsiString Data);
    bool       __fastcall IsAValue   (AnsiString pRegKey, AnsiString pFileExt);
__published:
    __property TMM_RegError_Event OnRegError = {read=FOnRegError, write=FOnRegError};
};
#endif
