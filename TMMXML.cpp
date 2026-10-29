
// ********************************************************************************************************* //
//                                                                                                         
//                                            XML Data Binding
//                                                                                                         
//         Generated on: 28/11/2004 11:06:33                                                               
//       Generated from: C:\Documents and Settings\arden\Desktop\mm-dev-01-04-2004\Settings\Settings.xml   
//   Settings stored in: C:\Documents and Settings\arden\Desktop\mm-dev-01-04-2004\Settings\Settings.xdb   
//                                                                                                         
// ********************************************************************************************************* //

#include <vcl.h>
#pragma hdrstop

#include "TMMSettings.h"

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
// Global Functions

_di_IXMLGamesType __fastcall GetGames(_di_IXMLDocument Doc)
{
  return (_di_IXMLGamesType) Doc->GetDocBinding("Games", __classid(TXMLGamesType));
};

_di_IXMLGamesType __fastcall GetGames(TXMLDocument *Doc)
{
  _di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetGames(DocIntf);
};

_di_IXMLGamesType __fastcall LoadGames(const WideString FileName)
{
  return (_di_IXMLGamesType) LoadXMLDocument(FileName)->GetDocBinding("Games", __classid(TXMLGamesType));
};

_di_IXMLGamesType __fastcall  NewGames()
{
  return (_di_IXMLGamesType) NewXMLDocument()->GetDocBinding("Games", __classid(TXMLGamesType));
};


// TXMLGamesType 

void __fastcall TXMLGamesType::AfterConstruction(void)
{
  RegisterChildNode(WideString("GameTypes"), __classid(TXMLGameTypesType));
  RegisterChildNode(WideString("GameSettings"), __classid(TXMLGameSettingsType));
  TXMLNode::AfterConstruction();
};

int __fastcall TXMLGamesType::Get_LastGameType()
{
  return TXMLNode::ChildNodes->Nodes[WideString("LastGameType")]->NodeValue;
};

void __fastcall TXMLGamesType::Set_LastGameType(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("LastGameType")]->NodeValue = Value;
};

_di_IXMLGameTypesType __fastcall TXMLGamesType::Get_GameTypes()
{
  return (_di_IXMLGameTypesType) TXMLNode::ChildNodes->Nodes[WideString("GameTypes")];
};

_di_IXMLGameSettingsType __fastcall TXMLGamesType::Get_GameSettings()
{
  return (_di_IXMLGameSettingsType) TXMLNode::ChildNodes->Nodes[WideString("GameSettings")];
};

// TXMLGameTypesType 

void __fastcall TXMLGameTypesType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLGameTypesType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLGameTypesType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLGameTypesType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLItemType 

int __fastcall TXMLItemType::Get_id()
{
  return TXMLNode::AttributeNodes->Nodes[WideString("id")]->NodeValue;
};

void __fastcall TXMLItemType::Set_id(int Value)
{
  TXMLNode::SetAttribute(WideString("id"), Value);
};

// TXMLGameSettingsType 

