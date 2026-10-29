#include <Registry.hpp>
#include "TSettings.h"  
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TSettings::TSettings()
    : TReg()
{
    LogFile        = "tmp.xml"; // default
    GameTag        = "";
    GameFolder     = "";
    ProgramFolder  = IncludeTrailingBackslash(ExtractFilePath(ParamStr(0)));
    MapFolder      = "";
    CacheFolder    = "";
    ArchiveFolder  = "";
    UserFile       = "User.ini";
    LogFile        = "";
    PlayGameString = "";
    LoadSettings();
}
//----------------------------------------------------------------------------
__fastcall TSettings::~TSettings()
{
    this->SaveSettings();
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetStringValue(const int Index, AnsiString Value)
{
    switch(Index)
    {
        case  0 : FGameTag        = Value; break;
        case  1 : FGameFolder     = Value; break;
        case  2 : FProgramFolder  = Value; break;
        case  3 : FMapFolder      = Value; break;
        case  4 : FCacheFolder    = Value; break;
        case  5 : FArchiveFolder  = Value; break;
        case  6 : FUserFile       = Value; break;
        case  7 : FLogFile        = Value; break;
        case  8 : FPlayGameString = Value; break;
        case  9 : FGameEXE        = Value; break;
        case 10 : FServerEXE      = Value; break;
        case 11 : FMusicFolder    = Value; break;
        case 12 : FTextureFolder  = Value; break;
    }

    if(Index>=0 && Index<=12)
        if(OnSettingsChanged)
            OnSettingsChanged(this);
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetBoolValue(const int Index, const bool Value)
{
    switch(Index)
    {
        case 0 : FMapSubFolders     = Value; break;
        case 1 : FArchiveSubFolders = Value; break;
        case 2 : FColArrange        = Value; break;
        case 3 : FSmartUninstall    = Value; break;
        case 4 : FColorCodeText     = Value; break;
    }

    if(Index>=0 && Index<=4)
        if(OnSettingsChanged)
            OnSettingsChanged(this);
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetIntValue(const int Index, const int Value)
{
    switch(Index)
    {
        case  0 : FGameMode = Value; break;
        default : FGameMode = Value; break; // only b/c its the only 1
    }

    if(Index==0)
        if(OnSettingsChanged)
            OnSettingsChanged(this);
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetInstallMode(const TMM_InstallMode Value)
{
    if(FInstallMode!=Value)
    {
        FInstallMode = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetSmartBackup(const TMM_SmartBackup Value)
{
    if(FSmartBackup!=Value)
    {
        FSmartBackup = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetInstallType(const TMM_InstallType Value)
{
    if(FInstallType!=Value)
    {
        FInstallType = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetCacheMode(const TMM_CacheMode Value)
{
    if(FCacheMode!=Value)
    {
        FCacheMode = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetGameType(const TMM_GameType Value)
{
    if(FGameType!=Value)
    {
        FGameType = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SetLoadArchivesType(const TMM_LoadArchivesType Value)
{
    if(FLoadArchivesType!=Value)
    {
        FLoadArchivesType = Value;

        if(OnSettingsChanged)
            OnSettingsChanged(this);
    }
}
//----------------------------------------------------------------------------
// Event
//----------------------------------------------------------------------------
void __fastcall TSettings::OnSettingsChangedEvent(TObject* Sender)
{
    this->SaveSettings();
}
//----------------------------------------------------------------------------
void __fastcall TSettings::GetGameTag() // also sets the GameTag - private function
{
    GameTag = this->GetGameTag(GameType);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TSettings::GetGameTag(TMM_GameType Type) // onlt returns the GameTag - public function
{
    return TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameTypes",
           TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStringTypes", GameTag));
}
//----------------------------------------------------------------------------
AnsiString __fastcall TSettings::GetSettingsFile()
{
    return TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\SettingsFile",
           TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStringTypes", GameTag));
}
//---------------------------------------------------------------------------
AnsiString __fastcall TSettings::GetGameEXE()
{
    return TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameEXE",
           TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStringTypes", GameTag));
}
//---------------------------------------------------------------------------
AnsiString __fastcall TSettings::GetServerEXE()
{
    return TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\ServerEXE",
           TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameStringTypes", GameTag));
}
//---------------------------------------------------------------------------
TMM_GameType __fastcall TSettings::LoadGameType()
{
    return (TMM_GameType) StrToIntDef(TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\Settings", "GameType"), 11);
}
//---------------------------------------------------------------------------
AnsiString __fastcall TSettings::LoadGameTag()
{
    return  TReg::GetDataFor("SOFTWARE\\Nasty PC's\\Map Manager\\GameTypes", IntToStr(GameType));
}
//---------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------
void __fastcall TSettings::LoadSettings()
{
    OnSettingsChanged = NULL; // stop events from running when loading!!
    GameType          = this->LoadGameType();
    GameTag           = this->LoadGameTag();
    LogFile           = "Archives" + GameTag + ".xml"; // default is Archives - lok into it, make it work better ;)
    AnsiString RegKey = "SOFTWARE\\Nasty PC's\\Map Manager\\Settings\\" + GameTag + "\\";
    // Archives
    ArchiveFolder     = IncludeTrailingPathDelimiter(TReg::GetDataFor(RegKey, "ArchiveFolder"));
    InstallMode       = (TMM_InstallMode) StrToIntDef(TReg::GetDataFor(RegKey, "InstallMode"), 1);  // MM_IM_Smart
    InstallType       = (TMM_InstallType) StrToIntDef(TReg::GetDataFor(RegKey, "InstallType"), 1);  // MM_IT_DropFolders
    ArchiveSubFolders = StrToBool(TReg::GetDataFor(RegKey, "ArchiveSubFolders"));                   // 0 = false
    LoadArchivesType  = (TMM_LoadArchivesType) StrToIntDef(TReg::GetDataFor(RegKey, "LoadArchivesType"), 0);                    // 0 = MM_LAT_None
    //Maps
    MapFolder         = IncludeTrailingPathDelimiter(TReg::GetDataFor(RegKey, "MapFolder"));
    MapSubFolders     = StrToBool(TReg::GetDataFor(RegKey, "MapSubFolders"));                       // 0 = false
    GameEXE           = TReg::GetDataFor(RegKey, "GameEXE");
    ServerEXE         = TReg::GetDataFor(RegKey, "ServerEXE");
    //general
    GameFolder        = IncludeTrailingPathDelimiter(TReg::GetDataFor(RegKey, "GameFolder"));
    SmartUninstall    = StrToBool(TReg::GetDataFor(RegKey, "SmartUninstall"));                      // 0 = false
    SmartBackup       = (TMM_SmartBackup) StrToIntDef(TReg::GetDataFor(RegKey, "SmartBackup"), 1);  //MM_SB_RenameFile
    // Cache
    CacheFolder       = IncludeTrailingPathDelimiter(TReg::GetDataFor(RegKey, "CacheFolder"));
    CacheMode         = (TMM_CacheMode) StrToIntDef(TReg::GetDataFor(RegKey,  "CacheMode"), 1);     // MM_CM_Smart
    // Misc
    UserFile          = TReg::GetDataFor(RegKey, "UserFile");
    PlayGameString    = TReg::GetDataFor(RegKey, "PlayGameString");
    ColArrange        = StrToBool(TReg::GetDataFor(RegKey, "ColArrange"));                          // true
    GameMode          = StrToIntDef(TReg::GetDataFor(RegKey, "GameMode"), 0);
    ColorCodeText     = StrToBool(TReg::GetDataFor(RegKey, "ColorCodeText"));                          // true

    OnSettingsChanged = OnSettingsChangedEvent;
}
//----------------------------------------------------------------------------
void __fastcall TSettings::SaveSettings()
{
    Registry->CloseKey();
    
    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Settings\\" + GameTag + "\\", true))
    {   // Archives
        Registry->WriteString("ArchiveFolder",     ArchiveFolder);
        Registry->WriteString("InstallMode",       IntToStr(InstallMode));
        Registry->WriteString("InstallType",       IntToStr(InstallType));
        Registry->WriteString("ArchiveSubFolders", BoolToStr(ArchiveSubFolders, false));
        Registry->WriteString("LoadArchivesType",  IntToStr(LoadArchivesType));
        // Maps
        Registry->WriteString("MapFolder",         MapFolder);
        Registry->WriteString("MapSubFolders",     BoolToStr(MapSubFolders, false));
        Registry->WriteString("GameEXE",           GameEXE);
        Registry->WriteString("ServerEXE",         ServerEXE);
        //General
        Registry->WriteString("GameFolder",        GameFolder);
        Registry->WriteString("SmartUninstall",    BoolToStr(SmartUninstall, false));
        Registry->WriteString("SmartBackup",       IntToStr(SmartBackup));
        //Cache
        Registry->WriteString("CacheFolder",       CacheFolder);
        Registry->WriteString("CacheMode",         IntToStr(CacheMode));
        //Misc
        Registry->WriteString("UserFile",          UserFile);
        Registry->WriteString("PlayGameString",    PlayGameString);
        Registry->WriteString("ColArrange",        BoolToStr(ColArrange, false));
        Registry->WriteString("GameMode",          IntToStr(GameMode));
        Registry->WriteString("ColorCodeText",     BoolToStr(ColorCodeText, true));

        Registry->CloseKey();

        if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Settings", true))
            Registry->WriteString("GameType",          IntToStr(GameType));

        Registry->CloseKey();
    }
}
//----------------------------------------------------------------------------


