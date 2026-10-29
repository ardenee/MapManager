
// ********************************************************************************************************* //
//
//                                            XML Data Binding
//
//         Generated on: 28/11/2004 11:06:33
//       Generated from: C:\Documents and Settings\arden\Desktop\mm-dev-01-04-2004\Settings\Settings.xml
//   Settings stored in: C:\Documents and Settings\arden\Desktop\mm-dev-01-04-2004\Settings\Settings.xdb
//
// ********************************************************************************************************* //

#ifndef   TMMXMLH
#define   TMMXMLH

#include <System.hpp>
#include <xmldom.hpp>
#include <XMLDoc.hpp>
#include <XMLIntf.hpp>
#include <XMLNodeImp.h>
#include "MMTypes.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Settings
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Forward Decls

__interface IXMLGamesType;
typedef System::DelphiInterface<IXMLGamesType> _di_IXMLGamesType;
__interface IXMLGameTypesType;
typedef System::DelphiInterface<IXMLGameTypesType> _di_IXMLGameTypesType;
__interface IXMLItemType;
typedef System::DelphiInterface<IXMLItemType> _di_IXMLItemType;
__interface IXMLGameSettingsType;
typedef System::DelphiInterface<IXMLGameSettingsType> _di_IXMLGameSettingsType;
__interface IXMLSettingsItemType;
typedef System::DelphiInterface<IXMLSettingsItemType> _di_IXMLSettingsItemType;
__interface IXMLGameDataType;
typedef System::DelphiInterface<IXMLGameDataType> _di_IXMLGameDataType;
__interface IXMLMenuTypesType;
typedef System::DelphiInterface<IXMLMenuTypesType> _di_IXMLMenuTypesType;
__interface IXMLInstallTypesType;
typedef System::DelphiInterface<IXMLInstallTypesType> _di_IXMLInstallTypesType;
__interface IXMLIconsType;
typedef System::DelphiInterface<IXMLIconsType> _di_IXMLIconsType;
__interface IXMLDisplayMenusType;
typedef System::DelphiInterface<IXMLDisplayMenusType> _di_IXMLDisplayMenusType;
__interface IXMLArchivesMenuType;
typedef System::DelphiInterface<IXMLArchivesMenuType> _di_IXMLArchivesMenuType;
__interface IXMLSItemType;
typedef System::DelphiInterface<IXMLSItemType> _di_IXMLSItemType;
__interface IXMLCacheMenuType;
typedef System::DelphiInterface<IXMLCacheMenuType> _di_IXMLCacheMenuType;
__interface IXMLLogsMenuType;
typedef System::DelphiInterface<IXMLLogsMenuType> _di_IXMLLogsMenuType;
__interface IXMLMapsMenuType;
typedef System::DelphiInterface<IXMLMapsMenuType> _di_IXMLMapsMenuType;
__interface IXMLMusicMenuType;
typedef System::DelphiInterface<IXMLMusicMenuType> _di_IXMLMusicMenuType;
__interface IXMLServersType;
typedef System::DelphiInterface<IXMLServersType> _di_IXMLServersType;
__interface IXMLTablesType;
typedef System::DelphiInterface<IXMLTablesType> _di_IXMLTablesType;
__interface IXMLArchivesTableType;
typedef System::DelphiInterface<IXMLArchivesTableType> _di_IXMLArchivesTableType;
__interface IXMLArchivesViewTableType;
typedef System::DelphiInterface<IXMLArchivesViewTableType> _di_IXMLArchivesViewTableType;
__interface IXMLCacheTableType;
typedef System::DelphiInterface<IXMLCacheTableType> _di_IXMLCacheTableType;
__interface IXMLFavoritesTableType;
typedef System::DelphiInterface<IXMLFavoritesTableType> _di_IXMLFavoritesTableType;
__interface IXMLFindTableType;
typedef System::DelphiInterface<IXMLFindTableType> _di_IXMLFindTableType;
__interface IXMLLogsTableType;
typedef System::DelphiInterface<IXMLLogsTableType> _di_IXMLLogsTableType;
__interface IXMLMapsTableType;
typedef System::DelphiInterface<IXMLMapsTableType> _di_IXMLMapsTableType;
__interface IXMLInfoTableType;
typedef System::DelphiInterface<IXMLInfoTableType> _di_IXMLInfoTableType;
__interface IXMLMusicTableType;
typedef System::DelphiInterface<IXMLMusicTableType> _di_IXMLMusicTableType;
__interface IXMLServersTableType;
typedef System::DelphiInterface<IXMLServersTableType> _di_IXMLServersTableType;
__interface IXMLTexturesTableType;
typedef System::DelphiInterface<IXMLTexturesTableType> _di_IXMLTexturesTableType;
__interface IXMLTablesAlignmentType;
typedef System::DelphiInterface<IXMLTablesAlignmentType> _di_IXMLTablesAlignmentType;
__interface IXMLArchivesAlignmentType;
typedef System::DelphiInterface<IXMLArchivesAlignmentType> _di_IXMLArchivesAlignmentType;
__interface IXMLArchivesViewAlignmentType;
typedef System::DelphiInterface<IXMLArchivesViewAlignmentType> _di_IXMLArchivesViewAlignmentType;
__interface IXMLCacheAlignmentType;
typedef System::DelphiInterface<IXMLCacheAlignmentType> _di_IXMLCacheAlignmentType;
__interface IXMLFavoritesAlignmentType;
typedef System::DelphiInterface<IXMLFavoritesAlignmentType> _di_IXMLFavoritesAlignmentType;
__interface IXMLFindAlignmentType;
typedef System::DelphiInterface<IXMLFindAlignmentType> _di_IXMLFindAlignmentType;
__interface IXMLLogsAlignmentType;
typedef System::DelphiInterface<IXMLLogsAlignmentType> _di_IXMLLogsAlignmentType;
__interface IXMLMapsAlignmentType;
typedef System::DelphiInterface<IXMLMapsAlignmentType> _di_IXMLMapsAlignmentType;
__interface IXMLInfoAlignmentType;
typedef System::DelphiInterface<IXMLInfoAlignmentType> _di_IXMLInfoAlignmentType;
__interface IXMLMusicAlignmentType;
typedef System::DelphiInterface<IXMLMusicAlignmentType> _di_IXMLMusicAlignmentType;
__interface IXMLServersAlignmentType;
typedef System::DelphiInterface<IXMLServersAlignmentType> _di_IXMLServersAlignmentType;
__interface IXMLTexturesAlignmentType;
typedef System::DelphiInterface<IXMLTexturesAlignmentType> _di_IXMLTexturesAlignmentType;

// IXMLGamesType 

__interface INTERFACE_UUID("{03ABC523-BFC4-43CA-BB53-2D7D8DD61BB2}") IXMLGamesType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_LastGameType() = 0;
  virtual _di_IXMLGameTypesType __fastcall Get_GameTypes() = 0;
  virtual _di_IXMLGameSettingsType __fastcall Get_GameSettings() = 0;
  virtual void __fastcall Set_LastGameType(int Value) = 0;
  // Methods & Properties 
  __property int LastGameType = { read=Get_LastGameType, write=Set_LastGameType };
  __property _di_IXMLGameTypesType GameTypes = { read=Get_GameTypes };
  __property _di_IXMLGameSettingsType GameSettings = { read=Get_GameSettings };
};

// IXMLGameTypesType 

__interface INTERFACE_UUID("{3E36F431-5B5A-42B1-A3A9-F14B569D1C97}") IXMLGameTypesType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLItemType 

__interface INTERFACE_UUID("{7C763B08-152B-4AB0-88D6-74C536365A5D}") IXMLItemType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_id() = 0;
  virtual void __fastcall Set_id(int Value) = 0;
  // Methods & Properties 
  __property int id = { read=Get_id, write=Set_id };
};

// IXMLGameSettingsType 

__interface INTERFACE_UUID("{4507F0FD-0E35-4EFD-827A-14266885A148}") IXMLGameSettingsType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLSettingsItemType __fastcall Get_SettingsItem(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLSettingsItemType __fastcall Add() = 0;
  virtual _di_IXMLSettingsItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLSettingsItemType SettingsItem[int Index] = { read=Get_SettingsItem };/* default */
};

// IXMLSettingsItemType 

__interface INTERFACE_UUID("{4F9F348A-09A2-464F-8136-61448DC90212}") IXMLSettingsItemType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_id() = 0;
  virtual _di_IXMLGameDataType __fastcall Get_GameData() = 0;
  virtual void __fastcall Set_id(int Value) = 0;
  // Methods & Properties 
  __property int id = { read=Get_id, write=Set_id };
  __property _di_IXMLGameDataType GameData = { read=Get_GameData };
};

// IXMLGameDataType 

