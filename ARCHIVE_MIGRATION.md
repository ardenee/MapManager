PATH UPDATE (29 October 2026): Active source is C:\Users\arden\source\repos\MapManager. Component source folders are sibling Virtual-TreeView, d7zip, and TUTPackage directories. References below to C:\Temp\MapManagerDeps or MapManagerAudit are historical and may no longer exist. See COMPONENT_BUILD_GUIDE.md for current paths.

# Archive component migration — 29 October 2026


## Update - 29 October 2026: Win64 linker gate closed

- Full RAD Studio 37.0 Win64 Debug build PASSED twice (normal /t:Build and /t:Build with /p:ForceLink=true; both exit 0). Output: Win64/Debug/Project1.exe (x64 PE image).
- Cause of unresolved Mmarchiveengine TMMArchiveEngine methods/vtable: generated Delphi MMArchiveEngine.o and sevenzip.o existed, but the project did not register them as linker input. Both are now explicit ObjFiles, scoped by target architecture and configuration. Their compilation hook runs before linker dependency analysis.
- Cause of broad RTL/Windows import failures: setting ILINK_AdditionalLibs to TUTPackage.a prevented C++Builder's default Windows import/RTL libraries. Replaced with platform-scoped LibFiles for TUTPackage.a.
- TMapFileData.cpp is already excluded from CppCompile because it duplicates TFileData.cpp; stale Win64 Debug TMapFileData.o and .d outputs removed. Source retained.
- The older sections below record their original migration state. The full Win64 build is no longer blocked. This does not certify GUI startup, archive install/undo, or XML/SQLite behavior.
- The project currently references locally compiled TUTPackage Win64 at C:\Temp\MapManagerDeps\Win64-units\TUTPackage.a and installed Virtual TreeView packages; clean-machine reproducibility not yet tested.

## Update - 29 October 2026: Win64 Modern Release compatibility

- Win64x/Release build and clean rebuild PASS (exit 0) in RAD Studio 37.0, producing Project1.exe. This is not the legacy Win64 toolchain.
- Delphi native inputs require COFF: dcc64 -jf:coffi creates modern-compatible .o files and llvm-lib packages TUTPackage.lib. Older ELF-format Win64 .o/.a files are incompatible.
- VirtualTreesCR Win64x/Release .lib and .bpi built separately; application includes the modern package in its library search path. Generated modern headers are stored under TUTPackage/generated/Win64x and ThirdParty/d7zip/generated/Win64x.
- Fresh builds stage Project1.res from the source resource if missing; post-link stages 64-bit 7z.dll when installed in Program Files.
- Redundant TMapFileData source/header removed after preserving its unique decoding helper in TFileData.cpp. Strict modern Clang declaration in TMMCache.h corrected.
- The earlier source migration tests are standalone: new full application build success does NOT constitute GUI, installation, undo, or encrypted/RAR5 acceptance.

## Scope

The recovered C++Builder application previously referenced two external VCL archiver components: ZipBuilder for ZIP and TDFUnRar for RAR. Their headers, object declarations, event callback types, component construction/destruction, C++ method calls, and package search/link references have now been removed from **active project source**.

Replacement: **MMArchiveEngine.pas** (application-owned Delphi facade) using **ThirdParty/d7zip/sevenzip.pas** and an **in-process native 7z.dll**. The application never calls 7z.exe or WinRAR for archive operations.

## Changed code

