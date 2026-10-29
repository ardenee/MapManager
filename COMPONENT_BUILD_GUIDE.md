# Manual component builds - RAD Studio 37.0

Select **Windows 64-bit (Modern) / Release** for the following projects.

| Component | Open in RAD Studio |
| --- | --- |
| TUTPackage | TUTPackage/TUTPackageNative.dproj |
| d7zip + MMArchiveEngine | ThirdParty/d7zip/MapManagerArchiveNative.dproj |
| JAM Virtual TreeView runtime | C:\Temp\MapManagerDeps\Virtual-TreeView\Packages\CBuilder 13\VirtualTreesCR.cbproj |
| All three runtime components | MapManager-Components.groupproj |

The Virtual TreeView designer project is available beside its runtime project as VirtualTreesCD.cbproj. It is not needed to link Map Manager. The aggregate group uses the existing local Virtual TreeView checkout and will need a path adjustment on another machine.

Each Delphi project is a runtime PACKAGE and builds native .bpl, .bpi, .dcp, .lib outputs. These are found in the Embarcadero Public Documents Bpl/Win64x and Dcp/Win64x directories. Both individual projects and the aggregate group have passed Win64x Release builds.

**Important: Map Manager links separate, static native COFF libraries instead of those runtime packages.** To rebuild the exact archive components used by the application, run from the repository root:

    build\compile-archive-units.cmd Win64x Release

The script compiles TUTPackage, MMArchiveEngine and sevenzip with dcc64 -jf:coffi and produces:

    Win64x\Release\TUTPackage.lib
    Win64x\Release\MMArchiveEngine.lib

The second library contains MMArchiveEngine.o and sevenzip.o. Project1.cbproj automatically runs this script before linking and includes TUTPackage.lib and MMArchiveEngine.lib in its IDE-native LinkPackageStatics property. The application also links the separately built Win64x VirtualTreesCR.lib. Do not mix legacy Win64 ELF .a files with Win64x COFF .lib files, nor simultaneously link both runtime BPL and static archives.

For the full app, open **Project1.cbproj** (NOT historical Project1.bpr or Project1.bdsproj), choose Windows 64-bit Modern / Release, and select Rebuild. A native 64-bit 7z.dll is automatically staged into Win64x/Release from the installed 7-Zip DLL when available. No external archive executable is required.

**TMapFileData.cpp / .h:** Stub compatibility files are present solely for IDEs that retain an old source list. The canonical TFileData implementation, including DecodeMapInfoString, is in TFileData.cpp. Never restore old duplicated implementations from other source folders.

Verified 29 October 2026: both component Delphi projects, the aggregate project group, and a clean Win64x Release application rebuild pass. End-to-end GUI and installer/undo runtime acceptance remains outstanding.
