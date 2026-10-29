//---------------------------------------------------------------------------
#include "TServer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TServer::TServer()
    : TPersistent()
{
}
//----------------------------------------------------------------------------
__fastcall TServer::~TServer()
{
}
//----------------------------------------------------------------------------
void __fastcall TServer::SetIntValue(const int Value, const int Index)
{
    switch(Index)
    {
    	case 0 : FTotalQuerys = Value; break;
    }
}
//----------------------------------------------------------------------------
void __fastcall TServer::SetQureyString(const int QueryType)
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
