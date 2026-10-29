//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GetFileListThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall GetFileListThread::GetFileListThread(bool CreateSuspended)
    : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall GetFileListThread::Execute()
{    //Synchronize(UpdateCaption);


}
//---------------------------------------------------------------------------
 