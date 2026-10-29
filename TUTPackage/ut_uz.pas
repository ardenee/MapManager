{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License Version
1.1 (the "License"); you may not use this file except in compliance with
the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

The Original Code is: ut_uz.pas, released on 2004-01-23.

The Initial Developer of the Original Code is Antonio Cordero Balcazar.

Portions created by the Initial Developer are Copyright (C) 2004
the Initial Developer. All Rights Reserved.

Contributor(s):

-----------------------------------------------------------------------------}
unit ut_uz;
{
  TUZFile v1.0

  Class used to read and extract from UZ compressed files.

  History:

  1.0 - Initial version.
}

// TODO : add support for uz2 (may use zlib?)

interface

uses classes,sysutils;

type
  TUZFile=class
  private
    FSignature:cardinal;
    FFilename:string;
    FOriginalFilename:string;
  public
    constructor Create(filename:string);
    procedure Decode (stream:tstream);
    property Filename:string read FFilename;
    property OriginalFilename:string read FOriginalFilename;
  end;

implementation

resourcestring
  rsInvalidSignature='Invalid signature on file %s';

function read_idx(stream: tstream): integer;
var
  b0, b1, b2, b3, b4: byte;
begin
  result := 0;
  stream.Read(b0,1);
  if (b0 and $40) <> 0 then
    begin
      stream.Read(b1,1);
      if (b1 and $80) <> 0 then
        begin
          stream.Read(b2,1);
          if (b2 and $80) <> 0 then
            begin
              stream.Read(b3,1);
              if (b3 and $80) <> 0 then
                begin
                  stream.Read(b4,1);
                  result := b4;
                end;
              result := (result shl 7) or (b3 and $7F);
            end;
          result := (result shl 7) or (b2 and $7F);
        end;
      result := (result shl 7) or (b1 and $7F);
    end;
  result := (result shl 6) or (b0 and $3F);
  if (b0 and $80) <> 0 then
    result := -result;
end;

{ Codecs }

type
  TCodec=class
  protected
    class procedure InternalDecode (instr,outstr:TStream);virtual;abstract;
  public
    class procedure Decode (instr,outstr:TStream);
  end;
  TCodecRLE=class(TCodec) // RLE
  protected
    class procedure InternalDecode (instr,outstr:TStream);override;
  end;
  TCodecBWT=class(TCodec) // Burrows-Wheeler inspired
  protected
    class procedure InternalDecode (instr,outstr:TStream);override;
  end;
  TCodecMTF=class(TCodec) // Move-to-front
  protected
    class procedure InternalDecode (instr,outstr:TStream);override;
  end;
  TCodecHuffman=class(TCodec) // Huffman
  protected
    class procedure InternalDecode (instr,outstr:TStream);override;
  end;

{ TCodec }

