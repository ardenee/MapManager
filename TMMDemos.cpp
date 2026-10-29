//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TMMDemos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)                     
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TMMDemos::TMMDemos(TMMEventManager* pEventManager)
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
__fastcall TMMDemos::~TMMDemos()
{
    delete fFileTypes;
    delete fFileFilters;
    delete fFileDiscriptions;
}
//---------------------------------------------------------------------------
void __fastcall TMMDemos::RefreshSettings()
{
	fFolder     = this->PEventManager->XMLSettings->DemosFolder;
	//fSubFolders = this->PEventManager->XMLSettings->DemosSubFolders;
	fGameFolder = this->PEventManager->XMLSettings->GameFolder;
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
void __fastcall TMMDemos::SetLoadFilesType(TMM_LoadFilesType pValue)
{
    fLoadFilesType = pValue;
}
//----------------------------------------------------------------------------
void __fastcall TMMDemos::SetStringLists(const int Index, TStrings* pValue)
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
AnsiString __fastcall TMMDemos::GetFileGameType(AnsiString pFileName)
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
void __fastcall TMMDemos::GetFileInfo(AnsiString pFile)
{
    // get info about the map, required files etc....
}
//----------------------------------------------------------------------------
// wrapers for the TFiles class
//----------------------------------------------------------------------------
void __fastcall TMMDemos::GetFiles()
{
    //fFiles->GetFileList(fSettings.GameFolder + MapFolder, MapSubFolders, LoadMapsType, MapFilters, MapTypes, MM_FLT_Maps);
	GetFileList(Folder, SubFolders, LoadFilesType, FileFilters, FileTypes, MM_FLT_Demos);
}
//----------------------------------------------------------------------------
void __fastcall TMMDemos::UninstallFiles(PFileList pFileList)
{
    //fFiles->UninstallFiles(PMapList);
}
//----------------------------------------------------------------------------
void __fastcall TMMDemos::RenameFiles(PFileList pFileList)
{
    //TMMFiles::RenameFiles(pFileList, EventManager->XMLSettings->GameTag, fFileFilters);
}
//----------------------------------------------------------------------------
void __fastcall TMMDemos::DeleteFiles(PFileList pFileList)
{
    //fFiles->DeleteFiles(PMapList);
}
//----------------------------------------------------------------------------
void __fastcall TMMDemos::GetFileTypes()
{
	//fFileTypes->Clear();
	//fFileTypes->Add(this->PEventManager->XMLSettings->DemoExt);
	this->PEventManager->XMLSettings->GetFileExts(fFileTypes, MM_FLT_Demos);
}
//----------------------------------------------------------------------------
void __fastcall TMMDemos::GetFileFilters()
{
	//fFileFilters->Clear();
	//_di_IXMLDemosMenuType DemoMenus = this->PEventManager->XMLSettings->DisplayMenus->Get_DemosMenu();

	//for(int i=0;i<DemosMenus->Count;i++)
	//	fFileFilters->Add(DemosMenus->Get_SItem(i)->Get_id());
	this->PEventManager->XMLSettings->GetFileFilters(fFileFilters, MM_FLT_Demos);
}
//----------------------------------------------------------------------------
void __fastcall TMMDemos::GetFileDiscriptions()
{
	//fFileDiscriptions->Clear();
	//_di_IXMLDemosMenuType DemosMenus = this->PEventManager->XMLSettings->DisplayMenus->Get_DemosMenu();

	//for(int i=0;i<DemosMenus->Count;i++)
	//	fFileDiscriptions->Add(DemosMenus->Get_SItem(i)->Text);
	this->PEventManager->XMLSettings->GetFileDiscriptions(fFileDiscriptions, MM_FLT_Demos);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMDemos::GetFileType(AnsiString pDiscription)
{
    return GetFilterFromDiscription(pDiscription);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMDemos::GetFilterFromDiscription(AnsiString pDiscription)
{
    return this->PEventManager->XMLSettings->GetFileExtFromDiscription(pDiscription, MM_FLT_Demos);
	//_di_IXMLDemosMenuType DemosMenus = this->PEventManager->XMLSettings->DisplayMenus->Get_DemosMenu();

	//for(int i=0;i<DemosMenus->Count;i++)
	//{
	//	if(!pDiscription.AnsiCompareIC(DemosMenus->Get_SItem(i)->Text))
	//		return DemosMenus->Get_SItem(i)->Get_id();
	//}

	//return "Unknown";
}
//----------------------------------------------------------------------------
// 12-04-2005 - 01:52 - Arden
// Load Icon for type of file : only does a xml settings search is the last icon
// loaded is different to the current one, else the last icon data is used.
// Speed inprovnment!!
//----------------------------------------------------------------------------
int  __fastcall TMMDemos::GetFileIcon(AnsiString pFileExt)
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
void __fastcall TMMDemos::GetFileData(AnsiString pFileName)
{
    TMM_GetFileInfoType action = MM_GFIT_INFO;
	GetDemosData(pFileName, action);
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Events
//----------------------------------------------------------------------------
void __fastcall TMMDemos::OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType)
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
void __fastcall TMMDemos::MakeListViewTable(TListColumns* pCols)
{
/*
	pCols->BeginUpdate();
    pCols->Clear();
    TListColumn* NewColumn;

	_di_IXMLMapsTableType DemosDisplayTable          = this->PEventManager->XMLSettings->Tables->Get_DemosTable();
	_di_IXMLMapsAlignmentType DemosTablesAllingment = this->PEventManager->XMLSettings->TablesAlignment->Get_DemosAlignment();

	for(int i=0;i<DemosDisplayTable->Count;i++)
    {
        NewColumn          = pCols->Add();
		NewColumn->Caption = DemosDisplayTable->Get_Item(i)->Text;
		NewColumn->Width   = StrToIntDef(DemosDisplayTable->Get_Item(i)->Get_id(), 50);

		if(this->PEventManager->XMLSettings->GameData->ColArrange)
        {
			for(int x=0;x<DemosTablesAllingment->Count;x++)
            {
				if(!NewColumn->Caption.Compare(DemosTablesAllingment->Get_Item(x)->Text))
                {
					if(DemosTablesAllingment->Get_Item(x)->Get_id()==1)
                        NewColumn->Alignment = taRightJustify;
                    else if(DemosTablesAllingment->Get_Item(x)->Get_id()==2)
                        NewColumn->Alignment = taCenter;
                }
            }
        }
    }

	pCols->EndUpdate();
	*/
}
//----------------------------------------------------------------------------












