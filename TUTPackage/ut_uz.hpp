// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ut_uz.pas' rev: 37.00 (Windows)

#ifndef ut_uzHPP
#define ut_uzHPP

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
#include <System.SysUtils.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ut_uz
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TUZFile;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TUZFile : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FSignature;
	System::UnicodeString FFilename;
	System::UnicodeString FOriginalFilename;
	
public:
	__fastcall TUZFile(System::UnicodeString filename);
	void __fastcall Decode(System::Classes::TStream* stream);
	__property System::UnicodeString Filename = {read=FFilename};
	__property System::UnicodeString OriginalFilename = {read=FOriginalFilename};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TUZFile() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Ut_uz */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UT_UZ)
using namespace Ut_uz;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ut_uzHPP
