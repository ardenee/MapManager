//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TArchives.h"
#include "MMArchiveEngine.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TArchives::TArchives(TFiles* Owner)
          : TPersistent()
{
    FFiles = Owner;
    FArchiveTypes   = new TStringList;
    FArchiveFilters = new TStringList;
	FFileList = new TMMFileList; // used for getting info about files
}
//---------------------------------------------------------------------------
__fastcall TArchives::~TArchives()
{
    delete FArchiveTypes;
    delete FArchiveFilters;
    delete FFileList;
}
//---------------------------------------------------------------------------
void __fastcall TArchives::SetLoadArchivesType(TMM_LoadFilesType Value)
{
    FLoadArchivesType = Value;
}
//---------------------------------------------------------------------------
void __fastcall TArchives::SetStringLists(const int Index, TStrings* Value)
{
    switch(Index)
    {
    	case 0 : FArchiveTypes->Clear();   FArchiveTypes->AddStrings(Value);   break;
    	case 1 : FArchiveFilters->Clear(); FArchiveFilters->AddStrings(Value); break;
    }
}
//----------------------------------------------------------------------------
// Events
//----------------------------------------------------------------------------
void __fastcall TArchives::OnFileInstalledEvent(TObject *Sender, AnsiString FileName, AnsiString ArchiveName)
{
    if(FOnFileInstalled)
        FOnFileInstalled(this, FileName, ArchiveName);
}
//----------------------------------------------------------------------------
void __fastcall TArchives::OnArchiveInstalledEvent(TObject *Sender, AnsiString Archive)
{
    if(FOnArchiveInstalled)
        FOnArchiveInstalled(this, Archive);
}
//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------
void __fastcall TArchives::Install(TMMFileList* pFileList)
{
	TMMFileList* insList = new TMMFileList;
    insList->Copy(pFileList);
    FInstallFiles = new InstallArchiveThread(true, FFiles, insList);
    FInstallFiles->OnFileInstalled    = OnFileInstalledEvent;
    FInstallFiles->OnArchiveInstalled = OnArchiveInstalledEvent;
    FInstallFiles->Resume();
    delete insList;
}
//----------------------------------------------------------------------------
void __fastcall TArchives::StopInstalling()
{
    if(FInstallFiles)
        FInstallFiles->Terminate();
}
//---------------------------------------------------------------------------
int __fastcall TArchives::GetArchiveFuncType(AnsiString ArchiveExt)
{
    return StrToIntDef(FFiles->GetDataFor("\\SOFTWARE\\Nasty PC's\\Map Manager\\InstallTypes\\" + FFiles->GameTag, ArchiveExt), 5);
}
//----------------------------------------------------------------------------
void __fastcall TArchives::GetArchiveInfo(AnsiString FileName)
{
    //FFileList->Clear();

    const UnicodeString ext = ExtractFileExt(FileName);
    if (SameText(ext, L".7z") || SameText(ext, L".zip") ||
        SameText(ext, L".rar"))
    {
        GetPackedInfo(FileName);
        return;
    }
    switch(GetArchiveFuncType(ExtractFileExt(FileName)))
    {
        case 0  : GetZipInfo(FileName);  break;
        case 1  : GetRarInfo(FileName);  break;
        case 2  : GetUmodInfo(FileName); break;
        case 3  : GetUzInfo(FileName);   break;
        default : break;
    }
}
//----------------------------------------------------------------------------
void __fastcall TArchives::GetZipInfo(AnsiString FileName)
{
    GetPackedInfo(FileName);
}
//---------------------------------------------------------------------------
void __fastcall TArchives::GetRarInfo(AnsiString FileName)
{
    GetPackedInfo(FileName);
}
//---------------------------------------------------------------------------
void __fastcall TArchives::GetPackedInfo(AnsiString FileName)
{
    TMMArchiveEngine *archive = new TMMArchiveEngine();
    try
    {
        archive->Open(UnicodeString(FileName));
        FFileList->Clear();
        PFileInfo file = FFileList->AddFile();
        if (file) FFiles->GetFileInfo(FileName, file);
        for (int i = 0; i < archive->Count; ++i)
        {
            if (archive->ItemIsFolder[i]) continue;
            file = FFileList->AddFile();
            if (!file) continue;
            const UnicodeString member = TMMArchiveEngine::SafeRelativePath(archive->ItemPath[i]);
            file->FileName = (FFiles->TSettings::InstallType == MM_IT_DropFolders)
                ? ExtractFileName(member) : member;
            file->FileSize = archive->ItemSize[i];
            file->FileDate = (double(archive->ItemDate[i]) > 0.0)
                ? AnsiString(DateTimeToStr(archive->ItemDate[i])) : AnsiString("");
            file->CRC32 = archive->ItemCRC[i];
        }
        if (FOnGotFileInfo) FOnGotFileInfo(this, FFileList);
    }
    __finally { delete archive; }
}
//---------------------------------------------------------------------------
// wrappers for the TFiles class
//---------------------------------------------------------------------------
void __fastcall TArchives::GetUmodInfo(AnsiString FileName)
{
    TUMOD* umod = new TUMOD();

    if(umod->IsUMOD(FileName))
    {
        TMMFileList* FileList = new TMMFileList;
        umod->Load(FileName);
        PFileInfo aFileData = FileList->AddFile();

        if(aFileData)
        {
            FFiles->GetFileInfo(FileName, aFileData);

            for(int i=0;i<umod->Count;i++)
            {
                aFileData = FileList->AddFile();

                if(aFileData)
                {
                    aFileData->FileName     = ExtractFileName(umod->Files[i]);
                    aFileData->FileSize     = umod->Size[i];// FormatFloat("#,##0", umod->Size[i]);
                    aFileData->FileLocation = FFiles->GameFolder + ExtractFilePath(umod->Files[i]);
                    aFileData->FileDate     = "";
                }
            }

            if(FOnGotFileInfo)
                FOnGotFileInfo(this, FileList);
        }

        delete FileList;
    }

    delete umod;
}
//---------------------------------------------------------------------------
void __fastcall TArchives::GetUzInfo(AnsiString FileName)
{
    // stuff
}
//---------------------------------------------------------------------------
// wrapers for the TFiles class
//---------------------------------------------------------------------------
void __fastcall TArchives::GetArchives()
{
    FFiles->GetFileList(FFiles->ArchiveFolder, FFiles->ArchiveSubFolders, LoadArchivesType, ArchiveFilters, ArchiveTypes);
}                       
//---------------------------------------------------------------------------
void __fastcall TArchives::UninstallArchives(TMMFileList* pArchiveList)
{
    FFiles->LoadFromFile("Archives" + FFiles->GameTag + ".xml");
    FFiles->UninstallFiles(pArchiveList);
}
//---------------------------------------------------------------------------
void __fastcall TArchives::RenameArchives(TMMFileList* pArchiveList)
{
    FFiles->RenameFiles(pArchiveList);
}
//---------------------------------------------------------------------------
void __fastcall TArchives::DeleteArchives(TMMFileList* pArchiveList)
{
    FFiles->DeleteFiles(pArchiveList);
}
//---------------------------------------------------------------------------
void __fastcall TArchives::FindArchives(TMMFileList* pArchiveList, AnsiString pSubString)
{
    FFiles->FindFile(pArchiveList, pSubString);
}
//---------------------------------------------------------------------------
void __fastcall TArchives::GetArchiveTypes()
{
    FFiles->GetValues("\\SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + FFiles->GameTag + "\\Archives", ArchiveTypes);
}
//---------------------------------------------------------------------------
void __fastcall TArchives::GetArchiveFilters()
{
    FFiles->GetValues("\\SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + FFiles->GameTag + "\\Archives", ArchiveFilters);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TArchives::GetArchiveType(AnsiString pMapFilter)
{
    return FFiles->GetValueFor("\\SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + FFiles->GameTag + "\\Archives", pMapFilter);
}
//----------------------------------------------------------------------------

