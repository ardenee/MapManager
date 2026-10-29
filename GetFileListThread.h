//---------------------------------------------------------------------------

#ifndef GetFileListThreadH
#define GetFileListThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class GetFileListThread : public TThread
{
private:
protected:
    void __fastcall Execute();
public:
    __fastcall GetFileListThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
 