__interface INTERFACE_UUID("{C0EE8D3B-5DF4-4737-9734-29F65DF1EFA5}") IXMLGameDataType : public IXMLNode
{
public:
  // Property Accessors 
  virtual AnsiString __fastcall Get_ArchiveFolder() = 0;
  virtual int __fastcall Get_ArchiveSubFolders() = 0;
  virtual AnsiString __fastcall Get_CacheFolder() = 0;
  virtual AnsiString __fastcall Get_CacheFile() = 0;
  virtual int __fastcall Get_CacheMode() = 0;
  virtual int __fastcall Get_ColArrange() = 0;
  virtual int __fastcall Get_ColorCodeText() = 0;
  virtual AnsiString __fastcall Get_DemoExt() = 0;
  virtual AnsiString __fastcall Get_DemosFolder() = 0;
  virtual int __fastcall Get_FilterRequired() = 0;
  virtual AnsiString __fastcall Get_GameEXE() = 0;
  virtual AnsiString __fastcall Get_GameFolder() = 0;
  virtual int __fastcall Get_GameMode() = 0;
  virtual AnsiString __fastcall Get_GameTag() = 0;
  virtual int __fastcall Get_InstallMode() = 0;
  virtual int __fastcall Get_InstallType() = 0;
  virtual AnsiString __fastcall Get_LogFile() = 0;
  virtual int __fastcall Get_LoadArchivesType() = 0;
  virtual AnsiString __fastcall Get_MapsExt() = 0;
  virtual AnsiString __fastcall Get_ScreenShotExt() = 0;
  virtual AnsiString __fastcall Get_MapFolder() = 0;
  virtual AnsiString __fastcall Get_MusicExt() = 0;
  virtual AnsiString __fastcall Get_MusicFolder() = 0;
  virtual int __fastcall Get_MapSubFolders() = 0;
  virtual AnsiString __fastcall Get_ProgramFolder() = 0;
  virtual AnsiString __fastcall Get_PlayGameString() = 0;
  virtual AnsiString __fastcall Get_RegKey() = 0;
  virtual AnsiString __fastcall Get_ScreenShotsFolder() = 0;
  virtual AnsiString __fastcall Get_ServerEXE() = 0;
  virtual int __fastcall Get_SmartBackup() = 0;
  virtual int __fastcall Get_SmartGameTypeInstall() = 0;
  virtual int __fastcall Get_SmartUninstall() = 0;
  virtual AnsiString __fastcall Get_TexturesExt() = 0;
  virtual AnsiString __fastcall Get_TextureFolder() = 0;
  virtual AnsiString __fastcall Get_UserFile() = 0;
  virtual _di_IXMLMenuTypesType __fastcall Get_MenuTypes() = 0;
  virtual _di_IXMLInstallTypesType __fastcall Get_InstallTypes() = 0;
  virtual _di_IXMLIconsType __fastcall Get_Icons() = 0;
  virtual _di_IXMLDisplayMenusType __fastcall Get_DisplayMenus() = 0;
  virtual _di_IXMLServersType __fastcall Get_Servers() = 0;
  virtual _di_IXMLTablesType __fastcall Get_Tables() = 0;
  virtual _di_IXMLTablesAlignmentType __fastcall Get_TablesAlignment() = 0;
  virtual void __fastcall Set_ArchiveFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_ArchiveSubFolders(int Value) = 0;
  virtual void __fastcall Set_CacheFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_CacheFile(AnsiString Value) = 0;
  virtual void __fastcall Set_CacheMode(int Value) = 0;
  virtual void __fastcall Set_ColArrange(int Value) = 0;
  virtual void __fastcall Set_ColorCodeText(int Value) = 0;
  virtual void __fastcall Set_DemoExt(AnsiString Value) = 0;
  virtual void __fastcall Set_DemosFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_FilterRequired(int Value) = 0;
  virtual void __fastcall Set_GameEXE(AnsiString Value) = 0;
  virtual void __fastcall Set_GameFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_GameMode(int Value) = 0;
  virtual void __fastcall Set_GameTag(AnsiString Value) = 0;
  virtual void __fastcall Set_InstallMode(int Value) = 0;
  virtual void __fastcall Set_InstallType(int Value) = 0;
  virtual void __fastcall Set_LogFile(AnsiString Value) = 0;
  virtual void __fastcall Set_LoadArchivesType(int Value) = 0;
  virtual void __fastcall Set_MapsExt(AnsiString Value) = 0;
  virtual void __fastcall Set_ScreenShotExt(AnsiString Value) = 0;
  virtual void __fastcall Set_MapFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_MusicExt(AnsiString Value) = 0;
  virtual void __fastcall Set_MusicFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_MapSubFolders(int Value) = 0;
  virtual void __fastcall Set_ProgramFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_PlayGameString(AnsiString Value) = 0;
  virtual void __fastcall Set_RegKey(AnsiString Value) = 0;
  virtual void __fastcall Set_ScreenShotsFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_ServerEXE(AnsiString Value) = 0;
  virtual void __fastcall Set_SmartBackup(int Value) = 0;
  virtual void __fastcall Set_SmartGameTypeInstall(int Value) = 0;
  virtual void __fastcall Set_SmartUninstall(int Value) = 0;
  virtual void __fastcall Set_TexturesExt(AnsiString Value) = 0;
  virtual void __fastcall Set_TextureFolder(AnsiString Value) = 0;
  virtual void __fastcall Set_UserFile(AnsiString Value) = 0;
  // Methods & Properties 
  __property AnsiString ArchiveFolder = { read=Get_ArchiveFolder, write=Set_ArchiveFolder };
  __property int ArchiveSubFolders = { read=Get_ArchiveSubFolders, write=Set_ArchiveSubFolders };
  __property AnsiString CacheFolder = { read=Get_CacheFolder, write=Set_CacheFolder };
  __property AnsiString CacheFile = { read=Get_CacheFile, write=Set_CacheFile };
  __property int CacheMode = { read=Get_CacheMode, write=Set_CacheMode };
  __property int ColArrange = { read=Get_ColArrange, write=Set_ColArrange };
  __property int ColorCodeText = { read=Get_ColorCodeText, write=Set_ColorCodeText };
  __property AnsiString DemoExt = { read=Get_DemoExt, write=Set_DemoExt };
  __property AnsiString DemosFolder = { read=Get_DemosFolder, write=Set_DemosFolder };
  __property int FilterRequired = { read=Get_FilterRequired, write=Set_FilterRequired };
  __property AnsiString GameEXE = { read=Get_GameEXE, write=Set_GameEXE };
  __property AnsiString GameFolder = { read=Get_GameFolder, write=Set_GameFolder };
  __property int GameMode = { read=Get_GameMode, write=Set_GameMode };
  __property AnsiString GameTag = { read=Get_GameTag, write=Set_GameTag };
  __property int InstallMode = { read=Get_InstallMode, write=Set_InstallMode };
  __property int InstallType = { read=Get_InstallType, write=Set_InstallType };
  __property AnsiString LogFile = { read=Get_LogFile, write=Set_LogFile };
  __property int LoadArchivesType = { read=Get_LoadArchivesType, write=Set_LoadArchivesType };
  __property AnsiString MapsExt = { read=Get_MapsExt, write=Set_MapsExt };
  __property AnsiString ScreenShotExt = { read=Get_ScreenShotExt, write=Set_ScreenShotExt };
  __property AnsiString MapFolder = { read=Get_MapFolder, write=Set_MapFolder };
  __property AnsiString MusicExt = { read=Get_MusicExt, write=Set_MusicExt };
  __property AnsiString MusicFolder = { read=Get_MusicFolder, write=Set_MusicFolder };
  __property int MapSubFolders = { read=Get_MapSubFolders, write=Set_MapSubFolders };
  __property AnsiString ProgramFolder = { read=Get_ProgramFolder, write=Set_ProgramFolder };
  __property AnsiString PlayGameString = { read=Get_PlayGameString, write=Set_PlayGameString };
  __property AnsiString RegKey = { read=Get_RegKey, write=Set_RegKey };
  __property AnsiString ScreenShotsFolder = { read=Get_ScreenShotsFolder, write=Set_ScreenShotsFolder };
  __property AnsiString ServerEXE = { read=Get_ServerEXE, write=Set_ServerEXE };
  __property int SmartBackup = { read=Get_SmartBackup, write=Set_SmartBackup };
  __property int SmartGameTypeInstall = { read=Get_SmartGameTypeInstall, write=Set_SmartGameTypeInstall };
  __property int SmartUninstall = { read=Get_SmartUninstall, write=Set_SmartUninstall };
  __property AnsiString TexturesExt = { read=Get_TexturesExt, write=Set_TexturesExt };
  __property AnsiString TextureFolder = { read=Get_TextureFolder, write=Set_TextureFolder };
  __property AnsiString UserFile = { read=Get_UserFile, write=Set_UserFile };
  __property _di_IXMLMenuTypesType MenuTypes = { read=Get_MenuTypes };
  __property _di_IXMLInstallTypesType InstallTypes = { read=Get_InstallTypes };
  __property _di_IXMLIconsType Icons = { read=Get_Icons };
  __property _di_IXMLDisplayMenusType DisplayMenus = { read=Get_DisplayMenus };
  __property _di_IXMLServersType Servers = { read=Get_Servers };
  __property _di_IXMLTablesType Tables = { read=Get_Tables };
  __property _di_IXMLTablesAlignmentType TablesAlignment = { read=Get_TablesAlignment };
};

