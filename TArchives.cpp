//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TArchives.h"
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
    TZipBuilder* ZipBuilder = new TZipBuilder(NULL);

    if(ZipBuilder->IsZipSFX(FileName)==1) // if we have a valid archive??
    {
        ZipBuilder->ZipFileName = FileName;
        PFileInfo aFileData    = FFileList->AddFile();

        if(aFileData)
        {
            FFiles->GetFileInfo(FileName, aFileData);

            for(int x=0;x<ZipBuilder->Count;x++) // loop through archive files
            {
                aFileData        = FFileList->AddFile();
                //ZipDirEntry *zde = (ZipDirEntry *)ZipBuilder->ZipContents->Items[x];

                if(aFileData)
                {
				  //  aFileData->FileName = ExtractFileName(zde->FileName);
				  //  aFileData->FileSize = FormatFloat("#,##0", zde->UncompressedSize);
                  //  aFileData->FileDate = DateTimeToStr(FileDateToDateTime(zde->DateTime));
                }
            }

            if(FOnGotFileInfo)
                FOnGotFileInfo(this, FFileList);
        }
    }

    delete ZipBuilder;
}
//---------------------------------------------------------------------------
void __fastcall TArchives::GetRarInfo(AnsiString FileName)
{
    if(FileExists(FileName))
    {
        TDFUnRar* DFUnRar1 = new TDFUnRar(NULL);
        DFUnRar1->OnFileProcessing = DFUnRar1FileProcessing;
        // set up events!
        DFUnRar1->FileName   = FileName;
        DFUnRar1->Mode       = DFRAR_LIST;  
        PFileInfo aFileData = FFileList->AddFile();

        if(aFileData)
        {
            FFiles->GetFileInfo(FileName, aFileData);

            switch(FFiles->TSettings::InstallType)
            {
				case  0 : DFUnRar1->Extract();  break; // keep folders
                default : DFUnRar1->Extract(); break;// drop flders keep files only
            }

            if(FOnGotFileInfo)
                FOnGotFileInfo(this, FFileList);
        }

        delete DFUnRar1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TArchives::DFUnRar1FileProcessing(TObject *Sender, const TDFRARHeaderData &hdrData, int status)
{
    if(!hdrData.IsDirectory)
    {
        PFileInfo aFileData = FFileList->AddFile();

        if(aFileData)
        {
            if(FFiles->TSettings::InstallType == MM_IT_DropFolders) // for display reasons
                aFileData->FileName = ExtractFileName(hdrData.FileName);
            else
                aFileData->FileName = hdrData.FileName;

			aFileData->FileSize = hdrData.UnpSize;// FormatFloat("#,##0", hdrData.UnpSize);
            aFileData->FileDate = DateTimeToStr(hdrData.FileTime);
        }
    }
}
//---------------------------------------------------------------------------
// wrapers for the TFiles class
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

