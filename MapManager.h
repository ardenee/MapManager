//---------------------------------------------------------------------------
#ifndef MapManagerH
#define MapManagerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include "TMapManager.h"
#include "VirtualTrees.hpp"
#include "TMMFileList.h"
#include <ImgList.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <System.ImageList.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Data.DbxSqlite.hpp>
#include <Datasnap.DBClient.hpp>
#include "VirtualTrees.AncestorVcl.hpp"
#include "VirtualTrees.BaseAncestorVcl.hpp"
#include "VirtualTrees.BaseTree.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *StatusBar1;
    TListBox *ListBox1;
    TImage *Image1;
    TPageControl *PageControl1;
    TProgressBar *ProgressBar1;
    TMainMenu *MainMenu1;
    TPopupMenu *PopupMenu1;
    TPopupMenu *PopupMenu2;
    TMenuItem *File1;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel4;
    TSplitter *Splitter1;
    TSplitter *Splitter2;
    TGroupBox *GroupBox1;
    TGroupBox *GroupBox2;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TTabSheet *TabSheet3;
    TTabSheet *TabSheet4;
    TTabSheet *TabSheet5;
    TTabSheet *TabSheet6;
    TVirtualStringTree *VirtualStringTree1;
    TImageList *ImageList1;
    TTimer *Timer1;
    TImageList *ImageList2;
    TTabSheet *TabSheet7;
    TTabSheet *TabSheet8;
    TMenuItem *Program1;
    TMenuItem *Settings1;
    TTabSheet *TabSheet9;
	TTabSheet *TabSheet10;
	TClientDataSet *ClientDataSet1;
	TSQLDataSet *SQLDataSet1;
    void __fastcall PageControl1Change(TObject *Sender);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall StatusBar1DrawPanel(TStatusBar *StatusBar, TStatusPanel *Panel, const TRect &Rect);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    // main pop up menu
    void __fastcall AutoRenameAllFiles1Click(TObject *Sender);
    void __fastcall AutoRenameSelectedFiles1Click(TObject *Sender);
    void __fastcall ManuallyRenameFile1Click(TObject *Sender);
    void __fastcall UninstallSelectedFiles1Click(TObject *Sender);
    void __fastcall DeleteSelectedFiles1Click(TObject *Sender);
    void __fastcall FindFiles1Click(TObject *Sender);
    void __fastcall PlayMap1Click(TObject *Sender);
    void __fastcall InstallAllArchives1Click(TObject *Sender);
    void __fastcall InstallSelectedArchives1Click(TObject *Sender);
    void __fastcall ViewArchive1Click(TObject *Sender);
    void __fastcall GetMapInfo1Click(TObject *Sender);
    void __fastcall StopInstalling1Click(TObject *Sender);
    // Map PopUpMenyType
    void __fastcall AddMapType1Click(TObject *Sender);
    void __fastcall RemoveMapType1Click(TObject *Sender);
    void __fastcall EditMapType1Click(TObject *Sender);
    // event function calls
    void __fastcall PopupMenu1Popup(TObject *Sender);
    void __fastcall Image1DblClick(TObject *Sender);
    //31-08-17 // void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType, WideString &CellText);
    void __fastcall ListView1SelectItem(TObject *Sender, TListItem *Item, bool Selected);  
    void __fastcall OnGotFileListEvent(TObject *Sender, PFileList FileList, TMM_FilesListType plistType);
    void __fastcall OnFileRenamedEvent(TObject *Sender, AnsiString OldName, AnsiString NewName);
    void __fastcall OnFilesRenamedEvent(TObject *Sender);
    void __fastcall OnFileDeletedEvent(TObject *Sender, AnsiString DeletedFileName);
    void __fastcall OnFilesDeletedEvent(TObject *Sender, PFileList List);
    void __fastcall OnFileInstalledEvent(TObject *Sender, AnsiString ArchiveName, AnsiString FileName);
    void __fastcall OnArchiveInstalledEvent(TObject *Sender, AnsiString Archive);
    void __fastcall OnFileUninstalledEvent(TObject *Sender, AnsiString FileName, AnsiString ArchiveName);
    void __fastcall OnFilesUninstalledEvent(TObject *Sender, PFileList List);
    void __fastcall OnGotCacheFileListEvent(TObject *Sender, PFileList List);
    void __fastcall OnGotFileInfoEvent(TObject *Sender, PFileList List);
    void __fastcall OnGotPicEvent(TObject *Sender, TPicture* Picture);
    void __fastcall OnGotLogEntrysEvent(TObject *Sender, PFileList pLogList);
    void __fastcall OnFileAddedEvent(TObject *Sender, AnsiString FileName);
    void __fastcall OnSFileUninstalledEvent(TObject *Sender, AnsiString FileName);
    //void __fastcall VirtualStringTree1GetImageIndex(TBaseVirtualTree *Sender, PVirtualNode Node, TVTImageKind Kind, TColumnIndex Column, bool &Ghosted, int &ImageIndex);
    void __fastcall ListView1Data(TObject *Sender, TListItem *Item);
    void __fastcall VirtualStringTree1BeforeItemErase(TBaseVirtualTree *Sender, TCanvas *TargetCanvas, PVirtualNode Node, TRect &ItemRect, TColor &ItemColor, TItemEraseAction &EraseAction);
    void __fastcall VirtualStringTree1PaintText(TBaseVirtualTree *Sender, const TCanvas *TargetCanvas, PVirtualNode Node, TColumnIndex Column, TVSTTextType TextType);
    void __fastcall ListView1AdvancedCustomDrawItem(TCustomListView *Sender, TListItem *Item, TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Image1Click(TObject *Sender);
    void __fastcall ListView1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void __fastcall Settings1Click(TObject *Sender);
    void __fastcall PopupMenu2Popup(TObject *Sender);
    void __fastcall OnGotDataListEvent(TObject *Sender, TStrings* pMapData);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall VirtualStringTree1GetImageIndex(TBaseVirtualTree *Sender, PVirtualNode Node,
          TVTImageKind Kind, TColumnIndex Column, bool &Ghosted, TImageIndex &ImageIndex);


private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
    TMapManager* MapManager1;
    AnsiString __fastcall GetTotals(TListView *TmpListView, int SubCol);
	void __fastcall DisplayArchiveLogs(PFileList FileList);

	void __fastcall DisplayMaps(PFileList FileList);
	void __fastcall DisplayArchives(PFileList FileList);
	void __fastcall DisplayCache(PFileList FileList);
	void __fastcall DisplayMusic(PFileList FileList);
	void __fastcall DisplayDemos(PFileList FileList);
    void __fastcall DisplayTextures(PFileList FileList);
	void __fastcall DisplayScreenShots(PFileList FileList);

    void __fastcall DisplayCacheLogs(PFileList FileList);
    void __fastcall DisplaySmartBackupLogs(PFileList FileList);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

