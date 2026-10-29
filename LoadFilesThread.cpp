#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "MapManager.h"
#include "OtherFunctions.h"
#include "LoadFilesThread.h"
#include "RenameFilesThread.h"

#pragma package(smart_init)
//#pragma link "ztvBase"
//#pragma link "ztvRegister"
//#pragma link "ztvZipCheck"
//#pragma link "ztvZipTV"
//#pragma link "ztvbase"
//---------------------------------------------------------------------------
__fastcall LoadFilesThread::LoadFilesThread(bool CreateSuspended, TListView *ListView, int FileType, TStrings* FileTypes, TStrings* FiltersTypes, AnsiString Location)
    : TThread(CreateSuspended)
{
    TmpFileTypes    = new TStringList;
    TmpNames        = new TStringList;
    Filters         = new TStringList;
    FilesList       = new TStringList; // file list
    //ZipTV1          = new TZipTV(NULL);
    TmpListView     = ListView;
    LoadType        = FileType;
    Folder          = Location;
    Total           = 0;
    TmpFileTypes->AddStrings(FileTypes);
    Filters->AddStrings(FiltersTypes);
    FreeOnTerminate = true;
    Resume();
}
//---------------------------------------------------------------------------

void __fastcall LoadFilesThread::Execute()
{
    Synchronize(CheckUsage);

    if(Terminated == false)
    {
        //TStrings* FilesList = new TStringList; // file list
        GetFiles(FilesList, Folder, true);     // load all files, and in subfolders
        Total = FilesList->Count;
        Synchronize(ProgressSet);

        // keep check between Threads work to see if the user has tried to stop the thread
        ProgressMessage = "Verfying Files ";
       // if(TmpProgramData->InstancesOfLoadFilesThread==1) // are they maps (look to file Ext)
            VerfyFiles(FilesList);
            
        ProgressMessage = "Filtering Files ";
       // if(TmpProgramData->InstancesOfLoadFilesThread==1) // Start of file name(CTF,BR,DOM, etc.. or is a valid archive)
            FilterFiles(FilesList);

        ProgressMessage = "Displaying Files ";
       // if(TmpProgramData->InstancesOfLoadFilesThread==1)
            Synchronize(DisplayMaps); // Maps

        //delete FilesList;
    }

    if(Terminated == false)
        Synchronize(FreeFlag);
}
//---------------------------------------------------------------------------
void __fastcall LoadFilesThread::CheckUsage()
{
    // The former switch(false) was an inactive placeholder, not a real
    // thread-use check. Keep the existing progress reset without dead code.
    Form1->ProgressBar1->Position = 0;
}
//---------------------------------------------------------------------------
void __fastcall LoadFilesThread::GetFiles(TStrings* Files, AnsiString Location, bool SubFolders)
{
    TSearchRec sr;
    Location = IncludeTrailingPathDelimiter(Location);
    TStrings* DirList = new TStringList;

    if(FindFirst(Location + "*.*", faAnyFile, sr) == 0)
    {
        do
        {
            if((sr.Name != ".") && (sr.Name != "..") && ((sr.Attr & faDirectory) == 0))
				Files->Add(Location + sr.Name + '\t' + sr.TimeStamp.DateTimeString() + '\t' + IntToStr(sr.Size));
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
                        Files->Add(DirList->Strings[a] + sr.Name + '\t' + sr.TimeStamp + '\t' + IntToStr(sr.Size));

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


//---------------------------------------------------------------------------
void __fastcall LoadFilesThread::ProgressPoint()
{
    Form1->ProgressBar1->Position = SubTotal;
}
//---------------------------------------------------------------------------
void __fastcall LoadFilesThread::ProgressSet()
{
    Form1->ProgressBar1->Max = Total * 3;
}
//---------------------------------------------------------------------------

void __fastcall LoadFilesThread::ProgressUpdate()
{
    Form1->ProgressBar1->Position = Form1->ProgressBar1->Position + 1;
    Form1->StatusBar1->Panels->Items[1]->Text = ProgressMessage + "[" + IntToStr(Form1->ProgressBar1->Position) + "] of [" + IntToStr(Form1->ProgressBar1->Max) + "]";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall LoadFilesThread::VerfyFiles(TStrings* FilesList)
{
    TmpNames->Clear();
    TmpNames->AddStrings(FilesList);
    GetFileNames(TmpNames); // get file names from display strings
    bool Delete = true;

    for(int i=0;i<TmpNames->Count;i++) // loop throught files
    {
        for(int x=0;x<TmpFileTypes->Count;x++) // loop through file types
        {
			if(!ExtractFileExt(TmpNames->Strings[i]).Compare(TmpFileTypes->Strings[x]) && !TmpFileTypes->Strings[x].IsEmpty())
            {
                Delete = false;
                break; // only breaks out of filetype loop !!
            }
            else
                Delete = true;
        }

        if(Delete)
        {
            TmpNames->Delete(i);
            FilesList->Delete(i);
            i--;
        }
        
        Synchronize(ProgressUpdate);
    }

    SubTotal = Total;
    Synchronize(ProgressPoint);
}
//---------------------------------------------------------------------------

void __fastcall LoadFilesThread::GetFileNames(TStrings* TmpFiles)
{   // gets the name of all files, delete date + size after the '/t'
    for(int i=0;i<TmpFiles->Count;i++)
    {
        for(int x=1;x<TmpFiles->Strings[i].Length();x++)
        {
            if(TmpFiles->Strings[i][x]=='\t')
            {
                TmpFiles->Strings[i] = TmpFiles->Strings[i].Delete(x, TmpFiles->Strings[i].Length());
                break;
            }
        }
    }
}
//---------------------------------------------------------------------------

void __fastcall LoadFilesThread::Test()
{
    ShowMessage(NUM);
}
//---------------------------------------------------------------------------

void __fastcall LoadFilesThread::FilterFiles(TStrings* FilesList)
{
    bool Delete = false;

    if(LoadType==0) // if(LoadType==0 && TmpProgramData->FilterRequired)
    {
        for(int i=0;i<TmpNames->Count;i++) // loop throught files
        {
            for(int x=0;x<Filters->Count;x++) // loop throught files
            {
                if(!StrLIComp(ExtractFileName(TmpNames->Strings[i]).c_str(), Filters->Strings[x].c_str(), Filters->Strings[x].Length()) && !Filters->Strings[x].IsEmpty())
                {
                    Delete = false;
                    break; // only breaks out of filetype loop !!
                }
                else
                    Delete = true;
            }

            if(Delete)
            {
                TmpNames->Delete(i);
                FilesList->Delete(i);
                i--;
            }

            Delete = false; // always reset after loop
            Synchronize(ProgressUpdate);
        }
    }
    else if(LoadType==1)  // else if(LoadType==1 && TmpProgramData->ValidateArchives)
    {
        for(int i=0;i<TmpNames->Count;i++) // loop throught files
		{
		/*
            ZipTV1->ArchiveFile = TmpNames->Strings[i];

            if(!ZipTV1->IsArcDecompressable(ZipTV1->ArcType))
            {
                TmpNames->Delete(i);
                FilesList->Delete(i);
                i--;
			}
            */

            Synchronize(ProgressUpdate);
        }
    }

    SubTotal = Total * 2;
    Synchronize(ProgressPoint);
}
//---------------------------------------------------------------------------
bool LoadFilesThread::ValidMapDisplayString(AnsiString TmpString)
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

//---------------------------------------------------------------------------
// function improved, only adds valid strings !
//---------------------------------------------------------------------------
void __fastcall LoadFilesThread::DisplayMaps()
{
   // if(LoadType==0)
   //     DisplayMapsOnFrom(TmpListView, FilesList, false, FilesList->Count, TmpProgramData->CurrentLogFile, TmpProgramData->GameTag);
   // else
   //     DisplayMapsOnFrom(TmpListView, FilesList, true, FilesList->Count, TmpProgramData->CurrentLogFile, TmpProgramData->GameTag);

  /*
    StringValues TmpValues;
    TIniFile* pif = new TIniFile(TmpProgramData->CurrentLogFile);

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
                if(pif->ValueExists(TmpProgramData->GameTag, LogSafeNameToFile(ExtractFileName(TmpValues.Name)) + '\t' + TmpValues.Date + '\t' +TmpValues.Size))
                    TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add("Yes"); 
                else
                    TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add("No"); // Default Value
            }
            else
                TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add(""); // Default Value

            TmpListView->Items->Item[TmpListView->Items->Count-1]->SubItems->Add(ExtractFilePath(TmpValues.Name));
        }
        Synchronize(ProgressUpdate);
    }

    delete pif;
    SubTotal = Total * 3;
    Synchronize(ProgressPoint);
  */
}
//---------------------------------------------------------------------------

void __fastcall LoadFilesThread::FreeFlag()
{
   // TmpProgramData->LoadFilesFlag              = false; //free the flag
   // TmpProgramData->InstancesOfLoadFilesThread = 0;
    Form1->ProgressBar1->Position              = 0;

   // Form1->StatusBar1->Panels->Items[0]->Text = Form1->PageControl1->ActivePage->Caption +" View.   [" + GetTotals(Form1->ListView1, 1) + " Bytes]";
    Form1->StatusBar1->Panels->Items[1]->Text = IntToStr(TmpListView->Items->Count) + " " + Form1->PageControl1->ActivePage->Caption +" Found.";

    Form1->PageControl1->OnChange = Form1->PageControl1Change;
    Form1->ListBox1->OnClick = Form1->ListBox1Click;
    
    if(Form1->PageControl1->ActivePageIndex!=Form1->PageControl1->Tag) 
        Form1->PageControl1Change(NULL);
    else if(Form1->ListBox1->ItemIndex!=Form1->ListBox1->Tag)
        Form1->ListBox1Click(NULL);
}
//---------------------------------------------------------------------------

__fastcall LoadFilesThread::~LoadFilesThread()
{   // free up used memory for thread ;)
    delete TmpFileTypes;
    delete TmpNames;
    delete Filters;
    //delete ZipTV1;
    delete FilesList;
}
//---------------------------------------------------------------------------

AnsiString __fastcall LoadFilesThread::LogSafeNameToFile(AnsiString FileName) // change all [ to < , input into file
{
    FileName = StringReplace(FileName, "[", "<", TReplaceFlags() << rfIgnoreCase << rfReplaceAll);
    FileName = StringReplace(FileName, "]", ">", TReplaceFlags() << rfIgnoreCase << rfReplaceAll);
    return FileName;
}
//---------------------------------------------------------------------------

TMM_FileInfo __fastcall LoadFilesThread::GetDataFromDisplayStr(AnsiString MainString)
{
    TMM_FileInfo Values;

	Values.FileName = MainString;
	Values.FileName.SetLength(AnsiPos('\t', MainString)-1);// -1 to get rid of the TAB '\t'
    MainString.Delete(1, AnsiPos('\t', MainString));

	Values.FileDate = MainString;
	Values.FileDate.SetLength(AnsiPos('\t', MainString)-1);// -1 to get rid of the TAB '\t'
    MainString.Delete(1, AnsiPos('\t', MainString));

    Values.FileSize  = MainString.ToIntDef(0);

    return Values;
}
//---------------------------------------------------------------------------




