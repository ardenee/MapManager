unit MMArchiveEngine;

interface

uses
  System.SysUtils, System.Classes, System.Variants, System.IOUtils,
  Winapi.Windows, sevenzip;

type
  // No external executable: each instance uses 7z.dll in the application directory.
  TMMArchiveEngine = class
  private
    FArchive: I7zInArchive;
    FName: string;
    function GetCount: Integer;
    function GetItemPath(Index: Integer): string;
    function GetItemSize(Index: Integer): Int64;
    function GetItemPackedSize(Index: Integer): Int64;
    function GetItemIsFolder(Index: Integer): Boolean;
    function GetItemDate(Index: Integer): TDateTime;
    function GetItemCRC(Index: Integer): Cardinal;
    function GetItemEncrypted(Index: Integer): Boolean;
    procedure CheckIndex(Index: Integer);
  public
    constructor Create;
    destructor Destroy; override;
    procedure Open(const FileName: string);
    procedure Close;
    // Extracts ONE selected entry, to a caller-controlled destination. Uses a
    // temporary file, so failures never leave a truncated installed file.
    procedure ExtractItemToFile(Index: Integer; const Destination: string);
    class function SafeRelativePath(const MemberPath: string): string; static;
    property Count: Integer read GetCount;
    property ItemPath[Index: Integer]: string read GetItemPath;
    property ItemSize[Index: Integer]: Int64 read GetItemSize;
    property ItemPackedSize[Index: Integer]: Int64 read GetItemPackedSize;
    property ItemIsFolder[Index: Integer]: Boolean read GetItemIsFolder;
    property ItemDate[Index: Integer]: TDateTime read GetItemDate;
    property ItemCRC[Index: Integer]: Cardinal read GetItemCRC;
    property ItemEncrypted[Index: Integer]: Boolean read GetItemEncrypted;
  end;

implementation

function ArchiveFormat(const FileName: string): TGUID;
var
  Stream: TFileStream;
  Sig: array[0..7] of Byte;
  ReadCount: Integer;
  Ext: string;
begin
  Stream := TFileStream.Create(FileName, fmOpenRead or fmShareDenyNone);
  try
    FillChar(Sig, SizeOf(Sig), 0);
    ReadCount := Stream.Read(Sig, SizeOf(Sig));
  finally
    Stream.Free;
  end;
  if (ReadCount >= 8) and (Sig[0] = $52) and (Sig[1] = $61) and
     (Sig[2] = $72) and (Sig[3] = $21) and (Sig[4] = $1A) and
     (Sig[5] = $07) and (Sig[6] = $01) and (Sig[7] = $00) then
    Exit(CLSID_CFormatRar5);
  if (ReadCount >= 7) and (Sig[0] = $52) and (Sig[1] = $61) and
     (Sig[2] = $72) and (Sig[3] = $21) and (Sig[4] = $1A) and
     (Sig[5] = $07) and (Sig[6] = $00) then
    Exit(CLSID_CFormatRar);
  if (ReadCount >= 6) and (Sig[0] = $37) and (Sig[1] = $7A) and
     (Sig[2] = $BC) and (Sig[3] = $AF) and (Sig[4] = $27) and (Sig[5] = $1C) then
    Exit(CLSID_CFormat7z);
  if (ReadCount >= 4) and (Sig[0] = $50) and (Sig[1] = $4B) and
     (Sig[2] in [$03,$05,$07]) and (Sig[3] in [$04,$06,$08]) then
    Exit(CLSID_CFormatZip);

  // Embedded ZIP SFX headers are not necessarily at byte 0.
  Ext := LowerCase(ExtractFileExt(FileName));
  if Ext = '.7z' then Exit(CLSID_CFormat7z);
  if Ext = '.rar' then Exit(CLSID_CFormatRar);
  if (Ext = '.zip') or (Ext = '.jar') or (Ext = '.pk3') or
     (Ext = '.exe') then Exit(CLSID_CFormatZip);
  raise EInvalidOperation.CreateFmt('Unsupported archive format: %s', [FileName]);
end;

function GetArchiveProperty(const A: I7zInArchive; const Index: Integer;
  const PropID: Cardinal): Variant;
