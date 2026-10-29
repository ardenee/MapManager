//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
#include "InstallArchiveThread.h"
//---------------------------------------------------------------------------
__fastcall InstallArchiveThread::InstallArchiveThread(bool CreateSuspended, TLogs* AOwner, PFileList AFileList)
    : TThread(CreateSuspended)
{
    Total     = 0;
    Num       = 0;
	LogList   = new TMMFileList;
	FileList  = new TMMFileList;
	sbLogList = new TMMFileList;
    fLogs     = AOwner;
    FileList->Copy(AFileList);
    FreeOnTerminate = true;

    // Archives
    umod                            = new TUMOD();

    ZipBuilder1                     = new TZipBuilder(NULL);
    ZipBuilder1->Unattended         = true;         // no error mesages, b/c we have our own
    ZipBuilder1->OnMessage          = InstallError; // message event
    ZipBuilder1->OnExtractOverwrite = OnZipExtFileExistsEvent;
    
    DFUnRar1                        = new TDFUnRar(NULL);
    DFUnRar1->OnFileProcessing      = DFUnRar1FileProcessing;
   // DFUnRar1->OnOverride            = DFUnRar1Override;

    if(fLogs)
        Synchronize(SetSettings);
    else
        TThread::DoTerminate();
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::Test()
{
   // ShowMessage(N);
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::SetSettings()
{
    SmartBackup = fLogs->SmartBackup;
    InstallMode = fLogs->InstallMode;
    InstallType = fLogs->InstallType;
    GameTag     = fLogs->GameTag;
    GameFolder  = fLogs->GameFolder;
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::DoTerminate()
{
    TThread::DoTerminate();
}
//---------------------------------------------------------------------------
__fastcall InstallArchiveThread::~InstallArchiveThread()
{
    delete DFUnRar1;
    delete ZipBuilder1;
    delete umod;
    delete FileList;
    delete LogList;
    delete sbLogList;
}
//---------------------------------------------------------------------------
// Main Execute()
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::Execute()
{
    if(Terminated==false)
    {
        int iCount = FileList->Count;

        for(Num=0;Num<iCount;Num++) // loop throught the files types
        {
            switch(GetArchiveType(ExtractFileExt(FileList->Files[Num]->FileName)))
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
inline int __fastcall InstallArchiveThread::GetArchiveType(AnsiString ArchiveExt)
{   // should be Synchronize or a new TRegistry call altogether
    int functionNumber  = 5;
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_LOCAL_MACHINE;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\InstallTypes\\" + GameTag, false))
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
void __fastcall InstallArchiveThread::InstallZip()
{
    if(ZipBuilder1->IsZipSFX(FileList->Files[Num]->FileLocation + FileList->Files[Num]->FileName)==1) // if we have a valid archive??
    {
        ZipBuilder1->ZipFileName = FileList->Files[Num]->FileLocation + FileList->Files[Num]->FileName; // assign to zip component
        ArchiveName = ZipBuilder1->ZipFileName;
        ZipBuilder1->ExtrOptions.Clear();    // clear for default
        // Logs
        AStruct = LogList->AddFile();

        if(AStruct)
        {   // Main Zip File used ofr logging, always add first!
            AStruct->FileName     = FileList->Files[Num]->FileName;
            AStruct->FileDate     = FileList->Files[Num]->FileDate;
            AStruct->FileSize     = FileList->Files[Num]->FileSize;
            AStruct->FileLocation = FileList->Files[Num]->FileLocation;
            AStruct->BelongsTo    = -1;
        }
        // Logs

        switch(InstallMode)
        {
            case MM_IM_Smart : ZipBuilder1->ExtrOptions << ExtrUpdate;    break;
            case MM_IM_Force : ZipBuilder1->ExtrOptions << ExtrOverWrite; break;
        }

        for(int x=0;x<ZipBuilder1->Count;x++) // loop through archive files
		{

			//TZBDirEntry* Entry = ZipBuilder->DirEntry[i];

			//ZipBuilder1->Z
			//ZipDirEntry *zde = (ZipDirEntry *)ZipBuilder1->ZipContents->Items[x];
			//ZipBuilder1->FSpecArgs->Clear(); // clear all info from FSpecArgs
			//ZipBuilder1->FSpecArgs->Add(zde->FileName);
		   // ZipBuilder1->ExtrBaseDir = IncludeTrailingPathDelimiter(GameFolder + GetFileFolder(ExtractFileExt(zde->FileName)));
			//tmpFileName = ZipBuilder1->ExtrBaseDir + zde->FileName;
            // Logs
            AStruct = LogList->AddFile();

            if(AStruct)
            {
				//AStruct->FileName     = ExtractFileName(zde->FileName);
				//AStruct->FileDate     = DateTimeToStr(FileDateToDateTime(zde->DateTime));
				//AStruct->FileSize     = FormatFloat("#,##0", zde->UncompressedSize);
				//AStruct->FileLocation = ZipBuilder1->ExtrBaseDir;
				//AStruct->BelongsTo    = 0;// added to make sure it doesnt get cauth in the InsertRecord() block checking for -1
				//AStruct->CRC32        = zde->CRC32;
            }
            // Logs
			//ZipBuilder1->Extract();
            Synchronize(OnFileInstalledEvent);
        }

        Synchronize(AddLog); // used for archive logging
    }
    else
        Synchronize(MessageError);
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallRar()
{
    DFUnRar1->FileName  = FileList->Files[Num]->FileLocation + FileList->Files[Num]->FileName;
    DFUnRar1->Directory = GameFolder; // default location
    DFUnRar1->Mode      = DFRAR_EXTRACT;
    ArchiveName         = DFUnRar1->FileName;

    switch(InstallMode)
    {
        case MM_IM_None  : DFUnRar1->OverrideEvent = OR_NEVER;  break;
        case MM_IM_Force : DFUnRar1->OverrideEvent = OR_ALWAYS; break; 
        default          : DFUnRar1->OverrideEvent = OR_EVENT;  break; // MM_IM_Smart
    }

    // Logs
    AStruct = LogList->AddFile();

    if(AStruct)
    {
        AStruct->FileName     = FileList->Files[Num]->FileName;
        AStruct->FileDate     = FileList->Files[Num]->FileDate;
        AStruct->FileSize     = FileList->Files[Num]->FileSize;
        AStruct->FileLocation = FileList->Files[Num]->FileLocation;
        AStruct->CRC32        = FileList->Files[Num]->CRC32;
        AStruct->BelongsTo    = -1;
    }
    // Logs

    switch(InstallType)
    {
		case MM_IT_KeepFolders : DFUnRar1->Extract();  break;    //keep folders?
		default                : DFUnRar1->Extract(); break;     // just dump files
    }

    Synchronize(AddLog); // used for archive logging
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::DFUnRar1FileProcessing(TObject *Sender, const TDFRARHeaderData &hdrData, int status) // event for get info function on rar files
{
    if(InstallType==MM_IT_DropFolders)// Drop folders
    {
        DFUnRar1->Directory = IncludeTrailingPathDelimiter(GameFolder + GetFileFolder(ExtractFileExt(hdrData.FileName)));
        tmpFileName = DFUnRar1->Directory + ExtractFileName(hdrData.FileName);
    }
    else
        tmpFileName = DFUnRar1->Directory + hdrData.FileName;

    if(!hdrData.IsDirectory) // only add files
    {
        // Logs
        AStruct = LogList->AddFile();

        if(AStruct)
        {
            AStruct->FileName     = ExtractFileName(tmpFileName);
            AStruct->FileDate     = DateTimeToStr(hdrData.FileTime);
			AStruct->FileSize     = hdrData.UnpSize;// FormatFloat("#,##0", hdrData.UnpSize);
            AStruct->FileLocation = ExtractFilePath(tmpFileName);
            AStruct->CRC32        = StrToIntDef(hdrData.FileCRC, 0);
        }
        // Logs

        Synchronize(OnFileInstalledEvent);
    }
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::DFUnRar1Override(TObject *Sender, UnicodeString FileName, bool &CanOverride, const Untunrar::TRARHeaderData &hdrData)
{
    AnsiString tmp = "";
    switch(InstallMode)
    {
		case MM_IM_Smart : CanOverride = (CompareDateTime(FileDateToDateTime(hdrData.FileTime), FileDateToDateTime(FileAge(FileName)))==1)? true : false; break;// A is earlier than B - older
        case MM_IM_Force : CanOverride = true; break;                         
        default          : CanOverride = false;
    }

//    Synchronize(Test);

    // only rename if newer! this way theres no need to delete the old .old file if not updating
    if(SmartBackup==MM_SB_RenameFile && CanOverride) // rename anyway!
    {
        if(FileExists(FileName + ".old")) // so .old file is always the newest 1
            DeleteFile(FileName + ".old");

        if(RenameFile(FileName, FileName + ".old")) // rename should work replacing the old .old file
        {//AddFile(AnsiString aFileName, AnsiString aFileSize, AnsiString aFileDate, AnsiString aInstalled, int aNum, int aBelongsTo)
            sbLogList->AddFile(FileName,          hdrData.UnpSize, DateTimeToStr(FileDateToDateTime(hdrData.FileTime)),           "Yes", 0, -1);
            sbLogList->AddFile(FileName + ".old", GetFileSize(FileName + ".old"),        DateTimeToStr(FileDateToDateTime(FileAge(FileName + ".old"))), "Yes", 0, 0); // 0 for default
            Synchronize(AddsbLog); // used for archive logging
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallMap()
{
    tmpFileName = IncludeTrailingBackslash(GameFolder + GetFileFolder(ExtractFileExt(FileList->Files[Num]->FileName))) + FileList->Files[Num]->FileName;
    ArchiveName = FileList->Files[Num]->FileLocation + FileList->Files[Num]->FileName;

    if(FileExists(tmpFileName))
    {
        if(CompareDateTime(FileDateToDateTime(FileAge(ArchiveName)), FileDateToDateTime(FileAge(tmpFileName)))==1) // A is earlier than B - older
        {
            if(FileExists(tmpFileName + ".old"))
                DeleteFile(tmpFileName + ".old");

            if(RenameFile(tmpFileName, tmpFileName + ".old"))
            {
                AStruct = sbLogList->AddFile(); // map in archive folder

                if(AStruct)
                {
                    AStruct->FileName     = FileList->Files[Num]->FileName;
                    AStruct->FileDate     = FileList->Files[Num]->FileDate;
                    AStruct->FileSize     = FileList->Files[Num]->FileSize;
                    AStruct->FileLocation = FileList->Files[Num]->FileLocation;
                    AStruct->CRC32        = FileList->Files[Num]->CRC32;
                    AStruct->BelongsTo    = -1;
                }

                AStruct = sbLogList->AddFile(); // map in map folder

                if(AStruct)
                {
                    AStruct->FileName     = ExtractFileName(tmpFileName);
                    AStruct->FileDate     = DateTimeToStr(FileDateToDateTime(FileAge(tmpFileName)));
					AStruct->FileSize     = GetFileSize(tmpFileName);
                    AStruct->FileLocation = ExtractFilePath(tmpFileName);
					//AStruct->CRC32        = GetCRC32(tmpFileName);
                }

                Synchronize(AddsbLog);
            }
        }
        else
            if(InstallMode==MM_IM_Smart)
                return; // file being installed is not newer, its older so dont install
    }

    switch(InstallMode)
    {
		case MM_IM_Force : CopyFile(UnicodeString(ArchiveName).c_str(), UnicodeString(tmpFileName).c_str(), false); break;
		default          : CopyFile(UnicodeString(ArchiveName).c_str(), UnicodeString(tmpFileName).c_str(), true);  break;
    }

	Synchronize(OnFileInstalledEvent);

    // Logs
    AStruct = LogList->AddFile(); // map in archive folder
    if(AStruct)
    {
        AStruct->FileName     = FileList->Files[Num]->FileName;
        AStruct->FileDate     = FileList->Files[Num]->FileDate;
        AStruct->FileSize     = FileList->Files[Num]->FileSize;
        AStruct->FileLocation = FileList->Files[Num]->FileLocation;
        AStruct->CRC32        = FileList->Files[Num]->CRC32;
    }

    AStruct = LogList->AddFile(); // map in map folder
    if(AStruct)
    {
        AStruct->FileName     = ExtractFileName(tmpFileName);
        AStruct->FileDate     = DateTimeToStr(FileDateToDateTime(FileAge(tmpFileName)));
		AStruct->FileSize     = GetFileSize(tmpFileName);
        AStruct->FileLocation = ExtractFilePath(tmpFileName);
        //AStruct->CRC32        = GetCRC32(tmpFileName);
    }
    // Logs
}
//---------------------------------------------------------------------------
//AnsiString __fastcall InstallArchiveThread::GetFileSize(AnsiString FileName)
__int64 __fastcall InstallArchiveThread::GetFileSize(AnsiString FileName)
{
    TSearchRec sr;

    FindFirst(FileName, faAnyFile, sr);
	__int64 size = sr.Size;
    FindClose(sr);

	//return FormatFloat("#,##0", size);
	return size;
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::OnZipExtFileExistsEvent(TObject *Sender, String ForFile, bool IsOlder, bool &DoOverwrite, int DirIndex)
{
    switch(InstallMode)
    {
        case MM_IM_Smart : DoOverwrite = (IsOlder) ? true : false; break;
        case MM_IM_Force : DoOverwrite = true;                     break;
    }

    if(SmartBackup==MM_SB_RenameFile && DoOverwrite) // rename anyway!
    {
        if(FileExists(ForFile + ".old")) // so .old file is always the newest 1
            DeleteFile(ForFile + ".old");

        if(RenameFile(ForFile, ForFile + ".old")) // rename should work replacing the old .old file
            Synchronize(AddsbLog);
    }
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallUmod()
{
    if(umod->IsUMOD(FileName))
    {
        umod->Load(FileName);
        umod->ExtractAll(GameFolder); // game folder
    }
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallUz()
{
    AStruct = LogList->AddFile();

    if(AStruct)
    {
        AStruct->FileName     = ExtractFileName(FileName);
        AStruct->FileDate     = ""; // getdate
		AStruct->FileSize     = 0; // getsize (compressed)
        AStruct->FileLocation = ExtractFilePath(FileName);
        //AStruct->CRC32        = GetCRC32(FileName);
    }

    // uncompress and copy to new folder
    // set date of new file to the old file!!!

    AStruct = LogList->AddFile();

    if(AStruct)
    {
        AStruct->FileName     = ExtractFileName(FileName);
        AStruct->FileDate     = ""; // set to uz2 filedate!!!
        AStruct->FileSize     = 0; // getsize (uncompressed)
        AStruct->FileLocation = ExtractFilePath(FileName);
        //AStruct->CRC32        = GetCRC32(FileName);
    }

    Synchronize(AddLog); // used for archive logging
}
//---------------------------------------------------------------------------
// Events
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::OnArchiveInstalledEvent()
{
    Total++;

    if(FOnArchiveInstalled)
        FOnArchiveInstalled(this, ArchiveName);
}
//---------------------------------------------------------------------------  
void __fastcall InstallArchiveThread::OnFileInstalledEvent()
{
    if(FOnFileInstalled)
        FOnFileInstalled(this, FileList->Files[Num]->FileLocation + FileList->Files[Num]->FileName, tmpFileName);
}
//---------------------------------------------------------------------------
AnsiString __fastcall InstallArchiveThread::GetFileFolder(AnsiString ArchiveExt)
{
    AnsiString Folder = "Help";
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_LOCAL_MACHINE;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + GameTag + "\\Cache", false))
    {
        if(Registry->ValueExists(ArchiveExt))
            Folder = Registry->ReadString(ArchiveExt);
        else
            Folder = Registry->ReadString("default");   

        Registry->CloseKey();
    }

    delete Registry;
    return Folder;
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallError(TObject *Sender, int ErrCode, UnicodeString Message)
{
    // error
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::MessageError()  // not really needed
{
    int ZipErrorCode = 2;
    AnsiString ZipErrorMessage = ExtractFileName(FileName) + " is an unsusported archive format.";
    ShowMessage(ExtractFileName(FileName) + " encountered some errors.\nZip Erro Code: " + ZipErrorCode + "\nZip Error Message: " + ZipErrorMessage);
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::AddLog()
{
    fLogs->LoadFromFile("Archives" + GameTag + ".xml");
	fLogs->AddArchiveLogEntry(LogList);
	//LogList->Clear(); // always reset after adding the log
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::AddsbLog()
{
    AnsiString oldLogFile = fLogs->LogFile;
    fLogs->LoadFromFile("SmartBackup" + GameTag + ".xml");
    fLogs->AddSmartBackupLogEntry(sbLogList);
	//sbLogList->Clear(); // always reset after adding the log
	//sbLogList->Count=0;
    fLogs->LoadFromFile(oldLogFile);
}
//---------------------------------------------------------------------------
