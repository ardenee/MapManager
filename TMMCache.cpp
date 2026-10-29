//---------------------------------------------------------------------------
#pragma hdrstop
#include <Registry.hpp>
//---------------------------------------------------------------------------
#include "TMMCache.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//----------------------------------------------------------------------------
__fastcall TMMCache::TMMCache(TMMEventManager* pEventManager)
    : TMMFiles()
{
    fFileTypes        = new TStringList;
    fFileFilters      = new TStringList;
    fFileDiscriptions = new TStringList;
    SetEventManager(pEventManager);
    RefreshSettings();
	fLastIconInfo.Ext = "";
    fLastIconInfo.Num = 10;
	fINIFile          = "Cache.ini";

	AnsiString tmp = fFolder + "cache.ini";
	pif            = new TIniFile(tmp);
	SQLConnection1 = new TSQLConnection(0);
	SQLQuery1      = new TSQLQuery(0);
	//SQLDataSet1    = new TSQLDataSet(0);
	SQLConnection1->DriverName = "Sqlite";
	SQLConnection1->Params->Add("Database=cache.sqlite3");
	SQLConnection1->LoginPrompt = false;

	try
	{
		SQLConnection1->Connected = true;
		SQLQuery1->SQLConnection  = SQLConnection1;
	}
	catch (EDatabaseError& E)
	{
		// change to status bar and logs
	   ShowMessage("Exception raised with message\n" + E.Message);
	}


	fFileDiscriptions->Sorted = true;
	fFileDiscriptions->Duplicates = System::Types::dupIgnore;

}
//----------------------------------------------------------------------------
__fastcall TMMCache::TMMCache()
    : TMMFiles()
{
    fFileTypes        = new TStringList;
    fFileFilters      = new TStringList;
	fFileDiscriptions = new TStringList;
	SetEventManager(this->PEventManager); // remove?
    RefreshSettings();
    fLastIconInfo.Ext = "";
    fLastIconInfo.Num = 10;
	fINIFile = "Cache.ini";

	AnsiString tmp = fFolder + "cache.ini";
	pif            = new TIniFile(tmp);
	SQLConnection1 = new TSQLConnection(0);
	SQLQuery1      = new TSQLQuery(0);
	//SQLDataSet1    = new TSQLDataSet(0);

}
//---------------------------------------------------------------------------
__fastcall TMMCache::~TMMCache()
{
    delete fFileTypes;
    delete fFileFilters;
	delete fFileDiscriptions;
	delete pif;
	delete SQLQuery1;
	//delete SQLDataSet1;
	SQLConnection1->Connected = false;
	delete SQLConnection1;
}
//---------------------------------------------------------------------------
void __fastcall TMMCache::GetCacheFolderFileList(TStrings* FileList)
{

}
//---------------------------------------------------------------------------
UnicodeString __fastcall TMMCache::GetStr1FromCacheString(UnicodeString FileName)
{

}
//---------------------------------------------------------------------------
UnicodeString __fastcall TMMCache::GetStr2FromCacheString(UnicodeString FileName)
{

}
//---------------------------------------------------------------------------
UnicodeString __fastcall TMMCache::GetFilesFolder(UnicodeString FileName)
{

}
//---------------------------------------------------------------------------
UnicodeString __fastcall TMMCache::GetStr3FromCacheString(UnicodeString FileName)
{

}
//---------------------------------------------------------------------------
void __fastcall TMMCache::RefreshSettings()
{
	fFolder     = this->PEventManager->XMLSettings->CacheFolder;
	//fSubFolders = this->PEventManager->XMLSettings->MapSubFolders;
	fGameFolder = this->PEventManager->XMLSettings->GameFolder;
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
void __fastcall TMMCache::SetLoadFilesType(TMM_LoadFilesType pValue)
{
	fLoadFilesType = pValue;
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::SetStringLists(const int Index, TStrings* pValue)
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
AnsiString __fastcall TMMCache::GetFileType(AnsiString pFileFilter)
{
// stuff
    return "";
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::GetAllFileTypesFor(TStrings* pData, AnsiString pFileFilter)
{
    pData->Clear();
	_di_IXMLCacheMenuType CacheMenu = this->PEventManager->XMLSettings->DisplayMenus->Get_CacheMenu();

    for(int i=0;i<CacheMenu->Count;i++)
    {
        if(!pFileFilter.AnsiCompareIC(CacheMenu->Get_SItem(i)->Text))
            pData->Add(CacheMenu->Get_SItem(i)->Get_id());
	}
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMCache::GetFilterFromDiscription(AnsiString pDiscription)
{
    return this->PEventManager->XMLSettings->GetFileExtFromDiscription(pDiscription, MM_FLT_Cache);
// stuff
    return "";
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::GetFileInfo(AnsiString pFile)
{
// stuff
}
//----------------------------------------------------------------------------
// wrapers for the TMMFiles class
//----------------------------------------------------------------------------
void __fastcall TMMCache::UninstallFiles(PFileList pFileList)
{
// stuff
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::RenameFiles(PFileList pFileList)
{
// stuff
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::DeleteFiles(PFileList pFileList)
{
// stuff
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::GetFiles()
{
// stuff
    GetFileList(Folder, false, LoadFilesType, FileFilters, FileTypes, MM_FLT_Cache);
    // verify files form Cache.ini
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::GetFileTypes()
{
	this->PEventManager->XMLSettings->GetFileExts(fFileTypes, MM_FLT_Cache);
}
//----------------------------------------------------------------------------;
void __fastcall TMMCache::GetFileFilters()
{
	this->PEventManager->XMLSettings->GetFileFilters(fFileFilters, MM_FLT_Cache);
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::GetFileDiscriptions()
{
   this->PEventManager->XMLSettings->GetFileDiscriptions(fFileDiscriptions, MM_FLT_Cache);
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::GetFileData(AnsiString pFileName)
{
// stuff
//get ini file name here
}
//----------------------------------------------------------------------------
UnicodeString __fastcall TMMCache::GetINIFileName(AnsiString pFileName)
{
	UnicodeString tmp = "Not Found";

	if(pif->ValueExists("Cache", ChangeFileExt(pFileName, "")))
		tmp = pif->ReadString("Cache", ChangeFileExt(pFileName, ""), "Not Found");

	return tmp;
}
//----------------------------------------------------------------------------
// virtual in TFiles
//----------------------------------------------------------------------------
int  __fastcall TMMCache::GetFileIcon(AnsiString pFileExt)
{
	return this->PEventManager->XMLSettings->GetFileIcon(pFileExt, MM_FLT_Cache);
}
//----------------------------------------------------------------------------
// Events
//----------------------------------------------------------------------------
void __fastcall TMMCache::OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType)
{
	FileList->Copy(pFileList);
	FormatFileList(FileList);

	if(this->PEventManager->OnGotFileList)
		this->PEventManager->OnGotFileList(this, FileList, plistType);

	UnicodeString query = "BEGIN TRANSACTION;";
	//TStrings* Inputs = new TStringList();
	//Inputs->Add(query);
	/*
	for(int i=0;i<FileList->Count;i++)
	{
		PFileInfo temp =  FileList->Files[i];
		query = "INSERT INTO Files VALUES(null," + IntToStr(temp->Num)       + ", " +
												   IntToStr(temp->BelongsTo) + ", '" +
												   temp->FileName            + "', " +
												   temp->FileSize            + ", '" +
												   temp->FileDate            + "', '" +
												   temp->FileLocation        + "', " +
												   temp->Installed           + ", '" +
												   temp->CRC32               + "');";
		Inputs->Add(query);
	}
	*/
	//Inputs->Add("COMMIT;");
	//ShowMessage(Inputs->Text);

	try
	{
		for(int i=0;i<FileList->Count;i++)
		{
			PFileInfo temp =  FileList->Files[i];
			query = "INSERT INTO Files VALUES(null," + IntToStr(temp->Num)       + ", " +
													   IntToStr(temp->BelongsTo) + ", '" +
													   temp->FileName            + "', " +
													   temp->FileSize            + ", '" +
													   temp->FileDate            + "', '" +
													   temp->FileLocation        + "', " +
													   temp->Installed           + ", '" +
													   temp->CRC32               + "');";
			SQLQuery1->SQL->Text = query;
			SQLQuery1->ExecSQL(true);
		}

		 //SQLQuery1->SQL->AddStrings(Inputs);
		 //SQLQuery1->SQL->
		 //SQLQuery1->SQL->Text = Inputs->Text;// query;
		 //SQLQuery1->ExecSQL(true);
		 //SQLQuery1->Active = true;
	}
	catch (Exception& E)
	{
		ShowMessage("No Insert\nException\n" + E.Message);
	}

    //SQLQuery1->Active    = false;

	 /*
    TStringList* names;
	TField* currentField;
	String currentLine;

	if (!SQLQuery1->IsEmpty())
	{
	  SQLQuery1->First();
	  names = new TStringList;

	  try{
		SQLQuery1->GetFieldNames(names);

		while (!SQLQuery1->Eof)
		{
		  currentLine = "";

		  for (int i = 0; i < names->Count; ++i)
		  {
			currentField = SQLQuery1->FieldByName(names->Strings[i]);
			currentLine = currentLine + " " + currentField->AsString;
		  }

		   ShowMessage(currentLine);
		   SQLQuery1->Next();
	    }
	  }
	  	catch (Exception& E)
	{
		ShowMessage("No Insert\nException raised with message" + E.Message);
	}
	}
	 */
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::MakeListViewTable(TListColumns* pCols)
{
    pCols->BeginUpdate();
    pCols->Clear();
    TListColumn* NewColumn;

	_di_IXMLCacheTableType CacheDisplayTable         = this->PEventManager->XMLSettings->Tables->Get_CacheTable();
	_di_IXMLCacheAlignmentType CacheTablesAllingment = this->PEventManager->XMLSettings->TablesAlignment->Get_CacheAlignment();

    for(int i=0;i<CacheDisplayTable->Count;i++)
    {
        NewColumn          = pCols->Add();
        NewColumn->Caption = CacheDisplayTable->Get_Item(i)->Text;
        NewColumn->Width   = StrToIntDef(CacheDisplayTable->Get_Item(i)->Get_id(), 50);

		if(this->PEventManager->XMLSettings->GameData->ColArrange)
        {
            for(int x=0;x<CacheTablesAllingment->Count;x++)
            {
				if(!NewColumn->Caption.Compare(CacheTablesAllingment->Get_Item(x)->Text))
                {
                    if(CacheTablesAllingment->Get_Item(x)->Get_id()==1)
                        NewColumn->Alignment = taRightJustify;
                    else if(CacheTablesAllingment->Get_Item(x)->Get_id()==2)
                        NewColumn->Alignment = taCenter;
                }
            }
        }
    }

	pCols->EndUpdate();
}
//----------------------------------------------------------------------------
void __fastcall TMMCache::FormatFileList(PFileList pFileList)
{
    for(int i=0;i<pFileList->Count;i++)
    {
       // pFileList->Files[i]->
    }
}
//----------------------------------------------------------------------------

