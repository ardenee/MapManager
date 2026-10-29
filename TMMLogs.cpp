//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include "TMMLogs.h"
#include <XMLDoc.hpp>
//----------------------------------------------------------------------------
__fastcall TMMLogs::TMMLogs()
    : TMMXML()
{
    fLogList   = new TMMFileList;
    fXMLLogFile = NewXMLDocument(); // InstallLogFile
    fLogFile = "Archives.xml";

    if(fXMLLogFile)
    {
        fXMLLogFile->Active     = true;
        fXMLLogFile->StandAlone = "yes";
    }

    this->LoadFromFile(LogFile);
    LoadDB();
}
//----------------------------------------------------------------------------
__fastcall TMMLogs::~TMMLogs()
{
    this->UpdateLogs();
    delete fLogList;
}
//----------------------------------------------------------------------------
// Private - load from file
//----------------------------------------------------------------------------
void __fastcall TMMLogs::LoadDB()
{
    //if(FileExists(ProgramFolder + LogFile))
    //{
    //    fXMLLogFile->LoadFromFile(ProgramFolder + LogFile);
    //    fXMLRootNode = fXMLLogFile->GetDocumentElement();
    //}
    //else
        fXMLRootNode = fXMLLogFile->AddChild("InstallLog");
}
//----------------------------------------------------------------------------
// Private - Set Value
//----------------------------------------------------------------------------
void __fastcall TMMLogs::SetIntValue(const int pindex, int pvalue)
{
     switch(pindex)
    {
        case 0 : fLogType = pvalue; break;
    }
}
//----------------------------------------------------------------------------
// Private - Default Functions
//----------------------------------------------------------------------------
void __fastcall TMMLogs::AddLogEntry(PFileList pLogList)
{
/*
    if(fXMLRootNode)
    {
        _di_IXMLNode XMLArchive;
        _di_IXMLNode XMLFile;
        _di_IXMLNode XMLtmp;

        for(int i=0;i<pLogList->Count;i++)
        {
            if(i==0) // first entry should be the Archive itself!!!!
            {
                XMLArchive = fXMLRootNode->AddChild("Archive");
                XMLFile    = XMLArchive->AddChild("ArchiveFile");
            }
            else
                XMLFile = XMLArchive->AddChild("File");

            XMLtmp = XMLFile->AddChild("CRC"); 
            XMLtmp->Text = IntToStr(fLogList->Files[i]->CRC32);
            XMLtmp = XMLFile->AddChild("Name");
            XMLtmp->Text = fLogList->Files[i]->FileName;
            XMLtmp = XMLFile->AddChild("Size");
            XMLtmp->Text = fLogList->Files[i]->FileSize;
            XMLtmp = XMLFile->AddChild("Date");
            XMLtmp->Text = fLogList->Files[i]->FileDate;
            XMLtmp = XMLFile->AddChild("Location");
            XMLtmp->Text = fLogList->Files[i]->FileLocation;
        }
	}
    */

    this->UpdateLogs(); // save back to file (Log file will always be uptodate ;))
}
//----------------------------------------------------------------------------
// Archive<GameTag>.xml
//----------------------------------------------------------------------------
void __fastcall TMMLogs::AddArchiveLogEntry(PFileList pLogList)
{
    fLogList->Copy(pLogList); // copy the contents over

    if(fLogList->Count>1) // must have at least 2 entrys to add to logs! [from and too]
    {
        if(MainArchiveLogExits(fLogList->Files[0])) // stop the same log entry from being entered more then once!
            return;
        else
            AddLogEntry(fLogList);
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMLogs::AddSmartBackupLogEntry(PFileList pLogList)
{
/*
    fLogList->Copy(pLogList); // copy the contents over

    if(FLogList->Count>1) // must have at least 2 entrys to add to logs! [from and too]
    {
        PFileInfo AFile = fLogList->Files[0];

        if(AFile)
        {
            if(MainArchiveLogExits(AFile)) // stop the same log entry from being entered more then once!
            {
                FClientDataSet->Filtered = true;

                for(int i=0;i<fLogList->Count;i++)
                {
                    FClientDataSet->Filter = "FileName = '"           + StringReplace(fLogList->Files[i]->FileName, "'", "*", TReplaceFlags() << rfReplaceAll) +
                                             "' and FileLocation = '" + fLogList->Files[i]->FileLocation + "'";

                    if(FClientDataSet->FindFirst())
                        EditLogEntry(FLogList->Files[i]);
                }

                FClientDataSet->Filtered = false;
            }
            else
                AddLogEntry(FLogList); // just add dont edit
        }
    }
    */
}
//----------------------------------------------------------------------------
// Cache<GameTag>.xml
//----------------------------------------------------------------------------
void __fastcall TMMLogs::AddCacheLogEntry(PFileList pLogList)
{
    fLogList->Copy(pLogList); // copy the contents over
}
//----------------------------------------------------------------------------
void __fastcall TMMLogs::EditLogEntry(PFileInfo plogEntry)
{
/*
    FClientDataSet->Edit();
    FClientDataSet->FieldByName("FileDate")->AsString = LogEntry->FileDate;
    FClientDataSet->FieldByName("FileSize")->AsString = LogEntry->FileSize;
    this->UpdateLogs();
*/
}
//----------------------------------------------------------------------------
bool __fastcall TMMLogs::MainArchiveLogExits(PFileInfo parchiveData)
{
/*
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
*/
    return false;
}
//----------------------------------------------------------------------------
void __fastcall TMMLogs::UninstallEntrys(PFileInfo plogEntry)
{
/*
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
*/
}
//----------------------------------------------------------------------------
void __fastcall TMMLogs::UninstallEntry(PFileInfo plogEntry)
{
/*
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
*/
}
//----------------------------------------------------------------------------
// Display - uses event to send data back
//----------------------------------------------------------------------------
void __fastcall TMMLogs::GetLogEntrys()
{
/*
	FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "FileName IS NOT NULL"; // valid entry?
    FLogList->Clear();

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
                FileData->FileSize     = FClientDataSet->FieldByName("FileSize"    )->AsString;
                FileData->FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
                FileData->BelongsTo    = FClientDataSet->FieldByName("BelongsTo"   )->AsInteger;
                FileData->CRC32        = FClientDataSet->FieldByName("CRC32"       )->AsInteger;
            }
        }while(FClientDataSet->FindNext());
    }

    if(FOnGotLogEntrys)
        FOnGotLogEntrys(this, FLogList);

	FClientDataSet->Filtered = false;
*/
}
//----------------------------------------------------------------------------
void __fastcall TMMLogs::GetArchiveFile(PFileInfo pfileData, PFileInfo parchiveData)
{      /*
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
    */
}
//----------------------------------------------------------------------------
bool __fastcall TMMLogs::GetFullLogEntry(PFileInfo plogEntry)
{
/*
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
        LogEntry->FileSize     = FClientDataSet->FieldByName("FileSize")->AsString;
        LogEntry->FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
        LogEntry->BelongsTo    = FClientDataSet->FieldByName("BelongsTo")->AsInteger;
        LogEntry->CRC32        = FClientDataSet->FieldByName("CRC32")->AsInteger;
        FClientDataSet->Filtered = false;
        return true;
    }

    FClientDataSet->Filtered = false;
    */
    return false;
}
//----------------------------------------------------------------------------
void __fastcall TMMLogs::GetFilesInArchive(PFileInfo parchiveData, PFileList pfilesInArchive)
{
/*
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
                    fileData->FileSize     = FClientDataSet->FieldByName("FileSize"    )->AsString;
                    fileData->FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
                    fileData->BelongsTo    = FClientDataSet->FieldByName("BelongsTo"   )->AsInteger;
                    fileData->CRC32        = FClientDataSet->FieldByName("CRC32"       )->AsInteger;
                }
            }while(FClientDataSet->FindNext());
        }

        FClientDataSet->Filtered = false;
    }
    */
}
//----------------------------------------------------------------------------
bool __fastcall TMMLogs::FileIsInLogs(PFileInfo parchiveData)
{
/*
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
    */
    return false;
}
//----------------------------------------------------------------------------
bool __fastcall TMMLogs::FileIsInSBLogs(PFileInfo parchiveData)
{
/*
    AnsiString OldLogFile = TMMSettings::LogFile;
    LoadFromFile("SmartBackup" + TMMSettings::GameTag + ".xml");

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
    LoadFromFile(TMMSettings::LogFile);
    */
    return false;
}
//----------------------------------------------------------------------------
TMM_FileInfo __fastcall TMMLogs::GetLogEntry(int plogNum)
{
/*
    FClientDataSet->Filtered = true;
    FClientDataSet->Filter   = "Num = '" + IntToStr(LogNum) + "'";
    TMM_FileInfo RootNode;

    if(FClientDataSet->FindFirst())
    {
        RootNode.Num          = FClientDataSet->FieldByName("Num"         )->AsInteger;
        RootNode.FileName     = FClientDataSet->FieldByName("FileName"    )->AsString;
        RootNode.FileDate     = FClientDataSet->FieldByName("FileDate"    )->AsString;
        RootNode.FileSize     = FClientDataSet->FieldByName("FileSize"    )->AsString;
        RootNode.FileLocation = FClientDataSet->FieldByName("FileLocation")->AsString;
        RootNode.BelongsTo    = FClientDataSet->FieldByName("BelongsTo"   )->AsInteger;
        RootNode.CRC32        = FClientDataSet->FieldByName("CRC32"       )->AsInteger;
    }

    FClientDataSet->Filtered = false;
    return RootNode;
    */
    TMM_FileInfo v;
    return v;
}
//----------------------------------------------------------------------------
// Saving and updating/changing
//----------------------------------------------------------------------------
void __fastcall TMMLogs::UpdateLogs()
{
    fXMLLogFile->SaveToFile(fLogFile);
    fXMLLogFile->Active   = false;
    //ShowMessage("Before Mergeing = " + IntToStr(FClientDataSet->RecordCount));
    //FClientDataSet->Filtered = false;
    //FClientDataSet->MergeChangeLog(); // make any updated we did earlier
    //FClientDataSet->SaveToFile(TMMSettings::ProgramFolder + TMMSettings::LogFile, dfXML);
    //ShowMessage("After Adding = " + IntToStr(FClientDataSet->RecordCount));
}
//---------------------------------------------------------------------------
// Display - used for menu
//---------------------------------------------------------------------------
void __fastcall TMMLogs::GetLogsDisplayFilters(TStrings* pFilterList)
{
    //pFilterList->Clear();
    //TReg::GetDatas("\\SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + TSettings::GameTag + "\\Logs", pFilterList, true);
}
//----------------------------------------------------------------------------
// public - set new DB file and then load
//----------------------------------------------------------------------------
void __fastcall TMMLogs::LoadFromFile(AnsiString NewLogFile)
{
/*
    TMMSettings::LogFile = NewLogFile;
    FClientDataSet->EmptyDataSet();
    LoadDB();
    */
}
//----------------------------------------------------------------------------
bool __fastcall TMMLogs::EditLogEnrty(PFileInfo OldLogEntry, PFileInfo NewLogEntry)
{
    return false;
}

