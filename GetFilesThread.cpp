//---------------------------------------------------------------------------
#include <vcl.h>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "GetFilesThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall GetFilesThread::GetFilesThread(bool CreateSuspended, AnsiString ALocation, bool ASubFolders, TMM_LoadFilesType AFilterType, TStrings* AFilter, TStrings* AFileType)
    : TThread(CreateSuspended)
{
    FreeOnTerminate = true;
    Location        = ALocation;
    SubFolders      = ASubFolders;
    LoadingType     = AFilterType;
    DirList         = new TStringList;
    FileFilters     = new TStringList;
	FileTypes       = new TStringList;
	FileList        = new TMMFileList;
    FileFilters->AddStrings(AFilter);
    FileTypes->AddStrings(AFileType);
}
//---------------------------------------------------------------------------
__fastcall GetFilesThread::~GetFilesThread()
{
    delete FileTypes;
    delete FileFilters;
    delete DirList;
    delete FileList;
}
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::Execute()
{   // no need to terminate checking, once thread is started it should complete!
    switch(LoadingType)
    {
 	    case  MM_LFT_Filter            : GetFilesByFilter();           break;
   	    case  MM_LFT_FileType          : GetFilesByType();             break;
        case  MM_LFT_FilterAndFileType :
   	    case  MM_LFT_UserDefined       : GetFilesByTypeAndFilter();    break;
        default                        : GetFiles(); /* MM_LFT_None */ break;
    }
}
//---------------------------------------------------------------------------
// Events
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::BeforeEnd()
{
    if(FOnBeforeEnd)
        FOnBeforeEnd(this, FileList, static_cast<TMM_FilesListType>(LoadingType));
}
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::FileAdded()
{
    // delete AStruct and use the last entry in the FileList instead !
    FOnFileAdded(this, AStruct->FileName);
}
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::DoTerminate()
{
    if(FOnBeforeEnd)
        Synchronize(BeforeEnd);

    TThread::DoTerminate();
}
//---------------------------------------------------------------------------
// No loading settings, just load everything in the folder(s)
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::GetFiles()
{
    TSearchRec sr;
    Location = IncludeTrailingPathDelimiter(Location);

    if(FindFirst(Location + "*.*", faAnyFile, sr)==0)
    {
        do
        {
            if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
            {
                AStruct = FileList->AddFile();

                if(AStruct)
                {
                    AStruct->FileName     = sr.Name;
					AStruct->FileDate     = sr.TimeStamp.DateTimeString();
                    AStruct->FileSize     = sr.Size;//FormatFloat("#,##0", sr.Size);
                    AStruct->FileLocation = Location;
					AStruct->CRC32        = 0;
                }

                if(FOnFileAdded)
                    Synchronize(FileAdded);
            }
            else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                DirList->Add(Location + sr.Name + "\\");
        }
        while(FindNext(sr)==0);

        FindClose(sr);
    }
    // loop through root folders,
    // adding new ones while looping
    if(SubFolders)
    {
        for(int a=0;a<DirList->Count;a++)
        {
            if(FindFirst(DirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                do
                {
                    if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
                    {
                        AStruct = FileList->AddFile();

                        if(AStruct)
                        {
                            AStruct->FileName     = sr.Name;
							AStruct->FileDate     = sr.TimeStamp.DateTimeString();
							AStruct->FileSize     = sr.Size; //FormatFloat("#,##0", sr.Size);
                            AStruct->FileLocation = DirList->Strings[a];
                            AStruct->CRC32        = 0;
                        }

                        if(FOnFileAdded)
                            Synchronize(FileAdded);
                    }
                    else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)!=0))
                        DirList->Add(DirList->Strings[a] + sr.Name + "\\");
                }
                while(FindNext(sr)==0);

                FindClose(sr);
            }
        }
    }
}
//---------------------------------------------------------------------------
// Get Files By File Type only
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::GetFilesByType()
{
    TSearchRec sr;
    Location = IncludeTrailingPathDelimiter(Location);

    if(FindFirst(Location + "*.*", faAnyFile, sr)==0)
    {
        do
        {
            if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
            {
                if(FileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                {
                    AStruct = FileList->AddFile();

                    if(AStruct)
                    {
                        AStruct->FileName     = sr.Name;
						AStruct->FileDate     = sr.TimeStamp.DateTimeString();
						AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                        AStruct->FileLocation = Location;
                        AStruct->CRC32        = 0;
                    }

                    if(FOnFileAdded)
                        Synchronize(FileAdded);
                }
            }
            else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                DirList->Add(Location + sr.Name + "\\");
        }
        while(FindNext(sr)==0);

        FindClose(sr);
    }
    // loop through root folders,
    // adding new ones while looping
    if(SubFolders)
    {
        for(int a=0;a<DirList->Count;a++)
        {
            if(FindFirst(DirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                do
                {
                    if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
                    {
                        if(FileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                        {
                            AStruct = FileList->AddFile();

                            if(AStruct)
                            {
                                AStruct->FileName     = sr.Name;
								AStruct->FileDate     = sr.TimeStamp.DateTimeString();
								AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                AStruct->FileLocation = DirList->Strings[a];
                                AStruct->CRC32        = 0;
                            }

                            if(FOnFileAdded)
                                Synchronize(FileAdded);
                        }
                    }
                    else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)!=0))
                        DirList->Add(DirList->Strings[a] + sr.Name + "\\");
                }
                while(FindNext(sr)==0);

                FindClose(sr);
            }
        }
    }
}
//---------------------------------------------------------------------------
// Get Files By File Filter only
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::GetFilesByFilter()
{
    TSearchRec sr;
    Location = IncludeTrailingPathDelimiter(Location);

    if(FindFirst(Location + "*.*", faAnyFile, sr)==0)
    {
        do
        {
            if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
            {
                for(int i=0;i<FileFilters->Count;i++)
                {
					if(FileFilters->Text.Pos(sr.Name)!=0)
					//if(AnsiStartsText(FileFilters->Strings[i],sr.Name)) // filter file ext
                    {
						AStruct = FileList->AddFile();

                        if(AStruct)
                        {
                            AStruct->FileName     = sr.Name;
							AStruct->FileDate     = sr.TimeStamp.DateTimeString();
							AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                            AStruct->FileLocation = Location;
                            AStruct->CRC32        = 0;
                        }

                        if(FOnFileAdded)
                            Synchronize(FileAdded);

                        break;
                    }
                }
            }
            else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                DirList->Add(Location + sr.Name + "\\");
        }
        while(FindNext(sr)==0);

        FindClose(sr);
    }
    // loop through root folders,
    // adding new ones while looping
    if(SubFolders)
    {
        for(int a=0;a<DirList->Count;a++)
        {
            if(FindFirst(DirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                do
                {
                    if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
                    {
                        for(int i=0;i<FileFilters->Count;i++)
                        {
                            if(AnsiStartsText(FileFilters->Strings[i],sr.Name)) // filter file ext
                            {
                                AStruct = FileList->AddFile();

                                if(AStruct)
                                {
                                    AStruct->FileName     = sr.Name;
									AStruct->FileDate     = sr.TimeStamp.DateTimeString();
									AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                    AStruct->FileLocation = DirList->Strings[a];
                                    AStruct->CRC32        = 0;
                                }

                                if(FOnFileAdded)
                                    Synchronize(FileAdded);

                                break;
                            }
                        }
                    }
                    else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)!=0))
                        DirList->Add(DirList->Strings[a] + sr.Name + "\\");
                }
                while(FindNext(sr)==0);

                FindClose(sr);
            }
        }
    }
}
//---------------------------------------------------------------------------
// Get Files By File And Filter only
//---------------------------------------------------------------------------
void __fastcall GetFilesThread::GetFilesByTypeAndFilter()
{
    TSearchRec sr;
    Location = IncludeTrailingPathDelimiter(Location);
    int iCount = FileFilters->Count;

    if(FindFirst(Location + "*.*", faAnyFile, sr)==0)
    {
        if(iCount==0) // no filtering required, just check for file types
        {
            do
            {
                if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
                {
                    if(FileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                    {
                        AStruct = FileList->AddFile();

                        if(AStruct)
                        {
                            AStruct->FileName     = sr.Name;
							AStruct->FileDate     = sr.TimeStamp.DateTimeString();
							AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                            AStruct->FileLocation = Location;
                            AStruct->CRC32        = 0;
                        }

                        if(FOnFileAdded)
                            Synchronize(FileAdded);
                    }
                }
                else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                    DirList->Add(Location + sr.Name + "\\");
            }
            while(FindNext(sr)==0);

            FindClose(sr);
        }
        else
        {
            do
            {
                if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
                {
                    for(int i=0;i<iCount;i++)
                    {
                        if(AnsiStartsText(FileFilters->Strings[i],sr.Name) && FileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1)
                        {
                            AStruct = FileList->AddFile();

                            if(AStruct)
                            {
                                AStruct->FileName     = sr.Name;
								AStruct->FileDate     = sr.TimeStamp.DateTimeString();
								AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                AStruct->FileLocation = Location;
                                AStruct->CRC32        = 0;
                            }

                            if(FOnFileAdded)
                                Synchronize(FileAdded);

                            break;
                        }
                    }
                }
                else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                    DirList->Add(Location + sr.Name + "\\");
            }
            while(FindNext(sr)==0);

            FindClose(sr);
        }
    }
    // loop through root folders,
    // adding new ones while looping
    if(SubFolders)
    {
        for(int a=0;a<DirList->Count;a++)
        {
            if(FindFirst(DirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                if(iCount==0) // no filtering required, just check for file types
                {
                    do
                    {
                        if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
                        {
                            if(FileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                            {
                                AStruct = FileList->AddFile();

                                if(AStruct)
                                {
                                    AStruct->FileName     = sr.Name;
									AStruct->FileDate     = sr.TimeStamp.DateTimeString();
									AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                    AStruct->FileLocation = DirList->Strings[a];
                                    AStruct->CRC32        = 0;
                                }

                                if(FOnFileAdded)
                                    Synchronize(FileAdded);
                            }
                        }
                        else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                            DirList->Add(DirList->Strings[a] + sr.Name + "\\");
                    }
                    while(FindNext(sr)==0);

                    FindClose(sr);
                }
                else
                {
                    do
                    {
                        if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
                        {
                            for(int i=0;i<iCount;i++)
                            {
                                if(AnsiStartsText(FileFilters->Strings[i],sr.Name) && FileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1)
                                {
                                    AStruct = FileList->AddFile();

                                    if(AStruct)
                                    {
                                        AStruct->FileName     = sr.Name;
										AStruct->FileDate     = sr.TimeStamp.DateTimeString();
                                        AStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                        AStruct->FileLocation = DirList->Strings[a];
                                        AStruct->CRC32        = 0;
                                    }

                                    if(FOnFileAdded)
                                        Synchronize(FileAdded);

                                    break;
                                }
                            }
                        }
                        else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                            DirList->Add(DirList->Strings[a] + sr.Name + "\\");
                    }
                    while(FindNext(sr)==0);

                    FindClose(sr);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
