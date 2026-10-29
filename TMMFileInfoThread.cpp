//---------------------------------------------------------------------------
#include <vcl.h>
#include <StrUtils.hpp>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TMMFileInfoThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TMMFileInfoThread::TMMFileInfoThread(bool CreateSuspended, TMM_GetFileInfoType action, AnsiString dataName, AnsiString fileName, TUTPackage_GameHint gameType)
    : TThread(CreateSuspended)
{
    // need a way to skip the queue and just load the last image not queue it
    FreeOnTerminate = true;
    Priority        = tpLower; // smoother
    fAction         = action;
    fDataName       = dataName;
    fFileName       = fileName;
    fGameType       = gameType;
    fExportedTextures = 0;
}
//---------------------------------------------------------------------------
__fastcall TMMFileInfoThread::~TMMFileInfoThread()
{
    delete fPicture;
    delete fData;

    if(fEpicPkg)
        fEpicPkg->ReleaseAllObjects();
        
    delete fEpicPkg;
    delete fEipcUmod;

    if(fEpicUz)
        delete fEpicUz;
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::Execute()
{
    fEpicPkg  = new TUTPackage();
    fPicture  = new TPicture();
    fData     = new TStringList();
    fEipcUmod = new TUMOD();

    if(FileExists(fFileName))
    {
        //fMapPkckage->Initialize(fFileName, fGameType);
    
        switch(fAction)
        {
            case MM_GFIT_IMAGE    : fEpicPkg->Initialize(fFileName, fGameType); GetImage();    break; // 0
            case MM_GFIT_INFO     : fEpicPkg->Initialize(fFileName, fGameType); GetInfo();     break; // 1
            case MM_GFIT_TEXTURES : fEpicPkg->Initialize(fFileName, fGameType); GetTextures(); break; // 2
            case MM_GFIT_DATA     : fEpicPkg->Initialize(fFileName, fGameType); GetData();     break; // 3

            case MM_GFIT_ZIPDATA  : GetZipData();  break; // 4
            case MM_GFIT_RARDATA  : GetRARData(false);  break; // 5
            case MM_GFIT_UMODDATA : if(fEipcUmod->IsUMOD(fFileName))
                                        GetUMODData();
                                    break; // 6
            case MM_GFIT_SFXDATA  : GetSFXData();  break; // 7

            case MM_GFIT_COPY     : GetFileData(); break; // 8
            case MM_GFIT_UZ2      : GetUZ2Data();  break; // 9
            case MM_GFIT_UZ       : fEpicUz = new TUZFile(fFileName); GetUZData();   break; // 10
            default               : GetFileData(); break; // 8
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::DoTerminate()
{
    if(fOnBeforePictureEnd || fOnDataListEnd || fOnTexturesEnd)
        Synchronize(BeforeEnd);

    TThread::DoTerminate();
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::BeforeEnd()
{
    switch(fAction)
    {
        case  MM_GFIT_IMAGE : if(fOnBeforePictureEnd)
                    fOnBeforePictureEnd(this, fPicture);
                  break; // GetImage();
        case  MM_GFIT_INFO : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetInfo();
        case  MM_GFIT_TEXTURES : if(fOnTexturesEnd)
                    fOnTexturesEnd(this, fExportedTextures);
                  break; // GetTextures();
        case  MM_GFIT_DATA : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        case  MM_GFIT_ZIPDATA : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        case  MM_GFIT_RARDATA : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        case  MM_GFIT_UMODDATA : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        case  MM_GFIT_SFXDATA : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        case  MM_GFIT_COPY : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        case  MM_GFIT_UZ2 : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        case  MM_GFIT_UZ : if(fOnDataListEnd)
                    fOnDataListEnd(this, fData);
                  break; // GetData(AnsiString);
        default : break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetImage()
{
    bool PicFound = false;
    AnsiString ShotObjNname = "";

        for(int i=0;i<fEpicPkg->ExportedCount;i++)
        {
			if(!fEpicPkg->Exported[i]->UTObjectName.Compare("LevelSummary"))
            {
                TUTObject* MapObj = new TUTObject(fEpicPkg, i);
                MapObj->ReadObject(true);

                for(int x=0;x<MapObj->Properties->Count;x++)
                {
					if(!MapObj->Properties->PropertyByPosition[x]->Name.Compare("Screenshot"))
                    {
                        ShotObjNname = MapObj->Properties->PropertyByPosition[x]->DescriptiveValue;
                        
                        if(AnsiStartsText("Screenshot", ShotObjNname) || AnsiStartsText("MaterialSequence", ShotObjNname))
                        {
                            ShotObjNname = ShotObjNname.Delete(1, ShotObjNname.AnsiPos("'"));
                            ShotObjNname = StringReplace(ShotObjNname, "'", "", TReplaceFlags() << rfReplaceAll << rfIgnoreCase);
                            PicFound = true;
                        }

                        break;
                    }
                }

                MapObj->ReleaseObject();
                delete MapObj;
            }
        }

        if(PicFound)
        {
            for(int i=0;i<fEpicPkg->ExportedCount;i++)
            {
				if(!fEpicPkg->Exported[i]->UTObjectName.Compare(ShotObjNname))
                {
                    TUTObject* MapObj = new TUTObject(fEpicPkg, i);
                    MapObj->ReadObject();

                    for(int x=0;x<MapObj->Properties->Count;x++)
                    {
                        if(MapObj->Properties->PropertyByPosition[x]->Name == "SequenceItems")
                        {
                            AnsiString tmp = MapObj->Properties->PropertyByPosition[x]->Description;

                            TStrings* st = new TStringList();
                            st->Text = tmp;

                            TStringList* t = new TStringList();
                            t->Sorted = true;
							t->Duplicates = System::Classes::dupIgnore;

							// Should be saving the array of screen shots to the list instread of just passing back 1 image ;)

                            for(int x=0;x<st->Count;x++)
                            {
                                st->Strings[x] = st->Strings[x].Delete(1, st->Strings[x].Pos('\''));
                                st->Strings[x] = st->Strings[x].Delete(st->Strings[x].Pos('\''), st->Strings[x].Length()); 
                                t->Add(st->Strings[x]);
                            }

                            for(int i=0;i<fEpicPkg->ExportedCount;i++)
                            {
                                if(!fEpicPkg->Exported[i]->UTObjectName.Compare(st->Strings[0]))
                                {
                                    TUTObjectClassTexture* Tex = new TUTObjectClassTexture(fEpicPkg, i);
                                    Tex->ReadObject();
                                    fPicture->Bitmap = Tex->GoodMipMap[0]->AsBitmap();
                                    //Picture->SaveToFile("tmp.bmp");
                                    Tex->ReleaseObject();
                                    delete Tex;
                                }
                            }

                            delete t;
                            delete st;
                            break;
                        }
                    }

                    MapObj->ReleaseObject();
                    delete MapObj;
                }
            }
        }
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetInfo()
{
    fData->Add(fFileName);
    fData->Add("Exported Objects|"            + IntToStr(fEpicPkg->ExportedCount));
    fData->Add("Imported Objects|"            + IntToStr(fEpicPkg->ImportedCount));
    fData->Add("Package Version|"             + IntToStr(fEpicPkg->Version));
    fData->Add("Imported Objects|"            + BoolToStr(fEpicPkg->IsPackageEncrypted(), true));
    fData->Add("Package|"                     + fEpicPkg->Package);
    fData->Add("Name Count|"                  + IntToStr(fEpicPkg->NameCount));
    fData->Add("Heritage Count|"              + IntToStr(fEpicPkg->HeritageCount));
    fData->Add("Generation Count|"            + IntToStr(fEpicPkg->GenerationCount));
    fData->Add("Unreferenced Sections Count|" + IntToStr(fEpicPkg->UnreferencedSectionsCount));
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetTextures()
{
// stuff
    if(fOnTexturesEnd)
        Synchronize(BeforeEnd);
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetData()
{
// stuff
    if(fOnDataListEnd)
        Synchronize(BeforeEnd);
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetZipData()
{
    GetPackedData();
}
//---------------------------------------------------------------------------
bool __fastcall TMMFileInfoThread::GetRARData(bool pJustTest)
{
    GetPackedData();
    return true;
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetPackedData()
{
    TMMArchiveEngine *archive = new TMMArchiveEngine();
    try
    {
        archive->Open(UnicodeString(fFileName));
        fData->Add(fFileName);
        for (int i = 0; i < archive->Count && !Terminated; ++i)
        {
            const UnicodeString name = archive->ItemPath[i];
            fData->Add(UnicodeString(L"File Name|") + ExtractFileName(name));
            fData->Add(UnicodeString(L"File Folder|") + ExtractFilePath(name));
            if (double(archive->ItemDate[i]) > 0.0)
                fData->Add(UnicodeString(L"File Date|") + DateTimeToStr(archive->ItemDate[i]));
            fData->Add(UnicodeString(L"File Size|") + IntToStr(archive->ItemSize[i]));
            fData->Add(UnicodeString(L"File Packed Size|") + IntToStr(archive->ItemPackedSize[i]));
            fData->Add(UnicodeString(L"File CRC|") + IntToHex((int)archive->ItemCRC[i], 8));
            if (archive->ItemEncrypted[i])
                fData->Add("File is password protected");
        }
    }
    __finally { delete archive; }
    if (fOnDataListEnd && !Terminated)
        Synchronize(BeforeEnd);
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetUMODData()
{
    fEipcUmod->Load(fFileName);

    for(int i=0;i<fEipcUmod->Count;i++)
        fData->Add(fEipcUmod->Files[i] + "|" + IntToStr(fEipcUmod->Size[i]));

    if(fOnDataListEnd)
        Synchronize(BeforeEnd);
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetSFXData()
{
    GetPackedData();  // d7zip supports ZIP self-extracting archives in-process
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetFileData()
{
// stuff
    if(fOnDataListEnd)
        Synchronize(BeforeEnd);
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetUZ2Data()
{
// stuff
    if(fOnDataListEnd)
        Synchronize(BeforeEnd);
}
//---------------------------------------------------------------------------
void __fastcall TMMFileInfoThread::GetUZData()
{
    fData->Add(fEpicUz->Filename + "|" + fEpicUz->OriginalFilename);
    // get more file info as in on file size etc...

// stuff
    if(fOnDataListEnd)
        Synchronize(BeforeEnd);
}
//---------------------------------------------------------------------------
