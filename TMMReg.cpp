//---------------------------------------------------------------------------
#include "TMMReg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TMMReg::TMMReg()
    : TPersistent()
{
    Registry          = new TRegistry;
    Registry->RootKey = HKEY_CURRENT_USER;
}
//----------------------------------------------------------------------------
__fastcall TMMReg::~TMMReg()
{
    delete Registry;
} 
//----------------------------------------------------------------------------
// Working - Gets all Keys for a Key
//----------------------------------------------------------------------------
void __fastcall TMMReg::GetKeys(AnsiString pRegKey, TStrings* pList)
{
    Registry->CloseKey();
    
    try
    {
        if(Registry->OpenKey(pRegKey, false))
        {
            Registry->GetKeyNames(pList);
            Registry->CloseKey();
        }
    }

    catch(ERegistryException &e)
    {
        Registry->CloseKey();
        
        if(FOnRegError)
            FOnRegError(this, "TMMReg::GetKeys(AnsiString, TStrings*)::Couldn't get Key List.\n\n" + e.Message);
    }
}
//----------------------------------------------------------------------------
// Working - Gets All Values for a Key
//----------------------------------------------------------------------------
void __fastcall TMMReg::GetValues(AnsiString pRegKey, TStrings* pList)
{
    Registry->CloseKey();

    try
    {
        if(Registry->OpenKey(pRegKey, false))
        {
            Registry->GetValueNames(pList);
            Registry->CloseKey();
        }
    }

    catch(ERegistryException &e)
    {
        Registry->CloseKey();

        if(FOnRegError)
            FOnRegError(this, "GetValues(AnsiString, TStrings*)::Couldn't get Value List.\n\n" + e.Message);
    }
}
//----------------------------------------------------------------------------
// Working - Gets All String Data Only - Can Keep or Drop Dubbles
//----------------------------------------------------------------------------
void __fastcall TMMReg::GetDatas(AnsiString pRegKey, TStrings* pList, bool pDropDoubles)
{
    Registry->CloseKey();
    TStringList* tmpList = new TStringList;
    tmpList->Sorted      = pDropDoubles; // it true next line will take effect ;)
	tmpList->Duplicates  = System::Classes::dupIgnore;

    try
    {
        if(Registry->OpenKey(pRegKey, false))
        {
            Registry->GetValueNames(pList); // will reset the list ;)

            for(int i=0;i<pList->Count;i++)
                if(Registry->GetDataType(pList->Strings[i])==rdString) //is string type?
                    tmpList->Add(Registry->ReadString(pList->Strings[i]));

            pList->Clear();
            pList->AddStrings(tmpList);
            Registry->CloseKey();
        }
    }

    catch(ERegistryException &e)
    {
        delete tmpList;
        Registry->CloseKey();

        if(FOnRegError)
            FOnRegError(this, "GetStringData(AnsiString, TStrings*, bool)::Couldn't get String Data List.\n\n" + e.Message);
    }

    delete tmpList;
}
//----------------------------------------------------------------------------
// Working - Gets Data for a Passed in Value
//----------------------------------------------------------------------------
AnsiString __fastcall TMMReg::GetDataFor(AnsiString pRegKey, AnsiString Value)
{
    Registry->CloseKey();
    
    try
    {
        if(Registry->OpenKey(pRegKey, false))
        {
            if(Registry->GetDataType(Value)==rdString)
                return Registry->ReadString(Value);
        }
    }

    catch(ERegistryException &e)
    {
        Registry->CloseKey();

        if(FOnRegError)
            FOnRegError(this, "GetDataFor(AnsiString, AnsiString, TRegDataType)::Couldn't get Data.\n\n" + e.Message);
    }

    return "Can't Open Key";
}
//----------------------------------------------------------------------------
// Private - Gets Data for a Passed in Value
//----------------------------------------------------------------------------
AnsiString __fastcall TMMReg::GetDataFor(AnsiString Value)
{    
    try
    {
        if(Registry->GetDataType(Value)==rdString)
            return Registry->ReadString(Value);
    }

    catch(ERegistryException &e)
    {
        if(FOnRegError)
            FOnRegError(this, "GetDataFor(AnsiString, AnsiString, TRegDataType)::Couldn't get Data.\n\n" + e.Message);
    }

    return "Can't Read Open Key";
}
//----------------------------------------------------------------------------
// Gets Data for a Passed in Value
//----------------------------------------------------------------------------
AnsiString __fastcall TMMReg::GetValueFor(AnsiString pRegKey, AnsiString Data)
{
    Registry->CloseKey();
    TStrings* VList = new TStringList();
    this->GetValues(pRegKey, VList);

    try
    {
        if(Registry->OpenKey(pRegKey, false))
        {
            for(int i=0;i<VList->Count;i++)
            {
                if(!this->GetDataFor(VList->Strings[i]).AnsiCompareIC(Data))
                {
                    Registry->CloseKey();
                    return VList->Strings[i];
                }
            }
        }
    }

    catch(ERegistryException &e)
    {
        Registry->CloseKey();

        if(FOnRegError)
            FOnRegError(this, "GetDataFor(AnsiString, AnsiString, TRegDataType)::Couldn't get Data.\n\n" + e.Message);
    }

    Registry->CloseKey();
    return "Not Find";
}
//----------------------------------------------------------------------------
// added -
//----------------------------------------------------------------------------
bool __fastcall TMMReg::IsAValue(AnsiString pRegKey, AnsiString pFileExt)
{
    Registry->CloseKey();

    try
    {
        if(Registry->OpenKey(pRegKey, false))
        {
            if(Registry->ValueExists(pFileExt))
            {
                Registry->CloseKey();
                return true;
            }
        }
    }

    catch(ERegistryException &e)
    {
        Registry->CloseKey();

        if(FOnRegError)
            FOnRegError(this, "IsAValue(AnsiString, AnsiString)::Couldn't get Data.\n\n" + e.Message);
    }

    Registry->CloseKey();
    return false;
}
//----------------------------------------------------------------------------


