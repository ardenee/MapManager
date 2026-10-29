#ifndef TSettingsH
#define TSettingsH
#include <vcl.h>
#include "TReg.h"
//---------------------------------------------------------------------------
class TSettings : public TReg
{
private:
    AnsiString FGameTag;            // UT2003, etc....
    AnsiString FGameFolder;         // C:\UT2003
    AnsiString FProgramFolder;      // MM Instaled folder
    AnsiString FMapFolder;          // Maps (C:\U2003\Maps)
    AnsiString FCacheFolder;        // Cache (C:\U2003\Cache)
    AnsiString FArchiveFolder;      // C:\Downloads
    AnsiString FUserFile;           // User.ini
    AnsiString FLogFile;            // log file for DB
    AnsiString FPlayGameString;     // parms to pas to exe when starting a game/server
    AnsiString FGameEXE;            // System\UT2003.exe
    AnsiString FServerEXE;          // System\UCC.exe
    AnsiString FMusicFolder;        // Music (C:\UT2003\Music)
    AnsiString FTextureFolder;      // Textures (C:\UT2003\Textures)
    // enum types
    TMM_GameType         FGameType;     // default=0->MM_GT_NotSpecified
    TMM_InstallMode      FInstallMode;  // default=1->MM_IM_None, MM_IM_Smart, MM_IM_Force
    TMM_InstallType      FInstallType;  // default=1->MM_IT_KeepFolders, MM_IT_DropFolders
    TMM_SmartBackup      FSmartBackup;  // default=1->MM_SB_DoNothing, MM_SB_RenameFile
    TMM_CacheMode        FCacheMode;    // default=1->MM_CM_None, MM_CM_Smart, MM_CM_Force, MM_CM_Remove, MM_CM_SmartAndRemove, MM_CM_ForceAndRemove
    TMM_LoadArchivesType FLoadArchivesType; //default=0, MM_LAT_None, MM_LAT_Validate, MM_LAT_Filter, MM_LAT_ValidateAndFilter
    // mix
    int  FGameMode;                 // Game Launching, run UT2003.exe ot UCC.exe
    bool FMapSubFolders;            // Process SubFolders
    bool FArchiveSubFolders;        // Process SubFolders
    bool FColArrange;               // arrange coloums, + something else...look into it (main form I think)
    bool FSmartUninstall;           // remove files from logs and uninstall files from archive too
    bool FColorCodeText;
    // events
    TNotifyEvent FOnSettingsChanged;  // ussed to keep the settings uptodate all the time
//----------------------------------------------------------------------------------------------
//  Type                    Method Name           Parm - Type            Name,  Type       Name
    void         __fastcall SetStringValue        (const int                  Index, AnsiString Value);
    void         __fastcall SetIntValue           (const int                  Index, const int  Value);
    void         __fastcall SetBoolValue          (const int                  Index, const bool Value);
    void         __fastcall SetInstallMode        (const TMM_InstallMode      Value);
    void         __fastcall SetSmartBackup        (const TMM_SmartBackup      Value);
    void         __fastcall SetInstallType        (const TMM_InstallType      Value);
    void         __fastcall SetCacheMode          (const TMM_CacheMode        Value);
    void         __fastcall SetGameType           (const TMM_GameType         Value);
    void         __fastcall SetLoadArchivesType   (const TMM_LoadArchivesType Value);

    void         __fastcall GetGameTag            ();
    void         __fastcall OnSettingsChangedEvent(TObject*                   Sender);
    AnsiString   __fastcall GetGameTag            (TMM_GameType               Type);
    AnsiString   __fastcall LoadGameTag           ();
    AnsiString   __fastcall GetSettingsFile       ();
    AnsiString   __fastcall GetGameEXE            ();
    AnsiString   __fastcall GetServerEXE          ();
    TMM_GameType __fastcall LoadGameType          ();
public:
    __fastcall TSettings();
    __fastcall ~TSettings();
    void __fastcall LoadSettings();
    void __fastcall SaveSettings();
__published:
    __property int                  GameMode          = {read=FGameMode,          write=SetIntValue,         index=0, default=0};
    __property bool                 MapSubFolders     = {read=FMapSubFolders,     write=SetBoolValue,        index=0, default=false};
    __property bool                 ArchiveSubFolders = {read=FArchiveSubFolders, write=SetBoolValue,        index=1, default=false};
    __property bool                 ColArrange        = {read=FColArrange,        write=SetBoolValue,        index=2, default=true};
    __property bool                 SmartUninstall    = {read=FSmartUninstall,    write=SetBoolValue,        index=3, default=true};
    __property bool                 ColorCodeText     = {read=FColorCodeText,     write=SetBoolValue,        index=4, default=true};
    __property AnsiString           GameTag           = {read=FGameTag,           write=SetStringValue,      index=0};
    __property AnsiString           GameFolder        = {read=FGameFolder,        write=SetStringValue,      index=1};
    __property AnsiString           ProgramFolder     = {read=FProgramFolder,     write=SetStringValue,      index=2};
    __property AnsiString           MapFolder         = {read=FMapFolder,         write=SetStringValue,      index=3};
    __property AnsiString           CacheFolder       = {read=FCacheFolder,       write=SetStringValue,      index=4};
    __property AnsiString           ArchiveFolder     = {read=FArchiveFolder,     write=SetStringValue,      index=5};
    __property AnsiString           UserFile          = {read=FUserFile,          write=SetStringValue,      index=6};
    __property AnsiString           LogFile           = {read=FLogFile,           write=SetStringValue,      index=7};
    __property AnsiString           PlayGameString    = {read=FPlayGameString,    write=SetStringValue,      index=8};
    __property AnsiString           GameEXE           = {read=FGameEXE,           write=SetStringValue,      index=9};
    __property AnsiString           ServerEXE         = {read=FServerEXE,         write=SetStringValue,      index=10};
    __property AnsiString           MusicFolder       = {read=FMusicFolder,       write=SetStringValue,      index=11};
    __property AnsiString           TextureFolder     = {read=FTextureFolder,     write=SetStringValue,      index=12};
    __property TMM_InstallMode      InstallMode       = {read=FInstallMode,       write=SetInstallMode,      default=MM_IM_Smart};
    __property TMM_SmartBackup      SmartBackup       = {read=FSmartBackup,       write=SetSmartBackup,      default=MM_SB_RenameFile};
    __property TMM_InstallType      InstallType       = {read=FInstallType,       write=SetInstallType,      default=MM_IT_DropFolders};
    __property TMM_CacheMode        CacheMode         = {read=FCacheMode,         write=SetCacheMode,        default=MM_CM_Smart};
    __property TMM_GameType         GameType          = {read=FGameType,          write=SetGameType,         default=MM_GT_NotSpecified};
    __property TMM_LoadArchivesType LoadArchivesType  = {read=FLoadArchivesType,  write=SetLoadArchivesType, default=MM_LAT_None};
    //Event
    __property TNotifyEvent         OnSettingsChanged = {read=FOnSettingsChanged, write=FOnSettingsChanged};
};
#endif
