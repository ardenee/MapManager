//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "OtherFunctions.h"
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)     
//---------------------------------------------------------------------------
// U Function - Checked
//---------------------------------------------------------------------------
AnsiString __fastcall GetTotals(TListView *TmpListView, int SubCol)
{
    __int64 Total = 0;

    for(int col=0;col<TmpListView->Items->Count;col++)
        Total += StrToIntDef(StringReplace(TmpListView->Items->Item[col]->SubItems->Strings[SubCol], ",", "", TReplaceFlags() << rfReplaceAll), 0);

    return FormatFloat("#,##0", Total);
}

//---------------------------------------------------------------------------
// U Function - Checked - Old -> void __fastcall LoadListBoxInfo(TListBox *TmpListBox, AnsiString Section, AnsiString GameTag)
//---------------------------------------------------------------------------
void __fastcall LoadRegistryData(TStringList *DataItems, AnsiString Section, AnsiString GameTag)
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\" + Section + "\\" + GameTag + "\\", false))
    {   // use TmpList so we can use "TmpList->Duplicates = dupIgnore;"
        TStringList* ValueNames  = new TStringList;
        Registry->GetValueNames(ValueNames);

        for(int i=0;i<ValueNames->Count;i++)
            DataItems->Add(Registry->ReadString(ValueNames->Strings[i]));

        delete ValueNames;
    }

    delete Registry;
}

//---------------------------------------------------------------------------
// U Function - Checked
//---------------------------------------------------------------------------
void __fastcall MakeListViewTable(AnsiString Table, TListView *TmpListView, int ReqCols, AnsiString GameTag, bool ColArrange)
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;
    TmpListView->Columns->Clear();
    TmpListView->Items->Clear();
    TListColumn *NewColumn;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Tables\\" + GameTag + "\\" + Table + "\\", false))
    {   ///AnsiString NewTable=pif->ReadString("ListViewTables", Table, "DefaultTable");
        TStrings* ColNames = new TStringList;
        Registry->GetValueNames(ColNames);

        if(ReqCols!=ColNames->Count)
        {   // user edited the regsettings, load default
            for(int num=0;num<ReqCols;num++)
            {
                NewColumn                               = TmpListView->Columns->Add();
                NewColumn->Caption                      = "Value " + IntToStr(num+1);
                TmpListView->Columns->Items[num]->Width = (TmpListView->Width/ReqCols);
            }
        }
        else
        {   // user defined cols + sizes (settings location WAS found)
            for(int num=0;num<ColNames->Count;num++)
            {
                NewColumn                               = TmpListView->Columns->Add();
                NewColumn->Caption                      = ColNames->Strings[num];
                TmpListView->Columns->Items[num]->Width = Registry->ReadInteger(ColNames->Strings[num]);
            }
        }

        Registry->CloseKey();

        if(ColArrange) // user want to set col allignment?
        {
            if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\TablesAlignment\\" + GameTag + "\\" + Table + "\\", false))
            {
                Registry->GetValueNames(ColNames);

                if(ReqCols==ColNames->Count)
                {   // user defined Alingment for cols (settings location WAS found)
                    for(int num=0;num<ColNames->Count;num++)
                    {
                        if(Registry->ReadInteger(ColNames->Strings[num])==1)
                            TmpListView->Columns->Items[num]->Alignment = taRightJustify;
                        else if(Registry->ReadInteger(ColNames->Strings[num])==2)
                            TmpListView->Columns->Items[num]->Alignment = taCenter;
                    }
                }
            }
        }

        delete ColNames;
        Registry->CloseKey();
    }
    else
    {   // default cols + sizes (settings location WAS NOT found)
        for(int num=0;num<ReqCols;num++)
        {
            NewColumn                               = TmpListView->Columns->Add();
            NewColumn->Caption                      = "Value " + IntToStr(num+1);
            TmpListView->Columns->Items[num]->Width = (TmpListView->Width/ReqCols);
        }
    }
    
    Registry->CloseKey();
    delete Registry;
}

