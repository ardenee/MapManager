//---------------------------------------------------------------------------
#include "TFileData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TFileData::TFileData()
    : TPersistent()
{
    FileName     = "";
    FileDate     = "";
    FileSize     = "";
    FileLocation = "";
}
//----------------------------------------------------------------------------
__fastcall TFileData::TFileData(AnsiString AFileName, AnsiString AFileDate, AnsiString AFileSize, AnsiString AFileLocation)
    : TPersistent()
{
    FileName      = AFileName;
    FileDate      = AFileDate;
    FileSize      = AFileSize;
    FileLocation  = AFileLocation;
}
//----------------------------------------------------------------------------
void __fastcall TFileData::Assign(TPersistent* Value)
{
    TFileData* Data = dynamic_cast<TFileData*>(Value);

    if(Data!=NULL)
    {
        FileName     = Data->FileName;
        FileDate     = Data->FileDate;
        FileSize     = Data->FileSize;
        FileLocation = Data->FileLocation;
    }
    else
    {
        TPersistent::Assign(Value);
    }
}
//----------------------------------------------------------------------------
__fastcall TFileData::TFileData(AnsiString FileInfoString)
    : TPersistent()
{
    if(ValidFileInfoString(FileInfoString))
        DecodeFileInfoString(FileInfoString);
    else
    { // default values
        FileName     = "";
        FileDate     = "";
        FileSize     = "";
        FileLocation = "";
    }
}
//----------------------------------------------------------------------------
void __fastcall TFileData::SetStringValue(int Index, AnsiString Value)
{
    switch(Index)
    {
        case 0 : FFileName     = Value; break;
        case 1 : FFileDate     = Value; break;
        case 2 : FFileSize     = Value; break;
        case 3 : FFileLocation = Value; break;
    }
}
//----------------------------------------------------------------------------
void __fastcall TFileData::DecodeFileInfoString(AnsiString FileInfoString)
{
    FileName = FileInfoString;
    FileName.SetLength(AnsiPos(":", FileInfoString)-1);// -1 to get rid of the TAB ':'
    FileInfoString.Delete(1, AnsiPos(":", FileInfoString));

    FileDate = FileInfoString;
    FileDate.SetLength(AnsiPos(":", FileInfoString)-1);// -1 to get rid of the TAB ':'
    FileInfoString.Delete(1, AnsiPos(":", FileInfoString));

    FileSize = FileInfoString;
    FileLocation = ExtractFilePath(FileName);
}
//----------------------------------------------------------------------------
bool __fastcall TFileData::ValidFileInfoString(AnsiString FileInfoString)
{
    bool Result = false;
    int num=0;

    for(int i=0;i<FileInfoString.Length();i++)
            num++;
            
    if(num==2)
        Result = true;
        
    return Result;
}
//----------------------------------------------------------------------------
