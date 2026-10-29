//---------------------------------------------------------------------------
#include "TMMServer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TMMServer::TMMServer()
    : TPersistent()
{
}
//----------------------------------------------------------------------------
__fastcall TMMServer::~TMMServer()
{
}
//----------------------------------------------------------------------------
void __fastcall TMMServer::SetIntValue(const int Value, const int Index)
{
    switch(Index)
    {
    	case 0 : FTotalQuerys = Value; break;
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMServer::SetQureyString(const int QueryType)
{
    switch(QueryType)
    {
    	case 0 : FQueryString = "Query 0"; break;
    	case 1 : FQueryString = "Query 1"; break;
    	case 2 : FQueryString = "Query 2"; break;
    	case 3 : FQueryString = "Query 3"; break;
    	case 4 : FQueryString = "Query 4"; break;
    	case 5 : FQueryString = "Query 5"; break;
    }
}
//----------------------------------------------------------------------------