// IXMLMenuTypesType 

__interface INTERFACE_UUID("{7F46A5FF-FF0E-442B-878C-82803A61D21A}") IXMLMenuTypesType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLInstallTypesType 

__interface INTERFACE_UUID("{DDD9F2F6-89BF-4B00-BB7D-56B624055288}") IXMLInstallTypesType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLIconsType 

__interface INTERFACE_UUID("{AF4E54FD-0B03-4FA0-BDCD-2478256CFA5D}") IXMLIconsType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLDisplayMenusType 

__interface INTERFACE_UUID("{761EF402-A02D-4623-89F6-8EAB1803EFDE}") IXMLDisplayMenusType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLArchivesMenuType __fastcall Get_ArchivesMenu() = 0;
  virtual _di_IXMLCacheMenuType __fastcall Get_CacheMenu() = 0;
  virtual _di_IXMLLogsMenuType __fastcall Get_LogsMenu() = 0;
  virtual _di_IXMLMapsMenuType __fastcall Get_MapsMenu() = 0;
  virtual _di_IXMLMusicMenuType __fastcall Get_MusicMenu() = 0;
  // Methods & Properties 
  __property _di_IXMLArchivesMenuType ArchivesMenu = { read=Get_ArchivesMenu };
  __property _di_IXMLCacheMenuType CacheMenu = { read=Get_CacheMenu };
  __property _di_IXMLLogsMenuType LogsMenu = { read=Get_LogsMenu };
  __property _di_IXMLMapsMenuType MapsMenu = { read=Get_MapsMenu };
  __property _di_IXMLMusicMenuType MusicMenu = { read=Get_MusicMenu };
};

// IXMLArchivesMenuType 

__interface INTERFACE_UUID("{6C2409D6-C15E-46D0-B055-1D809C3DB985}") IXMLArchivesMenuType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLSItemType __fastcall Add() = 0;
  virtual _di_IXMLSItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLSItemType SItem[int Index] = { read=Get_SItem };/* default */
};

// IXMLSItemType 

__interface INTERFACE_UUID("{FCC2F8CF-E03C-4838-8A9D-F75740EEA6CF}") IXMLSItemType : public IXMLNode
{
public:
  // Property Accessors 
  virtual AnsiString __fastcall Get_id() = 0;
  virtual void __fastcall Set_id(AnsiString Value) = 0;
  // Methods & Properties 
  __property AnsiString id = { read=Get_id, write=Set_id };
};

// IXMLCacheMenuType 

__interface INTERFACE_UUID("{2459421B-08EA-4E8D-8D77-CFADA2A8970C}") IXMLCacheMenuType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLSItemType __fastcall Add() = 0;
  virtual _di_IXMLSItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLSItemType SItem[int Index] = { read=Get_SItem };/* default */
};

// IXMLLogsMenuType 

__interface INTERFACE_UUID("{F10ECA75-198B-4558-9EEA-B5ABDEC324BB}") IXMLLogsMenuType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLMapsMenuType 

__interface INTERFACE_UUID("{078628C4-E30F-42CA-982A-F7723A911451}") IXMLMapsMenuType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLSItemType __fastcall Add() = 0;
  virtual _di_IXMLSItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLSItemType SItem[int Index] = { read=Get_SItem };/* default */
};

// IXMLMusicMenuType 

__interface INTERFACE_UUID("{03A3BB2C-A287-4FA5-8EF3-022F8E21FF45}") IXMLMusicMenuType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLSItemType __fastcall Add() = 0;
  virtual _di_IXMLSItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLSItemType SItem[int Index] = { read=Get_SItem };/* default */
};

// IXMLServersType 

__interface INTERFACE_UUID("{109B6034-C864-4B14-817A-8F6786CE977B}") IXMLServersType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLSItemType __fastcall Get_SItem() = 0;
  // Methods & Properties 
  __property _di_IXMLSItemType SItem = { read=Get_SItem };
};

// IXMLTablesType 

__interface INTERFACE_UUID("{C0265191-1E8E-443D-A709-68A2490BA7F8}") IXMLTablesType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLArchivesTableType __fastcall Get_ArchivesTable() = 0;
  virtual _di_IXMLArchivesViewTableType __fastcall Get_ArchivesViewTable() = 0;
  virtual _di_IXMLCacheTableType __fastcall Get_CacheTable() = 0;
  virtual _di_IXMLFavoritesTableType __fastcall Get_FavoritesTable() = 0;
  virtual _di_IXMLFindTableType __fastcall Get_FindTable() = 0;
  virtual _di_IXMLLogsTableType __fastcall Get_LogsTable() = 0;
  virtual _di_IXMLMapsTableType __fastcall Get_MapsTable() = 0;
  virtual _di_IXMLInfoTableType __fastcall Get_InfoTable() = 0;
  virtual _di_IXMLMusicTableType __fastcall Get_MusicTable() = 0;
  virtual _di_IXMLServersTableType __fastcall Get_ServersTable() = 0;
  virtual _di_IXMLTexturesTableType __fastcall Get_TexturesTable() = 0;
  // Methods & Properties 
  __property _di_IXMLArchivesTableType ArchivesTable = { read=Get_ArchivesTable };
  __property _di_IXMLArchivesViewTableType ArchivesViewTable = { read=Get_ArchivesViewTable };
  __property _di_IXMLCacheTableType CacheTable = { read=Get_CacheTable };
  __property _di_IXMLFavoritesTableType FavoritesTable = { read=Get_FavoritesTable };
  __property _di_IXMLFindTableType FindTable = { read=Get_FindTable };
  __property _di_IXMLLogsTableType LogsTable = { read=Get_LogsTable };
  __property _di_IXMLMapsTableType MapsTable = { read=Get_MapsTable };
  __property _di_IXMLInfoTableType InfoTable = { read=Get_InfoTable };
  __property _di_IXMLMusicTableType MusicTable = { read=Get_MusicTable };
  __property _di_IXMLServersTableType ServersTable = { read=Get_ServersTable };
  __property _di_IXMLTexturesTableType TexturesTable = { read=Get_TexturesTable };
};

// IXMLArchivesTableType 

__interface INTERFACE_UUID("{1997E171-93A2-4890-9B19-704837625B13}") IXMLArchivesTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLArchivesViewTableType 

__interface INTERFACE_UUID("{303D9976-B56F-41DA-A841-545CB8AB4C09}") IXMLArchivesViewTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLCacheTableType 

__interface INTERFACE_UUID("{A2F10BBF-D0DD-415E-A666-BD3BB984A7E4}") IXMLCacheTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLFavoritesTableType 

__interface INTERFACE_UUID("{20DE0CD4-CD30-4A81-B204-C4C0E178F8C3}") IXMLFavoritesTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLFindTableType 

__interface INTERFACE_UUID("{56606E8B-F0F9-4D9C-B856-E1DE7A771E43}") IXMLFindTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLLogsTableType 

__interface INTERFACE_UUID("{20C1F6E1-44BF-4FDB-B4BF-88143302B1CC}") IXMLLogsTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLMapsTableType 

__interface INTERFACE_UUID("{14DD46FF-6745-4D25-9EFD-39B0C56EEFF3}") IXMLMapsTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLInfoTableType 

__interface INTERFACE_UUID("{F6F50782-70F1-448C-9B8C-FF2D00ADB571}") IXMLInfoTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLMusicTableType 

__interface INTERFACE_UUID("{EE5B67A3-5A71-42DE-8A98-CA7454D24032}") IXMLMusicTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLServersTableType 

__interface INTERFACE_UUID("{C2E37724-6CF1-4864-A9EB-A0D80C0F8C09}") IXMLServersTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLTexturesTableType 

__interface INTERFACE_UUID("{D71A685C-C619-4E4B-8F1C-8ECC43DEBACA}") IXMLTexturesTableType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLTablesAlignmentType 

