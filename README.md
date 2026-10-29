# Map Manager

**Map Manager** is the recovery and modernization of a legacy Windows C++Builder/VCL application for organizing Unreal and Unreal Tournament game files. The recovered source contains modules for browsing, cataloguing and installing maps and archives; viewing Unreal packages, textures, music, demos and screenshots; handling favourites, servers, logs and file operations.

> **Status — 29 October 2026:** Source recovery in progress. **Win64 Modern / Release now passes a clean build**, and legacy Win64 Debug also builds under RAD Studio 37.0. The GUI, full installer/runtime workflows, and Win32 full build have not yet been certified.

## Project status

**Win64 Modern Release update (29 October 2026):** C++Builder 37.0 bcc64x now builds the full application successfully, including a clean Rebuild, with platform-specific COFF dependencies and 64-bit 7z.dll staged alongside the executable. RAD Studio must reopen Project1.cbproj after project-file modifications; the earlier IDE instance had loaded outdated file lists. Runtime functionality still requires acceptance testing.

**RAD Studio IDE note (29 October 2026):** If the IDE still reports the old MMArchiveEngine unresolved methods or duplicate TFileData symbols after the command-line Win64 build succeeds, close the currently loaded project and reopen Project1.cbproj in RAD Studio. The IDE was started before the project-file fixes and built an obsolete duplicate unit from cached project state. The redundant TMapFileData source/header were removed after preserving their unique method in TFileData.cpp.

| Subsystem | Status | Evidence / outstanding work |
| --- | --- | --- |
| Historical source recovery | Recovered | Selected 2017-era `mm-setup2` baseline; original source and archives preserved separately |
| Virtual TreeView UI component | Build **passed** | C++Builder 13 Win32 runtime and design-time packages compiled using RAD Studio 37.0; design-time package registered |
| TUTPackage Unreal reader | Build **passed** | `ut_packages`, `ut_umods`, `ut_uz` and `utpkgnat_ut2004` compiled; `TUTPackage.lib` built for Win32 |
| d7zip / 7z.dll | Standalone **tests passed** | ZIP, RAR and 7z listing/extraction passed; ZIP and 7z creation/read-back passed, all in-process. RAR5 not independently tested |
| Archive consolidation | **Source migration implemented; runtime acceptance pending** | Legacy ZipBuilder/TDFUnRar references removed; ZIP/RAR/7z listing and extraction use MMArchiveEngine.pas and in-process d7zip. Standalone Win32/Win64 tests pass; application installer and rollback need acceptance testing |
| XML → SQLite | **Partial** | Legacy XML and partially implemented SQLite paths exist; recovered `settings.sqlite3.sql` is a reference only, first-run initialization/import/parity incomplete |
| Application build | **Win64 Modern Release clean rebuild PASS; runtime pending** | Modern COFF d7zip/TUTPackage and Virtual TreeView packages compiled; Project1.exe (x64) links in both normal and clean builds. Legacy Win64 Debug also builds. Win32 and UI runtime not yet certified |
| Functional/regression testing | **Not complete** | Application startup, UI, persistence, installation, logging, rollback and end-to-end archive handling remain to be verified |

See [PROJECT_STATUS.md](PROJECT_STATUS.md) for test evidence, blockers and next acceptance gates. File-by-file replacements and outstanding parity gates are documented in [ARCHIVE_MIGRATION.md](ARCHIVE_MIGRATION.md).

**Current Win64 build update (29 October 2026):** SDK 10.0.26100.4654 has been repaired and the patched headers have been installed. Virtual TreeView Win64 and the full Map Manager Win64 Debug application now build. Application runtime and archive install/undo are not yet verified; see [SDK and Win64 setup](RAD_STUDIO_SDK_AND_WIN64.md).

## Dependencies

Initial target is **Windows Win32**. This repository is not yet a reproducible, standalone build.

