// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'sevenzip.pas' rev: 37.00 (Windows)

#ifndef sevenzipHPP
#define sevenzipHPP

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
#include <Winapi.Windows.hpp>
#include <Winapi.ActiveX.hpp>
#include <System.Classes.hpp>
#include <System.Contnrs.hpp>
#include <System.IOUtils.hpp>
#include <System.Math.hpp>

//-- user supplied -----------------------------------------------------------

namespace Sevenzip
{
//-- forward type declarations -----------------------------------------------
__interface DELPHIINTERFACE IProgress;
typedef System::DelphiInterface<IProgress> _di_IProgress;
__interface DELPHIINTERFACE ICryptoGetTextPassword;
typedef System::DelphiInterface<ICryptoGetTextPassword> _di_ICryptoGetTextPassword;
__interface DELPHIINTERFACE ICryptoGetTextPassword2;
typedef System::DelphiInterface<ICryptoGetTextPassword2> _di_ICryptoGetTextPassword2;
__interface DELPHIINTERFACE ISequentialInStream;
typedef System::DelphiInterface<ISequentialInStream> _di_ISequentialInStream;
__interface DELPHIINTERFACE ISequentialOutStream;
typedef System::DelphiInterface<ISequentialOutStream> _di_ISequentialOutStream;
__interface DELPHIINTERFACE IInStream;
typedef System::DelphiInterface<IInStream> _di_IInStream;
__interface DELPHIINTERFACE IOutStream;
typedef System::DelphiInterface<IOutStream> _di_IOutStream;
__interface DELPHIINTERFACE IStreamGetSize;
typedef System::DelphiInterface<IStreamGetSize> _di_IStreamGetSize;
__interface DELPHIINTERFACE IOutStreamFinish;
typedef System::DelphiInterface<IOutStreamFinish> _di_IOutStreamFinish;
__interface DELPHIINTERFACE IStreamGetProps;
typedef System::DelphiInterface<IStreamGetProps> _di_IStreamGetProps;
__interface DELPHIINTERFACE IArchiveOpenCallback;
typedef System::DelphiInterface<IArchiveOpenCallback> _di_IArchiveOpenCallback;
__interface DELPHIINTERFACE IArchiveExtractCallback;
typedef System::DelphiInterface<IArchiveExtractCallback> _di_IArchiveExtractCallback;
__interface DELPHIINTERFACE IArchiveExtractCallbackMessage;
typedef System::DelphiInterface<IArchiveExtractCallbackMessage> _di_IArchiveExtractCallbackMessage;
__interface DELPHIINTERFACE IArchiveExtractCallbackMessage2;
typedef System::DelphiInterface<IArchiveExtractCallbackMessage2> _di_IArchiveExtractCallbackMessage2;
__interface DELPHIINTERFACE IArchiveOpenVolumeCallback;
typedef System::DelphiInterface<IArchiveOpenVolumeCallback> _di_IArchiveOpenVolumeCallback;
__interface DELPHIINTERFACE IInArchiveGetStream;
typedef System::DelphiInterface<IInArchiveGetStream> _di_IInArchiveGetStream;
__interface DELPHIINTERFACE IArchiveOpenSetSubArchiveName;
typedef System::DelphiInterface<IArchiveOpenSetSubArchiveName> _di_IArchiveOpenSetSubArchiveName;
__interface DELPHIINTERFACE IInArchive;
typedef System::DelphiInterface<IInArchive> _di_IInArchive;
__interface DELPHIINTERFACE IArchiveOpenSeq;
typedef System::DelphiInterface<IArchiveOpenSeq> _di_IArchiveOpenSeq;
__interface DELPHIINTERFACE IArchiveGetRawProps;
typedef System::DelphiInterface<IArchiveGetRawProps> _di_IArchiveGetRawProps;
__interface DELPHIINTERFACE IArchiveGetRootProps;
typedef System::DelphiInterface<IArchiveGetRootProps> _di_IArchiveGetRootProps;
__interface DELPHIINTERFACE IArchiveUpdateCallback;
typedef System::DelphiInterface<IArchiveUpdateCallback> _di_IArchiveUpdateCallback;
__interface DELPHIINTERFACE IArchiveUpdateCallback2;
typedef System::DelphiInterface<IArchiveUpdateCallback2> _di_IArchiveUpdateCallback2;
__interface DELPHIINTERFACE IOutArchive;
typedef System::DelphiInterface<IOutArchive> _di_IOutArchive;
__interface DELPHIINTERFACE ISetProperties;
typedef System::DelphiInterface<ISetProperties> _di_ISetProperties;
__interface DELPHIINTERFACE IArchiveKeepModeForNextOpen;
typedef System::DelphiInterface<IArchiveKeepModeForNextOpen> _di_IArchiveKeepModeForNextOpen;
__interface DELPHIINTERFACE IArchiveAllowTail;
typedef System::DelphiInterface<IArchiveAllowTail> _di_IArchiveAllowTail;
__interface DELPHIINTERFACE ICompressProgressInfo;
typedef System::DelphiInterface<ICompressProgressInfo> _di_ICompressProgressInfo;
__interface DELPHIINTERFACE ICompressCoder;
typedef System::DelphiInterface<ICompressCoder> _di_ICompressCoder;
__interface DELPHIINTERFACE ICompressCoder2;
typedef System::DelphiInterface<ICompressCoder2> _di_ICompressCoder2;
__interface DELPHIINTERFACE ICompressSetCoderPropertiesOpt;
typedef System::DelphiInterface<ICompressSetCoderPropertiesOpt> _di_ICompressSetCoderPropertiesOpt;
__interface DELPHIINTERFACE ICompressSetCoderProperties;
typedef System::DelphiInterface<ICompressSetCoderProperties> _di_ICompressSetCoderProperties;
__interface DELPHIINTERFACE ICompressSetDecoderProperties2;
typedef System::DelphiInterface<ICompressSetDecoderProperties2> _di_ICompressSetDecoderProperties2;
__interface DELPHIINTERFACE ICompressWriteCoderProperties;
typedef System::DelphiInterface<ICompressWriteCoderProperties> _di_ICompressWriteCoderProperties;
__interface DELPHIINTERFACE ICompressGetInStreamProcessedSize;
typedef System::DelphiInterface<ICompressGetInStreamProcessedSize> _di_ICompressGetInStreamProcessedSize;
__interface DELPHIINTERFACE ICompressSetCoderMt;
typedef System::DelphiInterface<ICompressSetCoderMt> _di_ICompressSetCoderMt;
__interface DELPHIINTERFACE ICompressSetFinishMode;
typedef System::DelphiInterface<ICompressSetFinishMode> _di_ICompressSetFinishMode;
__interface DELPHIINTERFACE ICompressGetInStreamProcessedSize2;
typedef System::DelphiInterface<ICompressGetInStreamProcessedSize2> _di_ICompressGetInStreamProcessedSize2;
__interface DELPHIINTERFACE ICompressSetMemLimit;
typedef System::DelphiInterface<ICompressSetMemLimit> _di_ICompressSetMemLimit;
__interface DELPHIINTERFACE ICompressReadUnusedFromInBuf;
typedef System::DelphiInterface<ICompressReadUnusedFromInBuf> _di_ICompressReadUnusedFromInBuf;
__interface DELPHIINTERFACE ICompressGetSubStreamSize;
typedef System::DelphiInterface<ICompressGetSubStreamSize> _di_ICompressGetSubStreamSize;
__interface DELPHIINTERFACE ICompressSetInStream;
typedef System::DelphiInterface<ICompressSetInStream> _di_ICompressSetInStream;
__interface DELPHIINTERFACE ICompressSetOutStream;
typedef System::DelphiInterface<ICompressSetOutStream> _di_ICompressSetOutStream;
__interface DELPHIINTERFACE ICompressSetInStreamSize;
typedef System::DelphiInterface<ICompressSetInStreamSize> _di_ICompressSetInStreamSize;
__interface DELPHIINTERFACE ICompressSetOutStreamSize;
typedef System::DelphiInterface<ICompressSetOutStreamSize> _di_ICompressSetOutStreamSize;
__interface DELPHIINTERFACE ICompressSetBufSize;
typedef System::DelphiInterface<ICompressSetBufSize> _di_ICompressSetBufSize;
__interface DELPHIINTERFACE ICompressInitEncoder;
typedef System::DelphiInterface<ICompressInitEncoder> _di_ICompressInitEncoder;
__interface DELPHIINTERFACE ICompressSetInStream2;
typedef System::DelphiInterface<ICompressSetInStream2> _di_ICompressSetInStream2;
__interface DELPHIINTERFACE ICompressSetOutStream2;
typedef System::DelphiInterface<ICompressSetOutStream2> _di_ICompressSetOutStream2;
__interface DELPHIINTERFACE ICompressSetInStreamSize2;
typedef System::DelphiInterface<ICompressSetInStreamSize2> _di_ICompressSetInStreamSize2;
__interface DELPHIINTERFACE ICompressInSubStreams;
typedef System::DelphiInterface<ICompressInSubStreams> _di_ICompressInSubStreams;
__interface DELPHIINTERFACE ICompressOutSubStreams;
typedef System::DelphiInterface<ICompressOutSubStreams> _di_ICompressOutSubStreams;
__interface DELPHIINTERFACE ICompressFilter;
typedef System::DelphiInterface<ICompressFilter> _di_ICompressFilter;
__interface DELPHIINTERFACE ICompressCodecsInfo;
typedef System::DelphiInterface<ICompressCodecsInfo> _di_ICompressCodecsInfo;
__interface DELPHIINTERFACE ISetCompressCodecsInfo;
typedef System::DelphiInterface<ISetCompressCodecsInfo> _di_ISetCompressCodecsInfo;
__interface DELPHIINTERFACE ICryptoProperties;
typedef System::DelphiInterface<ICryptoProperties> _di_ICryptoProperties;
__interface DELPHIINTERFACE ICryptoResetSalt;
typedef System::DelphiInterface<ICryptoResetSalt> _di_ICryptoResetSalt;
__interface DELPHIINTERFACE ICryptoResetInitVector;
typedef System::DelphiInterface<ICryptoResetInitVector> _di_ICryptoResetInitVector;
__interface DELPHIINTERFACE ICryptoSetPassword;
typedef System::DelphiInterface<ICryptoSetPassword> _di_ICryptoSetPassword;
__interface DELPHIINTERFACE ICryptoSetCRC;
typedef System::DelphiInterface<ICryptoSetCRC> _di_ICryptoSetCRC;
__interface DELPHIINTERFACE IHasher;
typedef System::DelphiInterface<IHasher> _di_IHasher;
__interface DELPHIINTERFACE IHashers;
typedef System::DelphiInterface<IHashers> _di_IHashers;
__interface DELPHIINTERFACE I7zInArchive;
typedef System::DelphiInterface<I7zInArchive> _di_I7zInArchive;
__interface DELPHIINTERFACE I7zOutArchive;
typedef System::DelphiInterface<I7zOutArchive> _di_I7zOutArchive;
__interface DELPHIINTERFACE I7zCodec;
typedef System::DelphiInterface<I7zCodec> _di_I7zCodec;
class DELPHICLASS T7zStream;
__interface DELPHIINTERFACE IArchiveFactory;
typedef System::DelphiInterface<IArchiveFactory> _di_IArchiveFactory;
class DELPHICLASS TArchiveFactory;
//-- type declarations -------------------------------------------------------
typedef int *PInt32;

typedef System::Word *PVarType;

typedef System::StaticArray<unsigned, 536870911> TCardArray;

typedef TCardArray *PCardArray;

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000000050000}") IProgress  : public System::IInterface
{
	virtual HRESULT __stdcall SetTotal(unsigned __int64 total) = 0 ;
	virtual HRESULT __stdcall SetCompleted(System::PUInt64 completeValue) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000500100000}") ICryptoGetTextPassword  : public System::IInterface
{
	virtual HRESULT __stdcall CryptoGetTextPassword(Winapi::Activex::TBStr &password) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000500110000}") ICryptoGetTextPassword2  : public System::IInterface
{
	virtual HRESULT __stdcall CryptoGetTextPassword2(PInt32 passwordIsDefined, Winapi::Activex::TBStr &password) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000300010000}") ISequentialInStream  : public System::IInterface
{
	virtual HRESULT __stdcall Read(void * data, System::UInt32 size, System::PUint32 processedSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000300020000}") ISequentialOutStream  : public System::IInterface
{
	virtual HRESULT __stdcall Write(void * data, System::UInt32 size, System::PUint32 processedSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000300030000}") IInStream  : public ISequentialInStream
{
	virtual HRESULT __stdcall Seek(__int64 offset, System::UInt32 seekOrigin, System::PUInt64 newPosition) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000300040000}") IOutStream  : public ISequentialOutStream
{
	virtual HRESULT __stdcall Seek(__int64 offset, System::UInt32 seekOrigin, System::PUInt64 newPosition) = 0 ;
	virtual HRESULT __stdcall SetSize(unsigned __int64 newSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000300060000}") IStreamGetSize  : public System::IInterface
{
	virtual HRESULT __stdcall GetSize(System::PUInt64 size) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000300070000}") IOutStreamFinish  : public System::IInterface
{
	virtual HRESULT __stdcall OutStreamFinish() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000300080000}") IStreamGetProps  : public System::IInterface
{
	virtual HRESULT __stdcall GetProps(System::PUInt64 size, Winapi::Windows::PFileTime cTime, Winapi::Windows::PFileTime aTime, Winapi::Windows::PFileTime mTime, System::PUint32 attrib) = 0 ;
};

enum DECLSPEC_DENUM NFileTimeType : unsigned int { kWindows, kUnix, kDOS };

enum DECLSPEC_DENUM NArcInfoFlags : unsigned int { aifKeepName = 0x1, aifAltStreams, aifNtSecure = 0x4, aifFindSignature = 0x8, aifMultiSignature = 0x10, aifUseGlobalOffset = 0x20, aifStartOpen = 0x40, aifPureStartOpen = 0x80, aifBackwardOpen = 0x100, aifPreArc = 0x200, aifSymLinks = 0x400, aifHardLinks = 0x800 };

enum DECLSPEC_DENUM NHandlerPropID : unsigned int { kName, kClassID, kExtension, kAddExtension, kUpdate, kKeepName, kSignature, kMultiSignature, kSignatureOffset, kAltStreams, kNtSecure, kFlags, kTimeFlags };

enum DECLSPEC_DENUM NAskMode : unsigned int { kExtract, kTest, kSkip, kReadExternal };

enum DECLSPEC_DENUM NExtOperationResult : unsigned int { kOK, kUnSupportedMethod, kDataError, kCRCError, kUnavailable, kUnexpectedEnd, kDataAfterEnd, kIsNotArc, kHeadersError, kWrongPassword };

enum DECLSPEC_DENUM NEventIndexType : unsigned int { kNoIndex, kInArcIndex, kBlockIndex, kOutArcIndex };

enum DECLSPEC_DENUM NUpdOperationResult : unsigned int { kOK_, kError };

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600100000}") IArchiveOpenCallback  : public System::IInterface
{
	virtual HRESULT __stdcall SetTotal(System::PUInt64 files, System::PUInt64 bytes) = 0 ;
	virtual HRESULT __stdcall SetCompleted(System::PUInt64 files, System::PUInt64 bytes) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600200000}") IArchiveExtractCallback  : public IProgress
{
	virtual HRESULT __stdcall GetStream(System::UInt32 index, _di_ISequentialOutStream &outStream, NAskMode askExtractMode) = 0 ;
	virtual HRESULT __stdcall PrepareOperation(NAskMode askExtractMode) = 0 ;
	virtual HRESULT __stdcall SetOperationResult(NExtOperationResult resultEOperationResult) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600210000}") IArchiveExtractCallbackMessage  : public System::IInterface
{
	virtual HRESULT __stdcall ReportExtractResult(NEventIndexType indexType, System::UInt32 index, System::Int32 opRes) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600220000}") IArchiveExtractCallbackMessage2  : public System::IInterface
{
	virtual HRESULT __stdcall ReportExtractResult(NEventIndexType indexType, System::UInt32 index, System::Int32 opRes) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600300000}") IArchiveOpenVolumeCallback  : public System::IInterface
{
	virtual HRESULT __stdcall GetProperty(unsigned propID, System::OleVariant &value) = 0 ;
	virtual HRESULT __stdcall GetStream(const System::WideChar * name, _di_IInStream &inStream) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600400000}") IInArchiveGetStream  : public System::IInterface
{
	virtual HRESULT __stdcall GetStream(System::UInt32 index, _di_ISequentialInStream &stream) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600500000}") IArchiveOpenSetSubArchiveName  : public System::IInterface
{
	virtual HRESULT __stdcall SetSubArchiveName(System::WideChar * name) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600600000}") IInArchive  : public System::IInterface
{
	virtual HRESULT __stdcall Open(_di_IInStream stream, const System::PInt64 maxCheckStartPosition, _di_IArchiveOpenCallback openArchiveCallback) = 0 ;
	virtual HRESULT __stdcall Close() = 0 ;
	virtual HRESULT __stdcall GetNumberOfItems(System::UInt32 &numItems) = 0 ;
	virtual HRESULT __stdcall GetProperty(System::UInt32 index, unsigned propID, System::OleVariant &value) = 0 ;
	virtual HRESULT __stdcall Extract(PCardArray indices, System::UInt32 numItems, int testMode, _di_IArchiveExtractCallback extractCallback) = 0 ;
	virtual HRESULT __stdcall GetArchiveProperty(unsigned propID, System::OleVariant &value) = 0 ;
	virtual HRESULT __stdcall GetNumberOfProperties(System::PUint32 numProps) = 0 ;
	virtual HRESULT __stdcall GetPropertyInfo(System::UInt32 index, Winapi::Activex::PBStr name, Winapi::Activex::PPropID propID, PVarType varType) = 0 ;
	virtual HRESULT __stdcall GetNumberOfArchiveProperties(System::UInt32 &numProps) = 0 ;
	virtual HRESULT __stdcall GetArchivePropertyInfo(System::UInt32 index, Winapi::Activex::PBStr name, Winapi::Activex::PPropID propID, PVarType varType) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600610000}") IArchiveOpenSeq  : public System::IInterface
{
	virtual HRESULT __stdcall OpenSeq(_di_ISequentialInStream &stream) = 0 ;
};

enum DECLSPEC_DENUM NParentType : unsigned int { kDir, kAltStream };

enum DECLSPEC_DENUM NPropDataType : unsigned int { kMask_ZeroEnd = 16, kMask_Utf = 64, kMask_Utf8 = 64, kMask_Utf16, kNotDefined = 0, kRaw, kUtf8z = 80, kUtf16z };

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600700000}") IArchiveGetRawProps  : public System::IInterface
{
	virtual HRESULT __stdcall GetParent(System::UInt32 index, System::UInt32 &parent, System::UInt32 &parentType) = 0 ;
	virtual HRESULT __stdcall GetRawProp(System::UInt32 index, unsigned propID, void * &data, System::UInt32 &dataSize, System::UInt32 &propType) = 0 ;
	virtual HRESULT __stdcall GetNumRawProps(System::UInt32 &numProps) = 0 ;
	virtual HRESULT __stdcall GetRawPropInfo(System::UInt32 index, Winapi::Activex::PBStr name, unsigned &propID) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600710000}") IArchiveGetRootProps  : public System::IInterface
{
	virtual HRESULT __stdcall GetRootProp(unsigned propID, tagPROPVARIANT &value) = 0 ;
	virtual HRESULT __stdcall GetRootRawProp(unsigned propID, void * &data, System::UInt32 &dataSize, System::UInt32 &propType) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600800000}") IArchiveUpdateCallback  : public IProgress
{
	virtual HRESULT __stdcall GetUpdateItemInfo(System::UInt32 index, PInt32 newData, PInt32 newProps, System::PUint32 indexInArchive) = 0 ;
	virtual HRESULT __stdcall GetProperty(System::UInt32 index, unsigned propID, System::OleVariant &value) = 0 ;
	virtual HRESULT __stdcall GetStream(System::UInt32 index, _di_ISequentialInStream &inStream) = 0 ;
	virtual HRESULT __stdcall SetOperationResult(System::Int32 operationResult) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600820000}") IArchiveUpdateCallback2  : public IArchiveUpdateCallback
{
	virtual HRESULT __stdcall GetVolumeSize(System::UInt32 index, System::PUInt64 size) = 0 ;
	virtual HRESULT __stdcall GetVolumeStream(System::UInt32 index, _di_ISequentialOutStream &volumeStream) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600A00000}") IOutArchive  : public System::IInterface
{
	virtual HRESULT __stdcall UpdateItems(_di_ISequentialOutStream outStream, System::UInt32 numItems, _di_IArchiveUpdateCallback updateCallback) = 0 ;
	virtual HRESULT __stdcall GetFileTimeType(System::PUint32 type_) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600030000}") ISetProperties  : public System::IInterface
{
	virtual HRESULT __stdcall SetProperties(System::PPWideChar names, Winapi::Activex::PPropVariant values, System::UInt32 numProps) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600040000}") IArchiveKeepModeForNextOpen  : public System::IInterface
{
	virtual HRESULT __stdcall KeepModeForNextOpen() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000600050000}") IArchiveAllowTail  : public System::IInterface
{
	virtual HRESULT __stdcall AllowTail(System::Int32 allowTail) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400040000}") ICompressProgressInfo  : public System::IInterface
{
	virtual HRESULT __stdcall SetRatioInfo(System::PUInt64 inSize, System::PUInt64 outSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400050000}") ICompressCoder  : public System::IInterface
{
	virtual HRESULT __stdcall Code(_di_ISequentialInStream inStream, _di_ISequentialInStream outStream, System::PUInt64 inSize, System::PUInt64 outSize, _di_ICompressProgressInfo progress) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400180000}") ICompressCoder2  : public System::IInterface
{
	virtual HRESULT __stdcall Code(_di_ISequentialInStream &inStreams, System::PUInt64 &inSizes, System::UInt32 numInStreams, _di_ISequentialOutStream &outStreams, System::PUInt64 &outSizes, System::UInt32 numOutStreams, _di_ICompressProgressInfo progress) = 0 ;
};

enum DECLSPEC_DENUM NCoderPropID : unsigned int { kDefaultProp, kDictionarySize, kUsedMemorySize, kOrder, kBlockSize, kPosStateBits, kLitContextBits, kLitPosBits, kNumFastBytes, kMatchFinder, kMatchFinderCycles, kNumPasses, kAlgorithm, kNumThreads, kEndMarker, kLevel, kReduceSize };

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-0004001F0000}") ICompressSetCoderPropertiesOpt  : public System::IInterface
{
	virtual HRESULT __stdcall SetCoderPropertiesOpt(Winapi::Activex::PPropID propIDs, const tagPROPVARIANT &props, System::UInt32 numProps) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400200000}") ICompressSetCoderProperties  : public System::IInterface
{
	virtual HRESULT __stdcall SetCoderProperties(Winapi::Activex::PPropID propIDs, const tagPROPVARIANT &props, System::UInt32 numProps) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400220000}") ICompressSetDecoderProperties2  : public System::IInterface
{
	virtual HRESULT __stdcall SetDecoderProperties2(Winapi::Windows::PByte data, System::UInt32 size) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400230000}") ICompressWriteCoderProperties  : public System::IInterface
{
	virtual HRESULT __stdcall WriteCoderProperties(_di_ISequentialOutStream outStreams) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400240000}") ICompressGetInStreamProcessedSize  : public System::IInterface
{
	virtual HRESULT __stdcall GetInStreamProcessedSize(System::PUInt64 value) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400250000}") ICompressSetCoderMt  : public System::IInterface
{
	virtual HRESULT __stdcall SetNumberOfThreads(System::UInt32 numThreads) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400260000}") ICompressSetFinishMode  : public System::IInterface
{
	virtual HRESULT __stdcall SetFinishMode(System::UInt32 finishMode) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400270000}") ICompressGetInStreamProcessedSize2  : public System::IInterface
{
	virtual HRESULT __stdcall GetInStreamProcessedSize2(System::UInt32 streamIndex, System::PUInt64 value) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400280000}") ICompressSetMemLimit  : public System::IInterface
{
	virtual HRESULT __stdcall SetMemLimit(unsigned __int64 memUsage) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400290000}") ICompressReadUnusedFromInBuf  : public System::IInterface
{
	virtual HRESULT __stdcall ReadUnusedFromInBuf(void * data, System::UInt32 size, System::PUint32 processedSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400300000}") ICompressGetSubStreamSize  : public System::IInterface
{
	virtual HRESULT __stdcall GetSubStreamSize(unsigned __int64 subStream, System::PUInt64 value) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400310000}") ICompressSetInStream  : public System::IInterface
{
	virtual HRESULT __stdcall SetInStream(_di_ISequentialInStream inStream) = 0 ;
	virtual HRESULT __stdcall ReleaseInStream() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400320000}") ICompressSetOutStream  : public System::IInterface
{
	virtual HRESULT __stdcall SetOutStream(_di_ISequentialOutStream outStream) = 0 ;
	virtual HRESULT __stdcall ReleaseOutStream() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400330000}") ICompressSetInStreamSize  : public System::IInterface
{
	virtual HRESULT __stdcall SetInStreamSize(System::PUInt64 inSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400340000}") ICompressSetOutStreamSize  : public System::IInterface
{
	virtual HRESULT __stdcall SetOutStreamSize(System::PUInt64 outSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400350000}") ICompressSetBufSize  : public System::IInterface
{
	virtual HRESULT __stdcall SetInBufSize(System::UInt32 streamIndex, System::UInt32 size) = 0 ;
	virtual HRESULT __stdcall SetOutBufSize(System::UInt32 streamIndex, System::UInt32 size) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400360000}") ICompressInitEncoder  : public System::IInterface
{
	virtual HRESULT __stdcall InitEncoder() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400370000}") ICompressSetInStream2  : public System::IInterface
{
	virtual HRESULT __stdcall SetInStream2(System::UInt32 streamIndex, _di_ISequentialInStream inStream) = 0 ;
	virtual HRESULT __stdcall ReleaseInStream2(System::UInt32 streamIndex) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400380000}") ICompressSetOutStream2  : public System::IInterface
{
	virtual HRESULT __stdcall SetOutStream2(System::UInt32 streamIndex, _di_ISequentialOutStream outStream) = 0 ;
	virtual HRESULT __stdcall ReleaseOutStream2(System::UInt32 streamIndex) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400390000}") ICompressSetInStreamSize2  : public System::IInterface
{
	virtual HRESULT __stdcall SetInStreamSize2(System::UInt32 streamIndex, System::PUInt64 inSize) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-0004003A0000}") ICompressInSubStreams  : public System::IInterface
{
	virtual HRESULT __stdcall GetNextInSubStream(System::PUInt64 streamIndexRes, _di_ISequentialInStream &stream) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-0004003B0000}") ICompressOutSubStreams  : public System::IInterface
{
	virtual HRESULT __stdcall GetNextOutSubStream(System::PUInt64 streamIndexRes, _di_ISequentialOutStream &stream) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400400000}") ICompressFilter  : public System::IInterface
{
	virtual HRESULT __stdcall Init() = 0 ;
	virtual System::UInt32 __stdcall Filter(Winapi::Windows::PByte data, System::UInt32 size) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400600000}") ICompressCodecsInfo  : public System::IInterface
{
	virtual HRESULT __stdcall GetNumMethods(System::PUint32 numMethods) = 0 ;
	virtual HRESULT __stdcall GetProperty(System::UInt32 index, unsigned propID, tagPROPVARIANT &value) = 0 ;
	virtual HRESULT __stdcall CreateDecoder(System::UInt32 index, const System::PGUID iid, void * &coder) = 0 ;
	virtual HRESULT __stdcall CreateEncoder(System::UInt32 index, const System::PGUID iid, void * &coder) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400610000}") ISetCompressCodecsInfo  : public System::IInterface
{
	virtual HRESULT __stdcall SetCompressCodecsInfo(_di_ICompressCodecsInfo compressCodecsInfo) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400800000}") ICryptoProperties  : public System::IInterface
{
	virtual HRESULT __stdcall SetKey(Winapi::Windows::PByte Data, System::UInt32 size) = 0 ;
	virtual HRESULT __stdcall SetInitVector(Winapi::Windows::PByte data, System::UInt32 size) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400880000}") ICryptoResetSalt  : public System::IInterface
{
	virtual HRESULT __stdcall ResetSalt() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-0004008C0000}") ICryptoResetInitVector  : public System::IInterface
{
	virtual HRESULT __stdcall ResetInitVector() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400900000}") ICryptoSetPassword  : public System::IInterface
{
	virtual HRESULT __stdcall CryptoSetPassword(Winapi::Windows::PByte data, System::UInt32 size) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400A00000}") ICryptoSetCRC  : public System::IInterface
{
	virtual HRESULT __stdcall CryptoSetCRC(System::UInt32 crc) = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400C00000}") IHasher  : public System::IInterface
{
	virtual void __stdcall Init() = 0 ;
	virtual void __stdcall Update(const void * data, System::UInt32 size) = 0 ;
	virtual void __stdcall Final(Winapi::Windows::PByte digest) = 0 ;
	virtual System::UInt32 __stdcall GetDigestSize() = 0 ;
};

__interface  INTERFACE_UUID("{23170F69-40C1-278A-0000-000400C10000}") IHashers  : public System::IInterface
{
	virtual System::UInt32 __fastcall GetNumHashers() = 0 ;
	virtual HRESULT __stdcall GetHasherProp(System::UInt32 index, unsigned propID, tagPROPVARIANT &value) = 0 ;
	virtual HRESULT __stdcall CreateHasher(System::UInt32 index, _di_IHasher &hasher) = 0 ;
};

typedef HRESULT __stdcall (*T7zPasswordCallback)(void * sender, System::UnicodeString &password);

typedef HRESULT __stdcall (*T7zGetStreamCallBack)(void * sender, System::UInt32 index, _di_ISequentialOutStream &outStream);

typedef HRESULT __stdcall (*T7zProgressCallback)(void * sender, bool total, __int64 value);

__interface I7zInArchive  : public System::IInterface
{
	virtual void __stdcall OpenFile(const System::UnicodeString filename) = 0 ;
	virtual void __stdcall OpenStream(_di_IInStream stream) = 0 ;
	virtual void __stdcall Close() = 0 ;
	virtual System::UInt32 __stdcall GetNumberOfItems() = 0 ;
	virtual System::UnicodeString __stdcall GetItemPath(const int index) = 0 ;
	virtual System::UnicodeString __stdcall GetItemName(const int index) = 0 ;
	virtual __int64 __stdcall GetItemSize(const int index) = 0 ;
	virtual __int64 __stdcall GetItemCompressedSize(const int index) = 0 ;
	virtual System::TDateTime __stdcall GetItemWriteTime(const int index) = 0 ;
	virtual unsigned __stdcall GetItemAttributes(const int index) = 0 ;
	virtual bool __stdcall GetItemIsFolder(const int index) = 0 ;
	virtual _di_IInArchive __fastcall GetInArchive() = 0 ;
	virtual void __stdcall ExtractItem(const System::UInt32 item, System::Classes::TStream* Stream, System::LongBool test) = 0 ;
	virtual void __stdcall ExtractItems(PCardArray items, System::UInt32 count, System::LongBool test, void * sender, T7zGetStreamCallBack callback) = 0 ;
	virtual void __stdcall ExtractAll(System::LongBool test, void * sender, T7zGetStreamCallBack callback) = 0 ;
	virtual void __stdcall ExtractTo(const System::UnicodeString path) = 0 ;
	virtual void __stdcall SetPasswordCallback(void * sender, T7zPasswordCallback callback) = 0 ;
	virtual void __stdcall SetPassword(const System::UnicodeString password) = 0 ;
	virtual void __stdcall SetProgressCallback(void * sender, T7zProgressCallback callback) = 0 ;
	virtual void __fastcall SetClassId(const GUID &classid) = 0 ;
	virtual GUID __fastcall GetClassId() = 0 ;
	__property GUID ClassId = {read=GetClassId, write=SetClassId};
	__property System::UInt32 NumberOfItems = {read=GetNumberOfItems};
	__property System::UnicodeString ItemPath[const int index] = {read=GetItemPath};
	__property System::UnicodeString ItemName[const int index] = {read=GetItemName};
	__property __int64 ItemSize[const int index] = {read=GetItemSize};
	__property __int64 ItemCompressedSize[const int index] = {read=GetItemCompressedSize};
	__property bool ItemIsFolder[const int index] = {read=GetItemIsFolder};
	__property _di_IInArchive InArchive = {read=GetInArchive};
};

__interface I7zOutArchive  : public System::IInterface
{
	virtual void __stdcall AddStream(System::Classes::TStream* Stream, System::Classes::TStreamOwnership Ownership, unsigned Attributes, Winapi::Windows::TFileTime CreationTime, Winapi::Windows::TFileTime LastWriteTime, const System::UnicodeString Path, bool IsFolder, bool IsAnti) = 0 ;
	virtual void __stdcall AddFile(const System::Sysutils::TFileName Filename, const System::UnicodeString Path) = 0 ;
	virtual void __stdcall AddFiles(const System::UnicodeString Dir, const System::UnicodeString Path, const System::UnicodeString Wildcard, bool recurse) = 0 ;
	virtual void __stdcall SaveToFile(const System::Sysutils::TFileName FileName) = 0 ;
	virtual void __stdcall SaveToStream(System::Classes::TStream* stream) = 0 ;
	virtual void __stdcall SetProgressCallback(void * sender, T7zProgressCallback callback) = 0 ;
	virtual void __stdcall ClearBatch() = 0 ;
	virtual void __stdcall SetPassword(const System::UnicodeString password) = 0 ;
	virtual void __stdcall SetPropertie(System::UnicodeString name, System::OleVariant value) = 0 ;
	virtual void __fastcall SetClassId(const GUID &classid) = 0 ;
	virtual GUID __fastcall GetClassId() = 0 ;
	__property GUID ClassId = {read=GetClassId, write=SetClassId};
};

__interface I7zCodec  : public System::IInterface
{

};

class PASCALIMPLEMENTATION T7zStream : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;

private:
	System::Classes::TStream* FStream;
	System::Classes::TStreamOwnership FOwnership;
	System::UnicodeString FFileName;
	System::TDateTime FWriteTime;

protected:
	HRESULT __stdcall Read(void * data, System::UInt32 size, System::PUint32 processedSize);
	HRESULT __stdcall Seek(__int64 offset, System::UInt32 seekOrigin, System::PUInt64 newPosition);
	HRESULT __stdcall GetSize(System::PUInt64 size);
	HRESULT __stdcall SetSize(unsigned __int64 newSize);
	HRESULT __stdcall Write(void * data, System::UInt32 size, System::PUint32 processedSize);
	HRESULT __stdcall OutStreamFinish();

public:
	__fastcall T7zStream(System::Classes::TStream* Stream, System::Classes::TStreamOwnership Ownership, System::UnicodeString filename, System::TDateTime writeTime);
	__fastcall virtual ~T7zStream();
private:
	void *__IOutStreamFinish;	// IOutStreamFinish
	void *__IOutStream;	// IOutStream
	void *__IStreamGetSize;	// IStreamGetSize
	void *__IInStream;	// IInStream

public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {23170F69-40C1-278A-0000-000300070000}
	operator _di_IOutStreamFinish()
	{
		_di_IOutStreamFinish intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IOutStreamFinish*(void) { return (IOutStreamFinish*)&__IOutStreamFinish; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {23170F69-40C1-278A-0000-000300040000}
	operator _di_IOutStream()
	{
		_di_IOutStream intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IOutStream*(void) { return (IOutStream*)&__IOutStream; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {23170F69-40C1-278A-0000-000300010000}
	operator _di_ISequentialInStream()
	{
		_di_ISequentialInStream intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator ISequentialInStream*(void) { return (ISequentialInStream*)&__IInStream; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {23170F69-40C1-278A-0000-000300020000}
	operator _di_ISequentialOutStream()
	{
		_di_ISequentialOutStream intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator ISequentialOutStream*(void) { return (ISequentialOutStream*)&__IOutStream; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {23170F69-40C1-278A-0000-000300060000}
	operator _di_IStreamGetSize()
	{
		_di_IStreamGetSize intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IStreamGetSize*(void) { return (IStreamGetSize*)&__IStreamGetSize; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {23170F69-40C1-278A-0000-000300030000}
	operator _di_IInStream()
	{
		_di_IInStream intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IInStream*(void) { return (IInStream*)&__IInStream; }
	#endif

};


enum DECLSPEC_DENUM TZipCompressionMethod : unsigned int { mzCopy, mzDeflate, mzDeflate64, mzBZip2, mzLZMA, mzPPMD };

enum DECLSPEC_DENUM TZipEncryptionMethod : unsigned int { emAES128, emAES192, emAES256, emZIPCRYPTO };

enum DECLSPEC_DENUM T7zCompressionMethod : unsigned int { m7Copy, m7LZMA, m7BZip2, m7PPMd, m7Deflate, m7Deflate64, m7LZMA2 };

__interface  INTERFACE_UUID("{D178E493-F317-4F41-AD5C-6A7894329D8F}") IArchiveFactory  : public System::IInterface
{
	virtual _di_I7zInArchive __fastcall CreateInArchive(const System::UnicodeString AFileType, const System::UnicodeString lib = L"7z.dll") = 0 ;
	virtual _di_I7zOutArchive __fastcall CreateOutArchive(const System::UnicodeString AFileType, const System::UnicodeString lib = L"7z.dll") = 0 ;
};

class PASCALIMPLEMENTATION TArchiveFactory : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;

private:
	System::UnicodeString __fastcall GetFileTypeFromExtension(const System::UnicodeString AFileName);

public:
	_di_I7zInArchive __fastcall CreateInArchive(const System::UnicodeString AFileType, const System::UnicodeString lib = L"7z.dll");
	_di_I7zOutArchive __fastcall CreateOutArchive(const System::UnicodeString AFileType, const System::UnicodeString lib = L"7z.dll");
public:
	/* TObject.Create */ inline __fastcall TArchiveFactory() : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TArchiveFactory() { }

private:
	void *__IArchiveFactory;	// IArchiveFactory

public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D178E493-F317-4F41-AD5C-6A7894329D8F}
	operator _di_IArchiveFactory()
	{
		_di_IArchiveFactory intf;
		this->GetInterface(intf);
		return intf;
	}
	#else
	operator IArchiveFactory*(void) { return (IArchiveFactory*)&__IArchiveFactory; }
	#endif

};


//-- var, const, procedure ---------------------------------------------------
static _DELPHI_CONST System::Int8 kpidNoProperty = System::Int8(0x0);
static _DELPHI_CONST System::Int8 kpidMainSubfile = System::Int8(0x1);
static _DELPHI_CONST System::Int8 kpidHandlerItemIndex = System::Int8(0x2);
static _DELPHI_CONST System::Int8 kpidPath = System::Int8(0x3);
static _DELPHI_CONST System::Int8 kpidName = System::Int8(0x4);
static _DELPHI_CONST System::Int8 kpidExtension = System::Int8(0x5);
static _DELPHI_CONST System::Int8 kpidIsDir = System::Int8(0x6);
static _DELPHI_CONST System::Int8 kpidSize = System::Int8(0x7);
static _DELPHI_CONST System::Int8 kpidPackSize = System::Int8(0x8);
static _DELPHI_CONST System::Int8 kpidAttributes = System::Int8(0x9);
static _DELPHI_CONST System::Int8 kpidCreationTime = System::Int8(0xa);
static _DELPHI_CONST System::Int8 kpidLastAccessTime = System::Int8(0xb);
static _DELPHI_CONST System::Int8 kpidLastWriteTime = System::Int8(0xc);
static _DELPHI_CONST System::Int8 kpidSolid = System::Int8(0xd);
static _DELPHI_CONST System::Int8 kpidCommented = System::Int8(0xe);
static _DELPHI_CONST System::Int8 kpidEncrypted = System::Int8(0xf);
static _DELPHI_CONST System::Int8 kpidSplitBefore = System::Int8(0x10);
static _DELPHI_CONST System::Int8 kpidSplitAfter = System::Int8(0x11);
static _DELPHI_CONST System::Int8 kpidDictionarySize = System::Int8(0x12);
static _DELPHI_CONST System::Int8 kpidCRC = System::Int8(0x13);
static _DELPHI_CONST System::Int8 kpidType = System::Int8(0x14);
static _DELPHI_CONST System::Int8 kpidIsAnti = System::Int8(0x15);
static _DELPHI_CONST System::Int8 kpidMethod = System::Int8(0x16);
static _DELPHI_CONST System::Int8 kpidHostOS = System::Int8(0x17);
static _DELPHI_CONST System::Int8 kpidFileSystem = System::Int8(0x18);
static _DELPHI_CONST System::Int8 kpidUser = System::Int8(0x19);
static _DELPHI_CONST System::Int8 kpidGroup = System::Int8(0x1a);
static _DELPHI_CONST System::Int8 kpidBlock = System::Int8(0x1b);
static _DELPHI_CONST System::Int8 kpidComment = System::Int8(0x1c);
static _DELPHI_CONST System::Int8 kpidPosition = System::Int8(0x1d);
static _DELPHI_CONST System::Int8 kpidPrefix = System::Int8(0x1e);
static _DELPHI_CONST System::Int8 kpidNumSubDirs = System::Int8(0x1f);
static _DELPHI_CONST System::Int8 kpidNumSubFiles = System::Int8(0x20);
static _DELPHI_CONST System::Int8 kpidUnpackVer = System::Int8(0x21);
static _DELPHI_CONST System::Int8 kpidVolume = System::Int8(0x22);
static _DELPHI_CONST System::Int8 kpidIsVolume = System::Int8(0x23);
static _DELPHI_CONST System::Int8 kpidOffset = System::Int8(0x24);
static _DELPHI_CONST System::Int8 kpidLinks = System::Int8(0x25);
static _DELPHI_CONST System::Int8 kpidNumBlocks = System::Int8(0x26);
static _DELPHI_CONST System::Int8 kpidNumVolumes = System::Int8(0x27);
static _DELPHI_CONST System::Int8 kpidTimeType = System::Int8(0x28);
static _DELPHI_CONST System::Int8 kpidBit64 = System::Int8(0x29);
static _DELPHI_CONST System::Int8 kpidBigEndian = System::Int8(0x2a);
static _DELPHI_CONST System::Int8 kpidCpu = System::Int8(0x2b);
static _DELPHI_CONST System::Int8 kpidPhySize = System::Int8(0x2c);
static _DELPHI_CONST System::Int8 kpidHeadersSize = System::Int8(0x2d);
static _DELPHI_CONST System::Int8 kpidChecksum = System::Int8(0x2e);
static _DELPHI_CONST System::Int8 kpidCharacts = System::Int8(0x2f);
static _DELPHI_CONST System::Int8 kpidVa = System::Int8(0x30);
static _DELPHI_CONST System::Int8 kpidId = System::Int8(0x31);
static _DELPHI_CONST System::Int8 kpidShortName = System::Int8(0x32);
static _DELPHI_CONST System::Int8 kpidCreatorApp = System::Int8(0x33);
static _DELPHI_CONST System::Int8 kpidSectorSize = System::Int8(0x34);
static _DELPHI_CONST System::Int8 kpidPosixAttrib = System::Int8(0x35);
static _DELPHI_CONST System::Int8 kpidSymLink = System::Int8(0x36);
static _DELPHI_CONST System::Int8 kpidError = System::Int8(0x37);
static _DELPHI_CONST System::Int8 kpidTotalSize = System::Int8(0x38);
static _DELPHI_CONST System::Int8 kpidFreeSpace = System::Int8(0x39);
static _DELPHI_CONST System::Int8 kpidClusterSize = System::Int8(0x3a);
static _DELPHI_CONST System::Int8 kpidVolumeName = System::Int8(0x3b);
static _DELPHI_CONST System::Int8 kpidLocalName = System::Int8(0x3c);
static _DELPHI_CONST System::Int8 kpidProvider = System::Int8(0x3d);
static _DELPHI_CONST System::Int8 kpidNtSecure = System::Int8(0x3e);
static _DELPHI_CONST System::Int8 kpidIsAltStream = System::Int8(0x3f);
static _DELPHI_CONST System::Int8 kpidIsAux = System::Int8(0x40);
static _DELPHI_CONST System::Int8 kpidIsDeleted = System::Int8(0x41);
static _DELPHI_CONST System::Int8 kpidIsTree = System::Int8(0x42);
static _DELPHI_CONST System::Int8 kpidSha1 = System::Int8(0x43);
static _DELPHI_CONST System::Int8 kpidSha256 = System::Int8(0x44);
static _DELPHI_CONST System::Int8 kpidErrorType = System::Int8(0x45);
static _DELPHI_CONST System::Int8 kpidNumErrors = System::Int8(0x46);
static _DELPHI_CONST System::Int8 kpidErrorFlags = System::Int8(0x47);
static _DELPHI_CONST System::Int8 kpidWarningFlags = System::Int8(0x48);
static _DELPHI_CONST System::Int8 kpidWarning = System::Int8(0x49);
static _DELPHI_CONST System::Int8 kpidNumStreams = System::Int8(0x4a);
static _DELPHI_CONST System::Int8 kpidNumAltStreams = System::Int8(0x4b);
static _DELPHI_CONST System::Int8 kpidAltStreamsSize = System::Int8(0x4c);
static _DELPHI_CONST System::Int8 kpidVirtualSize = System::Int8(0x4d);
static _DELPHI_CONST System::Int8 kpidUnpackSize = System::Int8(0x4e);
static _DELPHI_CONST System::Int8 kpidTotalPhySize = System::Int8(0x4f);
static _DELPHI_CONST System::Int8 kpidVolumeIndex = System::Int8(0x50);
static _DELPHI_CONST System::Int8 kpidSubType = System::Int8(0x51);
static _DELPHI_CONST System::Int8 kpidShortComment = System::Int8(0x52);
static _DELPHI_CONST System::Int8 kpidCodePage = System::Int8(0x53);
static _DELPHI_CONST System::Int8 kpidIsNotArcType = System::Int8(0x54);
static _DELPHI_CONST System::Int8 kpidPhySizeCantBeDetected = System::Int8(0x55);
static _DELPHI_CONST System::Int8 kpidZerosTailIsAllowed = System::Int8(0x56);
static _DELPHI_CONST System::Int8 kpidTailSize = System::Int8(0x57);
static _DELPHI_CONST System::Int8 kpidEmbeddedStubSize = System::Int8(0x58);
static _DELPHI_CONST System::Int8 kpidNtReparse = System::Int8(0x59);
static _DELPHI_CONST System::Int8 kpidHardLink = System::Int8(0x5a);
static _DELPHI_CONST System::Int8 kpidINode = System::Int8(0x5b);
static _DELPHI_CONST System::Int8 kpidStreamId = System::Int8(0x5c);
static _DELPHI_CONST System::Int8 kpidReadOnly = System::Int8(0x5d);
static _DELPHI_CONST System::Int8 kpidOutName = System::Int8(0x5e);
static _DELPHI_CONST System::Int8 kpidCopyLink = System::Int8(0x5f);
static _DELPHI_CONST System::Int8 kpidArcFileName = System::Int8(0x60);
static _DELPHI_CONST System::Int8 kpidIsHash = System::Int8(0x61);
static _DELPHI_CONST System::Int8 kpidChangeTime = System::Int8(0x62);
static _DELPHI_CONST System::Int8 kpidUserId = System::Int8(0x63);
static _DELPHI_CONST System::Int8 kpidGroupId = System::Int8(0x64);
static _DELPHI_CONST System::Int8 kpidDeviceMajor = System::Int8(0x65);
static _DELPHI_CONST System::Int8 kpidDeviceMinor = System::Int8(0x66);
static _DELPHI_CONST System::Int8 kpidDevMajor = System::Int8(0x67);
static _DELPHI_CONST System::Int8 kpidDevMinor = System::Int8(0x68);
static _DELPHI_CONST int kpidUserDefined = int(0x10000);
extern DELPHI_PACKAGE GUID CLSID_CFormatZip;
extern DELPHI_PACKAGE GUID CLSID_CFormatBZ2;
extern DELPHI_PACKAGE GUID CLSID_CFormatRar;
extern DELPHI_PACKAGE GUID CLSID_CFormatArj;
extern DELPHI_PACKAGE GUID CLSID_CFormatZ;
extern DELPHI_PACKAGE GUID CLSID_CFormatLzh;
extern DELPHI_PACKAGE GUID CLSID_CFormat7z;
extern DELPHI_PACKAGE GUID CLSID_CFormatCab;
extern DELPHI_PACKAGE GUID CLSID_CFormatNsis;
extern DELPHI_PACKAGE GUID CLSID_CFormatLzma;
extern DELPHI_PACKAGE GUID CLSID_CFormatLzma86;
extern DELPHI_PACKAGE GUID CLSID_CFormatXz;
extern DELPHI_PACKAGE GUID CLSID_CFormatPpmd;
extern DELPHI_PACKAGE GUID CLSID_CFormatZStd;
extern DELPHI_PACKAGE GUID CLSID_CFormatLvm;
extern DELPHI_PACKAGE GUID CLSID_CFormatAVB;
extern DELPHI_PACKAGE GUID CLSID_CFormatLP;
extern DELPHI_PACKAGE GUID CLSID_CFormatSparse;
extern DELPHI_PACKAGE GUID CLSID_CFormatAPFS;
extern DELPHI_PACKAGE GUID CLSID_CFormatVhdx;
extern DELPHI_PACKAGE GUID CLSID_CFormatBase64;
extern DELPHI_PACKAGE GUID CLSID_CFormatCOFF;
extern DELPHI_PACKAGE GUID CLSID_CFormatExt;
extern DELPHI_PACKAGE GUID CLSID_CFormatVMDK;
extern DELPHI_PACKAGE GUID CLSID_CFormatVDI;
extern DELPHI_PACKAGE GUID CLSID_CFormatQcow;
extern DELPHI_PACKAGE GUID CLSID_CFormatGPT;
extern DELPHI_PACKAGE GUID CLSID_CFormatRar5;
extern DELPHI_PACKAGE GUID CLSID_CFormatIHex;
extern DELPHI_PACKAGE GUID CLSID_CFormatHxs;
extern DELPHI_PACKAGE GUID CLSID_CFormatTE;
extern DELPHI_PACKAGE GUID CLSID_CFormatUEFIc;
extern DELPHI_PACKAGE GUID CLSID_CFormatUEFIs;
extern DELPHI_PACKAGE GUID CLSID_CFormatSquashFS;
extern DELPHI_PACKAGE GUID CLSID_CFormatCramFS;
extern DELPHI_PACKAGE GUID CLSID_CFormatAPM;
extern DELPHI_PACKAGE GUID CLSID_CFormatMslz;
extern DELPHI_PACKAGE GUID CLSID_CFormatFlv;
extern DELPHI_PACKAGE GUID CLSID_CFormatSwf;
extern DELPHI_PACKAGE GUID CLSID_CFormatSwfc;
extern DELPHI_PACKAGE GUID CLSID_CFormatNtfs;
extern DELPHI_PACKAGE GUID CLSID_CFormatFat;
extern DELPHI_PACKAGE GUID CLSID_CFormatMbr;
extern DELPHI_PACKAGE GUID CLSID_CFormatVhd;
extern DELPHI_PACKAGE GUID CLSID_CFormatPe;
extern DELPHI_PACKAGE GUID CLSID_CFormatElf;
extern DELPHI_PACKAGE GUID CLSID_CFormatMachO;
extern DELPHI_PACKAGE GUID CLSID_CFormatUdf;
extern DELPHI_PACKAGE GUID CLSID_CFormatXar;
extern DELPHI_PACKAGE GUID CLSID_CFormatMub;
extern DELPHI_PACKAGE GUID CLSID_CFormatHfs;
extern DELPHI_PACKAGE GUID CLSID_CFormatDmg;
extern DELPHI_PACKAGE GUID CLSID_CFormatCompound;
extern DELPHI_PACKAGE GUID CLSID_CFormatWim;
extern DELPHI_PACKAGE GUID CLSID_CFormatIso;
extern DELPHI_PACKAGE GUID CLSID_CFormatBkf;
extern DELPHI_PACKAGE GUID CLSID_CFormatChm;
extern DELPHI_PACKAGE GUID CLSID_CFormatSplit;
extern DELPHI_PACKAGE GUID CLSID_CFormatRpm;
extern DELPHI_PACKAGE GUID CLSID_CFormatDeb;
extern DELPHI_PACKAGE GUID CLSID_CFormatCpio;
extern DELPHI_PACKAGE GUID CLSID_CFormatTar;
extern DELPHI_PACKAGE GUID CLSID_CFormatGZip;
extern DELPHI_PACKAGE Winapi::Windows::TFileTime __fastcall DateTimeToFileTime(System::TDateTime dt);
extern DELPHI_PACKAGE System::TDateTime __fastcall FileTimeToDateTime(const Winapi::Windows::TFileTime &ft);
extern DELPHI_PACKAGE Winapi::Windows::TFileTime __fastcall CurrentFileTime();
extern DELPHI_PACKAGE void __fastcall SetCompressionLevel(_di_I7zOutArchive Arch, unsigned level);
extern DELPHI_PACKAGE void __fastcall SetMultiThreading(_di_I7zOutArchive Arch, unsigned ThreadCount);
extern DELPHI_PACKAGE void __fastcall SetCompressionMethod(_di_I7zOutArchive Arch, TZipCompressionMethod method);
extern DELPHI_PACKAGE void __fastcall SetEncryptionMethod(_di_I7zOutArchive Arch, TZipEncryptionMethod method);
extern DELPHI_PACKAGE void __fastcall SetDictionnarySize(_di_I7zOutArchive Arch, unsigned size);
extern DELPHI_PACKAGE void __fastcall SetMemorySize(_di_I7zOutArchive Arch, unsigned size);
extern DELPHI_PACKAGE void __fastcall SetDeflateNumPasses(_di_I7zOutArchive Arch, unsigned pass);
extern DELPHI_PACKAGE void __fastcall SetNumFastBytes(_di_I7zOutArchive Arch, unsigned fb);
extern DELPHI_PACKAGE void __fastcall SetNumMatchFinderCycles(_di_I7zOutArchive Arch, unsigned mc);
extern DELPHI_PACKAGE void __fastcall SevenZipSetCompressionMethod(_di_I7zOutArchive Arch, T7zCompressionMethod method);
extern DELPHI_PACKAGE void __fastcall SevenZipSetBindInfo(_di_I7zOutArchive Arch, const System::UnicodeString bind);
extern DELPHI_PACKAGE void __fastcall SevenZipSetSolidSettings(_di_I7zOutArchive Arch, bool solid);
extern DELPHI_PACKAGE void __fastcall SevenZipRemoveSfxBlock(_di_I7zOutArchive Arch, bool remove);
extern DELPHI_PACKAGE void __fastcall SevenZipAutoFilter(_di_I7zOutArchive Arch, bool Auto);
extern DELPHI_PACKAGE void __fastcall SevenZipCompressHeaders(_di_I7zOutArchive Arch, bool compress);
extern DELPHI_PACKAGE void __fastcall SevenZipCompressHeadersFull(_di_I7zOutArchive Arch, bool compress);
extern DELPHI_PACKAGE void __fastcall SevenZipEncryptHeaders(_di_I7zOutArchive Arch, bool Encrypt);
extern DELPHI_PACKAGE void __fastcall SevenZipVolumeMode(_di_I7zOutArchive Arch, bool Mode);
extern DELPHI_PACKAGE _di_I7zInArchive __fastcall CreateInArchive(const GUID &classid, const System::UnicodeString lib = L"7z.dll");
extern DELPHI_PACKAGE _di_I7zOutArchive __fastcall CreateOutArchive(const GUID &classid, const System::UnicodeString lib = L"7z.dll");
}	/* namespace Sevenzip */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SEVENZIP)
using namespace Sevenzip;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// sevenzipHPP