__interface INTERFACE_UUID("{6D6FF2DF-E9AA-483B-8CD5-2F34549708E1}") IXMLTablesAlignmentType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLArchivesAlignmentType __fastcall Get_ArchivesAlignment() = 0;
  virtual _di_IXMLArchivesViewAlignmentType __fastcall Get_ArchivesViewAlignment() = 0;
  virtual _di_IXMLCacheAlignmentType __fastcall Get_CacheAlignment() = 0;
  virtual _di_IXMLFavoritesAlignmentType __fastcall Get_FavoritesAlignment() = 0;
  virtual _di_IXMLFindAlignmentType __fastcall Get_FindAlignment() = 0;
  virtual _di_IXMLLogsAlignmentType __fastcall Get_LogsAlignment() = 0;
  virtual _di_IXMLMapsAlignmentType __fastcall Get_MapsAlignment() = 0;
  virtual _di_IXMLInfoAlignmentType __fastcall Get_InfoAlignment() = 0;
  virtual _di_IXMLMusicAlignmentType __fastcall Get_MusicAlignment() = 0;
  virtual _di_IXMLServersAlignmentType __fastcall Get_ServersAlignment() = 0;
  virtual _di_IXMLTexturesAlignmentType __fastcall Get_TexturesAlignment() = 0;
  // Methods & Properties 
  __property _di_IXMLArchivesAlignmentType ArchivesAlignment = { read=Get_ArchivesAlignment };
  __property _di_IXMLArchivesViewAlignmentType ArchivesViewAlignment = { read=Get_ArchivesViewAlignment };
  __property _di_IXMLCacheAlignmentType CacheAlignment = { read=Get_CacheAlignment };
  __property _di_IXMLFavoritesAlignmentType FavoritesAlignment = { read=Get_FavoritesAlignment };
  __property _di_IXMLFindAlignmentType FindAlignment = { read=Get_FindAlignment };
  __property _di_IXMLLogsAlignmentType LogsAlignment = { read=Get_LogsAlignment };
  __property _di_IXMLMapsAlignmentType MapsAlignment = { read=Get_MapsAlignment };
  __property _di_IXMLInfoAlignmentType InfoAlignment = { read=Get_InfoAlignment };
  __property _di_IXMLMusicAlignmentType MusicAlignment = { read=Get_MusicAlignment };
  __property _di_IXMLServersAlignmentType ServersAlignment = { read=Get_ServersAlignment };
  __property _di_IXMLTexturesAlignmentType TexturesAlignment = { read=Get_TexturesAlignment };
};

// IXMLArchivesAlignmentType 

__interface INTERFACE_UUID("{02C3268F-A8A0-468A-A8FC-A2E0B0843665}") IXMLArchivesAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLArchivesViewAlignmentType 

__interface INTERFACE_UUID("{9DAC0EDF-4EAB-4AB0-A631-358B7176A2EF}") IXMLArchivesViewAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLCacheAlignmentType 

__interface INTERFACE_UUID("{CF880A37-CCB5-4A9F-AAF2-B2F9A0BAAF37}") IXMLCacheAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLFavoritesAlignmentType 

__interface INTERFACE_UUID("{B417CB80-1929-45AB-B86A-B911F887BACE}") IXMLFavoritesAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLFindAlignmentType 

__interface INTERFACE_UUID("{07A5C698-2EB3-439C-9FC1-71A418248E27}") IXMLFindAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLLogsAlignmentType 

__interface INTERFACE_UUID("{B5CA8216-630A-414D-B545-F8C3221A119E}") IXMLLogsAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLMapsAlignmentType 

__interface INTERFACE_UUID("{78520436-36FB-44F3-B758-C9847C2954A2}") IXMLMapsAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLInfoAlignmentType 

__interface INTERFACE_UUID("{1D4C3AE6-B598-42AD-B670-210C3E2E290F}") IXMLInfoAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLMusicAlignmentType 

__interface INTERFACE_UUID("{57098467-B246-4DE7-BB62-86D8205174AC}") IXMLMusicAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLServersAlignmentType 

__interface INTERFACE_UUID("{BC091933-2262-4721-A2EE-89893F5F3A54}") IXMLServersAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// IXMLTexturesAlignmentType 

__interface INTERFACE_UUID("{E976B40B-6382-4893-90F6-3E595AAF2FAB}") IXMLTexturesAlignmentType : public IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLItemType __fastcall Add() = 0;
  virtual _di_IXMLItemType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLItemType Item[int Index] = { read=Get_Item };/* default */
};

// Forward Decls 

class TXMLGamesType;
class TXMLGameTypesType;
class TXMLItemType;
class TXMLGameSettingsType;
class TXMLSettingsItemType;
class TXMLGameDataType;
class TXMLMenuTypesType;
class TXMLInstallTypesType;
class TXMLIconsType;
class TXMLDisplayMenusType;
class TXMLArchivesMenuType;
class TXMLSItemType;
class TXMLCacheMenuType;
class TXMLLogsMenuType;
class TXMLMapsMenuType;
class TXMLMusicMenuType;
class TXMLServersType;
class TXMLTablesType;
class TXMLArchivesTableType;
class TXMLArchivesViewTableType;
class TXMLCacheTableType;
class TXMLFavoritesTableType;
class TXMLFindTableType;
class TXMLLogsTableType;
class TXMLMapsTableType;
class TXMLInfoTableType;
class TXMLMusicTableType;
class TXMLServersTableType;
class TXMLTexturesTableType;
class TXMLTablesAlignmentType;
class TXMLArchivesAlignmentType;
class TXMLArchivesViewAlignmentType;
class TXMLCacheAlignmentType;
class TXMLFavoritesAlignmentType;
class TXMLFindAlignmentType;
class TXMLLogsAlignmentType;
class TXMLMapsAlignmentType;
class TXMLInfoAlignmentType;
class TXMLMusicAlignmentType;
class TXMLServersAlignmentType;
class TXMLTexturesAlignmentType;

// TXMLGamesType 

class TXMLGamesType : public TXMLNode, public IXMLGamesType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLGamesType 
  virtual int __fastcall Get_LastGameType();
  virtual _di_IXMLGameTypesType __fastcall Get_GameTypes();
  virtual _di_IXMLGameSettingsType __fastcall Get_GameSettings();
  virtual void __fastcall Set_LastGameType(int Value);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLGameTypesType 

class TXMLGameTypesType : public TXMLNodeCollection, public IXMLGameTypesType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLGameTypesType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLItemType 

class TXMLItemType : public TXMLNode, public IXMLItemType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLItemType 
  virtual int __fastcall Get_id();
  virtual void __fastcall Set_id(int Value);
};


// TXMLGameSettingsType 

class TXMLGameSettingsType : public TXMLNodeCollection, public IXMLGameSettingsType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLGameSettingsType 
  virtual _di_IXMLSettingsItemType __fastcall Get_SettingsItem(int Index);
  virtual _di_IXMLSettingsItemType __fastcall Add();
  virtual _di_IXMLSettingsItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLSettingsItemType 

class TXMLSettingsItemType : public TXMLNode, public IXMLSettingsItemType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLSettingsItemType 
  virtual int __fastcall Get_id();
  virtual _di_IXMLGameDataType __fastcall Get_GameData();
  virtual void __fastcall Set_id(int Value);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLGameDataType 

