#ifndef TFileDataH
#define TFileDataH
#include <vcl.h>
//---------------------------------------------------------------------------

class TFileData : public TPersistent
{
private:
    AnsiString FFileName;
    AnsiString FFileDate;
    AnsiString FFileSize;
    AnsiString FFileLocation;
    void __fastcall SetStringValue(int Index, AnsiString Value);
    void __fastcall DecodeFileInfoString(AnsiString FileInfoString);
    bool __fastcall ValidFileInfoString(AnsiString FileInfoString);
public:
    __fastcall TFileData();   //default constructor
    __fastcall TFileData(AnsiString AFileName, AnsiString AFileDate, AnsiString AFileSize, AnsiString AFileLocation);
    __fastcall TFileData(AnsiString AMapInfoString);
    void __fastcall Assign(TPersistent* Value);
__published:
    __property AnsiString FileName     = {read=FFileName,     write=SetStringValue, index=0};
    __property AnsiString FileDate     = {read=FFileDate,     write=SetStringValue, index=1};
    __property AnsiString FileSize     = {read=FFileSize,     write=SetStringValue, index=2};
    __property AnsiString FileLocation = {read=FFileLocation, write=SetStringValue, index=3};
};
#endif
