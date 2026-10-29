//---------------------------------------------------------------------------
#ifndef TypesH
#define TypesH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
/*
struct TMM_FileInfo
{
	int Num, BelongsTo; // these are only used for displaying the logs ;)
	AnsiString FileName, FileSize, FileDate, FileLocation, Installed;
	unsigned long CRC32;
};
*/

/*
struct TMM_FileInfo
{
	int Num, BelongsTo, Installed; // these are only used for displaying the logs ;)
	AnsiString FileName, FileDate, FileLocation;
	unsigned long FileSize;
	unsigned long CRC32;
};
*/

typedef struct
{
	int Num, BelongsTo, Installed; // these are only used for displaying the logs ;)
	AnsiString FileName, FileDate, FileLocation;
	unsigned long FileSize;
	unsigned long CRC32;
}TMM_FileInfo, *PTMM_FileInfo;



// new
struct TMM_MapFileInfo
{
    int Num; // these are only used for displaying the logs ;)
    AnsiString FileName, FileSize, FileDate, FileLocation;
};

struct TMM_ArchiveFileInfo
{
    int Num, BelongsTo; // these are only used for displaying the logs ;)
    AnsiString FileName, FileSize, FileDate, FileLocation, Installed;
    unsigned long CRC32;
};

struct TMM_CacheFileInfo
{
    int Num; // these are only used for displaying the logs ;)
    bool Installed;
    AnsiString FileName, FileSize, FileDate, FileLocation, Folder, RealName;
};

struct TMM_LogFileInfo
{
    int Num; // these are only used for displaying the logs ;)
    AnsiString FileName, FileSize, FileDate, FileLocation, CurrentDate, CurrentSize;
    unsigned long CRC32;
};

struct TMM_ServerInfo
{
    int Num, MaxPlayers, Ping; // these are only used for displaying the logs ;)
    AnsiString IP, Port, QueryPort, ID, ServerName, MapName, GameType;
};
// new




struct TMM_ColInfo
{
    AnsiString Title;
    int Width, Allignment; 
};

struct TMM_FavoriteInfo
{
    AnsiString ServerName;
    int IP, Port, QPort, ServerID;
};

struct TMM_FileIconType
{
    AnsiString Ext;
    int Num;
};

typedef struct
{
    AnsiString FileName, FileSize, FileDate, FileLocation, CFileSize, CFileDate;
    unsigned long CRC32;
}TMM_LogEntryData, *PTMM_LogEntryData;
//---------------------------------------------------------------------------
// forward declarations
class TMMFileList;
//class TFavoriteList;
//---------------------------------------------------------------------------
typedef TMMFileList*      PFileList;  // class no _
typedef TMM_ColInfo*      PColInfo;
typedef TMM_FileInfo*     PFileInfo;
typedef TMM_FavoriteInfo* PFavoriteInfo;


// ----------------------------------------------------------------------------
enum TMM_FilesListType{
                          MM_FLT_Maps,
                          MM_FLT_Archives,
						  MM_FLT_Cache,
						  MM_FLT_Servers,
						  MM_FLT_Favorites,
						  MM_FLT_Logs,
						  MM_FLT_Music,
						  MM_FLT_Textures,
						  MM_FLT_Demos,
						  MM_FLT_ScreenShots,
						  MM_FLT_Buddies,
                      };

enum TMM_ItemTypes{
						  MM_IT_Maps,
                          MM_IT_Archives,
						  MM_IT_Cache,
						  MM_IT_Servers,
						  MM_IT_Favorites,
						  MM_IT_Logs,
						  MM_IT_Music,
						  MM_IT_Textures,
                          MM_IT_Demos,
						  MM_IT_ScreenShots,
                          MM_IT_Buddies,
                      };
enum TMM_GetFileInfoType{
                          MM_GFIT_IMAGE,
                          MM_GFIT_INFO,
                          MM_GFIT_TEXTURES,
                          MM_GFIT_DATA,
                          MM_GFIT_ZIPDATA,
                          MM_GFIT_RARDATA,
                          MM_GFIT_UMODDATA,
                          MM_GFIT_SFXDATA,
                          MM_GFIT_COPY,
                          MM_GFIT_UZ2,
                          MM_GFIT_UZ,
					  };

/*
 enum TMM_GameType{
		MM_GT_Unreal,
		MM_GT_Unreal2,
		MM_GT_Unreal3,
		MM_GT_UnrealTournament,
		MM_GT_UnrealTournament2003,
		MM_GT_UnrealTournament2004,
 };
 */


