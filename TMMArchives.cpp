//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TMMArchives.h"
#include "MMArchiveEngine.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TMMArchives::TMMArchives(TMMEventManager* pEventManager)
          : TMMFiles()
{
    fFileTypes        = new TStringList;
    fFileFilters      = new TStringList;
    fFileDiscriptions = new TStringList;
	SetEventManager(pEventManager);
    RefreshSettings();
}
//---------------------------------------------------------------------------
__fastcall TMMArchives::~TMMArchives()
{
    delete fFileTypes;
    delete fFileFilters;
    delete fFileDiscriptions;
}
//---------------------------------------------------------------------------
void __fastcall TMMArchives::RefreshSettings()
{
	fFolder     = this->PEventManager->XMLSettings->ArchiveFolder;
	fSubFolders = this->PEventManager->XMLSettings->ArchiveSubFolders;
	fGameFolder = this->PEventManager->XMLSettings->GameFolder;
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
void __fastcall TMMArchives::SetLoadFilesType(TMM_LoadFilesType pValue)
{
    fLoadFilesType = pValue;
}
//----------------------------------------------------------------------------
void __fastcall TMMArchives::SetStringLists(const int Index, TStrings* pValue)
{
    switch(Index)
    {
    	case 0 : fFileTypes->Clear();        fFileTypes->AddStrings(pValue);        break;
    	case 1 : fFileFilters->Clear();      fFileFilters->AddStrings(pValue);      break;
        case 2 : fFileDiscriptions->Clear(); fFileDiscriptions->AddStrings(pValue); break;
    }
}
//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------
void __fastcall TMMArchives::Install(PFileList pFileList)
{
    PFileList insList = new TMMFileList;
    insList->Copy(pFileList);
	//fInstallFiles = new TMMInstallThread(true, fFiles, insList);
	//fInstallFiles->OnFileInstalled    = fFiles->PEventManager->OnFileInstalled;//OnFileInstalledEvent;
	//fInstallFiles->OnArchiveInstalled = fFiles->PEventManager->OnArchiveInstalledEvent;
    //fInstallFiles->Resume();
    delete insList;
}
//----------------------------------------------------------------------------
void __fastcall TMMArchives::StopInstalling()
{
    if(fInstallFiles)
        fInstallFiles->Terminate();
}
//---------------------------------------------------------------------------
int __fastcall TMMArchives::GetFileFuncType(AnsiString pArchiveExt)
{
    if (SameText(UnicodeString(pArchiveExt), L".rar")) return 1;
    if (SameText(UnicodeString(pArchiveExt), L".umod") ||
        SameText(UnicodeString(pArchiveExt), L".ut2mod")) return 2;
    if (SameText(UnicodeString(pArchiveExt), L".uz") ||
        SameText(UnicodeString(pArchiveExt), L".uz2")) return 3;
    if (SameText(UnicodeString(pArchiveExt), L".zip") ||
        SameText(UnicodeString(pArchiveExt), L".7z") ||
        SameText(UnicodeString(pArchiveExt), L".exe")) return 0;
    return 5;
}
//----------------------------------------------------------------------------
void __fastcall TMMArchives::GetFileInfo(AnsiString pFileName)
{
    //FFileList->Clear();

    switch(GetFileFuncType(ExtractFileExt(pFileName)))
    {
        case 0  : GetZipInfo(pFileName);  break;
        case 1  : GetRarInfo(pFileName);  break;
        case 2  : GetUmodInfo(pFileName); break;
        case 3  : GetUzInfo(pFileName);   break;
        default : break;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMArchives::GetZipInfo(AnsiString pFileName)
{
    GetPackedInfo(pFileName);
}
//---------------------------------------------------------------------------
void __fastcall TMMArchives::GetRarInfo(AnsiString pFileName)
{
    GetPackedInfo(pFileName);
}
//---------------------------------------------------------------------------
void __fastcall TMMArchives::GetPackedInfo(AnsiString pFileName)
{
    TMMArchiveEngine *archive = new TMMArchiveEngine();
    try
    {
        archive->Open(UnicodeString(pFileName));
        if (!FileList) return;
        FileList->Clear();
        PFileInfo file = FileList->AddFile();
        if (file) TMMFiles::GetFileInfo(pFileName, file);
        for (int i = 0; i < archive->Count; ++i)
        {
            if (archive->ItemIsFolder[i]) continue;
            file = FileList->AddFile();
            if (!file) continue;
            const UnicodeString member = TMMArchiveEngine::SafeRelativePath(archive->ItemPath[i]);
            file->FileName = member;
            file->FileSize = archive->ItemSize[i];
            file->FileDate = (double(archive->ItemDate[i]) > 0.0)
                ? AnsiString(DateTimeToStr(archive->ItemDate[i])) : AnsiString("");
            file->CRC32 = archive->ItemCRC[i];
        }
    }
    __finally { delete archive; }
}
//---------------------------------------------------------------------------
// wrappers for the TFiles class
//---------------------------------------------------------------------------
void __fastcall TMMArchives::GetUmodInfo(AnsiString pFileName)
{
/*
    TUMOD* umod = new TUMOD();

    if(umod->IsUMOD(FileName))
    {
        PFileList FileList = new TMMFileList;
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
                    aFileData->FileSize     = FormatFloat("#,##0", umod->Size[i]);
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
*/
}
//---------------------------------------------------------------------------
void __fastcall TMMArchives::GetUzInfo(AnsiString pFileName)
{
    // stuff
}
//---------------------------------------------------------------------------
// wrapers for the TFiles class
//---------------------------------------------------------------------------
void __fastcall TMMArchives::GetFiles()
{
    GetFileList(Folder, SubFolders, LoadFilesType, FileFilters, FileTypes, MM_FLT_Archives);
}                       
//---------------------------------------------------------------------------
void __fastcall TMMArchives::UninstallFiles(PFileList pFileList)
{
   // fFiles->LoadFromFile("Archives" + fFiles->GameTag + ".xml");
   // fFiles->UninstallFiles(pArchiveList);
}
//---------------------------------------------------------------------------
void __fastcall TMMArchives::RenameFiles(PFileList pFileList)
{
    fFileFilters->Count;
	//TMMFiles::RenameFiles(pFileList, this->PEventManager->XMLSettings->GameTag, fFileFilters);
}
//---------------------------------------------------------------------------
void __fastcall TMMArchives::DeleteFiles(PFileList pFileList)
{
   // fFiles->DeleteFiles(pArchiveList);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// TMMFiles wrapers
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TMMArchives::GetFileTypes()
{
	this->PEventManager->XMLSettings->GetFileExts(fFileTypes, MM_FLT_Archives);
}
//--------------------------------------------------------------------------
void __fastcall TMMArchives::GetFileFilters()
{
	 this->PEventManager->XMLSettings->GetFileExts(fFileFilters, MM_FLT_Archives);
}
//----------------------------------------------------------------------------
void __fastcall TMMArchives::GetFileDiscriptions()
{
	this->PEventManager->XMLSettings->GetFileDiscriptions(fFileDiscriptions, MM_FLT_Archives);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMArchives::GetFileType(AnsiString pDiscription)
{
	return GetFilterFromDiscription(pDiscription);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMArchives::GetFilterFromDiscription(AnsiString pDiscription)
{
	return this->PEventManager->XMLSettings->GetFileExtFromDiscription(pDiscription, MM_FLT_Archives);
}
//----------------------------------------------------------------------------
int  __fastcall TMMArchives::GetFileIcon(AnsiString pFileExt)
{
    if(fLastIconInfo.Ext!=pFileExt)
    {     
		for(int i=0;i<this->PEventManager->XMLSettings->Icons->Count;i++)
		{
			if(SameText(UnicodeString(pFileExt), UnicodeString(this->PEventManager->XMLSettings->Icons->Get_Item(i)->Text)))
			{

				fLastIconInfo.Num = StrToIntDef(this->PEventManager->XMLSettings->Icons->Get_Item(i)->Get_id(), fLastIconInfo.Num);
				fLastIconInfo.Ext = pFileExt;
				break;
			}
		}
    }

    return fLastIconInfo.Num; 
}
//----------------------------------------------------------------------------
// Events
//----------------------------------------------------------------------------
void __fastcall TMMArchives::OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType)
{  
    FileList->Copy(pFileList);

	if(this->PEventManager->OnGotFileList)
		this->PEventManager->OnGotFileList(this, FileList, plistType);
}
//----------------------------------------------------------------------------
void __fastcall TMMArchives::GetFileData(AnsiString pFileName)
{
	TMM_GetFileInfoType action = MM_GFIT_COPY;
    AnsiString Ext             = ExtractFileExt(pFileName);

	int InstallTypesCount = this->PEventManager->XMLSettings->GameData->InstallTypes->Count;

    for(int i=0;i<InstallTypesCount;i++)
    {
		if(SameText(UnicodeString(Ext), UnicodeString(this->PEventManager->XMLSettings->GameData->InstallTypes->Get_Item(i)->Text)))
        {
			action = (TMM_GetFileInfoType) this->PEventManager->XMLSettings->GameData->InstallTypes->Get_Item(i)->Get_id();
            break;
        }
    }

    if (SameText(UnicodeString(Ext), L".7z") && action == MM_GFIT_COPY)
        action = MM_GFIT_ZIPDATA;
	GetArchiveData(pFileName, action);
}
//----------------------------------------------------------------------------
void __fastcall TMMArchives::MakeListViewTable(TListColumns* pCols)
{
	pCols->BeginUpdate();
    pCols->Clear();
    TListColumn* NewColumn;

	_di_IXMLArchivesTableType ArchivesDisplayTable         = this->PEventManager->XMLSettings->Tables->Get_ArchivesTable();
	_di_IXMLArchivesAlignmentType ArchivesTablesAllingment = this->PEventManager->XMLSettings->TablesAlignment->Get_ArchivesAlignment();

    for(int i=0;i<ArchivesDisplayTable->Count;i++)
    {
        NewColumn          = pCols->Add();
        NewColumn->Caption = ArchivesDisplayTable->Get_Item(i)->Text;
        NewColumn->Width   = StrToIntDef(ArchivesDisplayTable->Get_Item(i)->Get_id(), 50);

        if(this->PEventManager->XMLSettings->GameData->ColArrange)
        {
            for(int x=0;x<ArchivesTablesAllingment->Count;x++)
            {
                if(SameText(NewColumn->Caption, UnicodeString(ArchivesTablesAllingment->Get_Item(x)->Text)))
                {
                    if(ArchivesTablesAllingment->Get_Item(x)->Get_id()==1)
                        NewColumn->Alignment = taRightJustify;
                    else if(ArchivesTablesAllingment->Get_Item(x)->Get_id()==2)
                        NewColumn->Alignment = taCenter;
                }
            }
        }
    }

	pCols->EndUpdate();
}
//----------------------------------------------------------------------------


