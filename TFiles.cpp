//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
#include <DateUtils.hpp>
//#include <shlobj.h>
//---------------------------------------------------------------------------
#include "TFiles.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TFiles::TFiles()
          : TLogs()
{
    FFileList = new TMMFileList;
}
//---------------------------------------------------------------------------
__fastcall TFiles::~TFiles()
{
    delete FFileList;
}
//---------------------------------------------------------------------------
// event functions
//---------------------------------------------------------------------------
void __fastcall TFiles::OnFileAddedEvent(TObject *Sender, AnsiString FileName)
{
    if(FOnFileAdded)
        FOnFileAdded(this, FileName);
}
//---------------------------------------------------------------------------
void __fastcall TFiles::OnGotFileListEvent(TObject *Sender, PFileList pFileList)
{
    FFileList->Copy(pFileList);

   // if(OnGotFileList)
    //    OnGotFileList(this, FFileList);
}
//---------------------------------------------------------------------------
void __fastcall TFiles::OnGotCacheFileListEvent(TObject *Sender, PFileList pFileList)
{
    FFileList->Copy(pFileList);

  //  if(OnGotCacheFileList)
  //      OnGotCacheFileList(this, FFileList);
}
//---------------------------------------------------------------------------
void __fastcall TFiles::OnFilesRenamedEvent(TObject *Sender)
{
    if(OnFilesRenamed)
        OnFilesRenamed(this);
}
//---------------------------------------------------------------------------
void __fastcall TFiles::OnFileRenamedEvent(TObject *Sender, AnsiString OldName, AnsiString NewName)
{  
    if(OnFileRenamed)
        OnFileRenamed(this, OldName, NewName);
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
void __fastcall TFiles::GetFileList(AnsiString pFileFolder, bool pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings* pFileFilters, TStrings* pFileTypes)
{
    GetFilesThread* FileLoading;
    FileLoading = new GetFilesThread(true, pFileFolder, pSubFolders, pLoadFilesType, pFileFilters, pFileTypes);
   // FileLoading->OnBeforeEnd = OnGotFileListEvent;
	FileLoading->OnFileAdded = OnFileAddedEvent;
    FileLoading->Resume();
}
//----------------------------------------------------------------------------
void __fastcall TFiles::GetCacheFileList(AnsiString pFileFolder, bool pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings* pFileFilters, TStrings* pFileTypes)
{
    GetFilesThread* FileLoading;
    FileLoading = new GetFilesThread(true, pFileFolder, pSubFolders, pLoadFilesType, pFileFilters, pFileTypes);
   // FileLoading->OnBeforeEnd = OnGotCacheFileListEvent;
    FileLoading->OnFileAdded = OnFileAddedEvent;
    FileLoading->Resume();
}
//----------------------------------------------------------------------------
// Outside functions
//----------------------------------------------------------------------------
void __fastcall TFiles::OpenFile(AnsiString FileName)
{
    TStrings* MapTypes = new TStringList;
    TReg::GetValues("SOFTWARE\\Nasty PC's\\Map Manager\\Maps\\" + GameTag, MapTypes);

    if(MapTypes->IndexOf(ExtractFileExt(FileName))!=-1)
        PlayMap(FileName);
   // else
   //     ShellExecute(NULL, "open", FileName.c_str(), NULL, NULL, SW_SHOWNORMAL);

    delete MapTypes;
}
//----------------------------------------------------------------------------
void __fastcall TFiles::PlayMap(AnsiString FileName)
{   // ucc server DM-Antalus?game=XGame.XDeathmatch ini=TypeIniFileHere.ini log=TypeLogNameHere.log
    AnsiString Paramertiers = "";

    if(GameMode)
        Paramertiers = Paramertiers + GameFolder + "System\\" + GameEXE + " " + PlayGameString;
    else
        Paramertiers = Paramertiers + GameFolder + "System\\" + ServerEXE + " " + PlayGameString;

    // did the user leave the Map Name tag in Paramertiers String?
     if(AnsiContainsText(Paramertiers, "<MapName>"))
       Paramertiers = StringReplace(Paramertiers, "<MapName>", " " + FileName + "?game=" + GetMapGameType(FileName), TReplaceFlags() << rfIgnoreCase);

    // did the user leave the UserFile tag in Paramertiers String?
     if(AnsiContainsText(Paramertiers, "<UserFile>"))
        Paramertiers = StringReplace(Paramertiers, "<UserFile>", " -ini=" + UserFile + " ", TReplaceFlags() << rfIgnoreCase);

   // ShowMessage(Paramertiers);
    //ShellExecute(0, "", GameEXE.c_str(), Paramertiers.c_str(), Folder.c_str(), SW_SHOW);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TFiles::GetMapGameType(AnsiString FileName)
{
    // load types from registry, check for a type, of not found set to default
    AnsiString MapType = FileName.Delete(AnsiPos("-", FileName),FileName.Length());
    TStrings* MapGameTypes = new TStringList;  

    /*
        Use new functions of TReg !!! for below code
    */

   // TRegistry *Registry = new TRegistry;
   // Registry->RootKey   = HKEY_LOCAL_MACHINE;

   // if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TSettings::GameTag, false))
   // {
   TReg::GetValues("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TSettings::GameTag, MapGameTypes);

        //Registry->GetValueNames(MapGameTypes);
        int num = MapGameTypes->IndexOf(MapType);

        if(num==-1)
            FileName = TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TSettings::GameTag, "Default"); //Registry->ReadString("Default");
        else
            FileName = TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TSettings::GameTag, MapGameTypes->Strings[num]); //Registry->ReadString(MapGameTypes->Strings[num]);

       // Registry->CloseKey();
   // }
   // else
     //   FileName = "Error";

   // delete Registry;
    delete MapGameTypes;
    return FileName;
}
//----------------------------------------------------------------------------
void __fastcall TFiles::FindFile(PFileList List, AnsiString SubString)
{   // returns a list which contain the information were looking for
    for(int i=0;i<List->Count;i++)
    {
        if(AnsiContainsText(List->Files[i]->FileName, SubString))
            continue;

	   // List->Delete(i);
        i--;
    }
}
//----------------------------------------------------------------------------
void __fastcall TFiles::DeleteFiles(PFileList List)
{
    TFileList* delList = new TFileList;
	//delList->Copy(List);
    int iCount = delList->Count;

    for(int i=0;i<iCount;i++)
    {
        if(IsSameFile(delList->Files[i], delList->Files[i]->FileLocation + delList->Files[i]->FileName))
        {
            if(DeleteFile(delList->Files[i]->FileLocation + delList->Files[i]->FileName))
            {
                if(FOnFileDeleted)
                    FOnFileDeleted(this, delList->Files[i]->FileLocation + delList->Files[i]->FileName);

                delList->Delete(i);
                iCount--;
                i--;
            }
        }
    }

	//if(FOnFilesDeleted)
	//	FOnFilesDeleted(this, delList); // return the list, should contain all files not deleted

    delete delList;
}
//----------------------------------------------------------------------------
bool __fastcall TFiles::IsArchive(AnsiString FileExt)
{
    return (TReg::IsAValue("SOFTWARE\\Nasty PC's\\Map Manager\\Archives\\" + GameTag, FileExt));
}
//----------------------------------------------------------------------------
TMM_FileInfo __fastcall TFiles::GetFileInfo(AnsiString pFileName, TMM_FileInfo fileData)
{
    if(FileExists(pFileName))
    {
        TSearchRec sr;  
        FindFirst(pFileName, faAnyFile, sr);
          fileData.FileName     = ExtractFileName(pFileName);
		  fileData.FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
		  fileData.FileDate     = sr.TimeStamp.DateTimeString();
          fileData.FileLocation = ExtractFilePath(pFileName);
        FindClose(sr);
    }

    return fileData;
}
//---------------------------------------------------------------------------
void __fastcall TFiles::GetFileInfo(AnsiString pFileName, PFileInfo &fileData)
{
    if(FileExists(pFileName))
    {
        TSearchRec sr;  
        FindFirst(pFileName, faAnyFile, sr);
          fileData->FileName     = ExtractFileName(pFileName);
		  fileData->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
		  fileData->FileDate     = sr.TimeStamp.DateTimeString();
          fileData->FileLocation = ExtractFilePath(pFileName);
        FindClose(sr);
    }   
}
//----------------------------------------------------------------------------
bool __fastcall TFiles::IsSameFile(PFileInfo fileData, AnsiString fileName)
{
    TMM_FileInfo localFile;
    localFile = GetFileInfo(fileName, localFile);
    PFileInfo localFileP = &localFile;

    if(fileData->FileName     == localFileP->FileName &&
       fileData->FileSize     == localFileP->FileSize &&
       fileData->FileDate     == localFileP->FileDate &&
       fileData->FileLocation == localFileP->FileLocation)
        return true;

    return false;
}
//----------------------------------------------------------------------------
void __fastcall TFiles::UninstallFiles(PFileList pList)
{   
    FFileList->Copy(pList); 
    int iCount=FFileList->Count;

    for(int i=0;i<iCount;i++)
    {
        if(FileIsInLogs(FFileList->Files[i])) //remove from logs
        {
			TMM_FileInfo AStruct;
            PFileInfo archiveData = &AStruct; // pointer to the struct!

            if(IsArchive(ExtractFileExt(FFileList->Files[i]->FileName)))
                FFileList->CopyFileTo(FFileList->Files[i], archiveData); // easy copy
            else
                GetArchiveFile(FFileList->Files[i], archiveData);

            TMMFileList* FilesInArchive = new TMMFileList;
			GetFilesInArchive(archiveData, FilesInArchive);
            int iACount = FilesInArchive->Count;
			AnsiString oldFileName = "";

            for(int i=0;i<iACount;i++)
            {
                if(!IsSameFile(FilesInArchive->Files[i], FilesInArchive->Files[i]->FileLocation + FilesInArchive->Files[i]->FileName))
                {
                    AnsiString oldFileName = FilesInArchive->Files[i]->FileName;
                    FilesInArchive->Files[i]->FileName = FilesInArchive->Files[i]->FileName + ".old";

                    if(!IsSameFile(FilesInArchive->Files[i], FilesInArchive->Files[i]->FileLocation + FilesInArchive->Files[i]->FileName + ".old"))
                        FilesInArchive->Files[i]->FileName = oldFileName;
                }

                if(DeleteFile(FilesInArchive->Files[i]->FileLocation + FilesInArchive->Files[i]->FileName))
                {
                    TLogs::UninstallEntry(FilesInArchive->Files[i]); // delete log entry

                    if(SmartUninstall) // only if we delete it
                        SmartInstallUninstall(FilesInArchive->Files[i]);

                    if(OnFileUninstalled)
                        OnFileUninstalled(this, FilesInArchive->Files[i]->FileName, archiveData->FileName); 
                }
            }

            if(!oldFileName.IsEmpty())
            {
                FilesInArchive->Files[i]->FileName = oldFileName;
                oldFileName = "";
            }

            UninstallEntry(archiveData);
            delete FilesInArchive;
        }
        else
        {
            if(DeleteFile(FFileList->Files[i]->FileLocation + FFileList->Files[i]->FileName))
            {
                if(SmartUninstall) // might not be in main log file but could be in SmartBackup Log File
                    SmartInstallUninstall(FFileList->Files[i]);

                if(FOnSFileUninstalled)
                    FOnSFileUninstalled(this, FFileList->Files[i]->FileName);
            }
        }
    }  

    for(int i=0;i<iCount;i++)
    {
        if(FileIsInLogs(FFileList->Files[i])) //remove from logs
        {
            TMM_FileInfo AStruct;
            PFileInfo archiveData = &AStruct; // pointer to the struct!

            if(IsArchive(ExtractFileExt(FFileList->Files[i]->FileName)))
                FFileList->CopyFileTo(FFileList->Files[i], archiveData); // easy copy
            else
                GetArchiveFile(FFileList->Files[i], archiveData);

            TMMFileList* FilesInArchive = new TMMFileList;
            GetFilesInArchive(archiveData, FilesInArchive);
            int iACount = FilesInArchive->Count;

            for(int i=0;i<iACount;i++)
            {   // this list will only ever have the files list, not the main archive file!
                if(IsSameFile(FilesInArchive->Files[i], FilesInArchive->Files[i]->FileLocation + FilesInArchive->Files[i]->FileName))
                {
                    if(DeleteFile(FilesInArchive->Files[i]->FileLocation + FilesInArchive->Files[i]->FileName))
                    {
                        TLogs::UninstallEntry(FilesInArchive->Files[i]); // delete log entry

                        if(SmartUninstall) // only if we delete it
                            SmartInstallUninstall(FilesInArchive->Files[i]);

                        if(OnFileUninstalled)
                            OnFileUninstalled(this, FilesInArchive->Files[i]->FileName, archiveData->FileName);
                    }
                }
                else
                {
                    // loo to FileName + ."old" ???
                }
            }

            UninstallEntry(archiveData);
            delete FilesInArchive;
        }
        else
        {
            if(DeleteFile(FFileList->Files[i]->FileLocation + FFileList->Files[i]->FileName))
            {
                if(SmartUninstall) // might not be in main log file but could be in SmartBackup Log File
                    SmartInstallUninstall(FFileList->Files[i]);

                if(FOnSFileUninstalled)
                    FOnSFileUninstalled(this, FFileList->Files[i]->FileName);
            }
        }
    }

    if(FOnFilesUninstalled)
        FOnFilesUninstalled(this, FFileList);
}
//---------------------------------------------------------------------------
void __fastcall TFiles::SmartInstallUninstall(PFileInfo fileData)
{
    AnsiString OldFile = TLogs::LogFile;
    TLogs::LoadFromFile("SmartBackup" + GameTag + ".xml");

    if(FileIsInLogs(fileData)) //remove from logs
    {
        TMMFileList* FileList = new TMMFileList;
        GetFilesInArchive(fileData, FileList);
        int iACount = FileList->Count;

        for(int i=0;i<iACount;i++)
        {
            if(FileExists(FileList->Files[i]->FileLocation + FileList->Files[i]->FileName))
            {
                AnsiString NewName = FileList->Files[i]->FileLocation + FileList->Files[i]->FileName;

                if(RenameFile(FileList->Files[i]->FileLocation + FileList->Files[i]->FileName, NewName.Delete(NewName.AnsiPos(".old"), 4)))
                {
                    TLogs::UninstallEntrys(fileData); // deletes the log entry in SmartBackup|GameTag|.xml
                }
            }
        }

        delete FileList;
    }

    // always reset back to archives log file!
    TLogs::LoadFromFile(OldFile); 
}
//---------------------------------------------------------------------------
inline int __fastcall TFiles::GetFileType(AnsiString pFileExtension)
{
    if(!pFileExtension.AnsiCompareIC(".exe") || !pFileExtension.AnsiCompareIC(".zip"))  // exe could be rar installer also!!
        return 0;
    else if(!pFileExtension.AnsiCompareIC(".rar"))
        return 1;
    else if(!pFileExtension.AnsiCompareIC(".umod"))
        return 2;
    else if(!pFileExtension.AnsiCompareIC(".uz2"))
        return 3;
    else
        return 4;
}
//---------------------------------------------------------------------------
// Done - Manually Rename File
//---------------------------------------------------------------------------
bool __fastcall TFiles::ManuallyRenameFile(AnsiString pOldName, AnsiString pNewName)
{
    if(RenameFile(pOldName, pNewName))
    {
        if(OnFileRenamed)
            OnFileRenamed(this, pOldName, pNewName);

            return true;
    }

    return false; // default
}
//---------------------------------------------------------------------------
// Done - Install Files
//---------------------------------------------------------------------------
void __fastcall TFiles::RenameFiles(PFileList pFileList)
{
/*
    RenameFilesThread* FileRenaming;
    FileRenaming = new RenameFilesThread(true, pFileList, GameTag, this);
    FileRenaming->OnFilesRenamed = FOnFilesRenamed; // set up the event!! do we need to?
    FileRenaming->OnFileRenamed  = FOnFileRenamed;  // set up the event!! do we need to?
	FileRenaming->Resume();
    */
}
//---------------------------------------------------------------------------
AnsiString __fastcall TFiles::GetFileSize(AnsiString fileName)
{
    if(FileExists(fileName))
    {
        TSearchRec sr;

        FindFirst(fileName, faAnyFile, sr);
        __int64 size = sr.Size;
        FindClose(sr);

        return FormatFloat("#,##0", size);
    }

    return ""; // default
}
//---------------------------------------------------------------------------
bool __fastcall TFiles::CompareFiles(AnsiString pFileDate, AnsiString pFileSize, AnsiString pFileName)
{
    if(FileExists(pFileName))// file is there?
    {
        if(CompareDateTime(StrToDateTime(pFileDate), FileDateToDateTime(FileAge(pFileName)))==0)
        {
            __int64 tmpNum = StrToIntDef(StringReplace(pFileSize, ",", "", TReplaceFlags() << rfReplaceAll), -1);

            if(tmpNum == StrToIntDef(StringReplace(GetFileSize(pFileName), ",", "", TReplaceFlags() << rfReplaceAll), -1) && tmpNum!=-1)
                return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------
bool __fastcall TFiles::CompareFiles(AnsiString pFileDate, AnsiString pFileSize, AnsiString pFileName, AnsiString pFileDate2, AnsiString pFileSize2)
{
    if(FileExists(pFileName))// file is there?
    {
        if(CompareDateTime(StrToDateTime(pFileDate), StrToDateTime(pFileDate2))==0)
        {
            __int64 tmpNum = StrToIntDef(StringReplace(pFileSize, ",", "", TReplaceFlags() << rfReplaceAll), -1);

            if(tmpNum == StrToIntDef(StringReplace(pFileSize2, ",", "", TReplaceFlags() << rfReplaceAll), -1) && tmpNum!=-1)
                return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TFiles::GetFileTypeFromFilter(AnsiString pFilter, AnsiString RegKey)
{
    return TReg::GetDataFor(RegKey, pFilter); 
}
//---------------------------------------------------------------------------
AnsiString __fastcall TFiles::GetFileFolder(AnsiString ArchiveExt)
{
    AnsiString Folder = "Help";

    if(IsAValue("SOFTWARE\\Nasty PC's\\Map Manager\\Cache\\" + GameTag, ArchiveExt))

        Folder = GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Cache\\" + GameTag, ArchiveExt);
    else
        Folder = GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Cache\\" + GameTag, "default");

    return Folder;
}
//---------------------------------------------------------------------------
int __fastcall TFiles::GetFileIcon(AnsiString ArchiveExt)
{
    return StrToIntDef(GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Icons\\" + GameTag + "\\", ArchiveExt), 10);
}
//---------------------------------------------------------------------------