//---------------------------------------------------------------------------
// U Function - Checked - set up value exists for every read, catch all posible errors!
//---------------------------------------------------------------------------
/*
AnsiString __fastcall LoadSettings(TMapManager* TmpMM1)
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Settings", false))
    {
        TmpMM1->Maps->GameType = (TMapManager_GameType) Registry->ReadInteger("CurrentGame");
        //ProgramSettings.GameTag = Registry->ReadIntrger("GameTag");
        switch(TmpMM1->Maps->GameType)
        {
            case MM_GT_NotSpecified              : TmpMM1->Maps->GameTag = "NotSpecified";              break; //0
            case MM_GT_Unreal                    : TmpMM1->Maps->GameTag = "Unreal";                    break; //1
            case MM_GT_UnrealTournament          : TmpMM1->Maps->GameTag = "UnrealTournament";          break; //2
            case MM_GT_TheWheelOfTime            : TmpMM1->Maps->GameTag = "TheWheelOfTime";            break; //3
            case MM_GT_KlingonHonorGuard         : TmpMM1->Maps->GameTag = "KlingonHonorGuard";         break; //4
            case MM_GT_Rune                      : TmpMM1->Maps->GameTag = "Rune";                      break; //5
            case MM_GT_Undying                   : TmpMM1->Maps->GameTag = "Undying";                   break; //6
            case MM_GT_DeusEx                    : TmpMM1->Maps->GameTag = "DeusEx";                    break; //7
            case MM_GT_XComEnforcer              : TmpMM1->Maps->GameTag = "XComEnforcer";              break; //8
            case MM_GT_DeepSpaceNine             : TmpMM1->Maps->GameTag = "DeepSpaceNine";             break; //9
            case MM_GT_NerfArenaBlast            : TmpMM1->Maps->GameTag = "NerfArenaBlast";            break; //10
            case MM_GT_UnrealTournament2003      : TmpMM1->Maps->GameTag = "UT2003";                    break; //11
            case MM_GT_ArmyOperations            : TmpMM1->Maps->GameTag = "ArmyOperations";            break; //12
            case MM_GT_HarryPotterSorcerersStone : TmpMM1->Maps->GameTag = "HarryPotterSorcerersStone"; break; //13
            case MM_GT_HarryPotterChamberSecrets : TmpMM1->Maps->GameTag = "HarryPotterChamberSecrets"; break; //14
            case MM_GT_Unreal2                   : TmpMM1->Maps->GameTag = "Unreal2";                   break; //15
            case MM_GT_SplinterCell              : TmpMM1->Maps->GameTag = "SplinterCell";              break; //16
            default                              : TmpMM1->Maps->GameTag = "UT2003";                    break; // 11
        }
        
        Registry->CloseKey();
    }
    else
        TmpMM1->Maps->GameTag = "NotSpecified";

    //Form6->Button6Click(NULL);

// HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\system\\unreal2.exe
// Path = C:Unreal2

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Settings\\" + TmpMM1->Maps->GameTag, false))
    {
        if(Registry->ValueExists("GameFolder"))
            TmpMM1->GameFolder = Registry->ReadString("GameFolder");
        else
            ShowMessage("Game Root Folders are not Set.\nLook in Program Settings->Misc");
            
       // TmpMM1->Settings->MapFolder                    = IncludeTrailingBackslash(TmpMM1->Settings->GameFolder + Registry->ReadString("MapFolderAddon"));
       // TmpMM1->Settings->CacheFolder                  = IncludeTrailingBackslash(TmpMM1->Settings->GameFolder + Registry->ReadString("CacheFolderAddon"));
       // TmpMM1->Settings->ArchiveFolder                = Registry->ReadString("ArchiveFolder");
       // TmpMM1->Settings->ColArrange                   = Registry->ReadBool("ColArrange");
       // TmpMM1->Settings->SubFolders                   = Registry->ReadBool("SubFolders");

      //  if(TmpMM1->Settings->GameMode)
      //      TmpMM1->Settings->GameString               = Registry->ReadString("GameString");
      //  else
      //      TmpMM1->Settings->GameString               = Registry->ReadString("ServerString");

        // secondary info
      //  TmpMM1->Settings->LogFile               = TmpMM1->Settings->ProgramFolder + TmpMM1->Settings->GameTag + "Archives.ini";
        Registry->CloseKey();
    }
    else
    {
        ShowMessage("Error Reading Program Settings from Registry.\nPlease Reinstall Map Manager 1.5 again to address this problem.\nExiting...");
        Application->Terminate();
    }

    delete Registry;
    return "Map Manager 1.5 - " + TmpMM1->Maps->GameTag;
}
*/
//---------------------------------------------------------------------------
// U Function - Checked - Should load all files for all reasons
//---------------------------------------------------------------------------
void __fastcall GetFiles(TStrings* Files, AnsiString Location, bool SubFolders)
{
    TSearchRec sr;
    Location = IncludeTrailingPathDelimiter(Location);
    TStrings* DirList = new TStringList;

    if(FindFirst(Location + "*.*", faAnyFile, sr) == 0)
    {
        do
        {
            if((sr.Name != ".") && (sr.Name != "..") && ((sr.Attr & faDirectory) == 0))
				Files->Add(Location + sr.Name + '\t' + IntToStr(sr.Size) + '\t' + sr.TimeStamp.TimeString());
            else if((sr.Name != ".") && (sr.Name != "..") && ((sr.Attr & faDirectory) != 0))
                DirList->Add(Location + sr.Name + "\\");
        }
        while(FindNext(sr) == 0);
		FindClose(sr);
    }

    // loop through root folders,
    // adding new ones while looping
    if(SubFolders)
    {
        for(int a=0;a<DirList->Count;a++)
        {
            if(FindFirst(DirList->Strings[a] + "*.*", faAnyFile, sr) == 0)
            {
                do
                {
                    if((sr.Name != ".") && (sr.Name != "..") && ((sr.Attr & faDirectory) == 0))
                        Files->Add(DirList->Strings[a] + sr.Name + '\t' + IntToStr(sr.Size) + '\t' + sr.TimeStamp);

                    if((sr.Name != ".") && (sr.Name != "..") && ((sr.Attr & faDirectory) != 0))
                        DirList->Add(DirList->Strings[a] + sr.Name + "\\");
                }
                while(FindNext(sr) == 0);
                FindClose(sr);
            }
        }
    }

    delete DirList;
}
//---------------------------------------------------------------------------
// U Function - Checked -
//---------------------------------------------------------------------------

