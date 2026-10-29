//---------------------------------------------------------------------------
#pragma hdrstop
#include "TMMFileList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall TMMFileList::TMMFileList()
		  : TPersistent()
{
	List = new TList();
}
//---------------------------------------------------------------------------
__fastcall TMMFileList::~TMMFileList()
{
	List->Clear();
    delete List;
}
//---------------------------------------------------------------------------
PFileInfo __fastcall TMMFileList::AddFile()
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
void __fastcall TMMFileList::Clear()
{
	List->Clear();
}
//---------------------------------------------------------------------------
// struck add type
//---------------------------------------------------------------------------
bool __fastcall TMMFileList::AddFile(TMM_FileInfo aFile)
{
	return (this->AddFile(aFile.FileLocation + aFile.FileName, aFile.FileSize, aFile.FileDate, aFile.Installed, aFile.Num, aFile.BelongsTo, aFile.CRC32));
}
//---------------------------------------------------------------------------
TMM_FileInfo __fastcall TMMFileList::GetFileStruct(int Index)
{
	TMM_FileInfo aFile; 
	//static_cast<&aFile>(inherited::this->Files[Index]);

	if(Index<=List->Count)
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
TMM_FileInfo __fastcall TMMFileList::ToStruct(PFileInfo aFile)
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
bool __fastcall TMMFileList::AddFile(AnsiString aFileName, __int64 aFileSize, AnsiString aFileDate, bool aInstalled, int aNum, int aBelongsTo, unsigned long aCRC32)
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
			AFile->FileSize     = aFileSize;
			AFile->FileDate     = aFileDate;
			AFile->FileLocation = ExtractFilePath(aFileName);
			AFile->BelongsTo    = aBelongsTo;
			AFile->Installed    = aInstalled;
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
int __fastcall TMMFileList::Add(PFileInfo aFile)
{
	try
	{
		return List->Add(aFile);
	}

	catch(Exception &)
	{
		return -1;
	}
}
//---------------------------------------------------------------------------
PFileInfo __fastcall TMMFileList::GetFile(int Index)
{
	return static_cast<PFileInfo>(List->Items[Index]);
}
//---------------------------------------------------------------------------
void __fastcall TMMFileList::Notify(void* Ptr, TListNotification Action)
{
	if(Action==lnDeleted)
		delete static_cast<PFileInfo>(Ptr);
}
//---------------------------------------------------------------------------
int __fastcall TMMFileList::AddFiles(PFileList aNewList)
{
	int iCount = List->Count;

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

	return aNewList->GetCount();
}
//---------------------------------------------------------------------------
int __fastcall TMMFileList::Copy(PFileList aOldList)
{
	List->Clear();
	int iCount = aOldList->GetCount();

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

    return List->Count;
}
//---------------------------------------------------------------------------
bool __fastcall TMMFileList::CopyFileTo(PFileInfo aSrcFile, PFileInfo aNewFile)
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
int __fastcall TMMFileList::GetCount()
{
	return List->Count;
}
//---------------------------------------------------------------------------