//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TMMFileListEvent    ) (TObject* Sender, PFileList     pFilesList, TMM_FilesListType plistType);
typedef void __fastcall (__closure *TMMLogListEvent     ) (TObject* Sender, PFileList     FilesList);
typedef void __fastcall (__closure *TMMFavoriteListEvent) (TObject* Sender, PFavoriteInfo FavoritesList);
// ----------------------------------------------------------------------------
typedef void __fastcall (__closure *TMMIntEvent         ) (TObject* Sender, int           Value);
typedef void __fastcall (__closure *TMMListEvent        ) (TObject* Sender, PFileList     List);
typedef void __fastcall (__closure *TMMStrEvent         ) (TObject* Sender, AnsiString    Value);
typedef void __fastcall (__closure *TMMGotInfoEvent     ) (TObject* Sender, PFileList     List);
typedef void __fastcall (__closure *TMMGotPicEvent      ) (TObject* Sender, TPicture*     Picture);
typedef void __fastcall (__closure *TMMLogEvent         ) (TObject* Sender, PFileList     List);
//typedef void __fastcall (__closure *TMMFileDataEvent  ) (TObject* Sender, PFileData     FileData);

typedef void __fastcall (__closure *TMMFileDelEvent     ) (TObject* Sender, AnsiString    DeletedFileName);
typedef void __fastcall (__closure *TMMFilesDelEvent    ) (TObject* Sender, PFileList     List);

typedef void __fastcall (__closure *TMMFileRenEvent     ) (TObject* Sender, AnsiString    OldName,         AnsiString NewName);
typedef void __fastcall (__closure *TMMFilesRenEvent    ) (TObject* Sender);

typedef void __fastcall (__closure *TMMFileInsEvent     ) (TObject* Sender, AnsiString    FileName,        AnsiString ArchiveName);
typedef void __fastcall (__closure *TMMFilesInsEvent    ) (TObject* Sender, PFileList     List,            int        Installed);
typedef void __fastcall (__closure *TMMArchiveInsEvent  ) (TObject* Sender, AnsiString    Archive);

typedef void __fastcall (__closure *TMMSFileUniEvent    ) (TObject* Sender, AnsiString    FileName);
typedef void __fastcall (__closure *TMMFileUniEvent     ) (TObject* Sender, AnsiString    FileName,        AnsiString ArchiveName);
typedef void __fastcall (__closure *TMMFilesUniEvent    ) (TObject* Sender, PFileList     List);
typedef void __fastcall (__closure *TMMArchiveUniEvent  ) (TObject* Sender, AnsiString    Archive);

typedef void __fastcall (__closure *TMM_XMLError_Event) (TObject *Sender, AnsiString ErrorMessage);

typedef void __fastcall (__closure *TMMGotDataListEvent) (TObject* Sender, TStrings*    DataList);
// ----------------------------------------------------------------------------
enum TMM_GameType{
                     MM_GT_NotSpecified,
                     MM_GT_Unreal,
                     MM_GT_UnrealTournament,
                     MM_GT_TheWheelOfTime,
                     MM_GT_KlingonHonorGuard,
                     MM_GT_Rune,
                     MM_GT_Undying,
                     MM_GT_DeusEx,
                     MM_GT_XComEnforcer,
                     MM_GT_DeepSpaceNine,
                     MM_GT_NerfArenaBlast,
                     MM_GT_UnrealTournament2003,
                     MM_GT_ArmyOperations,
                     MM_GT_HarryPotterSorcerersStone,
                     MM_GT_HarryPotterChamberSecrets,
                     MM_GT_Unreal2,
                     MM_GT_SplinterCell
                 };
// ----------------------------------------------------------------------------
enum TMM_LoadFilesType{
                          MM_LFT_None,
                          MM_LFT_Filter,
                          MM_LFT_FileType,
                          MM_LFT_FilterAndFileType,
                          MM_LFT_UserDefined
                      };
// ----------------------------------------------------------------------------
enum TMM_LoadArchivesType{
                          MM_LAT_None,
                          MM_LAT_Validate,
                          MM_LAT_Filter,
                          MM_LAT_ValidateAndFilter
                         };
// ----------------------------------------------------------------------------
enum TMM_InstallMode{
                          MM_IM_None,
                          MM_IM_Smart,
                          MM_IM_Force
                    };
// ----------------------------------------------------------------------------
enum TMM_SmartBackup{
                          MM_SB_DoNothing,  // 0
                          MM_SB_RenameFile  // 1
                    };
// ----------------------------------------------------------------------------
enum TMM_InstallType{
                          MM_IT_KeepFolders, // 0
                          MM_IT_DropFolders, // 1
                          MM_IT_CleaverKeepFolders, //2
                          MM_IT_CleaverDropFolders  //3
                    };
// ----------------------------------------------------------------------------
enum TMM_CacheMode{
                          MM_CM_None,
                          MM_CM_Smart,
                          MM_CM_Force,
                          MM_CM_Remove,
                          MM_CM_SmartAndRemove,
                          MM_CM_ForceAndRemove
                  };
// ----------------------------------------------------------------------------
enum TMM_GameMode{
                          MM_GM_Game,
                          MM_GM_Server
                 };
// ----------------------------------------------------------------------------
enum TMM_StringType{
                          MM_ST_File,
                          MM_ST_Log
                   };
// ----------------------------------------------------------------------------
#endif
