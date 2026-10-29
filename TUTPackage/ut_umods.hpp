// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ut_umods.pas' rev: 37.00 (Windows)

#ifndef ut_umodsHPP
#define ut_umodsHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ut_umods
{
//-- forward type declarations -----------------------------------------------
struct TUMODHeader;
struct TUMODFileData;
class DELPHICLASS TUMOD;
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD TUMODHeader
{
public:
	unsigned Magic;
	unsigned DirectoryStart;
	int UMODSize;
	unsigned Version;
	unsigned CRC;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD TUMODFileData
{
public:
	System::UnicodeString Name;
	unsigned Start;
	unsigned Size;
	unsigned Flags;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TUMOD : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TUMODFileData> _TUMOD__1;
	
	
private:
	System::UnicodeString FFilename;
	TUMODHeader FDirectoryHeader;
	_TUMOD__1 FFiles;
	System::UnicodeString FDescription;
	int __fastcall umod_read_idx(System::Classes::TStream* stream);
	int __fastcall GetCount();
	System::UnicodeString __fastcall GetFiles(int i);
	int __fastcall GetFileSize(int i);
	System::UnicodeString __fastcall GetDescription();
	
public:
	__fastcall TUMOD();
	bool __fastcall IsUMOD(System::UnicodeString filename);
	void __fastcall Load(System::UnicodeString filename);
	void __fastcall ExtractAll(System::UnicodeString destination);
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString Files[int i] = {read=GetFiles};
	__property int Size[int i] = {read=GetFileSize};
	__property System::UnicodeString Filename = {read=FFilename};
	__property System::UnicodeString Description = {read=FDescription};
	void __fastcall Extract(int f, System::UnicodeString destination)/* overload */;
	void __fastcall Extract(System::UnicodeString f, System::UnicodeString destination)/* overload */;
	void __fastcall Extract(System::UnicodeString f, System::Classes::TStream* destination)/* overload */;
	void __fastcall Extract(int f, System::Classes::TStream* destination)/* overload */;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TUMOD() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Ut_umods */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UT_UMODS)
using namespace Ut_umods;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ut_umodsHPP
