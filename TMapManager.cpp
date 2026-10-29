//---------------------------------------------------------------------------
#include <basepch.h>
#include <SysUtils.hpp>
#include <Registry.hpp>
#include <stdio.h>
#include <Dialogs.hpp> // only included for ShowMessage();
#include <StrUtils.hpp>
#include <DateUtils.hpp>
//---------------------------------------------------------------------------
#include "MapManager.h"
#include "TMapManager.h"
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//#pragma warn -pck   // added to remove linker error message
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
static inline void ValidCtrCheck(TMapManager *)
{
    new TMapManager(NULL);
}
//---------------------------------------------------------------------------
__fastcall TMapManager::TMapManager(TComponent* Owner)
    : TComponent(Owner)
{
    fSettings     = new TMMSettings();
    fXMLLogs      = new TMMLogs();
	fEventManager = new TMMEventManager(fSettings, fXMLLogs); //database instead of xml?
    fMaps         = new TMMMaps(fEventManager); // they can access the events throught th e TFiles ;)
    fArchives     = new TMMArchives(fEventManager);
    fCache        = new TMMCache(fEventManager);
	fDisplayFiles = new TMMDisplayFiles(fEventManager);//, fSettings);
	fMusic        = new TMMMusic(fEventManager);
	fDemos        = new TMMDemos(fEventManager);
	fTextures     = new TMMTextures(fEventManager);
	fScreenShots  = new TMMScreenShots(fEventManager);
    fLogList      = new TMMFileList;

    // Handler                          = Event function
	OnError                       = OnErrorEvent;
	EventManager->OnGotPicture    = OnGotPicEvent;
	EventManager->OnGotDataList   = OnGotFielDataEvent;
    fEventManager->OnFilesRenamed = OnFilesRenamedEvent;
	fEventManager->OnFileRenamed  = OnFileRenamedEvent;
	fMaps->RefreshSettings();

	//fDisplayFiles->EventManager->OnFilesRenamed = OnFilesRenamedEvent;
	//fDisplayFiles->EventManager->OnFileRenamed  = OnFileRenamedEvent;
}
//---------------------------------------------------------------------------
namespace Tmapmanager
{
    void __fastcall PACKAGE Register()
    {
         TComponentClass classes[1] = {__classid(TMapManager)};
         RegisterComponents("Nasty PC's", classes, 0);
    }
}
//---------------------------------------------------------------------------
__fastcall TMapManager::~TMapManager()
{
    delete fSettings;
    delete fEventManager;
    delete fLogList;
    delete fMaps;
    delete fArchives;
    delete fDisplayFiles;
    delete fXMLLogs;
    //delete fFiles;
    delete fCache;
    delete fMusic;
	delete fDemos;
	delete fTextures;
	delete fScreenShots;
}
//----------------------------------------------------------------------------
void __fastcall TMapManager::SetLogList(PFileList Value)
{
    fLogList->Assign((PFileList)Value);
}
//----------------------------------------------------------------------------
void __fastcall TMapManager::SetMaps(TMMMaps* Value)
{
    fMaps->Assign((TPersistent*)Value);
}
//----------------------------------------------------------------------------
void __fastcall TMapManager::SetArchives(TMMArchives* Value)
{
    fArchives->Assign((TPersistent*)Value);
}
//----------------------------------------------------------------------------
void __fastcall TMapManager::SetCache(TMMCache* Value)
{
    fCache->Assign((TPersistent*)Value);
}
//----------------------------------------------------------------------------
void __fastcall TMapManager::SetScreenShots(TMMScreenShots* Value)
{
    fScreenShots->Assign((TPersistent*)Value);
}
//----------------------------------------------------------------------------
void __fastcall TMapManager::SetSettings(TMMSettings* Value)
{
	fSettings->Assign((TPersistent*)Value);
}
//---------------------------------------------------------------------------
// Events
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnGotLogEntrysEvent(TObject *Sender, PFileList LogList)
{
    if(fOnGotLogEntrys)
        fOnGotLogEntrys(this, LogList);
}
//---------------------------------------------------------------------------
/*
void __fastcall TMapManager::OnGotFileListEvent(TObject *Sender, PFileList pFileList)
{
    //FileList->Copy(pFileList);

   // if(FOnGotFileList)
      //  FOnGotFileList(this, FileList, plistType);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnGotCacheFileListEvent(TObject *Sender, PFileList pFileList)
{
   // FileList->Copy(pFileList);

   // if(FOnGotCacheFileList)
    //    FOnGotCacheFileList(this, FileList);
}
*/
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFileRenamedEvent(TObject *Sender, AnsiString OldName, AnsiString NewName)
{   // update the filelist

    //ShowMessage("TMapManager::OnFileRenamedEvent()");

    for(int i=0;i<fDisplayFiles->FileList->Count;i++)
    {
        if(!fDisplayFiles->FileList->Files[i]->FileName.AnsiCompare(ExtractFileName(OldName)) && !fDisplayFiles->FileList->Files[i]->FileLocation.AnsiCompare(ExtractFilePath(OldName)))
        {   // append to file list!
            fDisplayFiles->FileList->Files[i]->FileName = ExtractFileName(NewName);
            break;
        }
    }

    if(FOnFileRenamed)
        FOnFileRenamed(this, OldName, NewName);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFilesRenamedEvent(TObject *Sender)
{   // let used know all files are renamed
    if(FOnFilesRenamed)
        FOnFilesRenamed(this);
}   
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFileDeletedEvent(TObject *Sender, AnsiString Value)
{
    if(FOnFileDeleted)
        FOnFileDeleted(this, Value);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFilesDeletedEvent(TObject *Sender, PFileList List)
{
    if(FOnFilesDeleted)
        FOnFilesDeleted(this, List);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFileUninstalledEvent(TObject *Sender, AnsiString FileName, AnsiString ArchiveName)
{
    if(OnFileUninstalled)
        OnFileUninstalled(this, FileName, ArchiveName);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFilesUninstalledEvent(TObject *Sender, PFileList List)
{
    if(OnFilesUninstalled)
        OnFilesUninstalled(this, List);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFileInstalledEvent(TObject *Sender, AnsiString ArchiveName, AnsiString FileName)
{
    if(OnFileInstalled)
        OnFileInstalled(this, ArchiveName, FileName);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnFilesInstalledEvent(TObject *Sender, PFileList List, int Installed)
{
    if(OnFilesInstalled)
        OnFilesInstalled(this, List, Installed);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnArchiveInstalledEvent(TObject *Sender, AnsiString Value)
{
/*
	for(int i=0;i<EventManager->FileList->Count;i++)
    {
        if(!EventManager->FileList->Files[i]->FileName.AnsiCompare(ExtractFileName(Value)) && !EventManager->FileList->Files[i]->FileLocation.AnsiCompare(ExtractFilePath(Value)))
        {   // append to file list!
            EventManager->FileList->Files[i]->Installed = "Yes";
            break;
        }
    }
*/

    if(OnArchiveInstalled)
        OnArchiveInstalled(this, Value);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnErrorEvent(TObject *Sender, AnsiString Value)
{
    //ShowMessage("TMapManager::OnErrorEvent -> " + Value);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnGotPicEvent(TObject *Sender, TPicture* Picture)
{
    //ShowMessage("Got Pic");
    if(FOnGotPicture)
        FOnGotPicture(this, Picture);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnGotFileInfoEvent(TObject *Sender, PFileList List)
{
    if(OnGotFileInfo)
        OnGotFileInfo(this, List);
}
//---------------------------------------------------------------------------
// Set Data
//---------------------------------------------------------------------------
void __fastcall TMapManager::SetFiles(TMMFiles* Value)
{
    //fFiles->Assign((TPersistent*)Value);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::SetMusic(TMMMusic*    Value)
{
    fMusic->Assign((TPersistent*)Value);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::SetTextures(TMMTextures*    Value)
{
    fTextures->Assign((TPersistent*)Value);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::SetDemos(TMMDemos*    Value)
{
    fDemos->Assign((TPersistent*)Value);
}
//---------------------------------------------------------------------------
// Globla functions
//---------------------------------------------------------------------------

/*
__int64	GetFileSize(AnsiString FileName)
{
    TSearchRec sr;

    FindFirst(FileName, faAnyFile, sr);
    __int64 size = sr.Size;
    FindClose(sr);

    return(size);
}

    __int64 FileLength=0;

    if(FileExists(TheFileName))
    {
        int FHandle;
        FHandle = FileOpen(TheFileName, fmOpenRead);
        FileLength = FileSeek(FHandle,0,2);
        FileClose(FHandle);
    }

    return FileLength;
}
    int fHandle = FileOpen("YourZip.zip", fmOpenRead);
    TDateTime fileDate = FileDateToDateTime(FileGetDate(fHandle));
*/
//---------------------------------------------------------------------------
AnsiString __fastcall TMapManager::GetDisplayFilters(TStrings* pFilterList, int MenuType)
{
    AnsiString Menu = "Unknown";

    if(fSettings->MenuTypes->ChildNodes->GetCount()>0)
    {
        _di_IXMLNodeList Items = fSettings->MenuTypes->GetChildNodes();

        for(int i=0;i<Items->Count;i++)
        {
            _di_IXMLItemType Item        = Items->Get(i);
            _di_IXMLNodeList ItemAttList = Item->GetAttributeNodes();
            _di_IXMLNode     Node        = ItemAttList->First();

            if(StrToIntDef(Node->GetText(), 0)== MenuType)
                Menu = Item->GetText();
        }
    }   

    return StringReplace(Menu, "\"", "", TReplaceFlags() << rfReplaceAll);
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::MakeListMenu(TStrings* MenuItems, int MenuType)
{
    MenuItems->Clear();
    
    _di_IXMLMapsMenuType MapMenus = fSettings->DisplayMenus->Get_MapsMenu();

    for(int i=0;i<MapMenus->Count;i++)
        MenuItems->Add(MapMenus->Get_SItem(i)->Text);

	/*
    if(MapMenus->Count()>0)
    {
        AnsiString Value = "";
        _di_IXMLNodeList Items = MapMenus->GetChildNodes();

        for(int i=0;i<Items->Count;i++)
        {
            _di_IXMLItemType Item = Items->Get(i);
            //_di_IXMLNodeList ItemAttList = Item->GetAttributeNodes();
            //_di_IXMLNode Node = ItemAttList->First();
            //MenuItems->Add(Node->GetText());
            MenuItems->Add(Item->GetText());
        }
    }
    */
}
//---------------------------------------------------------------------------
// This should be in the registry !!!!
AnsiString __fastcall TMapManager::GetMenuType(const int Value)
{   
    // Change GetDataFor() to read the default value for bad returns !!
    //return FFiles->GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\MenuTypes\\" + FFiles->GameTag, Value);
    return "UT2004";  
}
//---------------------------------------------------------------------------
bool __fastcall TMapManager::GetRegistryValues(const int MenuType, TStrings* MenuItems, AnsiString ExtraSection)
{
    bool Loaded = false;
    //TRegistry *Registry = new TRegistry;
    //Registry->RootKey = HKEY_CURRENT_USER;

   // if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\" + GetMenuType(MenuType) + "\\" + Files->GameTag + ExtraSection, false))
   // {   // use TmpList so we can use "TmpList->Duplicates = dupIgnore;"
   //     Registry->GetValueNames(MenuItems);
   //     Loaded = true;
   // }

    //Registry->CloseKey();

    //delete Registry;
    return Loaded;
}
//---------------------------------------------------------------------------
bool __fastcall TMapManager::GetRegistryValueData(const int MenuType, TStrings* MenuItems, bool DelDoubles, AnsiString ExtraSection)
{
    //TRegistry *Registry = new TRegistry;
    //Registry->RootKey   = HKEY_CURRENT_USER;
    bool Loaded         = false;
    ShowMessage("In");


    if(fSettings->MenuTypes->ChildNodes->GetCount()>0)
    {
        AnsiString Value = "";
        _di_IXMLNodeList Items = fSettings->MenuTypes->GetChildNodes();

        for(int i=0;i<Items->Count;i++)
        {
            _di_IXMLItemType Item = Items->Get(i);
            _di_IXMLNodeList ItemAttList = Item->GetAttributeNodes();
            _di_IXMLNode Node = ItemAttList->First();
            MenuItems->Add(Node->GetText());
        }
    }


    /*
    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\" + GetMenuType(MenuType) + "\\" + Files->GameTag + ExtraSection, false))
    {   // use TmpList so we can use "TmpList->Duplicates = dupIgnore;"
        TStringList* FileTypes = new TStringList;
        TStringList* TmpList   = new TStringList;

        Registry->GetValueNames(FileTypes);
        TmpList->Sorted     = DelDoubles;
        TmpList->Duplicates = dupIgnore; //dupIgnore=0, dupAccept=1, dupError=2

        for(int i=0;i<FileTypes->Count;i++)
            TmpList->Add(Registry->ReadString(FileTypes->Strings[i]));

       MenuItems->AddStrings(TmpList);

        delete FileTypes;
        delete TmpList;
    }
    */

    //Registry->CloseKey();

    //delete Registry;
    return Loaded;
}
//---------------------------------------------------------------------------
// Task Functions
//---------------------------------------------------------------------------
bool __fastcall TMapManager::MakeListViewTable(TListView *TmpListView, const int TableType)
{
    bool Result = false;
    TStrings* ColSettings = new TStringList;

    TmpListView->Columns->BeginUpdate();
    TmpListView->Columns->Clear();
    TListColumn* NewColumn;

    // Posible Table Types
    _di_IXMLMapsTableType MapDisplayTable;
    _di_IXMLFindTableType FindDisplayTable;

    //Table Items
    _di_IXMLNodeList Items; 

    switch(TableType)
    {
        case  0 : {
                    MapDisplayTable = fSettings->Tables->Get_MapsTable();
                    if(MapDisplayTable->ChildNodes->GetCount()>0)
                        Items = MapDisplayTable->GetChildNodes();

                    break;
                  }
        case 12 : {
                    FindDisplayTable = fSettings->Tables->Get_FindTable();
                    if(FindDisplayTable->ChildNodes->GetCount()>0)
                        Items = FindDisplayTable->GetChildNodes();
                    break;
                  }
        default : {
                    MapDisplayTable = fSettings->Tables->Get_MapsTable();
                    if(MapDisplayTable->ChildNodes->GetCount()>0)
                        Items = MapDisplayTable->GetChildNodes();

                    break;
                  }
    }

    if(Items)
    {
        for(int i=0;i<Items->Count;i++)
        {
            _di_IXMLItemType Item        = Items->Get(i);
            _di_IXMLNodeList ItemAttList = Item->GetAttributeNodes();
            _di_IXMLNode     Node        = ItemAttList->First();

            NewColumn          = TmpListView->Columns->Add();
            NewColumn->Caption = Item->GetText();
            NewColumn->Width   = StrToIntDef(Node->GetText(), 50);  

            if(fSettings->GameData->ColArrange)
            {
				_di_IXMLTablesAlignmentType DisplayTablesAllingment = fSettings->GameData->Get_TablesAlignment();

                // Posible Table Types
                _di_IXMLMapsAlignmentType MapsTableAlingment;
                _di_IXMLFindAlignmentType FindTableAlingment; 

                // Table Items
                _di_IXMLNodeList AlignItems;

                switch(TableType)
                {
                    case  0 : {
                                MapsTableAlingment = DisplayTablesAllingment->Get_MapsAlignment();
                                if(MapsTableAlingment->ChildNodes->GetCount()>0)
                                    AlignItems = MapsTableAlingment->GetChildNodes();

                                break;
                            }
                    case 12 : {
                                FindTableAlingment = DisplayTablesAllingment->Get_FindAlignment();
                                if(FindTableAlingment->ChildNodes->GetCount()>0)
                                    AlignItems = FindTableAlingment->GetChildNodes();
                                break;
                            }
                            
                    default : {
                                MapsTableAlingment = DisplayTablesAllingment->Get_MapsAlignment();
                                if(MapsTableAlingment->ChildNodes->GetCount()>0)
                                    AlignItems = MapsTableAlingment->GetChildNodes();

                                break;
                            }
                }    

                if(AlignItems)
                {
                    for(int i=0;i<AlignItems->Count;i++)
                    {
                        _di_IXMLItemType AlignItem        = AlignItems->Get(i);
                        _di_IXMLNodeList AlignItemAttList = AlignItem->GetAttributeNodes();
                        _di_IXMLNode     AlignNode        = AlignItemAttList->First();

                        if(AlignItem->GetText()==Item->GetText())
                        {
                            if(StrToIntDef(AlignNode->GetText(), 0)==1)
                                TmpListView->Columns->Items[i]->Alignment = taRightJustify;
                            else if(StrToIntDef(AlignNode->GetText(), 0)==2)
                                TmpListView->Columns->Items[i]->Alignment = taCenter;
                        } 
                    }
                }
            }
        }
    }

    TmpListView->Columns->EndUpdate();
    delete ColSettings;
    return Result;
}
//---------------------------------------------------------------------------
TMM_ColInfo __fastcall TMapManager::GetColInfo(AnsiString pColName, AnsiString pTableName)
{
    TMM_ColInfo data;
    data.Title      = pColName;
    //data.Width      = StrToIntDef(FFiles->GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Tables\\"          + FFiles->GameTag + "\\" + pTableName, pColName), 50);
    //data.Allignment = StrToIntDef(FFiles->GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\TablesAlignment\\" + FFiles->GameTag + "\\" + pTableName, pColName), 0);
    return data;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMapManager::GetFileType(AnsiString FileDescription, AnsiString RegSection)
{
    // should be using TReg
    //ShowMessage("SOFTWARE\\Nasty PC's\\Map Manager\\" + RegSection + Files->GameTag);
    //return FFiles->GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\" + RegSection + Files->GameTag, FileDescription);

 /*


    TRegistry *Registry   = new TRegistry;
    Registry->RootKey     = HKEY_CURRENT_USER;
    TStrings* TmpList     = new TStringList;
    AnsiString FilterName = "";
    
    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\" + RegSection + Files->GameTag, false))
    {
        Registry->GetValueNames(TmpList);

        for(int i=0;i<TmpList->Count;i++)
        {
            if(!Registry->ReadString(TmpList->Strings[i]).AnsiCompare(FileDescription))
            {
                FilterName = TmpList->Strings[i];
                break;
            }
        }
            
        Registry->CloseKey();
    }

    delete TmpList;
    delete Registry;
    return FilterName;
    */

    return "";
}
//---------------------------------------------------------------------------
int __fastcall TMapManager::GetFileIcon(AnsiString FileExt)
{
    return 10;
}
//---------------------------------------------------------------------------
void __fastcall TMapManager::OnGotFielDataEvent(TObject *Sender, TStrings* pFileData)
{
// stuff
    //ShowMessage("TMapManager::OnGotFielDataEvent"+ IntToStr(pFileData->Count));
}
//---------------------------------------------------------------------------