class TXMLGameDataType : public TXMLNode, public IXMLGameDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLGameDataType 
  virtual AnsiString __fastcall Get_ArchiveFolder();
  virtual int __fastcall Get_ArchiveSubFolders();
  virtual AnsiString __fastcall Get_CacheFolder();
  virtual AnsiString __fastcall Get_CacheFile();
  virtual int __fastcall Get_CacheMode();
  virtual int __fastcall Get_ColArrange();
  virtual int __fastcall Get_ColorCodeText();
  virtual AnsiString __fastcall Get_DemoExt();
  virtual AnsiString __fastcall Get_DemosFolder();
  virtual int __fastcall Get_FilterRequired();
  virtual AnsiString __fastcall Get_GameEXE();
  virtual AnsiString __fastcall Get_GameFolder();
  virtual int __fastcall Get_GameMode();
  virtual AnsiString __fastcall Get_GameTag();
  virtual int __fastcall Get_InstallMode();
  virtual int __fastcall Get_InstallType();
  virtual AnsiString __fastcall Get_LogFile();
  virtual int __fastcall Get_LoadArchivesType();
  virtual AnsiString __fastcall Get_MapsExt();
  virtual AnsiString __fastcall Get_ScreenShotExt();
  virtual AnsiString __fastcall Get_MapFolder();
  virtual AnsiString __fastcall Get_MusicExt();
  virtual AnsiString __fastcall Get_MusicFolder();
  virtual int __fastcall Get_MapSubFolders();
  virtual AnsiString __fastcall Get_ProgramFolder();
  virtual AnsiString __fastcall Get_PlayGameString();
  virtual AnsiString __fastcall Get_RegKey();
  virtual AnsiString __fastcall Get_ScreenShotsFolder();
  virtual AnsiString __fastcall Get_ServerEXE();
  virtual int __fastcall Get_SmartBackup();
  virtual int __fastcall Get_SmartGameTypeInstall();
  virtual int __fastcall Get_SmartUninstall();
  virtual AnsiString __fastcall Get_TexturesExt();
  virtual AnsiString __fastcall Get_TextureFolder();
  virtual AnsiString __fastcall Get_UserFile();
  virtual _di_IXMLMenuTypesType __fastcall Get_MenuTypes();
  virtual _di_IXMLInstallTypesType __fastcall Get_InstallTypes();
  virtual _di_IXMLIconsType __fastcall Get_Icons();
  virtual _di_IXMLDisplayMenusType __fastcall Get_DisplayMenus();
  virtual _di_IXMLServersType __fastcall Get_Servers();
  virtual _di_IXMLTablesType __fastcall Get_Tables();
  virtual _di_IXMLTablesAlignmentType __fastcall Get_TablesAlignment();
  virtual void __fastcall Set_ArchiveFolder(AnsiString Value);
  virtual void __fastcall Set_ArchiveSubFolders(int Value);
  virtual void __fastcall Set_CacheFolder(AnsiString Value);
  virtual void __fastcall Set_CacheFile(AnsiString Value);
  virtual void __fastcall Set_CacheMode(int Value);
  virtual void __fastcall Set_ColArrange(int Value);
  virtual void __fastcall Set_ColorCodeText(int Value);
  virtual void __fastcall Set_DemoExt(AnsiString Value);
  virtual void __fastcall Set_DemosFolder(AnsiString Value);
  virtual void __fastcall Set_FilterRequired(int Value);
  virtual void __fastcall Set_GameEXE(AnsiString Value);
  virtual void __fastcall Set_GameFolder(AnsiString Value);
  virtual void __fastcall Set_GameMode(int Value);
  virtual void __fastcall Set_GameTag(AnsiString Value);
  virtual void __fastcall Set_InstallMode(int Value);
  virtual void __fastcall Set_InstallType(int Value);
  virtual void __fastcall Set_LogFile(AnsiString Value);
  virtual void __fastcall Set_LoadArchivesType(int Value);
  virtual void __fastcall Set_MapsExt(AnsiString Value);
  virtual void __fastcall Set_ScreenShotExt(AnsiString Value);
  virtual void __fastcall Set_MapFolder(AnsiString Value);
  virtual void __fastcall Set_MusicExt(AnsiString Value);
  virtual void __fastcall Set_MusicFolder(AnsiString Value);
  virtual void __fastcall Set_MapSubFolders(int Value);
  virtual void __fastcall Set_ProgramFolder(AnsiString Value);
  virtual void __fastcall Set_PlayGameString(AnsiString Value);
  virtual void __fastcall Set_RegKey(AnsiString Value);
  virtual void __fastcall Set_ScreenShotsFolder(AnsiString Value);
  virtual void __fastcall Set_ServerEXE(AnsiString Value);
  virtual void __fastcall Set_SmartBackup(int Value);
  virtual void __fastcall Set_SmartGameTypeInstall(int Value);
  virtual void __fastcall Set_SmartUninstall(int Value);
  virtual void __fastcall Set_TexturesExt(AnsiString Value);
  virtual void __fastcall Set_TextureFolder(AnsiString Value);
  virtual void __fastcall Set_UserFile(AnsiString Value);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLMenuTypesType 

class TXMLMenuTypesType : public TXMLNodeCollection, public IXMLMenuTypesType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLMenuTypesType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLInstallTypesType 

class TXMLInstallTypesType : public TXMLNodeCollection, public IXMLInstallTypesType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLInstallTypesType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLIconsType 

class TXMLIconsType : public TXMLNodeCollection, public IXMLIconsType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLIconsType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLDisplayMenusType 

class TXMLDisplayMenusType : public TXMLNode, public IXMLDisplayMenusType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLDisplayMenusType 
  virtual _di_IXMLArchivesMenuType __fastcall Get_ArchivesMenu();
  virtual _di_IXMLCacheMenuType __fastcall Get_CacheMenu();
  virtual _di_IXMLLogsMenuType __fastcall Get_LogsMenu();
  virtual _di_IXMLMapsMenuType __fastcall Get_MapsMenu();
  virtual _di_IXMLMusicMenuType __fastcall Get_MusicMenu();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLArchivesMenuType 

class TXMLArchivesMenuType : public TXMLNodeCollection, public IXMLArchivesMenuType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLArchivesMenuType 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index);
  virtual _di_IXMLSItemType __fastcall Add();
  virtual _di_IXMLSItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLSItemType 

class TXMLSItemType : public TXMLNode, public IXMLSItemType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLSItemType 
  virtual AnsiString __fastcall Get_id();
  virtual void __fastcall Set_id(AnsiString Value);
};


// TXMLCacheMenuType 

class TXMLCacheMenuType : public TXMLNodeCollection, public IXMLCacheMenuType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLCacheMenuType 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index);
  virtual _di_IXMLSItemType __fastcall Add();
  virtual _di_IXMLSItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLLogsMenuType 

class TXMLLogsMenuType : public TXMLNodeCollection, public IXMLLogsMenuType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLLogsMenuType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLMapsMenuType 

class TXMLMapsMenuType : public TXMLNodeCollection, public IXMLMapsMenuType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLMapsMenuType 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index);
  virtual _di_IXMLSItemType __fastcall Add();
  virtual _di_IXMLSItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLMusicMenuType 

class TXMLMusicMenuType : public TXMLNodeCollection, public IXMLMusicMenuType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLMusicMenuType 
  virtual _di_IXMLSItemType __fastcall Get_SItem(int Index);
  virtual _di_IXMLSItemType __fastcall Add();
  virtual _di_IXMLSItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLServersType 

class TXMLServersType : public TXMLNode, public IXMLServersType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLServersType 
  virtual _di_IXMLSItemType __fastcall Get_SItem();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLTablesType 

class TXMLTablesType : public TXMLNode, public IXMLTablesType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLTablesType 
  virtual _di_IXMLArchivesTableType __fastcall Get_ArchivesTable();
  virtual _di_IXMLArchivesViewTableType __fastcall Get_ArchivesViewTable();
  virtual _di_IXMLCacheTableType __fastcall Get_CacheTable();
  virtual _di_IXMLFavoritesTableType __fastcall Get_FavoritesTable();
  virtual _di_IXMLFindTableType __fastcall Get_FindTable();
  virtual _di_IXMLLogsTableType __fastcall Get_LogsTable();
  virtual _di_IXMLMapsTableType __fastcall Get_MapsTable();
  virtual _di_IXMLInfoTableType __fastcall Get_InfoTable();
  virtual _di_IXMLMusicTableType __fastcall Get_MusicTable();
  virtual _di_IXMLServersTableType __fastcall Get_ServersTable();
  virtual _di_IXMLTexturesTableType __fastcall Get_TexturesTable();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLArchivesTableType 

class TXMLArchivesTableType : public TXMLNodeCollection, public IXMLArchivesTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLArchivesTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLArchivesViewTableType 

class TXMLArchivesViewTableType : public TXMLNodeCollection, public IXMLArchivesViewTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLArchivesViewTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLCacheTableType 

class TXMLCacheTableType : public TXMLNodeCollection, public IXMLCacheTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLCacheTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLFavoritesTableType 

class TXMLFavoritesTableType : public TXMLNodeCollection, public IXMLFavoritesTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLFavoritesTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLFindTableType 

class TXMLFindTableType : public TXMLNodeCollection, public IXMLFindTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLFindTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLLogsTableType 

class TXMLLogsTableType : public TXMLNodeCollection, public IXMLLogsTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLLogsTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLMapsTableType 

class TXMLMapsTableType : public TXMLNodeCollection, public IXMLMapsTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLMapsTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLInfoTableType 

class TXMLInfoTableType : public TXMLNodeCollection, public IXMLInfoTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLInfoTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLMusicTableType 

class TXMLMusicTableType : public TXMLNodeCollection, public IXMLMusicTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLMusicTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLServersTableType 

class TXMLServersTableType : public TXMLNodeCollection, public IXMLServersTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLServersTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLTexturesTableType 

class TXMLTexturesTableType : public TXMLNodeCollection, public IXMLTexturesTableType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLTexturesTableType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLTablesAlignmentType 

class TXMLTablesAlignmentType : public TXMLNode, public IXMLTablesAlignmentType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLTablesAlignmentType 
  virtual _di_IXMLArchivesAlignmentType __fastcall Get_ArchivesAlignment();
  virtual _di_IXMLArchivesViewAlignmentType __fastcall Get_ArchivesViewAlignment();
  virtual _di_IXMLCacheAlignmentType __fastcall Get_CacheAlignment();
  virtual _di_IXMLFavoritesAlignmentType __fastcall Get_FavoritesAlignment();
  virtual _di_IXMLFindAlignmentType __fastcall Get_FindAlignment();
  virtual _di_IXMLLogsAlignmentType __fastcall Get_LogsAlignment();
  virtual _di_IXMLMapsAlignmentType __fastcall Get_MapsAlignment();
  virtual _di_IXMLInfoAlignmentType __fastcall Get_InfoAlignment();
  virtual _di_IXMLMusicAlignmentType __fastcall Get_MusicAlignment();
  virtual _di_IXMLServersAlignmentType __fastcall Get_ServersAlignment();
  virtual _di_IXMLTexturesAlignmentType __fastcall Get_TexturesAlignment();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLArchivesAlignmentType 

class TXMLArchivesAlignmentType : public TXMLNodeCollection, public IXMLArchivesAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLArchivesAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLArchivesViewAlignmentType 

