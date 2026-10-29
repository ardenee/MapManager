#ifndef TServerDataH
#define TServerDataH
#include <vcl.h>
//---------------------------------------------------------------------------

class TServerData : public TPersistent    //put a 'T' in front of class types
{                                           //it is the professional way, they say
private://your valuable data that is safe from the outside world
    AnsiString FServerName;
    int FServerPort;           //do not use unsigned int's
    int FServerIP;             //do not use unsigned long
                               // there are know problems using unsigned values
    //your data access write methods that protect your private data
    //from being mistreated and will allow you to know when someone
    //tries to change it, you can then take evasive action!
    void __fastcall SetServerName(AnsiString Value);
    void __fastcall SetServerPort(int Value);
    void __fastcall SetServerIP(int Value);
public:
    __fastcall TServerData();   //default constructor
    __fastcall TServerData(AnsiString AServerName, int AServerPort, int AServerIP);
    void __fastcall Assign(TPersistent* Value);
__published:
    __property AnsiString ServerName = {read=FServerName, write=SetServerName};
    __property int ServerPort        = {read=FServerPort, write=SetServerPort};
    __property int ServerIP          = {read=FServerIP,   write=SetServerIP};
};  
#endif
