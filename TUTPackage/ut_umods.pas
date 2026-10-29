{-----------------------------------------------------------------------------
The contents of this file are subject to the Mozilla Public License Version
1.1 (the "License"); you may not use this file except in compliance with
the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

The Original Code is: ut_umods.pas, released on 2004-01-23.

The Initial Developer of the Original Code is Antonio Cordero Balcazar.

Portions created by the Initial Developer are Copyright (C) 2004
the Initial Developer. All Rights Reserved.

Contributor(s):

-----------------------------------------------------------------------------}
unit ut_umods;
{
  TUMOD v2.0

  Class used to read and extract from UMOD files.

  History:

  2.0 - Added Description.
        Added more Extract overloads.
        Added property to obtain file sizes.
  1.0 - Initial version.
}
interface

uses classes;

type
  TUMODHeader=packed record
                     Magic:cardinal;
                     DirectoryStart:cardinal;
                     UMODSize:integer;
                     Version:cardinal;
                     CRC:cardinal;
                     end;
  TUMODFileData=record
                    Name:string;
                    Start,Size,Flags:cardinal;
                    end;
  TUMOD=class
  private
    FFilename:string;
    FDirectoryHeader:TUMODHeader;
    FFiles:array of TUMODFileData;
    FDescription:string;
    function umod_read_idx(stream: tstream): integer;
    function GetCount: integer;
    function GetFiles(i: integer): string;
    function GetFileSize(i: integer): integer;
    function GetDescription: string;
  public
    constructor Create;
    function IsUMOD (filename:string):boolean;
    procedure Load (filename:string);
    procedure ExtractAll (destination:string);
    property Count:integer read GetCount;
    property Files[i:integer]:string read GetFiles;
    property Size[i:integer]:integer read GetFileSize;
    property Filename:string read FFilename;
    property Description:string read FDescription;
    procedure Extract (f:integer;destination:string);overload;
    procedure Extract (f,destination:string);overload;
    procedure Extract (f:string;destination:TStream);overload;
    procedure Extract (f:integer;destination:TStream);overload;
  end;

implementation

uses sysutils;

{ TUMOD }

constructor TUMOD.Create;
begin
     FFilename:='';
     fillchar(FDirectoryHeader,sizeof(FDirectoryHeader),0);
     setlength(FFiles,0);
end;

function TUMOD.umod_read_idx(stream: tstream): integer;
var
  b0, b1, b2, b3, b4: byte;
begin
  result := 0;
  stream.read (b0,1);
  if (b0 and $40) <> 0 then
    begin
      stream.read (b1,1);
      if (b1 and $80) <> 0 then
        begin
          stream.read (b2,1);
          if (b2 and $80) <> 0 then
            begin
              stream.read (b3,1);
              if (b3 and $80) <> 0 then
                begin
                  stream.read (b4,1);
                  result := b4;
                end;
              result := (result shl 7) or (b3 and $7F);
            end;
          result := (result shl 7) or (b2 and $7F);
        end;
      result := (result shl 7) or (b1 and $7F);
    end;
  result := (result shl 6) or (b0 and $3F);
  if (b0 and $80) <> 0 then result := -result;
end;