AnsiString __fastcall LogSafeNameFromFile(AnsiString FileName) // change all < to [, output from file
{
    FileName = StringReplace(FileName, "<", "[", TReplaceFlags() << rfIgnoreCase << rfReplaceAll);
    FileName = StringReplace(FileName, ">", "]", TReplaceFlags() << rfIgnoreCase << rfReplaceAll);
    return FileName;
}
//---------------------------------------------------------------------------
// U Function - Checked -
//---------------------------------------------------------------------------
AnsiString __fastcall LogSafeNameToFile(AnsiString FileName) // change all [ to < , input into file
{
    FileName = StringReplace(FileName, "[", "<", TReplaceFlags() << rfIgnoreCase << rfReplaceAll);
    FileName = StringReplace(FileName, "]", ">", TReplaceFlags() << rfIgnoreCase << rfReplaceAll);
    return FileName;
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
AnsiString __fastcall ManuallyRenameFile(AnsiString FileName)
{
    AnsiString NewMapName = ExtractFilePath(FileName) + InputBox("Rename File", "Current Name : " + ExtractFileName(FileName), ExtractFileName(FileName));

    if(!NewMapName.IsEmpty() && NewMapName!=FileName)
    {
        if(RenameFile(FileName, NewMapName))
        {
            Form1->StatusBar1->Panels->Items[0]->Text = "File was Renamed."; 
            FileName = NewMapName; //update display
        }
    }
    else
        Form1->StatusBar1->Panels->Items[0]->Text = "Map was not Renamed.";

    return FileName;
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall FindStr(AnsiString Str, TListView *TmpListView, int Col, TStrings* FileList)
{
    for(int i=0;i<TmpListView->Items->Count;i++)// level extra 1 with GetNumber for fixed Row !!
    {
        if(AnsiContainsText(TmpListView->Items->Item[i]->SubItems->Strings[Col], Str)) // name - date - size  = format
           FileList->Add(TmpListView->Items->Item[i]->SubItems->Strings[0] + '\t' + TmpListView->Items->Item[i]->SubItems->Strings[2]  +  '\t' + TmpListView->Items->Item[i]->SubItems->Strings[1]);
    }
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
AnsiString __fastcall GetGameType(AnsiString TmpString, AnsiString MapName)
{
    TStrings* FileTypes    = new TStringList;
    TStrings* GameTypes    = new TStringList;
    TRegistry *Registry    = new TRegistry;
    Registry->RootKey      = HKEY_CURRENT_USER;
    AnsiString TmpFileType = "";
    AnsiString DefGameType = "DM";

    // have we got a valid gametype entered?
    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\File Types\\" /* + Form1->MapManager1->GameTag*/, false))
    {
        Registry->GetValueNames(FileTypes);
        Registry->CloseKey();
    }

    // have we got a valid gametype entered?
    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Game Types\\" /* + Form1->MapManager1->GameTag*/, false))
    {
        Registry->GetValueNames(GameTypes);

        for(int i=0;i<GameTypes->Count;i++)
        {
            if(AnsiContainsText(TmpString, "<" + GameTypes->Strings[i] + ">"))
            {
				if(GameTypes->Strings[i].Compare("AUTO"))
                    TmpString = StringReplace(TmpString, "<" + GameTypes->Strings[i] + ">", Registry->ReadString(GameTypes->Strings[i]), TReplaceFlags() << rfIgnoreCase);
				else if(!GameTypes->Strings[i].Compare("AUTO")) // we need to find out which one
                {
                    Registry->CloseKey();
                    
                    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\File Types\\" /* + Form1->MapManager1->GameTag*/, false))
                    {
                        Registry->GetValueNames(FileTypes);
                        Registry->CloseKey();
                    }

                    // get game type from Map Name
                    for(int x=0;x<FileTypes->Count;x++)
                    {
						if(!StrLIComp(UnicodeString(MapName).c_str(), FileTypes->Strings[x].c_str(), FileTypes->Strings[x].Length()))
						{
							TmpFileType = FileTypes->Strings[x];
                            break;
						}
                    }

                    // reopen game types for getting game type
                    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Game Types\\" /*+ Form1->MapManager1->GameTag*/, false))
                    {
                        if(!TmpFileType.IsEmpty())
                            TmpString = StringReplace(TmpString, "<" + GameTypes->Strings[i] + ">", Registry->ReadString(TmpFileType), TReplaceFlags() << rfIgnoreCase);
                        else  // defaule is DeathMatch
                            TmpString = StringReplace(TmpString, "<" + GameTypes->Strings[i] + ">", Registry->ReadString(DefGameType), TReplaceFlags() << rfIgnoreCase);

                        Registry->CloseKey();
                    }
                }

                TmpFileType = FileTypes->Strings[i];
                break;
            }
        }

        // What if user entered <GR> and its not in our list? add default! user should'nt be so stupid!
        if(TmpFileType.IsEmpty())
        {
            int Start=0, End=0;

            for(int i=1;i<TmpString.Length();i++)
            {
                if(TmpString[i] == '<')
                    Start = i;

                if(TmpString[i] == '>')
                    End = i+1;
            }

            if(Start<End) // right way around? as in'<' before '>'
            {
                TmpString.Delete(Start, End-Start);
                TmpString.Insert(Registry->ReadString(DefGameType),Start);
            }
        }

        Registry->CloseKey();
    }

    delete Registry;
    delete GameTypes;
    delete FileTypes;
    return TmpString;
}
//---------------------------------------------------------------------------
// U Function - Checked
//---------------------------------------------------------------------------
void __fastcall LoadMaps(TListView *TmpListView, AnsiString FileDiscription)
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Maps\\" /* + Form1->MapManager1->GameTag + "\\"*/, false)) // get file types
    {
        TStrings* FileTypes = new TStringList; // file extensions
        Registry->GetValueNames(FileTypes);
        Registry->CloseKey();

        if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\File Types\\" /* + Form1->MapManager1->GameTag + "\\"*/, false)) // get map/archive types
        {
            TStrings* FilterTypes = new TStringList; // file type, as in zip, rar, CTF, BR

            if(!FileDiscription.AnsiCompareIC("All Map Types"))
                Registry->GetValueNames(FilterTypes);   // get all types
            else
            {
                TStrings* KeyNames = new TStringList;  // get selected type only
                Registry->GetValueNames(KeyNames);

                for(int i=0;i<KeyNames->Count;i++)
                {
					if(!Registry->ReadString(KeyNames->Strings[i]).Compare(FileDiscription))
                    {
                        FilterTypes->Add(KeyNames->Strings[i]);
                        break;
                    }
                }
                
                delete KeyNames;
            }

           // Form1->MapManager1->InstancesOfLoadFilesThread = 1; //add one to our stack of needed
          //  LoadFilesThread *LoadFilesThreadInstance; //Test MultiThreaded Item
            //LoadFilesThreadInstance = new LoadFilesThread(true, TmpListView, 0, FileTypes, FilterTypes, Form1->MapManager1->MapFolder);
           // LoadFilesThreadInstance->Resume();

            Registry->CloseKey();
            delete FilterTypes;
        }

        delete FileTypes;
    }

    Registry->CloseKey();
    delete Registry;
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall LoadArchives(TListView *TmpListView, AnsiString FileDiscription)
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Archives\\" /* + Form1->MapManager1->GameTag + "\\" */, false))
    {
        TStrings* FileTypes = new TStringList; // file extensions

        if(!FileDiscription.AnsiCompareIC("All Archive Types"))
            Registry->GetValueNames(FileTypes);
        else
        {
            TStrings* KeyNames = new TStringList;
            Registry->GetValueNames(KeyNames);

            for(int i=0;i<KeyNames->Count;i++)
            {
				if(!Registry->ReadString(KeyNames->Strings[i]).Compare(FileDiscription))
                {
                    FileTypes->Add(KeyNames->Strings[i]);
                    break;
                }
            }
            delete KeyNames;
        }

        //PageControl1->OnChange  = NULL;
        //ListBox1->OnClick       = NULL;

       // Form1->MapManager1->InstancesOfLoadFilesThread = 1; //add one to our stack of needed
       // LoadFilesThread *LoadFilesThreadInstance; //Test MultiThreaded Item
        //LoadFilesThreadInstance = new LoadFilesThread(true, TmpListView, 1, FileTypes, FileTypes, Form1->MapManager1->ArchiveFolder);
        //LoadFilesThreadInstance->Resume();

        delete FileTypes;
    }

    Registry->CloseKey();
    delete Registry;
}
//---------------------------------------------------------------------------
void __fastcall RenameFiles(TStrings* FileList)
{
   // Form1->MapManager1->InstancesOfRenameFilesThread = 1; //add one to our stack of needed
   // RenameFilesThread *RenameFilesThreadInstance; //Test MultiThreaded Item
   // RenameFilesThreadInstance = new RenameFilesThread(true, FileList);
  //  RenameFilesThreadInstance->Resume();
}
//---------------------------------------------------------------------------
/*
void __fastcall DisplayMapsOnFrom(TListView *TmpListView, TStrings* FileStrings, bool LogVerfy, int Progress, AnsiString LogFile, AnsiString GameTag)
{
    FileInfoData TmpValues;
    TIniFile* pif = new TIniFile(LogFile);

    TmpListView->Items->BeginUpdate();

    for(int i=0;i<FileStrings->Count;i++)
    {
        if(ValidMapDisplayString(FileStrings->Strings[i]))
        {
            TmpValues = GetDataFromDisplayStr(FileStrings->Strings[i]);

            TmpListView->Items->Insert(TmpListView->Items->Count);
            TmpListView->Items->Item[TmpListView->Items->Count-1]->Caption = IntToStr(i+1);
            TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add(ExtractFileName(TmpValues.Name));
            TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add(TmpValues.Size);
            TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add(TmpValues.Date);

            if(LogVerfy)
            {
                if(pif->ValueExists(GameTag, LogSafeNameToFile(ExtractFileName(TmpValues.Name)) + '\t' + TmpValues.Date + '\t' +TmpValues.Size))
                    TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add("Yes"); 
                else
                    TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add("No"); // Default Value
            }
            else
                TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add(""); // Default Value

            TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add(ExtractFilePath(TmpValues.Name));
        }

        Form1->ProgressBar1->Position = Form1->ProgressBar1->Position+1;
    }

    TmpListView->Items->EndUpdate();

    delete pif;
}
*/
//---------------------------------------------------------------------------

bool ValidMapDisplayString(AnsiString TmpString)
{
    int Tabs = 0;

    for(int i=1;i<TmpString.Length();i++)
    {
        if(TmpString[i]=='\t')
            Tabs++;
    }

    if(Tabs==2)
        return true;
    else
        return false;
}
/*
FileInfoData GetDataFromDisplayStr(AnsiString MainString)
{
    FileInfoData Values;

    Values.Name = MainString;
    Values.Name.SetLength(AnsiPos('\t', MainString)-1);// -1 to get rid of the TAB '\t'
    MainString.Delete(1, AnsiPos('\t', MainString));

    Values.Date = MainString;
    Values.Date.SetLength(AnsiPos('\t', MainString)-1);// -1 to get rid of the TAB '\t'
    MainString.Delete(1, AnsiPos('\t', MainString));

    Values.Size  = MainString;

    return Values;
}
*/


