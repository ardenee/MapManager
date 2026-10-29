//---------------------------------------------------------------------------
#include "TMMFavoriteData.h"  
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TMMFavoriteData::TMMFavoriteData()
    : TPersistent()
{
    //initialize some stuff if you like
    ServerName      = "";
    ServerPort      = 2;
    ServerQueryPort = 0;
    ServerID        = 0;
    ServerIP        = 0;
}
//----------------------------------------------------------------------------
__fastcall TMMFavoriteData::TMMFavoriteData(AnsiString AServerName, int AServerPort, int AServerQueryPort, int AServerID, int AServerIP)
    : TPersistent()
{
    //be sure to use the property names to assign our values and not the F names
    //or our write= methods won't protect the private data
    ServerName      = AServerName;
    ServerPort      = AServerPort;
    ServerQueryPort = AServerQueryPort;
    ServerID        = AServerID;
    ServerIP        = AServerIP;
}
//----------------------------------------------------------------------------
void __fastcall TMMFavoriteData::Assign( TPersistent* Value )
{
    TMMFavoriteData* Data = dynamic_cast<TMMFavoriteData*>(Value);

    if(Data!=NULL)
    {
        ServerName      = Data->ServerName;
        ServerPort      = Data->ServerPort;
        ServerQueryPort = Data->ServerQueryPort;
        ServerID        = Data->ServerID;
        ServerIP        = Data->ServerIP;
    }
    else
    {
        TPersistent::Assign( Value );
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMFavoriteData::SetServerName( AnsiString Value )
{
    if(Value!=FServerName && !Value.IsEmpty())
    {
        FServerName = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMFavoriteData::SetServerPort(int Value)
{
    if((Value!=FServerPort) && (Value>0 && Value<65536))
    {
        FServerPort = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMFavoriteData::SetServerQueryPort(int Value)
{
    if((Value!=FServerQueryPort) && (Value>0 && Value<65536))
    {
        FServerQueryPort = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMFavoriteData::SetServerID(int Value)
{
    if((Value!=FServerID) && (Value>0))
    {
        FServerID = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMFavoriteData::SetServerIP(int Value)
{
    if((Value != FServerIP) && (Value>0))
    {
        FServerIP = Value;
    }
}
//----------------------------------------------------------------------------

