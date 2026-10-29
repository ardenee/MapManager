//---------------------------------------------------------------------------
#ifndef TMMEventManagerH
#define TMMEventManagerH
#include <vcl.h>
#include "TMMFileList.h"
#include "TMMSettings.h"
#include "TMMLogs.h"
//---------------------------------------------------------------------------
class TMMEventManager : public TPersistent
{     
    TMMSettings*        fXMLSettings;
    TMMLogs*            fXMLLogs;
    TMM_FilesListType   fListType;
    TMMFileListEvent    fOnGotFileList;
	TMMFileRenEvent     fOnFileRenamed;
	TMMFilesRenEvent    fOnFilesRenamed;
    TMMStrEvent         fOnFileAdded;
    TMMFileInsEvent     fOnFileInstalled;
    TMMArchiveInsEvent  fOnArchiveInstalled;
    TMMGotPicEvent      fOnGotPicture;
    TMMGotDataListEvent fOnGotDataList;
public:
	PFileList           fFileList;
         __fastcall TMMEventManager(TMMSettings* pXMLSettings, TMMLogs* pXMLLogs);
         __fastcall ~TMMEventManager();
    void __fastcall OnGotFileListEvent      (TObject* Sender, PFileList  pFileList, TMM_FilesListType pdisplayType);
    void __fastcall OnFileAddedEvent        (TObject* Sender, AnsiString fileName);
    void __fastcall OnFilesRenamedEvent     (TObject* Sender);
	void __fastcall OnFileRenamedEvent      (TObject* Sender, AnsiString oldName, AnsiString newName);
    void __fastcall OnFileInstalledEvent    (TObject* Sender, AnsiString fileName, AnsiString archiveName);
    void __fastcall OnArchiveInstalledEvent (TObject* Sender, AnsiString archive);
    void __fastcall OnGotPicEventEvent      (TObject* Sender, TPicture*  Picture);
    void __fastcall OnGotDataListEvent      (TObject* Sender, TStrings*  Data);
__published:
    //__property PFileList           FileList           = {read=fFileList,           write=fFileList          };
    __property TMM_FilesListType   ListType           = {read=fListType,           write=fListType          };
    __property TMMFileListEvent    OnGotFileList      = {read=fOnGotFileList,      write=fOnGotFileList     };
    __property TMMStrEvent         OnFileAdded        = {read=fOnFileAdded,        write=fOnFileAdded       };
	__property TMMFileRenEvent     OnFileRenamed      = {read=fOnFileRenamed,      write=fOnFileRenamed     };
    __property TMMFilesRenEvent    OnFilesRenamed     = {read=fOnFilesRenamed,     write=fOnFilesRenamed    };
    __property TMMFileInsEvent     OnFileInstalled    = {read=fOnFileInstalled,    write=fOnFileInstalled   };
    __property TMMArchiveInsEvent  OnArchiveInstalled = {read=fOnArchiveInstalled, write=fOnArchiveInstalled};
    __property TMMGotPicEvent      OnGotPicture       = {read=fOnGotPicture,       write=fOnGotPicture      };
    __property TMMGotDataListEvent OnGotDataList      = {read=fOnGotDataList,      write=fOnGotDataList     };
    __property TMMSettings*        XMLSettings        = {read=fXMLSettings,        write=fXMLSettings       };
    __property TMMLogs*            XMLLogs            = {read=fXMLLogs,            write=fXMLLogs           };
};
#endif