class TXMLArchivesViewAlignmentType : public TXMLNodeCollection, public IXMLArchivesViewAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLArchivesViewAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLCacheAlignmentType 

class TXMLCacheAlignmentType : public TXMLNodeCollection, public IXMLCacheAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLCacheAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLFavoritesAlignmentType 

class TXMLFavoritesAlignmentType : public TXMLNodeCollection, public IXMLFavoritesAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLFavoritesAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLFindAlignmentType 

class TXMLFindAlignmentType : public TXMLNodeCollection, public IXMLFindAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLFindAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLLogsAlignmentType 

class TXMLLogsAlignmentType : public TXMLNodeCollection, public IXMLLogsAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLLogsAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLMapsAlignmentType 

class TXMLMapsAlignmentType : public TXMLNodeCollection, public IXMLMapsAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLMapsAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLInfoAlignmentType 

class TXMLInfoAlignmentType : public TXMLNodeCollection, public IXMLInfoAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLInfoAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLMusicAlignmentType 

class TXMLMusicAlignmentType : public TXMLNodeCollection, public IXMLMusicAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLMusicAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLServersAlignmentType 

class TXMLServersAlignmentType : public TXMLNodeCollection, public IXMLServersAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLServersAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLTexturesAlignmentType 

class TXMLTexturesAlignmentType : public TXMLNodeCollection, public IXMLTexturesAlignmentType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLTexturesAlignmentType 
  virtual _di_IXMLItemType __fastcall Get_Item(int Index);
  virtual _di_IXMLItemType __fastcall Add();
  virtual _di_IXMLItemType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};


// Global Functions 

_di_IXMLGamesType __fastcall GetGames(_di_IXMLDocument Doc);
_di_IXMLGamesType __fastcall GetGames(TXMLDocument *Doc);
_di_IXMLGamesType __fastcall LoadGames(const WideString FileName);
_di_IXMLGamesType __fastcall  NewGames();

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Logs
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Forward Decls

__interface IXMLFileLogsType;
typedef System::DelphiInterface<IXMLFileLogsType> _di_IXMLFileLogsType;
__interface IXMLLInstallType;
typedef System::DelphiInterface<IXMLLInstallType> _di_IXMLLInstallType;
__interface IXMLIArchiveType;
typedef System::DelphiInterface<IXMLIArchiveType> _di_IXMLIArchiveType;
__interface IXMLIArchiveDataType;
typedef System::DelphiInterface<IXMLIArchiveDataType> _di_IXMLIArchiveDataType;
__interface IXMLIFileDataType;
typedef System::DelphiInterface<IXMLIFileDataType> _di_IXMLIFileDataType;
__interface IXMLLRenameType;
typedef System::DelphiInterface<IXMLLRenameType> _di_IXMLLRenameType;
__interface IXMLRFileDataType;
typedef System::DelphiInterface<IXMLRFileDataType> _di_IXMLRFileDataType;
__interface IXMLLSmartInstallType;
typedef System::DelphiInterface<IXMLLSmartInstallType> _di_IXMLLSmartInstallType;
__interface IXMLSIFileDataType;
typedef System::DelphiInterface<IXMLSIFileDataType> _di_IXMLSIFileDataType;
__interface IXMLLSmartBackupType;
typedef System::DelphiInterface<IXMLLSmartBackupType> _di_IXMLLSmartBackupType;
__interface IXMLSBFileDataType;
typedef System::DelphiInterface<IXMLSBFileDataType> _di_IXMLSBFileDataType;
__interface IXMLLCacheType;
typedef System::DelphiInterface<IXMLLCacheType> _di_IXMLLCacheType;
__interface IXMLCFileDataType;
typedef System::DelphiInterface<IXMLCFileDataType> _di_IXMLCFileDataType;

// IXMLFileLogsType 

__interface INTERFACE_UUID("{3F711DCB-E8CA-4BFE-8A8B-0865279BA09B}") IXMLFileLogsType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLLInstallType __fastcall Get_LInstall() = 0;
  virtual _di_IXMLLRenameType __fastcall Get_LRename() = 0;
  virtual _di_IXMLLSmartInstallType __fastcall Get_LSmartInstall() = 0;
  virtual _di_IXMLLSmartBackupType __fastcall Get_LSmartBackup() = 0;
  virtual _di_IXMLLCacheType __fastcall Get_LCache() = 0;
  // Methods & Properties 
  __property _di_IXMLLInstallType LInstall = { read=Get_LInstall };
  __property _di_IXMLLRenameType LRename = { read=Get_LRename };
  __property _di_IXMLLSmartInstallType LSmartInstall = { read=Get_LSmartInstall };
  __property _di_IXMLLSmartBackupType LSmartBackup = { read=Get_LSmartBackup };
  __property _di_IXMLLCacheType LCache = { read=Get_LCache };
};

// IXMLLInstallType 

__interface INTERFACE_UUID("{6D5AEE75-C655-4E8D-839C-CD482A74F35D}") IXMLLInstallType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLIArchiveType __fastcall Get_IArchive() = 0;
  // Methods & Properties 
  __property _di_IXMLIArchiveType IArchive = { read=Get_IArchive };
};

// IXMLIArchiveType

__interface INTERFACE_UUID("{1D742D38-C7AD-4532-A51C-E75234B7859D}") IXMLIArchiveType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLIArchiveDataType __fastcall Get_IArchiveData() = 0;
  virtual _di_IXMLIFileDataType __fastcall Get_IFileData() = 0;
  // Methods & Properties 
  __property _di_IXMLIArchiveDataType IArchiveData = { read=Get_IArchiveData };
  __property _di_IXMLIFileDataType IFileData = { read=Get_IFileData };
};

// IXMLIArchiveDataType 

__interface INTERFACE_UUID("{7F9A6C78-9671-407F-A3AF-95B4A4570F82}") IXMLIArchiveDataType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_ArchiveCRC() = 0;
  virtual AnsiString __fastcall Get_ArchiveName() = 0;
  virtual AnsiString __fastcall Get_ArchiveSize() = 0;
  virtual AnsiString __fastcall Get_ArchiveDate() = 0;
  virtual AnsiString __fastcall Get_ArchiveLocation() = 0;
  virtual void __fastcall Set_ArchiveCRC(int Value) = 0;
  virtual void __fastcall Set_ArchiveName(AnsiString Value) = 0;
  virtual void __fastcall Set_ArchiveSize(AnsiString Value) = 0;
  virtual void __fastcall Set_ArchiveDate(AnsiString Value) = 0;
  virtual void __fastcall Set_ArchiveLocation(AnsiString Value) = 0;
  // Methods & Properties 
  __property int ArchiveCRC = { read=Get_ArchiveCRC, write=Set_ArchiveCRC };
  __property AnsiString ArchiveName = { read=Get_ArchiveName, write=Set_ArchiveName };
  __property AnsiString ArchiveSize = { read=Get_ArchiveSize, write=Set_ArchiveSize };
  __property AnsiString ArchiveDate = { read=Get_ArchiveDate, write=Set_ArchiveDate };
  __property AnsiString ArchiveLocation = { read=Get_ArchiveLocation, write=Set_ArchiveLocation };
};

// IXMLIFileDataType 

__interface INTERFACE_UUID("{6F80E822-7624-4186-9105-A09BF7C6BDF1}") IXMLIFileDataType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_FileCRC() = 0;
  virtual AnsiString __fastcall Get_FileName() = 0;
  virtual AnsiString __fastcall Get_FileSize() = 0;
  virtual AnsiString __fastcall Get_FileDate() = 0;
  virtual AnsiString __fastcall Get_FileLocation() = 0;
  virtual void __fastcall Set_FileCRC(int Value) = 0;
  virtual void __fastcall Set_FileName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileSize(AnsiString Value) = 0;
  virtual void __fastcall Set_FileDate(AnsiString Value) = 0;
  virtual void __fastcall Set_FileLocation(AnsiString Value) = 0;
  // Methods & Properties 
  __property int FileCRC = { read=Get_FileCRC, write=Set_FileCRC };
  __property AnsiString FileName = { read=Get_FileName, write=Set_FileName };
  __property AnsiString FileSize = { read=Get_FileSize, write=Set_FileSize };
  __property AnsiString FileDate = { read=Get_FileDate, write=Set_FileDate };
  __property AnsiString FileLocation = { read=Get_FileLocation, write=Set_FileLocation };
};

// IXMLLRenameType 

__interface INTERFACE_UUID("{3F2400C6-8657-456D-B739-B7536824A547}") IXMLLRenameType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLRFileDataType __fastcall Get_RFileData() = 0;
  // Methods & Properties 
  __property _di_IXMLRFileDataType RFileData = { read=Get_RFileData };
};

// IXMLRFileDataType