void __fastcall TXMLGameSettingsType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SettingsItem"), __classid(TXMLSettingsItemType));
  ItemTag = "SettingsItem";
  ItemInterface = __uuidof(IXMLSettingsItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLSettingsItemType __fastcall TXMLGameSettingsType::Get_SettingsItem(int Index)
{
  return (_di_IXMLSettingsItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLSettingsItemType __fastcall TXMLGameSettingsType::Add()
{
  return (_di_IXMLSettingsItemType) AddItem(-1);
};

_di_IXMLSettingsItemType __fastcall TXMLGameSettingsType::Insert(const int Index)
{
  return (_di_IXMLSettingsItemType) AddItem(Index);
};


// TXMLSettingsItemType 

void __fastcall TXMLSettingsItemType::AfterConstruction(void)
{
  RegisterChildNode(WideString("GameData"), __classid(TXMLGameDataType));
  TXMLNode::AfterConstruction();
};

int __fastcall TXMLSettingsItemType::Get_id()
{
  return TXMLNode::AttributeNodes->Nodes[WideString("id")]->NodeValue;
};

void __fastcall TXMLSettingsItemType::Set_id(int Value)
{
  TXMLNode::SetAttribute(WideString("id"), Value);
};

_di_IXMLGameDataType __fastcall TXMLSettingsItemType::Get_GameData()
{
  return (_di_IXMLGameDataType) TXMLNode::ChildNodes->Nodes[WideString("GameData")];
};

// TXMLGameDataType 

void __fastcall TXMLGameDataType::AfterConstruction(void)
{
  RegisterChildNode(WideString("MenuTypes"), __classid(TXMLMenuTypesType));
  RegisterChildNode(WideString("InstallTypes"), __classid(TXMLInstallTypesType));
  RegisterChildNode(WideString("Icons"), __classid(TXMLIconsType));
  RegisterChildNode(WideString("DisplayMenus"), __classid(TXMLDisplayMenusType));
  RegisterChildNode(WideString("Servers"), __classid(TXMLServersType));
  RegisterChildNode(WideString("Tables"), __classid(TXMLTablesType));
  RegisterChildNode(WideString("TablesAlignment"), __classid(TXMLTablesAlignmentType));
  TXMLNode::AfterConstruction();
};

AnsiString __fastcall TXMLGameDataType::Get_ArchiveFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ArchiveFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveFolder")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_ArchiveSubFolders()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveSubFolders")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ArchiveSubFolders(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveSubFolders")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_CacheFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("CacheFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_CacheFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("CacheFolder")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_CacheFile()
{
  return TXMLNode::ChildNodes->Nodes[WideString("CacheFile")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_CacheFile(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("CacheFile")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_CacheMode()
{
  return TXMLNode::ChildNodes->Nodes[WideString("CacheMode")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_CacheMode(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("CacheMode")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_ColArrange()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ColArrange")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ColArrange(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ColArrange")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_ColorCodeText()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ColorCodeText")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ColorCodeText(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ColorCodeText")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_DemoExt()
{
  return TXMLNode::ChildNodes->Nodes[WideString("DemoExt")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_DemoExt(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("DemoExt")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_DemosFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("DemosFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_DemosFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("DemosFolder")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_FilterRequired()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FilterRequired")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_FilterRequired(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FilterRequired")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_GameEXE()
{
  return TXMLNode::ChildNodes->Nodes[WideString("GameEXE")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_GameEXE(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("GameEXE")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_GameFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("GameFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_GameFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("GameFolder")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_GameMode()
{
  return TXMLNode::ChildNodes->Nodes[WideString("GameMode")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_GameMode(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("GameMode")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_GameTag()
{
  return TXMLNode::ChildNodes->Nodes[WideString("GameTag")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_GameTag(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("GameTag")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_InstallMode()
{
  return TXMLNode::ChildNodes->Nodes[WideString("InstallMode")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_InstallMode(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("InstallMode")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_InstallType()
{
  return TXMLNode::ChildNodes->Nodes[WideString("InstallType")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_InstallType(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("InstallType")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_LogFile()
{
  return TXMLNode::ChildNodes->Nodes[WideString("LogFile")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_LogFile(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("LogFile")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_LoadArchivesType()
{
  return TXMLNode::ChildNodes->Nodes[WideString("LoadArchivesType")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_LoadArchivesType(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("LoadArchivesType")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_MapsExt()
{
  return TXMLNode::ChildNodes->Nodes[WideString("MapsExt")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_MapsExt(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("MapsExt")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_ScreenShotExt()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ScreenShotExt")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ScreenShotExt(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ScreenShotExt")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_MapFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("MapFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_MapFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("MapFolder")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_MusicExt()
{
  return TXMLNode::ChildNodes->Nodes[WideString("MusicExt")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_MusicExt(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("MusicExt")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_MusicFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("MusicFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_MusicFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("MusicFolder")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_MapSubFolders()
{
  return TXMLNode::ChildNodes->Nodes[WideString("MapSubFolders")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_MapSubFolders(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("MapSubFolders")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_ProgramFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ProgramFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ProgramFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ProgramFolder")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_PlayGameString()
{
  return TXMLNode::ChildNodes->Nodes[WideString("PlayGameString")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_PlayGameString(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("PlayGameString")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_RegKey()
{
  return TXMLNode::ChildNodes->Nodes[WideString("RegKey")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_RegKey(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("RegKey")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_ScreenShotsFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ScreenShotsFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ScreenShotsFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ScreenShotsFolder")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_ServerEXE()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ServerEXE")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_ServerEXE(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ServerEXE")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_SmartBackup()
{
  return TXMLNode::ChildNodes->Nodes[WideString("SmartBackup")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_SmartBackup(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("SmartBackup")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_SmartGameTypeInstall()
{
  return TXMLNode::ChildNodes->Nodes[WideString("SmartGameTypeInstall")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_SmartGameTypeInstall(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("SmartGameTypeInstall")]->NodeValue = Value;
};

int __fastcall TXMLGameDataType::Get_SmartUninstall()
{
  return TXMLNode::ChildNodes->Nodes[WideString("SmartUninstall")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_SmartUninstall(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("SmartUninstall")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_TexturesExt()
{
  return TXMLNode::ChildNodes->Nodes[WideString("TexturesExt")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_TexturesExt(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("TexturesExt")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_TextureFolder()
{
  return TXMLNode::ChildNodes->Nodes[WideString("TextureFolder")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_TextureFolder(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("TextureFolder")]->NodeValue = Value;
};

AnsiString __fastcall TXMLGameDataType::Get_UserFile()
{
  return TXMLNode::ChildNodes->Nodes[WideString("UserFile")]->NodeValue;
};

void __fastcall TXMLGameDataType::Set_UserFile(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("UserFile")]->NodeValue = Value;
};

_di_IXMLMenuTypesType __fastcall TXMLGameDataType::Get_MenuTypes()
{
  return (_di_IXMLMenuTypesType) TXMLNode::ChildNodes->Nodes[WideString("MenuTypes")];
};

_di_IXMLInstallTypesType __fastcall TXMLGameDataType::Get_InstallTypes()
{
  return (_di_IXMLInstallTypesType) TXMLNode::ChildNodes->Nodes[WideString("InstallTypes")];
};

_di_IXMLIconsType __fastcall TXMLGameDataType::Get_Icons()
{
  return (_di_IXMLIconsType) TXMLNode::ChildNodes->Nodes[WideString("Icons")];
};

_di_IXMLDisplayMenusType __fastcall TXMLGameDataType::Get_DisplayMenus()
{
  return (_di_IXMLDisplayMenusType) TXMLNode::ChildNodes->Nodes[WideString("DisplayMenus")];
};

_di_IXMLServersType __fastcall TXMLGameDataType::Get_Servers()
{
  return (_di_IXMLServersType) TXMLNode::ChildNodes->Nodes[WideString("Servers")];
};

_di_IXMLTablesType __fastcall TXMLGameDataType::Get_Tables()
{
  return (_di_IXMLTablesType) TXMLNode::ChildNodes->Nodes[WideString("Tables")];
};

_di_IXMLTablesAlignmentType __fastcall TXMLGameDataType::Get_TablesAlignment()
{
  return (_di_IXMLTablesAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("TablesAlignment")];
};

// TXMLMenuTypesType 

void __fastcall TXMLMenuTypesType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLMenuTypesType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLMenuTypesType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLMenuTypesType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLInstallTypesType 

void __fastcall TXMLInstallTypesType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLInstallTypesType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLInstallTypesType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLInstallTypesType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLIconsType 

void __fastcall TXMLIconsType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLIconsType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLIconsType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLIconsType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLDisplayMenusType 

void __fastcall TXMLDisplayMenusType::AfterConstruction(void)
{
  RegisterChildNode(WideString("ArchivesMenu"), __classid(TXMLArchivesMenuType));
  RegisterChildNode(WideString("CacheMenu"), __classid(TXMLCacheMenuType));
  RegisterChildNode(WideString("LogsMenu"), __classid(TXMLLogsMenuType));
  RegisterChildNode(WideString("MapsMenu"), __classid(TXMLMapsMenuType));
  RegisterChildNode(WideString("MusicMenu"), __classid(TXMLMusicMenuType));
  TXMLNode::AfterConstruction();
};

_di_IXMLArchivesMenuType __fastcall TXMLDisplayMenusType::Get_ArchivesMenu()
{
  return (_di_IXMLArchivesMenuType) TXMLNode::ChildNodes->Nodes[WideString("ArchivesMenu")];
};

_di_IXMLCacheMenuType __fastcall TXMLDisplayMenusType::Get_CacheMenu()
{
  return (_di_IXMLCacheMenuType) TXMLNode::ChildNodes->Nodes[WideString("CacheMenu")];
};

_di_IXMLLogsMenuType __fastcall TXMLDisplayMenusType::Get_LogsMenu()
{
  return (_di_IXMLLogsMenuType) TXMLNode::ChildNodes->Nodes[WideString("LogsMenu")];
};

_di_IXMLMapsMenuType __fastcall TXMLDisplayMenusType::Get_MapsMenu()
{
  return (_di_IXMLMapsMenuType) TXMLNode::ChildNodes->Nodes[WideString("MapsMenu")];
};

_di_IXMLMusicMenuType __fastcall TXMLDisplayMenusType::Get_MusicMenu()
{
  return (_di_IXMLMusicMenuType) TXMLNode::ChildNodes->Nodes[WideString("MusicMenu")];
};

// TXMLArchivesMenuType 

void __fastcall TXMLArchivesMenuType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SItem"), __classid(TXMLSItemType));
  ItemTag = "SItem";
  ItemInterface = __uuidof(IXMLSItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLSItemType __fastcall TXMLArchivesMenuType::Get_SItem(int Index)
{
  return (_di_IXMLSItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLSItemType __fastcall TXMLArchivesMenuType::Add()
{
  return (_di_IXMLSItemType) AddItem(-1);
};

_di_IXMLSItemType __fastcall TXMLArchivesMenuType::Insert(const int Index)
{
  return (_di_IXMLSItemType) AddItem(Index);
};


// TXMLSItemType 

AnsiString __fastcall TXMLSItemType::Get_id()
{
  return TXMLNode::AttributeNodes->Nodes[WideString("id")]->NodeValue;
};

void __fastcall TXMLSItemType::Set_id(AnsiString Value)
{
  TXMLNode::SetAttribute(WideString("id"), Value);
};

// TXMLCacheMenuType 

void __fastcall TXMLCacheMenuType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SItem"), __classid(TXMLSItemType));
  ItemTag = "SItem";
  ItemInterface = __uuidof(IXMLSItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLSItemType __fastcall TXMLCacheMenuType::Get_SItem(int Index)
{
  return (_di_IXMLSItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLSItemType __fastcall TXMLCacheMenuType::Add()
{
  return (_di_IXMLSItemType) AddItem(-1);
};

_di_IXMLSItemType __fastcall TXMLCacheMenuType::Insert(const int Index)
{
  return (_di_IXMLSItemType) AddItem(Index);
};


// TXMLLogsMenuType 

void __fastcall TXMLLogsMenuType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLLogsMenuType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLLogsMenuType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLLogsMenuType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLMapsMenuType 

void __fastcall TXMLMapsMenuType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SItem"), __classid(TXMLSItemType));
  ItemTag = "SItem";
  ItemInterface = __uuidof(IXMLSItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLSItemType __fastcall TXMLMapsMenuType::Get_SItem(int Index)
{
  return (_di_IXMLSItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLSItemType __fastcall TXMLMapsMenuType::Add()
{
  return (_di_IXMLSItemType) AddItem(-1);
};

_di_IXMLSItemType __fastcall TXMLMapsMenuType::Insert(const int Index)
{
  return (_di_IXMLSItemType) AddItem(Index);
};


// TXMLMusicMenuType 

void __fastcall TXMLMusicMenuType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SItem"), __classid(TXMLSItemType));
  ItemTag = "SItem";
  ItemInterface = __uuidof(IXMLSItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLSItemType __fastcall TXMLMusicMenuType::Get_SItem(int Index)
{
  return (_di_IXMLSItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLSItemType __fastcall TXMLMusicMenuType::Add()
{
  return (_di_IXMLSItemType) AddItem(-1);
};

_di_IXMLSItemType __fastcall TXMLMusicMenuType::Insert(const int Index)
{
  return (_di_IXMLSItemType) AddItem(Index);
};


// TXMLServersType 

void __fastcall TXMLServersType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SItem"), __classid(TXMLSItemType));
  TXMLNode::AfterConstruction();
};

_di_IXMLSItemType __fastcall TXMLServersType::Get_SItem()
{
  return (_di_IXMLSItemType) TXMLNode::ChildNodes->Nodes[WideString("SItem")];
};

// TXMLTablesType 

void __fastcall TXMLTablesType::AfterConstruction(void)
{
  RegisterChildNode(WideString("ArchivesTable"), __classid(TXMLArchivesTableType));
  RegisterChildNode(WideString("ArchivesViewTable"), __classid(TXMLArchivesViewTableType));
  RegisterChildNode(WideString("CacheTable"), __classid(TXMLCacheTableType));
  RegisterChildNode(WideString("FavoritesTable"), __classid(TXMLFavoritesTableType));
  RegisterChildNode(WideString("FindTable"), __classid(TXMLFindTableType));
  RegisterChildNode(WideString("LogsTable"), __classid(TXMLLogsTableType));
  RegisterChildNode(WideString("MapsTable"), __classid(TXMLMapsTableType));
  RegisterChildNode(WideString("InfoTable"), __classid(TXMLInfoTableType));
  RegisterChildNode(WideString("MusicTable"), __classid(TXMLMusicTableType));
  RegisterChildNode(WideString("ServersTable"), __classid(TXMLServersTableType));
  RegisterChildNode(WideString("TexturesTable"), __classid(TXMLTexturesTableType));
  TXMLNode::AfterConstruction();
};

_di_IXMLArchivesTableType __fastcall TXMLTablesType::Get_ArchivesTable()
{
  return (_di_IXMLArchivesTableType) TXMLNode::ChildNodes->Nodes[WideString("ArchivesTable")];
};

_di_IXMLArchivesViewTableType __fastcall TXMLTablesType::Get_ArchivesViewTable()
{
  return (_di_IXMLArchivesViewTableType) TXMLNode::ChildNodes->Nodes[WideString("ArchivesViewTable")];
};

_di_IXMLCacheTableType __fastcall TXMLTablesType::Get_CacheTable()
{
  return (_di_IXMLCacheTableType) TXMLNode::ChildNodes->Nodes[WideString("CacheTable")];
};

_di_IXMLFavoritesTableType __fastcall TXMLTablesType::Get_FavoritesTable()
{
  return (_di_IXMLFavoritesTableType) TXMLNode::ChildNodes->Nodes[WideString("FavoritesTable")];
};

_di_IXMLFindTableType __fastcall TXMLTablesType::Get_FindTable()
{
  return (_di_IXMLFindTableType) TXMLNode::ChildNodes->Nodes[WideString("FindTable")];
};

_di_IXMLLogsTableType __fastcall TXMLTablesType::Get_LogsTable()
{
  return (_di_IXMLLogsTableType) TXMLNode::ChildNodes->Nodes[WideString("LogsTable")];
};

_di_IXMLMapsTableType __fastcall TXMLTablesType::Get_MapsTable()
{
  return (_di_IXMLMapsTableType) TXMLNode::ChildNodes->Nodes[WideString("MapsTable")];
};

_di_IXMLInfoTableType __fastcall TXMLTablesType::Get_InfoTable()
{
  return (_di_IXMLInfoTableType) TXMLNode::ChildNodes->Nodes[WideString("InfoTable")];
};

_di_IXMLMusicTableType __fastcall TXMLTablesType::Get_MusicTable()
{
  return (_di_IXMLMusicTableType) TXMLNode::ChildNodes->Nodes[WideString("MusicTable")];
};

_di_IXMLServersTableType __fastcall TXMLTablesType::Get_ServersTable()
{
  return (_di_IXMLServersTableType) TXMLNode::ChildNodes->Nodes[WideString("ServersTable")];
};

_di_IXMLTexturesTableType __fastcall TXMLTablesType::Get_TexturesTable()
{
  return (_di_IXMLTexturesTableType) TXMLNode::ChildNodes->Nodes[WideString("TexturesTable")];
};

// TXMLArchivesTableType 

void __fastcall TXMLArchivesTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLArchivesTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLArchivesTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLArchivesTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLArchivesViewTableType 

void __fastcall TXMLArchivesViewTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLArchivesViewTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLArchivesViewTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLArchivesViewTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLCacheTableType 

void __fastcall TXMLCacheTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLCacheTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLCacheTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLCacheTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLFavoritesTableType 

void __fastcall TXMLFavoritesTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLFavoritesTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLFavoritesTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLFavoritesTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLFindTableType 

void __fastcall TXMLFindTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLFindTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLFindTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLFindTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLLogsTableType 

void __fastcall TXMLLogsTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLLogsTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLLogsTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLLogsTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLMapsTableType 

void __fastcall TXMLMapsTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLMapsTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLMapsTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLMapsTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLInfoTableType 

void __fastcall TXMLInfoTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLInfoTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLInfoTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLInfoTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLMusicTableType 

void __fastcall TXMLMusicTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLMusicTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLMusicTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLMusicTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLServersTableType 

void __fastcall TXMLServersTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLServersTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLServersTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLServersTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLTexturesTableType 

void __fastcall TXMLTexturesTableType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLTexturesTableType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLTexturesTableType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLTexturesTableType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLTablesAlignmentType 

void __fastcall TXMLTablesAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("ArchivesAlignment"), __classid(TXMLArchivesAlignmentType));
  RegisterChildNode(WideString("ArchivesViewAlignment"), __classid(TXMLArchivesViewAlignmentType));
  RegisterChildNode(WideString("CacheAlignment"), __classid(TXMLCacheAlignmentType));
  RegisterChildNode(WideString("FavoritesAlignment"), __classid(TXMLFavoritesAlignmentType));
  RegisterChildNode(WideString("FindAlignment"), __classid(TXMLFindAlignmentType));
  RegisterChildNode(WideString("LogsAlignment"), __classid(TXMLLogsAlignmentType));
  RegisterChildNode(WideString("MapsAlignment"), __classid(TXMLMapsAlignmentType));
  RegisterChildNode(WideString("InfoAlignment"), __classid(TXMLInfoAlignmentType));
  RegisterChildNode(WideString("MusicAlignment"), __classid(TXMLMusicAlignmentType));
  RegisterChildNode(WideString("ServersAlignment"), __classid(TXMLServersAlignmentType));
  RegisterChildNode(WideString("TexturesAlignment"), __classid(TXMLTexturesAlignmentType));
  TXMLNode::AfterConstruction();
};

_di_IXMLArchivesAlignmentType __fastcall TXMLTablesAlignmentType::Get_ArchivesAlignment()
{
  return (_di_IXMLArchivesAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("ArchivesAlignment")];
};

_di_IXMLArchivesViewAlignmentType __fastcall TXMLTablesAlignmentType::Get_ArchivesViewAlignment()
{
  return (_di_IXMLArchivesViewAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("ArchivesViewAlignment")];
};

_di_IXMLCacheAlignmentType __fastcall TXMLTablesAlignmentType::Get_CacheAlignment()
{
  return (_di_IXMLCacheAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("CacheAlignment")];
};

_di_IXMLFavoritesAlignmentType __fastcall TXMLTablesAlignmentType::Get_FavoritesAlignment()
{
  return (_di_IXMLFavoritesAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("FavoritesAlignment")];
};

_di_IXMLFindAlignmentType __fastcall TXMLTablesAlignmentType::Get_FindAlignment()
{
  return (_di_IXMLFindAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("FindAlignment")];
};

_di_IXMLLogsAlignmentType __fastcall TXMLTablesAlignmentType::Get_LogsAlignment()
{
  return (_di_IXMLLogsAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("LogsAlignment")];
};

_di_IXMLMapsAlignmentType __fastcall TXMLTablesAlignmentType::Get_MapsAlignment()
{
  return (_di_IXMLMapsAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("MapsAlignment")];
};

_di_IXMLInfoAlignmentType __fastcall TXMLTablesAlignmentType::Get_InfoAlignment()
{
  return (_di_IXMLInfoAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("InfoAlignment")];
};

_di_IXMLMusicAlignmentType __fastcall TXMLTablesAlignmentType::Get_MusicAlignment()
{
  return (_di_IXMLMusicAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("MusicAlignment")];
};

_di_IXMLServersAlignmentType __fastcall TXMLTablesAlignmentType::Get_ServersAlignment()
{
  return (_di_IXMLServersAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("ServersAlignment")];
};

_di_IXMLTexturesAlignmentType __fastcall TXMLTablesAlignmentType::Get_TexturesAlignment()
{
  return (_di_IXMLTexturesAlignmentType) TXMLNode::ChildNodes->Nodes[WideString("TexturesAlignment")];
};

// TXMLArchivesAlignmentType 

void __fastcall TXMLArchivesAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLArchivesAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLArchivesAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLArchivesAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLArchivesViewAlignmentType 

void __fastcall TXMLArchivesViewAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLArchivesViewAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLArchivesViewAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLArchivesViewAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLCacheAlignmentType 

void __fastcall TXMLCacheAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLCacheAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLCacheAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLCacheAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLFavoritesAlignmentType 

void __fastcall TXMLFavoritesAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLFavoritesAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLFavoritesAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLFavoritesAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLFindAlignmentType 

void __fastcall TXMLFindAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLFindAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLFindAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLFindAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLLogsAlignmentType 

void __fastcall TXMLLogsAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLLogsAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLLogsAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLLogsAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLMapsAlignmentType 

void __fastcall TXMLMapsAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLMapsAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLMapsAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLMapsAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLInfoAlignmentType 

void __fastcall TXMLInfoAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLInfoAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLInfoAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLInfoAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLMusicAlignmentType 

void __fastcall TXMLMusicAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLMusicAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLMusicAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLMusicAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLServersAlignmentType 

void __fastcall TXMLServersAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLServersAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLServersAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLServersAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};


// TXMLTexturesAlignmentType 

void __fastcall TXMLTexturesAlignmentType::AfterConstruction(void)
{
  RegisterChildNode(WideString("Item"), __classid(TXMLItemType));
  ItemTag = "Item";
  ItemInterface = __uuidof(IXMLItemType);
  TXMLNodeCollection::AfterConstruction();
};

_di_IXMLItemType __fastcall TXMLTexturesAlignmentType::Get_Item(int Index)
{
  return (_di_IXMLItemType) TXMLNodeCollection::List->Nodes[Index];
};

_di_IXMLItemType __fastcall TXMLTexturesAlignmentType::Add()
{
  return (_di_IXMLItemType) AddItem(-1);
};

_di_IXMLItemType __fastcall TXMLTexturesAlignmentType::Insert(const int Index)
{
  return (_di_IXMLItemType) AddItem(Index);
};
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
// Global Functions

_di_IXMLFileLogsType __fastcall GetFileLogs(_di_IXMLDocument Doc)
{
  return (_di_IXMLFileLogsType) Doc->GetDocBinding("FileLogs", __classid(TXMLFileLogsType));
};

_di_IXMLFileLogsType __fastcall GetFileLogs(TXMLDocument *Doc)
{
  _di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetFileLogs(DocIntf);
};

_di_IXMLFileLogsType __fastcall LoadFileLogs(const WideString FileName)
{
  return (_di_IXMLFileLogsType) LoadXMLDocument(FileName)->GetDocBinding("FileLogs", __classid(TXMLFileLogsType));
};

_di_IXMLFileLogsType __fastcall  NewFileLogs()
{
  return (_di_IXMLFileLogsType) NewXMLDocument()->GetDocBinding("FileLogs", __classid(TXMLFileLogsType));
};


// TXMLFileLogsType 

void __fastcall TXMLFileLogsType::AfterConstruction(void)
{
  RegisterChildNode(WideString("LInstall"), __classid(TXMLLInstallType));
  RegisterChildNode(WideString("LRename"), __classid(TXMLLRenameType));
  RegisterChildNode(WideString("LSmartInstall"), __classid(TXMLLSmartInstallType));
  RegisterChildNode(WideString("LSmartBackup"), __classid(TXMLLSmartBackupType));
  RegisterChildNode(WideString("LCache"), __classid(TXMLLCacheType));
  TXMLNode::AfterConstruction();
};

_di_IXMLLInstallType __fastcall TXMLFileLogsType::Get_LInstall()
{
  return (_di_IXMLLInstallType) TXMLNode::ChildNodes->Nodes[WideString("LInstall")];
};

_di_IXMLLRenameType __fastcall TXMLFileLogsType::Get_LRename()
{
  return (_di_IXMLLRenameType) TXMLNode::ChildNodes->Nodes[WideString("LRename")];
};

_di_IXMLLSmartInstallType __fastcall TXMLFileLogsType::Get_LSmartInstall()
{
  return (_di_IXMLLSmartInstallType) TXMLNode::ChildNodes->Nodes[WideString("LSmartInstall")];
};

_di_IXMLLSmartBackupType __fastcall TXMLFileLogsType::Get_LSmartBackup()
{
  return (_di_IXMLLSmartBackupType) TXMLNode::ChildNodes->Nodes[WideString("LSmartBackup")];
};

_di_IXMLLCacheType __fastcall TXMLFileLogsType::Get_LCache()
{
  return (_di_IXMLLCacheType) TXMLNode::ChildNodes->Nodes[WideString("LCache")];
};

// TXMLLInstallType 

void __fastcall TXMLLInstallType::AfterConstruction(void)
{
  RegisterChildNode(WideString("IArchive"), __classid(TXMLIArchiveType));
  TXMLNode::AfterConstruction();
};

_di_IXMLIArchiveType __fastcall TXMLLInstallType::Get_IArchive()
{
  return (_di_IXMLIArchiveType) TXMLNode::ChildNodes->Nodes[WideString("IArchive")];
};

// TXMLIArchiveType

void __fastcall TXMLIArchiveType::AfterConstruction(void)
{
  RegisterChildNode(WideString("IArchiveData"), __classid(TXMLIArchiveDataType));
  RegisterChildNode(WideString("IFileData"), __classid(TXMLIFileDataType));
  TXMLNode::AfterConstruction();
};

_di_IXMLIArchiveDataType __fastcall TXMLIArchiveType::Get_IArchiveData()
{
  return (_di_IXMLIArchiveDataType) TXMLNode::ChildNodes->Nodes[WideString("IArchiveData")];
};

_di_IXMLIFileDataType __fastcall TXMLIArchiveType::Get_IFileData()
{
  return (_di_IXMLIFileDataType) TXMLNode::ChildNodes->Nodes[WideString("IFileData")];
};

// TXMLIArchiveDataType 

int __fastcall TXMLIArchiveDataType::Get_ArchiveCRC()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveCRC")]->NodeValue;
};

void __fastcall TXMLIArchiveDataType::Set_ArchiveCRC(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveCRC")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIArchiveDataType::Get_ArchiveName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveName")]->NodeValue;
};

void __fastcall TXMLIArchiveDataType::Set_ArchiveName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIArchiveDataType::Get_ArchiveSize()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveSize")]->NodeValue;
};

void __fastcall TXMLIArchiveDataType::Set_ArchiveSize(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveSize")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIArchiveDataType::Get_ArchiveDate()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveDate")]->NodeValue;
};

void __fastcall TXMLIArchiveDataType::Set_ArchiveDate(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveDate")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIArchiveDataType::Get_ArchiveLocation()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveLocation")]->NodeValue;
};

void __fastcall TXMLIArchiveDataType::Set_ArchiveLocation(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveLocation")]->NodeValue = Value;
};

// TXMLIFileDataType 

int __fastcall TXMLIFileDataType::Get_FileCRC()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue;
};

void __fastcall TXMLIFileDataType::Set_FileCRC(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIFileDataType::Get_FileName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue;
};

void __fastcall TXMLIFileDataType::Set_FileName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIFileDataType::Get_FileSize()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue;
};

void __fastcall TXMLIFileDataType::Set_FileSize(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIFileDataType::Get_FileDate()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue;
};

void __fastcall TXMLIFileDataType::Set_FileDate(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue = Value;
};

AnsiString __fastcall TXMLIFileDataType::Get_FileLocation()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue;
};

void __fastcall TXMLIFileDataType::Set_FileLocation(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue = Value;
};

// TXMLLRenameType 

void __fastcall TXMLLRenameType::AfterConstruction(void)
{
  RegisterChildNode(WideString("RFileData"), __classid(TXMLRFileDataType));
  TXMLNode::AfterConstruction();
};

_di_IXMLRFileDataType __fastcall TXMLLRenameType::Get_RFileData()
{
  return (_di_IXMLRFileDataType) TXMLNode::ChildNodes->Nodes[WideString("RFileData")];
};

// TXMLRFileDataType 

int __fastcall TXMLRFileDataType::Get_FileCRC()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_FileCRC(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue = Value;
};

AnsiString __fastcall TXMLRFileDataType::Get_OldArchiveName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("OldArchiveName")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_OldArchiveName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("OldArchiveName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLRFileDataType::Get_OldFileName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("OldFileName")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_OldFileName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("OldFileName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLRFileDataType::Get_NewArchiveName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("NewArchiveName")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_NewArchiveName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("NewArchiveName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLRFileDataType::Get_NewFileName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("NewFileName")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_NewFileName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("NewFileName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLRFileDataType::Get_FileSize()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_FileSize(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue = Value;
};

AnsiString __fastcall TXMLRFileDataType::Get_FileDate()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_FileDate(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue = Value;
};

AnsiString __fastcall TXMLRFileDataType::Get_FileLocation()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue;
};

void __fastcall TXMLRFileDataType::Set_FileLocation(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue = Value;
};

// TXMLLSmartInstallType 

void __fastcall TXMLLSmartInstallType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SIFileData"), __classid(TXMLSIFileDataType));
  TXMLNode::AfterConstruction();
};

_di_IXMLSIFileDataType __fastcall TXMLLSmartInstallType::Get_SIFileData()
{
  return (_di_IXMLSIFileDataType) TXMLNode::ChildNodes->Nodes[WideString("SIFileData")];
};

// TXMLSIFileDataType 

int __fastcall TXMLSIFileDataType::Get_FileCRC()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_FileCRC(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSIFileDataType::Get_OldArchiveName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("OldArchiveName")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_OldArchiveName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("OldArchiveName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSIFileDataType::Get_NewArchiveName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("NewArchiveName")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_NewArchiveName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("NewArchiveName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSIFileDataType::Get_FileName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_FileName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSIFileDataType::Get_ArchiveName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveName")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_ArchiveName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSIFileDataType::Get_FileSize()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_FileSize(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSIFileDataType::Get_FileDate()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_FileDate(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSIFileDataType::Get_FileLocation()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue;
};

void __fastcall TXMLSIFileDataType::Set_FileLocation(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue = Value;
};

// TXMLLSmartBackupType 

void __fastcall TXMLLSmartBackupType::AfterConstruction(void)
{
  RegisterChildNode(WideString("SBFileData"), __classid(TXMLSBFileDataType));
  TXMLNode::AfterConstruction();
};

_di_IXMLSBFileDataType __fastcall TXMLLSmartBackupType::Get_SBFileData()
{
  return (_di_IXMLSBFileDataType) TXMLNode::ChildNodes->Nodes[WideString("SBFileData")];
};

// TXMLSBFileDataType 

int __fastcall TXMLSBFileDataType::Get_FileCRC()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue;
};

void __fastcall TXMLSBFileDataType::Set_FileCRC(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSBFileDataType::Get_ArchiveName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("ArchiveName")]->NodeValue;
};

void __fastcall TXMLSBFileDataType::Set_ArchiveName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("ArchiveName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSBFileDataType::Get_FileName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue;
};

void __fastcall TXMLSBFileDataType::Set_FileName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSBFileDataType::Get_FileSize()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue;
};

void __fastcall TXMLSBFileDataType::Set_FileSize(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSBFileDataType::Get_FileDate()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue;
};

void __fastcall TXMLSBFileDataType::Set_FileDate(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue = Value;
};

AnsiString __fastcall TXMLSBFileDataType::Get_FileLocation()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue;
};

void __fastcall TXMLSBFileDataType::Set_FileLocation(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue = Value;
};

// TXMLLCacheType 

void __fastcall TXMLLCacheType::AfterConstruction(void)
{
  RegisterChildNode(WideString("CFileData"), __classid(TXMLCFileDataType));
  TXMLNode::AfterConstruction();
};

_di_IXMLCFileDataType __fastcall TXMLLCacheType::Get_CFileData()
{
  return (_di_IXMLCFileDataType) TXMLNode::ChildNodes->Nodes[WideString("CFileData")];
};

// TXMLCFileDataType 

int __fastcall TXMLCFileDataType::Get_FileCRC()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue;
};

void __fastcall TXMLCFileDataType::Set_FileCRC(int Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileCRC")]->NodeValue = Value;
};

AnsiString __fastcall TXMLCFileDataType::Get_CacheName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("CacheName")]->NodeValue;
};

void __fastcall TXMLCFileDataType::Set_CacheName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("CacheName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLCFileDataType::Get_FileName()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue;
};

void __fastcall TXMLCFileDataType::Set_FileName(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileName")]->NodeValue = Value;
};

AnsiString __fastcall TXMLCFileDataType::Get_FileSize()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue;
};

void __fastcall TXMLCFileDataType::Set_FileSize(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileSize")]->NodeValue = Value;
};

AnsiString __fastcall TXMLCFileDataType::Get_FileDate()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue;
};

void __fastcall TXMLCFileDataType::Set_FileDate(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileDate")]->NodeValue = Value;
};

AnsiString __fastcall TXMLCFileDataType::Get_FileLocation()
{
  return TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue;
};

void __fastcall TXMLCFileDataType::Set_FileLocation(AnsiString Value)
{
  TXMLNode::ChildNodes->Nodes[WideString("FileLocation")]->NodeValue = Value;
};

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

__fastcall TMMXML::TMMXML() : TPersistent()
{
    //Settings = LoadGames("Settings.xml");
}
//---------------------------------------------------------------------------
__fastcall TMMXML::~TMMXML()
{
}
//---------------------------------------------------------------------------
bool __fastcall TMMXML::ArchiveInLogs(AnsiString ArchiveName)
{
    return false;
}
//---------------------------------------------------------------------------
bool __fastcall TMMXML::FileInLogs(AnsiString FileName)
{
    return false;
} 
//---------------------------------------------------------------------------
_di_IXMLDisplayMenusType __fastcall TMMXML::GetDisplayMenu(AnsiString MenuType)
{
    _di_IXMLDisplayMenusType v;
    return v;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TMMXML::GetMenuType(int MenuType)
{
    //TXMLItemType Item = Settings.
    //_di_IXMLItemType MenuItem = NULL;

    return "";
}
//---------------------------------------------------------------------------
_di_IXMLItemType __fastcall TMMXML::GetItem()
{
    _di_IXMLItemType v;
    return v;
}
//---------------------------------------------------------------------------
_di_IXMLItemType __fastcall TMMXML::GetItemAttribute(AnsiString Value)
{
    _di_IXMLItemType v;
    return v;
}
//---------------------------------------------------------------------------
_di_IXMLItemType __fastcall TMMXML::GetItemValue(AnsiString Attribute)
{
    _di_IXMLItemType v;
    return v;
}
//---------------------------------------------------------------------------
