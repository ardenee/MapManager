//---------------------------------------------------------------------------
#ifndef TypesH
#define TypesH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
//#include "Types.h"
struct FileInfo
{
    int Num, BelongsTo; // these are only used for displaying the logs ;)
    AnsiString FileName, FileSize, FileDate, FileLocation, Installed;
    unsigned long CRC32;
};

struct ColInfo
{
    AnsiString Title;
    int Width, Allignment; 
};
struct FavoriteInfo
{
    AnsiString ServerName;
    int IP, Port, QPort, ServerID;
};    
//---------------------------------------------------------------------------
// forward declarations
class TFileList;
class TMMFileList;
//class TFavoriteList;
//---------------------------------------------------------------------------
typedef ColInfo*      PColInfo;
typedef FileInfo*     PFileInfo;
typedef TMMFileList*  PFileList;
typedef FavoriteInfo* PFavoriteInfo;
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TMMFileListEvent    ) (TObject *Sender, PFileList     FilesList);
typedef void __fastcall (__closure *TMMLogListEvent     ) (TObject *Sender, PFileList     FilesList);
typedef void __fastcall (__closure *TMMFavoriteListEvent) (TObject *Sender, PFavoriteInfo FavoritesList);
// ----------------------------------------------------------------------------
typedef void __fastcall (__closure *TMMIntEvent         ) (TObject *Sender, int           Value);
typedef void __fastcall (__closure *TMMListEvent        ) (TObject *Sender, PFileList     List);
typedef void __fastcall (__closure *TMMStrEvent         ) (TObject *Sender, AnsiString    Value);
typedef void __fastcall (__closure *TMMGotInfoEvent     ) (TObject *Sender, PFileList     List);
typedef void __fastcall (__closure *TMMGotPicEvent      ) (TObject *Sender, TPicture*     Picture);
typedef void __fastcall (__closure *TMMLogEvent         ) (TObject *Sender, PFileList     List);
//typedef void __fastcall (__closure *TMMFileDataEvent  ) (TObject *Sender, PFileData     FileData);

typedef void __fastcall (__closure *TMMFileDelEvent     ) (TObject *Sender, AnsiString    DeletedFileName);
typedef void __fastcall (__closure *TMMFilesDelEvent    ) (TObject *Sender, PFileList     List);

typedef void __fastcall (__closure *TMMFileRenEvent     ) (TObject *Sender, AnsiString    OldName,         AnsiString NewName);
typedef void __fastcall (__closure *TMMFilesRenEvent    ) (TObject *Sender);

typedef void __fastcall (__closure *TMMFileInsEvent     ) (TObject *Sender, AnsiString    FileName,        AnsiString ArchiveName);
typedef void __fastcall (__closure *TMMFilesInsEvent    ) (TObject *Sender, PFileList     List,            int        Installed);
typedef void __fastcall (__closure *TMMArchiveInsEvent  ) (TObject *Sender, AnsiString    Archive);

typedef void __fastcall (__closure *TMMSFileUniEvent    ) (TObject *Sender, AnsiString    FileName);
typedef void __fastcall (__closure *TMMFileUniEvent     ) (TObject *Sender, AnsiString    FileName,        AnsiString ArchiveName);
typedef void __fastcall (__closure *TMMFilesUniEvent    ) (TObject *Sender, PFileList     List);
typedef void __fastcall (__closure *TMMArchiveUniEvent  ) (TObject *Sender, AnsiString    Archive);
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