procedure TUMOD.Load(filename: string);
var umod:TFileStream;filecount,f,namesize:integer;
begin
     FDescription:='';
     FFilename:=filename;
     setlength(FFiles,0);
     fillchar(FDirectoryHeader,sizeof(FDirectoryheader),#0);
     umod:=tfilestream.create (FFilename,fmOpenRead+fmShareDenyNone);
     try
        umod.seek (-sizeof(FDirectoryHeader),soFromEnd);
        umod.read (FDirectoryHeader,sizeof(FDirectoryHeader));
        if FDirectoryHeader.magic<>$9FE3C5A3 then
           raise exception.create ('File is not an UMOD.')
        else if FDirectoryHeader.version<>1 then
           raise exception.create ('Unknown UMOD version.')
        else if FDirectoryHeader.UMODSize<>umod.size then
           raise exception.create ('UMOD file is corrupt (size does not match).')
        // TODO : should test CRC
        else begin
             try
                umod.seek (FDirectoryHeader.DirectoryStart,soFromBeginning);
                FileCount:=umod_read_idx (umod);
                setlength(FFiles,FileCount);
                for f:=0 to FileCount-1 do
                    begin
                    namesize:=umod_read_idx (umod);
                    setlength (FFiles[f].name,namesize);
                    umod.read (FFiles[f].name[1],namesize);
                    setlength (FFiles[f].name,namesize-1);
                    umod.read (FFiles[f].Start,4);
                    umod.read (FFiles[f].Size,4);
                    umod.read (FFiles[f].Flags,4);
                    end;
                GetDescription;
             except
                on e:exception do raise exception.create ('Error "'+e.message+'" reading UMOD directory.');
             end;
           end;
     finally
        umod.free;
     end;
end;

procedure TUMOD.Extract(f:integer;destination: string);
var save:tfilestream;
begin
     if copy(destination,length(destination),1)='\' then destination:=destination+extractfilename(FFiles[f].name);
     forcedirectories(extractfilepath(destination));
     save:=tfilestream.create (destination,fmCreate);
     try
       Extract (f,save);
     finally
       save.free;
     end;
end;

procedure TUMOD.ExtractAll(destination: string);
var umod,save:tfilestream;f:cardinal;
begin
     umod:=tfilestream.create (FFilename,fmOpenRead+fmShareDenyNone);
     try
        try
           if copy(destination,length(destination),1)<>'\' then destination:=destination+'\';
           for f:=0 to high(FFiles) do
               begin
               umod.seek (FFiles[f].start,soFromBeginning);
               forcedirectories(extractfilepath(destination+FFiles[f].name));
               save:=tfilestream.create (destination+FFiles[f].name,fmCreate);
               save.CopyFrom (umod,FFiles[f].size);
               save.free;
               end;
        except
           on e:exception do raise exception.create ('Exception "'+e.message+'" extracting files.');
        end;
     finally
        umod.free;
     end;
end;

function TUMOD.GetCount: integer;
begin
     result:=length(FFiles);
end;

function TUMOD.GetFiles(i: integer): string;
begin
     result:=FFiles[i].name;
end;

procedure TUMOD.Extract(f, destination: string);
var a:integer;
begin
     for a:=0 to high(FFiles) do
         if FFiles[a].name=f then
            begin
            Extract(a,destination);
            break;
            end;
end;

function TUMOD.IsUMOD(filename: string): boolean;
var umod:Tfilestream;dh:TUMODHeader;
begin
   result:=false;
   try
      umod:=tfilestream.create (Filename,fmOpenRead+fmShareDenyNone);
      umod.seek (-sizeof(dh),soFromEnd);
      umod.read (dh,sizeof(dh));
      result:=(dh.magic=$9FE3C5A3);
   except
   end;
   FreeAndNil (umod);
end;

function TUMOD.GetFileSize(i: integer): integer;
begin
     result:=FFiles[i].Size;
end;

function TUMOD.GetDescription: string;
var manifest:tstringstream;manifeststr:tstringlist;
begin
     manifest:=tstringstream.create ('');
     try
       Extract ('System\Manifest.int',manifest);
       manifeststr:=tstringlist.create;
       try
         manifeststr.text:=manifest.DataString;
         FDescription:=manifeststr.values['SetupWindowTitle'];
       finally
         manifeststr.free;
       end;
     except
     end;
     manifest.free;
end;

procedure TUMOD.Extract(f: string; destination: TStream);
var a:integer;
begin
     for a:=0 to high(FFiles) do
         if FFiles[a].name=f then
            begin
            Extract(a,destination);
            break;
            end;
end;

procedure TUMOD.Extract(f: integer; destination: TStream);
var umod:tfilestream;
begin
     umod:=tfilestream.create (FFilename,fmOpenRead+fmShareDenyNone);
     try
        try
           umod.seek (FFiles[f].start,soFromBeginning);
           destination.CopyFrom (umod,FFiles[f].size);
        except
           on e:exception do raise exception.create ('Exception "'+e.message+'" extracting file.');
        end;
     finally
        umod.free;
     end;
end;

end.