__interface INTERFACE_UUID("{534CF828-8EE8-4352-8653-50DDD983364D}") IXMLRFileDataType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_FileCRC() = 0;
  virtual AnsiString __fastcall Get_OldArchiveName() = 0;
  virtual AnsiString __fastcall Get_OldFileName() = 0;
  virtual AnsiString __fastcall Get_NewArchiveName() = 0;
  virtual AnsiString __fastcall Get_NewFileName() = 0;
  virtual AnsiString __fastcall Get_FileSize() = 0;
  virtual AnsiString __fastcall Get_FileDate() = 0;
  virtual AnsiString __fastcall Get_FileLocation() = 0;
  virtual void __fastcall Set_FileCRC(int Value) = 0;
  virtual void __fastcall Set_OldArchiveName(AnsiString Value) = 0;
  virtual void __fastcall Set_OldFileName(AnsiString Value) = 0;
  virtual void __fastcall Set_NewArchiveName(AnsiString Value) = 0;
  virtual void __fastcall Set_NewFileName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileSize(AnsiString Value) = 0;
  virtual void __fastcall Set_FileDate(AnsiString Value) = 0;
  virtual void __fastcall Set_FileLocation(AnsiString Value) = 0;
  // Methods & Properties 
  __property int FileCRC = { read=Get_FileCRC, write=Set_FileCRC };
  __property AnsiString OldArchiveName = { read=Get_OldArchiveName, write=Set_OldArchiveName };
  __property AnsiString OldFileName = { read=Get_OldFileName, write=Set_OldFileName };
  __property AnsiString NewArchiveName = { read=Get_NewArchiveName, write=Set_NewArchiveName };
  __property AnsiString NewFileName = { read=Get_NewFileName, write=Set_NewFileName };
  __property AnsiString FileSize = { read=Get_FileSize, write=Set_FileSize };
  __property AnsiString FileDate = { read=Get_FileDate, write=Set_FileDate };
  __property AnsiString FileLocation = { read=Get_FileLocation, write=Set_FileLocation };
};

// IXMLLSmartInstallType 

__interface INTERFACE_UUID("{EF3332F3-6621-41DB-A4E8-118F95E07803}") IXMLLSmartInstallType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLSIFileDataType __fastcall Get_SIFileData() = 0;
  // Methods & Properties 
  __property _di_IXMLSIFileDataType SIFileData = { read=Get_SIFileData };
};

// IXMLSIFileDataType 

__interface INTERFACE_UUID("{3336B58D-7628-4BF8-B30E-3DA75F40024A}") IXMLSIFileDataType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_FileCRC() = 0;
  virtual AnsiString __fastcall Get_OldArchiveName() = 0;
  virtual AnsiString __fastcall Get_NewArchiveName() = 0;
  virtual AnsiString __fastcall Get_FileName() = 0;
  virtual AnsiString __fastcall Get_ArchiveName() = 0;
  virtual AnsiString __fastcall Get_FileSize() = 0;
  virtual AnsiString __fastcall Get_FileDate() = 0;
  virtual AnsiString __fastcall Get_FileLocation() = 0;
  virtual void __fastcall Set_FileCRC(int Value) = 0;
  virtual void __fastcall Set_OldArchiveName(AnsiString Value) = 0;
  virtual void __fastcall Set_NewArchiveName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileName(AnsiString Value) = 0;
  virtual void __fastcall Set_ArchiveName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileSize(AnsiString Value) = 0;
  virtual void __fastcall Set_FileDate(AnsiString Value) = 0;
  virtual void __fastcall Set_FileLocation(AnsiString Value) = 0;
  // Methods & Properties 
  __property int FileCRC = { read=Get_FileCRC, write=Set_FileCRC };
  __property AnsiString OldArchiveName = { read=Get_OldArchiveName, write=Set_OldArchiveName };
  __property AnsiString NewArchiveName = { read=Get_NewArchiveName, write=Set_NewArchiveName };
  __property AnsiString FileName = { read=Get_FileName, write=Set_FileName };
  __property AnsiString ArchiveName = { read=Get_ArchiveName, write=Set_ArchiveName };
  __property AnsiString FileSize = { read=Get_FileSize, write=Set_FileSize };
  __property AnsiString FileDate = { read=Get_FileDate, write=Set_FileDate };
  __property AnsiString FileLocation = { read=Get_FileLocation, write=Set_FileLocation };
};

// IXMLLSmartBackupType 

__interface INTERFACE_UUID("{24D45FEF-EC7F-41EC-B12E-C0FBD743FD8D}") IXMLLSmartBackupType : public IXMLNode
{
public:
  // Property Accessors 
  virtual _di_IXMLSBFileDataType __fastcall Get_SBFileData() = 0;
  // Methods & Properties
  __property _di_IXMLSBFileDataType SBFileData = { read=Get_SBFileData };
};

// IXMLSBFileDataType 

__interface INTERFACE_UUID("{B22B6FE7-B701-47AD-99A3-7469E132B541}") IXMLSBFileDataType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_FileCRC() = 0;
  virtual AnsiString __fastcall Get_ArchiveName() = 0;
  virtual AnsiString __fastcall Get_FileName() = 0;
  virtual AnsiString __fastcall Get_FileSize() = 0;
  virtual AnsiString __fastcall Get_FileDate() = 0;
  virtual AnsiString __fastcall Get_FileLocation() = 0;
  virtual void __fastcall Set_FileCRC(int Value) = 0;
  virtual void __fastcall Set_ArchiveName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileSize(AnsiString Value) = 0;
  virtual void __fastcall Set_FileDate(AnsiString Value) = 0;
  virtual void __fastcall Set_FileLocation(AnsiString Value) = 0;
  // Methods & Properties 
  __property int FileCRC = { read=Get_FileCRC, write=Set_FileCRC };
  __property AnsiString ArchiveName = { read=Get_ArchiveName, write=Set_ArchiveName };
  __property AnsiString FileName = { read=Get_FileName, write=Set_FileName };
  __property AnsiString FileSize = { read=Get_FileSize, write=Set_FileSize };
  __property AnsiString FileDate = { read=Get_FileDate, write=Set_FileDate };
  __property AnsiString FileLocation = { read=Get_FileLocation, write=Set_FileLocation };
};

// IXMLLCacheType 

__interface INTERFACE_UUID("{6AE39862-D73C-4F0F-AB67-B704E21C26C5}") IXMLLCacheType : public IXMLNode
{
public:
  // Property Accessors
  virtual _di_IXMLCFileDataType __fastcall Get_CFileData() = 0;
  // Methods & Properties 
  __property _di_IXMLCFileDataType CFileData = { read=Get_CFileData };
};

// IXMLCFileDataType 

__interface INTERFACE_UUID("{03CFCDCE-2BEC-4249-9DC6-5D3DB0C93C76}") IXMLCFileDataType : public IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_FileCRC() = 0;
  virtual AnsiString __fastcall Get_CacheName() = 0;
  virtual AnsiString __fastcall Get_FileName() = 0;
  virtual AnsiString __fastcall Get_FileSize() = 0;
  virtual AnsiString __fastcall Get_FileDate() = 0;
  virtual AnsiString __fastcall Get_FileLocation() = 0;
  virtual void __fastcall Set_FileCRC(int Value) = 0;
  virtual void __fastcall Set_CacheName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileName(AnsiString Value) = 0;
  virtual void __fastcall Set_FileSize(AnsiString Value) = 0;
  virtual void __fastcall Set_FileDate(AnsiString Value) = 0;
  virtual void __fastcall Set_FileLocation(AnsiString Value) = 0;
  // Methods & Properties
  __property int FileCRC = { read=Get_FileCRC, write=Set_FileCRC };
  __property AnsiString CacheName = { read=Get_CacheName, write=Set_CacheName };
  __property AnsiString FileName = { read=Get_FileName, write=Set_FileName };
  __property AnsiString FileSize = { read=Get_FileSize, write=Set_FileSize };
  __property AnsiString FileDate = { read=Get_FileDate, write=Set_FileDate };
  __property AnsiString FileLocation = { read=Get_FileLocation, write=Set_FileLocation };
};

// Forward Decls 

class TXMLFileLogsType;
class TXMLLInstallType;
class TXMLIArchiveType;
class TXMLIArchiveDataType;
class TXMLIFileDataType;
class TXMLLRenameType;
class TXMLRFileDataType;
class TXMLLSmartInstallType;
class TXMLSIFileDataType;
class TXMLLSmartBackupType;
class TXMLSBFileDataType;
class TXMLLCacheType;
class TXMLCFileDataType;

// TXMLFileLogsType 

class TXMLFileLogsType : public TXMLNode, public IXMLFileLogsType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLFileLogsType 
  virtual _di_IXMLLInstallType __fastcall Get_LInstall();
  virtual _di_IXMLLRenameType __fastcall Get_LRename();
  virtual _di_IXMLLSmartInstallType __fastcall Get_LSmartInstall();
  virtual _di_IXMLLSmartBackupType __fastcall Get_LSmartBackup();
  virtual _di_IXMLLCacheType __fastcall Get_LCache();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLLInstallType 

