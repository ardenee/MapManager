//#include <Registry.hpp>
#include "TMMSettings.h"
#include "StrUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TMMSettings::TMMSettings()
    : TMMXML()
{
    LogFile        = "Settings\\Logs.xml"; // default
    GameTag        = "";
    GameFolder     = "";
    ProgramFolder  = IncludeTrailingBackslash(ExtractFilePath(ParamStr(0)));
    MapFolder      = "";
    CacheFolder    = "";
    ArchiveFolder  = "";
    UserFile       = "User.ini";
    LogFile        = "";
    PlayGameString = "";
    fLastGameType  = 0;
    fSettingsFile  = fProgramFolder + "Settings\\Settings.xml";

    // XML remains the active settings store until the SQLite migration and
    // complete schema have been implemented. Never create an empty SQLite
    // database or depend on the IDE's current working directory.
    SQLConnection1 = new TSQLConnection(0);
    SQLQuery1      = new TSQLQuery(0);
    SQLDataSet1    = new TSQLDataSet(0);
    SQLConnection1->DriverName = "Sqlite";
    SQLQuery1->SQLConnection   = SQLConnection1;
    SQLDataSet1->SQLConnection = SQLConnection1;
    SQLConnection1->LoginPrompt = false;
    const UnicodeString databaseFile =
        IncludeTrailingPathDelimiter(ExtractFilePath(ParamStr(0))) + L"settings.sqlite3";
    SQLConnection1->Params->Add(L"Database=" + databaseFile);

    // The recovered settings.sqlite3.sql does not contain a Settings table.
    // Only use a pre-existing, schema-compatible database; otherwise continue
    // with the original XML settings without showing a misleading SQLite error.
    if (FileExists(databaseFile))
    {
        try
        {
            SQLConnection1->Connected = true;
            SQLQuery1->SQL->Text =
                L"SELECT name FROM sqlite_master WHERE type='table' AND name='Settings'";
            SQLQuery1->Open();
            const bool schemaReady = !SQLQuery1->IsEmpty();
            SQLQuery1->Close();
            if (!schemaReady)
                SQLConnection1->Connected = false;
        }
        catch (EDatabaseError& E)
        {
            SQLConnection1->Connected = false;
            OutputDebugStringW((UnicodeString(L"MapManager: ignoring invalid settings database ") +
                databaseFile + L": " + E.Message).c_str());
        }
    }

    if (SQLConnection1->Connected)
        GetSettings();
    // LoadSettings() always reads the existing XML source of truth.
	LoadSettings();
}
//----------------------------------------------------------------------------
__fastcall TMMSettings::~TMMSettings()
{
    this->SaveSettings();
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetStringValue(const int Index, AnsiString Value)
{
    switch(Index)
    {
        case  0 : fGameTag           = Value; break;
        case  1 : fGameFolder        = Value; break;
        case  2 : fProgramFolder     = Value; break;
        case  3 : fMapFolder         = Value; break;
        case  4 : fCacheFolder       = Value; break;
        case  5 : fArchiveFolder     = Value; break;
        case  6 : fUserFile          = Value; break;
        case  7 : fLogFile           = Value; break;
        case  8 : fPlayGameString    = Value; break;
        case  9 : fGameEXE           = Value; break;
        case 10 : fServerEXE         = Value; break;
        case 11 : fMusicFolder       = Value; break;
        case 12 : fTextureFolder     = Value; break;
        case 13 : fDemosFolder       = Value; break;
        case 14 : fScreenShotsFolder = Value; break;
        case 15 : fSettingsFile      = Value; break;
        case 16 : fMapsExt           = Value; break;
        case 17 : fRegKey            = Value; break;
        case 18 : fDemoExt           = Value; break;
        case 19 : fTexturesExt       = Value; break;
        case 20 : fMusicExt          = Value; break;
        case 21 : fScreenShotExt     = Value; break;
        case 22 : fCacheFile         = Value; break;
    }

    if(Index>=0 && Index<=22)
        if(OnSettingsChanged)
            OnSettingsChanged(this);
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetBoolValue(const int Index, const bool Value)
{
    switch(Index)
    {
        case 0 : fMapSubFolders        = Value; break;
        case 1 : fArchiveSubFolders    = Value; break;
        case 2 : fColArrange           = Value; break;
        case 3 : fSmartUninstall       = Value; break;
        case 4 : fColorCodeText        = Value; break;
        case 5 : fFilterRequired       = Value; break;
        case 6 : fSmartGameTypeInstall = Value; break;
    }

    if(Index>=0 && Index<=6)
        if(OnSettingsChanged)
            OnSettingsChanged(this);
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetIntValue(const int Index, const int Value)
{
    switch(Index)
    {
        case  0 : fGameMode     = Value; break;
        case  1 : fLastGameType = Value; break;
        default : fGameMode     = Value; break; // only b/c its the only 1
    }

    if(Index>=0 && Index<=1)
        if(OnSettingsChanged)
            OnSettingsChanged(this);
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetInstallMode(const TMM_InstallMode Value)
{
    if(fInstallMode!=Value)
    {
        fInstallMode = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetSmartBackup(const TMM_SmartBackup Value)
{
    if(fSmartBackup!=Value)
    {
        fSmartBackup = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetInstallType(const TMM_InstallType Value)
{
    if(fInstallType!=Value)
    {                                       
        fInstallType = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetCacheMode(const TMM_CacheMode Value)
{
    if(fCacheMode!=Value)
    {
        fCacheMode = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetGameType(const TMM_GameType Value)
{
    if(fGameType!=Value)
    {
        fGameType = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SetLoadArchivesType(const TMM_LoadArchivesType Value)
{
    if(fLoadArchivesType!=Value)
    {
        fLoadArchivesType = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
// Event
//----------------------------------------------------------------------------
void __fastcall TMMSettings::OnSettingsChangedEvent(TObject* Sender)
{
    this->SaveSettings();
}
//---------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------
void __fastcall TMMSettings::LoadSettings()
{
	//UnicodeString query = "Select LastSeletedGame from Settings;";
    if (SQLConnection1->Connected)
    {
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}


	TStringList* fields;

	if (!SQLQuery1->IsEmpty())
	{
		  SQLQuery1->First();
		  fields = new TStringList;

		  try{
				SQLQuery1->GetFieldNames(fields);

				while (!SQLQuery1->Eof)
				{
					  for (int i = 0; i < fields->Count; ++i)
					  {
						//fLastGameType = SQLQuery1->FieldByName(fields->Strings[i])->AsInteger;
					  }
					   SQLQuery1->Next();
				}
		  }
		  catch (Exception& E)
		  {
			ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
			//return;
		  }

			fields->Free();
	}

	SQLQuery1->Close();
    }

	fXMLSSettingsFile = LoadXMLDocument(fSettingsFile);
	OnSettingsChanged = NULL; // stop events from running when loading!!

	if(fXMLSSettingsFile)
	{
		fXMLSSettingsFile->Active     = true;
		fXMLSSettingsFile->StandAlone = "yes";
	}

	// Get All Games
    fGames = GetGames(fXMLSSettingsFile);
    // Get Last GameType
    fLastGameType  = fGames->Get_LastGameType();
    fGameTypes     = fGames->Get_GameTypes();
    fGameSettings  = fGames->Get_GameSettings();

    _di_IXMLSettingsItemType GameItem;
    
    for(int i=0;i<fGameSettings->Count;i++)
    {
        GameItem = fGameSettings->Get_SettingsItem(i);

        if(GameItem->Get_id()==fLastGameType)
            break;
    }

    // if not found at all

    // get game setting gfor GameUnknown
    if(GameItem->Get_id()!=fLastGameType)
        GameItem = fGameSettings->Get_SettingsItem(0);


    fGameData        = GameItem->Get_GameData(); 
    fMenuTypes       = fGameData->Get_MenuTypes();
    fDisplayMenus    = fGameData->Get_DisplayMenus();
    fTables          = fGameData->Get_Tables();
    fTablesAlignment = fGameData->Get_TablesAlignment();
    fIcons           = fGameData->Get_Icons();

    fArchiveFolder        = GameData->Get_ArchiveFolder();
    fArchiveSubFolders    = GameData->Get_ArchiveSubFolders();
    fCacheFolder          = GameData->Get_CacheFolder();
    fCacheMode            = (TMM_CacheMode) GameData->Get_CacheMode();
    fColArrange           = GameData->Get_ColArrange();
    fColorCodeText        = GameData->Get_ColorCodeText();
    fDemosFolder          = GameData->Get_DemosFolder();
    fFilterRequired       = GameData->Get_FilterRequired();
    fGameEXE              = GameData->Get_GameEXE();
    fGameFolder           = GameData->Get_GameFolder();
    fGameMode             = GameData->Get_GameMode();
    fInstallMode          = (TMM_InstallMode) GameData->Get_InstallMode();
    fInstallType          = (TMM_InstallType) GameData->Get_InstallType();
    fLoadArchivesType     = (TMM_LoadArchivesType) GameData->Get_LoadArchivesType();
    fLogFile              = GameData->Get_LogFile();
    fMapFolder            = GameData->Get_MapFolder();
    fMapsExt              = GameData->Get_MapsExt();
    fMapSubFolders        = GameData->Get_MapSubFolders();
    fMusicFolder          = GameData->Get_MusicFolder();
    fPlayGameString       = GameData->Get_PlayGameString();
    fProgramFolder        = GameData->Get_ProgramFolder();
    fRegKey               = GameData->Get_RegKey();
    fScreenShotsFolder    = GameData->Get_ScreenShotsFolder();
    fServerEXE            = GameData->Get_ServerEXE();
    fSmartBackup          = (TMM_SmartBackup) GameData->Get_SmartBackup();
    fSmartGameTypeInstall = GameData->Get_SmartGameTypeInstall();
    fSmartUninstall       = GameData->Get_SmartUninstall();
    fTextureFolder        = GameData->Get_TextureFolder();
    fUserFile             = GameData->Get_UserFile();
    fGameTag              = GameData->Get_GameTag();
    fGameType             = (TMM_GameType) fLastGameType;
    fDemoExt              = GameData->Get_DemoExt();
    fTexturesExt          = GameData->Get_TexturesExt();
    fMusicExt             = GameData->Get_MusicExt();
    fScreenShotExt        = GameData->Get_ScreenShotExt();
    fCacheFile            = GameData->Get_CacheFile();

    //LogFile             = GameTag + LogFile;
    OnSettingsChanged = OnSettingsChangedEvent;
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::SaveSettings()
{
    OnSettingsChanged = NULL; // stop events from running when loading!!

    Games->Set_LastGameType(fLastGameType);
    GameData->Set_ArchiveFolder(fArchiveFolder);
    GameData->Set_ArchiveSubFolders(fArchiveSubFolders);
    GameData->Set_CacheFolder(fCacheFolder);
    GameData->Set_CacheMode(fCacheMode);
    GameData->Set_ColArrange(fColArrange);
    GameData->Set_ColorCodeText(fColorCodeText);
    GameData->Set_DemosFolder(fDemosFolder);
    GameData->Set_FilterRequired(fFilterRequired);
    GameData->Set_GameEXE(fGameEXE);
    GameData->Set_GameFolder(fGameFolder);
    GameData->Set_GameMode(fGameMode);
    GameData->Set_InstallMode(fInstallMode);
    GameData->Set_InstallType(fInstallType);
    GameData->Set_LoadArchivesType(fLoadArchivesType);
    GameData->Set_LogFile(fLogFile);
    GameData->Set_MapFolder(fMapFolder);
    GameData->Set_MapsExt(fMapsExt);
    GameData->Set_MapSubFolders(fMapSubFolders);
    GameData->Set_MusicFolder(fMusicFolder);
    GameData->Set_PlayGameString(fPlayGameString);
    GameData->Set_ProgramFolder(fProgramFolder);
    GameData->Set_RegKey(fRegKey);
    GameData->Set_ScreenShotsFolder(fScreenShotsFolder);
    GameData->Set_ServerEXE(fServerEXE);
    GameData->Set_SmartBackup(fSmartBackup);
    GameData->Set_SmartGameTypeInstall(fSmartGameTypeInstall);
    GameData->Set_SmartUninstall(fSmartUninstall);
    GameData->Set_TextureFolder(fTextureFolder);
    GameData->Set_UserFile(fUserFile);
    GameData->Set_GameTag(fGameTag);
    GameData->Set_DemoExt(fDemoExt);
    GameData->Set_TexturesExt(fTexturesExt);
    GameData->Set_MusicExt(fMusicExt);
    GameData->Set_ScreenShotExt(fScreenShotExt);
    GameData->Set_CacheFile(fCacheFile);

    fXMLSSettingsFile->SaveToFile(fSettingsFile);
    OnSettingsChanged = OnSettingsChangedEvent;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetFileTypes()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetFileTypesGroups()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetGameTypes()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetGameIcons()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetGameSettings()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetInstallTypes()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetMenuGroups()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetMenus()
{
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
*/
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetSettings()
{
	fLastGameType = GetIntValueFromDB("LastSeletedGame", "Settings");
/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings;";
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect LastSeletedGame from Settings;\n" + E.Message);
	}

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		__try
		{
			fLastGameType = SQLQuery1->FieldByName("LastSeletedGame")->AsInteger;
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetSettings()\nSQLQuery1->FieldByName('LastSeletedGame')->AsInteger;\n" + E.Message);
		}
	}
	else
	{
		fLastGameType = 2; // ut2004 default
	}

	SQLQuery1->Close();
	*/
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
__int64 __fastcall TMMSettings::GetIntValueFromDB(UnicodeString FieldName, UnicodeString TableName)
{
	__int64 Value = 0;

	try
	{
		SQLQuery1->SQL->Text = "Select "+FieldName+" from "+TableName+";";
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetIntValueFromDB()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		try
		{
			Value = SQLQuery1->FieldByName(FieldName)->AsInteger;
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetIntValueFromDB()\nSQLQuery1->FieldByName('"+FieldName+"')->AsInteger;\n" + E.Message);
		}
	}

	SQLQuery1->Close();
	return Value;
}
//----------------------------------------------------------------------------
UnicodeString __fastcall TMMSettings::GetStrValueFromDB(UnicodeString FieldName, UnicodeString TableName)
{
	UnicodeString Value = "";

	try
	{
		SQLQuery1->SQL->Text = "Select "+FieldName+" from "+TableName+";";
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetStrValueFromDB()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		try
		{
			Value = SQLQuery1->FieldByName(FieldName)->AsString;
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetStrValueFromDB()\nSQLQuery1->FieldByName('"+FieldName+"')->AsString;\n" + E.Message);
		}
	}

	SQLQuery1->Close();
	return Value;
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetStrListFromDB(UnicodeString FieldName, UnicodeString TableName, TStrings* pData)
{
	pData->Clear();

	try
	{
		SQLQuery1->SQL->Text = "Select "+FieldName+" from "+TableName+";";
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetStrListFromDB()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}

	//TStringList* fields;
	//int i=0;

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();
		//fields = new TStringList;

		try{
			//SQLQuery1->GetFieldNames(fields);

			while(!SQLQuery1->Eof)
			{
				//for(i=0; i<fields->Count; ++i)
				//{
				pData->Add(SQLQuery1->FieldByName(FieldName)->AsString);
				//}
				SQLQuery1->Next();
			}
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetStrListFromDB()\n+SQLQuery1->FieldByName('"+FieldName+"')->AsString\n" + E.Message);
		}

			//fields->Free();
	}

	SQLQuery1->Close();
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
UnicodeString __fastcall TMMSettings::GetFileExtFromDiscription(UnicodeString Discription, TMM_FilesListType Type)
{
	UnicodeString tabel = "FileFilters";

	switch(Type)
	{
		case MM_FLT_Cache : tabel = "CacheFiles"; break;
		default           : tabel = "FileFilters";
	}

	try
	{
		SQLQuery1->SQL->Text = "SELECT value FROM "+tabel+" WHERE name='"+Discription+"' and type="+IntToStr(Type)+";";
		SQLQuery1->Open();
		//ShowMessage("TMMSettings::GetFileExtFromDiscription()\n"+SQLQuery1->SQL->Text);
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetFileExtFromDiscription()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}


	/*
	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		__try{

			while(!SQLQuery1->Eof)
			{
				Data->Add(SQLQuery1->FieldByName("value")->AsString);
				SQLQuery1->Next();
			}
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetFileFilters()\n"+SQLQuery1->SQL->Text+" - 2\n" + E.Message);
		}
	}

	*/

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		try
		{
			//ShowMessage("TMMSettings::GetFileExtFromDiscription\n"+SQLQuery1->FieldByName("value")->AsString);
			return SQLQuery1->FieldByName("value")->AsString;
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetFileExtFromDiscription()\n"+SQLQuery1->SQL->Text+" - 2\n" + E.Message);
		}
	}

	SQLQuery1->Close();

	return "Unknown";
}
//----------------------------------------------------------------------------
int __fastcall TMMSettings::GetFileIcon(UnicodeString FileExt, TMM_FilesListType Type)
{
	UnicodeString tabel = "FileIcons";

	switch(Type)
	{
		case MM_FLT_Cache : tabel = "FileIcons"; break;
		default           : tabel = "FileIcons";
	}

	try
	{
		SQLQuery1->SQL->Text = "SELECT iconid FROM "+tabel+" WHERE name='"+FileExt+"' and gametype="+Type+";";
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetFileIcon()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		try
		{
			//ShowMessage("TMMSettings::GetFileIcon\n"+IntToStr(SQLQuery1->FieldByName("iconid")->AsInteger));
			return SQLQuery1->FieldByName("iconid")->AsInteger;
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetFileIcon()\n"+SQLQuery1->SQL->Text+" - 2\n" + E.Message);
		}
	}

	SQLQuery1->Close();

	return 0;
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetFileExts(TStrings* Data, TMM_FilesListType Type)
{
	Data->Clear();
	UnicodeString tabel = "FileExts";

	switch(Type)
	{
		case MM_FLT_Cache : tabel = "CacheFiles"; break;
		default           : tabel = "FileExts";
	}

	try
	{
		SQLQuery1->SQL->Text = "SELECT value FROM "+tabel+" WHERE type="+IntToStr(Type)+";";
		SQLQuery1->Open();
		//ShowMessage("TMMSettings::GetFileExts()\n"+SQLQuery1->SQL->Text);
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetFileExts()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		try{

			while(!SQLQuery1->Eof)
			{
				Data->Add(SQLQuery1->FieldByName("value")->AsString);
				SQLQuery1->Next();
			}
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetFileExts()\n"+SQLQuery1->SQL->Text+" - 2\n" + E.Message);
		}
	}

	//ShowMessage("TMMSettings::GetFileExts\n"+Data->Text);
	SQLQuery1->Close();
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetFileFilters(TStrings* Data, TMM_FilesListType Type)
{
	Data->Clear();
	UnicodeString tabel = "FileFilters";

	switch(Type)
	{
		case MM_FLT_Cache : tabel = "CacheFiles"; break;
		default           : tabel = "FileFilters";
	}

	try
	{
		SQLQuery1->SQL->Text = "SELECT value FROM "+tabel+" WHERE type="+IntToStr(Type)+";";
		SQLQuery1->Open();
		//ShowMessage("TMMSettings::GetFileFilters()\n"+SQLQuery1->SQL->Text);
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetFileFilters()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		try{

			while(!SQLQuery1->Eof)
			{
				Data->Add(SQLQuery1->FieldByName("value")->AsString);
				SQLQuery1->Next();
			}
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetFileFilters()\n"+SQLQuery1->SQL->Text+" - 2\n" + E.Message);
		}
	}

	//ShowMessage("TMMSettings::GetFileFilters\n"+Data->Text);
	SQLQuery1->Close();
}
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetFileDiscriptions(TStrings* Data, TMM_FilesListType Type)
{
	Data->Clear();
	UnicodeString tabel = "FileFilters";

	switch(Type)
	{
		case MM_FLT_Cache : tabel = "CacheFiles"; break;
		default           : tabel = "FileFilters";
	}

	try
	{
		SQLQuery1->SQL->Text = "SELECT name FROM "+tabel+" WHERE type="+IntToStr(Type)+";";
		SQLQuery1->Open();
		//ShowMessage("TMMSettings::GetFileDiscriptions()\n"+SQLQuery1->SQL->Text);
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::GetFileDiscriptions()\n"+SQLQuery1->SQL->Text+"\n" + E.Message);
	}

	if(!SQLQuery1->IsEmpty())
	{
		SQLQuery1->First();

		try{

			while(!SQLQuery1->Eof)
			{
				Data->Add(SQLQuery1->FieldByName("name")->AsString);
				SQLQuery1->Next();
			}
		}
		catch (Exception& E)
		{
			ShowMessage("TMMSettings::GetFileDiscriptions()\n"+SQLQuery1->SQL->Text+" - 2\n" + E.Message);
		}
	}

	//ShowMessage("TMMSettings::GetFileDiscriptions\n"+Data->Text);
	SQLQuery1->Close();
}
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void __fastcall TMMSettings::GetMapMenuData(TStrings* Data)
{
    Data->Clear();
    _di_IXMLMapsMenuType MapMenus = fDisplayMenus->Get_MapsMenu();

    for(int i=0;i<MapMenus->Count;i++)
		Data->Add(MapMenus->Get_SItem(i)->Text + ":" + MapMenus->Get_SItem(i)->Get_id());

	//ShowMessage(Data->Text);

		/*
	try
	{
		SQLQuery1->SQL->Text = "Select LastSeletedGame from Settings";
		SQLQuery1->ExecSQL(true);
		SQLQuery1->Open();
	}
	catch (Exception& E)
	{
		ShowMessage("TMMSettings::LoadSettings()\nSelect Exception\n" + E.Message);
		//return;
	}
   */

}
//----------------------------------------------------------------------------
// popup menu Maps
void __fastcall TMMSettings::GetMapsMenu(int Part, TStrings* pData)
{
	//switch(Part)
	//{
	//    case 0 : GetMapFilters(pData);  break;
	//    case 1 : GetMapTypes(pData);    break;
	//    case 2 : GetMapMenuData(pData); break;
    //}
}
//----------------------------------------------------------------------------
bool __fastcall TMMSettings::AddMapsMenu(AnsiString id, AnsiString Discription)
{
    bool add = true;
	id       = id.UpperCase(); // force to uppercase

    TStringList* Data = new TStringList();
    Data->Sorted = true;
	Data->Duplicates = System::Classes::dupIgnore;
    GetMapsMenu(0, Data);  // gtes the following "Capture The Flag"

    for(int i=0;i<Data->Count;i++)
    {
        if(!Data->Strings[i].Compare(id))// + ":" + Discription)) // doesnt matter about case  - type/filter match only!!
            add = false;
    }

    if(add==true)
    {
        _di_IXMLMapsMenuType MapMenus = fDisplayMenus->Get_MapsMenu();
        _di_IXMLSItemType newitem     = MapMenus->Add();
        newitem->SetText(Discription);
        newitem->Set_id(id);
        SaveSettings();
	}


    delete Data;
    return false;
}
//----------------------------------------------------------------------------
bool __fastcall TMMSettings::EditMapsMenu(AnsiString oldid, AnsiString oldDiscription, AnsiString newid, AnsiString newDiscription)
{
    newid = newid.UpperCase(); 
    _di_IXMLMapsMenuType MapMenus = fDisplayMenus->Get_MapsMenu();

    for(int i=0;i<MapMenus->Count;i++)
    {
        if(!oldid.AnsiCompareIC(MapMenus->Get_SItem(i)->Get_id()) && !oldDiscription.AnsiCompareIC(MapMenus->Get_SItem(i)->Text))
        {
            MapMenus->Get_SItem(i)->Set_id(newid);
            MapMenus->Get_SItem(i)->SetText(newDiscription);
            SaveSettings();
            return true;
        }
    }

    return false;
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMSettings::StripValue(AnsiString Value)
{
    if(AnsiStartsStr("\"", Value))
        Value.Delete(1,1);

    if(AnsiEndsStr("\"", Value))
        Value.Delete(Value.Length(),1);
        
    return Value;
}
//----------------------------------------------------------------------------
bool __fastcall TMMSettings::DelMapsMenu(AnsiString id, AnsiString Discription)
{
    _di_IXMLMapsMenuType MapMenus = fDisplayMenus->Get_MapsMenu();

    for(int i=0;i<MapMenus->Count;i++)
    {
        if(!id.AnsiCompareIC(MapMenus->Get_SItem(i)->Get_id()) && !Discription.AnsiCompareIC(MapMenus->Get_SItem(i)->Text))
        {
            MapMenus->Delete(i);
            SaveSettings();
            return true;
        }
    }

    return false;
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMSettings::GetMapFilter(AnsiString Desceiption)
{
    _di_IXMLMapsMenuType MapMenus = fDisplayMenus->Get_MapsMenu();

    for(int i=0;i<MapMenus->Count;i++)
    {
        if(!Desceiption.AnsiCompareIC(MapMenus->Get_SItem(i)->Text))
            return MapMenus->Get_SItem(i)->Get_id();
    }

    return "";
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMSettings::GetMapDesceiption(AnsiString Filter)
{
    _di_IXMLMapsMenuType MapMenus = fDisplayMenus->Get_MapsMenu();

    for(int i=0;i<MapMenus->Count;i++)
    {
        if(!Filter.AnsiCompareIC(MapMenus->Get_SItem(i)->Get_id()))
            return MapMenus->Get_SItem(i)->Text;
    }

    return "";
}
//----------------------------------------------------------------------------
