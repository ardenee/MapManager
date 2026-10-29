//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
#include "TMMInstallThread.h"
//---------------------------------------------------------------------------
__fastcall TMMInstallThread::TMMInstallThread(bool CreateSuspended, TMMLogs* pOwner, PFileList pFileList)
    : TThread(CreateSuspended)
{
    fTotal          = 0;
    fNum            = 0;
    fLogList        = new TMMFileList;
    fFileList       = new TMMFileList;
    fSBLogList      = new TMMFileList;
    fLogs           = pOwner;
    FreeOnTerminate = true;
    fFileList->Copy(pFileList);

    // Archives
    fUmod                            = new TUMOD();

    fZipBuilder1                     = new TZipBuilder(NULL);
    fZipBuilder1->Unattended         = true;         // no error mesages, b/c we have our own
    fZipBuilder1->OnMessage          = InstallError; // message event
    fZipBuilder1->OnExtractOverwrite = OnZipExtFileExistsEvent;

    fDFUnRar1                        = new TDFUnRar(NULL);
    fDFUnRar1->OnFileProcessing      = DFUnRar1FileProcessing;
	//fDFUnRar1->OnOverride            = DFUnRar1Override;

    if(fLogs)
        Synchronize(SetSettings);
    else
        TThread::DoTerminate();
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::Test()
{
   // ShowMessage(N);
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::SetSettings()
{
    //fSmartBackup = fLogs->SmartBackup;
    //fInstallMode = fLogs->InstallMode;
    //fInstallType = fLogs->InstallType;
    //fGameTag     = fLogs->GameTag;
    //fGameFolder  = fLogs->GameFolder;
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::DoTerminate()
{
    TThread::DoTerminate();
}
//---------------------------------------------------------------------------
__fastcall TMMInstallThread::~TMMInstallThread()
{
    delete fDFUnRar1;
    delete fZipBuilder1;
    delete fUmod;
    delete fFileList;
    delete fLogList;
    delete fSBLogList;
}
//---------------------------------------------------------------------------
// Main Execute()
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::Execute()
{
    if(Terminated==false)
    {
        int iCount = fFileList->Count;

        for(fNum=0;fNum<iCount;fNum++) // loop throught the files types
        {
            switch(GetArchiveType(ExtractFileExt(fFileList->Files[fNum]->FileName)))
            {
                case 0 : InstallZip();  Synchronize(OnArchiveInstalledEvent); break;
                case 1 : InstallRar();  Synchronize(OnArchiveInstalledEvent); break;
                case 2 : InstallUmod(); Synchronize(OnArchiveInstalledEvent); break;
                case 3 : InstallUz();   Synchronize(OnArchiveInstalledEvent); break;
                case 4 : InstallMap();  Synchronize(OnArchiveInstalledEvent); break;
            }

            if(Terminated==true)
                break;
        }
    }
}
//---------------------------------------------------------------------------
inline int __fastcall TMMInstallThread::GetArchiveType(AnsiString ArchiveExt)
{   // should be Synchronize or a new TRegistry call altogether
    int functionNumber  = 5;
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\InstallTypes\\" + fGameTag, false))
    {
        if(Registry->ValueExists(ArchiveExt))
            functionNumber = StrToIntDef(Registry->ReadString(ArchiveExt), 5);
        else
            functionNumber = StrToIntDef(Registry->ReadString("Default"), 5);

        Registry->CloseKey();
    }

    delete Registry;
    return functionNumber;

   // return StrToIntDef(fLogs->GetDataFor("\\SOFTWARE\\Nasty PC's\\Map Manager\\InstallTypes\\" + GameTag, ArchiveExt), 5);
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallZip()
{
/*
    if(fZipBuilder1->IsZipSFX(fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName)==1) // if we have a valid archive??
    {
        fZipBuilder1->ZipFileName = fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName; // assign to zip component
        fArchiveName = fZipBuilder1->ZipFileName;
        fZipBuilder1->ExtrOptions.Clear();    // clear for default
        // Logs
        fStruct = fLogList->AddFile();

        if(fStruct)
        {   // Main Zip File used ofr logging, always add first!
            fStruct->FileName     = fFileList->Files[fNum]->FileName;
            fStruct->FileDate     = fFileList->Files[fNum]->FileDate;
            fStruct->FileSize     = fFileList->Files[fNum]->FileSize;
            fStruct->FileLocation = fFileList->Files[fNum]->FileLocation;
            fStruct->BelongsTo    = -1;
        }
        // Logs

        switch(fInstallMode)
        {
            case MM_IM_Smart : fZipBuilder1->ExtrOptions << ExtrUpdate;    break;
            case MM_IM_Force : fZipBuilder1->ExtrOptions << ExtrOverWrite; break;
        }

        for(int x=0;x<fZipBuilder1->Count;x++) // loop through archive files
        {
            ZipDirEntry *zde = (ZipDirEntry *)fZipBuilder1->ZipContents->Items[x];
            fZipBuilder1->FSpecArgs->Clear(); // clear all info from FSpecArgs
            fZipBuilder1->FSpecArgs->Add(zde->FileName);
            fZipBuilder1->ExtrBaseDir = IncludeTrailingPathDelimiter(fGameFolder + GetFileFolder(ExtractFileExt(zde->FileName)));
            fTmpFileName = fZipBuilder1->ExtrBaseDir + zde->FileName;
            // Logs
            fStruct = fLogList->AddFile();

            if(fStruct)
            {
                fStruct->FileName     = ExtractFileName(zde->FileName);
                fStruct->FileDate     = DateTimeToStr(FileDateToDateTime(zde->DateTime));
                fStruct->FileSize     = FormatFloat("#,##0", zde->UncompressedSize);
                fStruct->FileLocation = fZipBuilder1->ExtrBaseDir;
                fStruct->BelongsTo    = 0;// added to make sure it doesnt get cauth in the InsertRecord() block checking for -1
                fStruct->CRC32        = zde->CRC32;
            }
            // Logs
            fZipBuilder1->Extract();
            Synchronize(OnFileInstalledEvent);
        }

        Synchronize(AddLog); // used for archive logging
    }
    else
        Synchronize(MessageError);
        */
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallRar()
{
    fDFUnRar1->FileName  = fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName;
    fDFUnRar1->Directory = fGameFolder; // default location
    fDFUnRar1->Mode      = DFRAR_EXTRACT;
    fArchiveName         = fDFUnRar1->FileName;

    switch(fInstallMode)
    {
        case MM_IM_None  : fDFUnRar1->OverrideEvent = OR_NEVER;  break;
        case MM_IM_Force : fDFUnRar1->OverrideEvent = OR_ALWAYS; break;
        default          : fDFUnRar1->OverrideEvent = OR_EVENT;  break; // MM_IM_Smart
    }

    // Logs
    fStruct = fLogList->AddFile();

    if(fStruct)
    {
        fStruct->FileName     = fFileList->Files[fNum]->FileName;
        fStruct->FileDate     = fFileList->Files[fNum]->FileDate;
        fStruct->FileSize     = fFileList->Files[fNum]->FileSize;
        fStruct->FileLocation = fFileList->Files[fNum]->FileLocation;
        fStruct->CRC32        = fFileList->Files[fNum]->CRC32;
        fStruct->BelongsTo    = -1;
    }
    // Logs

    switch(fInstallType)
    {
		case MM_IT_KeepFolders : fDFUnRar1->Extract();  break;
		default                : fDFUnRar1->Extract(); break;
    }

    Synchronize(AddLog); // used for archive logging
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::DFUnRar1FileProcessing(TObject *Sender, const TDFRARHeaderData &hdrData, int status) // event for get info function on rar files
{
    if(fInstallType==MM_IT_DropFolders)// Drop folders
    {
        fDFUnRar1->Directory = IncludeTrailingPathDelimiter(fGameFolder + GetFileFolder(ExtractFileExt(hdrData.FileName)));
        fTmpFileName = fDFUnRar1->Directory + ExtractFileName(hdrData.FileName);
    }
    else
        fTmpFileName = fDFUnRar1->Directory + hdrData.FileName;

    if(!hdrData.IsDirectory) // only add files
    {
        // Logs
        fStruct = fLogList->AddFile();

        if(fStruct)
        {
            fStruct->FileName     = ExtractFileName(fTmpFileName);
            fStruct->FileDate     = DateTimeToStr(hdrData.FileTime);
			fStruct->FileSize     = hdrData.UnpSize;// FormatFloat("#,##0", hdrData.UnpSize);
            fStruct->FileLocation = ExtractFilePath(fTmpFileName);
            fStruct->CRC32        = StrToIntDef(hdrData.FileCRC, 0);
        }
        // Logs

        Synchronize(OnFileInstalledEvent);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::DFUnRar1Override(TObject *Sender, AnsiString FileName, bool &CanOverride, const Untunrar::TRARHeaderData &hdrData)
{
    AnsiString tmp = "";
    switch(fInstallMode)
    {
        case MM_IM_Smart : CanOverride = (CompareDateTime(FileDateToDateTime(hdrData.FileTime), FileDateToDateTime(FileAge(FileName)))==1)? true : false; break;// A is earlier than B - older
        case MM_IM_Force : CanOverride = true; break;                         
        default          : CanOverride = false;
    }

//    Synchronize(Test);

    // only rename if newer! this way theres no need to delete the old .old file if not updating
    if(fSmartBackup==MM_SB_RenameFile && CanOverride) // rename anyway!
    {
        if(FileExists(fFileName + ".old")) // so .old file is always the newest 1
            DeleteFile(fFileName + ".old");

        if(RenameFile(fFileName, fFileName + ".old")) // rename should work replacing the old .old file
        {//AddFile(AnsiString aFileName, AnsiString aFileSize, AnsiString aFileDate, AnsiString aInstalled, int aNum, int aBelongsTo)
            fSBLogList->AddFile(fFileName,          hdrData.UnpSize, DateTimeToStr(FileDateToDateTime(hdrData.FileTime)),           "Yes", 0, -1);
            fSBLogList->AddFile(fFileName + ".old", GetFileSize(fFileName + ".old"),        DateTimeToStr(FileDateToDateTime(FileAge(fFileName + ".old"))), "Yes", 0, 0); // 0 for default
            Synchronize(AddsbLog); // used for archive logging
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallMap()
{
    fTmpFileName = IncludeTrailingBackslash(fGameFolder + GetFileFolder(ExtractFileExt(fFileList->Files[fNum]->FileName))) + fFileList->Files[fNum]->FileName;
    fArchiveName = fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName;

    if(FileExists(fTmpFileName))
    {
        if(CompareDateTime(FileDateToDateTime(FileAge(fArchiveName)), FileDateToDateTime(FileAge(fTmpFileName)))==1) // A is earlier than B - older
        {
            if(FileExists(fTmpFileName + ".old"))
                DeleteFile(fTmpFileName + ".old");

            if(RenameFile(fTmpFileName, fTmpFileName + ".old"))
            {
                fStruct = fSBLogList->AddFile(); // map in archive folder

                if(fStruct)
                {
                    fStruct->FileName     = fFileList->Files[fNum]->FileName;
                    fStruct->FileDate     = fFileList->Files[fNum]->FileDate;
                    fStruct->FileSize     = fFileList->Files[fNum]->FileSize;
                    fStruct->FileLocation = fFileList->Files[fNum]->FileLocation;
                    fStruct->CRC32        = fFileList->Files[fNum]->CRC32;
                    fStruct->BelongsTo    = -1;
                }

                fStruct = fSBLogList->AddFile(); // map in map folder

                if(fStruct)
                {
                    fStruct->FileName     = ExtractFileName(fTmpFileName);
                    fStruct->FileDate     = DateTimeToStr(FileDateToDateTime(FileAge(fTmpFileName)));
					fStruct->FileSize     = GetFileSize(fTmpFileName);
                    fStruct->FileLocation = ExtractFilePath(fTmpFileName);
                    //fStruct->CRC32        = GetCRC32(fTmpFileName);
                }

                Synchronize(AddsbLog);
            }
        }
        else
            if(fInstallMode==MM_IM_Smart)
                return; // file being installed is not newer, its older so dont install
    }

    switch(fInstallMode)
    {
		case MM_IM_Force : CopyFile(UnicodeString(fArchiveName).c_str(), UnicodeString(fTmpFileName).c_str(), false); break;
		default          : CopyFile(UnicodeString(fArchiveName).c_str(), UnicodeString(fTmpFileName).c_str(), true);  break;
	}

    Synchronize(OnFileInstalledEvent);

    // Logs
    fStruct = fLogList->AddFile(); // map in archive folder
    if(fStruct)
    {
        fStruct->FileName     = fFileList->Files[fNum]->FileName;
        fStruct->FileDate     = fFileList->Files[fNum]->FileDate;
        fStruct->FileSize     = fFileList->Files[fNum]->FileSize;
        fStruct->FileLocation = fFileList->Files[fNum]->FileLocation;
        fStruct->CRC32        = fFileList->Files[fNum]->CRC32;
    }

    fStruct = fLogList->AddFile(); // map in map folder
    if(fStruct)
    {
        fStruct->FileName     = ExtractFileName(fTmpFileName);
        fStruct->FileDate     = DateTimeToStr(FileDateToDateTime(FileAge(fTmpFileName)));
		fStruct->FileSize     = GetFileSize(fTmpFileName);
        fStruct->FileLocation = ExtractFilePath(fTmpFileName);
        //fStruct->CRC32        = GetCRC32(tmpFileName);
    }
    // Logs
}
//---------------------------------------------------------------------------
__int64 __fastcall TMMInstallThread::GetFileSize(AnsiString pfileName)
{
    TSearchRec sr;

    FindFirst(pfileName, faAnyFile, sr);
    __int64 size = sr.Size;
    FindClose(sr);

    return size;
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::OnZipExtFileExistsEvent(TObject *Sender, String ForFile, bool IsOlder, bool &DoOverwrite, int DirIndex)
{
    switch(fInstallMode)
    {
        case MM_IM_Smart : DoOverwrite = (IsOlder) ? true : false; break;
        case MM_IM_Force : DoOverwrite = true;                     break;
    }

    if(fSmartBackup==MM_SB_RenameFile && DoOverwrite) // rename anyway!
    {
        if(FileExists(ForFile + ".old")) // so .old file is always the newest 1
            DeleteFile(ForFile + ".old");

        if(RenameFile(ForFile, ForFile + ".old")) // rename should work replacing the old .old file
            Synchronize(AddsbLog);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallUmod()
{
    if(fUmod->IsUMOD(fFileName))
    {
        fUmod->Load(fFileName);
        fUmod->ExtractAll(fGameFolder); // game folder
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallUz()
{
    fStruct = fLogList->AddFile();

    if(fStruct)
    {
        fStruct->FileName     = ExtractFileName(fFileName);
        fStruct->FileDate     = ""; // getdate
		fStruct->FileSize     = 0; // getsize (compressed)
        fStruct->FileLocation = ExtractFilePath(fFileName);
        //fStruct->CRC32        = GetCRC32(FileName);
    }

    // uncompress and copy to new folder
    // set date of new file to the old file!!!

    fStruct = fLogList->AddFile();

    if(fStruct)
    {
        fStruct->FileName     = ExtractFileName(fFileName);
        fStruct->FileDate     = ""; // set to uz2 filedate!!!
        fStruct->FileSize     = 0; // getsize (uncompressed)
        fStruct->FileLocation = ExtractFilePath(fFileName);
        //fStruct->CRC32        = GetCRC32(FileName);
    }

    Synchronize(AddLog); // used for archive logging
}
//---------------------------------------------------------------------------
// Events
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::OnArchiveInstalledEvent()
{
    fTotal++;

    if(fOnArchiveInstalled)
        fOnArchiveInstalled(this, fArchiveName);
}
//---------------------------------------------------------------------------  
void __fastcall TMMInstallThread::OnFileInstalledEvent()
{
    if(fOnFileInstalled)
        fOnFileInstalled(this, fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName, fTmpFileName);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMMInstallThread::GetFileFolder(AnsiString parchiveExt)
{
    AnsiString Folder = "Help";
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + fGameTag + "\\Cache", false))
    {
        if(Registry->ValueExists(parchiveExt))
            Folder = Registry->ReadString(parchiveExt);
        else
            Folder = Registry->ReadString("default");

        Registry->CloseKey();
    }

    delete Registry;
    return Folder;
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallError(TObject *Sender, int ErrCode, UnicodeString Message)
{
    // error
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::MessageError()  // not really needed
{
    int ZipErrorCode = 2;
    AnsiString ZipErrorMessage = ExtractFileName(fFileName) + " is an unsusported archive format.";
    ShowMessage(ExtractFileName(fFileName) + " encountered some errors.\nZip Erro Code: " + ZipErrorCode + "\nZip Error Message: " + ZipErrorMessage);
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::AddLog()
{
    fLogs->LoadFromFile("Archives" + fGameTag + ".xml");
    fLogs->AddArchiveLogEntry(fLogList);
    //fLogList->Clear(); // always reset after adding the log
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::AddsbLog()
{
    AnsiString oldLogFile = fLogs->LogFile;
    fLogs->LoadFromFile("SmartBackup" + fGameTag + ".xml");
    fLogs->AddSmartBackupLogEntry(fSBLogList);
    //fSBLogList->Clear(); // always reset after adding the log
    fLogs->LoadFromFile(oldLogFile);
}
//---------------------------------------------------------------------------