var
  Value: OleVariant;
begin
  VarClear(Value);
  if A.InArchive.GetProperty(Cardinal(Index), PropID, Value) <> S_OK then
    Exit(Null);
  Result := Value;
end;

constructor TMMArchiveEngine.Create;
begin
  inherited;
end;

destructor TMMArchiveEngine.Destroy;
begin
  Close;
  inherited;
end;

procedure TMMArchiveEngine.Open(const FileName: string);
var
  Dll: string;
begin
  Close;
  if not FileExists(FileName) then
    raise EFOpenError.CreateFmt('Archive not found: %s', [FileName]);
  Dll := TPath.Combine(ExtractFilePath(ParamStr(0)), '7z.dll');
  if not FileExists(Dll) then
    raise EFOpenError.CreateFmt('Missing in-process 7-Zip runtime: %s', [Dll]);
  FArchive := CreateInArchive(ArchiveFormat(FileName), Dll);
  try
    FArchive.OpenFile(FileName);
    FName := FileName;
  except
    FArchive := nil;
    raise;
  end;
end;

procedure TMMArchiveEngine.Close;
begin
  if FArchive <> nil then
  begin
    FArchive.Close;
    FArchive := nil;
  end;
  FName := '';
end;

procedure TMMArchiveEngine.CheckIndex(Index: Integer);
begin
  if FArchive = nil then
    raise EInvalidOperation.Create('No archive open');
  if (Index < 0) or (Cardinal(Index) >= FArchive.NumberOfItems) then
    raise ERangeError.CreateFmt('Archive item out of range: %d', [Index]);
end;

function TMMArchiveEngine.GetCount: Integer;
begin
  if FArchive = nil then Exit(0);
  if FArchive.NumberOfItems > UInt32(High(Integer)) then
    raise ERangeError.Create('Archive has too many entries');
  Result := Integer(FArchive.NumberOfItems);
end;

function TMMArchiveEngine.GetItemPath(Index: Integer): string;
begin
  CheckIndex(Index);
  Result := FArchive.ItemPath[Index];
end;

function TMMArchiveEngine.GetItemSize(Index: Integer): Int64;
begin
  CheckIndex(Index);
  Result := FArchive.ItemSize[Index];
end;

function TMMArchiveEngine.GetItemPackedSize(Index: Integer): Int64;
begin
  CheckIndex(Index);
  Result := FArchive.ItemCompressedSize[Index];
end;

function TMMArchiveEngine.GetItemIsFolder(Index: Integer): Boolean;
begin
  CheckIndex(Index);
  Result := FArchive.ItemIsFolder[Index];
end;

function TMMArchiveEngine.GetItemDate(Index: Integer): TDateTime;
begin
  CheckIndex(Index);
  Result := FArchive.GetItemWriteTime(Index);
end;

function TMMArchiveEngine.GetItemCRC(Index: Integer): Cardinal;
var
  V: Variant;
begin
  CheckIndex(Index);
  V := GetArchiveProperty(FArchive, Index, kpidCRC);
  if VarIsNull(V) or VarIsEmpty(V) then Exit(0);
  Result := Cardinal(StrToUInt64(VarToStr(V)));
end;

function TMMArchiveEngine.GetItemEncrypted(Index: Integer): Boolean;
var
  V: Variant;
begin
  CheckIndex(Index);
  V := GetArchiveProperty(FArchive, Index, kpidEncrypted);
  if VarIsNull(V) or VarIsEmpty(V) then Exit(False);
  Result := Boolean(V);
end;

class function TMMArchiveEngine.SafeRelativePath(const MemberPath: string): string;
var
  Parts: TArray<string>;
  Part, Base: string;
  I: Integer;
