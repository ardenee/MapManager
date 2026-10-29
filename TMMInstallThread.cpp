//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <Dialogs.hpp>
#include "MMArchiveEngine.hpp"
#include <Winapi.Windows.hpp>
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
void __fastcall TMMInstallThread::InstallZip()
{
    InstallPacked();
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallRar()
{
    InstallPacked();
}
//---------------------------------------------------------------------------
void __fastcall TMMInstallThread::InstallPacked()
{
    const UnicodeString archiveName = UnicodeString(fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName);
    TMMArchiveEngine *archive = new TMMArchiveEngine();
    try
    {
        archive->Open(archiveName);
        fArchiveName = AnsiString(archiveName);
        fStruct = fLogList->AddFile();
        if (fStruct)
        {
            fStruct->FileName = fFileList->Files[fNum]->FileName;
            fStruct->FileDate = fFileList->Files[fNum]->FileDate;
            fStruct->FileSize = fFileList->Files[fNum]->FileSize;
            fStruct->FileLocation = fFileList->Files[fNum]->FileLocation;
            fStruct->CRC32 = fFileList->Files[fNum]->CRC32;
            fStruct->BelongsTo = -1;
        }

        for (int i = 0; i < archive->Count && !Terminated; ++i)
        {
            if (archive->ItemIsFolder[i]) continue;
            const UnicodeString member = TMMArchiveEngine::SafeRelativePath(archive->ItemPath[i]);
            const UnicodeString name = ExtractFileName(member);
            // Game folder mapping is based on the extracted file's extension.
            const UnicodeString gameBase = IncludeTrailingPathDelimiter(
                ExpandFileName(UnicodeString(fGameFolder) +
                    GetFileFolder(AnsiString(ExtractFileExt(name)))));
            const UnicodeString relative = (fInstallType == MM_IT_DropFolders)
                ? name : member;
            const UnicodeString target = ExpandFileName(gameBase + relative);
            if (!SameText(target.SubString(0, gameBase.Length()), gameBase))
                throw Exception(L"Archive entry escapes game directory: " + member);
            fTmpFileName = AnsiString(target);
            const bool exists = FileExists(target);
            if (exists)
            {
                if (fInstallMode == MM_IM_None)
                    continue;
                if (fInstallMode == MM_IM_Smart)
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
                if (exists && fSmartBackup == MM_SB_RenameFile)
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
                    fSBLogList->AddFile(AnsiString(target), archive->ItemSize[i],
                        DateTimeToStr(archive->ItemDate[i]), "Yes", 0, -1);
                    fSBLogList->AddFile(AnsiString(backup), GetFileSize(AnsiString(backup)),
                        DateTimeToStr(archive->ItemDate[i]), "Yes", 0, 0);
                    Synchronize(AddsbLog);
                }
                else if (!MoveFileExW(stage.c_str(), target.c_str(),
                        MOVEFILE_WRITE_THROUGH | (exists ? MOVEFILE_REPLACE_EXISTING : 0)))
                    RaiseLastOSError();
                committed = true;
                if (double(archive->ItemDate[i]) > 0.0)
                    FileSetDate(target, DateTimeToFileDate(archive->ItemDate[i]));
                fStruct = fLogList->AddFile();
                if (fStruct)
                {
                    fStruct->FileName = AnsiString(name);
                    fStruct->FileDate = (double(archive->ItemDate[i]) > 0.0)
                        ? AnsiString(DateTimeToStr(archive->ItemDate[i])) : AnsiString("");
                    fStruct->FileSize = archive->ItemSize[i];
                    fStruct->FileLocation = AnsiString(ExtractFilePath(target));
                    fStruct->CRC32 = archive->ItemCRC[i];
                    fStruct->BelongsTo = 0;
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
