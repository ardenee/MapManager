//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <FileCtrl.hpp>
#include "SettingsForm.h"
#include "MapManager.h"
#include <IniFiles.hpp>
#include <Registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
    this->GetSettings();
    StatusBar1->SimpleText = "Settings Loaded.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Close1Click(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ToRegistry1Click(TObject *Sender)
{
    //Form1->MapManager1->Files->SaveSettings();
    StatusBar1->SimpleText = "Settings Saved.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::GetSettings()
{  
    Edit1->Text  = Form1->MapManager1->EventManager->XMLSettings->GameFolder;
    Edit2->Text  = Form1->MapManager1->EventManager->XMLSettings->GameEXE;
    Edit3->Text  = Form1->MapManager1->EventManager->XMLSettings->ServerEXE;
    Edit4->Text  = Form1->MapManager1->EventManager->XMLSettings->UserFile;
    Edit5->Text  = Form1->MapManager1->EventManager->XMLSettings->PlayGameString;
    Edit6->Text  = Form1->MapManager1->EventManager->XMLSettings->MapFolder;
    Edit7->Text  = Form1->MapManager1->EventManager->XMLSettings->ArchiveFolder;
    Edit8->Text  = Form1->MapManager1->EventManager->XMLSettings->CacheFolder;
    Edit9->Text  = Form1->MapManager1->EventManager->XMLSettings->DemosFolder;
    Edit10->Text = Form1->MapManager1->EventManager->XMLSettings->ScreenShotsFolder;
    Edit11->Text = Form1->MapManager1->EventManager->XMLSettings->MusicFolder;
    Edit12->Text = Form1->MapManager1->EventManager->XMLSettings->TextureFolder;
    Edit13->Text = Form1->MapManager1->EventManager->XMLSettings->MapsExt;
    Edit14->Text = Form1->MapManager1->EventManager->XMLSettings->LogFile;
    Edit15->Text = Form1->MapManager1->EventManager->XMLSettings->RegKey;
    Edit16->Text = Form1->MapManager1->EventManager->XMLSettings->GameTag;
    Edit17->Text = Form1->MapManager1->EventManager->XMLSettings->CacheFile;
    Edit18->Text = Form1->MapManager1->EventManager->XMLSettings->DemoExt;
    Edit19->Text = Form1->MapManager1->EventManager->XMLSettings->ScreenShotExt;
    Edit20->Text = Form1->MapManager1->EventManager->XMLSettings->MusicExt;
    Edit21->Text = Form1->MapManager1->EventManager->XMLSettings->TexturesExt;

    CheckBox1->Checked = Form1->MapManager1->EventManager->XMLSettings->ColorCodeText;
    CheckBox2->Checked = Form1->MapManager1->EventManager->XMLSettings->ColArrange;
    CheckBox3->Checked = Form1->MapManager1->EventManager->XMLSettings->FilterRequired;
    CheckBox4->Checked = Form1->MapManager1->EventManager->XMLSettings->MapSubFolders;
    CheckBox5->Checked = Form1->MapManager1->EventManager->XMLSettings->ArchiveSubFolders;
    CheckBox9->Checked = Form1->MapManager1->EventManager->XMLSettings->SmartUninstall;
    CheckBox6->Checked = Form1->MapManager1->EventManager->XMLSettings->SmartGameTypeInstall;

    ComboBox1->ItemIndex = (int) Form1->MapManager1->EventManager->XMLSettings->LastGameType;
    ComboBox2->ItemIndex = (int) Form1->MapManager1->EventManager->XMLSettings->GameMode;
    ComboBox3->ItemIndex = (int) Form1->MapManager1->EventManager->XMLSettings->InstallMode;
    ComboBox4->ItemIndex = (int) Form1->MapManager1->EventManager->XMLSettings->InstallType;
    ComboBox5->ItemIndex = (int) Form1->MapManager1->EventManager->XMLSettings->CacheMode;
    ComboBox6->ItemIndex = (int) Form1->MapManager1->EventManager->XMLSettings->SmartBackup;
    ComboBox7->ItemIndex = (int) Form1->MapManager1->EventManager->XMLSettings->LoadArchivesType;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::SetSettings()
{
    // all other settings get saved via on change events ;)
    Form1->MapManager1->EventManager->XMLSettings->GameFolder           = Edit1->Text;
    Form1->MapManager1->EventManager->XMLSettings->GameEXE              = Edit2->Text;
    Form1->MapManager1->EventManager->XMLSettings->ServerEXE            = Edit3->Text;
    Form1->MapManager1->EventManager->XMLSettings->UserFile             = Edit4->Text;
    Form1->MapManager1->EventManager->XMLSettings->PlayGameString       = Edit5->Text;
    Form1->MapManager1->EventManager->XMLSettings->MapFolder            = Edit6->Text;
    Form1->MapManager1->EventManager->XMLSettings->ArchiveFolder        = Edit7->Text;
    Form1->MapManager1->EventManager->XMLSettings->CacheFolder          = Edit8->Text;
    Form1->MapManager1->EventManager->XMLSettings->DemosFolder          = Edit9->Text;
    Form1->MapManager1->EventManager->XMLSettings->ScreenShotsFolder    = Edit10->Text;
    Form1->MapManager1->EventManager->XMLSettings->MusicFolder          = Edit11->Text;
    Form1->MapManager1->EventManager->XMLSettings->TextureFolder        = Edit12->Text;
    Form1->MapManager1->EventManager->XMLSettings->MapsExt              = Edit13->Text;
    Form1->MapManager1->EventManager->XMLSettings->LogFile              = Edit14->Text;
    Form1->MapManager1->EventManager->XMLSettings->RegKey               = Edit15->Text;
    Form1->MapManager1->EventManager->XMLSettings->GameTag              = Edit16->Text;
    Form1->MapManager1->EventManager->XMLSettings->CacheFile            = Edit17->Text;
    Form1->MapManager1->EventManager->XMLSettings->DemoExt              = Edit18->Text;
    Form1->MapManager1->EventManager->XMLSettings->ScreenShotExt        = Edit19->Text;
    Form1->MapManager1->EventManager->XMLSettings->MusicExt             = Edit20->Text;
    Form1->MapManager1->EventManager->XMLSettings->TexturesExt          = Edit21->Text; 
    
    // added for complete saving and loading of settings via file menu
    Form1->MapManager1->EventManager->XMLSettings->ColorCodeText        = CheckBox1->Checked;
    Form1->MapManager1->EventManager->XMLSettings->ColArrange           = CheckBox2->Checked;
    Form1->MapManager1->EventManager->XMLSettings->FilterRequired       = CheckBox3->Checked;
    Form1->MapManager1->EventManager->XMLSettings->MapSubFolders        = CheckBox4->Checked;
    Form1->MapManager1->EventManager->XMLSettings->ArchiveSubFolders    = CheckBox5->Checked;
    Form1->MapManager1->EventManager->XMLSettings->SmartGameTypeInstall = CheckBox6->Checked;
    Form1->MapManager1->EventManager->XMLSettings->SmartUninstall       = CheckBox9->Checked; 

    Form1->MapManager1->EventManager->XMLSettings->LastGameType         = ComboBox1->ItemIndex;
    Form1->MapManager1->EventManager->XMLSettings->GameMode             = (TMM_GameMode)         ComboBox2->ItemIndex;
    Form1->MapManager1->EventManager->XMLSettings->InstallMode          = (TMM_InstallMode)      ComboBox3->ItemIndex;
    Form1->MapManager1->EventManager->XMLSettings->InstallType          = (TMM_InstallType)      ComboBox4->ItemIndex;
    Form1->MapManager1->EventManager->XMLSettings->CacheMode            = (TMM_CacheMode)        ComboBox5->ItemIndex;
    Form1->MapManager1->EventManager->XMLSettings->SmartBackup          = (TMM_SmartBackup)      ComboBox6->ItemIndex;
    Form1->MapManager1->EventManager->XMLSettings->LoadArchivesType     = (TMM_LoadArchivesType) ComboBox7->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
    ShowMessage("You have changed the Game Type.\nAll the setting for that game will now be loaded.");

    // posible breaking here, Get_Item = number not value of the ID  - should be fixed incase xml file doesnt have all game settings
    Form1->MapManager1->EventManager->XMLSettings->GameItem = Form1->MapManager1->EventManager->XMLSettings->GameSettings->Get_SettingsItem(ComboBox1->ItemIndex);

    for(int i=0;i<Form1->MapManager1->EventManager->XMLSettings->GameSettings->Count;i++)
    {
        Form1->MapManager1->EventManager->XMLSettings->GameItem = Form1->MapManager1->EventManager->XMLSettings->GameSettings->Get_SettingsItem(i);

        if(Form1->MapManager1->EventManager->XMLSettings->GameItem->Get_id()==Form1->MapManager1->EventManager->XMLSettings->LastGameType)
            break;
    }

    /*
    Get the Id for the game selected, then compare with loaded GameSettins
    if(GameItem->Get_id()!=LastGameType)
    {
        for(int i=0;i<fGameSettings->Count;i++)
        {
            GameItem = fGameSettings->Get_SettingsItem(i);

            if(GameItem->Get_id()==LastGameType)
                break;
        }

        GameItem = fGameSettings->Get_SettingsItem(0);
    }
    */

    Form1->MapManager1->EventManager->XMLSettings->LastGameType = ComboBox1->ItemIndex;
    Form1->MapManager1->EventManager->XMLSettings->LoadSettings();
    this->GetSettings();
    this->SetSettings();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FromRegistry1Click(TObject *Sender)
{
    //Form1->MapManager1->Files->LoadSettings();
    this->GetSettings();
    StatusBar1->SimpleText = "Settings Loaded.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
    UnicodeString B = Edit1->Text;

	if(SelectDirectory("Select Game Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->GameFolder = IncludeTrailingPathDelimiter(B);
        Edit1->Text = Form1->MapManager1->EventManager->XMLSettings->GameFolder;
        StatusBar1->SimpleText = "Game Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Game Folder was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button5Click(TObject *Sender)
{
	UnicodeString B = Edit6->Text;

    if(SelectDirectory("Select Map Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->MapFolder = IncludeTrailingPathDelimiter(B);
        Edit6->Text = Form1->MapManager1->EventManager->XMLSettings->MapFolder;
        StatusBar1->SimpleText = "Map Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Map Folder was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button4Click(TObject *Sender)
{
	UnicodeString B = Edit7->Text;

    if(SelectDirectory("Select Archive Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->ArchiveFolder = IncludeTrailingPathDelimiter(B);
        Edit7->Text = Form1->MapManager1->EventManager->XMLSettings->ArchiveFolder;
        StatusBar1->SimpleText = "Archive Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Archive Folder was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button7Click(TObject *Sender)
{
	UnicodeString B = Edit8->Text;
    
    if(SelectDirectory("Select Cache Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->CacheFolder = IncludeTrailingPathDelimiter(B);
        Edit8->Text = Form1->MapManager1->EventManager->XMLSettings->CacheFolder;
        StatusBar1->SimpleText = "Cache Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Cache Folder was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
    this->SetSettings();
    Form1->MapManager1->Maps->RefreshSettings();
    Form1->MapManager1->Archives->RefreshSettings();
}
//---------------------------------------------------------------------------  
void __fastcall TForm4::Button2Click(TObject *Sender)
{
    OpenDialog1->Options.Clear();
    OpenDialog1->Options << ofFileMustExist;
    OpenDialog1->Title       = "Load Game EXE";
    OpenDialog1->Filter      = "Applications (*.exe)|*.exe";
    OpenDialog1->FilterIndex = 0;
    OpenDialog1->DefaultExt  = "EXE";
    //OpenDialog1->FileName    = ExtractFileName(Form1->MapManager1->Files->GameEXE);

    if(OpenDialog1->Execute())
    {
        Form1->MapManager1->EventManager->XMLSettings->GameEXE = OpenDialog1->FileName;
        Edit2->Text = Form1->MapManager1->EventManager->XMLSettings->GameEXE;
        StatusBar1->SimpleText = "Game EXE Changed.";
    }
    else
        StatusBar1->SimpleText = "Game EXE was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender)
{
    OpenDialog1->Options.Clear();
    OpenDialog1->Options << ofFileMustExist;
    OpenDialog1->Title       = "Load Server EXE";
    OpenDialog1->Filter      = "Applications (*.exe)|*.exe";
    OpenDialog1->FilterIndex = 0;
    OpenDialog1->DefaultExt  = "EXE";
    //OpenDialog1->FileName    = ExtractFileName(Form1->MapManager1->Files->ServerEXE);

    if(OpenDialog1->Execute())
    {
        Form1->MapManager1->EventManager->XMLSettings->ServerEXE = OpenDialog1->FileName;
        Edit3->Text = Form1->MapManager1->EventManager->XMLSettings->ServerEXE;
        StatusBar1->SimpleText = "Server EXE Changed.";
    }
    else
        StatusBar1->SimpleText = "Server EXE was not Changed.";
}
//--------------------------------------------------------------------------- 
void __fastcall TForm4::Button8Click(TObject *Sender)
{
    OpenDialog1->Options.Clear();
    OpenDialog1->Options << ofFileMustExist;
    OpenDialog1->Title       = "Load User File";
    OpenDialog1->Filter      = "INI File (*.ini)|*.ini";
    OpenDialog1->FilterIndex = 0;
    OpenDialog1->DefaultExt  = "INI";
    //OpenDialog1->FileName    = ExtractFileName(Form1->MapManager1->Files->UserFile);

    if(OpenDialog1->Execute())
    {
        Form1->MapManager1->EventManager->XMLSettings->UserFile = OpenDialog1->FileName;
        Edit4->Text = Form1->MapManager1->EventManager->XMLSettings->UserFile;
        StatusBar1->SimpleText = "User File Changed.";
    }
    else
        StatusBar1->SimpleText = "User File was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::CheckBox1Click(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->ColorCodeText = CheckBox1->Checked;
    StatusBar1->SimpleText = "Color Code Text Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::CheckBox2Click(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->ColArrange = CheckBox2->Checked;
    StatusBar1->SimpleText = "Colume Arrange Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ComboBox2Change(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->GameMode = ComboBox2->ItemIndex;
    StatusBar1->SimpleText = "Game Mode Changed.";
}
//--------------------------------------------------------------------------- 
void __fastcall TForm4::CheckBox4Click(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->MapSubFolders = CheckBox4->Checked;
    StatusBar1->SimpleText = "Map SubFolders Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ComboBox3Change(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->InstallMode = (TMM_InstallMode) ComboBox3->ItemIndex;
    StatusBar1->SimpleText = "Install Mode Changed.";
}
//---------------------------------------------------------------------------  
void __fastcall TForm4::ComboBox6Change(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->CacheMode = (TMM_CacheMode) ComboBox6->ItemIndex;
    StatusBar1->SimpleText = "Smart Backup Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ComboBox7Change(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->LoadArchivesType = (TMM_LoadArchivesType) ComboBox7->ItemIndex;
    StatusBar1->SimpleText = "Load Archives Type Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ComboBox4Change(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->InstallType = (TMM_InstallType) ComboBox4->ItemIndex;
    StatusBar1->SimpleText = "Install Type Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::CheckBox5Click(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->ArchiveSubFolders = CheckBox5->Checked;
    StatusBar1->SimpleText = "Archive SubFolders Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::CheckBox9Click(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->SmartUninstall = CheckBox9->Checked;
    StatusBar1->SimpleText = "Smart Uninstall Changed.";
}
//---------------------------------------------------------------------------   
void __fastcall TForm4::ComboBox5Change(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->CacheMode = (TMM_CacheMode) ComboBox5->ItemIndex;
    StatusBar1->SimpleText = "Cache Mode Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FromFile1Click(TObject *Sender)
{
    GetSettings();
    /*
    OpenDialog1->Options.Clear();
    OpenDialog1->Options << ofFileMustExist;
    OpenDialog1->Title       = "Load Settings File";
    OpenDialog1->Filter      = "INI File (*.ini)|*.ini|Text File (*.txt)|*.txt";
    OpenDialog1->FilterIndex = 0;
    OpenDialog1->DefaultExt  = "INI";
    OpenDialog1->FileName    = "Settings";
    */

    /*
    if(OpenDialog1->Execute())
    {
        TIniFile *pIniFile = new TIniFile(OpenDialog1->FileName);
        AnsiString FileSection = Form1->MapManager1->Files->GameTag + "-Settings"; 
        Form1->MapManager1->Files->GameFolder        = pIniFile->ReadString(FileSection,  "GameFolder",        Form1->MapManager1->Files->GameFolder);
        Form1->MapManager1->Files->GameEXE           = pIniFile->ReadString(FileSection,  "GameEXE",           Form1->MapManager1->Files->GameEXE);
        Form1->MapManager1->Files->ServerEXE         = pIniFile->ReadString(FileSection,  "ServerEXE",         Form1->MapManager1->Files->ServerEXE);
        Form1->MapManager1->Files->UserFile          = pIniFile->ReadString(FileSection,  "UserFile",          Form1->MapManager1->Files->UserFile);
        Form1->MapManager1->Files->PlayGameString    = pIniFile->ReadString(FileSection,  "PlayGameString",    Form1->MapManager1->Files->PlayGameString);
        Form1->MapManager1->Files->MapFolder         = pIniFile->ReadString(FileSection,  "MapFolder",         Form1->MapManager1->Files->MapFolder);
        Form1->MapManager1->Files->ArchiveFolder     = pIniFile->ReadString(FileSection,  "ArchiveFolder",     Form1->MapManager1->Files->ArchiveFolder);
        Form1->MapManager1->Files->CacheFolder       = pIniFile->ReadString(FileSection,  "CacheFolder",       Form1->MapManager1->Files->CacheFolder);
        Form1->MapManager1->Files->GameType          = (TMM_GameType)         pIniFile->ReadInteger(FileSection, "GameType",          Form1->MapManager1->Files->GameType);
        Form1->MapManager1->Files->GameMode          = (TMM_GameMode)         pIniFile->ReadInteger(FileSection, "GameMode",          Form1->MapManager1->Files->GameMode);
        Form1->MapManager1->Files->InstallMode       = (TMM_InstallMode)      pIniFile->ReadInteger(FileSection, "InstallMode",       Form1->MapManager1->Files->InstallMode);
        Form1->MapManager1->Files->InstallType       = (TMM_InstallType)      pIniFile->ReadInteger(FileSection, "InstallType",       Form1->MapManager1->Files->InstallType);
        Form1->MapManager1->Files->SmartBackup       = (TMM_SmartBackup)      pIniFile->ReadInteger(FileSection, "SmartBackup",       Form1->MapManager1->Files->SmartBackup);
        Form1->MapManager1->Files->LoadArchivesType  = (TMM_LoadArchivesType) pIniFile->ReadInteger(FileSection, "LoadArchivesType",  Form1->MapManager1->Files->LoadArchivesType);
        Form1->MapManager1->Files->CacheMode         = (TMM_CacheMode)        pIniFile->ReadInteger(FileSection, "CacheMode",         Form1->MapManager1->Files->CacheMode);
        Form1->MapManager1->Files->ColorCodeText     = pIniFile->ReadBool(FileSection,    "CacheMode",         Form1->MapManager1->Files->ColorCodeText);
        Form1->MapManager1->Files->ColArrange        = pIniFile->ReadBool(FileSection,    "ColArrange",        Form1->MapManager1->Files->ColArrange);
        Form1->MapManager1->Files->MapSubFolders     = pIniFile->ReadBool(FileSection,    "MapSubFolders",     Form1->MapManager1->Files->MapSubFolders);
        Form1->MapManager1->Files->ArchiveSubFolders = pIniFile->ReadBool(FileSection,    "ArchiveSubFolders", Form1->MapManager1->Files->ArchiveSubFolders);
        Form1->MapManager1->Files->SmartUninstall    = pIniFile->ReadBool(FileSection,    "SmartUninstall",    Form1->MapManager1->Files->SmartUninstall);
        delete pIniFile;
        this->GetSettings();
        StatusBar1->SimpleText = "Settings Loaded.";
    }
    else
        StatusBar1->SimpleText = "Settings not Loaded.";
        */
}
//---------------------------------------------------------------------------  
void __fastcall TForm4::ToFile1Click(TObject *Sender)
{
    SetSettings();
    /*

    SaveDialog1->Options.Clear();
    SaveDialog1->Options << ofOverwritePrompt << ofPathMustExist;
    SaveDialog1->Title       = "Save Settings File";
    SaveDialog1->Filter      = "INI File (*.ini)|*.ini|Text File (*.txt)|*.txt";
    SaveDialog1->FilterIndex = 0;
    SaveDialog1->DefaultExt  = "INI";
    SaveDialog1->FileName    = "Settings";
    */

    /*
    if(SaveDialog1->Execute())
    {
        TIniFile *pIniFile = new TIniFile(SaveDialog1->FileName);
        AnsiString FileSection = Form1->MapManager1->Files->GameTag + "-Settings";
        pIniFile->WriteString(FileSection,  "GameFolder",        Form1->MapManager1->Files->GameFolder);
        pIniFile->WriteString(FileSection,  "GameEXE",           Form1->MapManager1->Files->GameEXE);
        pIniFile->WriteString(FileSection,  "ServerEXE",         Form1->MapManager1->Files->ServerEXE);
        pIniFile->WriteString(FileSection,  "UserFile",          Form1->MapManager1->Files->UserFile);
        pIniFile->WriteString(FileSection,  "PlayGameString",    Form1->MapManager1->Files->PlayGameString);
        pIniFile->WriteString(FileSection,  "MapFolder",         Form1->MapManager1->Files->MapFolder);
        pIniFile->WriteString(FileSection,  "ArchiveFolder",     Form1->MapManager1->Files->ArchiveFolder);
        pIniFile->WriteString(FileSection,  "CacheFolder",       Form1->MapManager1->Files->CacheFolder);
        pIniFile->WriteInteger(FileSection, "GameType",          Form1->MapManager1->Files->GameType);
        pIniFile->WriteInteger(FileSection, "GameMode",          Form1->MapManager1->Files->GameMode);
        pIniFile->WriteInteger(FileSection, "InstallMode",       Form1->MapManager1->Files->InstallMode);
        pIniFile->WriteInteger(FileSection, "InstallType",       Form1->MapManager1->Files->InstallType);
        pIniFile->WriteInteger(FileSection, "SmartBackup",       Form1->MapManager1->Files->SmartBackup);
        pIniFile->WriteInteger(FileSection, "LoadArchivesType",  Form1->MapManager1->Files->LoadArchivesType);
        pIniFile->WriteInteger(FileSection, "CacheMode",         Form1->MapManager1->Files->CacheMode);
        pIniFile->WriteBool(FileSection,    "ColorCodeText",     Form1->MapManager1->Files->ColorCodeText);
        pIniFile->WriteBool(FileSection,    "ColArrange",        Form1->MapManager1->Files->ColArrange);
        pIniFile->WriteBool(FileSection,    "MapSubFolders",     Form1->MapManager1->Files->MapSubFolders);
        pIniFile->WriteBool(FileSection,    "ArchiveSubFolders", Form1->MapManager1->Files->ArchiveSubFolders);
        pIniFile->WriteBool(FileSection,    "SmartUninstall",    Form1->MapManager1->Files->SmartUninstall);
        delete pIniFile;
        StatusBar1->SimpleText = "Settings Saved.";
    }
    else
        StatusBar1->SimpleText = "Settings not Saved.";
        */
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
{
    for(int i=0;i<Form1->MapManager1->EventManager->XMLSettings->GameTypes->Count;i++)
    {
        _di_IXMLItemType Item = Form1->MapManager1->EventManager->XMLSettings->GameTypes->Get_Item(i);
        ComboBox1->Items->Add(Item->Text);

        if(Item->Get_id()==Form1->MapManager1->EventManager->XMLSettings->LastGameType)
            ComboBox1->ItemIndex = Item->Get_id();
    }
        
    this->GetSettings();
    StatusBar1->SimpleText = "Settings Loaded.";    
}
//--------------------------------------------------------------------------- 
void __fastcall TForm4::CheckBox3Click(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->FilterRequired = CheckBox3->Checked;
    StatusBar1->SimpleText = "Filter Required Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::CheckBox6Click(TObject *Sender)
{
    Form1->MapManager1->EventManager->XMLSettings->SmartGameTypeInstall = CheckBox6->Checked;
    StatusBar1->SimpleText = "Smart Game Type Install Changed.";
}
//---------------------------------------------------------------------------  
void __fastcall TForm4::Button9Click(TObject *Sender)
{
	UnicodeString B = Edit9->Text;

    if(SelectDirectory("Select Demo Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->DemosFolder = IncludeTrailingPathDelimiter(B);
        Edit9->Text = Form1->MapManager1->EventManager->XMLSettings->DemosFolder;
        StatusBar1->SimpleText = "Demo Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Demo Folder was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button10Click(TObject *Sender)
{
	UnicodeString B = Edit10->Text;

    if(SelectDirectory("Select Screen Shots Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->ScreenShotsFolder = IncludeTrailingPathDelimiter(B);
        Edit10->Text = Form1->MapManager1->EventManager->XMLSettings->ScreenShotsFolder;
        StatusBar1->SimpleText = "Screen Shots Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Screen Shots Folder was not Changed.";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button11Click(TObject *Sender)
{
	UnicodeString B = Edit11->Text;

    if(SelectDirectory("Select Music Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->MusicFolder = IncludeTrailingPathDelimiter(B);
        Edit11->Text = Form1->MapManager1->EventManager->XMLSettings->MusicFolder;
        StatusBar1->SimpleText = "Music Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Music Folder was not Changed.";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button12Click(TObject *Sender)
{
    UnicodeString B = Edit12->Text;

    if(SelectDirectory("Select Texture Folder", "", B))
    {
        Form1->MapManager1->EventManager->XMLSettings->TextureFolder = IncludeTrailingPathDelimiter(B);
        Edit12->Text = Form1->MapManager1->EventManager->XMLSettings->TextureFolder;
        StatusBar1->SimpleText = "Texture Folder Changed.";
    }
    else
        StatusBar1->SimpleText = "Texture Folder was not Changed.";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button13Click(TObject *Sender)
{
    OpenDialog1->Options.Clear();
    OpenDialog1->Options << ofFileMustExist;
    OpenDialog1->Title       = "Set Log File";
    OpenDialog1->Filter      = "XML File (*.xml)|*.xml";
    OpenDialog1->FilterIndex = 0;
    OpenDialog1->DefaultExt  = "XML";

    if(OpenDialog1->Execute())
    {
        Form1->MapManager1->EventManager->XMLSettings->LogFile = ExtractFileName(OpenDialog1->FileName);
        Edit14->Text  = Form1->MapManager1->EventManager->XMLSettings->LogFile;
        StatusBar1->SimpleText = "Log File Changed.";
    }
    else
        StatusBar1->SimpleText = "Log File was not Changed.";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button6Click(TObject *Sender)
{
    TRegistry *Registry = new TRegistry(KEY_READ);

    try
    {
        Registry->RootKey = HKEY_LOCAL_MACHINE;
        Registry->OpenKey(Form1->MapManager1->EventManager->XMLSettings->RegKey, false);

        if(DirectoryExists(Registry->ReadString("Folder")))
        {
            Edit1->Text = IncludeTrailingPathDelimiter(Registry->ReadString("Folder"));
            Form1->MapManager1->EventManager->XMLSettings->GameFolder = Edit1->Text;
        }
    }
    __finally
    {
        delete Registry;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button14Click(TObject *Sender)
{
    OpenDialog1->Options.Clear();
    OpenDialog1->Options << ofFileMustExist;
    OpenDialog1->Title       = "Load Cache File";
    OpenDialog1->Filter      = "INI File (*.ini)|*.ini";
    OpenDialog1->FilterIndex = 0;
    OpenDialog1->DefaultExt  = "INI";
    //OpenDialog1->FileName    = ExtractFileName(Form1->MapManager1->Files->GameEXE);

    if(OpenDialog1->Execute())
    {
        Form1->MapManager1->EventManager->XMLSettings->CacheFile = OpenDialog1->FileName;
        Edit17->Text = Form1->MapManager1->EventManager->XMLSettings->CacheFile;
        StatusBar1->SimpleText = "Cache File Changed.";
    }
    else
        StatusBar1->SimpleText = "Cache File was not Changed.";
}
//---------------------------------------------------------------------------

