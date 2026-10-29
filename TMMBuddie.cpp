#include "TMMBuddie.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma hdrstop
//----------------------------------------------------------------------------
__fastcall TMMBuddie::TMMBuddie(TMM_GameType AGameType, AnsiString ABuddieFile)
    : TPersistent()
{
    FBuddieFile = ABuddieFile;
    SetSectionMarker(AGameType);
    SetBuddieStringFormat(AGameType);
    NewBuddieName = "";
    OldBuddieName = "";
}
//----------------------------------------------------------------------------
void __fastcall TMMBuddie::SetSectionMarker(TMM_GameType Value)
{
    switch(Value)
    {
    	case MM_GT_Unreal               : FSectionMarker="";                                         break;
    	case MM_GT_Unreal2              : FSectionMarker="";                                         break;
    	case MM_GT_UnrealTournament     : FSectionMarker="";                                         break;
		case MM_GT_UnrealTournament2003 : FSectionMarker="[XInterface.Browser_ServerListPageBuddy]"; break;
		default                         : FSectionMarker="[XInterface.Browser_ServerListPageBuddy]"; // MM_GT_UnrealTournament2003
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMBuddie::SetBuddieStringFormat(TMM_GameType Value)
{
	switch(Value)
    {
    	case MM_GT_Unreal               : FBuddieStringFormat="<:BUDDIE:>";         break;
    	case MM_GT_Unreal2              : FBuddieStringFormat="<:BUDDIE:>";         break;
    	case MM_GT_UnrealTournament     : FBuddieStringFormat="<:BUDDIE:>";         break;
		case MM_GT_UnrealTournament2003 : FBuddieStringFormat="Buddies=<:BUDDIE:>"; break;
		default                         : FBuddieStringFormat="Buddies=<:BUDDIE:>"; //  MM_GT_UnrealTournament2003
    }
}
//----------------------------------------------------------------------------
void __fastcall TMMBuddie::SetNewBuddieName(const AnsiString Value)
{
    if((Value!=FNewBuddieName) && !Value.IsEmpty())
        FNewBuddieName = Value;
}
//----------------------------------------------------------------------------
void __fastcall TMMBuddie::SetOldBuddieName(const AnsiString Value)
{
    if((Value!=FOldBuddieName) && !Value.IsEmpty())
        FOldBuddieName = Value;
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMBuddie::EncodeBuddieString(void)
{
    return StringReplace("<:BUDDIE:>", NewBuddieName, BuddieStringFormat, TReplaceFlags() << rfIgnoreCase);
}
//----------------------------------------------------------------------------
AnsiString __fastcall TMMBuddie::DecodeBuddieString(AnsiString BuddieString)
{ // format could be
  // 1) <:BUDDIE:>
  // 2) Buddies=<:BUDDIE:>
  // 3) Buddies=<:BUDDIE:>=No1
  // 4) <:BUDDIE:>=No1
  // use string replace to remove other string bits? would be safer too!

    AnsiString TmpString = StringReplace("<:BUDDIE:>", "\t", BuddieStringFormat, TReplaceFlags() << rfIgnoreCase);

    int EndOfStart = AnsiPos('\t', TmpString);

    if(EndOfStart==0 && TmpString.Length()==1) // format 1
        return BuddieString;

    if(EndOfStart==TmpString.Length()) // format 2
        return BuddieString.Delete(1, TmpString.Length());
        
    if(EndOfStart==TmpString.Length()) // format 3
    {
        BuddieString = BuddieString.Delete(1,TmpString.Length());
        return BuddieString.Delete(TmpString.Length()-1, BuddieString.Length());
    }
    
    if(EndOfStart==0 && TmpString.Length()>1) // format 4
		return BuddieString.Delete(TmpString.Length()-1, BuddieString.Length());

	return "";
}
//----------------------------------------------------------------------------
int __fastcall TMMBuddie::GetBussidList(TStrings* BuddieList)
{
    bool Loaded = false;

    if(FileExists(BuddieFile))
    {
        BuddieList->LoadFromFile(BuddieFile);
        GetFileSection(BuddieList);
        Loaded = true;
    }

    return Loaded;
}
//----------------------------------------------------------------------------
bool __fastcall TMMBuddie::Add(void)
{
    bool Added = false;

    if(!NewBuddieName.IsEmpty())
    {
        TStrings* FileStrings = new TStringList;
        FileStrings->LoadFromFile(BuddieFile);
        NewBuddieName = EncodeBuddieString();

        if(AddStringAt(FileStrings, NewBuddieName))
        {
            FileStrings->SaveToFile(BuddieFile);
            Added = true;
        }

        delete FileStrings;
    }

    return Added;
}
//----------------------------------------------------------------------------
bool __fastcall TMMBuddie::Delete(void)
{
    bool Deleted = false;

    if(!OldBuddieName.IsEmpty())
    {
        TStrings* FileStrings = new TStringList;
        FileStrings->LoadFromFile(BuddieFile);
        OldBuddieName = EncodeBuddieString();

        for(int i=0;i<FileStrings->Count;i++)
        {
			if(!FileStrings->Strings[i].Compare(OldBuddieName))
			{
                FileStrings->Delete(i);
                FileStrings->SaveToFile(BuddieFile);
                Deleted = true;
                break;
            }
        }

        delete FileStrings;
    }

    return Deleted;
}
//----------------------------------------------------------------------------
bool __fastcall TMMBuddie::Edit(void)
{
    bool Result = false;
	Result = TMMBuddie::Delete();
    Result = TMMBuddie::Add();
    return Result;
}
//----------------------------------------------------------------------------
void __fastcall TMMBuddie::GetFileSection(TStrings* FileStrings)
{
    int marker=0;

    // find start of Favorites then delete all before
    for(int i=0;i<FileStrings->Count;i++)
    {
        if(FileStrings->Strings[i]==SectionMarker) // caps and everything!!
        {
            marker=i;
            break;
        }
        else
        {   // added to delete entrys, keep junk from being displayed if section is not found
            FileStrings->Delete(i);
            i--;
        }  
    }

    if(marker<FileStrings->Count)
    {   // marker marks the end of where we stop deleting
        for(int i=0;i<(marker+1);i++)
            FileStrings->Delete(0);

        for(int i=0;i<FileStrings->Count;i++)
        {
            if(FileStrings->Strings[i].IsEmpty())
            {
                marker=i;
                break;
            }
            else
                marker=i; // but we dont break !!!
        }

        // while we have other after out fav start, delete them
        // marker marks the end of where we stop deleting, working backwards
        while(FileStrings->Count!=marker+1)
            FileStrings->Delete(FileStrings->Count-1);

        // delete all blank strings
        for(int i=0;i<FileStrings->Count;i++)
        {
            if(FileStrings->Strings[i].IsEmpty())
            {
                FileStrings->Delete(i);
                i--;
            }
        }
    } 
}
//---------------------------------------------------------------------------
bool __fastcall TMMBuddie::AddStringAt(TStrings* FileStrings, AnsiString StringToAdd)
{
    int Added = false;

    for(int i=0;i<FileStrings->Count;i++)
    {
		if(!FileStrings->Strings[i].Compare(SectionMarker))
        {
            FileStrings->Insert(i+1, StringToAdd);
            Added = true;
            break;
        }
    }

    if(!Added)
    {   // no buddies at all, we'll add em plus the section Marker!! ;)
        FileStrings->Insert(FileStrings->Count, SectionMarker);
        FileStrings->Insert(FileStrings->Count, StringToAdd);
        Added = true;
    }

    return Added;
}
//---------------------------------------------------------------------------
bool __fastcall TMMBuddie::DeleteStringAt(TStrings* FileStrings, AnsiString StringToDelete)
{
    int Deleted = false;

    for(int i=0;i<FileStrings->Count;i++)
    {
		if(!FileStrings->Strings[i].Compare(SectionMarker))
        {
            for(int x=i;x<FileStrings->Count;x++)
            {
                if(!FileStrings->Strings[x].Compare(StringToDelete))
                {
                    FileStrings->Delete(x);
                    Deleted = true;
                    break;
                }
            }
        }
    }
    
    return Deleted;
}
//---------------------------------------------------------------------------


