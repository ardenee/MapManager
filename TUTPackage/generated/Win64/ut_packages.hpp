// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ut_packages.pas' rev: 37.00 (Windows)

#ifndef ut_packagesHPP
#define ut_packagesHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Types.hpp>
#include <System.Math.hpp>
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Ut_packages
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS EInvalidUTPackage;
class DELPHICLASS EProcessingUTPackage;
class DELPHICLASS EReadingUTProperty;
class DELPHICLASS EUnknownUTOpcode;
class DELPHICLASS EInvalidUTNativeIndex;
class DELPHICLASS EUnknownObjectFormat;
struct TNativeFunction;
class DELPHICLASS TUTProperty;
class DELPHICLASS TUTPropertyList;
class DELPHICLASS TUTObject;
class DELPHICLASS TUTObjectClassField;
class DELPHICLASS TUTObjectClassEnum;
class DELPHICLASS TUTObjectClassConst;
class DELPHICLASS TUTObjectClassProperty;
class DELPHICLASS TUTObjectClassByteProperty;
class DELPHICLASS TUTObjectClassIntProperty;
class DELPHICLASS TUTObjectClassBoolProperty;
class DELPHICLASS TUTObjectClassFloatProperty;
class DELPHICLASS TUTObjectClassNameProperty;
class DELPHICLASS TUTObjectClassStrProperty;
class DELPHICLASS TUTObjectClassStringProperty;
class DELPHICLASS TUTObjectClassObjectProperty;
class DELPHICLASS TUTObjectClassClassProperty;
class DELPHICLASS TUTObjectClassFixedArrayProperty;
class DELPHICLASS TUTObjectClassArrayProperty;
class DELPHICLASS TUTObjectClassMapProperty;
class DELPHICLASS TUTObjectClassStructProperty;
class DELPHICLASS TUTObjectClassDelegateProperty;
class DELPHICLASS TUTObjectClassPointerProperty;
struct TUT_Struct_LabelEntry;
class DELPHICLASS TUTObjectClassStruct;
class DELPHICLASS TUTObjectClassState;
struct TUT_Struct_Dependency;
class DELPHICLASS TUTObjectClassClass;
class DELPHICLASS TUTObjectClassPalette;
class DELPHICLASS TUTObjectClassSound;
class DELPHICLASS TUTObjectClassProceduralSound;
class DELPHICLASS TUTObjectClassSoundGroup;
class DELPHICLASS TUTObjectClassMusic;
class DELPHICLASS TUTObjectClassTextBuffer;
struct TUT_Struct_FontCharacter;
struct TUT_Struct_Map;
class DELPHICLASS TUTObjectClassFont;
struct TUT_Struct_Vector;
struct TUT_Struct_Plane;
struct TUT_Struct_Rotator;
struct TUT_Struct_Polygon;
class DELPHICLASS TUTBitmap;
class DELPHICLASS TUTObjectClassTexture;
struct TUT_Struct_Spark;
class DELPHICLASS TUTObjectClassFireTexture;
class DELPHICLASS TUTObjectClassIceTexture;
class DELPHICLASS TUTObjectClassWaterTexture;
class DELPHICLASS TUTObjectClassWetTexture;
class DELPHICLASS TUTObjectClassWaveTexture;
class DELPHICLASS TUTObjectClassFluidTexture;
class DELPHICLASS TUTObjectClassScriptedTexture;
class DELPHICLASS TUTObjectClassMovieTexture;
class DELPHICLASS TUTObjectClassCubeMap;
struct TUT_Struct_BoundingBox;
struct TUT_Struct_BoundingSphere;
struct TUT_MeshExporter_Material;
struct TUT_MeshExporter_Vertex;
struct TUT_MeshExporter_Face;
struct TUT_MeshExporter_Object;
class DELPHICLASS TUT_MeshExporter;
class DELPHICLASS TUT_3DStudioExporter;
class DELPHICLASS TUT_Unreal3DExporter;
class DELPHICLASS TUTObjectClassPrimitive;
class DELPHICLASS TUTObjectClassIndexBuffer;
class DELPHICLASS TUTObjectClassVertexBuffer;
class DELPHICLASS TUTObjectClassPolys;
class DELPHICLASS TUTObjectClassBrush;
class DELPHICLASS TUTObjectClassMover;
class DELPHICLASS TUTObjectClassConvexVolume;
struct TUT_Struct_FVert;
struct TUT_Struct_BspNode;
struct TUT_Struct_BspSurf;
struct TUT_Struct_LightMapIndex;
struct TUT_Struct_Leaf;
struct TUT_Struct_ZoneProperties;
class DELPHICLASS TUTObjectClassModel;
struct TUT_Struct_URL;
class DELPHICLASS TUTObjectClassLevelBase;
struct TUT_Struct_ReachSpec;
class DELPHICLASS TUTObjectClassLevel;
struct TUT_Struct_Vert;
struct TUT_Struct_Tri;
struct TUT_Struct_Texture;
struct TUT_Struct_AnimSeqNotify;
struct TUT_Struct_AnimSeq;
struct TUT_Struct_Connects;
class DELPHICLASS TUTObjectClassMesh;
struct TUT_Struct_Wedge;
struct TUT_Struct_Face;
struct TUT_Struct_Material;
class DELPHICLASS TUTObjectClassLodMesh;
class DELPHICLASS TUTObjectClassVertMesh;
struct TUT_Struct_MeshFloatUV;
struct TUT_Struct_MeshExtWedge;
struct TUT_Struct_Quat;
struct TUT_Struct_JointPos;
struct TUT_Struct_MeshBone;
struct TUT_Struct_BoneInfIndex;
struct TUT_Struct_BoneInfluence;
struct TUT_Struct_Coords;
class DELPHICLASS TUTObjectClassStaticMesh;
class DELPHICLASS TUTObjectClassSkeletalMesh;
struct TUT_Struct_NamedBone;
struct TUT_Struct_AnalogTrack;
struct TUT_Struct_MotionChunk;
class DELPHICLASS TUTObjectClassAnimation;
class DELPHICLASS TUTObjectClassMeshAnimation;
class DELPHICLASS TUTObjectClassFunction;
class DELPHICLASS TUTObjectClassPackageCheckInfo;
class DELPHICLASS TUTImportTableObjectData;
class DELPHICLASS TUTExportTableObjectData;
struct TUTPackage_GenerationInfo;
struct TUTPackageSection;
class DELPHICLASS TUTPackage;
struct TKnownStructElement;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TUTPackage_GameHint : unsigned char { UTPGH_NotSpecified, UTPGH_Unreal, UTPGH_UnrealTournament, UTPGH_TheWheelOfTime, UTPGH_KlingonHonorGuard, UTPGH_Rune, UTPGH_Undying, UTPGH_DeusEx, UTPGH_XComEnforcer, UTPGH_DeepSpaceNine, UTPGH_NerfArenaBlast, UTPGH_UnrealTournament2003, UTPGH_ArmyOperations, UTPGH_HarryPotterSorcerersStone, UTPGH_HarryPotterChamberSecrets, UTPGH_Unreal2, UTPGH_SplinterCell, UTPGH_Devastation, UTPGH_Rainbow6RavenShield, UTPGH_UnrealChampionship, UTPGH_Lineage2, UTPGH_Postal2, UTPGH_UnrealEngine2Runtime, UTPGH_DeusExInvisibleWar, UTPGH_DesertThunder, UTPGH_UnrealTournament2004, UTPGH_XIII };

typedef System::StaticArray<System::UnicodeString, 27> Ut_packages__1;

