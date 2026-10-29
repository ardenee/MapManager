//---------------------------------------------------------------------------
#include <Registry.hpp>
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#include "TMaps.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//---------------------------------------------------------------------------
__fastcall TMaps::TMaps(TFiles* Owner)
          : TPersistent()
{
    FMapTypes   = new TStringList;
    FMapFilters = new TStringList;
    FFiles      = Owner;
}
//---------------------------------------------------------------------------
__fastcall TMaps::~TMaps()
{
    delete FMapTypes;
    delete FMapFilters;
}
//----------------------------------------------------------------------------
// Var setting
//----------------------------------------------------------------------------
//void __fastcall TMaps::SetFileData(TFileData* Value)
//{
//    FileData->Assign((TPersistent*)Value);
//}
//----------------------------------------------------------------------------
void __fastcall TMaps::SetLoadMapsType(TMM_LoadFilesType Value)
{
    FLoadMapsType = Value;
}
//----------------------------------------------------------------------------
void __fastcall TMaps::SetStringLists(const int Index, TStrings* Value)
{
    switch(Index)
    {
    	case 0 : FMapTypes->Clear();   FMapTypes->AddStrings(Value);   break;
    	case 1 : FMapFilters->Clear(); FMapFilters->AddStrings(Value); break;
    }
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMaps::GetMapGameType(AnsiString FileName)
{
    // load types from registry, check for a type, of not found set to default
    AnsiString MapType = FileName.Delete(AnsiPos("-", FileName),FileName.Length());
    TStrings* MapGameTypes = new TStringList;

    TRegistry *Registry = new TRegistry;
    Registry->RootKey   = HKEY_LOCAL_MACHINE;

    if(Registry->OpenKey("SOFTWARE\\Nasty PC's\\Map Manager\\GameStarting\\" + FFiles->GameTag, false))
    {
        Registry->GetValueNames(MapGameTypes);
        int num = MapGameTypes->IndexOf(MapType);

        if(num==-1)
            FileName = Registry->ReadString("Default");
        else
            FileName = Registry->ReadString(MapGameTypes->Strings[num]);

        Registry->CloseKey();
    }
    else
        FileName = "Error";

    delete Registry;
    delete MapGameTypes;
    return FileName;
}
//---------------------------------------------------------------------------
bool __fastcall TMaps::GetPicture(AnsiString FileName)
{
    bool Result = false;

    if(FileExists(FileName))
    {
        // New Code to support screenshot grabbing, should work with all maps from now on
        // look to demo.cpp and sort out MetericalSeq class loading etc..
        //TUTPackage* MapPkg = new TUTPackage(FileName, (TUTPackage_GameHint) FFiles->GameType);
        TUTPackage* MapPkg = new TUTPackage();
        MapPkg->Initialize(FileName, (TUTPackage_GameHint) FFiles->GameType);

        TPicture* Picture = new TPicture();
        AnsiString pcName = GetPictureClass(FFiles->GameType);
        bool PicFound = false;
        AnsiString ShotObjNname = "";

        TStrings* OList = new TStringList();
        TStrings* PList = new TStringList();

        for(int i=0;i<MapPkg->ExportedCount;i++)
        {
            OList->Add(MapPkg->Exported[i]->UTObjectName);
            // void __fastcall FindObjectAndPackage(int index, TUTPackage* &pkg, TUTObject* &obj);
            // int  __fastcall FindObject(TUTPackageObjectLocations where,
                                       // TUTPackageFindWhatSet what,
                                       // AnsiString packagename,
                                       // AnsiString objectname,
                                       // AnsiString classname,
                                       // int start = 0x0);
            // enum TUTPackageObjectLocations { utolNames, utolExports, utolImports };
            // enum TUTPackageFindWhat { utfwName, utfwGroup, utfwClass };
            // typedef Set<TUTPackageFindWhat, utfwName, utfwClass>  TUTPackageFindWhatSet;

           // int g = MapPkg->FindObject(utolExports,  (TUTPackageFindWhatSet)utfwName, "LevelSummary", "", "");

			if(!MapPkg->Exported[i]->UTObjectName.Compare("LevelSummary"))
            {
                TUTObject* MapObj = new TUTObject(MapPkg, i);
                MapObj->ReadObject(true); 

                for(int x=0;x<MapObj->Properties->Count;x++)
                {
                    PList->Add(MapObj->Properties->PropertyByPosition[x]->Name);



					if(!MapObj->Properties->PropertyByPosition[x]->Name.Compare("Screenshot"))
                    {
                        ShotObjNname = MapObj->Properties->PropertyByPosition[x]->DescriptiveValue;
                        //ShowMessage(MapObj->Properties->PropertyByPosition[x]->Description);
                        if(AnsiStartsText("Texture", ShotObjNname) || AnsiStartsText("MaterialSequence", ShotObjNname))
                        {
                            ShotObjNname = ShotObjNname.Delete(1, ShotObjNname.AnsiPos("'"));
                            ShotObjNname = StringReplace(ShotObjNname, "'", "", TReplaceFlags() << rfReplaceAll << rfIgnoreCase);
                            PicFound = true;
                        }

                        //ShowMessage(ShotObjNname);

                        break;
                    }
                }

                MapObj->ReleaseObject();
                delete MapObj;
                //break;
            }
        }

        PList->Clear();
        delete OList;  

        if(PicFound)
        {
            for(int i=0;i<MapPkg->ExportedCount;i++)
            {
				if(!MapPkg->Exported[i]->UTObjectName.Compare("levelpreview" /*ShotObjNname*/))
                {
                    TUTObject* MapObj = new TUTObject(MapPkg, i);
                    MapObj->ReadObject(true);

                    for(int x=0;x<MapObj->Properties->Count;x++)
                        PList->Add(MapObj->Properties->PropertyByPosition[x]->Description);

                    //TUTObjectClassTexture* Tex = new TUTObjectClassTexture(MapPkg, i);// (TUTObjectClassTexture* ) MapPkg->Exported[i];
                    //Tex->ReadObject();
                    //Picture->Bitmap = Tex->GoodMipMap[0]->AsBitmap();
                    //Tex->ReleaseObject();
                   // delete Tex;
                   delete MapObj;
                }
            }
        }

        delete PList;

        if(FOnGotPicture)
            FOnGotPicture(this, Picture);

        delete Picture;
        delete MapPkg;
    }

    return Result;
}
//---------------------------------------------------------------------------
// Global functions ;)
//---------------------------------------------------------------------------
AnsiString __fastcall TMaps::GetPictureClass(TMM_GameType Type) // onlt returns the GameTag - public function
{
    return FFiles->GetValueFor("\\SOFTWARE\\Nasty PC's\\Map Manager\\GameTypes\\", IntToStr((int) Type));
}
//----------------------------------------------------------------------------
void __fastcall TMaps::GetMapInfo(AnsiString pMap)
{
    // get info about the map, required files etc....
}
//----------------------------------------------------------------------------
// wrapers for the TFiles class
//----------------------------------------------------------------------------
void __fastcall TMaps::GetMaps()
{
    FFiles->GetFileList(FFiles->MapFolder, FFiles->MapSubFolders, LoadMapsType, MapFilters, MapTypes);
}          
//----------------------------------------------------------------------------
void __fastcall TMaps::UninstallMaps(TMMFileList* pMapList)
{
    FFiles->UninstallFiles(pMapList);
}    
//----------------------------------------------------------------------------
void __fastcall TMaps::RenameMaps(TMMFileList* pMapList)
{
    FFiles->RenameFiles(pMapList);
}
//----------------------------------------------------------------------------
void __fastcall TMaps::DeleteMaps(TMMFileList* pMapList)
{
    FFiles->DeleteFiles(pMapList);
}  
//----------------------------------------------------------------------------
void __fastcall TMaps::FindMaps(TMMFileList* pMapList, AnsiString pSubString)
{
    FFiles->FindFile(pMapList, pSubString);
}
//----------------------------------------------------------------------------
void __fastcall TMaps::GetMapTypes()
{
    FFiles->GetValues("SOFTWARE\\Nasty PC's\\Map Manager\\Maps\\" + FFiles->GameTag, MapTypes);
}
//----------------------------------------------------------------------------
void __fastcall TMaps::GetMapFilters()
{
    FFiles->GetValues("\\SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + FFiles->GameTag + "\\Maps", MapFilters);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMaps::GetMapType(AnsiString pMapFilter)
{
    return FFiles->GetValueFor("\\SOFTWARE\\Nasty PC's\\Map Manager\\DisplayMenus\\" + FFiles->GameTag + "\\Maps", pMapFilter);
}
//----------------------------------------------------------------------------

