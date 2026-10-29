//---------------------------------------------------------------------------
#pragma hdrstop
#include "TMMEventManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TMMEventManager::TMMEventManager(TMMSettings* pXMLSettings, TMMLogs* pXMLLogs)
          : TPersistent()
{
    fXMLSettings = pXMLSettings;
    fXMLLogs     = pXMLLogs;
    fFileList    = new TMMFileList;
    fListType    =  MM_FLT_Maps;  // default Maps
}
//---------------------------------------------------------------------------
__fastcall TMMEventManager::~TMMEventManager()
{
   // fFileList->Clear();
    delete fFileList;
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnGotFileListEvent(TObject* Sender, PFileList pFileList, TMM_FilesListType pdisplayType)
{
	if(fListType == pdisplayType) // only update list if were updating the right view
    {
		//fFileList->Clear();
		fFileList->Copy(pFileList); // should be move, not copied // ShowMessage(pFileList->Files[0]->FileName);
		fListType = pdisplayType;

		//int t = fFileList->Count;
		//int tt = pFileList->Count;

        //ShowMessage("TMMEventManager::OnGotFileListEvent - 2");

        if(fOnGotFileList)
            fOnGotFileList(this, fFileList, fListType);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnFileAddedEvent(TObject* Sender, AnsiString fileName)
{
    if(fOnFileAdded)
        fOnFileAdded(this, fileName);
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnFilesRenamedEvent(TObject* Sender)
{
    if(fOnFilesRenamed)
        fOnFilesRenamed(this);
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnFileRenamedEvent(TObject* Sender, AnsiString oldName, AnsiString newName)
{
    if(fOnFileRenamed)
        fOnFileRenamed(this, oldName, newName);
    else
        ShowMessage("No");
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnFileInstalledEvent(TObject* Sender, AnsiString fileName, AnsiString archiveName)
{
    if(fOnFileInstalled)
        fOnFileInstalled(this, fileName, archiveName);
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnArchiveInstalledEvent(TObject* Sender, AnsiString archive)
{
    if(fOnArchiveInstalled)
        fOnArchiveInstalled(this, archive);
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnGotPicEventEvent(TObject* Sender, TPicture* Picture)
{
    if(fOnGotPicture)
        fOnGotPicture(this, Picture);
}
//---------------------------------------------------------------------------
void __fastcall TMMEventManager::OnGotDataListEvent(TObject* Sender, TStrings* Data)
{
    if(fOnGotDataList)
        fOnGotDataList(this, Data);
}
//---------------------------------------------------------------------------