class PASCALIMPLEMENTATION EInvalidUTPackage : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidUTPackage(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidUTPackage(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidUTPackage(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidUTPackage(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidUTPackage(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidUTPackage(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidUTPackage(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidUTPackage(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidUTPackage(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidUTPackage(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidUTPackage(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidUTPackage(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidUTPackage() { }
	
};


class PASCALIMPLEMENTATION EProcessingUTPackage : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EProcessingUTPackage(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EProcessingUTPackage(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EProcessingUTPackage(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EProcessingUTPackage(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EProcessingUTPackage(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EProcessingUTPackage(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EProcessingUTPackage(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EProcessingUTPackage(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EProcessingUTPackage(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EProcessingUTPackage(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EProcessingUTPackage(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EProcessingUTPackage(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EProcessingUTPackage() { }
	
};


class PASCALIMPLEMENTATION EReadingUTProperty : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EReadingUTProperty(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EReadingUTProperty(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EReadingUTProperty(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EReadingUTProperty(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EReadingUTProperty(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EReadingUTProperty(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EReadingUTProperty(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EReadingUTProperty(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EReadingUTProperty(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EReadingUTProperty(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EReadingUTProperty(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EReadingUTProperty(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EReadingUTProperty() { }
	
};


class PASCALIMPLEMENTATION EUnknownUTOpcode : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EUnknownUTOpcode(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EUnknownUTOpcode(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EUnknownUTOpcode(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EUnknownUTOpcode(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EUnknownUTOpcode(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EUnknownUTOpcode(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EUnknownUTOpcode(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EUnknownUTOpcode(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EUnknownUTOpcode(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EUnknownUTOpcode(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnknownUTOpcode(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnknownUTOpcode(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EUnknownUTOpcode() { }
	
};


class PASCALIMPLEMENTATION EInvalidUTNativeIndex : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EInvalidUTNativeIndex(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EInvalidUTNativeIndex(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidUTNativeIndex(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EInvalidUTNativeIndex(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidUTNativeIndex(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EInvalidUTNativeIndex(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EInvalidUTNativeIndex(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidUTNativeIndex(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidUTNativeIndex(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EInvalidUTNativeIndex(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidUTNativeIndex(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidUTNativeIndex(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EInvalidUTNativeIndex() { }
	
};


class PASCALIMPLEMENTATION EUnknownObjectFormat : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EUnknownObjectFormat(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EUnknownObjectFormat(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High) : System::Sysutils::Exception(Msg, Args, Args_High) { }
	/* Exception.CreateRes */ inline __fastcall EUnknownObjectFormat(System::NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EUnknownObjectFormat(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EUnknownObjectFormat(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High) { }
	/* Exception.CreateResFmt */ inline __fastcall EUnknownObjectFormat(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High) { }
	/* Exception.CreateHelp */ inline __fastcall EUnknownObjectFormat(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EUnknownObjectFormat(const System::UnicodeString Msg, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EUnknownObjectFormat(System::NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EUnknownObjectFormat(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnknownObjectFormat(System::PResStringRec ResStringRec, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_High, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnknownObjectFormat(System::NativeUInt Ident, const System::TVarRec *Args, const System::NativeInt Args_High, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_High, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EUnknownObjectFormat() { }
	
};


struct DECLSPEC_DRECORD TNativeFunction
{
public:
	int Index;
	System::Byte Format;
	System::Byte OperatorPrecedence;
	System::UnicodeString Name;
};


typedef System::DynamicArray<TNativeFunction> TNativeFunctions;

typedef unsigned TUTPropertyType;

class PASCALIMPLEMENTATION TUTProperty : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<System::Byte> _TUTProperty__1;
	
	
private:
	bool FIsInitialized;
	TUTPackage* FOwner;
	TUTObject* FOwnerObject;
	int __fastcall GetArrayTypeLength();
	
protected:
	System::UnicodeString FName;
	int FArrayIndex;
	TUTPropertyType FPropertyType;
	_TUTProperty__1 FValue;
	System::UnicodeString FTypeName;
	virtual System::Variant __fastcall GetFirstValue();
	virtual System::UnicodeString __fastcall GetTypeName();
	virtual System::UnicodeString __fastcall GetDescription();
	virtual System::UnicodeString __fastcall GetDescriptiveValue();
	
public:
	void __fastcall SetOwnerObject(TUTObject* ownerobject);
	virtual void __fastcall SetProperty(TUTPackage* Owner, System::UnicodeString n, int i, TUTPropertyType t, void *value, int valuesize, System::UnicodeString _typename = System::UnicodeString());
	__property System::UnicodeString Name = {read=FName};
	__property int ArrayIndex = {read=FArrayIndex, nodefault};
	__property int ArrayTypeLength = {read=GetArrayTypeLength, nodefault};
	__property System::Variant Value = {read=GetFirstValue};
	__property System::UnicodeString DescriptiveValue = {read=GetDescriptiveValue};
	__property TUTPropertyType PropertyType = {read=FPropertyType, nodefault};
	__property System::UnicodeString Description = {read=GetDescription};
	__property System::UnicodeString GenericTypeName = {read=FTypeName};
	__property System::UnicodeString SpecificTypeName = {read=GetTypeName};
	int __fastcall ValueCount();
	virtual void __fastcall GetValue(int ai, int i, System::UnicodeString &valuename, System::Variant &value, System::UnicodeString &descriptivevalue, TUTPropertyType &valuetype, System::UnicodeString &valuetypename);
	virtual System::UnicodeString __fastcall GetValueTypeName(TUTPropertyType t);
public:
	/* TObject.Create */ inline __fastcall TUTProperty() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TUTProperty() { }
	
};


_DECLARE_METACLASS(System::TMetaClass, TUTPropertyClass);

class PASCALIMPLEMENTATION TUTPropertyList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Variant operator[](System::UnicodeString name) { return this->PropertyByNameValue[name]; }
	
private:
	System::Classes::TList* FProperties;
	TUTProperty* __fastcall GetProperty(int i);
	int __fastcall GetPropertyCount();
	TUTProperty* __fastcall NewProperty();
	TUTProperty* __fastcall GetPropertyByName(System::UnicodeString name);
	System::Variant __fastcall GetPropertyByNameValue(System::UnicodeString name);
	System::Variant __fastcall GetPropertyByNameValueDefault(System::UnicodeString name, const System::Variant &adefault);
	System::Variant __fastcall GetPropertyValueDefault(int i, const System::Variant &adefault);
	System::Variant __fastcall GetPropertyValue(int i);
	System::UnicodeString __fastcall GetPropertyListDescriptions();
	
public:
	__fastcall TUTPropertyList();
	__fastcall virtual ~TUTPropertyList();
	__property TUTProperty* New = {read=NewProperty};
	__property int Count = {read=GetPropertyCount, nodefault};
	__property TUTProperty* PropertyByPosition[int i] = {read=GetProperty};
	__property TUTProperty* PropertyByName[System::UnicodeString name] = {read=GetPropertyByName};
	__property System::Variant PropertyByNameValue[System::UnicodeString name] = {read=GetPropertyByNameValue/*, default*/};
	__property System::Variant PropertyByNameValueDefault[System::UnicodeString name][System::Variant adefault] = {read=GetPropertyByNameValueDefault};
	__property System::Variant PropertyByPositionValue[int i] = {read=GetPropertyValue};
	__property System::Variant PropertyByPositionValueDefault[int i][System::Variant adefault] = {read=GetPropertyValueDefault};
	void __fastcall Clear();
	__property System::UnicodeString Descriptions = {read=GetPropertyListDescriptions};
	virtual void __fastcall FixArrayIndices();
};


class PASCALIMPLEMENTATION TUTObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FStartInPackage;
	TUTPackage* Fowner;
	int Fexportedindex;
	bool FHasBeenRead;
	bool FHasBeenInterpreted;
	int FReadCount;
	System::UnicodeString __fastcall Get_ClassName();
	System::UnicodeString __fastcall GetObjectname();
	System::UnicodeString __fastcall GetGroupName();
	System::UnicodeString __fastcall GetSuperName();
	int __fastcall GetClassIndex();
	int __fastcall GetObjectIndex();
	int __fastcall GetGroupIndex();
	int __fastcall GetSuperIndex();
	int __fastcall GetSerialOffset();
	int __fastcall GetSerialSize();
	unsigned __fastcall GetFlags();
	TUTPropertyList* __fastcall GetProperties();
	void __fastcall check_initialized();
	System::UnicodeString __fastcall GetFullName();
	int __fastcall GetPosition();
	void __fastcall SetPosition(const int Value);
	TUTPackage* __fastcall GetOwner();
	int __fastcall GetBufferPosition();
	
protected:
	TUTPropertyList* FProperties;
	System::Classes::TMemoryStream* Buffer;
	int FExtraDataCount;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	virtual void __fastcall DoReleaseObject();
	virtual void __fastcall ReadProperties();
	
public:
	__fastcall virtual TUTObject(TUTPackage* owner, int exportedindex);
	__fastcall virtual ~TUTObject();
	void __fastcall ReadObject(bool interpret = true);
	void __fastcall ReleaseObject();
	void __fastcall RawSaveToFile(System::UnicodeString filename);
	void __fastcall RawSaveToStream(System::Classes::TStream* stream);
	int __fastcall CheckArrayLength(int size);
	__property TUTPackage* Owner = {read=GetOwner};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property bool HasBeenRead = {read=FHasBeenRead, nodefault};
	__property bool HasBeenInterpreted = {read=FHasBeenInterpreted, nodefault};
	__property int ExportedIndex = {read=Fexportedindex, nodefault};
	__property TUTPropertyList* Properties = {read=GetProperties};
	__property int UTObjectIndex = {read=GetObjectIndex, nodefault};
	__property int UTClassIndex = {read=GetClassIndex, nodefault};
	__property int UTGroupIndex = {read=GetGroupIndex, nodefault};
	__property int UTSuperIndex = {read=GetSuperIndex, nodefault};
	__property int UTSerialOffset = {read=GetSerialOffset, nodefault};
	__property int UTSerialSize = {read=GetSerialSize, nodefault};
	__property unsigned UTFlags = {read=GetFlags, nodefault};
	__property System::UnicodeString UTObjectName = {read=GetObjectname};
	__property System::UnicodeString UTClassName = {read=Get_ClassName};
	__property System::UnicodeString UTGroupName = {read=GetGroupName};
	__property System::UnicodeString UTSuperName = {read=GetSuperName};
	__property System::UnicodeString UTFullName = {read=GetFullName};
	__property int ExtraDataCount = {read=FExtraDataCount, nodefault};
	__property int BufferPosition = {read=GetBufferPosition, nodefault};
};


_DECLARE_METACLASS(System::TMetaClass, TUTObjectClass);

class PASCALIMPLEMENTATION TUTObjectClassField : public TUTObject
{
	typedef TUTObject inherited;
	
private:
	int FSuperField;
	int FNext;
	int __fastcall GetNext();
	int __fastcall GetSuperField();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int SuperField = {read=GetSuperField, nodefault};
	__property int Next = {read=GetNext, nodefault};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassField(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassField() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassEnum : public TUTObjectClassField
{
	typedef TUTObjectClassField inherited;
	
	
private:
	typedef System::DynamicArray<int> _TUTObjectClassEnum__1;
	
	
private:
	_TUTObjectClassEnum__1 FValues;
	int __fastcall GetCount();
	int __fastcall GetValue(int i);
	System::UnicodeString __fastcall GetValueName(int i);
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int Count = {read=GetCount, nodefault};
	__property int EnumValue[int i] = {read=GetValue};
	__property System::UnicodeString EnumName[int i] = {read=GetValueName};
	System::UnicodeString __fastcall GetDeclaration();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassEnum(TUTPackage* owner, int exportedindex) : TUTObjectClassField(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassEnum() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassConst : public TUTObjectClassField
{
	typedef TUTObjectClassField inherited;
	
private:
	System::UnicodeString FValue;
	System::UnicodeString __fastcall GetValue();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property System::UnicodeString Value = {read=GetValue};
	System::UnicodeString __fastcall GetDeclaration();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassConst(TUTPackage* owner, int exportedindex) : TUTObjectClassField(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassConst() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassProperty : public TUTObjectClassField
{
	typedef TUTObjectClassField inherited;
	
private:
	int FArrayDimension;
	int FElementSize;
	unsigned FPropertyFlags;
	System::UnicodeString FCategory;
	System::Word FRepOffset;
	System::UnicodeString FComment;
	int __fastcall GetArrayDimension();
	System::UnicodeString __fastcall GetCategory();
	int __fastcall GetElementSize();
	unsigned __fastcall GetPropertyFlags();
	System::Word __fastcall GetRepOffset();
	System::UnicodeString __fastcall GetComment();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int ArrayDimension = {read=GetArrayDimension, nodefault};
	__property int ElementSize = {read=GetElementSize, nodefault};
	__property unsigned PropertyFlags = {read=GetPropertyFlags, nodefault};
	__property System::UnicodeString Category = {read=GetCategory};
	__property System::Word ReplicationOffset = {read=GetRepOffset, nodefault};
	__property System::UnicodeString Comment = {read=GetComment};
	virtual System::UnicodeString __fastcall GenericTypeName();
	HIDESBASE System::UnicodeString __fastcall GetFlags(System::UnicodeString cn);
	System::UnicodeString __fastcall GetDeclaration(System::UnicodeString context, System::UnicodeString cn);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassField(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassByteProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FEnum;
	int __fastcall GetEnum();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int Enum = {read=GetEnum, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassByteProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassByteProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassIntProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FMin;
	int FMax;
	int FIncrement;
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	virtual System::UnicodeString __fastcall GenericTypeName();
	__property int Min = {read=FMin, nodefault};
	__property int Max = {read=FMax, nodefault};
	__property int Increment = {read=FIncrement, nodefault};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassIntProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassIntProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassBoolProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassBoolProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassBoolProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassFloatProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	double FMin;
	double FMax;
	double FIncrement;
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	virtual System::UnicodeString __fastcall GenericTypeName();
	__property double Min = {read=FMin};
	__property double Max = {read=FMax};
	__property double Increment = {read=FIncrement};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassFloatProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassFloatProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassNameProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassNameProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassNameProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassStrProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassStrProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassStrProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassStringProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassStringProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassStringProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassObjectProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FObject;
	int __fastcall GetObject();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int UTObjectType = {read=GetObject, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassObjectProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassObjectProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassClassProperty : public TUTObjectClassObjectProperty
{
	typedef TUTObjectClassObjectProperty inherited;
	
private:
	int FClass;
	int __fastcall GetClass();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int UTClassType = {read=GetClass, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassClassProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassObjectProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassClassProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassFixedArrayProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FInner;
	int FCount;
	int __fastcall GetCount();
	int __fastcall GetInner();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int ElementCount = {read=GetCount, nodefault};
	__property int InnerProperty = {read=GetInner, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassFixedArrayProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassFixedArrayProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassArrayProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FInner;
	int __fastcall GetInner();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int InnerProperty = {read=GetInner, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassArrayProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassArrayProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassMapProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FKey;
	int FValue;
	int __fastcall GetKey();
	int __fastcall GetValue();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int KeyProperty = {read=GetKey, nodefault};
	__property int ValueProperty = {read=GetValue, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassMapProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassMapProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassStructProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FStruct;
	int __fastcall GetStruct();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int Struct = {read=GetStruct, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassStructProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassStructProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassDelegateProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
private:
	int FEvent;
	int __fastcall GetEvent();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int Event = {read=GetEvent, nodefault};
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassDelegateProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassDelegateProperty() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassPointerProperty : public TUTObjectClassProperty
{
	typedef TUTObjectClassProperty inherited;
	
public:
	virtual System::UnicodeString __fastcall GenericTypeName();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassPointerProperty(TUTPackage* owner, int exportedindex) : TUTObjectClassProperty(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassPointerProperty() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_LabelEntry
{
public:
	int Name;
	int iCode;
};


class PASCALIMPLEMENTATION TUTObjectClassStruct : public TUTObjectClassField
{
	typedef TUTObjectClassField inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_LabelEntry> _TUTObjectClassStruct__1;
	
	
private:
	int FScriptText;
	int FChildren;
	System::UnicodeString FFriendlyName;
	unsigned FLine;
	unsigned FTextPos;
	unsigned FScriptSize;
	bool prev_is_iteratornext;
	bool next_is_not_delegate;
	int __fastcall GetChildren();
	System::UnicodeString __fastcall GetFriendlyName();
	unsigned __fastcall GetLine();
	unsigned __fastcall GetScriptSize();
	int __fastcall GetScriptText();
	unsigned __fastcall GetTextPos();
	System::UnicodeString __fastcall ReadStatement();
	
protected:
	int FScriptStart;
	System::Classes::TList* jumplist;
	System::Classes::TList* nest;
	System::Classes::TStringList* endnestlist;
	System::UnicodeString labellist;
	System::UnicodeString indent_chars;
	bool need_semicolon;
	bool context_change;
	unsigned position_icode;
	unsigned last_position_icode;
	int indent_level;
	_TUTObjectClassStruct__1 FLabelTable;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	virtual void __fastcall DoReleaseObject();
	System::UnicodeString __fastcall ReadStatements(bool beautify = true, bool showoffsets = false)/* overload */;
	void __fastcall ReadStatements(System::Classes::TStrings* code, bool beautify = true, bool showoffsets = false)/* overload */;
	void __fastcall SkipStatements();
	
public:
	__property int ScriptText = {read=GetScriptText, nodefault};
	__property int FirstChild = {read=GetChildren, nodefault};
	__property System::UnicodeString FriendlyName = {read=GetFriendlyName};
	__property unsigned Line = {read=GetLine, nodefault};
	__property unsigned TextPos = {read=GetTextPos, nodefault};
	__property unsigned ScriptSize = {read=GetScriptSize, nodefault};
	System::UnicodeString __fastcall GetDeclaration();
	System::UnicodeString __fastcall ReadToken(System::Byte OuterOperatorPrecedence = (System::Byte)(0xff));
	virtual System::UnicodeString __fastcall Decompile(bool beautify = true, bool showoffsets = false)/* overload */;
	virtual void __fastcall Decompile(System::Classes::TStrings* code, bool beautify = true, bool showoffsets = false)/* overload */;
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassStruct(TUTPackage* owner, int exportedindex) : TUTObjectClassField(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassStruct() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassState : public TUTObjectClassStruct
{
	typedef TUTObjectClassStruct inherited;
	
private:
	__int64 FProbeMask;
	__int64 FIgnoreMask;
	System::Word FLabelTableOffset;
	unsigned FStateFlags;
	__int64 __fastcall GetIgnoreMask();
	System::Word __fastcall GetLabelTableOffset();
	__int64 __fastcall GetProbeMask();
	unsigned __fastcall GetStateFlags();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property __int64 ProbeMask = {read=GetProbeMask};
	__property __int64 IgnoreMask = {read=GetIgnoreMask};
	__property System::Word LabelTableOffset = {read=GetLabelTableOffset, nodefault};
	__property unsigned StateFlags = {read=GetStateFlags, nodefault};
	virtual System::UnicodeString __fastcall Decompile(bool beautify = true, bool showoffsets = false)/* overload */;
	virtual void __fastcall Decompile(System::Classes::TStrings* code, bool beautify = true, bool showoffsets = false)/* overload */;
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassState(TUTPackage* owner, int exportedindex) : TUTObjectClassStruct(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassState() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_Dependency
{
public:
	int _Class;
	int Deep;
	int ScriptTextCRC;
};


class PASCALIMPLEMENTATION TUTObjectClassClass : public TUTObjectClassState
{
	typedef TUTObjectClassState inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_Dependency> _TUTObjectClassClass__1;
	
	typedef System::DynamicArray<int> _TUTObjectClassClass__2;
	
	typedef System::DynamicArray<int> _TUTObjectClassClass__3;
	
	
private:
	unsigned FClassFlags;
	GUID FClassGuid;
	_TUTObjectClassClass__1 FDependencies;
	_TUTObjectClassClass__2 FPackageImports;
	int FClassWithin;
	int FClassConfigName;
	_TUTObjectClassClass__3 FHideCategoriesList;
	TUT_Struct_Dependency __fastcall GetDependencies(int i);
	int __fastcall GetPackageImports(int i);
	int __fastcall GetClassConfigName();
	unsigned __fastcall GetClassFlags();
	GUID __fastcall GetClassGuid();
	int __fastcall GetClassWithin();
	int __fastcall GetDependencyCount();
	int __fastcall GetPackageImportsCount();
	int __fastcall GetHideCategoriesList(int i);
	int __fastcall GetHideCategoriesListCount();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	virtual System::UnicodeString __fastcall Decompile(bool beautify = true, bool showoffsets = false)/* overload */;
	virtual void __fastcall Decompile(System::Classes::TStrings* code, bool beautify = true, bool showoffsets = false)/* overload */;
	System::UnicodeString __fastcall GetSource(bool beautify = true, bool showoffsets = false);
	void __fastcall SaveToFile(System::UnicodeString Filename);
	__property unsigned ClassFlags = {read=GetClassFlags, nodefault};
	__property GUID ClassGuid = {read=GetClassGuid};
	__property int DependencyCount = {read=GetDependencyCount, nodefault};
	__property TUT_Struct_Dependency Dependencies[int i] = {read=GetDependencies};
	__property int PackageImportsCount = {read=GetPackageImportsCount, nodefault};
	__property int PackageImports[int i] = {read=GetPackageImports};
	__property int ClassWithin = {read=GetClassWithin, nodefault};
	__property int ClassConfigName = {read=GetClassConfigName, nodefault};
	__property int HideCategoriesListCount = {read=GetHideCategoriesListCount, nodefault};
	__property int HideCategoriesList[int i] = {read=GetHideCategoriesList};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassClass(TUTPackage* owner, int exportedindex) : TUTObjectClassState(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassClass() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassPalette : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<tagRGBQUAD> _TUTObjectClassPalette__1;
	
	
private:
	int FColorCount;
	_TUTObjectClassPalette__1 FColors;
	System::Uitypes::TColor __fastcall GetColor(int n);
	HPALETTE __fastcall GetNewPalette();
	int __fastcall GetColorCount();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int ColorCount = {read=GetColorCount, nodefault};
	__property System::Uitypes::TColor Color[int n] = {read=GetColor};
	__property HPALETTE GetPalette = {read=GetNewPalette};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassPalette(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassPalette() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassSound : public TUTObject
{
	typedef TUTObject inherited;
	
private:
	System::UnicodeString FFormat;
	System::UnicodeString FData;
	System::UnicodeString __fastcall GetData();
	System::UnicodeString __fastcall GetFormat();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property System::UnicodeString Format = {read=GetFormat};
	__property System::UnicodeString Data = {read=GetData};
	void __fastcall SaveToFile(System::UnicodeString filename);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassSound(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassSound() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassProceduralSound : public TUTObject
{
	typedef TUTObject inherited;
	
private:
	int FBaseSound;
	double FPitchModification;
	double FVolumeModification;
	double FPitchVariance;
	double FVolumeVariance;
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int BaseSound = {read=FBaseSound, nodefault};
	__property double PitchModification = {read=FPitchModification};
	__property double VolumeModification = {read=FVolumeModification};
	__property double PitchVariance = {read=FPitchVariance};
	__property double VolumeVariance = {read=FVolumeVariance};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassProceduralSound(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassProceduralSound() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassSoundGroup : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<int> _TUTObjectClassSoundGroup__1;
	
	
private:
	_TUTObjectClassSoundGroup__1 FSounds;
	int __fastcall GetSound(int i);
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int Sounds[int i] = {read=GetSound};
	int __fastcall SoundCount();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassSoundGroup(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassSoundGroup() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassMusic : public TUTObject
{
	typedef TUTObject inherited;
	
private:
	System::UnicodeString FFormat;
	System::UnicodeString FData;
	System::UnicodeString __fastcall GetData();
	System::UnicodeString __fastcall GetFormat();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property System::UnicodeString Format = {read=GetFormat};
	__property System::UnicodeString Data = {read=GetData};
	void __fastcall SaveToFile(System::UnicodeString filename);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassMusic(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassMusic() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassTextBuffer : public TUTObject
{
	typedef TUTObject inherited;
	
private:
	System::UnicodeString FData;
	System::UnicodeString __fastcall GetData();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property System::UnicodeString Data = {read=GetData};
	void __fastcall SaveToFile(System::UnicodeString filename);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassTextBuffer(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassTextBuffer() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_FontCharacter
{
public:
	int Texture;
	int X;
	int Y;
	int W;
	int H;
};


struct DECLSPEC_DRECORD TUT_Struct_Map
{
public:
	System::UnicodeString Key;
	System::UnicodeString Value;
};


class PASCALIMPLEMENTATION TUTObjectClassFont : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_FontCharacter> _TUTObjectClassFont__1;
	
	typedef System::DynamicArray<TUT_Struct_Map> _TUTObjectClassFont__2;
	
	
private:
	_TUTObjectClassFont__1 FCharacters;
	_TUTObjectClassFont__2 FCharRemap;
	bool FIsRemapped;
	int FCharactersPerPage;
	int FKerning;
	int FDropShadowX;
	int FDropShadowY;
	int FStyle;
	bool FAntiAlias;
	System::UnicodeString __fastcall GetGetMapping(System::WideChar c);
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	void __fastcall GetCharacterInfo(int i, int &texture, int &x, int &y, int &w, int &h);
	__property System::UnicodeString GetMapping[System::WideChar c] = {read=GetGetMapping};
	__property bool IsRemapped = {read=FIsRemapped, nodefault};
	__property int CharactersPerPage = {read=FCharactersPerPage, nodefault};
	__property int Kerning = {read=FKerning, nodefault};
	__property int DropShadowX = {read=FDropShadowX, nodefault};
	__property int DropShadowY = {read=FDropShadowY, nodefault};
	__property int Style = {read=FStyle, nodefault};
	__property bool AntiAlias = {read=FAntiAlias, nodefault};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassFont(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassFont() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_Vector
{
public:
	float X;
	float Y;
	float Z;
};


struct DECLSPEC_DRECORD TUT_Struct_Plane
{
public:
	float X;
	float Y;
	float Z;
	float W;
};


struct DECLSPEC_DRECORD TUT_Struct_Rotator
{
public:
	int Yaw;
	int Roll;
	int Pitch;
};


struct DECLSPEC_DRECORD TUT_Struct_Polygon
{
	
private:
	typedef System::DynamicArray<TUT_Struct_Vector> _TUT_Struct_Polygon__1;
	
	
public:
	TUT_Struct_Vector Base;
	TUT_Struct_Vector Normal;
	TUT_Struct_Vector TextureU;
	TUT_Struct_Vector TextureV;
	_TUT_Struct_Polygon__1 Vertex;
	int PolyFlags;
	int Actor;
	int Texture;
	int ItemName;
	int iLink;
	int iBrushPoly;
	int pan_u;
	int pan_v;
};


class PASCALIMPLEMENTATION TUTBitmap : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FWidth;
	int FHeight;
	int FBPP;
	bool FMasked;
	void *FData;
	HPALETTE FPalette;
	void *FOriginalData;
	int FOriginalDataSize;
	int FOriginalFormat;
	void * __fastcall GetScanLine(int y);
	void __fastcall SetPalette(const HPALETTE Value);
	
public:
	__fastcall TUTBitmap(unsigned width, unsigned height, unsigned bpp, bool masked);
	__fastcall virtual ~TUTBitmap();
	__property int Width = {read=FWidth, nodefault};
	__property int Height = {read=FHeight, nodefault};
	__property int BPP = {read=FBPP, nodefault};
	__property HPALETTE Palette = {read=FPalette, write=SetPalette};
	__property void * ScanLine[int y] = {read=GetScanLine};
	Vcl::Graphics::TBitmap* __fastcall AsBitmap();
	Vcl::Graphics::TBitmap* __fastcall AsBitmapWithAlpha();
	Vcl::Graphics::TBitmap* __fastcall AsAlpha();
	void __fastcall SetOriginal(int format, void *buffer, __int64 size);
	__property void * OriginalData = {read=FOriginalData};
	__property int OriginalDataSize = {read=FOriginalDataSize, nodefault};
	__property int OriginalFormat = {read=FOriginalFormat, nodefault};
};


class PASCALIMPLEMENTATION TUTObjectClassTexture : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<TUTBitmap*> _TUTObjectClassTexture__1;
	
	typedef System::DynamicArray<TUTBitmap*> _TUTObjectClassTexture__2;
	
	
private:
	_TUTObjectClassTexture__1 FMipMaps;
	_TUTObjectClassTexture__2 FCompMipMaps;
	int __fastcall GetMipMapCount();
	TUTBitmap* __fastcall GetMipMap(int i);
	int __fastcall GetCompMipMapCount();
	TUTBitmap* __fastcall GetCompMipMap(int i);
	TUTBitmap* __fastcall GetGoodMipMap(int i);
	int __fastcall GetGoodMipMapCount();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	virtual void __fastcall DoReleaseObject();
	
public:
	__property int MipMapCount = {read=GetMipMapCount, nodefault};
	__property TUTBitmap* MipMap[int i] = {read=GetMipMap};
	__property int CompMipMapCount = {read=GetCompMipMapCount, nodefault};
	__property TUTBitmap* CompMipMap[int i] = {read=GetCompMipMap};
	__property int GoodMipMapCount = {read=GetGoodMipMapCount, nodefault};
	__property TUTBitmap* GoodMipMap[int i] = {read=GetGoodMipMap};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassTexture(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassTexture() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_Spark
{
public:
	System::Byte SparkType;
	System::Byte Heat;
	System::Byte X;
	System::Byte Y;
	System::Byte X_Speed;
	System::Byte Y_Speed;
	System::Byte Age;
	System::Byte ExpTime;
};


class PASCALIMPLEMENTATION TUTObjectClassFireTexture : public TUTObjectClassTexture
{
	typedef TUTObjectClassTexture inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_Spark> _TUTObjectClassFireTexture__1;
	
	
private:
	_TUTObjectClassFireTexture__1 FSparks;
	TUT_Struct_Spark __fastcall GetSpark(int i);
	int __fastcall GetSparkCount();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int SparkCount = {read=GetSparkCount, nodefault};
	__property TUT_Struct_Spark Spark[int i] = {read=GetSpark};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassFireTexture(TUTPackage* owner, int exportedindex) : TUTObjectClassTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassFireTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassIceTexture : public TUTObjectClassTexture
{
	typedef TUTObjectClassTexture inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassIceTexture(TUTPackage* owner, int exportedindex) : TUTObjectClassTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassIceTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassWaterTexture : public TUTObjectClassTexture
{
	typedef TUTObjectClassTexture inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassWaterTexture(TUTPackage* owner, int exportedindex) : TUTObjectClassTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassWaterTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassWetTexture : public TUTObjectClassWaterTexture
{
	typedef TUTObjectClassWaterTexture inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassWetTexture(TUTPackage* owner, int exportedindex) : TUTObjectClassWaterTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassWetTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassWaveTexture : public TUTObjectClassWaterTexture
{
	typedef TUTObjectClassWaterTexture inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassWaveTexture(TUTPackage* owner, int exportedindex) : TUTObjectClassWaterTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassWaveTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassFluidTexture : public TUTObjectClassWaterTexture
{
	typedef TUTObjectClassWaterTexture inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassFluidTexture(TUTPackage* owner, int exportedindex) : TUTObjectClassWaterTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassFluidTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassScriptedTexture : public TUTObject
{
	typedef TUTObject inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassScriptedTexture(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassScriptedTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassMovieTexture : public TUTObjectClassTexture
{
	typedef TUTObjectClassTexture inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassMovieTexture(TUTPackage* owner, int exportedindex) : TUTObjectClassTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassMovieTexture() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassCubeMap : public TUTObjectClassTexture
{
	typedef TUTObjectClassTexture inherited;
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassCubeMap(TUTPackage* owner, int exportedindex) : TUTObjectClassTexture(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassCubeMap() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_BoundingBox
{
public:
	TUT_Struct_Vector Min;
	TUT_Struct_Vector Max;
	System::Byte Valid;
};


struct DECLSPEC_DRECORD TUT_Struct_BoundingSphere
{
public:
	TUT_Struct_Vector Center;
	float Radius;
};


enum DECLSPEC_DENUM TUT_MeshExporter_Animation : unsigned char { exp_anim_MixedInFile, exp_anim_MultiFile };

struct DECLSPEC_DRECORD TUT_MeshExporter_Material
{
public:
	System::UnicodeString Name;
	System::StaticArray<System::Byte, 3> DiffuseColor;
	System::UnicodeString Texture;
};


struct DECLSPEC_DRECORD TUT_MeshExporter_Vertex
{
public:
	float X;
	float Y;
	float Z;
	System::Byte U;
	System::Byte V;
};


struct DECLSPEC_DRECORD TUT_MeshExporter_Face
{
public:
	int VertexIndex1;
	int VertexIndex2;
	int VertexIndex3;
	int MaterialIndex;
	int Flags;
};


struct DECLSPEC_DRECORD TUT_MeshExporter_Object
{
	
private:
	typedef System::DynamicArray<TUT_MeshExporter_Vertex> _TUT_MeshExporter_Object__1;
	
	typedef System::DynamicArray<TUT_MeshExporter_Face> _TUT_MeshExporter_Object__2;
	
	typedef System::DynamicArray<TUT_MeshExporter_Material> _TUT_MeshExporter_Object__3;
	
	
public:
	_TUT_MeshExporter_Object__1 Vertices;
	_TUT_MeshExporter_Object__2 Faces;
	_TUT_MeshExporter_Object__3 Materials;
	int AnimationFrames;
};


class PASCALIMPLEMENTATION TUT_MeshExporter : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TUT_MeshExporter_Object> _TUT_MeshExporter__1;
	
	
public:
	_TUT_MeshExporter__1 Objects;
	__fastcall TUT_MeshExporter();
	int __fastcall AddObject();
	bool __fastcall AllObjectsSameFrames();
	virtual void __fastcall Save(System::UnicodeString filename) = 0 ;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TUT_MeshExporter() { }
	
};


enum DECLSPEC_DENUM TUT_3DStudioExporter_Smoothing : unsigned char { exp3ds_smooth_None, exp3ds_smooth_One, exp3ds_smooth_exp3ds_smooth_ByMaterial };

class PASCALIMPLEMENTATION TUT_3DStudioExporter : public TUT_MeshExporter
{
	typedef TUT_MeshExporter inherited;
	
public:
	TUT_3DStudioExporter_Smoothing Smoothing;
	bool MirrorX;
	virtual void __fastcall Save(System::UnicodeString filename);
public:
	/* TUT_MeshExporter.Create */ inline __fastcall TUT_3DStudioExporter() : TUT_MeshExporter() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TUT_3DStudioExporter() { }
	
};


class PASCALIMPLEMENTATION TUT_Unreal3DExporter : public TUT_MeshExporter
{
	typedef TUT_MeshExporter inherited;
	
public:
	float CoordsDivisor;
	virtual void __fastcall Save(System::UnicodeString filename);
public:
	/* TUT_MeshExporter.Create */ inline __fastcall TUT_Unreal3DExporter() : TUT_MeshExporter() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TUT_Unreal3DExporter() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassPrimitive : public TUTObject
{
	typedef TUTObject inherited;
	
protected:
	TUT_Struct_BoundingBox FPrimitiveBoundingBox;
	TUT_Struct_BoundingSphere FPrimitiveBoundingSphere;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property TUT_Struct_BoundingBox PrimitiveBoundingBox = {read=FPrimitiveBoundingBox};
	__property TUT_Struct_BoundingSphere PrimitiveBoundingSphere = {read=FPrimitiveBoundingSphere};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassPrimitive(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassPrimitive() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassIndexBuffer : public TUTObject
{
	typedef TUTObject inherited;
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassIndexBuffer(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassIndexBuffer() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassVertexBuffer : public TUTObject
{
	typedef TUTObject inherited;
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassVertexBuffer(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassVertexBuffer() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassPolys : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_Polygon> _TUTObjectClassPolys__1;
	
	
private:
	_TUTObjectClassPolys__1 FPolygons;
	int __fastcall GetPolygonCount();
	TUT_Struct_Polygon __fastcall GetPolygon(int n);
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int PolygonCount = {read=GetPolygonCount, nodefault};
	__property TUT_Struct_Polygon Polygon[int n] = {read=GetPolygon};
	virtual void __fastcall PrepareExporter(TUT_MeshExporter* exporter, System::TIntegerDynArray frames);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassPolys(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassPolys() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassBrush : public TUTObject
{
	typedef TUTObject inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassBrush(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassBrush() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassMover : public TUTObjectClassBrush
{
	typedef TUTObjectClassBrush inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassMover(TUTPackage* owner, int exportedindex) : TUTObjectClassBrush(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassMover() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassConvexVolume : public TUTObjectClassPrimitive
{
	typedef TUTObjectClassPrimitive inherited;
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassConvexVolume(TUTPackage* owner, int exportedindex) : TUTObjectClassPrimitive(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassConvexVolume() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_FVert
{
public:
	int pVertex;
	int iSide;
};


typedef __int64 QWORD;

struct DECLSPEC_DRECORD TUT_Struct_BspNode
{
public:
	TUT_Struct_Plane Plane;
	QWORD ZoneMask;
	int iVertPool;
	int iSurf;
	int iBack;
	int iFront;
	int iPlane;
	int iCollisionBound;
	int iRenderBound;
	System::StaticArray<System::Byte, 2> iZone;
	System::Byte NumVertices;
	System::Byte NodeFlags;
	System::StaticArray<System::Byte, 2> iLeaf;
};


struct DECLSPEC_DRECORD TUT_Struct_BspSurf
{
public:
	int Texture;
	unsigned PolyFlags;
	int pBase;
	int vNormal;
	int vTextureU;
	int vTextureV;
	int iLightMap;
	int iBrushPoly;
	short PanU;
	short PanV;
	int Actor;
};


struct DECLSPEC_DRECORD TUT_Struct_LightMapIndex
{
public:
	int DataOffset;
	int iLightActors;
	TUT_Struct_Vector Pan;
	float UScale;
	float VSCale;
	int UClamp;
	int VClamp;
	System::Byte UBits;
	System::Byte VBits;
};


struct DECLSPEC_DRECORD TUT_Struct_Leaf
{
public:
	int iZone;
	int iPermeating;
	int iVolumetric;
	QWORD VisibleZones;
};


struct DECLSPEC_DRECORD TUT_Struct_ZoneProperties
{
public:
	int ZoneActor;
	float LastRenderTime;
	QWORD Connectivity;
	QWORD Visibility;
};


class PASCALIMPLEMENTATION TUTObjectClassModel : public TUTObjectClassPrimitive
{
	typedef TUTObjectClassPrimitive inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_Vector> _TUTObjectClassModel__1;
	
	typedef System::DynamicArray<TUT_Struct_Vector> _TUTObjectClassModel__2;
	
	typedef System::DynamicArray<TUT_Struct_FVert> _TUTObjectClassModel__3;
	
	typedef System::DynamicArray<TUT_Struct_BspNode> _TUTObjectClassModel__4;
	
	typedef System::DynamicArray<TUT_Struct_BspSurf> _TUTObjectClassModel__5;
	
	typedef System::DynamicArray<TUT_Struct_LightMapIndex> _TUTObjectClassModel__6;
	
	typedef System::DynamicArray<System::Byte> _TUTObjectClassModel__7;
	
	typedef System::DynamicArray<TUT_Struct_BoundingBox> _TUTObjectClassModel__8;
	
	typedef System::DynamicArray<int> _TUTObjectClassModel__9;
	
	typedef System::DynamicArray<TUT_Struct_Leaf> _TUTObjectClassModel__01;
	
	typedef System::DynamicArray<int> _TUTObjectClassModel__11;
	
	typedef System::DynamicArray<TUT_Struct_ZoneProperties> _TUTObjectClassModel__21;
	
	
private:
	_TUTObjectClassModel__1 FVectors;
	_TUTObjectClassModel__2 FPoints;
	_TUTObjectClassModel__3 FVerts;
	_TUTObjectClassModel__4 FNodes;
	_TUTObjectClassModel__5 FSurfs;
	_TUTObjectClassModel__6 FLightMap;
	_TUTObjectClassModel__7 FLightBits;
	_TUTObjectClassModel__8 FBounds;
	_TUTObjectClassModel__9 FLeafHulls;
	_TUTObjectClassModel__01 FLeaves;
	_TUTObjectClassModel__11 FLights;
	bool FRootOutside;
	bool FLinked;
	int FNumSharedSides;
	int FNumZones;
	int FPolys;
	_TUTObjectClassModel__21 FZones;
	int __fastcall GetBoundCount();
	int __fastcall GetLeafCount();
	int __fastcall GetLeafHullCount();
	int __fastcall GetLightBitCount();
	int __fastcall GetLightCount();
	int __fastcall GetLightMapCount();
	int __fastcall GetNodeCount();
	int __fastcall GetPointCount();
	int __fastcall GetSurfCount();
	int __fastcall GetVectorCount();
	int __fastcall GetVertCount();
	TUT_Struct_BoundingBox __fastcall GetBound(int n);
	TUT_Struct_Leaf __fastcall GetLeaf(int n);
	int __fastcall GetLeafHull(int n);
	int __fastcall GetLight(int n);
	System::Byte __fastcall GetLightBit(int n);
	TUT_Struct_LightMapIndex __fastcall GetLightMap(int n);
	TUT_Struct_BspNode __fastcall GetNode(int n);
	TUT_Struct_Vector __fastcall GetPoint(int n);
	TUT_Struct_BspSurf __fastcall GetSurf(int n);
	TUT_Struct_Vector __fastcall GetVector(int n);
	TUT_Struct_FVert __fastcall GetVert(int n);
	TUT_Struct_ZoneProperties __fastcall GetZone(int n);
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int VectorCount = {read=GetVectorCount, nodefault};
	__property TUT_Struct_Vector Vector[int n] = {read=GetVector};
	__property int PointCount = {read=GetPointCount, nodefault};
	__property TUT_Struct_Vector Point[int n] = {read=GetPoint};
	__property int VertCount = {read=GetVertCount, nodefault};
	__property TUT_Struct_FVert Vert[int n] = {read=GetVert};
	__property int NodeCount = {read=GetNodeCount, nodefault};
	__property TUT_Struct_BspNode Node[int n] = {read=GetNode};
	__property int SurfCount = {read=GetSurfCount, nodefault};
	__property TUT_Struct_BspSurf Surf[int n] = {read=GetSurf};
	__property int LightMapCount = {read=GetLightMapCount, nodefault};
	__property TUT_Struct_LightMapIndex LightMap[int n] = {read=GetLightMap};
	__property int LightBitCount = {read=GetLightBitCount, nodefault};
	__property System::Byte LightBit[int n] = {read=GetLightBit};
	__property int BoundCount = {read=GetBoundCount, nodefault};
	__property TUT_Struct_BoundingBox Bound[int n] = {read=GetBound};
	__property int LeafHullCount = {read=GetLeafHullCount, nodefault};
	__property int LeafHull[int n] = {read=GetLeafHull};
	__property int LeafCount = {read=GetLeafCount, nodefault};
	__property TUT_Struct_Leaf Leaf[int n] = {read=GetLeaf};
	__property int LightCount = {read=GetLightCount, nodefault};
	__property int Light[int n] = {read=GetLight};
	__property bool RootOutside = {read=FRootOutside, nodefault};
	__property bool Linked = {read=FLinked, nodefault};
	__property int NumSharedSides = {read=FNumSharedSides, nodefault};
	__property int ZoneCount = {read=FNumZones, nodefault};
	__property TUT_Struct_ZoneProperties Zone[int n] = {read=GetZone};
	__property int Polys = {read=FPolys, nodefault};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassModel(TUTPackage* owner, int exportedindex) : TUTObjectClassPrimitive(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassModel() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_URL
{
	
private:
	typedef System::DynamicArray<System::UnicodeString> _TUT_Struct_URL__1;
	
	
public:
	System::UnicodeString Protocol;
	System::UnicodeString Host;
	int Port;
	System::UnicodeString Map;
	_TUT_Struct_URL__1 Options;
	System::UnicodeString Portal;
	bool Valid;
};


class PASCALIMPLEMENTATION TUTObjectClassLevelBase : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<int> _TUTObjectClassLevelBase__1;
	
	
private:
	_TUTObjectClassLevelBase__1 FActors;
	TUT_Struct_URL FURL;
	int __fastcall GetActor(int n);
	int __fastcall GetActorCount();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int ActorCount = {read=GetActorCount, nodefault};
	__property int Actor[int n] = {read=GetActor};
	__property TUT_Struct_URL URL = {read=FURL};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassLevelBase(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassLevelBase() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_ReachSpec
{
public:
	int Distance;
	int Start;
	int _End;
	int CollisionRadius;
	int CollisionHeight;
	int ReachFlags;
	System::Byte bPruned;
};


class PASCALIMPLEMENTATION TUTObjectClassLevel : public TUTObjectClassLevelBase
{
	typedef TUTObjectClassLevelBase inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_ReachSpec> _TUTObjectClassLevel__1;
	
	typedef System::DynamicArray<TUT_Struct_Map> _TUTObjectClassLevel__2;
	
	
private:
	int FModel;
	_TUTObjectClassLevel__1 FReachSpecs;
	int FFirstDeleted;
	System::StaticArray<int, 16> FTextBlocks;
	_TUTObjectClassLevel__2 FTravelInfo;
	TUT_Struct_ReachSpec __fastcall GetReachSpec(int n);
	int __fastcall GetReachSpecCount();
	int __fastcall GetTextBlock(int n);
	TUT_Struct_Map __fastcall GetTravelInfo(int n);
	int __fastcall GetTravelInfoCount();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int Model = {read=FModel, nodefault};
	__property int ReachSpecCount = {read=GetReachSpecCount, nodefault};
	__property TUT_Struct_ReachSpec ReachSpec[int n] = {read=GetReachSpec};
	__property int FirstDeleted = {read=FFirstDeleted, nodefault};
	__property int TextBlocks[int n] = {read=GetTextBlock};
	__property int TravelInfoCount = {read=GetTravelInfoCount, nodefault};
	__property TUT_Struct_Map TravelInfo[int n] = {read=GetTravelInfo};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassLevel(TUTPackage* owner, int exportedindex) : TUTObjectClassLevelBase(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassLevel() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_Vert
{
public:
	float X;
	float Y;
	float Z;
};


struct DECLSPEC_DRECORD TUT_Struct_Tri
{
public:
	int VertexIndex1;
	int VertexIndex2;
	int VertexIndex3;
	System::Byte U1;
	System::Byte V1;
	System::Byte U2;
	System::Byte V2;
	System::Byte U3;
	System::Byte V3;
	int Flags;
	int TextureIndex;
};


struct DECLSPEC_DRECORD TUT_Struct_Texture
{
public:
	int Value;
};


struct DECLSPEC_DRECORD TUT_Struct_AnimSeqNotify
{
public:
	float Time;
	int _Function;
};


struct DECLSPEC_DRECORD TUT_Struct_AnimSeq
{
	
private:
	typedef System::DynamicArray<TUT_Struct_AnimSeqNotify> _TUT_Struct_AnimSeq__1;
	
	
public:
	int Name;
	int Group;
	int StartFrame;
	int NumFrames;
	_TUT_Struct_AnimSeq__1 Notifys;
	float Rate;
};


struct DECLSPEC_DRECORD TUT_Struct_Connects
{
public:
	int NumVertTriangles;
	int TriangleListOffset;
};


class PASCALIMPLEMENTATION TUTObjectClassMesh : public TUTObjectClassPrimitive
{
	typedef TUTObjectClassPrimitive inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_Vert> _TUTObjectClassMesh__1;
	
	typedef System::DynamicArray<TUT_Struct_Tri> _TUTObjectClassMesh__2;
	
	typedef System::DynamicArray<TUT_Struct_Texture> _TUTObjectClassMesh__3;
	
	typedef System::DynamicArray<TUT_Struct_AnimSeq> _TUTObjectClassMesh__4;
	
	typedef System::DynamicArray<TUT_Struct_Connects> _TUTObjectClassMesh__5;
	
	typedef System::DynamicArray<int> _TUTObjectClassMesh__6;
	
	typedef System::DynamicArray<TUT_Struct_BoundingBox> _TUTObjectClassMesh__7;
	
	typedef System::DynamicArray<TUT_Struct_BoundingSphere> _TUTObjectClassMesh__8;
	
	typedef System::DynamicArray<float> _TUTObjectClassMesh__9;
	
	
private:
	TUT_Struct_AnimSeq __fastcall GetAnimSeq(int i);
	int __fastcall GetAnimSeqCount();
	int __fastcall GetAnimFrames();
	TUT_Struct_BoundingBox __fastcall GetBoundingBox(int i);
	int __fastcall GetBoundingBoxCount();
	TUT_Struct_BoundingSphere __fastcall GetBoundingSphere(int i);
	int __fastcall GetBoundingSphereCount();
	TUT_Struct_Connects __fastcall GetConnect(int i);
	int __fastcall GetConnectsCount();
	TUT_Struct_Texture __fastcall GetTexture(int i);
	float __fastcall GetTextureLOD(int i);
	int __fastcall GetTextureLODCount();
	int __fastcall GetTexturesCount();
	TUT_Struct_Tri __fastcall GetTri(int i);
	int __fastcall GetTrisCount();
	TUT_Struct_Vert __fastcall GetVert(int i);
	int __fastcall GetVertLink(int i);
	int __fastcall GetVertLinksCount();
	int __fastcall GetVertsCount();
	
protected:
	_TUTObjectClassMesh__1 FVerts;
	_TUTObjectClassMesh__2 FTris;
	_TUTObjectClassMesh__3 FTextures;
	_TUTObjectClassMesh__4 FAnimSeqs;
	_TUTObjectClassMesh__5 FConnects;
	TUT_Struct_BoundingBox FBoundingBox;
	TUT_Struct_BoundingSphere FBoundingSphere;
	_TUTObjectClassMesh__6 FVertLinks;
	_TUTObjectClassMesh__7 FBoundingBoxes;
	_TUTObjectClassMesh__8 FBoundingSpheres;
	TUT_Struct_Vector FScale;
	TUT_Struct_Vector FOrigin;
	TUT_Struct_Rotator FRotOrigin;
	int FFrameVerts;
	int FAnimFrames;
	unsigned FANDFlags;
	unsigned FORFlags;
	int FCurPoly;
	int FCurVertex;
	_TUTObjectClassMesh__9 FTextureLOD;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int VertCount = {read=GetVertsCount, nodefault};
	__property TUT_Struct_Vert Verts[int i] = {read=GetVert};
	__property int TrisCount = {read=GetTrisCount, nodefault};
	__property TUT_Struct_Tri Tris[int i] = {read=GetTri};
	__property int TextureCount = {read=GetTexturesCount, nodefault};
	__property TUT_Struct_Texture Textures[int i] = {read=GetTexture};
	__property int AnimSeqCount = {read=GetAnimSeqCount, nodefault};
	__property TUT_Struct_AnimSeq AnimSeqs[int i] = {read=GetAnimSeq};
	__property int ConnectCount = {read=GetConnectsCount, nodefault};
	__property TUT_Struct_Connects Connects[int i] = {read=GetConnect};
	__property TUT_Struct_BoundingBox BoundingBox = {read=FBoundingBox};
	__property TUT_Struct_BoundingSphere BoundingSphere = {read=FBoundingSphere};
	__property int VertLinksCount = {read=GetVertLinksCount, nodefault};
	__property int VertLinks[int i] = {read=GetVertLink};
	__property int BoundingBoxCount = {read=GetBoundingBoxCount, nodefault};
	__property TUT_Struct_BoundingBox BoundingBoxes[int i] = {read=GetBoundingBox};
	__property int BoundingSphereCount = {read=GetBoundingSphereCount, nodefault};
	__property TUT_Struct_BoundingSphere BoundingSpheres[int i] = {read=GetBoundingSphere};
	__property TUT_Struct_Vector Scale = {read=FScale};
	__property TUT_Struct_Vector Origin = {read=FOrigin};
	__property TUT_Struct_Rotator RotOrigin = {read=FRotOrigin};
	__property int FrameVerts = {read=FFrameVerts, nodefault};
	__property int AnimFrames = {read=GetAnimFrames, nodefault};
	__property unsigned ANDFlags = {read=FANDFlags, nodefault};
	__property unsigned ORFlags = {read=FORFlags, nodefault};
	__property int CurPoly = {read=FCurPoly, nodefault};
	__property int CurVertex = {read=FCurVertex, nodefault};
	__property int TextureLODCount = {read=GetTextureLODCount, nodefault};
	__property float TextureLOD[int i] = {read=GetTextureLOD};
	virtual void __fastcall Save_Unreal3D(System::UnicodeString filename);
	virtual void __fastcall Save_UnrealUC(System::UnicodeString filename);
	virtual void __fastcall PrepareExporter(TUT_MeshExporter* exporter, System::TIntegerDynArray frames);
	virtual void __fastcall Save_3DS(System::UnicodeString filename, System::TIntegerDynArray frames, TUT_MeshExporter_Animation mode = (TUT_MeshExporter_Animation)(0x0), TUT_3DStudioExporter_Smoothing smoothing = (TUT_3DStudioExporter_Smoothing)(0x0), bool MirrorX = false);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassMesh(TUTPackage* owner, int exportedindex) : TUTObjectClassPrimitive(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassMesh() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_Wedge
{
public:
	int VertexIndex;
	System::Byte U;
	System::Byte V;
};


struct DECLSPEC_DRECORD TUT_Struct_Face
{
public:
	int WedgeIndex1;
	int WedgeIndex2;
	int WedgeIndex3;
	int MatIndex;
};


struct DECLSPEC_DRECORD TUT_Struct_Material
{
public:
	int Flags;
	int TextureIndex;
};


class PASCALIMPLEMENTATION TUTObjectClassLodMesh : public TUTObjectClassMesh
{
	typedef TUTObjectClassMesh inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_Wedge> _TUTObjectClassLodMesh__1;
	
	typedef System::DynamicArray<TUT_Struct_Face> _TUTObjectClassLodMesh__2;
	
	typedef System::DynamicArray<TUT_Struct_Material> _TUTObjectClassLodMesh__3;
	
	typedef System::DynamicArray<System::Word> _TUTObjectClassLodMesh__4;
	
	typedef System::DynamicArray<System::Word> _TUTObjectClassLodMesh__5;
	
	typedef System::DynamicArray<System::Word> _TUTObjectClassLodMesh__6;
	
	typedef System::DynamicArray<TUT_Struct_Face> _TUTObjectClassLodMesh__7;
	
	typedef System::DynamicArray<System::Word> _TUTObjectClassLodMesh__8;
	
	
private:
	System::Word __fastcall GetCollapsePointThus(int i);
	int __fastcall GetCollapsePointThusCount();
	System::Word __fastcall GetCollapseWedgeThus(int i);
	int __fastcall GetCollapseWedgeThusCount();
	TUT_Struct_Face __fastcall GetFace(int i);
	int __fastcall GetFaceCount();
	System::Word __fastcall GetFaceLevel(int i);
	int __fastcall GetFaceLevelCount();
	TUT_Struct_Material __fastcall GetMaterial(int i);
	int __fastcall GetMaterialCount();
	System::Word __fastcall GetRemapAnimVerts(int i);
	int __fastcall GetRemapAnimVertsCount();
	TUT_Struct_Face __fastcall GetSpecialFace(int i);
	int __fastcall GetSpecialFaceCount();
	TUT_Struct_Wedge __fastcall GetWedge(int i);
	int __fastcall GetWedgeCount();
	
protected:
	_TUTObjectClassLodMesh__1 FWedges;
	_TUTObjectClassLodMesh__2 FFaces;
	_TUTObjectClassLodMesh__3 FMaterials;
	_TUTObjectClassLodMesh__4 FCollapsePointThus;
	_TUTObjectClassLodMesh__5 FFaceLevel;
	_TUTObjectClassLodMesh__6 FCollapseWedgeThus;
	_TUTObjectClassLodMesh__7 FSpecialFaces;
	_TUTObjectClassLodMesh__8 FRemapAnimVerts;
	int FModelVerts;
	int FSpecialVerts;
	int FOldFrameVerts;
	float FMeshScaleMax;
	float FLODHysteresis;
	float FLODStrength;
	float FLODMinVerts;
	float FLODMorph;
	float FLODZDisplace;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int WedgeCount = {read=GetWedgeCount, nodefault};
	__property TUT_Struct_Wedge Wedges[int i] = {read=GetWedge};
	__property int FaceCount = {read=GetFaceCount, nodefault};
	__property TUT_Struct_Face Faces[int i] = {read=GetFace};
	__property int MaterialCount = {read=GetMaterialCount, nodefault};
	__property TUT_Struct_Material Materials[int i] = {read=GetMaterial};
	__property int CollapsePointThusCount = {read=GetCollapsePointThusCount, nodefault};
	__property System::Word CollapsePointThus[int i] = {read=GetCollapsePointThus};
	__property int FaceLevelCount = {read=GetFaceLevelCount, nodefault};
	__property System::Word FaceLevel[int i] = {read=GetFaceLevel};
	__property int CollapseWedgeThusCount = {read=GetCollapseWedgeThusCount, nodefault};
	__property System::Word CollapseWedgeThus[int i] = {read=GetCollapseWedgeThus};
	__property int SpecialFaceCount = {read=GetSpecialFaceCount, nodefault};
	__property TUT_Struct_Face SpecialFaces[int i] = {read=GetSpecialFace};
	__property int RemapAnimVertsCount = {read=GetRemapAnimVertsCount, nodefault};
	__property System::Word RemapAnimVerts[int i] = {read=GetRemapAnimVerts};
	__property int ModelVerts = {read=FModelVerts, nodefault};
	__property int SpecialVerts = {read=FSpecialVerts, nodefault};
	__property int OldFrameVerts = {read=FOldFrameVerts, nodefault};
	__property float MeshScaleMax = {read=FMeshScaleMax};
	__property float LODHysteresis = {read=FLODHysteresis};
	__property float LODStrength = {read=FLODStrength};
	__property float LODMinVerts = {read=FLODMinVerts};
	__property float LODMorph = {read=FLODMorph};
	__property float LODZDisplace = {read=FLODZDisplace};
	virtual void __fastcall Save_UnrealUC(System::UnicodeString filename);
	virtual void __fastcall PrepareExporter(TUT_MeshExporter* exporter, System::TIntegerDynArray frames);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassLodMesh(TUTPackage* owner, int exportedindex) : TUTObjectClassMesh(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassLodMesh() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassVertMesh : public TUTObjectClassLodMesh
{
	typedef TUTObjectClassLodMesh inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassVertMesh(TUTPackage* owner, int exportedindex) : TUTObjectClassLodMesh(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassVertMesh() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_MeshFloatUV
{
public:
	float U;
	float V;
};


struct DECLSPEC_DRECORD TUT_Struct_MeshExtWedge
{
public:
	System::Word iVertex;
	System::Word Flags;
	TUT_Struct_MeshFloatUV TexUV;
};


struct DECLSPEC_DRECORD TUT_Struct_Quat
{
public:
	float X;
	float Y;
	float Z;
	float W;
};


struct DECLSPEC_DRECORD TUT_Struct_JointPos
{
public:
	TUT_Struct_Quat Orientation;
	TUT_Struct_Vector Position;
	float Length;
	float XSize;
	float YSize;
	float ZSize;
};


struct DECLSPEC_DRECORD TUT_Struct_MeshBone
{
public:
	int Name;
	unsigned Flags;
	TUT_Struct_JointPos BonePos;
	int NumChildren;
	int ParentIndex;
};


struct DECLSPEC_DRECORD TUT_Struct_BoneInfIndex
{
public:
	System::Word WeightIndex;
	System::Word Number;
	System::Word DetailA;
	System::Word DetailB;
};


struct DECLSPEC_DRECORD TUT_Struct_BoneInfluence
{
public:
	System::Word PointIndex;
	System::Word BoneWeight;
};


struct DECLSPEC_DRECORD TUT_Struct_Coords
{
public:
	TUT_Struct_Vector Origin;
	TUT_Struct_Vector XAxis;
	TUT_Struct_Vector YAxis;
	TUT_Struct_Vector ZAXis;
};


class PASCALIMPLEMENTATION TUTObjectClassStaticMesh : public TUTObjectClassPrimitive
{
	typedef TUTObjectClassPrimitive inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_Material> _TUTObjectClassStaticMesh__1;
	
	typedef System::DynamicArray<TUT_Struct_Vert> _TUTObjectClassStaticMesh__2;
	
	typedef System::DynamicArray<TUT_Struct_MeshFloatUV> _TUTObjectClassStaticMesh__3;
	
	typedef System::DynamicArray<TUT_Struct_Face> _TUTObjectClassStaticMesh__4;
	
	
private:
	TUT_Struct_Material __fastcall GetMaterial(int i);
	int __fastcall GetMaterialsCount();
	TUT_Struct_Face __fastcall GetTriangle(int i);
	int __fastcall GetTrianglesCount();
	TUT_Struct_MeshFloatUV __fastcall GetUV(int i);
	int __fastcall GetUVCount();
	TUT_Struct_Vert __fastcall GetVertex(int i);
	int __fastcall GetVertexCount();
	
protected:
	_TUTObjectClassStaticMesh__1 FMaterials;
	_TUTObjectClassStaticMesh__2 FVertex;
	_TUTObjectClassStaticMesh__3 FUV;
	_TUTObjectClassStaticMesh__4 FTriangles;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int MaterialsCount = {read=GetMaterialsCount, nodefault};
	__property TUT_Struct_Material Materials[int i] = {read=GetMaterial};
	__property int VertexCount = {read=GetVertexCount, nodefault};
	__property TUT_Struct_Vert Vertex[int i] = {read=GetVertex};
	__property int UVCount = {read=GetUVCount, nodefault};
	__property TUT_Struct_MeshFloatUV UV[int i] = {read=GetUV};
	__property int TrianglesCount = {read=GetTrianglesCount, nodefault};
	__property TUT_Struct_Face Triangles[int i] = {read=GetTriangle};
	virtual void __fastcall PrepareExporter(TUT_MeshExporter* exporter, System::TIntegerDynArray frames);
	virtual void __fastcall Save_Unreal3D(System::UnicodeString filename);
	virtual void __fastcall Save_UnrealUC(System::UnicodeString filename);
	virtual void __fastcall Save_3DS(System::UnicodeString filename, System::TIntegerDynArray frames, TUT_MeshExporter_Animation mode = (TUT_MeshExporter_Animation)(0x0), TUT_3DStudioExporter_Smoothing smoothing = (TUT_3DStudioExporter_Smoothing)(0x0), bool MirrorX = false);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassStaticMesh(TUTPackage* owner, int exportedindex) : TUTObjectClassPrimitive(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassStaticMesh() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassSkeletalMesh : public TUTObjectClassLodMesh
{
	typedef TUTObjectClassLodMesh inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_MeshExtWedge> _TUTObjectClassSkeletalMesh__1;
	
	typedef System::DynamicArray<TUT_Struct_Vector> _TUTObjectClassSkeletalMesh__2;
	
	typedef System::DynamicArray<TUT_Struct_MeshBone> _TUTObjectClassSkeletalMesh__3;
	
	typedef System::DynamicArray<TUT_Struct_BoneInfIndex> _TUTObjectClassSkeletalMesh__4;
	
	typedef System::DynamicArray<TUT_Struct_BoneInfluence> _TUTObjectClassSkeletalMesh__5;
	
	typedef System::DynamicArray<TUT_Struct_Vector> _TUTObjectClassSkeletalMesh__6;
	
	
private:
	TUT_Struct_BoneInfluence __fastcall GetBoneWeight(int i);
	int __fastcall GetBoneWeightCount();
	TUT_Struct_BoneInfIndex __fastcall GetBoneWeightIdx(int i);
	int __fastcall GetBoneWeightIdxCount();
	TUT_Struct_MeshExtWedge __fastcall GetExtWedge(int i);
	int __fastcall GetExtWedgeCount();
	TUT_Struct_Vector __fastcall GetLocalPoint(int i);
	int __fastcall GetLocalPointCount();
	TUT_Struct_Vector __fastcall GetPoint(int i);
	int __fastcall GetPointCount();
	TUT_Struct_MeshBone __fastcall GetRefSkeleton(int i);
	int __fastcall GetRefSkeletonCount();
	
protected:
	_TUTObjectClassSkeletalMesh__1 FExtWedges;
	_TUTObjectClassSkeletalMesh__2 FPoints;
	_TUTObjectClassSkeletalMesh__3 FRefSkeleton;
	_TUTObjectClassSkeletalMesh__4 FBoneWeightIdx;
	_TUTObjectClassSkeletalMesh__5 FBoneWeights;
	_TUTObjectClassSkeletalMesh__6 FLocalPoints;
	int FSkeletalDepth;
	int FDefaultAnimation;
	int FWeaponBoneIndex;
	TUT_Struct_Coords FWeaponAdjust;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property int ExtWedgeCount = {read=GetExtWedgeCount, nodefault};
	__property TUT_Struct_MeshExtWedge ExtWedges[int i] = {read=GetExtWedge};
	__property int PointCount = {read=GetPointCount, nodefault};
	__property TUT_Struct_Vector Points[int i] = {read=GetPoint};
	__property int RefSkeletonCount = {read=GetRefSkeletonCount, nodefault};
	__property TUT_Struct_MeshBone RefSkeleton[int i] = {read=GetRefSkeleton};
	__property int BoneWeightIdxCount = {read=GetBoneWeightIdxCount, nodefault};
	__property TUT_Struct_BoneInfIndex BoneWeightIdx[int i] = {read=GetBoneWeightIdx};
	__property int BoneWeightCount = {read=GetBoneWeightCount, nodefault};
	__property TUT_Struct_BoneInfluence BoneWeights[int i] = {read=GetBoneWeight};
	__property int LocalPointCount = {read=GetLocalPointCount, nodefault};
	__property TUT_Struct_Vector LocalPoints[int i] = {read=GetLocalPoint};
	__property int SkeletalDepth = {read=FSkeletalDepth, nodefault};
	__property int DefaultAnimation = {read=FDefaultAnimation, nodefault};
	__property int WeaponBoneIndex = {read=FWeaponBoneIndex, nodefault};
	__property TUT_Struct_Coords WeaponAdjust = {read=FWeaponAdjust};
	virtual void __fastcall Save_Unreal3D(System::UnicodeString filename);
	virtual void __fastcall Save_UnrealUC(System::UnicodeString filename);
	virtual void __fastcall PrepareExporter(TUT_MeshExporter* exporter, System::TIntegerDynArray frames);
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassSkeletalMesh(TUTPackage* owner, int exportedindex) : TUTObjectClassLodMesh(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassSkeletalMesh() { }
	
};


struct DECLSPEC_DRECORD TUT_Struct_NamedBone
{
public:
	int Name;
	unsigned Flags;
	int ParentIndex;
};


struct DECLSPEC_DRECORD TUT_Struct_AnalogTrack
{
	
private:
	typedef System::DynamicArray<TUT_Struct_Quat> _TUT_Struct_AnalogTrack__1;
	
	typedef System::DynamicArray<TUT_Struct_Vector> _TUT_Struct_AnalogTrack__2;
	
	typedef System::DynamicArray<float> _TUT_Struct_AnalogTrack__3;
	
	
public:
	unsigned Flags;
	_TUT_Struct_AnalogTrack__1 KeyQuat;
	_TUT_Struct_AnalogTrack__2 KeyPos;
	_TUT_Struct_AnalogTrack__3 KeyTime;
};


struct DECLSPEC_DRECORD TUT_Struct_MotionChunk
{
	
private:
	typedef System::DynamicArray<int> _TUT_Struct_MotionChunk__1;
	
	typedef System::DynamicArray<TUT_Struct_AnalogTrack> _TUT_Struct_MotionChunk__2;
	
	
public:
	TUT_Struct_Vector RootSpeed3D;
	float TrackTime;
	int StartBone;
	unsigned Flags;
	_TUT_Struct_MotionChunk__1 BoneIndices;
	_TUT_Struct_MotionChunk__2 AnimTracks;
	TUT_Struct_AnalogTrack RootTrack;
};


class PASCALIMPLEMENTATION TUTObjectClassAnimation : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<TUT_Struct_NamedBone> _TUTObjectClassAnimation__1;
	
	typedef System::DynamicArray<TUT_Struct_MotionChunk> _TUTObjectClassAnimation__2;
	
	typedef System::DynamicArray<TUT_Struct_AnimSeq> _TUTObjectClassAnimation__3;
	
	
private:
	TUT_Struct_AnimSeq __fastcall GetAnimSeqs(int i);
	int __fastcall GetAnimSeqsCount();
	TUT_Struct_MotionChunk __fastcall GetMoves(int i);
	int __fastcall GetMovesCount();
	TUT_Struct_NamedBone __fastcall GetRefBones(int i);
	int __fastcall GetRefBonesCount();
	
protected:
	_TUTObjectClassAnimation__1 FRefBones;
	_TUTObjectClassAnimation__2 FMoves;
	_TUTObjectClassAnimation__3 FAnimSeqs;
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property TUT_Struct_NamedBone RefBones[int i] = {read=GetRefBones};
	__property int RefBonesCount = {read=GetRefBonesCount, nodefault};
	__property TUT_Struct_MotionChunk Moves[int i] = {read=GetMoves};
	__property int MovesCount = {read=GetMovesCount, nodefault};
	__property TUT_Struct_AnimSeq AnimSeqs[int i] = {read=GetAnimSeqs};
	__property int AnimSeqsCount = {read=GetAnimSeqsCount, nodefault};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassAnimation(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassAnimation() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassMeshAnimation : public TUTObjectClassAnimation
{
	typedef TUTObjectClassAnimation inherited;
	
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassMeshAnimation(TUTPackage* owner, int exportedindex) : TUTObjectClassAnimation(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassMeshAnimation() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassFunction : public TUTObjectClassStruct
{
	typedef TUTObjectClassStruct inherited;
	
private:
	int FiNative;
	int FRepOffset;
	int FOperatorPrecedence;
	unsigned FFunctionFlags;
	unsigned __fastcall GetFunctionFlags();
	int __fastcall GetiNative();
	int __fastcall GetOperatorPrecedence();
	int __fastcall GetRepOffset();
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	virtual System::UnicodeString __fastcall Decompile(bool beautify = true, bool showoffsets = false)/* overload */;
	virtual void __fastcall Decompile(System::Classes::TStrings* code, bool beautify = true, bool showoffsets = false)/* overload */;
	__property int NativeIndex = {read=GetiNative, nodefault};
	__property int ReplicationOffset = {read=GetRepOffset, nodefault};
	__property int OperatorPrecedence = {read=GetOperatorPrecedence, nodefault};
	__property unsigned FunctionFlags = {read=GetFunctionFlags, nodefault};
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassFunction(TUTPackage* owner, int exportedindex) : TUTObjectClassStruct(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassFunction() { }
	
};


class PASCALIMPLEMENTATION TUTObjectClassPackageCheckInfo : public TUTObject
{
	typedef TUTObject inherited;
	
	
private:
	typedef System::DynamicArray<System::UnicodeString> _TUTObjectClassPackageCheckInfo__1;
	
	
private:
	System::UnicodeString FPackageMD5;
	_TUTObjectClassPackageCheckInfo__1 FMD5;
	System::UnicodeString __fastcall GetMD5(int i);
	
protected:
	virtual void __fastcall InitializeObject();
	virtual void __fastcall InterpretObject();
	
public:
	__property System::UnicodeString PackageMD5 = {read=FPackageMD5};
	__property System::UnicodeString MD5[int i] = {read=GetMD5};
	int __fastcall MD5Count();
public:
	/* TUTObject.create */ inline __fastcall virtual TUTObjectClassPackageCheckInfo(TUTPackage* owner, int exportedindex) : TUTObject(owner, exportedindex) { }
	/* TUTObject.Destroy */ inline __fastcall virtual ~TUTObjectClassPackageCheckInfo() { }
	
};


class PASCALIMPLEMENTATION TUTImportTableObjectData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TUTPackage* FOwner;
	int FObjectIndex;
	int FClassPackageIndex;
	int FClassIndex;
	int FPackageIndex;
	void __fastcall SetObjectIndex(const int Value);
	void __fastcall SetClassIndex(const int Value);
	void __fastcall SetClassPackageIndex(const int Value);
	void __fastcall SetPackageIndex(const int Value);
	System::UnicodeString __fastcall Get_ClassName();
	System::UnicodeString __fastcall GetClassPackageName();
	System::UnicodeString __fastcall GetObjectName();
	System::UnicodeString __fastcall GetPackageName();
	
public:
	__property TUTPackage* Owner = {read=FOwner, write=FOwner};
	__property int UTObjectIndex = {read=FObjectIndex, write=SetObjectIndex, nodefault};
	__property int UTClassPackageIndex = {read=FClassPackageIndex, write=SetClassPackageIndex, nodefault};
	__property int UTClassIndex = {read=FClassIndex, write=SetClassIndex, nodefault};
	__property int UTPackageIndex = {read=FPackageIndex, write=SetPackageIndex, nodefault};
	__property System::UnicodeString UTObjectName = {read=GetObjectName};
	__property System::UnicodeString UTClassPackageName = {read=GetClassPackageName};
	__property System::UnicodeString UTClassName = {read=Get_ClassName};
	__property System::UnicodeString UTPackageName = {read=GetPackageName};
public:
	/* TObject.Create */ inline __fastcall TUTImportTableObjectData() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TUTImportTableObjectData() { }
	
};


class PASCALIMPLEMENTATION TUTExportTableObjectData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TUTPackage* FOwner;
	int FSerialOffset;
	int FClassIndex;
	int FObjectIndex;
	int FSerialSize;
	int FGroupIndex;
	int FSuperIndex;
	int FFlags;
	TUTObject* FUTObject;
	int FExportedIndex;
	void __fastcall SetClassIndex(const int Value);
	void __fastcall SetFlags(const int Value);
	void __fastcall SetObjectIndex(const int Value);
	void __fastcall SetGroupIndex(const int Value);
	void __fastcall SetSerialOffset(const int Value);
	void __fastcall SetSerialSize(const int Value);
	void __fastcall SetSuperIndex(const int Value);
	void __fastcall SetUTObject(TUTObject* const Value);
	System::UnicodeString __fastcall Get_ClassName();
	System::UnicodeString __fastcall GetObjectName();
	System::UnicodeString __fastcall GetGroupName();
	System::UnicodeString __fastcall GetSuperName();
	TUTObject* __fastcall GetUTObject();
	
public:
	__property TUTPackage* Owner = {read=FOwner, write=FOwner};
	__property int ExportedIndex = {read=FExportedIndex, write=FExportedIndex, nodefault};
	void __fastcall CreateObject();
	void __fastcall FreeObject();
	__fastcall virtual ~TUTExportTableObjectData();
	__property int UTObjectIndex = {read=FObjectIndex, write=SetObjectIndex, nodefault};
	__property int UTClassIndex = {read=FClassIndex, write=SetClassIndex, nodefault};
	__property int UTGroupIndex = {read=FGroupIndex, write=SetGroupIndex, nodefault};
	__property int UTSuperIndex = {read=FSuperIndex, write=SetSuperIndex, nodefault};
	__property int Flags = {read=FFlags, write=SetFlags, nodefault};
	__property int SerialSize = {read=FSerialSize, write=SetSerialSize, nodefault};
	__property int SerialOffset = {read=FSerialOffset, write=SetSerialOffset, nodefault};
	__property System::UnicodeString UTObjectName = {read=GetObjectName};
	__property System::UnicodeString UTClassName = {read=Get_ClassName};
	__property System::UnicodeString UTGroupName = {read=GetGroupName};
	__property System::UnicodeString UTSuperName = {read=GetSuperName};
	__property TUTObject* UTObject = {read=GetUTObject, write=SetUTObject};
public:
	/* TObject.Create */ inline __fastcall TUTExportTableObjectData() : System::TObject() { }
	
};


enum DECLSPEC_DENUM TUTPackageObjectLocations : unsigned char { utolNames, utolExports, utolImports };

enum DECLSPEC_DENUM TUTPackageFindWhat : unsigned char { utfwName, utfwGroup, utfwClass };

typedef System::Set<TUTPackageFindWhat, TUTPackageFindWhat::utfwName, TUTPackageFindWhat::utfwClass> TUTPackageFindWhatSet;

typedef void __fastcall (__closure *TUT_OnProgressEvent)(System::TObject* Sender, int position);

typedef System::UnicodeString __fastcall (__closure *TUT_OnGetStringConst)(System::UnicodeString s);

typedef System::WideString __fastcall (__closure *TUT_OnGetUnicodeStringConst)(System::WideString s);

typedef void __fastcall (__closure *TUT_OnPackageNeeded)(System::UnicodeString &package);

enum DECLSPEC_DENUM TUTBasicDataTypes : unsigned char { utbdBuffer, utbdASCIIZ, utbdBool, utbdFloat, utbdIndex, utbdUInt8, utbdUInt16, utbdInt32, utbdUInt32, utbdUInt64, utbdSizedASCII, utbdDoubleSizedASCIIZ, utbdSizedASCIIZ, utbdGUID, utbdName, utbdProperty, utbdCodeStatement };

enum DECLSPEC_DENUM TUTDataMeaningTypes : unsigned char { utdmUnknown, utdmAsValue, utdmRefToName, utdmRefToObject, utdmFlags, utdmOffset, utdmCRC };

typedef void __fastcall (__closure *TUT_OnBasicData)(__int64 package_position, TUTBasicDataTypes basicdatatype, TUTDataMeaningTypes datameaning, __int64 size, const System::UnicodeString name);

typedef void __fastcall (__closure *TUT_OnGetGameHint)(System::TObject* Sender, TUTPackage_GameHint &GameHint);

typedef void __fastcall (__closure *TUT_OnProcessMessages)(System::TObject* Sender);

struct DECLSPEC_DRECORD TUTPackage_GenerationInfo
{
public:
	int ExportCount;
	int NameCount;
};


typedef TUTPackageSection *TUTPackageSectionPointer;

struct DECLSPEC_DRECORD TUTPackageSection
{
public:
	unsigned Offset;
	unsigned Size;
};


class PASCALIMPLEMENTATION TUTPackage : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<GUID> _TUTPackage__1;
	
	typedef System::DynamicArray<TUTPackage_GenerationInfo> _TUTPackage__2;
	
	
private:
	TUT_OnProgressEvent FOnProgress;
	System::Classes::TStream* Fstr;
	System::UnicodeString FPackage;
	System::Word FVersion;
	System::Word FLicenseeMode;
	unsigned FFlags;
	int FReadingPackageCount;
	System::Classes::TStringList* FNameTableList;
	System::Classes::TList* FImportTableList;
	System::Classes::TList* FExportTableList;
	_TUTPackage__1 FHeritageTableList;
	_TUTPackage__2 FGenerationInfo;
	bool FAllowReadingOtherPackages;
	TUT_OnGetStringConst FOnGetStringConst;
	TUT_OnGetUnicodeStringConst FOnGetUnicodeStringConst;
	TUT_OnPackageNeeded FOnPackageNeeded;
	System::Classes::TStringList* FEnumCache;
	TUTPackage_GameHint FGameHint;
	TNativeFunctions NativeFunctions;
	bool FSaveOriginalTextureFormat;
	bool AAOEncrypted;
	bool LineageEncrypted;
	System::Byte EncryptKey;
	bool FCallOnBasicDataEvent;
	bool FInternalCallOnBasicDataEvent;
	TUT_OnBasicData FOnBasicData;
	TUT_OnGetGameHint FOnGetGameHint;
	unsigned FPackagePrefixSize;
	TUT_OnProcessMessages FOnProcessMessages;
	unsigned FOtherFlags;
	System::Classes::TList* FUnreferencedSections;
	unsigned FFileSize;
	void __fastcall Process();
	void __fastcall DoOnProgress(int position, int maxposition);
	TUTExportTableObjectData* __fastcall GetExport(int i);
	GUID __fastcall GetHeritage(int i);
	TUTImportTableObjectData* __fastcall GetImport(int i);
	System::UnicodeString __fastcall GetName(int i);
	int __fastcall GetNameFlags(int i);
	int __fastcall GetExportCount();
	int __fastcall GetHeritageCount();
	int __fastcall GetImportCount();
	int __fastcall GetNameCount();
	int __fastcall GetPackagePosition();
	System::Classes::TStream* __fastcall GetStream();
	int __fastcall GetExportIndex(System::UnicodeString objectname, System::UnicodeString classname);
	int __fastcall GetNameIndex(System::UnicodeString objectname);
	TUTPackage_GenerationInfo __fastcall GetGeneration(int i);
	int __fastcall GetGenerationCount();
	bool __fastcall GetInitialized();
	void __fastcall SetName(int i, const System::UnicodeString Value);
	System::UnicodeString __fastcall GetStringConst(System::UnicodeString s);
	System::WideString __fastcall GetUnicodeStringConst(System::WideString s);
	bool __fastcall ExistsImportedPackage(System::UnicodeString name);
	System::Byte __fastcall AAODecrypt(System::Byte EncryptedByte, __int64 FilePos, System::Byte Key);
	void __fastcall SetCallOnBasicDataEvent(const bool Value);
	void __fastcall SetOnBasicData(const TUT_OnBasicData Value);
	void __fastcall SetOnGetGameHint(const TUT_OnGetGameHint Value);
	void __fastcall SetOnProcessMessages(const TUT_OnProcessMessages Value);
	TUTPackageSection __fastcall GetUnreferencedSection(unsigned i);
	int __fastcall GetUnreferencedSectionsCount();
	void __fastcall RemoveReferencedSection(unsigned offset, unsigned size);
	void __fastcall ClearUnreferencedSections();
	
protected:
	System::UnicodeString __fastcall IndentText(System::UnicodeString indent, System::UnicodeString txt);
	virtual void __fastcall DetectGamePreProcess();
	virtual void __fastcall DetectGameInProcess();
	virtual void __fastcall DetectGamePostProcess();
	void __fastcall SetNativeFunctionArray(TNativeFunction *a, const System::NativeInt a_High);
	void __fastcall SetNativeFunctionArrayFromHint();
	
public:
	__property System::Classes::TStream* stream = {read=GetStream};
	__fastcall TUTPackage();
	__fastcall TUTPackage(const System::UnicodeString package, TUTPackage* other_pkg);
	void __fastcall Initialize(const System::UnicodeString package, TUTPackage_GameHint GameHint = (TUTPackage_GameHint)(0x0));
	__property TUTPackage_GameHint GameHint = {read=FGameHint, write=FGameHint, nodefault};
	__fastcall virtual ~TUTPackage();
	__property System::UnicodeString Package = {read=FPackage};
	__property unsigned FileSize = {read=FFileSize, nodefault};
	__property bool Initialized = {read=GetInitialized, nodefault};
	__property TUT_OnProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property System::Word Version = {read=FVersion, nodefault};
	__property System::Word LicenseeMode = {read=FLicenseeMode, nodefault};
	__property unsigned Flags = {read=FFlags, nodefault};
	__property unsigned OtherFlags = {read=FOtherFlags, nodefault};
	__property int NameCount = {read=GetNameCount, nodefault};
	__property System::UnicodeString Names[int i] = {read=GetName, write=SetName};
	__property int NameFlags[int i] = {read=GetNameFlags};
	System::UnicodeString __fastcall GetObjectFlagsText(const unsigned e);
	__property int ExportedCount = {read=GetExportCount, nodefault};
	__property TUTExportTableObjectData* Exported[int i] = {read=GetExport};
	__property int ImportedCount = {read=GetImportCount, nodefault};
	__property TUTImportTableObjectData* Imported[int i] = {read=GetImport};
	__property int HeritageCount = {read=GetHeritageCount, nodefault};
	__property GUID Heritages[int i] = {read=GetHeritage};
	__property int GenerationCount = {read=GetGenerationCount, nodefault};
	__property TUTPackage_GenerationInfo Generations[int i] = {read=GetGeneration};
	__property int ExportIndex[System::UnicodeString objectname][System::UnicodeString classname] = {read=GetExportIndex};
	__property int NameIndex[System::UnicodeString objectname] = {read=GetNameIndex};
	__property int UnreferencedSectionsCount = {read=GetUnreferencedSectionsCount, nodefault};
	__property TUTPackageSection UnreferencedSection[unsigned i] = {read=GetUnreferencedSection};
	bool __fastcall IsPackageEncrypted();
	int __fastcall FindObject(TUTPackageObjectLocations where, TUTPackageFindWhatSet what, System::UnicodeString packagename, System::UnicodeString objectname, System::UnicodeString classname, int start = 0x0);
	void __fastcall FindObjectRecursive(TUTPackageFindWhatSet what, System::UnicodeString packagename, System::UnicodeString objectname, System::UnicodeString classname, System::UnicodeString associated_class, TUTPackage* &found_pkg, int &found_index);
	void __fastcall FindObjectAndPackage(int index, TUTPackage* &pkg, TUTObject* &obj);
	void __fastcall ReadAllObjects();
	void __fastcall ReleaseAllObjects();
	System::UnicodeString __fastcall EncodeIndex(int i);
	void __fastcall StartReadingPackage();
	void __fastcall EndReadingPackage();
	__property int Position = {read=GetPackagePosition, nodefault};
	void __fastcall Seek(int p);
	bool __fastcall ReadProperty(TUTProperty* prop, System::Classes::TStream* stream);
	void __fastcall SaveDataBlock(System::UnicodeString filename, int position, int size)/* overload */;
	void __fastcall SaveDataBlock(System::Classes::TStream* strm, int position, int size)/* overload */;
	System::UnicodeString __fastcall GetObjectPath(int limit, int index);
	void __fastcall read_buffer(void *buffer, const int size, System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	System::UnicodeString __fastcall read_asciiz(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	bool __fastcall read_bool(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	System::Byte __fastcall read_byte(System::Classes::TStream* stream, TUTDataMeaningTypes datameaning = (TUTDataMeaningTypes)(0x0), const System::UnicodeString name = System::UnicodeString());
	float __fastcall read_float(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	int __fastcall read_idx(System::Classes::TStream* stream, TUTDataMeaningTypes datameaning = (TUTDataMeaningTypes)(0x0), const System::UnicodeString name = System::UnicodeString());
	int __fastcall read_int(System::Classes::TStream* stream, TUTDataMeaningTypes datameaning = (TUTDataMeaningTypes)(0x0), const System::UnicodeString name = System::UnicodeString());
	unsigned __fastcall read_dword(System::Classes::TStream* stream, TUTDataMeaningTypes datameaning = (TUTDataMeaningTypes)(0x0), const System::UnicodeString name = System::UnicodeString());
	__int64 __fastcall read_qword(System::Classes::TStream* stream, TUTDataMeaningTypes datameaning = (TUTDataMeaningTypes)(0x0), const System::UnicodeString name = System::UnicodeString());
	GUID __fastcall read_guid(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	System::UnicodeString __fastcall read_sizedascii(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	System::UnicodeString __fastcall read_doublesizedasciiz(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	System::UnicodeString __fastcall read_sizedasciiz(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	System::Word __fastcall read_word(System::Classes::TStream* stream, TUTDataMeaningTypes datameaning = (TUTDataMeaningTypes)(0x0), const System::UnicodeString name = System::UnicodeString());
	System::UnicodeString __fastcall Read_Name(System::Classes::TStream* stream, const System::UnicodeString name = System::UnicodeString());
	int __fastcall read_idx_from_buffer(void * buffer, int &start);
	__property bool CallOnBasicDataEvent = {read=FCallOnBasicDataEvent, write=SetCallOnBasicDataEvent, nodefault};
	__property bool AllowReadingOtherPackages = {read=FAllowReadingOtherPackages, write=FAllowReadingOtherPackages, nodefault};
	__property bool SaveOriginalTextureFormat = {read=FSaveOriginalTextureFormat, write=FSaveOriginalTextureFormat, nodefault};
	__property TUT_OnGetStringConst OnGetStringConst = {read=FOnGetStringConst, write=FOnGetStringConst};
	__property TUT_OnGetUnicodeStringConst OnGetUnicodeStringConst = {read=FOnGetUnicodeStringConst, write=FOnGetUnicodeStringConst};
	__property TUT_OnPackageNeeded OnPackageNeeded = {read=FOnPackageNeeded, write=FOnPackageNeeded};
	__property TUT_OnBasicData OnBasicData = {read=FOnBasicData, write=SetOnBasicData};
	__property TUT_OnGetGameHint OnGetGameHint = {read=FOnGetGameHint, write=SetOnGetGameHint};
	__property TUT_OnProcessMessages OnProcessMessages = {read=FOnProcessMessages, write=SetOnProcessMessages};
};


struct DECLSPEC_DRECORD TKnownStructElement
{
public:
	System::UnicodeString Name;
	System::UnicodeString SpecificTypeName;
	int ValueType;
};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 PKG_AllowDownload = System::Int8(0x1);
static _DELPHI_CONST System::Int8 PKG_ClientOptional = System::Int8(0x2);
static _DELPHI_CONST System::Int8 PKG_ServerSideOnly = System::Int8(0x4);
static _DELPHI_CONST System::Int8 PKG_BrokenLinks = System::Int8(0x8);
static _DELPHI_CONST System::Int8 PKG_Unsecure = System::Int8(0x10);
static _DELPHI_CONST System::Int8 PKG_Encrypted = System::Int8(0x20);
static _DELPHI_CONST System::Word PKG_Need = System::Word(0x8000);
static _DELPHI_CONST System::Int8 PKG_OTHER_FLAGS_AAOEncrypted = System::Int8(0x1);
static _DELPHI_CONST System::Int8 PKG_OTHER_FLAGS_Lineage2Encrypted = System::Int8(0x2);
static _DELPHI_CONST System::Int8 RF_Transactional = System::Int8(0x1);
static _DELPHI_CONST System::Int8 RF_Unreachable = System::Int8(0x2);
static _DELPHI_CONST System::Int8 RF_Public = System::Int8(0x4);
static _DELPHI_CONST System::Int8 RF_TagImp = System::Int8(0x8);
static _DELPHI_CONST System::Int8 RF_TagExp = System::Int8(0x10);
static _DELPHI_CONST System::Int8 RF_SourceModified = System::Int8(0x20);
static _DELPHI_CONST System::Int8 RF_TagGarbage = System::Int8(0x40);
static _DELPHI_CONST System::Byte RF_Private = System::Byte(0x80);
static _DELPHI_CONST System::Word RF_Unk_00000100 = System::Word(0x100);
static _DELPHI_CONST System::Word RF_NeedLoad = System::Word(0x200);
static _DELPHI_CONST System::Word RF_HighlightedName = System::Word(0x400);
static _DELPHI_CONST System::Word RF_InSingularFunc = System::Word(0x800);
static _DELPHI_CONST System::Word RF_Suppress = System::Word(0x1000);
static _DELPHI_CONST System::Word RF_InEndState = System::Word(0x2000);
static _DELPHI_CONST System::Word RF_Transient = System::Word(0x4000);
static _DELPHI_CONST System::Word RF_PreLoading = System::Word(0x8000);
static _DELPHI_CONST int RF_LoadForClient = int(0x10000);
static _DELPHI_CONST int RF_LoadForServer = int(0x20000);
static _DELPHI_CONST int RF_LoadForEdit = int(0x40000);
static _DELPHI_CONST int RF_Standalone = int(0x80000);
static _DELPHI_CONST int RF_NotForClient = int(0x100000);
static _DELPHI_CONST int RF_NotForServer = int(0x200000);
static _DELPHI_CONST int RF_NotForEdit = int(0x400000);
static _DELPHI_CONST int RF_Destroyed = int(0x800000);
static _DELPHI_CONST int RF_NeedPostLoad = int(0x1000000);
static _DELPHI_CONST int RF_HasStack = int(0x2000000);
static _DELPHI_CONST int RF_Native = int(0x4000000);
static _DELPHI_CONST int RF_Marked = int(0x8000000);
static _DELPHI_CONST int RF_ErrorShutdown = int(0x10000000);
static _DELPHI_CONST int RF_DebugPostLoad = int(0x20000000);
static _DELPHI_CONST int RF_DebugSerialize = int(0x40000000);
static _DELPHI_CONST unsigned RF_DebugDestroy = unsigned(0x80000000);
static _DELPHI_CONST System::Int8 otNone = System::Int8(0x0);
static _DELPHI_CONST System::Int8 otByte = System::Int8(0x1);
static _DELPHI_CONST System::Int8 otInt = System::Int8(0x2);
static _DELPHI_CONST System::Int8 otBool = System::Int8(0x3);
static _DELPHI_CONST System::Int8 otFloat = System::Int8(0x4);
static _DELPHI_CONST System::Int8 otObject = System::Int8(0x5);
static _DELPHI_CONST System::Int8 otName = System::Int8(0x6);
static _DELPHI_CONST System::Int8 otString = System::Int8(0x7);
static _DELPHI_CONST System::Int8 otClass = System::Int8(0x8);
static _DELPHI_CONST System::Int8 otArray = System::Int8(0x9);
static _DELPHI_CONST System::Int8 otStruct = System::Int8(0xa);
static _DELPHI_CONST System::Int8 otVector = System::Int8(0xb);
static _DELPHI_CONST System::Int8 otRotator = System::Int8(0xc);
static _DELPHI_CONST System::Int8 otStr = System::Int8(0xd);
static _DELPHI_CONST System::Int8 otMap = System::Int8(0xe);
static _DELPHI_CONST System::Int8 otFixedArray = System::Int8(0xf);
static _DELPHI_CONST System::Word otExtendedValue = System::Word(0x100);
static _DELPHI_CONST System::Word otBuffer = System::Word(0x100);
static _DELPHI_CONST System::Word otWord = System::Word(0x101);
extern DELPHI_PACKAGE Ut_packages__1 UTPackage_GameHintStrings;
static _DELPHI_CONST System::Int8 nffFunction = System::Int8(0x0);
static _DELPHI_CONST System::Int8 nffPreOperator = System::Int8(0x1);
static _DELPHI_CONST System::Int8 nffPostOperator = System::Int8(0x2);
static _DELPHI_CONST System::Int8 nffOperator = System::Int8(0x3);
static _DELPHI_CONST System::Word M3DMAGIC = System::Word(0x4d4d);
static _DELPHI_CONST System::Int8 M3D_VERSION = System::Int8(0x2);
static _DELPHI_CONST System::Word MDATA = System::Word(0x3d3d);
static _DELPHI_CONST System::Word MESH_VERSION = System::Word(0x3d3e);
static _DELPHI_CONST System::Word MAT_ENTRY = System::Word(0xafff);
static _DELPHI_CONST System::Word MAT_NAME = System::Word(0xa000);
static _DELPHI_CONST System::Word MAT_DIFFUSE = System::Word(0xa020);
static _DELPHI_CONST System::Word MAT_TEXMAP = System::Word(0xa200);
static _DELPHI_CONST System::Word MAT_MAPNAME = System::Word(0xa300);
static _DELPHI_CONST System::Int8 COLOR_24 = System::Int8(0x11);
static _DELPHI_CONST System::Word NAMED_OBJECT = System::Word(0x4000);
static _DELPHI_CONST System::Word N_TRI_OBJECT = System::Word(0x4100);
static _DELPHI_CONST System::Word POINT_ARRAY = System::Word(0x4110);
static _DELPHI_CONST System::Word TEX_VERTS = System::Word(0x4140);
static _DELPHI_CONST System::Word FACE_ARRAY = System::Word(0x4120);
static _DELPHI_CONST System::Word MSH_MAT_GROUP = System::Word(0x4130);
static _DELPHI_CONST System::Word SMOOTH_GROUP = System::Word(0x4150);
static _DELPHI_CONST System::Word KFDATA = System::Word(0xb000);
static _DELPHI_CONST System::Word KFHDR = System::Word(0xb00a);
static _DELPHI_CONST System::Word KFSEG = System::Word(0xb008);
static _DELPHI_CONST System::Word KFCURTIME = System::Word(0xb009);
static _DELPHI_CONST System::Word OBJECT_NODE_TAG = System::Word(0xb002);
static _DELPHI_CONST System::Word NODE_ID = System::Word(0xb030);
static _DELPHI_CONST System::Word NODE_HDR = System::Word(0xb010);
static _DELPHI_CONST System::Word PIVOT = System::Word(0xb013);
static _DELPHI_CONST System::Word POS_TRACK_TAG = System::Word(0xb020);
static _DELPHI_CONST System::Word ROT_TRACK_TAG = System::Word(0xb021);
static _DELPHI_CONST System::Word SCL_TRACK_TAG = System::Word(0xb022);
static _DELPHI_CONST System::Word HIDE_TRACK_TAG = System::Word(0xb029);
static _DELPHI_CONST System::Int8 FaceCAVisable3DS = System::Int8(0x1);
static _DELPHI_CONST System::Int8 FaceBCVisable3DS = System::Int8(0x2);
static _DELPHI_CONST System::Int8 FaceABVisable3DS = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EX_LocalVariable = System::Int8(0x0);
static _DELPHI_CONST System::Int8 EX_InstanceVariable = System::Int8(0x1);
static _DELPHI_CONST System::Int8 EX_DefaultVariable = System::Int8(0x2);
static _DELPHI_CONST System::Int8 EX_UnknownVariable = System::Int8(0x3);
static _DELPHI_CONST System::Int8 EX_Return = System::Int8(0x4);
static _DELPHI_CONST System::Int8 EX_Switch = System::Int8(0x5);
static _DELPHI_CONST System::Int8 EX_Jump = System::Int8(0x6);
static _DELPHI_CONST System::Int8 EX_JumpIfNot = System::Int8(0x7);
static _DELPHI_CONST System::Int8 EX_Stop = System::Int8(0x8);
static _DELPHI_CONST System::Int8 EX_Assert = System::Int8(0x9);
static _DELPHI_CONST System::Int8 EX_Case = System::Int8(0xa);
static _DELPHI_CONST System::Int8 EX_Nothing = System::Int8(0xb);
static _DELPHI_CONST System::Int8 EX_LabelTable = System::Int8(0xc);
static _DELPHI_CONST System::Int8 EX_GotoLabel = System::Int8(0xd);
static _DELPHI_CONST System::Int8 EX_EatString = System::Int8(0xe);
static _DELPHI_CONST System::Int8 EX_Let = System::Int8(0xf);
static _DELPHI_CONST System::Int8 EX_DynArrayElement = System::Int8(0x10);
static _DELPHI_CONST System::Int8 EX_New = System::Int8(0x11);
static _DELPHI_CONST System::Int8 EX_ClassContext = System::Int8(0x12);
static _DELPHI_CONST System::Int8 EX_Metacast = System::Int8(0x13);
static _DELPHI_CONST System::Int8 EX_LetBool = System::Int8(0x14);
static _DELPHI_CONST System::Int8 EX_Unknown_jumpover = System::Int8(0x15);
static _DELPHI_CONST System::Int8 EX_EndFunctionParms = System::Int8(0x16);
static _DELPHI_CONST System::Int8 EX_Self = System::Int8(0x17);
static _DELPHI_CONST System::Int8 EX_Skip = System::Int8(0x18);
static _DELPHI_CONST System::Int8 EX_Context = System::Int8(0x19);
static _DELPHI_CONST System::Int8 EX_ArrayElement = System::Int8(0x1a);
static _DELPHI_CONST System::Int8 EX_VirtualFunction = System::Int8(0x1b);
static _DELPHI_CONST System::Int8 EX_FinalFunction = System::Int8(0x1c);
static _DELPHI_CONST System::Int8 EX_IntConst = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 EX_FloatConst = System::Int8(0x1e);
static _DELPHI_CONST System::Int8 EX_StringConst = System::Int8(0x1f);
static _DELPHI_CONST System::Int8 EX_ObjectConst = System::Int8(0x20);
static _DELPHI_CONST System::Int8 EX_NameConst = System::Int8(0x21);
static _DELPHI_CONST System::Int8 EX_RotationConst = System::Int8(0x22);
static _DELPHI_CONST System::Int8 EX_VectorConst = System::Int8(0x23);
static _DELPHI_CONST System::Int8 EX_ByteConst = System::Int8(0x24);
static _DELPHI_CONST System::Int8 EX_IntZero = System::Int8(0x25);
static _DELPHI_CONST System::Int8 EX_IntOne = System::Int8(0x26);
static _DELPHI_CONST System::Int8 EX_True = System::Int8(0x27);
static _DELPHI_CONST System::Int8 EX_False = System::Int8(0x28);
static _DELPHI_CONST System::Int8 EX_NativeParm = System::Int8(0x29);
static _DELPHI_CONST System::Int8 EX_NoObject = System::Int8(0x2a);
static _DELPHI_CONST System::Int8 EX_Unknown_jumpover2 = System::Int8(0x2b);
static _DELPHI_CONST System::Int8 EX_IntConstByte = System::Int8(0x2c);
static _DELPHI_CONST System::Int8 EX_BoolVariable = System::Int8(0x2d);
static _DELPHI_CONST System::Int8 EX_DynamicCast = System::Int8(0x2e);
static _DELPHI_CONST System::Int8 EX_Iterator = System::Int8(0x2f);
static _DELPHI_CONST System::Int8 EX_IteratorPop = System::Int8(0x30);
static _DELPHI_CONST System::Int8 EX_IteratorNext = System::Int8(0x31);
static _DELPHI_CONST System::Int8 EX_StructCmpEq = System::Int8(0x32);
static _DELPHI_CONST System::Int8 EX_StructCmpNe = System::Int8(0x33);
static _DELPHI_CONST System::Int8 EX_UnicodeStringConst = System::Int8(0x34);
static _DELPHI_CONST System::Int8 EX_StructMember = System::Int8(0x36);
static _DELPHI_CONST System::Int8 EX_Length = System::Int8(0x37);
static _DELPHI_CONST System::Int8 EX_GlobalFunction = System::Int8(0x38);
static _DELPHI_CONST System::Int8 EX_RotatorToVector = System::Int8(0x39);
static _DELPHI_CONST System::Int8 EX_ByteToInt = System::Int8(0x3a);
static _DELPHI_CONST System::Int8 EX_ByteToBool = System::Int8(0x3b);
static _DELPHI_CONST System::Int8 EX_ByteToFloat = System::Int8(0x3c);
static _DELPHI_CONST System::Int8 EX_IntToByte = System::Int8(0x3d);
static _DELPHI_CONST System::Int8 EX_IntToBool = System::Int8(0x3e);
static _DELPHI_CONST System::Int8 EX_IntToFloat = System::Int8(0x3f);
static _DELPHI_CONST System::Int8 EX_BoolToByte = System::Int8(0x40);
static _DELPHI_CONST System::Int8 EX_BoolToInt = System::Int8(0x41);
static _DELPHI_CONST System::Int8 EX_Remove = System::Int8(0x41);
static _DELPHI_CONST System::Int8 EX_BoolToFloat = System::Int8(0x42);
static _DELPHI_CONST System::Int8 EX_FloatToByte = System::Int8(0x43);
static _DELPHI_CONST System::Int8 EX_DelegateCall = System::Int8(0x43);
static _DELPHI_CONST System::Int8 EX_FloatToInt = System::Int8(0x44);
static _DELPHI_CONST System::Int8 EX_DelegateName = System::Int8(0x44);
static _DELPHI_CONST System::Int8 EX_FloatToBool = System::Int8(0x45);
static _DELPHI_CONST System::Int8 EX_DelegateAssign = System::Int8(0x45);
static _DELPHI_CONST System::Int8 EX_StringToName = System::Int8(0x46);
static _DELPHI_CONST System::Int8 EX_ObjectToBool = System::Int8(0x47);
static _DELPHI_CONST System::Int8 EX_NameToBool = System::Int8(0x48);
static _DELPHI_CONST System::Int8 EX_StringToByte = System::Int8(0x49);
static _DELPHI_CONST System::Int8 EX_StringToInt = System::Int8(0x4a);
static _DELPHI_CONST System::Int8 EX_StringToBool = System::Int8(0x4b);
static _DELPHI_CONST System::Int8 EX_StringToFloat = System::Int8(0x4c);
static _DELPHI_CONST System::Int8 EX_StringToVector = System::Int8(0x4d);
static _DELPHI_CONST System::Int8 EX_StringToRotator = System::Int8(0x4e);
static _DELPHI_CONST System::Int8 EX_VectorToBool = System::Int8(0x4f);
static _DELPHI_CONST System::Int8 EX_VectorToRotator = System::Int8(0x50);
static _DELPHI_CONST System::Int8 EX_RotatorToBool = System::Int8(0x51);
static _DELPHI_CONST System::Int8 EX_ByteToString = System::Int8(0x52);
static _DELPHI_CONST System::Int8 EX_IntToString = System::Int8(0x53);
static _DELPHI_CONST System::Int8 EX_BoolToString = System::Int8(0x54);
static _DELPHI_CONST System::Int8 EX_FloatToString = System::Int8(0x55);
static _DELPHI_CONST System::Int8 EX_ObjectToString = System::Int8(0x56);
static _DELPHI_CONST System::Int8 EX_NameToString = System::Int8(0x57);
static _DELPHI_CONST System::Int8 EX_VectorToString = System::Int8(0x58);
static _DELPHI_CONST System::Int8 EX_RotatorToString = System::Int8(0x59);
static _DELPHI_CONST System::Int8 EX_StringToName2 = System::Int8(0x5a);
static _DELPHI_CONST System::Int8 EX_Unknown5B = System::Int8(0x5b);
static _DELPHI_CONST System::Int8 EX_ExtendedNative = System::Int8(0x60);
static _DELPHI_CONST System::Int8 EX_FirstNative = System::Int8(0x70);
static _DELPHI_CONST System::Int8 NEST_Foreach = System::Int8(0x1);
static _DELPHI_CONST System::Int8 NEST_Switch = System::Int8(0x2);
static _DELPHI_CONST System::Int8 NEST_If = System::Int8(0x3);
static _DELPHI_CONST System::Int8 NEST_Else = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CPF_Edit = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CPF_Const = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CPF_Input = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CPF_ExportObject = System::Int8(0x8);
static _DELPHI_CONST System::Int8 CPF_OptionalParm = System::Int8(0x10);
static _DELPHI_CONST System::Int8 CPF_Net = System::Int8(0x20);
static _DELPHI_CONST System::Int8 CPF_ConstRef = System::Int8(0x40);
static _DELPHI_CONST System::Byte CPF_Parm = System::Byte(0x80);
static _DELPHI_CONST System::Word CPF_OutParm = System::Word(0x100);
static _DELPHI_CONST System::Word CPF_SkipParm = System::Word(0x200);
static _DELPHI_CONST System::Word CPF_ReturnParm = System::Word(0x400);
static _DELPHI_CONST System::Word CPF_CoerceParm = System::Word(0x800);
static _DELPHI_CONST System::Word CPF_Native = System::Word(0x1000);
static _DELPHI_CONST System::Word CPF_Transient = System::Word(0x2000);
static _DELPHI_CONST System::Word CPF_Config = System::Word(0x4000);
static _DELPHI_CONST System::Word CPF_Localized = System::Word(0x8000);
static _DELPHI_CONST int CPF_Travel = int(0x10000);
static _DELPHI_CONST int CPF_EditConst = int(0x20000);
static _DELPHI_CONST int CPF_GlobalConfig = int(0x40000);
static _DELPHI_CONST int CPF_OnDemand = int(0x100000);
static _DELPHI_CONST int CPF_New = int(0x200000);
static _DELPHI_CONST int CPF_NeedCtorLink = int(0x400000);
static _DELPHI_CONST int CPF_EditorData = int(0x2000000);
static _DELPHI_CONST int CPF_EditInlineUse = int(0x14000000);
static _DELPHI_CONST int CPF_EditInline = int(0x4000000);
static _DELPHI_CONST int CPF_Deprecated = int(0x20000000);
static _DELPHI_CONST System::Int8 FUNC_Final = System::Int8(0x1);
static _DELPHI_CONST System::Int8 FUNC_Defined = System::Int8(0x2);
static _DELPHI_CONST System::Int8 FUNC_Iterator = System::Int8(0x4);
static _DELPHI_CONST System::Int8 FUNC_Latent = System::Int8(0x8);
static _DELPHI_CONST System::Int8 FUNC_PreOperator = System::Int8(0x10);
static _DELPHI_CONST System::Int8 FUNC_Singular = System::Int8(0x20);
static _DELPHI_CONST System::Int8 FUNC_Net = System::Int8(0x40);
static _DELPHI_CONST System::Byte FUNC_NetReliable = System::Byte(0x80);
static _DELPHI_CONST System::Word FUNC_Simulated = System::Word(0x100);
static _DELPHI_CONST System::Word FUNC_Exec = System::Word(0x200);
static _DELPHI_CONST System::Word FUNC_Native = System::Word(0x400);
static _DELPHI_CONST System::Word FUNC_Event = System::Word(0x800);
static _DELPHI_CONST System::Word FUNC_Operator = System::Word(0x1000);
static _DELPHI_CONST System::Word FUNC_Static = System::Word(0x2000);
static _DELPHI_CONST System::Word FUNC_NoExport = System::Word(0x4000);
static _DELPHI_CONST System::Word FUNC_Const = System::Word(0x8000);
static _DELPHI_CONST int FUNC_Invariant = int(0x10000);
static _DELPHI_CONST int FUNC_Unk_00020000 = int(0x20000);
static _DELPHI_CONST int FUNC_Delegate = int(0x100000);
static _DELPHI_CONST int FUNC_Unk_01000000 = int(0x1000000);
static _DELPHI_CONST System::Int8 CLASS_Abstract = System::Int8(0x1);
static _DELPHI_CONST System::Int8 CLASS_Compiled = System::Int8(0x2);
static _DELPHI_CONST System::Int8 CLASS_Config = System::Int8(0x4);
static _DELPHI_CONST System::Int8 CLASS_Transient = System::Int8(0x8);
static _DELPHI_CONST System::Int8 CLASS_Parsed = System::Int8(0x10);
static _DELPHI_CONST System::Int8 CLASS_Localized = System::Int8(0x20);
static _DELPHI_CONST System::Int8 CLASS_SafeReplace = System::Int8(0x40);
static _DELPHI_CONST System::Byte CLASS_RuntimeStatic = System::Byte(0x80);
static _DELPHI_CONST System::Word CLASS_NoExport = System::Word(0x100);
static _DELPHI_CONST System::Word CLASS_NoUserCreate = System::Word(0x200);
static _DELPHI_CONST System::Word CLASS_PerObjectConfig = System::Word(0x400);
static _DELPHI_CONST System::Word CLASS_NativeReplication = System::Word(0x800);
static _DELPHI_CONST System::Word CLASS_EditInlineNew = System::Word(0x1000);
static _DELPHI_CONST System::Word CLASS_CollapseCategories = System::Word(0x2000);
static _DELPHI_CONST System::Word CLASS_ExportStructs = System::Word(0x4000);
static _DELPHI_CONST System::Int8 STATE_Editable = System::Int8(0x1);
static _DELPHI_CONST System::Int8 STATE_Auto = System::Int8(0x2);
static _DELPHI_CONST System::Int8 STATE_Simulated = System::Int8(0x4);
static _DELPHI_CONST System::Int8 NF_NotCsg = System::Int8(0x1);
static _DELPHI_CONST System::Int8 NF_ShootThrough = System::Int8(0x2);
static _DELPHI_CONST System::Int8 NF_NotVisBlocking = System::Int8(0x4);
static _DELPHI_CONST System::Int8 NF_PolyOccluded = System::Int8(0x8);
static _DELPHI_CONST System::Int8 NF_BoxOccluded = System::Int8(0x10);
static _DELPHI_CONST System::Int8 NF_BrightCorners = System::Int8(0x10);
static _DELPHI_CONST System::Int8 NF_IsNew = System::Int8(0x20);
static _DELPHI_CONST System::Int8 NF_IsFront = System::Int8(0x40);
static _DELPHI_CONST System::Byte NF_IsBack = System::Byte(0x80);
static _DELPHI_CONST System::Int8 NF_NeverMove = System::Int8(0x0);
static _DELPHI_CONST System::Int8 R_WALK = System::Int8(0x1);
static _DELPHI_CONST System::Int8 R_FLY = System::Int8(0x2);
static _DELPHI_CONST System::Int8 R_SWIM = System::Int8(0x4);
static _DELPHI_CONST System::Int8 R_JUMP = System::Int8(0x8);
static _DELPHI_CONST System::Int8 R_DOOR = System::Int8(0x10);
static _DELPHI_CONST System::Int8 R_SPECIAL = System::Int8(0x20);
static _DELPHI_CONST System::Int8 R_PLAYERONLY = System::Int8(0x40);
static _DELPHI_CONST System::Int8 PF_Invisible = System::Int8(0x1);
static _DELPHI_CONST System::Int8 PF_Masked = System::Int8(0x2);
static _DELPHI_CONST System::Int8 PF_Translucent = System::Int8(0x4);
static _DELPHI_CONST System::Int8 PF_NotSolid = System::Int8(0x8);
static _DELPHI_CONST System::Int8 PF_Environment = System::Int8(0x10);
static _DELPHI_CONST System::Int8 PF_ForceViewZone = System::Int8(0x10);
static _DELPHI_CONST System::Int8 PF_Semisolid = System::Int8(0x20);
static _DELPHI_CONST System::Int8 PF_Modulated = System::Int8(0x40);
static _DELPHI_CONST System::Byte PF_FakeBackdrop = System::Byte(0x80);
static _DELPHI_CONST System::Word PF_TwoSided = System::Word(0x100);
static _DELPHI_CONST System::Word PF_AutoUPan = System::Word(0x200);
static _DELPHI_CONST System::Word PF_AutoVPan = System::Word(0x400);
static _DELPHI_CONST System::Word PF_NoSmooth = System::Word(0x800);
static _DELPHI_CONST System::Word PF_BigWavy = System::Word(0x1000);
static _DELPHI_CONST System::Word PF_SpecialPoly = System::Word(0x1000);
static _DELPHI_CONST System::Word PF_SmallWavy = System::Word(0x2000);
static _DELPHI_CONST System::Word PF_Flat = System::Word(0x4000);
static _DELPHI_CONST System::Word PF_LowShadowDetail = System::Word(0x8000);
static _DELPHI_CONST int PF_NoMerge = int(0x10000);
static _DELPHI_CONST int PF_CloudWavy = int(0x20000);
static _DELPHI_CONST int PF_DirtyShadows = int(0x40000);
static _DELPHI_CONST int PF_BrightCorners = int(0x80000);
static _DELPHI_CONST int PF_SpecialLit = int(0x100000);
static _DELPHI_CONST int PF_Gouraud = int(0x200000);
static _DELPHI_CONST int PF_NoBoundRejection = int(0x200000);
static _DELPHI_CONST int PF_Unlit = int(0x400000);
static _DELPHI_CONST int PF_HighShadowDetail = int(0x800000);
static _DELPHI_CONST int PF_Portal = int(0x4000000);
static _DELPHI_CONST int PF_Mirrored = int(0x8000000);
static _DELPHI_CONST int PF_Memorized = int(0x1000000);
static _DELPHI_CONST int PF_Selected = int(0x2000000);
static _DELPHI_CONST int PF_Highlighted = int(0x10000000);
static _DELPHI_CONST int PF_FlatShaded = int(0x40000000);
static _DELPHI_CONST int PF_EdProcessed = int(0x40000000);
static _DELPHI_CONST unsigned PF_EdCut = unsigned(0x80000000);
static _DELPHI_CONST int PF_RenderFog = int(0x40000000);
static _DELPHI_CONST unsigned PF_Occlude = unsigned(0x80000000);
static _DELPHI_CONST int PF_RenderHint = int(0x1000000);
static _DELPHI_CONST System::Int8 PF_NoOcclude = System::Int8(0x47);
static _DELPHI_CONST unsigned PF_NoEdit = unsigned(0xc3010000);
static _DELPHI_CONST unsigned PF_NoImport = unsigned(0xc3010000);
static _DELPHI_CONST System::Int8 PF_AddLast = System::Int8(0x28);
static _DELPHI_CONST unsigned PF_NoAddToBSP = unsigned(0xc3000000);
static _DELPHI_CONST int PF_NoShadows = int(0x400091);
static _DELPHI_CONST int PF_Transient = int(0x10000000);
static _DELPHI_CONST System::Int8 TEXF_P8 = System::Int8(0x0);
static _DELPHI_CONST System::Int8 TEXF_RGBA7 = System::Int8(0x1);
static _DELPHI_CONST System::Int8 TEXF_RGB16 = System::Int8(0x2);
static _DELPHI_CONST System::Int8 TEXF_DXT1 = System::Int8(0x3);
static _DELPHI_CONST System::Int8 TEXF_RGB8 = System::Int8(0x4);
static _DELPHI_CONST System::Int8 TEXF_RGBA8 = System::Int8(0x5);
static _DELPHI_CONST System::Int8 TEXF_NODATA = System::Int8(0x6);
static _DELPHI_CONST System::Int8 TEXF_DXT3 = System::Int8(0x7);
static _DELPHI_CONST System::Int8 TEXF_DXT5 = System::Int8(0x8);
static _DELPHI_CONST System::Int8 TEXF_L8 = System::Int8(0x9);
static _DELPHI_CONST System::Int8 TEXF_G16 = System::Int8(0xa);
static _DELPHI_CONST System::Int8 TEXF_RRRGGGBBB = System::Int8(0xb);
extern DELPHI_PACKAGE TUTPropertyClass UTPropertyClass;
extern DELPHI_PACKAGE void __fastcall AddUTClassEquivalence(System::UnicodeString classname, System::UnicodeString equivalentclass);
extern DELPHI_PACKAGE void __fastcall ClearUTClassEquivalences();
extern DELPHI_PACKAGE void __fastcall RegisterUTObjectClass(System::UnicodeString classname, TUTObjectClass classclass);
extern DELPHI_PACKAGE TUTObjectClass __fastcall GetUTObjectClass(System::UnicodeString classname);
extern DELPHI_PACKAGE TUT_Struct_Vector __fastcall Read_Struct_Vector(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Rotator __fastcall Read_Struct_Rotator(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Polygon __fastcall Read_Struct_Polygon(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Spark __fastcall Read_Struct_Spark(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_BoundingBox __fastcall Read_Struct_BoundingBox(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_BoundingSphere __fastcall Read_Struct_BoundingSphere(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Vert __fastcall Read_Struct_Vert(TUTPackage* owner, System::Classes::TStream* buffer, bool highres, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Tri __fastcall Read_Struct_Tri(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Texture __fastcall Read_Struct_Texture(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_AnimSeqNotify __fastcall Read_Struct_AnimSeqNotify(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_AnimSeq __fastcall Read_Struct_AnimSeq(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name_ = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Connects __fastcall Read_Struct_Connects(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Wedge __fastcall Read_Struct_Wedge(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Face __fastcall Read_Struct_Face(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Material __fastcall Read_Struct_Material(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_MeshFloatUV __fastcall Read_Struct_MeshFloatUV(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_MeshExtWedge __fastcall Read_Struct_MeshExtWedge(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Quat __fastcall Read_Struct_Quat(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_JointPos __fastcall Read_Struct_JointPos(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_MeshBone __fastcall Read_Struct_MeshBone(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name_ = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_BoneInfIndex __fastcall Read_Struct_BoneInfIndex(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_BoneInfluence __fastcall Read_Struct_BoneInfluence(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Coords __fastcall Read_Struct_Coords(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_NamedBone __fastcall Read_Struct_NamedBone(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name_ = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_AnalogTrack __fastcall Read_Struct_AnalogTrack(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_MotionChunk __fastcall Read_Struct_MotionChunk(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Dependency __fastcall Read_Struct_Dependency(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_LabelEntry __fastcall Read_Struct_LabelEntry(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name_ = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_BspNode __fastcall Read_Struct_BspNode(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_BspSurf __fastcall Read_Struct_BspSurf(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_FVert __fastcall Read_Struct_FVert(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_ZoneProperties __fastcall Read_Struct_Zone(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_LightMapIndex __fastcall Read_Struct_LightMap(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Leaf __fastcall Read_Struct_Leaf(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_URL __fastcall Read_Struct_URL(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_ReachSpec __fastcall Read_Struct_ReachSpec(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE TUT_Struct_Map __fastcall Read_Struct_Map(TUTPackage* owner, System::Classes::TStream* buffer, System::UnicodeString name = System::UnicodeString());
extern DELPHI_PACKAGE void __fastcall RegisterKnownEnumValues(System::UnicodeString enumtype, System::UnicodeString *values, const System::NativeInt values_High);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetKnownEnumValue(System::UnicodeString enumtype, int index);
extern DELPHI_PACKAGE void __fastcall RegisterNativeFunctionArray(TUTPackage_GameHint gamehint, const TNativeFunction *functions, const System::NativeInt functions_High);
extern DELPHI_PACKAGE int __fastcall KnownStructElementCount(System::UnicodeString name);
extern DELPHI_PACKAGE bool __fastcall IsKnownStruct(System::UnicodeString name);
extern DELPHI_PACKAGE TKnownStructElement __fastcall KnownStructElement(System::UnicodeString name, int i);
extern DELPHI_PACKAGE void __fastcall Register2DClasses();
extern DELPHI_PACKAGE void __fastcall Register3DClasses();
extern DELPHI_PACKAGE void __fastcall RegisterSoundClasses();
extern DELPHI_PACKAGE void __fastcall RegisterCodeClasses();
extern DELPHI_PACKAGE void __fastcall RegisterOtherClasses();
extern DELPHI_PACKAGE void __fastcall RegisterAllClasses();
}	/* namespace Ut_packages */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_UT_PACKAGES)
using namespace Ut_packages;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ut_packagesHPP
