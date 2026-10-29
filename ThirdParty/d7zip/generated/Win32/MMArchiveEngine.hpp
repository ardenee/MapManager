// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MMArchiveEngine.pas' rev: 37.00 (Windows)

#ifndef MMArchiveEngineHPP
#define MMArchiveEngineHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <System.Variants.hpp>
#include <System.IOUtils.hpp>
#include <Winapi.Windows.hpp>
#include <sevenzip.hpp>

//-- user supplied -----------------------------------------------------------

namespace Mmarchiveengine
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TMMArchiveEngine;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TMMArchiveEngine : public System::TObject
{
	typedef System::TObject inherited;

private:
	Sevenzip::_di_I7zInArchive FArchive;
	System::UnicodeString FName;
	int __fastcall GetCount();
	System::UnicodeString __fastcall GetItemPath(int Index);
	__int64 __fastcall GetItemSize(int Index);
	__int64 __fastcall GetItemPackedSize(int Index);
	bool __fastcall GetItemIsFolder(int Index);
	System::TDateTime __fastcall GetItemDate(int Index);
	unsigned __fastcall GetItemCRC(int Index);
	bool __fastcall GetItemEncrypted(int Index);
	void __fastcall CheckIndex(int Index);

public:
	__fastcall TMMArchiveEngine();
	__fastcall virtual ~TMMArchiveEngine();
	void __fastcall Open(const System::UnicodeString FileName);
	void __fastcall Close();
	void __fastcall ExtractItemToFile(int Index, const System::UnicodeString Destination);
	static System::UnicodeString __fastcall SafeRelativePath(const System::UnicodeString MemberPath);
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString ItemPath[int Index] = {read=GetItemPath};
	__property __int64 ItemSize[int Index] = {read=GetItemSize};
	__property __int64 ItemPackedSize[int Index] = {read=GetItemPackedSize};
	__property bool ItemIsFolder[int Index] = {read=GetItemIsFolder};
	__property System::TDateTime ItemDate[int Index] = {read=GetItemDate};
	__property unsigned ItemCRC[int Index] = {read=GetItemCRC};
	__property bool ItemEncrypted[int Index] = {read=GetItemEncrypted};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Mmarchiveengine */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_MMARCHIVEENGINE)
using namespace Mmarchiveengine;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MMArchiveEngineHPP