| Dependency | Use | Notes |
| --- | --- | --- |
| [Embarcadero RAD Studio / C++Builder 37.0](https://www.embarcadero.com/products/rad-studio) | Build C++Builder/VCL application and Delphi units | Win32 C++Builder (Clang), Delphi compiler and Windows SDK needed. Development version installed at `C:\Program Files (x86)\Embarcadero\Studio\37.0` |
| [JAM Virtual TreeView](https://github.com/JAM-Software/Virtual-TreeView) | Main tree/list display | Build CBuilder 13 Win32 `VirtualTreesCR` runtime and `VirtualTreesCD` design-time packages; generated `VirtualTrees.hpp` and libraries must be discoverable |
| [d7zip](https://github.com/geoffsmith82/d7zip) | Unified archive interface | MPL 1.1 Delphi source at `ThirdParty/d7zip/sevenzip.pas`, included in `Project1.cbproj`; Win32 generated C++ header included |
| [7-Zip](https://www.7-zip.org/) | Native codecs, in-process | Tested official 7-Zip 26.05 **32-bit** `7z.dll`. Obtain a matching DLL separately and put beside the application executable. **Never call `7z.exe` in the application.** |
| [TUTPackage / UT Packages](https://sourceforge.net/projects/utpackages/) | Legacy Unreal package, UMOD and UZ readers | Recovered MPL 1.1 Delphi source at `TUTPackage/`, originally by Antonio Cordero Balcazar and contributors |
| Embarcadero RTL/VCL, XML, dbExpress, DataSnap | UI, XML/settings, SQLite | Project references `rtl`, `vcl`, `vclx`, `vclimg`, `xmlrtl`, `dbrtl`, `dbexpress`, `DbxCommonDriver`, `DBXSqliteDriver`, `dsnap` and related RAD Studio units |
| **Legacy only:** ZipBuilder and TDFUnRar | Old ZIP/RAR handlers | Still called in source; replace after verifying equivalent functionality through d7zip |

### Current developer setup

1. Install RAD Studio 37.0 with Win32 C++Builder/Delphi compiler support and a compatible Windows SDK.
2. Build JAM Virtual TreeView's CBuilder 13 Win32 runtime/design packages and configure the runtime library and generated C++ header paths. Virtual TreeView's source is **not** vendored here.
3. Download the official **32-bit** `7z.dll` matching the Win32 build. It is intentionally excluded from Git.
4. Open `Project1.cbproj`. The project contains historical and recovery-era machine-specific paths that still need cleanup, and it does **not** currently complete a full build. The Delphi d7zip unit is already listed in the project.
5. Rebuild TUTPackage Delphi units where required. Link/runtime compatibility with the application is still unverified.

## Modernization roadmap

### Phase 1 — clean Win32 application build

- Fix C++Builder compiler/SDK and generated-header incompatibilities without changing installed RAD Studio system headers.
- Make project paths portable, remove stale dependencies once replaced, and verify a clean GUI launch.
- Establish a fixed, documented acceptance-test checklist and avoid repeating passing tests without new evidence.

### Phase 2 — archive consolidation (source replacement implemented; acceptance pending)

Replace ZipBuilder + TDFUnRar with **one in-process** d7zip + `7z.dll` implementation; no WinRAR or 7-Zip executable launched at runtime.

- List, inspect and extract ZIP, RAR/RAR5 and 7z; select the correct archive handler by content rather than filename extension alone.
- Support ZIP and 7z creation where needed (RAR read/extract only), passwords, file metadata, progress, cancellation, error reporting and multipart archives where available.
- Validate archived paths against traversal, absolute paths, symlinks/reparse points, collisions and unsafe overwrites; extract to a staging location before installing game content.
- Preserve game-specific UMOD/UZ logic, installer logging, rollback and file operations.
- Remove old archive libraries only after real-file and failure-path acceptance tests pass.

### Phase 3 — XML-to-SQLite migration

- Inventory XML-backed settings, categories, file lists, favourites, history, logs and other persisted data.
- Define and version SQLite schema; implement fresh-install database creation, schema upgrades and default seed data.
- Import existing XML without losing entries, references or ordering. Validate data counts and feature parity.
- Route storage through transactional SQLite access; retire XML writers only after rollback-safe verification.
- The existing `settings.sqlite3.sql` is a recovered starting point, **not** a validated complete migration.

### Phase 4 — functionality and release

- Verify map, texture, music, demo, screenshot, server and archive views; search/filter, file operations and installers.
- Verify progress/cancellation, favourites, logs and undo/rollback under real and malformed inputs.
- Test fresh startup, SQLite migration and deployment with no previous configuration.
- Produce repeatable Win32 builds, licence notices and a development release only after all gates pass.

## Repository layout

- `Project1.cbproj` / `Project1.cpp` — recovered C++Builder project and entry point.
- `MapManager.*` and `TMM*.cpp/.h` — recovered forms and application modules.
- `TUTPackage/` — historical Unreal Delphi readers and C++Builder headers.
- `ThirdParty/d7zip/` — MPL 1.1 source wrapper, header, licence and setup notes.
- `ThirdParty/7Zip/License.txt` — upstream licence details for the separately obtained DLL.
- `settings.sqlite3.sql` — historical schema/seed reference.
- `PROJECT_STATUS.md` — build blockers, evidence and next gates.

Historical archives, local configuration, private settings and compiled binaries are intentionally excluded from Git.

## Licensing and attribution

- **d7zip**: Mozilla Public License 1.1; original notices and full license included under `ThirdParty/d7zip`.
- **TUTPackage**: Mozilla Public License 1.1; original developer Antonio Cordero Balcazar and source notices retained, full licence under `TUTPackage/License.txt`.
- **Virtual TreeView**: separately downloaded and licensed according to its upstream repository.
- **7-Zip DLL**: separately downloaded; redistribution, including RAR decoding, is subject to applicable upstream 7-Zip/unRAR notices.
- The legacy Map Manager application source is being recovered; do not infer rights to redistribute proprietary Unreal game assets.

**SDK/build update (29 October 2026):** The Windows SDK patcher and Win64 Virtual TreeView runtime package build successfully. Win64 Debug Map Manager now compiles and links; legacy code warnings and runtime acceptance remain. See [SDK and Win64 diagnostics](RAD_STUDIO_SDK_AND_WIN64.md).

**GUI Win64 Modern Release builds:** Open [MapManager-All.groupproj](MapManager-All.groupproj) in RAD Studio for TUTPackage, d7zip/MMArchiveEngine, Virtual TreeView and the application. The application links static libraries generated by those projects without a manual archive script. See [COMPONENT_BUILD_GUIDE.md](COMPONENT_BUILD_GUIDE.md).

**First-run SQLite popup (29 October 2026):** The SQLite driver reports 'unable to open database file' when the missing settings.sqlite3 or cache.sqlite3 is opened. Fresh startup now leaves missing files unopened and uses XML settings; the Win64x build stages Settings/Settings.xml only if absent. This does NOT complete the SQLite migration. See PROJECT_STATUS.md.
