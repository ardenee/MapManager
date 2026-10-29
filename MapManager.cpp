//---------------------------------------------------------------------------
#include <vcl.h>
#include <StrUtils.hpp>
#include <Registry.hpp>
//---------------------------------------------------------------------------
#include "MapManager.h"
#include "SearchForm.h"
#include "FileView.h"
#include "SettingsForm.h"
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees.AncestorVCL"
#pragma link "VirtualTrees.BaseAncestorVCL"
#pragma link "VirtualTrees.BaseTree"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    MapManager1          = new TMapManager(this);
    ProgressBar1->Parent = StatusBar1;
    ProgressBar1->Width  = (StatusBar1->Panels->Items[0]->Width + StatusBar1->Panels->Items[0]->Width) - (StatusBar1->Width-15);
    //Form1->Caption = "Map Manager 1.5 - " + MapManager1->Files->GameTag;

	MapManager1->EventManager->OnGotFileList  = OnGotFileListEvent;
    MapManager1->EventManager->OnGotPicture   = OnGotPicEvent;
	MapManager1->EventManager->OnGotDataList  = OnGotDataListEvent;
	MapManager1->EventManager->OnFileAdded    = OnFileAddedEvent;
	//MapManager1->OnGotCacheFileList           = OnGotCacheFileListEvent;
	MapManager1->OnFileRenamed                = OnFileRenamedEvent;
	MapManager1->OnFilesRenamed               = OnFilesRenamedEvent;
	MapManager1->OnFileUninstalled            = OnFileUninstalledEvent;
	MapManager1->OnFilesUninstalled           = OnFilesUninstalledEvent;
	MapManager1->OnFileInstalled              = OnFileInstalledEvent;
	MapManager1->OnArchiveInstalled           = OnArchiveInstalledEvent;
	MapManager1->OnGotLogEntrys               = OnGotLogEntrysEvent;
	MapManager1->OnGotFileInfo                = OnGotFileInfoEvent;
	//MapManager1->DisplayFiles->OnGotFileList  = OnGotFileListEvent;
	// MapManager1->Files->OnFileDeleted        = OnFileDeletedEvent;
	// MapManager1->Files->OnFilesDeleted       = OnFilesDeletedEvent;
    // MapManager1->Files->OnSFileUninstalled   = OnSFileUninstalledEvent;

    VirtualStringTree1->NodeDataSize = sizeof(TMM_LogEntryData);
	PageControl1Change(NULL);
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
	//ListView1->Items->Count = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayMaps(PFileList FileList)
{
	VirtualStringTree1->BeginUpdate();
	VirtualStringTree1->Clear();
	VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
	unsigned int iCount              = MapManager1->Maps->FileList->Count;
	PVirtualNode Node;

	//ShowMessage("TForm1::DisplayMaps - " + IntToStr(__int64(iCount)));

	// add root nodes + copy from thread list to local list
	for(unsigned int i=0;i<iCount;++i)
	{
		PFileInfo ASrcFile = MapManager1->Maps->FileList->Files[i];
		Node = VirtualStringTree1->AddChild(NULL);


		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
	}

	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayArchives(PFileList FileList)
{
	VirtualStringTree1->BeginUpdate();
	VirtualStringTree1->Clear();
	VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
	unsigned int iCount              = MapManager1->Archives->FileList->Count;
	PVirtualNode Node;

	//ShowMessage("TForm1::DisplayMaps - " + IntToStr(__int64(iCount)));

    // add root nodes + copy from thread list to local list
    for(unsigned int i=0;i<iCount;++i)
    {
		PFileInfo ASrcFile = MapManager1->Archives->FileList->Files[i];
		Node = VirtualStringTree1->AddChild(NULL);

        PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Installed    = ASrcFile->Installed;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
	}

	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayCache(PFileList FileList)
{
	VirtualStringTree1->BeginUpdate();
	VirtualStringTree1->Clear();
	VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
	unsigned int iCount              = MapManager1->Cache->FileList->Count;
	PVirtualNode Node;

	//ShowMessage("TForm1::DisplayMaps - " + IntToStr(__int64(iCount)));

	// add root nodes + copy from thread list to local list
	for(unsigned int i=0;i<iCount;++i)
	{
		PFileInfo ASrcFile = MapManager1->Cache->FileList->Files[i];
		Node = VirtualStringTree1->AddChild(NULL);


		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Installed    = ASrcFile->Installed;
		//PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->RealName    = ASrcFile->RealName;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
	}

	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayMusic(PFileList FileList)
{
	VirtualStringTree1->BeginUpdate();
	VirtualStringTree1->Clear();
	VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
	unsigned int iCount              = MapManager1->Music->FileList->Count;
	PVirtualNode Node;

	//ShowMessage("TForm1::DisplayMaps - " + IntToStr(__int64(iCount)));

	// add root nodes + copy from thread list to local list
	for(unsigned int i=0;i<iCount;++i)
	{
		PFileInfo ASrcFile = MapManager1->Music->FileList->Files[i];
		Node = VirtualStringTree1->AddChild(NULL);


		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
	}

	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayDemos(PFileList FileList)
{
	VirtualStringTree1->BeginUpdate();
	VirtualStringTree1->Clear();
	VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
	unsigned int iCount              = MapManager1->Demos->FileList->Count;
	PVirtualNode Node;

	//ShowMessage("TForm1::DisplayMaps - " + IntToStr(__int64(iCount)));

	// add root nodes + copy from thread list to local list
	for(unsigned int i=0;i<iCount;++i)
	{
		PFileInfo ASrcFile = MapManager1->Demos->FileList->Files[i];
		Node = VirtualStringTree1->AddChild(NULL);


		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
	}

	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayTextures(PFileList FileList)
{
	VirtualStringTree1->BeginUpdate();
	VirtualStringTree1->Clear();
	VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
	unsigned int iCount              = MapManager1->Textures->FileList->Count;
	PVirtualNode Node;

	//ShowMessage("TForm1::DisplayMaps - " + IntToStr(__int64(iCount)));

	// add root nodes + copy from thread list to local list
	for(unsigned int i=0;i<iCount;++i)
	{
		PFileInfo ASrcFile = MapManager1->Textures->FileList->Files[i];
		Node = VirtualStringTree1->AddChild(NULL);


		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
	}

	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayScreenShots(PFileList FileList)
{
	VirtualStringTree1->BeginUpdate();
	VirtualStringTree1->Clear();
	VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
	unsigned int iCount              = MapManager1->ScreenShots->FileList->Count;
	PVirtualNode Node;

	//ShowMessage("TForm1::DisplayMaps - " + IntToStr(__int64(iCount)));

	// add root nodes + copy from thread list to local list
	for(unsigned int i=0;i<iCount;++i)
	{
		PFileInfo ASrcFile = MapManager1->ScreenShots->FileList->Files[i];
		Node = VirtualStringTree1->AddChild(NULL);


		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
		PTMM_FileInfo(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
		//PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
	}

	VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayArchiveLogs(PFileList FileList)
{
	unsigned int iCount = FileList->Count;
    VirtualStringTree1->BeginUpdate();
    PVirtualNode Node;

    // add root nodes + copy from thread list to local list
    for(unsigned int i=0;i<iCount;++i)
    {
        PFileInfo ASrcFile = FileList->Files[i];

        if(ASrcFile->BelongsTo==-1) // add all root nodes at start, dont add to the loglist!!
        {
			Node = VirtualStringTree1->AddChild(NULL);
			//PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
			//PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->CRC32        = ASrcFile->CRC32;
        }
		else // only add childern to the LogList, no root nodes!
        {
			/* 2-1-07
			PFileInfo ANewFile = MapManager1->LogList->AddFile();

			if(ANewFile)
            {
                ANewFile->FileName     = ASrcFile->FileName;
                ANewFile->FileSize     = ASrcFile->FileSize;
                ANewFile->FileDate     = ASrcFile->FileDate;
                ANewFile->FileLocation = ASrcFile->FileLocation;
                ANewFile->CRC32        = ASrcFile->CRC32;
			}
			*/
        }
    }

    // Add Children
	// 2-1-07
	// iCount = MapManager1->LogList->Count;
	iCount = 0;

    for(unsigned int i=0;i<iCount;i++)
    {
		//PFileInfo newFileData = MapManager1->LogList->Files[i];

		//if(newFileData)
		//{
		//    PVirtualNode RNode = VirtualStringTree1->GetFirst();

		//    while(RNode)
	   //     {
                   // Erro with the check, stayes the same?
                   /*
                if(PTMM_NodeData(VirtualStringTree1->GetNodeData(RNode))->Num == newFileData->BelongsTo)
                {
                    Node = VirtualStringTree1->AddChild(RNode);
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileName     = newFileData->FileName;
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileDate     = newFileData->FileDate;
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileSize     = newFileData->FileSize;
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(newFileData->FileLocation + newFileData->FileName);
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(newFileData->FileLocation + newFileData->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(newFileData->FileLocation + newFileData->FileName))) : AnsiString("");
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = newFileData->FileLocation;
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CRC32        = newFileData->CRC32;
                    MapManager1->LogList->Delete(i); // remove from log list to speed up adding logs
                    i--;
                    iCount--;
                    break;
                }
                */

			 //   RNode = VirtualStringTree1->GetNextSibling(RNode);
		   // }
		//}
    }

    // edit display to show percent of installed files from archive
    PVirtualNode RNode = VirtualStringTree1->GetFirst();

    while(RNode) // loop throught the root nodes
    {
        iCount = 0;
        Node   = VirtualStringTree1->GetFirstChild(RNode);
        
        while(Node) // loop throught the root nodes
        {
           // if(PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->Installed=="Yes")
           //     iCount++;

            Node = VirtualStringTree1->GetNextSibling(Node);
        }

        //if(iCount==0)
        //    PTMM_NodeData(VirtualStringTree1->GetNodeData(RNode))->Installed = "0%";
        //else if(iCount==RNode->ChildCount)
        //    PTMM_NodeData(VirtualStringTree1->GetNodeData(RNode))->Installed = "100%";
        //else
        //    PTMM_NodeData(VirtualStringTree1->GetNodeData(RNode))->Installed = IntToStr((100/RNode->ChildCount)*iCount) + "%";

        RNode = VirtualStringTree1->GetNextSibling(RNode);
    }     

    VirtualStringTree1->EndUpdate();
   // MapManager1->LogList->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplayCacheLogs(PFileList FileList)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DisplaySmartBackupLogs(PFileList FileList)
{
    unsigned int iCount = FileList->Count;
    VirtualStringTree1->BeginUpdate();
    PVirtualNode Node;

    // add root nodes + copy from thread list to local list
    for(unsigned int i=0;i<iCount;++i)
    {
        PFileInfo ASrcFile = FileList->Files[i];

        if(ASrcFile->BelongsTo==-1) // add all root nodes at start, dont add to the loglist!!
        {
			Node = VirtualStringTree1->AddChild(NULL);
            //PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->Num          = ASrcFile->Num;
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileName     = ASrcFile->FileName;
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileDate     = ASrcFile->FileDate;
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileSize     = ASrcFile->FileSize;
			//PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(ASrcFile->FileLocation + ASrcFile->FileName);
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(ASrcFile->FileLocation + ASrcFile->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(ASrcFile->FileLocation + ASrcFile->FileName))) : UnicodeString("");
			PTMM_LogEntryData(VirtualStringTree1->GetNodeData(Node))->FileLocation = ASrcFile->FileLocation;
        }
        else // only add childern to the LogList, no root nodes!
        {
		 /* 2-1-07
			PFileInfo ANewFile = MapManager1->LogList->AddFile();

            if(ANewFile)
            {
                ANewFile->FileName     = ASrcFile->FileName;
                ANewFile->FileSize     = ASrcFile->FileSize;
                ANewFile->FileDate     = ASrcFile->FileDate;
                ANewFile->FileLocation = ASrcFile->FileLocation;
			}

			*/
		}
		
    }

    // Add Children
	// 2-1-07
	//iCount = MapManager1->LogList->Count;
	iCount = 0;

    for(unsigned int i=0;i<iCount;i++)
    {
		//PFileInfo newFileData = MapManager1->LogList->Files[i];

		//if(newFileData)
	   // {
		//    PVirtualNode RNode = VirtualStringTree1->GetFirst();

	   //     while(RNode)
		//    {
            /*
                if(PTMM_NodeData(VirtualStringTree1->GetNodeData(RNode))->Num == newFileData->BelongsTo)
                {
                    Node = VirtualStringTree1->AddChild(RNode);
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileName     = newFileData->FileName;
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileDate     = newFileData->FileDate;
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileSize     = newFileData->FileSize;
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileSize    = MapManager1->Files->GetFileSize(newFileData->FileLocation + newFileData->FileName);
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->CFileDate    = FileExists(newFileData->FileLocation + newFileData->FileName) ? DateTimeToStr(FileDateToDateTime(FileAge(newFileData->FileLocation + newFileData->FileName))) : AnsiString("");
                    PTMM_NodeData(VirtualStringTree1->GetNodeData(Node))->FileLocation = newFileData->FileLocation;
                    MapManager1->LogList->Delete(i); // remove from log list to speed up adding logs
                    i--;
                    iCount--;
                    break;
                }
                */

			 //   RNode = VirtualStringTree1->GetNextSibling(RNode);
		   // }
		//}
    }

    VirtualStringTree1->EndUpdate();
	//MapManager1->LogList->Clear();
}
//---------------------------------------------------------------------------
// Events
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFileAddedEvent(TObject *Sender, AnsiString FileName)
{
    StatusBar1->Panels->Items[1]->Text= "Added File " + FileName + ".";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnGotLogEntrysEvent(TObject *Sender, PFileList pLogList)
{   // add new items to local loglist
    switch(ListBox1->ItemIndex)
    {
        case 1  : DisplayCacheLogs(pLogList);       break;
        case 2  : DisplaySmartBackupLogs(pLogList); break;
        default : DisplayArchiveLogs(pLogList);     break;
    }

	// 2-1-07
	//apManager1->LogList->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnGotFileInfoEvent(TObject *Sender, PFileList List)
{
/*
	Form3->ListView1->Items->BeginUpdate();
    MapManager1->MakeListViewTable(Form3->ListView1, 11);

    if(List->Count>0)
    {
        Form3->Label4->Caption = List->Files[0]->FileLocation + List->Files[0]->FileName;
        Form3->Label5->Caption = List->Files[0]->FileSize;
        Form3->Label6->Caption = List->Files[0]->FileDate;
        Form3->ListView1->Clear();

        for(int i=1;i<List->Count;i++)
        {
            Form3->ListView1->Items->Insert(Form3->ListView1->Items->Count);
            Form3->ListView1->Items->Item[Form3->ListView1->Items->Count-1]->Caption = IntToStr(Form3->ListView1->Items->Count);
            Form3->ListView1->Items->Item[Form3->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileName);
            Form3->ListView1->Items->Item[Form3->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileSize);
            Form3->ListView1->Items->Item[Form3->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileDate);
            Form3->ListView1->Items->Item[Form3->ListView1->Items->Count-1]->SubItems->Add("");
            Form3->ListView1->Items->Item[Form3->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileLocation);
        }
    }
    
    Form3->ListView1->Items->EndUpdate();
    */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFileRenamedEvent(TObject *Sender, AnsiString OldName, AnsiString NewName)
{
    StatusBar1->Panels->Items[1]->Text= "Renamed " + ExtractFileName(OldName) + " to " + ExtractFileName(NewName);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFilesRenamedEvent(TObject *Sender)
{
    //ListView1->Refresh();
    StatusBar1->Panels->Items[1]->Text= "Renameing Done.";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFileDeletedEvent(TObject *Sender, AnsiString DeletedFileName)
{
    for(int i=0;i<MapManager1->DisplayFiles->FileList->Count;i++)
    {
        if(!MapManager1->DisplayFiles->FileList->Files[i]->FileName.AnsiCompare(ExtractFileName(DeletedFileName)) &&
           !MapManager1->DisplayFiles->FileList->Files[i]->FileLocation.AnsiCompare(ExtractFilePath(DeletedFileName)))
        {   // append to file list!
			// 2-01-07
			//MapManager1->DisplayFiles->FileList->Delete(i);
            break;
        }
    }

	//ListView1->Items->Count            = MapManager1->DisplayFiles->FileList->Count; // reset!!
    StatusBar1->Panels->Items[1]->Text = ExtractFileName(DeletedFileName) + " Deleted.";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFilesDeletedEvent(TObject *Sender, PFileList List)
{
    //ListView1->Refresh();
    StatusBar1->Panels->Items[1]->Text= "Deleteing Done.";
    //StatusBar1->Panels->Items[0]->Text = StringReplace(GroupBox1->Caption, " ", "", TReplaceFlags() << rfReplaceAll) + " View.   [" + GetTotals(ListView1, 1) + " Bytes]";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFileUninstalledEvent(TObject *Sender, AnsiString FileName, AnsiString ArchiveName)
{
    for(int i=0;i<MapManager1->DisplayFiles->FileList->Count;i++)
    {
        if(!MapManager1->DisplayFiles->FileList->Files[i]->FileName.AnsiCompare(ExtractFileName(FileName)) &&
           !MapManager1->DisplayFiles->FileList->Files[i]->FileLocation.AnsiCompare(ExtractFilePath(FileName)))
        {   // append to file list!
			// 2-1-07
			//MapManager1->DisplayFiles->FileList->Delete(i);
            break;
        }
    }



    //ListView1->Items->Count = MapManager1->DisplayFiles->FileList->Count; // reset!!
    StatusBar1->Panels->Items[1]->Text = ExtractFileName(FileName) + " Uninstalled from " + ExtractFileName(ArchiveName);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnSFileUninstalledEvent(TObject *Sender, AnsiString FileName)
{
    for(int i=0;i<MapManager1->DisplayFiles->FileList->Count;i++)
    {
        if(!MapManager1->DisplayFiles->FileList->Files[i]->FileName.AnsiCompare(ExtractFileName(FileName)) &&
           !MapManager1->DisplayFiles->FileList->Files[i]->FileLocation.AnsiCompare(ExtractFilePath(FileName)))
        {   // append to file list!
			// 2-1-07
			// MapManager1->DisplayFiles->FileList->Delete(i);
            break;
        }
    }

	//ListView1->Items->Count = MapManager1->DisplayFiles->FileList->Count; // reset!!
    StatusBar1->Panels->Items[1]->Text = ExtractFileName(FileName) + " Uninstalled.";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFilesUninstalledEvent(TObject *Sender, PFileList List)
{
	//ListView1->Refresh();
    StatusBar1->Panels->Items[1]->Text= "Uninstalling Done.";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType)
{
    StatusBar1->Panels->Items[1]->Text = "Displaying...";

   // if(PageControl1->ActivePageIndex==1)
   // {
       // for(int i=0;i<FileList->Count;i++)
       // {
            // edit filter to accept ' in strings
		   // FileList->Files[i]->Installed = MapManager1->Files->FileIsInLogs(FileList->Files[i]) ? "Yes" : "No";
       // }
   // }
    //int u = MapManager1->DisplayFiles->FileList->Count;
	//int t = pFileList->Count;
	//int mapsc = MapManager1->Maps->FileList->Count;

	MapManager1->DisplayFiles->CopyFileList(pFileList, plistType); //FileList->Copy(FileList);
	//MapManager1->DisplayFiles->GetFileListType
	//ListView1->Items->Count            = MapManager1->DisplayFiles->FileList->Count;
	//StatusBar1->Panels->Items[1]->Text = IntToStr(ListView1->Items->Count) + " " + StringReplace(GroupBox1->Caption, " ", "", TReplaceFlags() << rfReplaceAll) + " Found.";
	//StatusBar1->Panels->Items[0]->Text = StringReplace(GroupBox1->Caption, " ", "", TReplaceFlags() << rfReplaceAll) + " View.   [" + GetTotals(ListView1, 1) + " Bytes]";

	switch(plistType)
	{
		case MM_FLT_Maps        : DisplayMaps(MapManager1->Maps->FileList);            break;
		case MM_FLT_Archives    : DisplayArchives(MapManager1->Archives->FileList);    break;
		case MM_FLT_Cache       : DisplayCache(MapManager1->Cache->FileList);       break;
		case MM_FLT_Demos       : DisplayDemos(MapManager1->Demos->FileList);       break;
		case MM_FLT_ScreenShots : DisplayScreenShots(MapManager1->ScreenShots->FileList); break;
		case MM_FLT_Textures    : DisplayTextures(MapManager1->Textures->FileList);    break;
		case MM_FLT_Music       : DisplayMusic(MapManager1->Music->FileList);       break;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnGotCacheFileListEvent(TObject *Sender, PFileList List)
{
    StatusBar1->Panels->Items[1]->Text = "Displaying...";

    if(PageControl1->ActivePageIndex==2)
    {
		//for(int i=0;i<List->Count;i++)
		//   List->Files[i]->Installed = MapManager1->Cache-> Files->FileIsInLogs(List->Files[i]) ? "Yes" : "No";

    }

	//ListView1->Items->Count = MapManager1->DisplayFiles->FileList->Count;
	//StatusBar1->Panels->Items[0]->Text = "Cache View.   [" + GetTotals(ListView1, 1) + " Bytes]";
    //StatusBar1->Panels->Items[1]->Text = IntToStr(ListView1->Items->Count) + " Cache Files Found.";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnArchiveInstalledEvent(TObject *Sender, AnsiString Archive)
{
    StatusBar1->Panels->Items[1]->Text = ExtractFileName(Archive) + " Installed.";
   // ListView1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnFileInstalledEvent(TObject *Sender, AnsiString ArchiveName, AnsiString FileName)
{
    StatusBar1->Panels->Items[1]->Text = ExtractFileName(FileName) + " Installed from " + ExtractFileName(ArchiveName);
}
//---------------------------------------------------------------------------
// Done - Rename All Files
//---------------------------------------------------------------------------
void __fastcall TForm1::AutoRenameAllFiles1Click(TObject *Sender)
{
    switch(PageControl1->ActivePageIndex)
    {
        case 0 : MapManager1->Maps->RenameFiles(MapManager1->DisplayFiles->FileList);     break;
        case 1 : MapManager1->Archives->RenameFiles(MapManager1->DisplayFiles->FileList); break;
    }
}
//---------------------------------------------------------------------------
// Done - Rename Selected Files
//--------------------------------------------------------------------------
void __fastcall TForm1::AutoRenameSelectedFiles1Click(TObject *Sender)
{
/*
    PFileList renList  = new TMMFileList;
    TItemStates selected = TItemStates() << isSelected;
    TListItem *Item      = ListView1->Selected;

    while(Item)
    {
        PFileInfo fileData = renList->AddFile();

        if(fileData)
        {
            fileData->FileName     = Item->SubItems->Strings[0];
			fileData->FileSize     = Item->SubItems->Strings[1].ToIntDef(0);
            fileData->FileDate     = Item->SubItems->Strings[2];
            fileData->FileLocation = Item->SubItems->Strings[4];
        }

        Item = ListView1->GetNextItem(Item, sdAll, selected);
    }


    switch(PageControl1->ActivePageIndex)
    {
        case 0 : MapManager1->Maps->RenameFiles    (renList); break;
        case 1 : MapManager1->Archives->RenameFiles(renList); break;
    }

    //MapManager1->DisplayFiles->RenameFiles(renList, MapManager1->Settings->GameTag);

	//renList->Clear(); // clear b4 free
	delete renList;
    */
}
//---------------------------------------------------------------------------
// Done - Manually Rename File
//---------------------------------------------------------------------------
void __fastcall TForm1::ManuallyRenameFile1Click(TObject *Sender)
{
/*
    PFileInfo tmpFile = MapManager1->DisplayFiles->FileList->Files[ListView1->Selected->Index]; // get seleted file

    if(FileExists(tmpFile->FileLocation + tmpFile->FileName))
    {
        AnsiString NewName = InputBox("Rename File", "Current Name : " + tmpFile->FileName, tmpFile->FileName);

        if(!NewName.IsEmpty() && NewName.AnsiCompare(tmpFile->FileName)) // case senceative check!
        {
            if(MapManager1->DisplayFiles->ManuallyRenameFile(tmpFile->FileLocation + tmpFile->FileName, tmpFile->FileLocation + NewName))
            {
                tmpFile->FileName = NewName;
                StatusBar1->Panels->Items[1]->Text = "File was Renamed.";
                ListView1->Refresh();
            }
        }
        else
            StatusBar1->Panels->Items[1]->Text = "Map was not Renamed.";
    }
    else
		StatusBar1->Panels->Items[0]->Text = "File not Found.";
        */
}
//---------------------------------------------------------------------------
// Done - Delete Selected Files
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteSelectedFiles1Click(TObject *Sender)
{
/*
    int Button = Application->MessageBox(L"Are you sure you want to Delete the selected Files ?", L"Warning", MB_YESNO|MB_ICONSTOP);

    if(Button==IDYES) //check to see if map is required for log uninstall (first map in log string)
    {
        PFileList delList  = new TMMFileList;
        TItemStates selected = TItemStates() << isSelected;
        TListItem* Item      = ListView1->Selected;

        while(Item)
        {
            PFileInfo fileData = delList->AddFile();

            if(fileData)
            {
                fileData->FileName     = Item->SubItems->Strings[0];
				fileData->FileSize     = Item->SubItems->Strings[1].ToIntDef(0);
                fileData->FileDate     = Item->SubItems->Strings[2];
                fileData->FileLocation = Item->SubItems->Strings[4];
            }

            Item = ListView1->GetNextItem(Item, sdAll, selected);
        }

        switch(PageControl1->ActivePageIndex)
        {
            case 0 : MapManager1->Maps->DeleteFiles(delList);         break;
            case 1 : MapManager1->Archives->DeleteFiles(delList); break;
        }

        delete delList;
    }
    else
		StatusBar1->Panels->Items[1]->Text = "Deleted Cancled.";
		*/
}
//---------------------------------------------------------------------------
// Done - Find Files
//---------------------------------------------------------------------------
void __fastcall TForm1::FindFiles1Click(TObject *Sender)
{   // Find Map
/*
    AnsiString SearchStr = InputBox("Find File", "File Name : eg SkyLine", "");
    MapManager1->MakeListViewTable(Form2->ListView1, 12);

    if(!SearchStr.IsEmpty())
    {
        PFileList List = new TMMFileList;

		for(int col=0;col<ListView1->Items->Count;col++)
        {
            PFileInfo fileData = List->AddFile();

            if(fileData)
            {
                fileData->CRC32        = StrToIntDef(ListView1->Items->Item[col]->SubItems->Strings[3], 0);
                fileData->FileName     = ListView1->Items->Item[col]->SubItems->Strings[0];
				fileData->FileSize     = ListView1->Items->Item[col]->SubItems->Strings[1].ToIntDef(0);
                fileData->FileDate     = ListView1->Items->Item[col]->SubItems->Strings[2];
                fileData->FileLocation = ListView1->Items->Item[col]->SubItems->Strings[4];
                //fileData->Installed    = ListView1->Items->Item[col]->SubItems->Strings[3];
            }
        }

        MapManager1->DisplayFiles->FindFile(List, SearchStr);

        Form2->AddFiles(List);

        //Form2->ListView1->Items->BeginUpdate();
        //Form2->ListView1->Clear();

        //for(int i=0;i<List->Count;i++)
        //{
        //    Form2->ListView1->Items->Insert(Form2->ListView1->Items->Count);
        //    Form2->ListView1->Items->Item[Form2->ListView1->Items->Count-1]->Caption = IntToStr(Form2->ListView1->Items->Count);
        //    Form2->ListView1->Items->Item[Form2->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileName);
        //    Form2->ListView1->Items->Item[Form2->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileSize);
        //    Form2->ListView1->Items->Item[Form2->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileDate);
        //    Form2->ListView1->Items->Item[Form2->ListView1->Items->Count-1]->SubItems->Add("");
        //    Form2->ListView1->Items->Item[Form2->ListView1->Items->Count-1]->SubItems->Add(List->Files[i]->FileLocation);
        //}

        //Form2->ListView1->Items->EndUpdate();

        delete List; 
        Form2->Label3->Caption = SearchStr;
        Form2->Label4->Caption = Form2->ListView1->Items->Count;
        Form2->ShowModal();
	}
    */
}
//---------------------------------------------------------------------------
// Done - Get FileInfo
//---------------------------------------------------------------------------
void __fastcall TForm1::GetMapInfo1Click(TObject *Sender)
{
/*
    TItemStates selected = TItemStates() << isSelected;
    TListItem* Item      = ListView1->Selected;

    if(Item)
    {
        MapManager1->Maps->GetFileData(Item->SubItems->Strings[4] + Item->SubItems->Strings[0]);
        Form3->ShowModal();
	}
    */
}
//---------------------------------------------------------------------------
// Dong - Install All Files
//---------------------------------------------------------------------------
void __fastcall TForm1::InstallAllArchives1Click(TObject *Sender)
{
    MapManager1->Archives->Install(MapManager1->DisplayFiles->FileList);
}
//---------------------------------------------------------------------------
// Done - Install Selected Files
//---------------------------------------------------------------------------
void __fastcall TForm1::InstallSelectedArchives1Click(TObject *Sender)
{
/*
    PFileList insList    = new TMMFileList;
    TItemStates selected = TItemStates() << isSelected;
    TListItem *Item      = ListView1->Selected;

    while(Item)
    {
        PFileInfo fileData = insList->AddFile();

        if(fileData)
        {
            fileData->FileName     = Item->SubItems->Strings[0];
			fileData->FileSize     = Item->SubItems->Strings[1].ToIntDef(0);
            fileData->FileDate     = Item->SubItems->Strings[2];
            fileData->FileLocation = Item->SubItems->Strings[4];
        }

        Item = ListView1->GetNextItem(Item, sdAll, selected);
    }

    MapManager1->Archives->Install(insList);
	delete insList;
    */
}
//---------------------------------------------------------------------------
// Done - Stop Installing Files
//---------------------------------------------------------------------------
void __fastcall TForm1::StopInstalling1Click(TObject *Sender)
{
    MapManager1->Archives->StopInstalling();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ViewArchive1Click(TObject *Sender)
{
/*
    TItemStates selected = TItemStates() << isSelected;
    TListItem*  Item     = ListView1->Selected;

    if(Item)
    {
        MapManager1->Archives->GetFileData(Item->SubItems->Strings[4] + Item->SubItems->Strings[0]);
        Form3->ShowModal();
	}
    */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PageControl1Change(TObject *Sender)
{
	Image1->Picture             = NULL;
    GroupBox1->Tag              = PageControl1->ActivePageIndex;
    PageControl1->Tag           = PageControl1->ActivePageIndex;
	ListBox1->Items->BeginUpdate();
    ListBox1->Clear();
	ListBox1->Tag                = -1; // always reset when setting new data!!!!!!
    //MapManager1->MakeListViewTable(ListView1, PageControl1->Tag);
    GroupBox1->Caption           = "  " + MapManager1->GetDisplayFilters(ListBox1->Items, PageControl1->ActivePageIndex) + "  ";
	// 2-1-07
	// MapManager1->DisplayFiles->FileList->Clear();
	StatusBar1->Panels->Items[0]->Text = GroupBox1->Caption.Trim() + " View.";
   // StatusBar1->Panels->Items[1]->Text = IntToStr(ListBox1->Items->Count) + " " + GroupBox1->Caption.Trim() + " Found.";



	switch(PageControl1->ActivePageIndex)
    {
		case  0 : { //Maps
                    MapManager1->Maps->LoadFilesType = MM_LFT_FileType; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
					MapManager1->Maps->GetFileTypes();
					MapManager1->Maps->GetFileFilters();
					MapManager1->Maps->GetFileDiscriptions();
					MapManager1->Maps->GetFiles();
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Maps);
					ListBox1->Items->AddStrings(MapManager1->Maps->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Maps");
                    break;
				  }
		case  1 : { //Archives
					MapManager1->Archives->LoadFilesType = MM_LFT_FileType; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
                    MapManager1->Archives->GetFileTypes();
                    MapManager1->Archives->GetFileFilters();
                    MapManager1->Archives->GetFileDiscriptions();
					MapManager1->Archives->GetFiles();
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Archives);
                    ListBox1->Items->AddStrings(MapManager1->Archives->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Archives");
					break;
                  }
		case  2 : { //Cache
					MapManager1->Cache->LoadFilesType = MM_LFT_FileType;
					MapManager1->Cache->GetFileTypes();
					MapManager1->Cache->GetFileFilters();
                    MapManager1->Cache->GetFileDiscriptions();
					MapManager1->Cache->GetFiles();


					ShowMessage(MapManager1->Cache->FileTypes->Text);
					ShowMessage(MapManager1->Cache->FileFilters->Text);
					ShowMessage(MapManager1->Cache->FileDiscriptions->Text);

					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Cache);
					ListBox1->Items->AddStrings(MapManager1->Cache->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Files");
                    break;
				  }
		case  3 : { // case 3: 3 Servers
					//MapManager1->Servers->LoadFilesType = MM_LFT_FileType;
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Servers);
					GroupBox1->Caption = "  Buddies  ";
					//ListBox1->Items->AddStrings(MapManager1->Servers->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Buddies");
					break;
					}
		case  4 : { // case 3: 3 Favorites
					//MapManager1->Favorites->LoadFilesType = MM_LFT_FileType;
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Favorites);
					GroupBox1->Caption = "  Buddies  ";
					//ListBox1->Items->AddStrings(MapManager1->Favorites->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Favorites");
					break;
					}
		case  5 : {  //logs
					//MapManager1->Logs->LoadFilesType = MM_LFT_FileType;
					//VirtualStringTree1->NodeDataSize = sizeof(TMM_FileInfo);
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Logs);
					//ListBox1->Items->AddStrings(MapManager1->Logs->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Logs");
					break;
				  }
		case  6 : { //music
					MapManager1->Music->LoadFilesType = MM_LFT_FileType; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
					MapManager1->Music->GetFileTypes();
					MapManager1->Music->GetFileFilters();
					MapManager1->Music->GetFileDiscriptions();
					MapManager1->Music->GetFiles();
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Music);
					StatusBar1->Panels->Items[1]->Text = IntToStr(ListBox1->Items->Count) + " " + GroupBox1->Caption.Trim() + " Files Found.";
					ListBox1->Items->AddStrings(MapManager1->Music->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Music");
					break;
				  }
		case  7 : { //teztures
					MapManager1->Textures->LoadFilesType = MM_LFT_FileType; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
					MapManager1->Textures->GetFileTypes();
					MapManager1->Textures->GetFileFilters();
					MapManager1->Textures->GetFileDiscriptions();
					MapManager1->Textures->GetFiles();
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Textures);
                    StatusBar1->Panels->Items[1]->Text = IntToStr(ListBox1->Items->Count) + " " + GroupBox1->Caption.Trim() + " Files Found.";
					ListBox1->Items->AddStrings(MapManager1->Textures->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Textures");
					break;
                  }
		case  8 : { //demos
					MapManager1->Demos->LoadFilesType = MM_LFT_FileType; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
					MapManager1->Demos->GetFileTypes();
					MapManager1->Demos->GetFileFilters();
					MapManager1->Demos->GetFileDiscriptions();
					MapManager1->Demos->GetFiles();
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_Demos);
					StatusBar1->Panels->Items[1]->Text = IntToStr(ListBox1->Items->Count) + " " + GroupBox1->Caption.Trim() + " Files Found.";
					ListBox1->Items->AddStrings(MapManager1->Demos->FileDiscriptions);
					ListBox1->Items->Insert(0, "All Demos");
					break;
                  }
		case  9 : { //screenshots
					MapManager1->ScreenShots->LoadFilesType = MM_LFT_FileType; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
					MapManager1->ScreenShots->GetFileTypes();
					MapManager1->ScreenShots->GetFileFilters();
					MapManager1->ScreenShots->GetFileDiscriptions();
					MapManager1->ScreenShots->GetFiles();
					MapManager1->DisplayFiles->MakeTreeViewDisplay(VirtualStringTree1, MM_IT_ScreenShots);
                    StatusBar1->Panels->Items[1]->Text = IntToStr(ListBox1->Items->Count) + " " + GroupBox1->Caption.Trim() + " Files Found.";
                    ListBox1->Items->AddStrings(MapManager1->ScreenShots->FileDiscriptions);
					ListBox1->Items->Insert(0, "All ScreenShots");
					break;
                  }
	}

	ListBox1->Items->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
	if(ListBox1->ItemIndex!=-1 && ListBox1->Tag!=ListBox1->ItemIndex)
    {
        ListBox1->Hint = ListBox1->Items->Strings[ListBox1->ItemIndex];
        ListBox1->Tag  = ListBox1->ItemIndex;
		//ListView1->Items->BeginUpdate();
		//ListView1->Items->Clear();
		//ListView1->Items->Count = 0;
        // 2-1-07
			// MapManager1->DisplayFiles->FileList->Clear();
       // ListView1->Items->Count = 0;

        if(GroupBox1->Tag==0)// Maps
        {
            MapManager1->Maps->LoadFilesType = MM_LFT_UserDefined; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
            MapManager1->Maps->GetFileTypes();
            MapManager1->Maps->FileFilters->Clear();

            if(ListBox1->ItemIndex<=0)
                MapManager1->Maps->GetFileFilters();
            else
                MapManager1->Maps->FileFilters->Add(MapManager1->Maps->GetFilterFromDiscription(ListBox1->Items->Strings[ListBox1->ItemIndex]));

            MapManager1->Maps->GetFiles();
        }
        else if(GroupBox1->Tag==1)// Archives
        {
            MapManager1->Archives->FileFilters->Clear();
            MapManager1->Archives->FileTypes->Clear();
            MapManager1->Archives->LoadFilesType = MM_LFT_UserDefined; //MM_LFT_FileType

            if(ListBox1->ItemIndex<=0)
                MapManager1->Archives->GetFileTypes();
            else
                MapManager1->Archives->FileTypes->Add(MapManager1->Archives->GetFileType(ListBox1->Items->Strings[ListBox1->ItemIndex]));

            MapManager1->Archives->GetFiles();
        }
		else if(GroupBox1->Tag==2)// Cache
        {
            MapManager1->Cache->FileFilters->Clear();
            MapManager1->Cache->FileTypes->Clear();
            MapManager1->Cache->LoadFilesType = MM_LFT_UserDefined; //MM_LFT_FileType

            if(ListBox1->ItemIndex<=0)
                MapManager1->Cache->GetFileTypes();
            else
            {
                TStrings* tmpFilters = new TStringList();
                MapManager1->Cache->GetAllFileTypesFor(tmpFilters, ListBox1->Items->Strings[ListBox1->ItemIndex]); 
                MapManager1->Cache->FileTypes->AddStrings(tmpFilters);
                delete tmpFilters;
            }

            MapManager1->Cache->GetFiles();
        }
        else if(GroupBox1->Tag==5)// Logs
        {
            //if(MapManager1->Files->LogFile.AnsiCompareIC(ListBox1->Items->Strings[ListBox1->ItemIndex] + MapManager1->Files->GameTag + ".xml"))
            //{
            //    MapManager1->Files->UpdateLogs();
            //    MapManager1->Files->LoadFromFile(ListBox1->Items->Strings[ListBox1->ItemIndex] + MapManager1->Files->GameTag + ".xml");
            //}

            VirtualStringTree1->Clear();
		   // MapManager1->Files->GetLogEntrys();
            StatusBar1->Panels->Items[1]->Text = IntToStr((__int64)VirtualStringTree1->RootNodeCount) + " Logs Found.";
        }
		else if(GroupBox1->Tag==6)// Music
		{
			MapManager1->Music->LoadFilesType = MM_LFT_UserDefined; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
			MapManager1->Music->GetFileTypes();
			MapManager1->Music->FileFilters->Clear();

			if(ListBox1->ItemIndex<=0)
				MapManager1->Music->GetFileFilters();
			else
				MapManager1->Music->FileFilters->Add(MapManager1->Music->GetFilterFromDiscription(ListBox1->Items->Strings[ListBox1->ItemIndex]));

			MapManager1->Music->GetFiles();
		}
		else if(GroupBox1->Tag==7)// Textures
		{
			MapManager1->Textures->LoadFilesType = MM_LFT_UserDefined; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
			MapManager1->Textures->GetFileTypes();
			MapManager1->Textures->FileFilters->Clear();

			if(ListBox1->ItemIndex<=0)
				MapManager1->Textures->GetFileFilters();
			else
				MapManager1->Textures->FileFilters->Add(MapManager1->Textures->GetFilterFromDiscription(ListBox1->Items->Strings[ListBox1->ItemIndex]));

			MapManager1->Textures->GetFiles();
		}
		else if(GroupBox1->Tag==8)// ScreenShots
		{
			MapManager1->Demos->LoadFilesType = MM_LFT_UserDefined; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
			MapManager1->Demos->GetFileTypes();
			MapManager1->Demos->FileFilters->Clear();

			if(ListBox1->ItemIndex<=0)
				MapManager1->Demos->GetFileFilters();
			else
				MapManager1->Demos->FileFilters->Add(MapManager1->Demos->GetFilterFromDiscription(ListBox1->Items->Strings[ListBox1->ItemIndex]));

			MapManager1->Demos->GetFiles();
		}
		else if(GroupBox1->Tag==9)// ScreenShots
		{
			MapManager1->ScreenShots->LoadFilesType = MM_LFT_UserDefined; // MM_LFT_Filter   MM_LFT_FileType   MM_LFT_None   MM_LFT_FilterAndFileType
			MapManager1->ScreenShots->GetFileTypes();
			MapManager1->ScreenShots->FileFilters->Clear();

			if(ListBox1->ItemIndex<=0)
				MapManager1->ScreenShots->GetFileFilters();
			else
				MapManager1->ScreenShots->FileFilters->Add(MapManager1->ScreenShots->GetFilterFromDiscription(ListBox1->Items->Strings[ListBox1->ItemIndex]));

			MapManager1->ScreenShots->GetFiles();
		}

		//ListView1->Items->EndUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StatusBar1DrawPanel(TStatusBar *StatusBar, TStatusPanel *Panel, const TRect &Rect)
{
    if(Panel->Index==ProgressBar1->Tag)
    {
        ProgressBar1->Top    = Rect.Top-1 ;
        ProgressBar1->Left   = Rect.Left-1;
        ProgressBar1->Width  = StatusBar->Panels->Items[ProgressBar1->Tag]->Width;
        ProgressBar1->Height = Rect.Bottom-Rect.Top+1;
    }    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UninstallSelectedFiles1Click(TObject *Sender)
{   // Uninstall Maps
/*
    int Button = Application->MessageBox(L"Are you sure you want to Uninstall the selected Files(s) ?", L"Warning", MB_YESNO|MB_ICONSTOP);

    if(Button==IDYES)
    {
        PFileList uniList  = new TMMFileList;
        TItemStates selected = TItemStates() << isSelected;
		TListItem *Item      = ListView1->Selected;

        while(Item)
        {
            PFileInfo fileData = uniList->AddFile();

            if(fileData)
            {
                fileData->FileName     = Item->SubItems->Strings[0];
                fileData->FileSize     = Item->SubItems->Strings[1].ToIntDef(0);
                fileData->FileDate     = Item->SubItems->Strings[2];
                fileData->FileLocation = Item->SubItems->Strings[4];
            }

            Item = ListView1->GetNextItem(Item, sdAll, selected);
        }


        switch(PageControl1->ActivePageIndex)
        {
            case 0 : MapManager1->Maps->UninstallFiles(uniList);         break;
            case 1 : MapManager1->Archives->UninstallFiles(uniList); break;
        }

        delete uniList;
    }
    else
		StatusBar1->Panels->Items[1]->Text="Uninstall Cancled.";
	*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PlayMap1Click(TObject *Sender)
{   
    //if(ListView1->ItemIndex!=-1)
       // MapManager1->Files->OpenFile(ListView1->Items->Item[ListView1->ItemIndex]->SubItems->Strings[0]);
}
//---------------------------------------------------------------------------  
void __fastcall TForm1::FormResize(TObject *Sender)
{
    StatusBar1->Panels->Items[0]->Width = ((StatusBar1->Width-739)/3)+350;
    StatusBar1->Panels->Items[1]->Width = ((StatusBar1->Width-739)/3)+300;
    StatusBar1->Panels->Items[2]->Width = ((StatusBar1->Width-739)/3)+74;
    ProgressBar1->Width = StatusBar1->Panels->Items[2]->Width;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    delete MapManager1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PopupMenu1Popup(TObject *Sender)
{
    if(PopupMenu1->Items->Count>0)
    {   // Clear the PopUpMenu
        for(int index=PopupMenu1->Items->Count-1;index>=0;index--)
            PopupMenu1->Items->Delete(index);
    }

    if(PageControl1->Tag==0) // Maps
    {
        TMenuItem *Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Auto &Rename All Maps";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = AutoRenameAllFiles1Click;      // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Auto Rename &Selected Maps";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = AutoRenameSelectedFiles1Click; // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Manually Rename Map";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = ManuallyRenameFile1Click;      // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Uninstall Selected Maps";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = UninstallSelectedFiles1Click;  // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Delete Selected Maps";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = DeleteSelectedFiles1Click;     // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Find Map";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = FindFiles1Click;               // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Play Maps";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = PlayMap1Click;                 // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&View Info";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = GetMapInfo1Click;              // done
    }
    else if(PageControl1->Tag==1) // Archives
    {
        TMenuItem *Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Auto &Rename All Archives";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = AutoRenameAllFiles1Click;      // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Auto Rename &Selected Archives";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = AutoRenameSelectedFiles1Click; // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Manually Rename Archives";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = ManuallyRenameFile1Click;      // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Install &All Archives";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = InstallAllArchives1Click;     // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Install &Selected Archives";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = InstallSelectedArchives1Click; // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Uninstall Selected Archives";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = UninstallSelectedFiles1Click;  // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Delete S&elected Archives";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = DeleteSelectedFiles1Click;     // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Stop Installing Archives";
        PopupMenu1->Items->Add(Item);
         Item->OnClick = StopInstalling1Click;         // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&View Info";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = ViewArchive1Click;             // done

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Find Archive";
        PopupMenu1->Items->Add(Item);
        Item->OnClick = FindFiles1Click;               // done
    }
    else if(PageControl1->Tag==2) // Cache
    {
        TMenuItem *Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Convert &All";
        PopupMenu1->Items->Add(Item);
        // Item->OnClick = ConvertAllFiles1Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Convert &Selected";
        PopupMenu1->Items->Add(Item);
        // Item->OnClick = ConvertFile1Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Delete All";
        PopupMenu1->Items->Add(Item);
        // Item->OnClick = DeleteallFiles1Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Delete S&elected";
        PopupMenu1->Items->Add(Item);
        // Item->OnClick = DeleteFile1Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        //Item = new TMenuItem(PopupMenu1);
        //Item->Caption = "&Edit File Info";
        //PopupMenu1->Items->Add(Item);
        // Item->OnClick = EditInfo1Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Reload Cache Files";
        PopupMenu1->Items->Add(Item);
        // Item->OnClick = ReloadFiles2Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Remove Files Already Converted";
        PopupMenu1->Items->Add(Item);
        // Item->OnClick = RemoveFilesAlreadyConverted1Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Remove Partial Downloads";
        PopupMenu1->Items->Add(Item);
        // Item->OnClick = RemovePartialDownloads1Click;
    }
    else if(PageControl1->Tag==3) // Server
    {
        TMenuItem *Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Add Server";
        PopupMenu1->Items->Add(Item);
     //   Item->OnClick = AddServer;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Remove Server";
        PopupMenu1->Items->Add(Item);
     //   Item->OnClick = DelServer;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Edit Server";
        PopupMenu1->Items->Add(Item);
      //  Item->OnClick = EditServer;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Start Querys";
        PopupMenu1->Items->Add(Item);
        //Item->OnClick = StartServerQuery;
        
        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "Stop &Querys";
        PopupMenu1->Items->Add(Item);
        //Item->OnClick = StopServerQuery;
    }
    else if(PageControl1->Tag==4) // Favorites
    {
        TMenuItem *Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Add Buddie";
        PopupMenu1->Items->Add(Item);
     //   Item->OnClick = AddBuddie;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Remove Buddie";
        PopupMenu1->Items->Add(Item);
      //  Item->OnClick = DelBuddie;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Edit Buddie";
        PopupMenu1->Items->Add(Item);
    //    Item->OnClick = EditBuddie;
    }    
    else if(PageControl1->Tag==5) // Logs
    {
        TMenuItem *Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Uninstall File";
        PopupMenu1->Items->Add(Item);
        //Item->OnClick = InstallallZips1Click;

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "-";
        PopupMenu1->Items->Add(Item);

        Item = new TMenuItem(PopupMenu1);
        Item->Caption = "&Clear Log";
        PopupMenu1->Items->Add(Item);
        //Item->OnClick = InstallZip1Click;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnGotPicEvent(TObject *Sender, TPicture* Picture)
{
	Image1->Picture = Picture;
    //ShowMessage("in");
}
//---------------------------------------------------------------------------
AnsiString __fastcall TForm1::GetTotals(TListView *TmpListView, int SubCol)
{
    __int64 Total = 0; // for big ass numbers! lol

    for(int col=0;col<TmpListView->Items->Count;col++)
        Total += StrToIntDef(StringReplace(TmpListView->Items->Item[col]->SubItems->Strings[SubCol], ",", "", TReplaceFlags() << rfReplaceAll), 0);

    return FormatFloat("#,##0", Total);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1DblClick(TObject *Sender)
{
    // open a new form displaying the picture with info ;)
}
//---------------------------------------------------------------------------
/*
void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType, WideString &CellText)
{
	switch(Column)
	{
		case 0 : CellText = PTMM_NodeData(Sender->GetNodeData(Node))->FileName;     break;
		case 1 : CellText = PTMM_NodeData(Sender->GetNodeData(Node))->FileSize;     break;
		case 2 : CellText = PTMM_NodeData(Sender->GetNodeData(Node))->CFileSize;    break;
		case 3 : CellText = PTMM_NodeData(Sender->GetNodeData(Node))->FileDate;     break;
		case 4 : CellText = PTMM_NodeData(Sender->GetNodeData(Node))->CFileDate;    break;
		// 2-1-07
			// case 6 : CellText = PTMM_NodeData(Sender->GetNodeData(Node))->CRC32;        break;
		//case 6 : CellText = NodeData(Sender->GetNodeData(Node))->FileLocation; break;
		//case 7 : CellText = NodeData(Sender->GetNodeData(Node))->Num;          break;
	}
}
*/
//---------------------------------------------------------------------------
void __fastcall TForm1::ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected)
{
	if(PageControl1->ActivePageIndex==0 && Selected)
		MapManager1->Maps->GetPicture(Item->SubItems->Strings[4] + Item->SubItems->Strings[0]);
}
//---------------------------------------------------------------------------
/*
void __fastcall TForm1::VirtualStringTree1GetImageIndex(TBaseVirtualTree *Sender, PVirtualNode Node, TVTImageKind Kind, TColumnIndex Column, bool &Ghosted, int &ImageIndex);
{
    if(Column==0)
    {
        TRegistry *Registry = new TRegistry;
        Registry->RootKey   = HKEY_CURRENT_USER;

        //if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\Icons\\" + MapManager1->Files->GameTag + "\\", false))
        //{
        //    ImageIndex = StrToIntDef(Registry->ReadString(ExtractFileExt(PTMM_NodeData(Sender->GetNodeData(Node))->FileName)), 10);
        //    Registry->CloseKey();
        //}

        delete Registry;
    }
}
*/
//---------------------------------------------------------------------------
void __fastcall TForm1::ListView1Data(TObject *Sender, TListItem *Item)
{
/*
	if(ListView1->VisibleRowCount<ListView1->Items->Count)
    {
        int NewWidth = 0;

        for(int i=0;i<ListView1->Columns->Count;i++)
            NewWidth += ListView1->Columns->Items[i]->Width;

        if((NewWidth+7)>ListView1->Width)
            ListView1->Columns->Items[1]->Width -= 16; 
    }
        
    Item->Caption = (Item->Index+1);
    //PFileInfo fileData = MapManager1->EventManager->FileList->Files[Item->Index];
    PFileInfo fileData = MapManager1->DisplayFiles->FileList->Files[Item->Index];

    if(fileData)
    {
		Item->SubItems->Append(fileData->FileName);
        Item->SubItems->Append(fileData->FileSize);
        Item->SubItems->Append(fileData->FileDate);

        //if(fileData->Installed.IsEmpty())  // only check for items were viewing ;) should be fastrer loading
		  //  fileData->Installed = MapManager1->Files->FileIsInLogs(fileData) ? "Yes" : "No";

		Item->SubItems->Append(fileData->Installed); // display the is installed here instead?
		Item->SubItems->Append(fileData->FileLocation);

		  //if cachs add additional info
		if(PageControl1->ActivePageIndex==2)
			Item->SubItems->Append(MapManager1->Cache->GetINIFileName(fileData->FileName));

        Item->SubItemImages[0] = MapManager1->Maps->GetFileIcon(ExtractFileExt(fileData->FileName));
        Item->Indent = -1;
	}
    */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::VirtualStringTree1BeforeItemErase(TBaseVirtualTree *Sender, TCanvas *TargetCanvas, PVirtualNode Node,
      TRect &ItemRect, TColor &ItemColor, TItemEraseAction &EraseAction)
{
    //if(MapManager1->Files->ColorCodeText)
    //{
   //     ItemColor   = (Node->Parent==Sender->RootNode) ? (TColor) 0x00F3F3F3 : ItemColor;
   //     EraseAction = (Node->Parent==Sender->RootNode) ? eaColor : eaDefault;
    //}
}
//--------------------------------------------------------------------------- 
void __fastcall TForm1::VirtualStringTree1PaintText(TBaseVirtualTree *Sender, const TCanvas *TargetCanvas, PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType)
{
   // if(MapManager1->Files->ColorCodeText)
   // {
     //   if(Node->Parent!=Sender->RootNode)
     //       TargetCanvas->Font->Color = (TColor) 0x00006400; // Green

       // if(PTMM_NodeData(Sender->GetNodeData(Node))->Installed == "No")
         //   TargetCanvas->Font->Color = clMaroon;

        //if(PTMM_NodeData(Sender->GetNodeData(Node))->Installed == "100%" && Node->Parent==Sender->RootNode || NodeData(Sender->GetNodeData(Node))->Installed == "Yes" && Node->Parent==Sender->RootNode)
        //    TargetCanvas->Font->Color = (TColor) 0x00A00000; // blue
   // }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListView1AdvancedCustomDrawItem(TCustomListView *Sender, TListItem *Item, TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw)
{
   // if(MapManager1->Files->ColorCodeText)
    //    if(!Item->SubItems->Strings[3].AnsiCompareIC("No")) // installed??
     //       Sender->Canvas->Font->Color = clMaroon;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
/*    Image1->Picture->Bitmap = NULL;
    Image1->Tag++;

    if(Image1->Tag>=ImageList1->Count)
        Image1->Tag = 0;

    ImageList1->GetBitmap(Image1->Tag, Image1->Picture->Bitmap);
    */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1Click(TObject *Sender)
{
   // Timer1Timer(NULL);
}
//---------------------------------------------------------------------------   
void __fastcall TForm1::ListView1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
/*
    TListItem* item = ListView1->GetItemAt(X, Y);

    if(item)
        ListView1->Hint = "FileName : "     + item->SubItems->Strings[0] + "\n\r" +
                          "FileLocation : " + item->SubItems->Strings[4] + "\n\r" +
                          "File Size : "    + item->SubItems->Strings[1] + "\n\r" +
                          "File Date : "    + item->SubItems->Strings[2];
    else
		ListView1->Hint = "";
        */
}
//---------------------------------------------------------------------------  
void __fastcall TForm1::Settings1Click(TObject *Sender)
{
    Form4->ShowModal();    
}
//---------------------------------------------------------------------------  

void __fastcall TForm1::PopupMenu2Popup(TObject *Sender)
{
    if(PopupMenu2->Items->Count>0)
    {   // Clear the PopUpMenu
        for(int index=PopupMenu2->Items->Count-1;index>=0;index--)
            PopupMenu2->Items->Delete(index);
    }

    if(PageControl1->Tag==0) // Maps
    {
        TMenuItem *Item = new TMenuItem(PopupMenu2);
        Item->Caption = "&Add Map Type";
        PopupMenu2->Items->Add(Item);
        Item->OnClick = AddMapType1Click;      // done

        Item = new TMenuItem(PopupMenu2);
        Item->Caption = "&Remove Map Type";
        PopupMenu2->Items->Add(Item);
        Item->OnClick = RemoveMapType1Click; // done

        Item = new TMenuItem(PopupMenu2);
        Item->Caption = "&Edit Map Type";
        PopupMenu2->Items->Add(Item);
        Item->OnClick = EditMapType1Click;      // done
    }
}
//---------------------------------------------------------------------------
// Map PopUpMenyType
void __fastcall TForm1::AddMapType1Click(TObject *Sender)
{
    AnsiString NewMapType = InputBox("Add Map Type", "Map Type : eg CTF", "");
    AnsiString NewMapDiscription = InputBox("Add Discription", "Discription : eg Capture the Flag", "");
    MapManager1->Settings->AddMapsMenu(NewMapType, NewMapDiscription);
    MapManager1->MakeListMenu(ListBox1->Items, 0);
    ListBox1->Items->Insert(0, "All Maps");
    ListBox1->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RemoveMapType1Click(TObject *Sender)
{
    if(ListBox1->ItemIndex!=0)
    {
        int Button = Application->MessageBox(L"Are you sure you want to Remove the Map Type?", L"Warning", MB_YESNO|MB_ICONSTOP);

        if(Button==IDYES)
        {
            MapManager1->Settings->DelMapsMenu(MapManager1->Settings->GetMapFilter(ListBox1->Items->Strings[ListBox1->ItemIndex]) , ListBox1->Items->Strings[ListBox1->ItemIndex]);
            MapManager1->MakeListMenu(ListBox1->Items, 0);
            ListBox1->Items->Insert(0, "All Maps");
            ListBox1->ItemIndex = 0;
            ListBox1->Tag = -1;
            ListBox1Click(NULL);
        }
    }
    else
        ShowMessage("This is not a valid Map Type, and therefore can not be removed.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditMapType1Click(TObject *Sender)
{
    if(ListBox1->ItemIndex!=0)
    {
        int selected = ListBox1->ItemIndex;
        AnsiString oldMapType        = MapManager1->Settings->GetMapFilter(ListBox1->Items->Strings[ListBox1->ItemIndex]);
        AnsiString oldMapDiscription = ListBox1->Items->Strings[ListBox1->ItemIndex];
        AnsiString NewMapType        = InputBox("Edit Map Type", "Map Type : eg CTF", oldMapType);
        AnsiString NewMapDiscription = InputBox("Edit Discription", "Discription : eg Capture the Flag", oldMapDiscription);

        MapManager1->Settings->EditMapsMenu(oldMapType , oldMapDiscription, NewMapType, NewMapDiscription);
        MapManager1->MakeListMenu(ListBox1->Items, 0);
        ListBox1->Items->Insert(0, "All Maps");
        ListBox1->ItemIndex = selected;
        ListBox1->Tag = -1;
        ListBox1Click(NULL);
    }
    else
        ShowMessage("This is not a valid Map Type, and therefore can not be removed.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnGotDataListEvent(TObject *Sender, TStrings* pMapData)
{
    Form3->AddData(pMapData);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{

	switch(PageControl1->ActivePageIndex)
    {
		case 0 : { //Maps

			switch(Column)
			{
				case 0 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;     break;
				case 1 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileName;     break;
				case 2 : CellText = FormatFloat("#,##0", PTMM_FileInfo(Sender->GetNodeData(Node))->FileSize);     break;
				//case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->CFileSize;    break;
				case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileDate;     break;
				//case 5 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->CFileDate;    break;
				// 2-1-07
					// case 6 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->CRC32;        break;
				//case 6 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileLocation; break;
				//case 7 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;          break;
			}
		}
		case 1 : { //Archived

			switch(Column)
			{
				case 0 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;     break;
				case 1 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileName;     break;
				case 2 : CellText = FormatFloat("#,##0", PTMM_FileInfo(Sender->GetNodeData(Node))->FileSize);     break;
				case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileDate;     break;
				case 4 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Installed;     break;
			}
		}
		case 2 : { //Cache

			switch(Column)
			{
				case 0 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;     break;
				case 1 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileName;     break;
				case 2 : CellText = FormatFloat("#,##0", PTMM_FileInfo(Sender->GetNodeData(Node))->FileSize);     break;
				case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileDate;     break;
				case 4 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileLocation;     break;
				case 5 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Installed;     break;
				case 6 : CellText = MapManager1->Cache->GetINIFileName(PTMM_FileInfo(Sender->GetNodeData(Node))->FileName);     break;
			}
		}

		case 6 : { //Music

			switch(Column)
			{
				case 0 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;     break;
				case 1 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileName;     break;
				case 2 : CellText = FormatFloat("#,##0", PTMM_FileInfo(Sender->GetNodeData(Node))->FileSize);     break;
				case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileDate;     break;
				//case 4 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileLocation;     break;
				//case 5 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Installed;     break;
				//case 6 : CellText = MapManager1->Cache->GetINIFileName(PTMM_FileInfo(Sender->GetNodeData(Node))->FileName);     break;
			}
		}
		case 7 : { //Textures

			switch(Column)
			{
				case 0 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;     break;
				case 1 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileName;     break;
				case 2 : CellText = FormatFloat("#,##0", PTMM_FileInfo(Sender->GetNodeData(Node))->FileSize);     break;
				case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileDate;     break;
				//case 4 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileLocation;     break;
				//case 5 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Installed;     break;
				//case 6 : CellText = MapManager1->Cache->GetINIFileName(PTMM_FileInfo(Sender->GetNodeData(Node))->FileName);     break;
			}
		}
		case 8 : { //Demos

			switch(Column)
			{
				case 0 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;     break;
				case 1 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileName;     break;
				case 2 : CellText = FormatFloat("#,##0", PTMM_FileInfo(Sender->GetNodeData(Node))->FileSize);     break;
				case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileDate;     break;
				//case 4 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileLocation;     break;
				//case 5 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Installed;     break;
				//case 6 : CellText = MapManager1->Cache->GetINIFileName(PTMM_FileInfo(Sender->GetNodeData(Node))->FileName);     break;
			}
		}
		case 9 : { //ScreenShots

			switch(Column)
			{
				case 0 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Num;     break;
				case 1 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileName;     break;
				case 2 : CellText = FormatFloat("#,##0", PTMM_FileInfo(Sender->GetNodeData(Node))->FileSize);     break;
				case 3 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileDate;     break;
				//case 4 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->FileLocation;     break;
				//case 5 : CellText = PTMM_FileInfo(Sender->GetNodeData(Node))->Installed;     break;
				//case 6 : CellText = MapManager1->Cache->GetINIFileName(PTMM_FileInfo(Sender->GetNodeData(Node))->FileName);     break;
			}
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1GetImageIndex(TBaseVirtualTree *Sender,
		  PVirtualNode Node, TVTImageKind Kind, TColumnIndex Column,
		  bool &Ghosted, TImageIndex &ImageIndex)
{
	if(Column == 1 && Kind == ikNormal)
	{
   		 // shouyld be generic get ext function, not just in Maps
		ImageIndex = MapManager1->Maps->GetFileIcon(ExtractFileExt(PTMM_FileInfo(Sender->GetNodeData(Node))->FileName));
	}
}
//---------------------------------------------------------------------------