class TXMLLInstallType : public TXMLNode, public IXMLLInstallType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLLInstallType
  virtual _di_IXMLIArchiveType __fastcall Get_IArchive();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLIArchiveType 

class TXMLIArchiveType : public TXMLNode, public IXMLIArchiveType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLIArchiveType 
  virtual _di_IXMLIArchiveDataType __fastcall Get_IArchiveData();
  virtual _di_IXMLIFileDataType __fastcall Get_IFileData();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLIArchiveDataType 

class TXMLIArchiveDataType : public TXMLNode, public IXMLIArchiveDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLIArchiveDataType 
  virtual int __fastcall Get_ArchiveCRC();
  virtual AnsiString __fastcall Get_ArchiveName();
  virtual AnsiString __fastcall Get_ArchiveSize();
  virtual AnsiString __fastcall Get_ArchiveDate();
  virtual AnsiString __fastcall Get_ArchiveLocation();
  virtual void __fastcall Set_ArchiveCRC(int Value);
  virtual void __fastcall Set_ArchiveName(AnsiString Value);
  virtual void __fastcall Set_ArchiveSize(AnsiString Value);
  virtual void __fastcall Set_ArchiveDate(AnsiString Value);
  virtual void __fastcall Set_ArchiveLocation(AnsiString Value);
};


// TXMLIFileDataType 

class TXMLIFileDataType : public TXMLNode, public IXMLIFileDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLIFileDataType 
  virtual int __fastcall Get_FileCRC();
  virtual AnsiString __fastcall Get_FileName();
  virtual AnsiString __fastcall Get_FileSize();
  virtual AnsiString __fastcall Get_FileDate();
  virtual AnsiString __fastcall Get_FileLocation();
  virtual void __fastcall Set_FileCRC(int Value);
  virtual void __fastcall Set_FileName(AnsiString Value);
  virtual void __fastcall Set_FileSize(AnsiString Value);
  virtual void __fastcall Set_FileDate(AnsiString Value);
  virtual void __fastcall Set_FileLocation(AnsiString Value);
};


// TXMLLRenameType 

class TXMLLRenameType : public TXMLNode, public IXMLLRenameType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLLRenameType 
  virtual _di_IXMLRFileDataType __fastcall Get_RFileData();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLRFileDataType 

class TXMLRFileDataType : public TXMLNode, public IXMLRFileDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLRFileDataType 
  virtual int __fastcall Get_FileCRC();
  virtual AnsiString __fastcall Get_OldArchiveName();
  virtual AnsiString __fastcall Get_OldFileName();
  virtual AnsiString __fastcall Get_NewArchiveName();
  virtual AnsiString __fastcall Get_NewFileName();
  virtual AnsiString __fastcall Get_FileSize();
  virtual AnsiString __fastcall Get_FileDate();
  virtual AnsiString __fastcall Get_FileLocation();
  virtual void __fastcall Set_FileCRC(int Value);
  virtual void __fastcall Set_OldArchiveName(AnsiString Value);
  virtual void __fastcall Set_OldFileName(AnsiString Value);
  virtual void __fastcall Set_NewArchiveName(AnsiString Value);
  virtual void __fastcall Set_NewFileName(AnsiString Value);
  virtual void __fastcall Set_FileSize(AnsiString Value);
  virtual void __fastcall Set_FileDate(AnsiString Value);
  virtual void __fastcall Set_FileLocation(AnsiString Value);
};


// TXMLLSmartInstallType 

class TXMLLSmartInstallType : public TXMLNode, public IXMLLSmartInstallType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLLSmartInstallType 
  virtual _di_IXMLSIFileDataType __fastcall Get_SIFileData();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLSIFileDataType 

class TXMLSIFileDataType : public TXMLNode, public IXMLSIFileDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLSIFileDataType 
  virtual int __fastcall Get_FileCRC();
  virtual AnsiString __fastcall Get_OldArchiveName();
  virtual AnsiString __fastcall Get_NewArchiveName();
  virtual AnsiString __fastcall Get_FileName();
  virtual AnsiString __fastcall Get_ArchiveName();
  virtual AnsiString __fastcall Get_FileSize();
  virtual AnsiString __fastcall Get_FileDate();
  virtual AnsiString __fastcall Get_FileLocation();
  virtual void __fastcall Set_FileCRC(int Value);
  virtual void __fastcall Set_OldArchiveName(AnsiString Value);
  virtual void __fastcall Set_NewArchiveName(AnsiString Value);
  virtual void __fastcall Set_FileName(AnsiString Value);
  virtual void __fastcall Set_ArchiveName(AnsiString Value);
  virtual void __fastcall Set_FileSize(AnsiString Value);
  virtual void __fastcall Set_FileDate(AnsiString Value);
  virtual void __fastcall Set_FileLocation(AnsiString Value);
};


// TXMLLSmartBackupType 

class TXMLLSmartBackupType : public TXMLNode, public IXMLLSmartBackupType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLLSmartBackupType 
  virtual _di_IXMLSBFileDataType __fastcall Get_SBFileData();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLSBFileDataType 

class TXMLSBFileDataType : public TXMLNode, public IXMLSBFileDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLSBFileDataType 
  virtual int __fastcall Get_FileCRC();
  virtual AnsiString __fastcall Get_ArchiveName();
  virtual AnsiString __fastcall Get_FileName();
  virtual AnsiString __fastcall Get_FileSize();
  virtual AnsiString __fastcall Get_FileDate();
  virtual AnsiString __fastcall Get_FileLocation();
  virtual void __fastcall Set_FileCRC(int Value);
  virtual void __fastcall Set_ArchiveName(AnsiString Value);
  virtual void __fastcall Set_FileName(AnsiString Value);
  virtual void __fastcall Set_FileSize(AnsiString Value);
  virtual void __fastcall Set_FileDate(AnsiString Value);
  virtual void __fastcall Set_FileLocation(AnsiString Value);
};


// TXMLLCacheType 

class TXMLLCacheType : public TXMLNode, public IXMLLCacheType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLLCacheType
  virtual _di_IXMLCFileDataType __fastcall Get_CFileData();
public:
  virtual void __fastcall AfterConstruction(void);
};


// TXMLCFileDataType 

class TXMLCFileDataType : public TXMLNode, public IXMLCFileDataType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLCFileDataType 
  virtual int __fastcall Get_FileCRC();
  virtual AnsiString __fastcall Get_CacheName();
  virtual AnsiString __fastcall Get_FileName();
  virtual AnsiString __fastcall Get_FileSize();
  virtual AnsiString __fastcall Get_FileDate();
  virtual AnsiString __fastcall Get_FileLocation();
  virtual void __fastcall Set_FileCRC(int Value);
  virtual void __fastcall Set_CacheName(AnsiString Value);
  virtual void __fastcall Set_FileName(AnsiString Value);
  virtual void __fastcall Set_FileSize(AnsiString Value);
  virtual void __fastcall Set_FileDate(AnsiString Value);
  virtual void __fastcall Set_FileLocation(AnsiString Value);
};


// Global Functions 

_di_IXMLFileLogsType __fastcall GetFileLogs(_di_IXMLDocument Doc);
_di_IXMLFileLogsType __fastcall GetFileLogs(TXMLDocument *Doc);
_di_IXMLFileLogsType __fastcall LoadFileLogs(const WideString FileName);
_di_IXMLFileLogsType __fastcall  NewFileLogs();


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TMMXML : public TPersistent
{
public:
    __fastcall TMMXML();
    __fastcall ~TMMXML();
    TMM_XMLError_Event FOnXMLError;
    AnsiString __fastcall GetDataFor(AnsiString Value);
    //_di_IXMLArchiveType     __fastcall GetArchive    (AnsiString ArchiveName);
    //_di_IXMLArchiveFileType __fastcall GetArchiveFile(AnsiString ArchiveName);
    //_di_IXMLFileType        __fastcall GetFile       (AnsiString ArchiveName);
    //_di_IXMLFileTypeList    __fastcall GetFile       (AnsiString ArchiveName, AnsiString FileName);
    //_di_IXMLArchiveType     __fastcall FindArchive    (AnsiString ArchiveName);
    //_di_IXMLArchiveFileType __fastcall FindArchiveFile(AnsiString ArchiveName);
    //_di_IXMLFileType        __fastcall FindFile       (AnsiString FileName);
    _di_IXMLDisplayMenusType __fastcall GetDisplayMenu(AnsiString MenuType);
    AnsiString               __fastcall GetMenuType(int MenuType);
    _di_IXMLItemType         __fastcall GetItem();
    _di_IXMLItemType         __fastcall GetItemAttribute(AnsiString Value);
    _di_IXMLItemType         __fastcall GetItemValue(AnsiString Attribute);
    bool       __fastcall ArchiveInLogs  (AnsiString ArchiveName);
    bool       __fastcall FileInLogs     (AnsiString FileName);
__published:
    __property TMM_XMLError_Event OnXMLError = {read=FOnXMLError, write=FOnXMLError};
};
//---------------------------------------------------------------------------
#endif