//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <Dialogs.hpp>
#include "MMArchiveEngine.hpp"
#include <Winapi.Windows.hpp>
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
    if (functionNumber == 5)
    {
        if (SameText(UnicodeString(ArchiveExt), L".zip") ||
            SameText(UnicodeString(ArchiveExt), L".7z")) return 0;
        if (SameText(UnicodeString(ArchiveExt), L".rar")) return 1;
    }
    return functionNumber;

   // return StrToIntDef(fLogs->GetDataFor("\\SOFTWARE\\Nasty PC's\\Map Manager\\InstallTypes\\" + GameTag, ArchiveExt), 5);
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallZip()
{
    InstallPacked();
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallRar()
{
    InstallPacked();
}
//---------------------------------------------------------------------------
void __fastcall InstallArchiveThread::InstallPacked()
{
    const UnicodeString archiveName = UnicodeString(FileList->Files[Num]->FileLocation + FileList->Files[Num]->FileName);
    TMMArchiveEngine *archive = new TMMArchiveEngine();
    try
    {
        archive->Open(archiveName);
        ArchiveName = AnsiString(archiveName);
        AStruct = LogList->AddFile();
        if (AStruct)
        {
            AStruct->FileName = FileList->Files[Num]->FileName;
            AStruct->FileDate = FileList->Files[Num]->FileDate;
            AStruct->FileSize = FileList->Files[Num]->FileSize;
            AStruct->FileLocation = FileList->Files[Num]->FileLocation;
            AStruct->CRC32 = FileList->Files[Num]->CRC32;
            AStruct->BelongsTo = -1;
        }

        for (int i = 0; i < archive->Count && !Terminated; ++i)
        {
            if (archive->ItemIsFolder[i]) continue;
            const UnicodeString member = TMMArchiveEngine::SafeRelativePath(archive->ItemPath[i]);
            const UnicodeString name = ExtractFileName(member);
            // Game folder mapping is based on the extracted file's extension.
            const UnicodeString gameBase = IncludeTrailingPathDelimiter(
                ExpandFileName(UnicodeString(GameFolder) +
                    GetFileFolder(AnsiString(ExtractFileExt(name)))));
            const UnicodeString relative = (InstallType == MM_IT_DropFolders)
                ? name : member;
            const UnicodeString target = ExpandFileName(gameBase + relative);
            if (!SameText(target.SubString(0, gameBase.Length()), gameBase))
                throw Exception(L"Archive entry escapes game directory: " + member);
            tmpFileName = AnsiString(target);
            const bool exists = FileExists(target);
            if (exists)
            {
                if (InstallMode == MM_IM_None)
                    continue;
                if (InstallMode == MM_IM_Smart)
                {
                    const int age = FileAge(target);
                    TDateTime oldDate(0.0);
                    if (age != -1) oldDate = FileDateToDateTime(age);
                    if (archive->ItemDate[i] <= oldDate)
                        continue;
                }
            }
            // Extract into same-directory staging FIRST. No existing file is
            // removed until d7zip has successfully decoded and verified it.
            const UnicodeString stage = target + L".mm-stage";
            if (FileExists(stage))
                throw Exception(L"Installation staging file already exists: " + stage);
            archive->ExtractItemToFile(i, stage);
            bool committed = false;
            try
            {
                if (Terminated) break;
                if (exists && SmartBackup == MM_SB_RenameFile)
                {
                    const UnicodeString backup = target + L".old";
                    // Match historical smart-backup layout but never create a
                    // partial installed file.
                    if (FileExists(backup) && !DeleteFile(backup))
                        throw Exception(L"Cannot replace prior backup: " + backup);
                    if (!RenameFile(target, backup))
                        throw Exception(L"Cannot back up installed file: " + target);
                    if (!MoveFileExW(stage.c_str(), target.c_str(), MOVEFILE_WRITE_THROUGH))
                    {
                        RenameFile(backup, target); // restore if promotion fails
                        RaiseLastOSError();
                    }
                    sbLogList->AddFile(AnsiString(target), archive->ItemSize[i],
                        DateTimeToStr(archive->ItemDate[i]), "Yes", 0, -1);
                    sbLogList->AddFile(AnsiString(backup), GetFileSize(AnsiString(backup)),
                        DateTimeToStr(archive->ItemDate[i]), "Yes", 0, 0);
                    Synchronize(AddsbLog);
                }
                else if (!MoveFileExW(stage.c_str(), target.c_str(),
                        MOVEFILE_WRITE_THROUGH | (exists ? MOVEFILE_REPLACE_EXISTING : 0)))
                    RaiseLastOSError();
                committed = true;
                if (double(archive->ItemDate[i]) > 0.0)
                    FileSetDate(target, DateTimeToFileDate(archive->ItemDate[i]));
                AStruct = LogList->AddFile();
                if (AStruct)
                {
                    AStruct->FileName = AnsiString(name);
                    AStruct->FileDate = (double(archive->ItemDate[i]) > 0.0)
                        ? AnsiString(DateTimeToStr(archive->ItemDate[i])) : AnsiString("");
                    AStruct->FileSize = archive->ItemSize[i];
                    AStruct->FileLocation = AnsiString(ExtractFilePath(target));
                    AStruct->CRC32 = archive->ItemCRC[i];
                    AStruct->BelongsTo = 0;
                }
                Synchronize(OnFileInstalledEvent);
            }
            __finally
            {
                if (!committed && FileExists(stage)) DeleteFile(stage);
            }
        }
        if (!Terminated) Synchronize(AddLog);
    }
    __finally { delete archive; }
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
