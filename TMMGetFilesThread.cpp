//---------------------------------------------------------------------------
#include <vcl.h>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TMMGetFilesThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TMMGetFilesThread::TMMGetFilesThread(bool CreateSuspended, AnsiString plocation, bool psubFolders, TMM_LoadFilesType pfilterType, TStrings* pFilter, TStrings* pFileType, TMM_FilesListType plistType)
    : TThread(CreateSuspended)
{
    FreeOnTerminate = true;
    fLocation        = IncludeTrailingPathDelimiter(plocation);
    fSubFolders      = psubFolders;
    fLoadingType     = pfilterType;
    fDirList         = new TStringList;
    fFileFilters     = new TStringList;
    fFileTypes       = new TStringList;
    fFileList        = new TMMFileList;
    fFileFilters->AddStrings(pFilter);
    fFileTypes->AddStrings(pFileType);
    fListType = plistType;
}
//---------------------------------------------------------------------------
__fastcall TMMGetFilesThread::~TMMGetFilesThread()
{
    delete fFileTypes;
    delete fFileFilters;
    delete fDirList;
    delete fFileList;
}
//---------------------------------------------------------------------------
void __fastcall TMMGetFilesThread::Execute()
{   // no need to terminate checking, once thread is started it should complete!
    switch(fLoadingType)
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
void __fastcall TMMGetFilesThread::BeforeEnd()
{
    if(fOnBeforeEnd)
        fOnBeforeEnd(this, fFileList, fListType);

    //fFileList->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TMMGetFilesThread::FileAdded()
{
    // delete AStruct and use the last entry in the FileList instead !
    fOnFileAdded(this, fStruct->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TMMGetFilesThread::DoTerminate()
{
    if(fOnBeforeEnd)
        Synchronize(BeforeEnd);

    TThread::DoTerminate();
}
//---------------------------------------------------------------------------
// No loading settings, just load everything in the folder(s)
//---------------------------------------------------------------------------
void __fastcall TMMGetFilesThread::GetFiles()
{
	TSearchRec sr;
	int num = 1;

    if(FindFirst(fLocation + "*.*", faAnyFile, sr)==0)
    {
        do
        {
            if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
            {
                fStruct = fFileList->AddFile();

                if(fStruct)
				{
					fStruct->Num          = num;
                    fStruct->FileName     = sr.Name;
					fStruct->FileDate     = sr.TimeStamp.DateTimeString();
					fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                    fStruct->FileLocation = fLocation;
                    fStruct->CRC32        = 0;
				}

				num++;

                if(fOnFileAdded)
					Synchronize(FileAdded);
            }
            else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                fDirList->Add(fLocation + sr.Name + "\\");
        }
        while(FindNext(sr)==0);

        FindClose(sr);
	}

    // loop through root folders,
    // adding new ones while looping
    if(fSubFolders)
    {
        for(int a=0;a<fDirList->Count;a++)
        {
            if(FindFirst(fDirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                do
                {
                    if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
                    {
                        fStruct = fFileList->AddFile();

                        if(fStruct)
						{
							fStruct->Num          = num;
                            fStruct->FileName     = sr.Name;
							fStruct->FileDate     = sr.TimeStamp.DateTimeString();
							fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                            fStruct->FileLocation = fDirList->Strings[a];
                            fStruct->CRC32        = 0;
						}

						num++;

                        if(fOnFileAdded)
                            Synchronize(FileAdded);  
                    }
                    else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)!=0))
                        fDirList->Add(fDirList->Strings[a] + sr.Name + "\\");
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
void __fastcall TMMGetFilesThread::GetFilesByType()
{
    TSearchRec sr;
	int num=1;

    if(FindFirst(fLocation + "*.*", faAnyFile, sr)==0)
    {
        do
        {
            if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
            {
                if(fFileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                {
                    fStruct = fFileList->AddFile();

                    if(fStruct)
					{
						fStruct->Num          = num;
						fStruct->FileName     = sr.Name;
						fStruct->FileDate     = sr.TimeStamp.DateTimeString();
						fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                        fStruct->FileLocation = fLocation;
                        fStruct->CRC32        = 0;
					}

					num++;

                    if(fOnFileAdded)
                        Synchronize(FileAdded);
                }
            }
            else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                fDirList->Add(fLocation + sr.Name + "\\");
        }
        while(FindNext(sr)==0);

        FindClose(sr);
    }
    // loop through root folders,
    // adding new ones while looping
    if(fSubFolders)
    {
        for(int a=0;a<fDirList->Count;a++)
        {
            if(FindFirst(fDirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                do
                {
                    if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
                    {      
                        if(fFileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                        {
                            fStruct = fFileList->AddFile();

                            if(fStruct)
							{
								fStruct->Num          = num;
                                fStruct->FileName     = sr.Name;
								fStruct->FileDate     = sr.TimeStamp.DateTimeString();
								fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                fStruct->FileLocation = fDirList->Strings[a];
                                fStruct->CRC32        = 0;
							}

							num++;

                            if(fOnFileAdded)
                                Synchronize(FileAdded);
                        }
                    }
                    else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)!=0))
                        fDirList->Add(fDirList->Strings[a] + sr.Name + "\\");
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
void __fastcall TMMGetFilesThread::GetFilesByFilter()
{
    TSearchRec sr;
	int num = 1;

    if(FindFirst(fLocation + "*.*", faAnyFile, sr)==0)
    {
        do
        {
            if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
            {
                for(int i=0;i<fFileFilters->Count;i++)
                {
					if(AnsiStartsStr(fFileFilters->Text, ExtractFileExt(sr.Name))==false || AnsiStartsStr(fFileFilters->Text, sr.Name)==false)
                    //if(AnsiStartsText(FileFilters->Strings[i],sr.Name)) // filter file ext
                    {
						fStruct = fFileList->AddFile();

						if(fStruct)
						{
							fStruct->Num          = num;
							fStruct->FileName     = sr.Name;
							fStruct->FileDate     = sr.TimeStamp.DateTimeString();
							fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
							fStruct->FileLocation = fLocation;
							fStruct->CRC32        = 0;
						}

						num++;

						if(fOnFileAdded)
							Synchronize(FileAdded);

						break;
                    }
                }
            }
            else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                fDirList->Add(fLocation + sr.Name + "\\");
        }
        while(FindNext(sr)==0);

        FindClose(sr);
    }
    // loop through root folders,
    // adding new ones while looping
    if(fSubFolders)
    {
        for(int a=0;a<fDirList->Count;a++)
        {
            if(FindFirst(fDirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                do
                {
                    if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)==0))
                    {
                        for(int i=0;i<fFileFilters->Count;i++)
						{
							if(AnsiStartsText(fFileFilters->Strings[i],ExtractFileExt(sr.Name)) || AnsiStartsText(fFileFilters->Strings[i],sr.Name)) // filter file ext
                            {
								fStruct = fFileList->AddFile();

                                if(fStruct)
								{
									fStruct->Num          = num;
                                    fStruct->FileName     = sr.Name;
									fStruct->FileDate     = sr.TimeStamp.DateTimeString();
									fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                    fStruct->FileLocation = fDirList->Strings[a];
                                    fStruct->CRC32        = 0;
								}

								num++;

                                if(fOnFileAdded)
                                    Synchronize(FileAdded);

								break;
                            }
                        }
                    }
                    else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory)!=0))
                        fDirList->Add(fDirList->Strings[a] + sr.Name + "\\");
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
void __fastcall TMMGetFilesThread::GetFilesByTypeAndFilter()
{         
    TSearchRec sr;
	int iCount = fFileFilters->Count;
	int num=1;

    if(FindFirst(fLocation + "*.*", faAnyFile, sr)==0)
    {
        if(iCount==0) // no filtering required, just check for file types
        {
            do
            {
                if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
                {
					if(fFileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                    {
                        fStruct = fFileList->AddFile();
						int tq  = fFileList->Count;

                        if(fStruct)
						{
							fStruct->Num          = num;
                            fStruct->FileName     = sr.Name;
							fStruct->FileDate     = sr.TimeStamp.DateTimeString();
							fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                            fStruct->FileLocation = fLocation;
                            fStruct->CRC32        = 0;
						}

						num++;

                        if(fOnFileAdded)
                            Synchronize(FileAdded);
                    }
                }
                else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                    fDirList->Add(fLocation + sr.Name + "\\");
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
					//change "-" to file type space character
					//AnsiString tt = fFileFilters->Strings[i];
					//AnsiString t1 = fFileFilters->Text;
					//AnsiString t2 = fFileTypes->Text;

					 //int n = fFileTypes->IndexOf(ExtractFileExt(sr.Name));
					 //UnicodeString nn = ExtractFileExt(sr.Name);

						// map or otherfile
						if((AnsiStartsText(fFileFilters->Strings[i], sr.Name) || AnsiStartsText(fFileFilters->Strings[i],ExtractFileExt(sr.Name)) )&& fFileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1)
						{
							fStruct = fFileList->AddFile();

                            if(fStruct)
							{
								fStruct->Num          = num;
                                fStruct->FileName     = sr.Name;
								fStruct->FileDate     = sr.TimeStamp.DateTimeString();
								fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                fStruct->FileLocation = fLocation;
                                fStruct->CRC32        = 0;
							}

							num++;

                            if(fOnFileAdded)
                                Synchronize(FileAdded);

                            break;
                        }
                    }
                }
                else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                    fDirList->Add(fLocation + sr.Name + "\\");
            }
            while(FindNext(sr)==0);

            FindClose(sr);
        }
    }
    // loop through root folders,
    // adding new ones while looping
    if(fSubFolders)
    {
        for(int a=0;a<fDirList->Count;a++)
        {
            if(FindFirst(fDirList->Strings[a] + "*.*", faAnyFile, sr)==0)
            {
                if(iCount==0) // no filtering required, just check for file types
                {
                    do
                    {
                        if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) == 0))
                        {
                            if(fFileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1) // filter file ext
                            {
                                fStruct = fFileList->AddFile();
								int tq  = fFileList->Count;

                                if(fStruct)
								{
									fStruct->Num          = num;
                                    fStruct->FileName     = sr.Name;
									fStruct->FileDate     = sr.TimeStamp.DateTimeString();
									fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                    fStruct->FileLocation = fDirList->Strings[a];
                                    fStruct->CRC32        = 0;
								}

								num++;

                                if(fOnFileAdded)
                                    Synchronize(FileAdded);
                            }
                        }
                        else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                            fDirList->Add(fDirList->Strings[a] + sr.Name + "\\");
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
                                if(AnsiStartsText(fFileFilters->Strings[i],sr.Name) && fFileTypes->IndexOf(ExtractFileExt(sr.Name))!=-1)
                                {
                                    fStruct = fFileList->AddFile();

                                    if(fStruct)
									{
										fStruct->Num          = num;
                                        fStruct->FileName     = sr.Name;
										fStruct->FileDate     = sr.TimeStamp.DateTimeString();
                                        fStruct->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
                                        fStruct->FileLocation = fDirList->Strings[a];
                                        fStruct->CRC32        = 0;
									}

									num++;

                                    if(fOnFileAdded)
                                        Synchronize(FileAdded);

                                    break;
                                }
                            }
                        }
                        else if((sr.Name!=".") && (sr.Name!="..") && ((sr.Attr & faDirectory) != 0))
                            fDirList->Add(fDirList->Strings[a] + sr.Name + "\\");
                    }
                    while(FindNext(sr)==0);

                    FindClose(sr);
                }
            }
        }
	}

    //ShowMessage(fFileList->Count);
}
//---------------------------------------------------------------------------

