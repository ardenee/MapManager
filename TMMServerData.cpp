//---------------------------------------------------------------------------
#include "TMMServerData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TMMServerData::TMMServerData()
    : TPersistent()
{
    //initialize some stuff if you like
    ServerName = "";
    ServerPort = 0;
    ServerIP   = 0;
}
//----------------------------------------------------------------------------
__fastcall TMMServerData::TMMServerData(AnsiString AServerName, int AServerPort, int AServerIP)
    : TPersistent()
{
    //be sure to use the property names to assign our values and not the F names
    //or our write= methods won't protect the private data
    ServerName = AServerName;
    ServerPort = AServerPort;
    ServerIP   = AServerIP;
}
//----------------------------------------------------------------------------
void __fastcall TMMServerData::Assign(TPersistent* Value)
{
    TMMServerData* Data = dynamic_cast<TMMServerData*>(Value);

    if(Data!=NULL)
    {
        ServerName = Data->ServerName;
        ServerPort = Data->ServerPort;
        ServerIP   = Data->ServerIP;
    }
    else
    {
        TPersistent::Assign(Value);
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMServerData::SetServerName(AnsiString Value)
{
    if(Value!=FServerName && !Value.IsEmpty())
    {
        FServerName = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMServerData::SetServerPort(int Value)
{
    if((Value!=FServerPort) && (Value>0 && Value<65536))
    {
        FServerPort = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMServerData::SetServerIP(int Value)
{
    if((Value!=FServerIP) && (Value>0))
    {
        FServerIP = Value;
    }
}
//----------------------------------------------------------------------------

