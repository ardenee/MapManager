//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include "TLogs.h"  
//----------------------------------------------------------------------------
__fastcall TLogs::TLogs()
    : TSettings()
{
    FDataSource    = new TDataSource(NULL);
    FClientDataSet = new TClientDataSet(NULL);
	FLogList       = new TMMFileList();
    this->CreateDB();

    // default
    TSettings::LogFile = "Archives" + TSettings::GameTag + ".xml";
    this->LoadFromFile(TSettings::LogFile);
}
//----------------------------------------------------------------------------
__fastcall TLogs::~TLogs()  
{
    this->UpdateLogs();
    delete FDataSource;
	delete FClientDataSet;
    delete FLogList;
}
//----------------------------------------------------------------------------
// Private - load from file
//----------------------------------------------------------------------------
void __fastcall TLogs::LoadDB()
{
    if(FileExists(TSettings::ProgramFolder + TSettings::LogFile))
        FClientDataSet->LoadFromFile(TSettings::ProgramFolder + TSettings::LogFile);
}
//----------------------------------------------------------------------------
// Private - Make DB Table
//----------------------------------------------------------------------------
void __fastcall TLogs::CreateDB()
{
    TFieldDefs *pDefs = FClientDataSet->FieldDefs;
    TFieldDef *pDef = pDefs->AddFieldDef();
    pDef->DataType = ftInteger;
    pDef->Name = "Num";
    pDef = pDefs->AddFieldDef();
    pDef->DataType = ftString;
    pDef->Size = 150;
    pDef->Name = "FileName";
    pDef = pDefs->AddFieldDef();
    pDef->DataType = ftString;
    pDef->Size = 15;
    pDef->Name = "FileSize";
    pDef = pDefs->AddFieldDef();
    pDef->DataType = ftString;
    pDef->Size = 200;
    pDef->Name = "FileLocation";
    pDef = pDefs->AddFieldDef();
    pDef->DataType = ftDateTime;
    pDef->Name = "FileDate"; 
    pDef = pDefs->AddFieldDef();
    pDef->DataType = ftInteger;
    pDef->Name = "BelongsTo";
    pDef = pDefs->AddFieldDef();
    pDef->DataType = ftInteger;
    pDef->Name = "CRC32";
    TIndexDef *pIDef = FClientDataSet->IndexDefs->AddIndexDef();
    pIDef->Fields = "Num";
    pIDef->Name = "IntIndex";
    FClientDataSet->CreateDataSet();

    FDataSource->DataSet       = FClientDataSet;
    FClientDataSet->Active     = true;
    FClientDataSet->LogChanges = false;//false;
}
//----------------------------------------------------------------------------
// Private - Set Value
//----------------------------------------------------------------------------
void __fastcall TLogs::SetIntValue(const int Index, int Value)
{
     switch(Index)
    {
        case 0 : FLogType = Value; break;
    }
}
//----------------------------------------------------------------------------
// Private - Default Functions
//----------------------------------------------------------------------------
void __fastcall TLogs::AddLogEntry(PFileList pLogList)
{
    int num = FClientDataSet->RecordCount+1;

    //ShowMessage("Before Adding = " + IntToStr(FClientDataSet->RecordCount));

    for(int i=0;i<pLogList->Count;i++)
    {
        //ShowMessage(num);
        if(FLogList->Files[i]->BelongsTo==-1)
        {
            num = FClientDataSet->RecordCount+1;
            FClientDataSet->InsertRecord(ARRAYOFCONST((FClientDataSet->RecordCount+1,
                                                       FLogList->Files[i]->FileName,
                                                       FLogList->Files[i]->FileSize,
                                                       FLogList->Files[i]->FileLocation,
                                                       FLogList->Files[i]->FileDate,
                                                       -1,
                                                       (int) FLogList->Files[i]->CRC32)));

            continue; // used to skip the block below, keeps the loop/data added valid ;)
        }

       FClientDataSet->InsertRecord(ARRAYOFCONST((FClientDataSet->RecordCount+1,
                                                  FLogList->Files[i]->FileName,
                                                  FLogList->Files[i]->FileSize,
                                                  FLogList->Files[i]->FileLocation,
                                                  FLogList->Files[i]->FileDate,
                                                  num,
                                                  (int) FLogList->Files[i]->CRC32)));
    }

    //ShowMessage("After Adding = " + IntToStr(FClientDataSet->RecordCount));
    this->UpdateLogs();
}
//----------------------------------------------------------------------------
// Archive<GameTag>.xml
//----------------------------------------------------------------------------
void __fastcall TLogs::AddArchiveLogEntry(PFileList pLogList)
{
    FLogList->Copy(pLogList); // copy the contents over

    if(FLogList->Count>1) // must have at least 2 entrys to add to logs! [from and too]
    {
        if(MainArchiveLogExits(FLogList->Files[0])) // stop the same log entry from being entered more then once!
            return;
        else
            AddLogEntry(FLogList);
    }
}
//----------------------------------------------------------------------------
void __fastcall TLogs::AddSmartBackupLogEntry(PFileList pLogList)
{
    FLogList->Copy(pLogList); // copy the contents over

    if(FLogList->Count>1) // must have at least 2 entrys to add to logs! [from and too]
    {
        PFileInfo AFile = FLogList->Files[0];

        if(AFile)
        {
            if(MainArchiveLogExits(AFile)) // stop the same log entry from being entered more then once!
            {
                FClientDataSet->Filtered = true;

                for(int i=0;i<FLogList->Count;i++)
                {
                    FClientDataSet->Filter = "FileName = '"           + StringReplace(FLogList->Files[i]->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                                             "' and FileLocation = '" + FLogList->Files[i]->FileLocation + "'";

                    if(FClientDataSet->FindFirst())
                        EditLogEntry(FLogList->Files[i]);
                }

                FClientDataSet->Filtered = false;
            }
            else
                AddLogEntry(FLogList); // just add dont edit
        }
    }
}
//----------------------------------------------------------------------------
// Cache<GameTag>.xml
//----------------------------------------------------------------------------
void __fastcall TLogs::AddCacheLogEntry(PFileList pLogList)
{
    FLogList->Copy(pLogList); // copy the contents over
}
//----------------------------------------------------------------------------
void __fastcall TLogs::EditLogEntry(PFileInfo LogEntry)
{
    FClientDataSet->Edit();
    FClientDataSet->FieldByName("FileDate")->AsString = LogEntry->FileDate;
    FClientDataSet->FieldByName("FileSize")->AsString = LogEntry->FileSize;
    this->UpdateLogs();
}
//----------------------------------------------------------------------------
bool __fastcall TLogs::MainArchiveLogExits(PFileInfo archiveData)
{
    if(FClientDataSet->RecordCount==0 || archiveData->BelongsTo!=-1)
        return false;

    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileName = '"           + StringReplace(archiveData->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                               "' and FileLocation = '" + archiveData->FileLocation +
                               "' and BelongsTo = "     + IntToStr(-1);

    if(FClientDataSet->FindFirst())
    {
        FClientDataSet->Filtered = false;
        return true;
    }

    FClientDataSet->Filtered = false;
    return false;
}
//----------------------------------------------------------------------------
void __fastcall TLogs::UninstallEntrys(PFileInfo LogEntry)
{
    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileName = '"           + StringReplace(LogEntry->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                               "' and FileSize = '"     + LogEntry->FileSize     +
                               "' and FileDate = '"     + LogEntry->FileDate     +
                               "' and FileLocation = '" + LogEntry->FileLocation + "'";

    if(FClientDataSet->FindFirst()) // remove Log Entrys, root and children
    {
        FClientDataSet->Filter = "FileName = '"           + StringReplace(LogEntry->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                                 "' and FileSize = '"     + LogEntry->FileSize     +
                                 "' and FileDate = '"     + LogEntry->FileDate     +
                                 "' and FileLocation = '" + LogEntry->FileLocation +
                                 "' or BelongsTo = "      + FClientDataSet->FieldByName("Num")->AsInteger; // used for secondary file!

        if(FClientDataSet->FindFirst())
        {
            do
            {
                FClientDataSet->Delete(); // deletes current record !
            }while(FClientDataSet->FindFirst()); // not next b/c we delete the first, so reset to first

            this->UpdateLogs();
        }
    }

    if(FOnGotLogEntrys)
        FOnGotLogEntrys(this, FLogList);

    FClientDataSet->Filtered = false;
}
//----------------------------------------------------------------------------
void __fastcall TLogs::UninstallEntry(PFileInfo LogEntry)
{
    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileName = '"           + StringReplace(LogEntry->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                               "' and FileSize = '"     + LogEntry->FileSize     +
                               "' and FileDate = '"     + LogEntry->FileDate     +
                               "' and FileLocation = '" + LogEntry->FileLocation + "'";

    if(FClientDataSet->FindFirst()) // remove Log Entrys, root and children
    {
        FClientDataSet->Delete(); // deletes current record !
        this->UpdateLogs();
    }

    FClientDataSet->Filtered = false;
}
//----------------------------------------------------------------------------
// Display - uses event to send data back
//----------------------------------------------------------------------------
void __fastcall TLogs::GetLogEntrys()
{
    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileName IS NOT NULL"; // valid entry?
    //FLogList->Clear();

    if(FClientDataSet->FindFirst())
    {
        do
        {
            PFileInfo FileData = FLogList->AddFile();

            if(FileData)
            {
                FileData->Num          = FClientDataSet->FieldByName("Num"         )->AsInteger;
                FileData->FileName     = FClientDataSet->FieldByName("FileName"    )->AsString;
                FileData->FileDate     = FClientDataSet->FieldByName("FileDate"    )->AsString;
				FileData->FileSize     = FClientDataSet->FieldByName("FileSize"    )->AsLargeInt;// AsString;
                FileData->FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
                FileData->BelongsTo    = FClientDataSet->FieldByName("BelongsTo"   )->AsInteger;
                FileData->CRC32        = FClientDataSet->FieldByName("CRC32"       )->AsInteger;
            }
        }while(FClientDataSet->FindNext());
    }

    if(FOnGotLogEntrys)
        FOnGotLogEntrys(this, FLogList);

    FClientDataSet->Filtered = false;
}
//----------------------------------------------------------------------------
void __fastcall TLogs::GetArchiveFile(PFileInfo FileData, PFileInfo ArchiveData)
{
    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileName = '"           + StringReplace(FileData->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                               "' and FileSize = '"     + FileData->FileSize     +
                               "' and FileDate = '"     + FileData->FileDate     +
                               "' and FileLocation = '" + FileData->FileLocation + "'";

    if(FClientDataSet->FindFirst())
    {
        TMM_FileInfo tmp = GetLogEntry(FClientDataSet->FieldByName("BelongsTo")->AsInteger);
        ArchiveData->Num          = tmp.Num;
        ArchiveData->BelongsTo    = tmp.BelongsTo;
        ArchiveData->FileName     = tmp.FileName;
        ArchiveData->FileSize     = tmp.FileSize;
        ArchiveData->FileDate     = tmp.FileDate;
        ArchiveData->FileLocation = tmp.FileLocation;
        ArchiveData->CRC32        = tmp.CRC32;
        ArchiveData->Installed    = tmp.Installed;
    }

    FClientDataSet->Filtered = false;
}
//----------------------------------------------------------------------------
bool __fastcall TLogs::GetFullLogEntry(PFileInfo LogEntry)
{
    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileName = '"           + StringReplace(LogEntry->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                               "' and FileSize = '"     + LogEntry->FileSize     +
                               "' and FileDate = '"     + LogEntry->FileDate     +
                               "' and FileLocation = '" + LogEntry->FileLocation + "'";

    if(FClientDataSet->FindFirst())
    {
        LogEntry->Num          = FClientDataSet->FieldByName("Num")->AsInteger;
        LogEntry->FileName     = FClientDataSet->FieldByName("FileName")->AsString;
        LogEntry->FileDate     = FClientDataSet->FieldByName("FileDate")->AsString;
        LogEntry->FileSize     = FClientDataSet->FieldByName("FileSize")->AsLargeInt; //AsString;
        LogEntry->FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
        LogEntry->BelongsTo    = FClientDataSet->FieldByName("BelongsTo")->AsInteger;
        LogEntry->CRC32        = FClientDataSet->FieldByName("CRC32")->AsInteger;
        FClientDataSet->Filtered = false;
        return true;
    }

    FClientDataSet->Filtered = false;
    return false;
}
//----------------------------------------------------------------------------
void __fastcall TLogs::GetFilesInArchive(PFileInfo archiveData, PFileList FilesInArchive)
{
    if(GetFullLogEntry(archiveData))
    {
        FClientDataSet->Filtered = true;
        FClientDataSet->Filter   = "BelongsTo = " + IntToStr(archiveData->Num);

        if(FClientDataSet->FindFirst())
        {
            do
            {
                PFileInfo fileData = FilesInArchive->AddFile();

                if(fileData)
                {
                    fileData->Num          = FClientDataSet->FieldByName("Num"         )->AsInteger;
                    fileData->FileName     = FClientDataSet->FieldByName("FileName"    )->AsString;
                    fileData->FileDate     = FClientDataSet->FieldByName("FileDate"    )->AsString;
                    fileData->FileSize     = FClientDataSet->FieldByName("FileSize"    )->AsLargeInt;//AsString;
                    fileData->FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
                    fileData->BelongsTo    = FClientDataSet->FieldByName("BelongsTo"   )->AsInteger;
                    fileData->CRC32        = FClientDataSet->FieldByName("CRC32"       )->AsInteger;
                }
            }while(FClientDataSet->FindNext());
        }

        FClientDataSet->Filtered = false;
    }
}
//----------------------------------------------------------------------------
bool __fastcall TLogs::FileIsInLogs(PFileInfo archiveData)
{
    FClientDataSet->Filtered = true;

    FClientDataSet->Filter   = "FileName = '"           + StringReplace(archiveData->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                               "' and FileSize = '"     + archiveData->FileSize     +
                               "' and FileDate = '"     + archiveData->FileDate     +
                               "' and FileLocation = '" + archiveData->FileLocation + "'";

    if(FClientDataSet->FindFirst())
    {
        FClientDataSet->Filtered = false;
        return true;
    }

    FClientDataSet->Filtered = false;
    return false;
}
//----------------------------------------------------------------------------
bool __fastcall TLogs::FileIsInSBLogs(PFileInfo archiveData)
{
    AnsiString OldLogFile = TSettings::LogFile;
    LoadFromFile("SmartBackup" + TSettings::GameTag + ".xml");

    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileSize = '"           + StringReplace(archiveData->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                               "' and FileDate = '"     + archiveData->FileDate     +
                               "' and FileLocation = '" + archiveData->FileLocation +
                               "' and (FileName = '"    + archiveData->FileName     +
                               "' or FileName = '"      + archiveData->FileName + ".old')";

    if(FClientDataSet->FindFirst())
    {
        FClientDataSet->Filtered = false;
        return true;
    }

    FClientDataSet->Filtered = false; 
    LoadFromFile(TSettings::LogFile);
    return false;
}
//----------------------------------------------------------------------------
TMM_FileInfo __fastcall TLogs::GetLogEntry(int LogNum)
{
    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "Num = '" + IntToStr(LogNum) + "'";
    TMM_FileInfo RootNode;

    if(FClientDataSet->FindFirst())
    {
        RootNode.Num          = FClientDataSet->FieldByName("Num"         )->AsInteger;
        RootNode.FileName     = FClientDataSet->FieldByName("FileName"    )->AsString;
        RootNode.FileDate     = FClientDataSet->FieldByName("FileDate"    )->AsString;
		RootNode.FileSize     = FClientDataSet->FieldByName("FileSize"    )->AsLargeInt;
        RootNode.FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
        RootNode.BelongsTo    = FClientDataSet->FieldByName("BelongsTo"   )->AsInteger;
        RootNode.CRC32        = FClientDataSet->FieldByName("CRC32"       )->AsInteger;
    }

    FClientDataSet->Filtered = false;
    return RootNode;
}
//----------------------------------------------------------------------------
// Saving and updating/changing
//----------------------------------------------------------------------------
void __fastcall TLogs::UpdateLogs()
{
    //ShowMessage("Before Mergeing = " + IntToStr(FClientDataSet->RecordCount));
    FClientDataSet->Filtered = false;
    FClientDataSet->MergeChangeLog(); // make any updated we did earlier
    FClientDataSet->SaveToFile(TSettings::ProgramFolder + TSettings::LogFile, dfXML);   
    //ShowMessage("After Adding = " + IntToStr(FClientDataSet->RecordCount));
}
//---------------------------------------------------------------------------
// Display - used for menu
//---------------------------------------------------------------------------
void __fastcall TLogs::GetLogsDisplayFilters(TStrings* pFilterList)
{
    //pFilterList->Clear();
    //TReg::GetDatas("\\SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + TSettings::GameTag + "\\Logs", pFilterList, true);
}
//----------------------------------------------------------------------------
// public - set new DB file and then load
//----------------------------------------------------------------------------
void __fastcall TLogs::LoadFromFile(AnsiString NewLogFile)
{
    TSettings::LogFile = NewLogFile;
    FClientDataSet->EmptyDataSet();
    LoadDB();
}
//----------------------------------------------------------------------------
bool __fastcall TLogs::EditLogEnrty(PFileInfo OldLogEntry, PFileInfo NewLogEntry)
{
	 return false;
}

