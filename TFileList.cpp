//---------------------------------------------------------------------------
#pragma hdrstop
#include "TFileList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TFileList::TFileList()
        : TList()
{
}
//---------------------------------------------------------------------------
__fastcall TFileList::~TFileList()
{
    this->Clear();
}
//---------------------------------------------------------------------------
PFileInfo __fastcall TFileList::AddFile()
{
    PFileInfo AFile = NULL;

    try
    {
        AFile = new TMM_FileInfo;
    }
    catch(...)
    {
    }

    if(AFile)
    {
        if(this->Add(AFile)!=-1)
        {
            AFile->Num          = -1;
            AFile->FileName     = "";
			AFile->FileSize     = 0;
            AFile->FileDate     = "";
            AFile->FileLocation = "";
            AFile->BelongsTo    = -1;
            AFile->CRC32        =  0;
            return AFile;
        }

        delete AFile;
    }

    return NULL;
}
//---------------------------------------------------------------------------
// struck add type
//---------------------------------------------------------------------------
bool __fastcall TFileList::AddFile(TMM_FileInfo aFile)
{
    return (this->AddFile(aFile.FileLocation + aFile.FileName, aFile.FileSize, aFile.FileDate, aFile.Installed, aFile.Num, aFile.BelongsTo, aFile.CRC32));
}
//---------------------------------------------------------------------------
TMM_FileInfo __fastcall TFileList::GetFileStruct(int Index)
{
	TMM_FileInfo aFile;

    if(Index<=this->Count)
    {
        aFile.Num          = this->Files[Index]->Num;
        aFile.BelongsTo    = this->Files[Index]->BelongsTo;
        aFile.FileName     = this->Files[Index]->FileName;
        aFile.FileSize     = this->Files[Index]->FileSize;
        aFile.FileDate     = this->Files[Index]->FileDate;
        aFile.FileLocation = this->Files[Index]->FileLocation;
        aFile.Installed    = this->Files[Index]->Installed;
        aFile.CRC32        = this->Files[Index]->CRC32;
    }

    return aFile;
}
//---------------------------------------------------------------------------
TMM_FileInfo __fastcall TFileList::ToStruct(PFileInfo aFile)
{
    TMM_FileInfo data;

    if(aFile)
    {
        data.Num          = aFile->Num;
        data.BelongsTo    = aFile->BelongsTo;
        data.FileName     = aFile->FileName;
        data.FileSize     = aFile->FileSize;
        data.FileDate     = aFile->FileDate;
        data.FileLocation = aFile->FileLocation;
        data.Installed    = aFile->Installed;
        data.CRC32        = aFile->CRC32;
    }

    return data;
}
//---------------------------------------------------------------------------
// for adding without having to have a local list, can use pointers
//---------------------------------------------------------------------------
bool __fastcall TFileList::AddFile(AnsiString aFileName, AnsiString aFileSize, AnsiString aFileDate, AnsiString aInstalled, int aNum, int aBelongsTo, unsigned long aCRC32)
{
    PFileInfo AFile = NULL;

    try
    {
		AFile = new TMM_FileInfo;
    }
    catch(...)
    {
        return false;
    }

    if(AFile)
    {
        if(this->Add(AFile)!=-1)
        {
            AFile->Num          = aNum;
            AFile->FileName     = ExtractFileName(aFileName);
            AFile->FileSize     = aFileSize.ToIntDef(0);
            AFile->FileDate     = aFileDate;
            AFile->FileLocation = ExtractFilePath(aFileName);
            AFile->BelongsTo    = aBelongsTo;
            AFile->CRC32        = aCRC32;
        }
        else
        {
            delete AFile;
            return false;
        }
    }

    return true;
}
//---------------------------------------------------------------------------
int __fastcall TFileList::Add(PFileInfo aFile)
{
    try
    {
        return inherited::Add(aFile);
    }

    catch(Exception &)
    {
        return -1;
    }
}
//---------------------------------------------------------------------------
PFileInfo __fastcall TFileList::GetFile(int Index)
{
    return static_cast<PFileInfo>(inherited::Items[Index]);
}
//---------------------------------------------------------------------------
void __fastcall TFileList::Notify(void* Ptr, TListNotification Action)
{
    if(Action==lnDeleted)
        delete static_cast<PFileInfo>(Ptr);
}
//---------------------------------------------------------------------------
int __fastcall TFileList::AddFiles(TFileList* aNewList)
{
    int iCount = this->Count;

    for(int i=0;i<iCount;++i)
    {
        PFileInfo aSrcFile = this->Files[i];
        PFileInfo aNewFile = aNewList->AddFile();

        if(aNewFile)
        {
            aNewFile->Num          = aSrcFile->Num;
            aNewFile->FileName     = aSrcFile->FileName;
            aNewFile->FileSize     = aSrcFile->FileSize;
            aNewFile->FileDate     = aSrcFile->FileDate;
            aNewFile->FileLocation = aSrcFile->FileLocation;
            aNewFile->Installed    = aSrcFile->Installed;
            aNewFile->BelongsTo    = aSrcFile->BelongsTo;
            aNewFile->CRC32        = aSrcFile->CRC32;
        }
    }

    return aNewList->Count;
}
//---------------------------------------------------------------------------
int __fastcall TFileList::Copy(TFileList* aOldList)
{
    this->Clear();
    int iCount = aOldList->Count;

    for(int i=0;i<iCount;++i)
    {
        PFileInfo aSrcFile = aOldList->Files[i];
        PFileInfo aNewFile = this->AddFile();

        if(aNewFile)
        {
            aNewFile->Num          = aSrcFile->Num;
            aNewFile->FileName     = aSrcFile->FileName;
            aNewFile->FileSize     = aSrcFile->FileSize;
            aNewFile->FileDate     = aSrcFile->FileDate;
            aNewFile->FileLocation = aSrcFile->FileLocation;
            aNewFile->Installed    = aSrcFile->Installed;
            aNewFile->BelongsTo    = aSrcFile->BelongsTo;
            aNewFile->CRC32        = aSrcFile->CRC32;
        }
    }

    return this->Count;
}
//---------------------------------------------------------------------------
bool __fastcall TFileList::CopyFileTo(PFileInfo aSrcFile, PFileInfo aNewFile)
{
    if(aNewFile && aSrcFile)
    {
        aNewFile->Num          = aSrcFile->Num;
        aNewFile->FileName     = aSrcFile->FileName;
        aNewFile->FileSize     = aSrcFile->FileSize;
        aNewFile->FileDate     = aSrcFile->FileDate;
        aNewFile->FileLocation = aSrcFile->FileLocation;
        aNewFile->Installed    = aSrcFile->Installed;
        aNewFile->BelongsTo    = aSrcFile->BelongsTo;
        aNewFile->CRC32        = aSrcFile->CRC32;

        return true;
    }

    return false;
}
//---------------------------------------------------------------------------
