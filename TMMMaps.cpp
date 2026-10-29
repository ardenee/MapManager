//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TMMMaps.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)                     
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TMMMaps::TMMMaps(TMMEventManager* pEventManager)
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
__fastcall TMMMaps::~TMMMaps()
{
    delete fFileTypes;
    delete fFileFilters;
    delete fFileDiscriptions;
}
//---------------------------------------------------------------------------
void __fastcall TMMMaps::RefreshSettings()
{
	fFolder     = this->PEventManager->XMLSettings->MapFolder;
	fSubFolders = this->PEventManager->XMLSettings->MapSubFolders;
	fGameFolder = this->PEventManager->XMLSettings->GameFolder;
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
void __fastcall TMMMaps::SetLoadFilesType(TMM_LoadFilesType pValue)
{
    fLoadFilesType = pValue;
}
//----------------------------------------------------------------------------
void __fastcall TMMMaps::SetStringLists(const int Index, TStrings* pValue)
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
AnsiString __fastcall TMMMaps::GetFileGameType(AnsiString pFileName)
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
void __fastcall TMMMaps::GetFileInfo(AnsiString pFile)
{
    // get info about the map, required files etc....
}
//----------------------------------------------------------------------------
// wrapers for the TFiles class
//----------------------------------------------------------------------------
void __fastcall TMMMaps::GetFiles()
{
    //fFiles->GetFileList(fSettings.GameFolder + MapFolder, MapSubFolders, LoadMapsType, MapFilters, MapTypes, MM_FLT_Maps);
    GetFileList(Folder, SubFolders, LoadFilesType, FileFilters, FileTypes, MM_FLT_Maps);
}
//----------------------------------------------------------------------------
void __fastcall TMMMaps::UninstallFiles(PFileList pFileList)
{
    //fFiles->UninstallFiles(PMapList);
}    
//----------------------------------------------------------------------------
void __fastcall TMMMaps::RenameFiles(PFileList pFileList)
{
    //TMMFiles::RenameFiles(pFileList, EventManager->XMLSettings->GameTag, fFileFilters);
}
//----------------------------------------------------------------------------
void __fastcall TMMMaps::DeleteFiles(PFileList pFileList)
{
    //fFiles->DeleteFiles(PMapList);
}  
//----------------------------------------------------------------------------
void __fastcall TMMMaps::GetFileTypes()
{
	this->PEventManager->XMLSettings->GetFileExts(fFileTypes, MM_FLT_Maps);
}
//----------------------------------------------------------------------------
void __fastcall TMMMaps::GetFileFilters()
{
	this->PEventManager->XMLSettings->GetFileFilters(fFileFilters, MM_FLT_Maps);
}
//----------------------------------------------------------------------------
void __fastcall TMMMaps::GetFileDiscriptions()
{
	this->PEventManager->XMLSettings->GetFileDiscriptions(fFileDiscriptions, MM_FLT_Maps);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMMaps::GetFileType(AnsiString pDiscription)
{
    return GetFilterFromDiscription(pDiscription);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMMaps::GetFilterFromDiscription(AnsiString pDiscription)
{
	return this->PEventManager->XMLSettings->GetFileExtFromDiscription(pDiscription, MM_FLT_Maps);

	/*
	_di_IXMLMapsMenuType MapMenus = this->PEventManager->XMLSettings->DisplayMenus->Get_MapsMenu();

    for(int i=0;i<MapMenus->Count;i++)
    {
        if(!pDiscription.AnsiCompareIC(MapMenus->Get_SItem(i)->Text))
            return MapMenus->Get_SItem(i)->Get_id();
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
int  __fastcall TMMMaps::GetFileIcon(AnsiString pFileExt)
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
void __fastcall TMMMaps::GetFileData(AnsiString pFileName)
{
    TMM_GetFileInfoType action = MM_GFIT_INFO;
    GetMapData(pFileName, action);
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Events
//----------------------------------------------------------------------------
void __fastcall TMMMaps::OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType)
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
void __fastcall TMMMaps::MakeListViewTable(TListColumns* pCols)
{
	pCols->BeginUpdate();
    pCols->Clear();
    TListColumn* NewColumn;

	_di_IXMLMapsTableType MapDisplayTable          = this->PEventManager->XMLSettings->Tables->Get_MapsTable();
    _di_IXMLMapsAlignmentType MapsTablesAllingment = this->PEventManager->XMLSettings->TablesAlignment->Get_MapsAlignment();

    for(int i=0;i<MapDisplayTable->Count;i++)
    {
        NewColumn          = pCols->Add();
        NewColumn->Caption = MapDisplayTable->Get_Item(i)->Text;
        NewColumn->Width   = StrToIntDef(MapDisplayTable->Get_Item(i)->Get_id(), 50);

		if(this->PEventManager->XMLSettings->GameData->ColArrange)
        {
            for(int x=0;x<MapsTablesAllingment->Count;x++)
            {
				if(!NewColumn->Caption.Compare(MapsTablesAllingment->Get_Item(x)->Text))
                {
                    if(MapsTablesAllingment->Get_Item(x)->Get_id()==1)
                        NewColumn->Alignment = taRightJustify;
                    else if(MapsTablesAllingment->Get_Item(x)->Get_id()==2)
                        NewColumn->Alignment = taCenter;
                }
            }
        }
    }

	pCols->EndUpdate();
}
//----------------------------------------------------------------------------












