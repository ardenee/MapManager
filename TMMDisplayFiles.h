//---------------------------------------------------------------------------

#ifndef TMMDisplayFilesH
#define TMMDisplayFilesH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------
#include "TMMFiles.h"
#include "VirtualTrees.hpp"
//---------------------------------------------------------------------------
class TMMDisplayFiles : public TMMFiles//TPersistent
{
private:
	TMM_FileIconType  fLastIconInfo;
	TMM_FilesListType flistType;
public:
    __fastcall TMMDisplayFiles(TMMEventManager* pEventManager);//, TMMSettings* pXMLSettings);
    __fastcall ~TMMDisplayFiles();
    int  __fastcall GetFileIcon(AnsiString FileExt); // virtual in TFiles
    void __fastcall OnGotFileListEvent(TObject *Sender, PFileList pFileList, TMM_FilesListType plistType);
	void __fastcall CopyFileList(PFileList pFileList, TMM_FilesListType plistType);
	void __fastcall MakeTreeViewDisplay(TVirtualStringTree* pVirtualStringTree, TMM_ItemTypes pType);
__published:
	__property TMM_FilesListType GetFileListType = {read=flistType};
};
#endif
