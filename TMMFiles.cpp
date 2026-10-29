//---------------------------------------------------------------------------
#include <fmx.h>
#include <Registry.hpp>
#include <StrUtils.hpp>
#include <DateUtils.hpp>
//#include <shlobj.h>
//---------------------------------------------------------------------------
#include "TMMFiles.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TMMFiles::TMMFiles()
          : TPersistent()
{
    fFileList        = new TMMFileList;
    fEventManagerSet = false;
}
//---------------------------------------------------------------------------
__fastcall TMMFiles::~TMMFiles()
{
    //fFileList->Clear();
    fEventManager = NULL;
    delete fFileList;
}
//---------------------------------------------------------------------------
bool __fastcall TMMFiles::SetEventManager(TMMEventManager* pEventManager)
{
    if(pEventManager)
    {
        fEventManager    = pEventManager;
        fEventManagerSet = true;
    }
    
    return fEventManagerSet;
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
void __fastcall TMMFiles::GetFileList(AnsiString pFileFolder, bool pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings* pFileFilters, TStrings* pFileTypes, TMM_FilesListType plistType)
{
    TMMGetFilesThread* FileLoading;
    FileLoading              = new TMMGetFilesThread(true, pFileFolder, pSubFolders, pLoadFilesType, pFileFilters, pFileTypes, plistType);
    //FileLoading->OnBeforeEnd = fEventManager->OnGotFileListEvent;  // OnGotFileListEvent;
	FileLoading->OnBeforeEnd = OnGotFileListEvent;
    FileLoading->OnFileAdded = fEventManager->OnFileAddedEvent;    // OnFileAddedEvent;
	fEventManager->ListType  = plistType;
    FileLoading->Resume();
}
//----------------------------------------------------------------------------
void __fastcall TMMFiles::GetCacheFileList(AnsiString pFileFolder, bool pSubFolders, TMM_LoadFilesType pLoadFilesType, TStrings* pFileFilters, TStrings* pFileTypes)
{
    //GetFilesThread* FileLoading;
    //FileLoading = new GetFilesThread(true, pFileFolder, pSubFolders, pLoadFilesType, pFileFilters, pFileTypes);
    //FileLoading->OnBeforeEnd = OnGotCacheFileListEvent;
    //FileLoading->OnFileAdded = OnFileAddedEvent;
    //FileLoading->Resume();
}
//----------------------------------------------------------------------------
// Outside functions
//----------------------------------------------------------------------------
void __fastcall TMMFiles::OpenFile(AnsiString FileName)
{
    TStrings* MapTypes = new TStringList;
   // TMMReg::GetValues("SOFTWARE\\Nasty PC's\\Map Manager\\Maps\\" + GameTag, MapTypes);

    if(MapTypes->IndexOf(ExtractFileExt(FileName))!=-1)
        PlayMap(FileName);
	//else
    //    ShellExecute(NULL, "open", FileName.c_str(), NULL, NULL, SW_SHOWNORMAL);

    delete MapTypes;
}
//----------------------------------------------------------------------------
void __fastcall TMMFiles::PlayMap(AnsiString FileName)   //rename PlayFile 31-8-17
{   // ucc server DM-Antalus?game=XGame.XDeathmatch ini=TypeIniFileHere.ini log=TypeLogNameHere.log
    AnsiString Paramertiers = "";

    /*
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
    */
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMFiles::GetMapGameType(AnsiString FileName) //rename GetFileType 31-8-17
{
    // load types from registry, check for a type, of not found set to default
   // AnsiString MapType = FileName.Delete(AnsiPos("-", FileName),FileName.Length());
   // TStrings* MapGameTypes = new TStringList;

    /*
        Use new functions of TReg !!! for below code
    */

   // TRegistry *Registry = new TRegistry;
   // Registry->RootKey   = HKEY_CURRENT_USER;

   // if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TSettings::GameTag, false))
   // {
  // TMMReg::GetValues("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TMMSettings::GameTag, MapGameTypes);

        //Registry->GetValueNames(MapGameTypes);
        //int num = MapGameTypes->IndexOf(MapType);

        //if(num==-1)
           // FileName = TMMReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TMMSettings::GameTag, "Default"); //Registry->ReadString("Default");
       // else
           // FileName = TMMReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStartings\\" + TMMSettings::GameTag, MapGameTypes->Strings[num]); //Registry->ReadString(MapGameTypes->Strings[num]);

       // Registry->CloseKey();
   // }
   // else
     //   FileName = "Error";

   // delete Registry;
   // delete MapGameTypes;
    return FileName;
}
//----------------------------------------------------------------------------
void __fastcall TMMFiles::FindFile(PFileList List, AnsiString SubString)
{   // returns a list which contain the information were looking for
    List->Copy(fFileList);

    for(int i=0;i<List->Count;i++)
    {
        if(AnsiContainsText(List->Files[i]->FileName, SubString))
            continue;

		//List->Delete(i);
        i--;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMFiles::DeleteFiles(PFileList List)
{
    PFileList delList = new TMMFileList;
    delList->Copy(List);
    int iCount = delList->Count;

    for(int i=0;i<iCount;i++)
    {
        if(IsSameFile(delList->Files[i], delList->Files[i]->FileLocation + delList->Files[i]->FileName))
        {
            if(DeleteFile(delList->Files[i]->FileLocation + delList->Files[i]->FileName))
            {
                if(FOnFileDeleted)
                    FOnFileDeleted(this, delList->Files[i]->FileLocation + delList->Files[i]->FileName);

				//delList->Delete(i);
                iCount--;
                i--;
            }
        }
    }

    if(FOnFilesDeleted)
        FOnFilesDeleted(this, delList); // return the list, should contain all files not deleted

    delete delList;
}
//----------------------------------------------------------------------------
bool __fastcall TMMFiles::IsArchive(AnsiString FileExt) // move to TMMArchives ?? 31-8-17
{
   // return (TMMReg::IsAValue("SOFTWARE\\Nasty PC's\\Map Manager\\Archives\\" + GameTag, FileExt));
    return false;
}
//----------------------------------------------------------------------------
TMM_FileInfo __fastcall TMMFiles::GetFileInfo(AnsiString pFileName)
{
    TMM_FileInfo fileData;

    if(FileExists(pFileName))
    {
        TSearchRec sr;  
        FindFirst(pFileName, faAnyFile, sr);
          fileData.FileName     = ExtractFileName(pFileName);
		  fileData.FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
		  fileData.FileDate     = sr.TimeStamp.DateTimeString();
		  fileData.FileLocation = ExtractFilePath(pFileName);
          fileData.CRC32 = 0;
          fileData.Installed = 0;
		  fileData.BelongsTo = 0;
        FindClose(sr);
    }

    return fileData;
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetFileInfo(AnsiString pFileName, PFileInfo &fileData)
{
    if(FileExists(pFileName))
    {
        TSearchRec sr;  
        FindFirst(pFileName, faAnyFile, sr);
          fileData->FileName     = ExtractFileName(pFileName);
          fileData->FileSize     = sr.Size;// FormatFloat("#,##0", sr.Size);
		  fileData->FileDate     = sr.TimeStamp.DateTimeString();
          fileData->FileLocation = ExtractFilePath(pFileName);
          fileData->CRC32 = 0;
          fileData->Installed = 0;
          fileData->BelongsTo = 0;
        FindClose(sr);
    }   
}
//----------------------------------------------------------------------------
bool __fastcall TMMFiles::IsSameFile(PFileInfo fileData, AnsiString fileName)
{
    TMM_FileInfo localFile;
    localFile = GetFileInfo(fileName);
    PFileInfo localFileP = &localFile;

    if(fileData->FileName     == localFileP->FileName &&
       fileData->FileSize     == localFileP->FileSize &&
       fileData->FileDate     == localFileP->FileDate &&
       fileData->FileLocation == localFileP->FileLocation)
        return true;

    return false;
}
//----------------------------------------------------------------------------
void __fastcall TMMFiles::UninstallFiles(PFileList pList)
{   
    fFileList->Copy(pList); 
    int iCount=fFileList->Count;

    for(int i=0;i<iCount;i++)
    {
    /*
        if(FileIsInLogs(FFileList->Files[i])) //remove from logs
        {
            TMM_FileInfo AStruct;
            PFileInfo archiveData = &AStruct; // pointer to the struct!

            if(IsArchive(ExtractFileExt(FFileList->Files[i]->FileName)))
                FFileList->CopyFileTo(FFileList->Files[i], archiveData); // easy copy
            else
                GetArchiveFile(FFileList->Files[i], archiveData);

            PFileList FilesInArchive = new TMMFileList;
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
                    TMMLogs::UninstallEntry(FilesInArchive->Files[i]); // delete log entry

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
        */
    }  

    for(int i=0;i<iCount;i++)
    {
    /*
        if(FileIsInLogs(FFileList->Files[i])) //remove from logs
        {
            TMM_FileInfo AStruct;
            PFileInfo archiveData = &AStruct; // pointer to the struct!

            if(IsArchive(ExtractFileExt(FFileList->Files[i]->FileName)))
                FFileList->CopyFileTo(FFileList->Files[i], archiveData); // easy copy
            else
                GetArchiveFile(FFileList->Files[i], archiveData);

            PFileList FilesInArchive = new TMMFileList;
            GetFilesInArchive(archiveData, FilesInArchive);
            int iACount = FilesInArchive->Count;

            for(int i=0;i<iACount;i++)
            {   // this list will only ever have the files list, not the main archive file!
                if(IsSameFile(FilesInArchive->Files[i], FilesInArchive->Files[i]->FileLocation + FilesInArchive->Files[i]->FileName))
                {
                    if(DeleteFile(FilesInArchive->Files[i]->FileLocation + FilesInArchive->Files[i]->FileName))
                    {
                        TMMLogs::UninstallEntry(FilesInArchive->Files[i]); // delete log entry

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
        */
    }

    if(FOnFilesUninstalled)
        FOnFilesUninstalled(this, fFileList);
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::SmartInstallUninstall(PFileInfo fileData)
{
    //AnsiString OldFile = TMMLogs::LogFile;
    //TMMLogs::LoadFromFile("SmartBackup" + GameTag + ".xml");
   /*
    if(FileIsInLogs(fileData)) //remove from logs
    {
        PFileList FileList = new TMMFileList;
        GetFilesInArchive(fileData, FileList);
        int iACount = FileList->Count;

        for(int i=0;i<iACount;i++)
        {
            if(FileExists(FileList->Files[i]->FileLocation + FileList->Files[i]->FileName))
            {
                AnsiString NewName = FileList->Files[i]->FileLocation + FileList->Files[i]->FileName;

                if(RenameFile(FileList->Files[i]->FileLocation + FileList->Files[i]->FileName, NewName.Delete(NewName.AnsiPos(".old"), 4)))
                {
                    TMMLogs::UninstallEntrys(fileData); // deletes the log entry in SmartBackup|GameTag|.xml
                }
            }
        }

        delete FileList;
    }

    // always reset back to archives log file!
    TMMLogs::LoadFromFile(OldFile);
    */
}
//---------------------------------------------------------------------------
inline int __fastcall TMMFiles::GetFileType(AnsiString pFileExtension)
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
bool __fastcall TMMFiles::ManuallyRenameFile(AnsiString pOldName, AnsiString pNewName)
{
    if(RenameFile(pOldName, pNewName))
    {
        if(fEventManager->OnFileRenamed)
            fEventManager->OnFileRenamed(this, pOldName, pNewName);

            return true;
    }

    return false; // default
}
//---------------------------------------------------------------------------
// Done - Install Files
//---------------------------------------------------------------------------
void __fastcall TMMFiles::RenameFiles(PFileList pFileList, AnsiString pGameTag, TStrings* pFileTypes)
{        
    //TStrings* FileTypes = new TStringList();
    //GetFileTypes(FileTypes, 1);

    //__fastcall TMMRenameThread(bool CreateSuspended, PFileList pFileList, AnsiString pgameTag, TMMLogs* pFiles);
    TMMRenameThread* FileRenaming;
    FileRenaming = new TMMRenameThread(true, pFileList, pFileTypes, pGameTag, fEventManager->XMLLogs);
    FileRenaming->OnFilesRenamed = fEventManager->OnFilesRenamedEvent; //FOnFilesRenamed; // set up the event!! do we need to?
    FileRenaming->OnFileRenamed  = fEventManager->OnFileRenamedEvent;// FOnFileRenamed;  // set up the event!! do we need to?
    FileRenaming->Resume();
   // delete FileTypes;
}                                                      
//---------------------------------------------------------------------------
AnsiString __fastcall TMMFiles::GetFileSize(AnsiString fileName)
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
bool __fastcall TMMFiles::CompareFiles(AnsiString pFileDate, AnsiString pFileSize, AnsiString pFileName)
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
bool __fastcall TMMFiles::CompareFiles(AnsiString pFileDate, AnsiString pFileSize, AnsiString pFileName, AnsiString pFileDate2, AnsiString pFileSize2)
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
AnsiString __fastcall TMMFiles::GetFileTypeFromFilter(AnsiString pFilter, AnsiString RegKey)
{
   // return TMMReg::GetDataFor(RegKey, pFilter);
    return "";
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMMFiles::GetFileFolder(AnsiString ArchiveExt)
{
    AnsiString Folder = "Help";

   // if(IsAValue("SOFTWARE\\Nasty PC's\\Map Manager\\Cache\\" + GameTag, ArchiveExt))

    //    Folder = GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Cache\\" + GameTag, ArchiveExt);
   // else
     //   Folder = GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Cache\\" + GameTag, "default");

    return Folder;
}
//---------------------------------------------------------------------------
//int __fastcall TMMFiles::GetFileIcon(AnsiString ArchiveExt)
//{
   //return StrToIntDef(GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Icons\\" + GameTag + "\\", ArchiveExt), 10);
//   return 10;
//}
//---------------------------------------------------------------------------
/*
void __fastcall TMMFiles::GetFileTypes(TStrings* FileTypes, int FileType)
{
	FileTypes->Clear();
	this->PEventManager->XMLSettings->GetMapTypes(FileTypes);

    // switch here for file types using the FileType value
    _di_IXMLMapsMenuType MapMenus = fEventManager->XMLSettings->DisplayMenus->Get_MapsMenu();

    if(MapMenus->ChildNodes->GetCount()>0)
    {
        _di_IXMLNodeList Items = MapMenus->GetChildNodes();

        for(int i=0;i<Items->Count;i++)
        {
            _di_IXMLItemType Item = Items->Get(i);
            _di_IXMLNodeList ItemAttList = Item->GetAttributeNodes();
            _di_IXMLNode     Node        = ItemAttList->First();
            FileTypes->Add(Node->GetText());
        }
	}
}
*/
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetMapData(AnsiString pFileName, TMM_GetFileInfoType pAction)  //move to TMMMaps 31-8-17
{
		fFileDataThread = new TMMFileInfoThread(true, pAction, "", pFileName, (TUTPackage_GameHint)fEventManager->XMLSettings->GameType);
		fFileDataThread->OnDataListEnd = fEventManager->OnGotDataList;
		fFileDataThread->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetMusicData(AnsiString pFileName, TMM_GetFileInfoType pAction)  //move to TMMMaps 31-8-17
{
		fFileDataThread = new TMMFileInfoThread(true, pAction, "", pFileName, (TUTPackage_GameHint)fEventManager->XMLSettings->GameType);
		fFileDataThread->OnDataListEnd = fEventManager->OnGotDataList;
		fFileDataThread->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetTexturesData(AnsiString pFileName, TMM_GetFileInfoType pAction)  //move to TMMMaps 31-8-17
{
		fFileDataThread = new TMMFileInfoThread(true, pAction, "", pFileName, (TUTPackage_GameHint)fEventManager->XMLSettings->GameType);
		fFileDataThread->OnDataListEnd = fEventManager->OnGotDataList;
		fFileDataThread->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetDemosData(AnsiString pFileName, TMM_GetFileInfoType pAction)  //move to TMMMaps 31-8-17
{
		fFileDataThread = new TMMFileInfoThread(true, pAction, "", pFileName, (TUTPackage_GameHint)fEventManager->XMLSettings->GameType);
		fFileDataThread->OnDataListEnd = fEventManager->OnGotDataList;
		fFileDataThread->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetScreenShotsData(AnsiString pFileName, TMM_GetFileInfoType pAction)  //move to TMMMaps 31-8-17
{
		fFileDataThread = new TMMFileInfoThread(true, pAction, "", pFileName, (TUTPackage_GameHint)fEventManager->XMLSettings->GameType);
		fFileDataThread->OnDataListEnd = fEventManager->OnGotDataList;
		fFileDataThread->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetArchiveData(AnsiString pFileName, TMM_GetFileInfoType pAction) //move to TMMArchive 31-8-17
{
		fFileDataThread = new TMMFileInfoThread(true, pAction, "", pFileName, (TUTPackage_GameHint)fEventManager->XMLSettings->GameType);
		fFileDataThread->OnDataListEnd = fEventManager->OnGotDataList;
		fFileDataThread->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMMFiles::GetPicture(AnsiString pFileName) //move to TMMArchive 31-8-17 - why needed?
{
        TMM_GetFileInfoType action = MM_GFIT_IMAGE;
		fFileDataThread = new TMMFileInfoThread(true, action, "", pFileName, (TUTPackage_GameHint)fEventManager->XMLSettings->GameType);
		fFileDataThread->OnBeforePictureEnd = fEventManager->OnGotPicture;
		fFileDataThread->Resume();
}
//---------------------------------------------------------------------------

