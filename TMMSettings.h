#ifndef TMMSettingsH
#define TMMSettingsH
#include <vcl.h>
#include "TMMXML.h"
#include <XMLDoc.hpp>
// SQLite
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>

//---------------------------------------------------------------------------
/*
typedef struct
{
    AnsiString MapFolder;
    AnsiString GameFolder;
    bool       SubFolders;                        // Process SubFolders
}TMM_MapsSettings, *pMapsSettings;
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString           ArchiveFolder;
    bool                 SubFolders;               // Process SubFolders
    TMM_LoadArchivesType LoadArchivesType;         // default=0, MM_LAT_None, MM_LAT_Validate, MM_LAT_Filter, MM_LAT_ValidateAndFilter
    TMM_InstallMode      InstallMode;              // default=1->MM_IM_None, MM_IM_Smart, MM_IM_Force
    TMM_InstallType      InstallType;              // default=1->MM_IT_KeepFolders, MM_IT_DropFolders
    bool                 SmartUninstall;           // remove files from logs and uninstall files from archive too
}TMM_ArchivesSettings, *pArchivesSettings;
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString    CacheFolder;
    bool          SubFolders;
    TMM_CacheMode CacheMode;          // default=1->MM_CM_None, MM_CM_Smart, MM_CM_Force, MM_CM_Remove, MM_CM_SmartAndRemove, MM_CM_ForceAndRemove
}TMM_CacheSettings, *pCacheSettings;
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString      GameTag;                  // UT2003, etc....
    AnsiString      SettingsFile;
    AnsiString      GameFolder;               // C:\UT2003
    AnsiString      ProgramFolder;            // MM Instaled folde
    AnsiString      UserFile;                 // User.ini
    AnsiString      LogFile;                  // log file for DB
    AnsiString      PlayGameString;           // parms to pas to exe when starting a game/server
    AnsiString      GameEXE;                  // System\UT2003.exe
    AnsiString      ServerEXE;                // System\UCC.exe
    TMM_GameType    GameType;                 // default=0->MM_GT_NotSpecified
    TMM_SmartBackup SmartBackup;              // default=1->MM_SB_DoNothing, MM_SB_RenameFile
    int             GameMode;                 // Game Launching, run UT2003.exe ot UCC.exe
    bool            ColArrange;               // arrange coloums, + something else...look into it (main form I think)
    bool            SmartUninstall;           // remove files from logs and uninstall files from archive too
    bool            ColorCodeText;
}TMM_ProgramSettings, *pProgramSettings;
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString ScreenShotsFolder;
    bool       SubFolders;
}TMM_ScreenShotsSettings, *pScreenShotsSettings;
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString DemosFolder;
    bool       SubFolders;
}TMM_DemosSettings, *pDemosSettings;
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString TextureFolder;
    bool       SubFolders;
}TMM_TextureSettings, *pTextureSettings;
//---------------------------------------------------------------------------
typedef struct
{
    AnsiString MusicFolder;
    bool       SubFolders;
}TMM_MusicSettings, *pMusicSettings;
*/
//---------------------------------------------------------------------------
class TMMSettings : public TMMXML//TMMReg
{
private:
	TSQLConnection *SQLConnection1;
	TSQLQuery      *SQLQuery1;
    TSQLDataSet    *SQLDataSet1;

    _di_IXMLDocument            fXMLSSettingsFile;
	_di_IXMLNode                fXMLSRootNode; // root node
	_di_IXMLGameTypesType       fGameTypes;
    _di_IXMLGamesType           fGames;
    _di_IXMLGameSettingsType    fGameSettings;
    _di_IXMLGameDataType        fGameData;
    _di_IXMLMenuTypesType       fMenuTypes;
    _di_IXMLDisplayMenusType    fDisplayMenus;
    _di_IXMLTablesType          fTables;
    _di_IXMLTablesAlignmentType fTablesAlignment;
    _di_IXMLIconsType           fIcons;
    _di_IXMLSettingsItemType    fGameItem;

    int fLastGameType;
    int fGameMode;

    bool fMapSubFolders;
    bool fArchiveSubFolders;
    bool fColArrange;
    bool fSmartUninstall;
    bool fColorCodeText;
    bool fFilterRequired;
    bool fSmartGameTypeInstall;

    AnsiString fGameTag;
    AnsiString fGameFolder;
    AnsiString fProgramFolder;
    AnsiString fMapFolder;
    AnsiString fCacheFolder;
    AnsiString fArchiveFolder;
    AnsiString fUserFile;
    AnsiString fLogFile;
    AnsiString fPlayGameString;
    AnsiString fGameEXE;
    AnsiString fServerEXE;
    AnsiString fMusicFolder;
    AnsiString fTextureFolder;
    AnsiString fDemosFolder;
    AnsiString fScreenShotsFolder;
    AnsiString fSettingsFile;
    AnsiString fMapsExt;
    AnsiString fRegKey; 
    AnsiString fDemoExt;
    AnsiString fTexturesExt;
    AnsiString fMusicExt;
    AnsiString fScreenShotExt;
    AnsiString fCacheFile;

