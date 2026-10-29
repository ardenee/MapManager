//---------------------------------------------------------------------------
#include <vcl.h>
#include <Registry.hpp>
#include <StrUtils.hpp>  
//---------------------------------------------------------------------------
#include "RenameFilesThread.h"
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall RenameFilesThread::RenameFilesThread(bool CreateSuspended, TFileList* AFileList, AnsiString AGameTag, TLogs* ALog)
    : TThread(CreateSuspended)
{
    FreeOnTerminate = true;
    Total           = 0;
    GameTag         = AGameTag;
    FileTypes       = new TStringList;
    FileList        = new TFileList;
    Log           = ALog;  // usedf ro accessing the TLogs ! (make sure its Synchronize though!!!)
    GetFileTypes();
    FileList->Copy(AFileList); // copy over so the other list can be free from thread
}
//---------------------------------------------------------------------------
void __fastcall RenameFilesThread::DoTerminate()
{
    if(FOnFilesRenamed)
        Synchronize(OnFilesRenamedEvent);

    TThread::DoTerminate();
}
//---------------------------------------------------------------------------
__fastcall RenameFilesThread::~RenameFilesThread()
{
    delete FileList;
    delete FileTypes;
}
//---------------------------------------------------------------------------
// Main Execute()
//---------------------------------------------------------------------------
void __fastcall RenameFilesThread::Execute()
{
    if(Terminated==false)
    {
        int fCount = FileList->Count;
        int tCount = FileTypes->Count;

        for(int i=0;i<tCount;i++) // loop throught the files types
        {
            for(FNum=0;FNum<fCount;FNum++) // loop through the files
            {
            	MapName = StringReplace(FileList->Files[FNum]->FileName, " ", "", TReplaceFlags() << rfReplaceAll); // Remove white space from filenames, all of them

                if(AnsiStartsText(FileTypes->Strings[i], MapName)) // this is case insencative ;) find FileType filter
                {
                    if(MapName.Length()>FileTypes->Strings[i].Length()+2) // so we dont have and dstring errore for blank strings ;)
                    {   // incase we have,  old -> ctf-chrome.ut2, new -> CTF-chrome.ut2
                        MapName = StringReplace(MapName, FileTypes->Strings[i], FileTypes->Strings[i], TReplaceFlags() << rfIgnoreCase); // only the very first 1 !!

                        if(MapName[FileTypes->Strings[i].Length()+1]!='-') // make sure we have, old CTFchrome.ut2, new CTF-chrome.ut2
                            MapName.Insert("-", FileTypes->Strings[i].Length()+1);

                        MapName[FileTypes->Strings[i].Length()+2] = UpCase(MapName[FileTypes->Strings[i].Length()+2]); // incase we have, old -> CTF-chrome.ut2, new -> CTF-Chrome.ut2

                        if(Rename())
                        {
                            Total++;
                            fCount--;
                        }
                        
                        continue; // skips the checking below, no need to check
                    }
                }
            }

            if(i==tCount) // only if not found in the filters then come in here and do renaming
            {
               MapName    = FileTypes->Strings[i];
               MapName[0] = UpCase(MapName[0]);
               Rename();
            }
        }

        if(FOnFilesRenamed)
            Synchronize(OnFilesRenamedEvent);
    }
}
//---------------------------------------------------------------------------
void __fastcall RenameFilesThread::RenameInLog()
{
    if(Log->FileIsInLogs(FileList->Files[FNum]))
    {
        ShowMessage("Found it");         
    }
}
//---------------------------------------------------------------------------
bool __fastcall RenameFilesThread::Rename()
{
    if(FileList->Files[FNum]->FileName.AnsiCompare(MapName)) // only rename if different! case sencative ;)
    {
        // Look in logs and change to new file name as needed
        // this function is NOT Synchronized
        Synchronize(RenameInLog);

        if(RenameFile(FileList->Files[FNum]->FileLocation + FileList->Files[FNum]->FileName, FileList->Files[FNum]->FileLocation + MapName))
        {
            if(FOnFileRenamed)
                Synchronize(OnFileRenamedEvent);

            FileList->Delete(FNum); // remove from list, its been done already, no point in looping with it again
            FNum--;
            return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------
// Events
//---------------------------------------------------------------------------
void __fastcall RenameFilesThread::OnFilesRenamedEvent()
{
    FOnFilesRenamed(this);
}
//---------------------------------------------------------------------------
void __fastcall RenameFilesThread::OnFileRenamedEvent()
{
    FOnFileRenamed(this, FileList->Files[FNum]->FileLocation + FileList->Files[FNum]->FileName, FileList->Files[FNum]->FileLocation + MapName);
}
//---------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------
void __fastcall RenameFilesThread::GetFileTypes()
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_LOCAL_MACHINE;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + GameTag + "\\Maps", false))
        Registry->GetValueNames(FileTypes);

    Registry->CloseKey();
    delete Registry;
}
//---------------------------------------------------------------------------

