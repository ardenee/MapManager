//---------------------------------------------------------------------------

#ifndef TMMFileInfoThreadH
#define TMMFileInfoThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
#include "MMTypes.h"
#include "ut_uz.hpp"
#include "ut_umods.hpp"
#include "ut_packages.hpp"
#include "MMArchiveEngine.hpp"

//---------------------------------------------------------------------------
class TMMFileInfoThread : public TThread
{
private:
    TMM_GetFileInfoType fAction;
    int                 fExportedTextures;
    AnsiString          fDataName;
    AnsiString          fFileName;
    TUTPackage_GameHint fGameType;
    TUTPackage*         fEpicPkg;
    TUMOD*              fEipcUmod;
    TUZFile*            fEpicUz;
    TPicture*           fPicture;
    TStrings*           fData;
    TMMGotPicEvent      fOnBeforePictureEnd;
    TMMGotDataListEvent fOnDataListEnd;
    TMMIntEvent         fOnTexturesEnd;
    void __fastcall GetImage();    // fOnBeforePictureEnd
    void __fastcall GetInfo();     // fOnDataListEnd
    void __fastcall GetTextures(); // fOnTexturesEnd
    void __fastcall GetData();     // fOnDataListEnd 
    void __fastcall GetPackedData();
    void __fastcall GetZipData();  // fOnDataListEnd
    bool __fastcall GetRARData(bool pJustTest);  // fOnDataListEnd
    void __fastcall GetUMODData(); // fOnDataListEnd
    void __fastcall GetSFXData(); // fOnDataListEnd - could be zip or rar
    void __fastcall GetFileData(); // fOnDataListEnd - could be zip or rar
    void __fastcall GetUZ2Data(); // fOnDataListEnd - could be zip or rar
    void __fastcall GetUZData(); // fOnDataListEnd - could be zip or rar
    void __fastcall BeforeEnd();
// Zip
// rar
protected:
    void __fastcall Execute();
    void __fastcall DoTerminate();
public:
    __fastcall TMMFileInfoThread(bool CreateSuspended, TMM_GetFileInfoType action, AnsiString dataName, AnsiString fileName, TUTPackage_GameHint gameType);
    __fastcall ~TMMFileInfoThread();

    __property TMMGotPicEvent   OnBeforePictureEnd = {read=fOnBeforePictureEnd, write=fOnBeforePictureEnd};
    __property TMMGotDataListEvent OnDataListEnd   = {read=fOnDataListEnd, write=fOnDataListEnd};
    __property TMMIntEvent      OnTexturesEnd      = {read=fOnTexturesEnd, write=fOnTexturesEnd};
};
//---------------------------------------------------------------------------
#endif
