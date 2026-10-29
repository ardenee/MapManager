//---------------------------------------------------------------------------
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TMMDisplayFiles.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)                     
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TMMDisplayFiles::TMMDisplayFiles(TMMEventManager* pEventManager)//, TMMSettings* pXMLSettings)
          : TMMFiles()//TPersistent()
{
    SetEventManager(pEventManager);
}
//---------------------------------------------------------------------------
__fastcall TMMDisplayFiles::~TMMDisplayFiles()
{
    //FileList->Clear();
}
//----------------------------------------------------------------------------
// 12-04-2005 - 01:52 - Arden
// Load Icon for type of file : only does a xml settings search is the last icon
// loaded is different to the current one, else the last icon data is used.
// Speed inprovnment!!
//----------------------------------------------------------------------------
int  __fastcall TMMDisplayFiles::GetFileIcon(AnsiString FileExt)
{
	if(fLastIconInfo.Ext!=FileExt)
    {
		if(this->PEventManager->XMLSettings->Icons->ChildNodes->GetCount()>0)
        {
            _di_IXMLNodeList Items = this->PEventManager->XMLSettings->Icons->GetChildNodes();

            for(int i=0;i<Items->Count;i++)
            {
                _di_IXMLItemType Item = Items->Get(i);

                if(StringReplace(Item->GetText(), "\"", "", TReplaceFlags() << rfReplaceAll)==FileExt)
                {
                    _di_IXMLNodeList ItemAttList = Item->GetAttributeNodes();
                    _di_IXMLNode     Node        = ItemAttList->First();
                    fLastIconInfo.Num = StrToIntDef(Node->GetText(), fLastIconInfo.Num);
                    fLastIconInfo.Ext = FileExt;
                }
            }
        }
    }

	return fLastIconInfo.Num;
}
//----------------------------------------------------------------------------
void __fastcall TMMDisplayFiles::OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType)
{
    //FileList->Clear();
	FileList->Copy(pFileList);
	flistType = plistType;
}
//----------------------------------------------------------------------------
void __fastcall TMMDisplayFiles::MakeTreeViewDisplay(TVirtualStringTree* pVirtualStringTree, TMM_ItemTypes pType)
{
	pVirtualStringTree->BeginUpdate();
	pVirtualStringTree->Clear();
	pVirtualStringTree->Header->Columns->Clear();
	pVirtualStringTree->Header->Options >> hoAutoResize;

	switch(pType)
	{
		case MM_IT_Maps        :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 250;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Archives    :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 250;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Installed";
								col->Width = 60;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Cache       :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 200;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Folder";
								col->Width = 60;
								col->Alignment = taRightJustify;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Installed";
								col->Width = 60;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Real Name";
								col->Width = 150;
								pVirtualStringTree->Header->AutoSizeIndex = 6;
							}
							break;
		case MM_IT_Demos       :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 200;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_ScreenShots :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 200;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Textures    :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 200;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Music       :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 200;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Logs        :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 250;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Favorites   :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Server Name";
								col->Width = 250;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Server IP";
								col->Width = 100;
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Servers     :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Server Name";
								col->Width = 250;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Server IP";
								col->Width = 100;
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		case MM_IT_Buddies     :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Name";
								col->Width = 250;
								col = pVirtualStringTree->Header->Columns->Add();
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
		default               :
							{
								TVirtualTreeColumn* col;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "Num";
								col->Width = 80;
								//col->Options = col->Options << coSmartResize << coAutoSpring;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Name";
								col->Width = 250;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Size";
								col->Width = 100;
								col->Alignment = taRightJustify;
								col = pVirtualStringTree->Header->Columns->Add();
								col->Text = "File Date";
								col->Width = 140;
								col->Alignment = taRightJustify;//taLeftJustify, taRightJustify, taCenter
								pVirtualStringTree->Header->AutoSizeIndex = 1;
							}
							break;
	}

	pVirtualStringTree->Header->Options << hoAutoResize;
	pVirtualStringTree->EndUpdate();
}
//----------------------------------------------------------------------------
void __fastcall TMMDisplayFiles::CopyFileList(PFileList pFileList, TMM_FilesListType plistType)
{
	FileList->Clear();
	FileList->Copy(pFileList);
	flistType = plistType;
}
//----------------------------------------------------------------------------







