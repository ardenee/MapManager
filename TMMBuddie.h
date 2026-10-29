#ifndef TMMBuddieH
#define TMMBuddieH
#include <vcl.h>
#include "Types.h"
//---------------------------------------------------------------------------

class TMMBuddie : public TPersistent
{
private:
    AnsiString FNewBuddieName;
    AnsiString FOldBuddieName;
    AnsiString FSectionMarker;
    AnsiString FBuddieStringFormat;
    AnsiString FBuddieFile;
    // set values
    void __fastcall SetNewBuddieName(const AnsiString Value);
    void __fastcall SetOldBuddieName(const AnsiString Value);
	void __fastcall SetSectionMarker(TMM_GameType Value);
	void __fastcall SetBuddieStringFormat(TMM_GameType Value);
    void __fastcall GetFileSection(TStrings* FileStrings);
    bool __fastcall AddStringAt(TStrings* FileStrings, AnsiString StringToAdd);
    bool __fastcall DeleteStringAt(TStrings* FileStrings, AnsiString StringToDelete);
    // functions
    inline AnsiString __fastcall EncodeBuddieString(void);
    AnsiString __fastcall DecodeBuddieString(AnsiString BuddieString);
public:
    __fastcall TMMBuddie(TMM_GameType AGameType, AnsiString ABuddieFile); //default constructor
    int __fastcall GetBussidList(TStrings* BuddieList);
    bool __fastcall Add(void);
    bool __fastcall Delete(void);
    bool __fastcall Edit(void);

__published:
    __property AnsiString NewBuddieName      = {read=FNewBuddieName, write=SetNewBuddieName};
    __property AnsiString OldBuddieName      = {read=FOldBuddieName, write=SetOldBuddieName};
    __property AnsiString BuddieFile         = {read=FBuddieFile};
    __property AnsiString SectionMarker      = {read=FSectionMarker};
    __property AnsiString BuddieStringFormat = {read=FBuddieStringFormat};
};
#endif