    TMM_InstallMode fInstallMode;
    TMM_SmartBackup fSmartBackup;
    TMM_InstallType fInstallType;
    TMM_CacheMode   fCacheMode;
    TMM_GameType    fGameType;

	TMM_LoadArchivesType fLoadArchivesType;


/*
    TMM_MapsSettings        fMapsSettings;
    TMM_ArchivesSettings    fArchivesSettings;
    TMM_CacheSettings       fCacheSettings;
    TMM_ProgramSettings     fProgramSettings;
    TMM_MusicSettings       fMusicSettings;
    TMM_TextureSettings     fTextureSettings;
    TMM_DemosSettings       fDemosSettings;
    TMM_ScreenShotsSettings fScreenShotsSettings;
*/
    // events
    TNotifyEvent FOnSettingsChanged;  // ussed to keep the settings uptodate all the time
//----------------------------------------------------------------------------------------------
//  Type                    Method Name           Parm - Type            Name,  Type       Name
    void         __fastcall SetStringValue         (const int                  Index, AnsiString Value);
    void         __fastcall SetIntValue            (const int                  Index, const int  Value);
    void         __fastcall SetBoolValue           (const int                  Index, const bool Value);
    void         __fastcall SetInstallMode         (const TMM_InstallMode      Value);
    void         __fastcall SetSmartBackup         (const TMM_SmartBackup      Value);
    void         __fastcall SetInstallType         (const TMM_InstallType      Value);
    void         __fastcall SetCacheMode           (const TMM_CacheMode        Value);
    void         __fastcall SetGameType            (const TMM_GameType         Value);
    void         __fastcall SetLoadArchivesType    (const TMM_LoadArchivesType Value);

    void         __fastcall OnSettingsChangedEvent (TObject*                   Sender);
    AnsiString __fastcall StripValue(AnsiString Value);
public:
         __fastcall TMMSettings();
         __fastcall ~TMMSettings();
    void __fastcall LoadSettings();
    void __fastcall SaveSettings();
   //	void __fastcall GetMapTypes(TStrings* Data);
    void __fastcall GetMapMenuData(TStrings* Data);
    //void __fastcall GetArchiveTypes(TStrings* Data);
    //void __fastcall GetMenus(TStrings* Data);
    AnsiString __fastcall GetMapFilter(AnsiString Desceiption);
    AnsiString __fastcall GetMapDesceiption(AnsiString Filter);
    // popup menu Maps
	void __fastcall GetMapsMenu   (int Part, TStrings* pData);
	bool __fastcall AddMapsMenu   (AnsiString id, AnsiString Discription);
    bool __fastcall DelMapsMenu   (AnsiString id, AnsiString Discription);
	bool __fastcall EditMapsMenu  (AnsiString oldid, AnsiString oldDiscription, AnsiString newid, AnsiString newDiscription);


	void __fastcall GetFileTypes();
	void __fastcall GetFileTypesGroups();
	void __fastcall GetGameTypes();
	void __fastcall GetGameIcons();
	void __fastcall GetGameSettings();
	void __fastcall GetInstallTypes();
	void __fastcall GetMenuGroups();
	void __fastcall GetMenus();
	void __fastcall GetSettings();

	int  __fastcall GetFileTypes(TStrings* Data,  TMM_FilesListType Type);

    int  __fastcall GetFileIcon(UnicodeString FileExt,  TMM_FilesListType Type);
	void __fastcall GetFileExts(TStrings* Data,         TMM_FilesListType Type);
	void __fastcall GetFileFilters(TStrings* Data,      TMM_FilesListType Type);
	void __fastcall GetFileDiscriptions(TStrings* Data, TMM_FilesListType Type);
	UnicodeString __fastcall GetFileExtFromDiscription(UnicodeString Discription, TMM_FilesListType Type);

	__int64       __fastcall GetIntValueFromDB(UnicodeString FieldName, UnicodeString TableName);
	UnicodeString __fastcall GetStrValueFromDB(UnicodeString FieldName, UnicodeString TableName);
	void          __fastcall GetStrListFromDB(UnicodeString FieldName, UnicodeString TableName, TStrings* pData);

    int fMapTypeValue;
__published:
    __property int                  GameMode          = {read=fGameMode,             write=SetIntValue,         index=0, default=0};
    __property int                  LastGameType      = {read=fLastGameType,         write=SetIntValue,         index=1, default=0};

    __property bool                 MapSubFolders     = {read=fMapSubFolders,        write=SetBoolValue,        index=0, default=false};
    __property bool                 ArchiveSubFolders = {read=fArchiveSubFolders,    write=SetBoolValue,        index=1, default=false};
    __property bool                 ColArrange        = {read=fColArrange,           write=SetBoolValue,        index=2, default=true};
    __property bool                 SmartUninstall    = {read=fSmartUninstall,       write=SetBoolValue,        index=3, default=true};
    __property bool                 ColorCodeText     = {read=fColorCodeText,        write=SetBoolValue,        index=4, default=true};
    __property bool                 FilterRequired    = {read=fFilterRequired,       write=SetBoolValue,        index=5, default=true};
    __property bool                 SmartGameTypeInstall = {read=fSmartGameTypeInstall, write=SetBoolValue,     index=6, default=true};

