//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TMMMusic.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)                     
#pragma hdrstop
__fastcall TMMMusic::TMMMusic(TMMEventManager* pEventManager)
          : TMMFiles()
{
    fFileTypes        = new TStringList;
    fFileFilters      = new TStringList;
    fFileDiscriptions = new TStringList;
    SetEventManager(pEventManager);
    RefreshSettings();
    fLastIconInfo.Ext = "";
    fLastIconInfo.Num = 10;
    //MyList = new TList;
}
//---------------------------------------------------------------------------
__fastcall TMMMusic::~TMMMusic()
{
    delete fFileTypes;
    delete fFileFilters;
    delete fFileDiscriptions;
}
//---------------------------------------------------------------------------
void __fastcall TMMMusic::RefreshSettings()
{
	fFolder     = this->PEventManager->XMLSettings->MusicFolder;
	//fSubFolders = this->PEventManager->XMLSettings->MusicSubFolders;
	fGameFolder = this->PEventManager->XMLSettings->GameFolder;
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
void __fastcall TMMMusic::SetLoadFilesType(TMM_LoadFilesType pValue)
{
    fLoadFilesType = pValue;
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::SetStringLists(const int Index, TStrings* pValue)
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
AnsiString __fastcall TMMMusic::GetFileGameType(AnsiString pFileName)
{
    // load types from registry, check for a type, of not found set to default
    AnsiString FileType = pFileName.Delete(AnsiPos("-", pFileName),pFileName.Length());
    //TStrings* MapGameTypes = new TStringList;

    //TRegistry *Registry = new TRegistry;
    //Registry->RootKey   = HKEY_CURRENT_USER;

    /*
    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\GameStarting\\" + FFiles->GameTag, false))
    {
        Registry->GetValueNames(MapGameTypes);
        int num = MapGameTypes->IndexOf(MapType);

        if(num==-1)
            FileName = Registry->ReadString("Default");
        else
            FileName = Registry->ReadString(MapGameTypes->Strings[num]);

        Registry->CloseKey();
    }
    else
        FileName = "Error";
        */

    //delete Registry;
    //delete MapGameTypes;
    return pFileName;
}
//---------------------------------------------------------------------------
// Global functions ;)
//----------------------------------------------------------------------------
void __fastcall TMMMusic::GetFileInfo(AnsiString pFile)
{
	// get info about the map, required files etc....
}
//----------------------------------------------------------------------------
// wrapers for the TFiles class
//----------------------------------------------------------------------------
void __fastcall TMMMusic::GetFiles()
{
	//fFiles->GetFileList(fSettings.GameFolder + MapFolder, MapSubFolders, LoadMapsType, MapFilters, MapTypes, MM_FLT_Maps);
	GetFileList(Folder, SubFolders, LoadFilesType, FileFilters, FileTypes, MM_FLT_Music);
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::UninstallFiles(PFileList pFileList)
{
	//fFiles->UninstallFiles(PMapList);
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::RenameFiles(PFileList pFileList)
{
    //TMMFiles::RenameFiles(pFileList, EventManager->XMLSettings->GameTag, fFileFilters);
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::DeleteFiles(PFileList pFileList)
{
	//fFiles->DeleteFiles(PMapList);
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::GetFileTypes()
{
	this->PEventManager->XMLSettings->GetFileExts(fFileTypes, MM_FLT_Music);
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::GetFileFilters()
{
	this->PEventManager->XMLSettings->GetFileFilters(fFileFilters, MM_FLT_Music);
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::GetFileDiscriptions()
{
	this->PEventManager->XMLSettings->GetFileDiscriptions(fFileDiscriptions, MM_FLT_Music);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMMusic::GetFileType(AnsiString pDiscription)
{
    return GetFilterFromDiscription(pDiscription);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMMusic::GetFilterFromDiscription(AnsiString pDiscription)
{
	return this->PEventManager->XMLSettings->GetFileExtFromDiscription(pDiscription, MM_FLT_Music);

/*
	_di_IXMLMusicMenuType MusicMenus = this->PEventManager->XMLSettings->DisplayMenus->Get_MusicMenu();

	for(int i=0;i<MusicMenus->Count;i++)
	{
		if(!pDiscription.AnsiCompareIC(MusicMenus->Get_SItem(i)->Text))
			return MusicMenus->Get_SItem(i)->Get_id();
	}

	return "Unknown";
    */
}
//----------------------------------------------------------------------------
// 12-04-2005 - 01:52 - Arden
// Load Icon for type of file : only does a xml settings search is the last icon
// loaded is different to the current one, else the last icon data is used.
// Speed inprovnment!!
//----------------------------------------------------------------------------
int  __fastcall TMMMusic::GetFileIcon(AnsiString pFileExt)
{
    if(fLastIconInfo.Ext!=pFileExt)
	{
		for(int i=0;i<this->PEventManager->XMLSettings->Icons->Count;i++)
        {
			if(!pFileExt.AnsiCompareIC(this->PEventManager->XMLSettings->Icons->Get_Item(i)->Text))
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
void __fastcall TMMMusic::GetFileData(AnsiString pFileName)
{
    TMM_GetFileInfoType action = MM_GFIT_INFO;
	GetMusicData(pFileName, action);
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Events
//----------------------------------------------------------------------------
void __fastcall TMMMusic::OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType)
{
	FileList->Copy(pFileList);

	if(this->PEventManager->OnGotFileList)
		this->PEventManager->OnGotFileList(this, FileList, plistType);
    /*
    List.empty();

	TMM_FileInfo tmp;

    for(int i=0;i<pFileList->Count;i++)
    {
        tmp = pFileList->GetFileStruct(i);
        List.push_back(tmp);
		MyList->Add(pFileList->Files[i]);
    }
	*/
    //ShowMessage(pFileList->Count);
	//ShowMessage(List.size());
	//ShowMessage(MyList->Count);

	//tmp = (TMM_FileInfo&)MyList->Items[5];
}
//----------------------------------------------------------------------------
void __fastcall TMMMusic::MakeListViewTable(TListColumns* pCols)
{
	pCols->BeginUpdate();
    pCols->Clear();
    TListColumn* NewColumn;

	_di_IXMLMusicTableType MusicDisplayTable          = this->PEventManager->XMLSettings->Tables->Get_MusicTable();
	_di_IXMLMusicAlignmentType MusicTablesAllingment = this->PEventManager->XMLSettings->TablesAlignment->Get_MusicAlignment();

	for(int i=0;i<MusicDisplayTable->Count;i++)
    {
        NewColumn          = pCols->Add();
		NewColumn->Caption = MusicDisplayTable->Get_Item(i)->Text;
		NewColumn->Width   = StrToIntDef(MusicDisplayTable->Get_Item(i)->Get_id(), 50);

		if(this->PEventManager->XMLSettings->GameData->ColArrange)
        {
			for(int x=0;x<MusicTablesAllingment->Count;x++)
            {
				if(!NewColumn->Caption.Compare(MusicTablesAllingment->Get_Item(x)->Text))
                {
					if(MusicTablesAllingment->Get_Item(x)->Get_id()==1)
                        NewColumn->Alignment = taRightJustify;
					else if(MusicTablesAllingment->Get_Item(x)->Get_id()==2)
                        NewColumn->Alignment = taCenter;
                }
            }
        }
    }

	pCols->EndUpdate();
}
//----------------------------------------------------------------------------