begin
  Result := StringReplace(MemberPath, '/', '\', [rfReplaceAll]);
  if (Result = '') or (Result[1] = '\') or (Pos(':', Result) <> 0) then
    raise EArgumentException.CreateFmt('Unsafe archive path: %s', [MemberPath]);
  if Pos(#0, Result) <> 0 then
    raise EArgumentException.Create('NUL byte in archive path');
  Parts := Result.Split(['\']);
  for Part in Parts do
  begin
    if (Part = '') or (Part = '.') or (Part = '..') or
       Part.EndsWith(' ') or Part.EndsWith('.') then
      raise EArgumentException.CreateFmt('Unsafe archive path: %s', [MemberPath]);
    Base := UpperCase(Part.Split(['.'])[0]);
    if (Base = 'CON') or (Base = 'PRN') or (Base = 'AUX') or
       (Base = 'NUL') or (Base = 'CONIN$') or (Base = 'CONOUT$') then
      raise EArgumentException.CreateFmt('Reserved filename in archive: %s', [MemberPath]);
    for I := 1 to 9 do
      if (Base = 'COM' + IntToStr(I)) or (Base = 'LPT' + IntToStr(I)) then
        raise EArgumentException.CreateFmt('Reserved filename in archive: %s', [MemberPath]);
  end;
end;

procedure EnsureSafeParent(const FullName: string);
var
  Parent, Cursor, Above: string;
  Attr: DWORD;

  procedure RejectReparse(const Name: string);
  begin
    Attr := GetFileAttributes(PChar(Name));
    if (Attr <> INVALID_FILE_ATTRIBUTES) and
       ((Attr and FILE_ATTRIBUTE_REPARSE_POINT) <> 0) then
      raise EArgumentException.CreateFmt('Reparse point in extraction path: %s', [Name]);
  end;

begin
  Parent := ExcludeTrailingPathDelimiter(ExtractFilePath(ExpandFileName(FullName)));
  if Parent = '' then
    raise EArgumentException.Create('Extraction requires a full destination path');

  // Check all existing ancestors BEFORE creating directories. This also
  // handles UNC shares correctly, rather than rebuilding a path from segments.
  Cursor := Parent;
  while Cursor <> '' do
  begin
    RejectReparse(Cursor);
    Above := ExcludeTrailingPathDelimiter(ExtractFileDir(Cursor));
    if (Above = '') or SameText(Above, Cursor) then Break;
    Cursor := Above;
  end;
  if not ForceDirectories(Parent) then
    raise EFCreateError.CreateFmt('Cannot create extraction directory: %s', [Parent]);
  Cursor := Parent;
  while Cursor <> '' do
  begin
    RejectReparse(Cursor);
    Above := ExcludeTrailingPathDelimiter(ExtractFileDir(Cursor));
    if (Above = '') or SameText(Above, Cursor) then Break;
    Cursor := Above;
  end;
end;

procedure TMMArchiveEngine.ExtractItemToFile(Index: Integer; const Destination: string);
var
  Tmp: string;
  Stream: TFileStream;
  Attr: DWORD;
begin
  CheckIndex(Index);
  if ItemIsFolder[Index] then Exit;
  if ItemEncrypted[Index] then
    raise EInvalidOperation.Create('Encrypted archive item requires a password');
  EnsureSafeParent(Destination);
  Attr := GetFileAttributes(PChar(Destination));
  if (Attr <> INVALID_FILE_ATTRIBUTES) and
     ((Attr and FILE_ATTRIBUTE_REPARSE_POINT) <> 0) then
    raise EArgumentException.CreateFmt('Refusing reparse point: %s', [Destination]);
  Tmp := Destination + '.mm-extract-tmp';
  if FileExists(Tmp) then
    raise EInvalidOperation.CreateFmt('Temporary extraction file exists: %s', [Tmp]);
  Stream := TFileStream.Create(Tmp, fmCreate);
  try
    try
      FArchive.ExtractItem(Cardinal(Index), Stream, False);
      if (ItemSize[Index] >= 0) and (Stream.Size <> ItemSize[Index]) then
        raise EInvalidOperation.CreateFmt('Archive size mismatch: %s', [ItemPath[Index]]);
    finally
      Stream.Free;
    end;
    if FileExists(Destination) then
      raise EInvalidOperation.CreateFmt('Extraction destination exists: %s', [Destination]);
    if not RenameFile(Tmp, Destination) then
      RaiseLastOSError;
    Tmp := '';
  finally
    if (Tmp <> '') and FileExists(Tmp) then System.SysUtils.DeleteFile(Tmp);
  end;
end;

end.
