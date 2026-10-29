# Building Map Manager and components in RAD Studio 37.0

## Recommended: use a project group

In RAD Studio select File > Open Project, then open MapManager-All.groupproj in the DEV repository root. Set Windows 64-bit (Modern) and Release. Choose Build All Projects, or build individual projects in Project Manager.

The projects in build order:

1. TUTPackage/TUTPackageNative.dproj - Unreal package reader
2. ThirdParty/d7zip/MapManagerArchiveNative.dproj - d7zip plus MMArchiveEngine
3. C:\Temp\MapManagerDeps\Virtual-TreeView\Packages\CBuilder 13\VirtualTreesCR.cbproj - JAM Virtual TreeView runtime
4. Project1.cbproj - Map Manager application

The Virtual TreeView path is the existing DEV checkout and must be adjusted on a different machine. MapManager-Components.groupproj remains available for components only.

## What the GUI build produces

With Delphi Compiler / Output - C/C++ set to generate all files, the TUTPackage and archive .dproj packages emit COFF static libraries in:

    C:\Users\Public\Documents\Embarcadero\Studio\37.0\Dcp\Win64x\TUTPackageNative.lib
    C:\Users\Public\Documents\Embarcadero\Studio\37.0\Dcp\Win64x\MapManagerArchiveNative.lib

They also produce BPL, BPI and DCP files. Map Manager uses these static .lib files, not the runtime package BPLs. RAD Studio already includes Dcp/Win64x in the linker library search path.

Project1.cbproj Win64x Release now uses LinkPackageStatics with TUTPackageNative.lib and MapManagerArchiveNative.lib (plus the existing Win64x VirtualTreesCR.lib). No object search path or manual compilation of MMArchiveEngine.o is necessary.

A missing -l:MapManagerArchiveNative.lib in ld.lld's command line means the IDE has older project settings loaded. Close and reopen Project1.cbproj (or MapManager-All.groupproj). Do not open the historical Project1.bpr or Project1.bdsproj.

## Archive Delphi units in the application project

Although the GUI-buildable MapManagerArchiveNative.dproj produces a COFF static package library, the current clean application link requires the MMArchiveEngine.pas and sevenzip.pas DelphiCompile entries in Project1.cbproj. RAD Studio compiles these automatically as part of the GUI build. Temporarily removing those entries produced unresolved MMArchiveEngine methods/vtable even after rebuilding the package library. Keep them enabled until a standalone-library-only link has been independently certified. This does not require running any external batch script.

## Existing legacy targets

The application build/compile-archive-units.cmd hook remains for Win32 and legacy Win64 only; the Win64 Modern Release application no longer invokes it. Win64 Modern uses COFF .lib, not legacy Win64 ELF .a. The source Project1.res is staged for clean rebuild, and native 64-bit 7z.dll is staged beside the executable when installed.

TMapFileData.cpp/.h are compatibility stubs defining no TFileData methods. The canonical TFileData class remains in TFileData.cpp. Do not restore duplicate source files.

## Verified 29 October 2026

- Separate TUTPackageNative and MapManagerArchiveNative Delphi project builds: PASS.
- VirtualTreesCR Win64x runtime build: PASS.
- MapManager-Components.groupproj: PASS.
- MapManager-All.groupproj (components and application): PASS.
- Full clean Win64x Release application rebuild without the archive script: PASS.

GUI startup, file installation, archive extraction and undo end-to-end runtime acceptance remain outstanding.
