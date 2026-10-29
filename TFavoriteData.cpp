//---------------------------------------------------------------------------
#include "TFavoriteData.h"  
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TFavoriteData::TFavoriteData()
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
__fastcall TFavoriteData::TFavoriteData(AnsiString AServerName, int AServerPort, int AServerQueryPort, int AServerID, int AServerIP)
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
void __fastcall TFavoriteData::Assign( TPersistent* Value )
{
    TFavoriteData* Data = dynamic_cast<TFavoriteData*>(Value);

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
void __fastcall TFavoriteData::SetServerName( AnsiString Value )
{
    if(Value!=FServerName && !Value.IsEmpty())
    {
        FServerName = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TFavoriteData::SetServerPort(int Value)
{
    if((Value!=FServerPort) && (Value>0 && Value<65536))
    {
        FServerPort = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TFavoriteData::SetServerQueryPort(int Value)
{
    if((Value!=FServerQueryPort) && (Value>0 && Value<65536))
    {
        FServerQueryPort = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TFavoriteData::SetServerID(int Value)
{
    if((Value!=FServerID) && (Value>0))
    {
        FServerID = Value;
    }
}
//----------------------------------------------------------------------------
void __fastcall TFavoriteData::SetServerIP(int Value)
{
    if((Value != FServerIP) && (Value>0))
    {
        FServerIP = Value;
    }
}
//----------------------------------------------------------------------------