    __property AnsiString           GameTag           = {read=fGameTag,              write=SetStringValue,      index=0};
    __property AnsiString           GameFolder        = {read=fGameFolder,           write=SetStringValue,      index=1};
    __property AnsiString           ProgramFolder     = {read=fProgramFolder,        write=SetStringValue,      index=2};
    __property AnsiString           MapFolder         = {read=fMapFolder,            write=SetStringValue,      index=3};
    __property AnsiString           CacheFolder       = {read=fCacheFolder,          write=SetStringValue,      index=4};
    __property AnsiString           ArchiveFolder     = {read=fArchiveFolder,        write=SetStringValue,      index=5};
    __property AnsiString           UserFile          = {read=fUserFile,             write=SetStringValue,      index=6};
    __property AnsiString           LogFile           = {read=fLogFile,              write=SetStringValue,      index=7};
    __property AnsiString           PlayGameString    = {read=fPlayGameString,       write=SetStringValue,      index=8};
    __property AnsiString           GameEXE           = {read=fGameEXE,              write=SetStringValue,      index=9};
    __property AnsiString           ServerEXE         = {read=fServerEXE,            write=SetStringValue,      index=10};
    __property AnsiString           MusicFolder       = {read=fMusicFolder,          write=SetStringValue,      index=11};
    __property AnsiString           TextureFolder     = {read=fTextureFolder,        write=SetStringValue,      index=12};
    __property AnsiString           DemosFolder       = {read=fDemosFolder,          write=SetStringValue,      index=13};
    __property AnsiString           ScreenShotsFolder = {read=fScreenShotsFolder,    write=SetStringValue,      index=14};
    __property AnsiString           SettingsFile      = {read=fSettingsFile,         write=SetStringValue,      index=15};
    __property AnsiString           MapsExt           = {read=fMapsExt,              write=SetStringValue,      index=16};
	__property AnsiString           RegKey            = {read=fRegKey,               write=SetStringValue,      index=17};
    __property AnsiString           DemoExt           = {read=fDemoExt,              write=SetStringValue,      index=18};
    __property AnsiString           TexturesExt       = {read=fTexturesExt,          write=SetStringValue,      index=19};
    __property AnsiString           MusicExt          = {read=fMusicExt,             write=SetStringValue,      index=20};
    __property AnsiString           ScreenShotExt     = {read=fScreenShotExt,        write=SetStringValue,      index=21};
    __property AnsiString           CacheFile         = {read=fCacheFile,            write=SetStringValue,      index=22};

    __property TMM_InstallMode      InstallMode       = {read=fInstallMode,          write=SetInstallMode,      default=MM_IM_Smart};
    __property TMM_SmartBackup      SmartBackup       = {read=fSmartBackup,          write=SetSmartBackup,      default=MM_SB_RenameFile};
    __property TMM_InstallType      InstallType       = {read=fInstallType,          write=SetInstallType,      default=MM_IT_DropFolders};
    __property TMM_CacheMode        CacheMode         = {read=fCacheMode,            write=SetCacheMode,        default=MM_CM_Smart};
    __property TMM_GameType         GameType          = {read=fGameType,             write=SetGameType,         default=MM_GT_NotSpecified};
    __property TMM_LoadArchivesType LoadArchivesType  = {read=fLoadArchivesType,     write=SetLoadArchivesType, default=MM_LAT_None};
    
    __property _di_IXMLGameSettingsType    GameSettings    =  {read=fGameSettings,   write=fGameSettings};
    __property _di_IXMLGameDataType        GameData        =  {read=fGameData,       write=fGameData};
    __property _di_IXMLMenuTypesType       MenuTypes       =  {read=fMenuTypes,      write=fMenuTypes};
    __property _di_IXMLDisplayMenusType    DisplayMenus    =  {read=fDisplayMenus,   write=fDisplayMenus};
    __property _di_IXMLTablesType          Tables          =  {read=fTables,         write=fTables};
    __property _di_IXMLTablesAlignmentType TablesAlignment = {read=fTablesAlignment, write=fTablesAlignment};
    __property _di_IXMLIconsType           Icons           =  {read=fIcons,          write=fIcons};
    __property _di_IXMLGameTypesType       GameTypes       = {read=fGameTypes,       write=fGameTypes};
    __property _di_IXMLSettingsItemType    GameItem        = {read=fGameItem,        write=fGameItem};
    __property _di_IXMLGamesType           Games           = {read=fGames,           write=fGames};
    //Event
    __property TNotifyEvent             OnSettingsChanged = {read=FOnSettingsChanged, write=FOnSettingsChanged};
    __property _di_IXMLDocument         XMLSettingsFile   = {read=fXMLSSettingsFile, write=fXMLSSettingsFile};
};
#endif