- MMArchiveEngine.pas — shared open, signature-based format routing, enumeration, size, compressed size, CRC, encrypted flag, timestamp and selected-file extraction to a temporary file then rename; path sanitation and reparse-point checks.
- ThirdParty/d7zip/generated/Win32/MMArchiveEngine.hpp and generated/Win64/MMArchiveEngine.hpp — platform-specific C++ headers.
- TArchives.cpp/.h and TMMArchives.cpp/.h — archive content listing now enumerates the unified archive backend rather than ZIP/RAR VCL components or empty placeholders.
- TMMFileInfoThread.cpp/.h — ZIP, RAR and ZIP-SFX detail views now read archive entries and metadata through the facade; no legacy component ownership/callbacks.
- InstallArchiveThread.cpp/.h and TMMInstallThread.cpp/.h — ZIP and RAR install methods delegate to InstallPacked(), which uses one d7zip backend for selected member extraction, game-extension folder routing, optional original subfolders, per-file notifications, backup and install logs.
- MapManager.cpp/.h — old archive component link directive and includes removed; pre-existing user-edited Virtual TreeView modernization changes retained.
- Project1.cbproj — obsolete ZipBuilder/TDFUnRar include paths, import/static libraries and historic C++ header directories removed. MMArchiveEngine.pas added as a Delphi unit alongside sevenzip.pas. Win32 compiler set to bcc32c to match compiled Virtual TreeView.
- build/compile-archive-units.cmd — automatic platform-specific Delphi object compilation during C++ linking via MSBuild MapManagerArchiveDelphiObjects target. Tested Win32 target separately.
- Archive-FileTypes.txt — added .7z, with automatic .zip/.rar/.7z fallback routing in installers when legacy registry mappings do not provide a known type.

## Verified working

1. RAD Studio 37 Win32 standalone new facade compiles and lists/extracts ZIP, 7z and historical RAR4. Member names, sizes, packed sizes, CRC and write times retrieved successfully.
2. RAD Studio 37 Win64 standalone facade compiles and lists/extracts ZIP, 7z and RAR4 using native 64-bit 7z.dll.
3. ZIP-SFX with harmless fake EXE stub and ZIP overlay enumerated and extracted inside the 32-bit process without executing the EXE.
4. Malicious ZIP member names (../, nested ../, drive-absolute, slash-absolute, Windows ADS and reserved device names) rejected; no file escaped the extraction directory. Existing targets refused by facade (Win32 fixture tests).
5. No active ZipBuilder, DFUnRar, ZBldr or TDFRARHeaderData references remain in .cpp/.h/.cbproj/.dfm files (audit).
6. The old archive-related C++ source files compiled under the Win32 bcc32c toolchain. Full application build then proceeded to *unrelated* TMMSettings.cpp syntax errors under newer Clang; application does not yet link or start.
7. Win64 full-app build now compiles and links as of the later 29 October 2026 linker fixes above. Exception syntax in TMMSettings.cpp was repaired; runtime acceptance is still outstanding.
8. Build hook MapManagerArchiveDelphiObjects invoked directly for Win32 and generated required MMArchiveEngine.obj and sevenzip.obj successfully.

## Remaining validation and compatibility caveats

- **Full Win64 Debug Map Manager has built but has not been launched or runtime-validated.** Actual VCL UI, game folder routing, install/undo and Log XML workflows have not been end-to-end tested. The modern TMMArchives::Install branch was historically disabled; this migration did not re-enable it or recreate its missing application settings.
- Encrypted/password-protected files are detected and rejected with a clear error; no UI prompt or password callback has been wired yet. RAR5 format GUID is selected from the RAR5 signature but no genuine RAR5 archive fixture has been accepted yet.
- Multipart archives and cancellation in the middle of one large compressed member remain unverified. Termination is checked **between** archive members. User-visible per-byte progress remains to implement.
- The legacy app uses AnsiString for many game paths, so full Unicode filename preservation is not certified.
- The installer stages file bytes, then applies overwrite policy; game mapping and backup logging need dedicated integration tests against a fake game directory and disposable logs before any real game folder is used.
- Do not treat archive and application feature parity as completed; use this document to close these gates once the app builds.

## Local paths / reproducibility

- Project source: C:\Users\arden\source\repos\MapManager-Recovered
- Current Win32 DLL: Win32\Debug\7z.dll (official 7-Zip 26.05 x86)
- Current Win64 DLL: Win64\Debug\7z.dll (official 7-Zip 26.05 x64)
- Temporary test scripts: C:\Temp\MapManagerDeps\MMArchiveSmoke.dpr, test-mm-archive-safety.py, test-sfx-in-process.py
- Local build logs: C:\Temp\MapManagerDeps\mm-archive-win32-rebuild.log and mm-archive-migration-win64.log
- Pre-edit snapshot preserving the user's uncommitted changes: C:\Temp\MapManagerDeps\archive-migration-backup-20261029

The third-party DLLs and native build products remain excluded from Git; compile/redistribute with the applicable MPL 1.1 and 7-Zip licensing notices.