class procedure TCodec.Decode (instr,outstr:TStream);
//var str:tfilestream;
begin
  try
    InternalDecode (instr,outstr);
  finally
    {// following code used to debug
    str:=tfilestream.create ('C:\Temp\'+classname+'.bin',fmCreate);
    try
      outstr.Seek(0,soFromBeginning);
      str.CopyFrom(outstr,outstr.Size-outstr.position);
    finally
      str.free;
    end;}
  end;
end;

{ TCodecRLE }

class procedure TCodecRLE.InternalDecode(instr, outstr: TStream);
const RLE_LEAD=5;
var Count:integer;PrevChar,B,C:byte;
begin
  Count:=0;
  PrevChar:=0;
  while instr.Position<instr.Size do
		begin
      instr.read (B,1);
      outstr.Write(B,1);
			if (B<>PrevChar) then
			  begin
				  PrevChar := B;
				  Count    := 1;
        end
			else
        begin
          inc(Count);
          if (Count=RLE_LEAD) then
            begin
              instr.Read(C,1);
              assert (C>=2);
              while (C>RLE_LEAD) do
                begin
                  outstr.Write(B,1);
                  dec(C);
                end;
              Count := 0;
            end;
        end;
    end;
end;

{ TCodecBWT }

class procedure TCodecBWT.InternalDecode(instr, outstr: TStream);
const MAX_BUFFER_SIZE=$40000;
var
  DecompressBuffer:array of byte;
  Temp:array of integer;
  DecompressLength:integer;
  DecompressCount:array[0..256] of integer;
  RunningTotal:array[0..256] of integer;
  i,j,First,Last,Sum,Index:integer;
begin
  setlength(DecompressBuffer,MAX_BUFFER_SIZE+1);
  setlength(Temp,MAX_BUFFER_SIZE+1);
  while instr.Position<instr.size do
		begin
      {DecompressLength:=read_idx(instr); //}instr.read (DecompressLength,4);
      First:=read_idx(instr); //instr.read (First,4);
      Last:=read_idx(instr); //instr.read (Last,4);
      assert (DecompressLength<=MAX_BUFFER_SIZE+1);
      assert (DecompressLength<=instr.size-instr.position);
      inc(DecompressLength);
      instr.Read(DecompressBuffer[0],DecompressLength); // TODO : warning, TArray!
      for i:=0 to 256 do DecompressCount[i]:=0;
      for i:=0 to DecompressLength-1 do
        if i<>Last then
          inc(DecompressCount[DecompressBuffer[i]])
        else
          inc(DecompressCount[256]);
			Sum := 0;
      for i:=0 to 256 do
        begin
				  RunningTotal[i] := Sum;
				  Sum := Sum+DecompressCount[i];
				  DecompressCount[i] := 0;
			  end;
      for i:=0 to DecompressLength-1 do
        begin
          if i<>Last then Index:=DecompressBuffer[i] else Index:=256;
	  			Temp[RunningTotal[Index] + DecompressCount[Index]] := i;
          inc(DecompressCount[Index]);
			  end;
      i:=First;j:=0;
      while j<DecompressLength-1 do
        begin
          outstr.Write(DecompressBuffer[i],1);
          i:=Temp[i];
          inc(j);
        end;
		end;
end;

{ TCodecMTF }

class procedure TCodecMTF.InternalDecode(instr, outstr: TStream);
var List:array [0..255] of byte;B,C:byte;i,NewPos:integer;
begin
  for i:=0 to 255 do List[i]:=i;
  while instr.Position<instr.size do
		begin
      instr.Read(B,1);
      C:=List[B];
      outstr.Write(C,1);
      NewPos:=0;
      for i:=B downto NewPos+1 do
        List[i]:=List[i-1];
      List[NewPos]:=C;
    end;
end;

{ TCodecHuffman }

type
  TBitMemoryStream=class(TMemoryStream)
  private
    FBitPosition:int64;
    FBit:byte;
    FCurrentByte:byte;
    function GetBitCount:int64;
    function GetNextBit:byte;
    function GetNextByte:byte;
  public
    constructor Create;
    property BitPosition:int64 read FBitPosition;
    property BitCount:int64 read GetBitCount;
    property ReadBit:byte read GetNextBit;
    property ReadByte:byte read GetNextByte;
  end;

constructor TBitMemoryStream.Create;
begin
  inherited;
  FBitPosition:=0;
  FBit:=7;
end;

function TBitMemoryStream.GetBitCount: int64;
begin
  result:=8*self.Size;
end;

function TBitMemoryStream.GetNextBit: byte;
begin
  if (FBit=7) then self.Read (FCurrentByte,1);
  result:=((FCurrentByte and (1 shl FBit)) shr FBit);
  if FBit=0 then FBit:=7 else dec(FBit);
  inc(FBitPosition);
end;

function TBitMemoryStream.GetNextByte:byte;
var n:byte;
begin
  result:=0;
  for n:=0 to 7 do
    result:=(result shl 1) or GetNextBit;
end;

type
  THuffman=class
  private
    Ch,Count:integer;
    Child:array [boolean] of THuffman;
  public
    constructor Create (InCh:integer);
    destructor Destroy;override;
    procedure ReadTable (Reader:TBitMemoryStream);
  end;

constructor THuffman.Create(InCh: integer);
begin
  Ch:=InCh;
  Count:=0;
end;

destructor THuffman.Destroy;
begin
  Child[false].free;
  Child[true].free;
  inherited;
end;

procedure THuffman.ReadTable(Reader: TBitMemoryStream);
begin
  if Reader.ReadBit=1 then
    begin
      Child[false]:=THuffman.Create(-1);
      Child[false].ReadTable(Reader);
      Child[true]:=THuffman.Create(-1);
      Child[true].ReadTable(Reader);
    end
  else
    Ch:=Reader.ReadByte;
end;

class procedure TCodecHuffman.InternalDecode(instr, outstr: TStream);
var Total:integer;Reader:TBitMemoryStream;
    Root,Node:THuffman;B:Byte;
begin
  instr.read (Total,4);
  // TODO : warning, original code uses TArray to read the bit stream
  Reader:=TBitMemoryStream.create;
  Reader.CopyFrom(instr,instr.Size-instr.position);
  Reader.Seek(0,soFromBeginning);
  Root:=THuffman.create (-1);
  Root.ReadTable (Reader);
  while (Total>0) do
		  begin
        assert (Reader.BitPosition<Reader.BitCount);
        Node:=Root;
        while Node.ch=-1 do
          Node:=Node.Child[(Reader.ReadBit=1)];
        B:=Node.ch;
        outstr.Write (B,1);
        dec(Total);
		  end;
  Root.free;
  Reader.free;
end;

{ TUZFile }

{
   DWORD Signature = 1234 or 5678
   SizedASCIIZ OriginalFilename
   CompressedStream
   Order of Codecs: RLE, BWT, MTF, RLE(only in 5678), Huffman
}

constructor TUZFile.Create(filename: string);
var str:tfilestream;size:byte;
begin
  str:=tfilestream.create (filename,fmOpenRead);
  try
    str.Read(FSignature,4);
    if (FSignature<>1234) and (FSignature<>5678) then
      raise exception.create (format(rsInvalidSignature,[filename]));
    FFilename:=filename;
    str.read(size,1); // TODO : should be an index but this should be enough
    setlength(FOriginalFilename,size-1);
    str.read(FOriginalFilename[1],size-1);
    str.read(size,1); // ending null character
  finally
    str.free;
  end;
end;

procedure TUZFile.Decode(stream: tstream);
var str,outend:tfilestream;intmp,outtmp,tmp:TMemoryStream;
begin
  intmp:=tmemorystream.create;
  str:=tfilestream.create (FFilename,fmOpenRead);
  try
    str.seek (4+2+length(FOriginalFilename),soFromBeginning);
    intmp.CopyFrom(str,str.Size-str.position);
    intmp.seek(0,soFromBeginning);
  finally
    str.free;
  end;
  outtmp:=tmemorystream.create;
  try
    TCodecHuffman.Decode(intmp,outtmp);
    intmp.Clear;tmp:=intmp;intmp:=outtmp;outtmp:=tmp;intmp.Seek(0,soFromBeginning);
    if FSignature=5678 then
      begin
        TCodecRLE.Decode(intmp,outtmp);
        intmp.Clear;tmp:=intmp;intmp:=outtmp;outtmp:=tmp;intmp.Seek(0,soFromBeginning);
      end;
    TCodecMTF.Decode(intmp,outtmp);
    intmp.Clear;tmp:=intmp;intmp:=outtmp;outtmp:=tmp;intmp.Seek(0,soFromBeginning);
    TCodecBWT.Decode(intmp,outtmp);
    intmp.Clear;tmp:=intmp;intmp:=outtmp;outtmp:=tmp;intmp.Seek(0,soFromBeginning);
    TCodecRLE.Decode(intmp,outtmp);
    outend:=tfilestream.create (extractfilepath(FFilename)+FOriginalFilename,fmCreate);
    try
      outend.CopyFrom(outtmp,0);
    finally
      outend.free;
    end;
  finally
    outtmp.free;
    intmp.free;
  end;
end;

end.
