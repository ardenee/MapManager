//---------------------------------------------------------------------------
#include <vcl.h>
#include <Registry.hpp>
#include <StrUtils.hpp>  
//---------------------------------------------------------------------------
#include "TMMRenameThread.h"
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TMMRenameThread::TMMRenameThread(bool CreateSuspended, PFileList pFileList, TStrings* pFileTypes, AnsiString pgameTag, TMMLogs* pLog)
    : TThread(CreateSuspended)
{
    FreeOnTerminate = true;
    fTotal           = 0;
    fGameTag         = pgameTag;
    fFileTypes       = new TStringList;
    fFileList        = new TMMFileList;
    fLog             = pLog;  // usedf ro accessing the TLogs ! (make sure its Synchronize though!!!)
    fFileList->Copy(pFileList); // copy over so the other list can be free from thread
    fFileTypes->AddStrings(pFileTypes);
}
//---------------------------------------------------------------------------
void __fastcall TMMRenameThread::DoTerminate()
{
    if(fOnFilesRenamed)
        Synchronize(OnFilesRenamedEvent);

    TThread::DoTerminate();
}
//---------------------------------------------------------------------------
__fastcall TMMRenameThread::~TMMRenameThread()
{
    delete fFileList;
    delete fFileTypes;
}
//---------------------------------------------------------------------------
// Main Execute()
//---------------------------------------------------------------------------
void __fastcall TMMRenameThread::Execute()
{
    if(Terminated==false)
    {
        int fCount = fFileList->Count;
        int tCount = fFileTypes->Count;

        for(int i=0;i<tCount;i++) // loop throught the files types
        {
            for(fNum=0;fNum<fCount;fNum++) // loop through the files
            {
            	fMapName = StringReplace(fFileList->Files[fNum]->FileName, " ", "", TReplaceFlags() << rfReplaceAll); // Remove white space from filenames, all of them

                if(AnsiStartsText(fFileTypes->Strings[i], fMapName)) // this is case insencative ;) find FileType filter
                {
                    if(fMapName.Length()>fFileTypes->Strings[i].Length()+2) // so we dont have and dstring errore for blank strings ;)
                    {   // incase we have,  old -> ctf-chrome.ut2, new -> CTF-chrome.ut2
                        fMapName = StringReplace(fMapName, fFileTypes->Strings[i], fFileTypes->Strings[i], TReplaceFlags() << rfIgnoreCase); // only the very first 1 !!

                        //if(fMapName[fFileTypes->Strings[i].Length()+1]!='-') // make sure we have, old CTFchrome.ut2, new CTF-chrome.ut2
                        //    fMapName.Insert("-", fFileTypes->Strings[i].Length()+1);

                        fMapName[fFileTypes->Strings[i].Length()+1] = UpCase(fMapName[fFileTypes->Strings[i].Length()+1]); // incase we have, old -> CTF-chrome.ut2, new -> CTF-Chrome.ut2

                        if(Rename())
                        {
                            fTotal++;
                            fCount--;
                        }
                        
                        continue; // skips the checking below, no need to check
                    }
                }
            }

            if(i==tCount) // only if not found in the filters then come in here and do renaming
            {
               fMapName    = fFileTypes->Strings[i];
               fMapName[1] = UpCase(fMapName[1]);
               Rename();
            }
        }

        if(fOnFilesRenamed)
            Synchronize(OnFilesRenamedEvent);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMRenameThread::RenameInLog()
{
    if(fLog->FileIsInLogs(fFileList->Files[fNum]))
    {
        ShowMessage("Found it");         
    }
}
//---------------------------------------------------------------------------
bool __fastcall TMMRenameThread::Rename()
{
    if(fFileList->Files[fNum]->FileName.AnsiCompare(fMapName)) // only rename if different! case sencative ;)
    {
        // Look in logs and change to new file name as needed
        // this function is NOT Synchronized
        Synchronize(RenameInLog);

        if(RenameFile(fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName, fFileList->Files[fNum]->FileLocation + fMapName))
        {
            if(fOnFileRenamed)
                Synchronize(OnFileRenamedEvent);

            //fFileList->Delete(fNum); // remove from list, its been done already, no point in looping with it again
            fNum--;
            return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------
// Events
//---------------------------------------------------------------------------
void __fastcall TMMRenameThread::OnFilesRenamedEvent()
{
    fOnFilesRenamed(this);
}
//---------------------------------------------------------------------------
void __fastcall TMMRenameThread::OnFileRenamedEvent()
{
    fOnFileRenamed(this, fFileList->Files[fNum]->FileLocation + fFileList->Files[fNum]->FileName, fFileList->Files[fNum]->FileLocation + fMapName);
}
//---------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------
void __fastcall TMMRenameThread::GetFileTypes()
{
    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_CURRENT_USER;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + fGameTag + "\\Maps", false))
        Registry->GetValueNames(fFileTypes);

    Registry->CloseKey();
    delete Registry;
}
//---------------------------------------------------------------------------

