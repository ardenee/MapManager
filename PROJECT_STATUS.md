### GitHub synchronization and RAD Studio Win64x build confirmation - 29 October 2026

- User reports the MapManager application and its components appear to be building/working again in the RAD Studio 37.0 Win64 Modern / Release IDE workflow. This closes the immediate component/linker build investigation based on the user's confirmation; full runtime workflow acceptance (especially archive installs and rollback) remains separately unverified.
- The nine remaining MapManager application source and DFM edits have been included for GitHub synchronization, covering file details, Unreal/game enum additions, tree refresh defaults, buddy formats and GUI layout.
- Native VirtualTreesCR integration including Pascal source/header fixes is retained in build/patches/VirtualTreesCR-Native-Win64x.patch; clean-index application check passed against the separate JAM Virtual TreeView checkout.
- Native d7zip archive integration is now captured in build/patches/d7zip-MapManagerArchiveNative-RAD37.patch, including the local sevenzip.pas adjustment plus MapManagerArchiveNative.dproj/.dpk; clean-index application check passed against the separate geoffsmith82/d7zip checkout.
- Both third-party Git remotes point to maintainers' repositories; local modifications were not pushed to the upstream maintainers. Build outputs, personal settings and binaries are not included in MapManager Git.
- TUTPackage exists as a local, ignored folder inside a different parent working tree, with no separately versioned TUTPackage source repo here. Its source is not backed up by this MapManager commit; preserving it in GitHub would require an explicit source-vendoring/repository decision.
- No new build or runtime test was executed during GitHub synchronization.

### VirtualTreesCR native Delphi rebuild errors - 29 October 2026 (pending user retest)

- IDE rebuild of MapManager component group failed in VirtualTreesCR.dproj on VirtualTrees.BaseTree.pas(24) E2029 and VirtualTrees.WorkerThread.pas(194) E2250. TUTPackageNative had only its two existing nonfatal hints, and MapManagerArchiveNative compiled.
- The E2029 was introduced by changing an IFDEF block to an IF expression without updating its closing directive. Corrected the closing {$ENDIF} to {$IFEND} in upstream VirtualTrees.BaseTree.pas.
- Inspected installed RAD Studio 37.0 System.Classes.pas: TThreadProcedure is reference to procedure, and TThread.Synchronize(const AThread: TThread; AThreadProc: TThreadProcedure) exists. Changed the WorkerThread exception-rethrow callback to an explicitly typed TThreadProcedure passed to Synchronize to resolve overload selection; preserved synchronous exception handoff.
- Simplified native VirtualTreesCR.dproj define to MAPMANAGER_VTV_NATIVE, removing an empty intermediate semicolon in the -D argument.
- Updated build/patches/VirtualTreesCR-Native-Win64x.patch with the fixes and preserved original Pascal BOM and CRLF. Patch passes clean-index applicability; RAD Studio 37 RTL and project XML statically checked. No compiler build performed, per user's testing preference.
- Nine unrelated MapManager DEV source edits remain untouched.


### Win64x native VirtualTreeView generated-header fixes - 29 October 2026 (awaiting IDE rebuild)

- Latest Project1 Win64x Release GUI log reached ld.lld and failed on a single missing VirtualTreesR.lib, despite explicitly linking the existing VirtualTreesCR.lib. This came from a hidden auto-link directive emitted by upstream Source/VirtualTrees.BaseTree.pas, not from Project1.cbproj.
- Upstream Pascal source emits #pragma comment(lib, VirtualTreesCR) only under BCB, otherwise VirtualTreesR. The new Delphi-native VirtualTreesCR.dproj does not define BCB, so its generated VirtualTrees.BaseTree.hpp forced the incorrect VirtualTreesR.lib.
- Added project-specific MAPMANAGER_VTV_NATIVE to VirtualTreesCR.dproj and changed the BaseTree.pas conditional to choose VirtualTreesCR under BCB OR MAPMANAGER_VTV_NATIVE; standalone Delphi VirtualTreesR package remains unchanged by default.
- Repeated bcc64x non-portable-include-path warnings were caused by Pascal declarations and uses referring to VirtualTrees.(Base)AncestorVCL while files and newly generated headers use ...AncestorVcl. Normalized casing across the five affected Virtual TreeView Pascal files and the two explicit MapManager.h includes. Existing generated .hpp files were NOT manually edited.
- Updated reproducible build/patches/VirtualTreesCR-Native-Win64x.patch to include the native Delphi package additions and Pascal source fixes. Checked its applicability against the separate Virtual TreeView clean Git index and statically verified project XML, compiler symbol, unit spellings and application includes.
- User requested to run GUI build themselves. No compiler or GUI build was performed after this correction. Preserve nine unrelated uncommitted MapManager source edits.

### Remove obsolete TUTPackage.lib from application project - 29 October 2026

- Per user request, **removed every TUTPackage.lib reference** from the active Project1.cbproj, including all Win32/legacy-Win64 platform overrides. The old library is no longer an input to any application project configuration.
- The shared Base AllPackageLibs now lists only SDK/common libraries. Base_Win64x AllPackageLibs explicitly adds the correct TUTPackageNative.lib and MapManagerArchiveNative.lib; Win64x Release LinkPackageStatics already correctly specifies both. Thus the native static libraries are selected only for Win64 Modern.
- Confirmed TUTPackageNative.lib and MapManagerArchiveNative.lib in Embarcadero Studio 37.0 Dcp/Win64x. The old physical Win32/Debug library was not deleted; archived helper scripts or historical documentation can still mention it, but Project1.cbproj does not.
- Project XML and the key platform-specific properties were validated. User will perform IDE build; no new build was run. Nine unrelated worktree source edits were preserved.

### Native package GUI confirmation and shared TUTPackage library list - 29 October 2026 (resolved)

- User confirmed the RAD Studio Win64 Modern / Release GUI group build works using native Delphi VirtualTreesCR.dproj. The 22 missing VirtualTrees .o failures of the old C++Builder runtime path are closed for this active GUI build.
- Confirmed TUTPackageNative.lib, TUTPackageNative.bpi in the standard Embarcadero Studio 37.0 Dcp/Win64x directory and TUTPackageNative.bpl in Bpl/Win64x. The old TUTPackage.lib under TUTPackage/Win32/Debug belongs to a legacy build.
- Project1.cbproj still hardcoded TUTPackage.lib in the platform-neutral AllPackageLibs property; corrected the shared default to TUTPackageNative.lib and MapManagerArchiveNative.lib, matching the existing Win64x Release LinkPackageStatics.
- Preserved legacy TUTPackage.lib explicitly under Win32 Debug/Release and legacy Win64 Debug/Release AllPackageLibs overrides, to avoid silently changing those targets.
- Project XML and property presence were checked. No build was run following the correction, per user's testing preference; interactive RAD Studio reload required if the project is already loaded.
- Existing unrelated source edits were not changed.

### Native Delphi VirtualTreesCR Win64 Modern runtime - 29 October 2026 (awaiting IDE verification)

- Successive GUI build logs repeated 22 missing VirtualTrees.*.o object errors from the mixed C++Builder package. Output path fixes, custom target-order changes and standalone command-line successes had not fixed GUI building.
- Retired the failing VirtualTreesCR.cbproj from both active MapManager groups (old project/source preserved in the separate upstream checkout). Created VirtualTreesCR.dproj and VirtualTreesCR.dpk alongside it using the existing native Delphi package structure and TUTPackage's working Delphi project format.
- Package name VirtualTreesCR is preserved. The new DPK references the exact same 22 upstream Pascal units and the required rtl, vcl, vclx and vclimg packages. Win64x Release, C++ static library/header generation, unique Base/Debug/Release configurations and normal Delphi build targets are configured.
- Updated both .groupproj files and Project1.cbproj's Win64x header path to this source-local native package output directory. Existing VirtualTreesCR.lib and .bpi references remain unchanged.
- Added reproducible build/patches/VirtualTreesCR-Native-Win64x.patch for the two new external project files; retired the obsolete C++Builder runtime workaround patch from the current MapManager repository.
- Revised COMPONENT_BUILD_GUIDE.md and build/validate-rad-projects.py for this native project. Native project XML, source references and patch against the clean upstream Git index were checked. NO build was run; user's next GUI build is the acceptance check.
- All nine existing uncommitted MapManager source edits and unrelated upstream Virtual TreeView edits remain untouched.

### Virtual TreeView Win64 Modern MSBuild target evaluation correction - 29 October 2026 (untested GUI)

- Latest user IDE build still reports missing VirtualTrees.*.o files. The prior LinkDependsOnTargets override was AFTER CodeGear.Cpp.Targets Import and did not affect the already established Link target dependencies.
- Confirmed installed RAD Studio 37.0 CodeGear.Cpp.Targets appends native Link dependencies to the LinkDependsOnTargets property during import; it also schedules MakeStaticPackage after Link by default.
- Moved a Win64x-only LinkDependsOnTargets declaration BEFORE the CodeGear.Cpp.Targets import: it prepends MakeStaticPackage, then the native import adds _ResolveOutput, CreateDirectories, PreLinkEvent, and _PerformLink. Nested static builds are excluded with _DoingStaticPackageBuild=true.
- Updated the local VirtualTreesCR.cbproj in the sibling Virtual-TreeView checkout and the versioned integration patch build/patches/VirtualTreesCR-Win64x-RAD37.patch.
- Static XML syntax and patch applicability checked. No build or IDE test performed, per user preference. Await user's Win64x Release GUI rebuild. Unrelated DEV files preserved.

### Virtual Trees Win64x missing Delphi .o follow-up - 29 October 2026 (unverified)

- User IDE build after the earlier BeforeTargets=_CheckLinkDependencies target STILL reports 22 missing VirtualTrees.*.o files under Win64x/Release, confirming the earlier hook did not ensure the static-package build ran ahead of the runtime linker.
- Inspected actual installed RAD Studio 37.0 CodeGear.Cpp.Targets: MakeDependsOnTargets schedules MakeObjs;Link;...;MakeStaticPackage. The native MakeStaticPackage pass runs DCC_CBuilderOutput=JPHN and creates the Delphi object inputs; the runtime pass -JL does not emit them into the expected directory.
- Replaced the ineffective custom BeforeTargets hook with an explicit Win64x-only LinkDependsOnTargets chain: _ResolveOutput;CreateDirectories;PreLinkEvent;MakeStaticPackage;_PerformLink. The nested static pass is excluded via _DoingStaticPackageBuild=true so it retains the original target graph.
- Corrected the local VirtualTreesCR.cbproj in the separate Virtual-TreeView Git checkout and updated build/patches/VirtualTreesCR-Win64x-RAD37.patch for reproducible application to a clean checkout.
- No build was run, as requested. IDE verification is pending; if it fails, use the complete command log to determine whether the JPHN/static pass actually executed before ld.lld. The nine unrelated MapManager DEV changes remain untouched.

### Virtual Trees Win64x Delphi object-file linking - 29 October 2026 (unverified IDE change)

- User's Win64 Modern Release GUI build now emits correctly separated .o paths, but ld.lld still reports missing VirtualTrees.*.o from the expected Virtual-TreeView/Packages/CBuilder 13/Win64x/Release folder.
- Direct inspection shows 22 older .o files in Virtual-TreeView/Source and no freshly generated Delphi unit .o files in Win64x/Release; copying the old source objects would risk stale linking.
- RAD Studio CodeGear.Cpp.Targets defines MakeStaticPackage as a native second build pass with DCC_CBuilderOutput=JPHN and DCC_ObjOutput inherited from the runtime build. Normally this runs after the runtime package link. Added CompileVirtualTreesObjectsBeforeLink in the local VirtualTreesCR.cbproj to call that native pass before _CheckLinkDependencies for Win64x non-static builds. The inner static build is protected by _DoingStaticPackageBuild, preventing recursion.
- The updated dependency patch is stored in build/patches/VirtualTreesCR-Win64x-RAD37.patch. No build or runtime test was executed after this change, at the user's request; IDE verification is pending.
- Avoid linking old source-tree .o files; objects should be created by the native static package compilation into the build output path.

### RAD Studio native Delphi package output restored - 29 October 2026

- RAD Studio's own Save All rewrote the external TUTPackageNative.dproj and MapManagerArchiveNative.dproj into native ProjectVersion 20.3 format, removing the C++ package library-output option. The existing .lib files were stale as a result.
- Restored DCC_CBuilderOutput=All to each external Delphi project's Base PropertyGroup, avoiding duplicate Release/Debug configuration groups. Updated build/validate-rad-projects.py to accept the option in the IDE-native Base position.
- Forced /t:Rebuild for both Delphi packages PASS: TUTPackageNative.lib and MapManagerArchiveNative.lib (plus generated .hpp files) refreshed in their canonical shared and project-local output directories.
- Complete MapManager-All Win64x Release group Build repeated after fresh package libraries: PASS with 0 errors, only the two inherited ut_packages hints.
- Preserved a reproducible patch for the independent Virtual TreeView checkout in build/patches/VirtualTreesCR-Win64x-RAD37.patch. Verified the patch applies cleanly against that checkout's unmodified Git index. The active local checkout already contains the patch and was not overwritten or pushed upstream.

### Virtual TreeView Win64 Modern TLIB and clean rebuild - 29 October 2026 (latest)

- GUI Win64x Release successfully linked VirtualTreesCR.bpl but then reported TLIB error exit code 1. The Win64x TLIB task uses llvm-ar.exe to build VirtualTreesCR.lib, required by MapManager.
- An isolated forced MakeStaticPackage build succeeded, including llvm-ar and all 24 object modules. An independent VTV full Rebuild exposed a second concrete problem: the resource compiler placed VirtualTreesCR.res in the source root while the linker expected Win64x/Release/VirtualTreesCR.res.
- Updated sibling Virtual-TreeView/Packages/CBuilder 13/VirtualTreesCR.cbproj with a StageVirtualTreesCRResourceWin64x pre-link target that copies the resource into the Win64x Release intermediate directory, without regenerating or overwriting source files.
- Full VirtualTreesCR Win64x Release Rebuild PASSED, including linker and the TLIB/llvm-ar static library stage; 0 errors. Full MapManager-All Win64x Release group Build PASSED, 0 errors, two nonfatal ut_packages.pas hints.
- The TLIB GUI exit-code-1 symptom did not reproduce in command-line tests and cannot yet be conclusively attributed to the resource issue; an interactive IDE rebuild is required to verify GUI behavior. Do not turn off static package generation because the MapManager application links VirtualTreesCR.lib. Preserve unrelated MapManager DEV edits.
- The repaired Virtual TreeView project belongs to the separate local dependency checkout. Its upstream Git remote was not pushed.

### RAD Studio duplicate configuration correction - 29 October 2026 (latest)

- The previous Delphi project metadata edit mistakenly retained TWO Release and TWO Debug PropertyGroup declarations in TUTPackageNative.dproj and MapManagerArchiveNative.dproj. Although MSBuild tolerated them, RAD Studio rejected both projects with "Duplicate configuration 'Release'" and removed them from the GUI group.
- Both external Delphi .dproj files now have a single Release and Debug declaration each, with the C++ output option merged into the corresponding property group, and unique Base/Debug/Release BuildConfiguration entries.
- Added build/validate-rad-projects.py to guard against this error, validate the Delphi project personality metadata, and check project-group source references.
- Complete Win64x Release MapManager-All project group builds with zero errors, and validation script passes. IDE project reopen and Save All still require interactive confirmation; a successful MSBuild build does not verify RAD Studio's project loader.
- TUTPackage is local-only. d7zip is a separate upstream Git checkout; its local .dproj changes were not pushed upstream.

### Delphi package project metadata and Virtual TreeView name alignment - 29 October 2026

- Diagnosed the GUI project's mixed configurations: hand-authored TUTPackageNative.dproj and MapManagerArchiveNative.dproj had no BuildConfiguration records, causing RAD Studio to use Base while the runtime VirtualTreesCR.cbproj defaulted to Win32. Both Delphi package files now use the standard Base/Debug/Release configuration keys and Win64x configuration inheritance found in Embarcadero-generated projects.
- Added Delphi.Personality / BorlandProject source and platform information and ProjectFileVersion metadata missing from the hand-authored Delphi project files. The observed IDE crash stack was BaseDelphiProject.SaveFile -> Xml.XMLIniFile.WriteString / FindXmlNodeOrAdd; malformed/missing IDE metadata is a plausible cause, but an actual IDE Save All retest remains required.
- The MapManager-Components and MapManager-All group files now include the standard RAD Studio ProjectExtensions and Make targets. The runtime VirtualTreesCR project defaults to Win64x and uses a blank DllSuffix instead of $(Auto), matching the actual VirtualTreesCR.bpl produced by the linker. The old Auto suffix had led to a VirtualTreesCR370.bpl package-load mismatch in the IDE.
- Win64x Release MSBuild component group PASS, complete app group PASS, both zero build errors. The MSBuild-only MTA threading warning MSB4056 is not a C++/Delphi compilation error.
- When the IDE is already open, save any source edits individually first; then reload the Delphi project files and the entire MapManager-All.groupproj to refresh the IDE's cached metadata. The two Delphi package sources live in separate sibling folders; local external projects were not pushed to upstream GitHub.

### MapManager and dependency relocation - 29 October 2026 (latest)

- Active DEV Git checkout moved (including .git and unrelated user edits) to C:\Users\arden\source\repos\MapManager; GitHub origin remains https://github.com/ardenee/MapManager.git.
- Moved the original Virtual TreeView Git checkout and uncommitted RAD Studio project modifications from Temp to C:\Users\arden\source\repos\Virtual-TreeView; likewise moved the separate d7zip upstream Git checkout to C:\Users\arden\source\repos\d7zip, retaining patched sevenzip.pas and manual GUI package projects.
- Extracted TUTPackage sources and the standalone GUI .dproj/.dpk from MapManager to C:\Users\arden\source\repos\TUTPackage (no standalone GitHub); its previous Temp objects are under TUTPackage\Win32\Debug and TUTPackage\Win64\Release.
- Updated app .cbproj, both project groups, external Delphi .dproj/.dpk and helper .cmd to refer to sibling directories. Compiler output now goes in source project folders or standard Embarcadero locations.
- Combined GUI project group Build and separate Win64x Release app Rebuild both pass (exit code 0) from new locations. The RAD Studio IDE was open with an earlier project path during the relocation; reopen the new MapManager-All.groupproj before further GUI builds.
- Historical Temp audit/build logs were purged on request after successful verification; current instructions are in COMPONENT_BUILD_GUIDE.md.

### Settings SQLite migration and automatic database creation - 29 October 2026 (latest)

- RECOVERED: Original working settings.sqlite3 in old Map Manager/mm-setup/Win32/Debug with 12 historical tables, including Settings, GameSettings, FileTypes, Menus, filters, icons, and cache lookup types. Original cache.sqlite3 Files table recovered from two historical datasets (1491/6338 records). Original settings.sqlite3.sql is an incomplete SQL-only script; the mistakenly renamed settings.sqlite3 text copy in DEV has been restored to settings.sqlite3.sql byte-for-byte.
- Database/build_templates.py constructs versioned real SQLite templates for settings, cache, and logs from Database/legacy_settings.sql and the complete Settings/Settings.xml. The existing historical settings database schema is preserved and extended for five XML scalar fields absent from GameSettings. All 17 profiles, 35 scalar values per profile, and 119 nested section rows are present. Complete original XML structure is also stored in SettingsDocument.
- MMDatabase.h ensures all three databases are copied on first run into %LOCALAPPDATA%/MapManager (writable per-user directory). It never overwrites an existing database. Project1.cbproj stages the templates beside the Win64x executable for first run; no Python or SQL script runs on application startup.
- TMMSettings.cpp reads from SettingsDocument after migration; imports legacy Settings.xml only on first run. It no longer saves a Settings.xml file. SaveSettings writes the canonical document, selected game, active game's 35 scalar fields and seven nested sections in one transaction via correctly parameterized dbExpress ExecSQL(false). The TMMSettings destructor, called from existing form-close TMapManager destructor, calls SaveSettings.
- TMMCache.cpp initializes and opens a real cache Files SQLite database automatically. A logs.sqlite3 database is created with an empty LogEntries table, but the existing logs XML code has NOT yet been migrated.
- VALIDATED: Win64x Release Rebuild (0 errors); template integrity; 17 source XML profiles and 119 nested groups parity; SQL long-text parameter binding Delphi smoke; first-run isolated app launched and saved three databases; independent second launch without any XML file or database templates uses existing SQLite successfully; transactional save/reload in isolated DB. Actual interactive GUI close and logs migration are still open.
- Source of truth: Database/MIGRATION.md and Database/SCHEMA.md. No unrelated uncommitted DEV code was included in this migration.


### First-run database popup and XML staging - 29 October 2026

- At startup TMMSettings.cpp and TMMCache.cpp attempted to connect to Database=settings.sqlite3 and Database=cache.sqlite3 using relative paths. Neither SQLite file was present in DEV. SQLite/dbExpress produced the text "unable to open database file", which is not an application string.
- The recovered settings.sqlite3.sql does not yet define the Settings table required by GetSettings. It is an incomplete historical migration, NOT a deployable application schema.
- Settings startup now uses the executable's absolute database location, only attempts SQLite if a file exists, and checks the Settings table. If missing or invalid, it falls back to XML without a startup popup. Cache startup likewise only connects to an existing SQLite file. Failure of an existing SQLite file is reported to OutputDebugStringW for developers.
- LoadSettings only runs the preliminary SQLite query if the schema is validated. The existing Settings/Settings.xml remains authoritative for current settings and persistence.
- Win64 Modern builds stage the recovered XML into Win64x/<Config>/Settings/Settings.xml only when absent. An existing user-edited XML is not overwritten. No blank SQLite files were created or schema inferred.
- A complete Win64x Release application Rebuild passed with exit code 0 and no compile/link errors after these changes. GUI startup is not yet interactively verified. XML-to-SQLite migration and cache schema remain incomplete.

### Win64 Modern / Release compiler warning cleanup - 29 October 2026

- W1005: d7zip's Windows-only sevenzip unit was explicitly declared PLATFORM; removed the redundant hint in the local vendor copy, without changing platform-specific code or using a global suppression.
- W1023: MMArchiveEngine.GetCount compares a UInt32 archive item count to UInt32(High(Integer)) before conversion to Integer.
- W6452: LoadFilesThread.CheckUsage had switch(false), whose body could only execute the no-op case; removed dead switch while retaining progress reset.
- RAD Studio Win64x Release TUTPackageNative.dproj and MapManagerArchiveNative.dproj Rebuilds pass. The full Project1.cbproj Win64x Release Rebuild also passes (exit 0), with no W1005, W1023 or W6452. Warnings from the unrelated MSBuild MTA invocation or older TUTPackage hint may remain.
- A concurrent, uncommitted MMTypes.h edit introduced a missing comma after MM_GT_SplinterCell; corrected locally to enable full-build verification, but MMTypes.h and all other concurrent DEV edits were kept OUT of this warning-cleanup Git commit.
- Important: Removing the application's DelphiCompile entries for MMArchiveEngine/sevenzip caused unresolved MMArchiveEngine symbols, even with the separately compiled Delphi package .lib available. The entries remain in Project1.cbproj for GUI-based compilation and linking; no external command script is necessary for Win64x. Do not remove these entries until a standalone-library-only full link passes independently.

### Native RAD Studio GUI project builds - 29 October 2026 (latest)

- Win64x Release Project1.cbproj now links TUTPackageNative.lib and MapManagerArchiveNative.lib from standalone Delphi .dproj package builds. Both reside in RAD Studio's standard Dcp/Win64x search path. The issue was the absent -l:MapManagerArchiveNative.lib linker INPUT, not an object search directory.
- Disabled automatic archive batch compilation for Win64x only; retained the hook for Win32 and legacy Win64. Moved Project1.res staging to a separate pre-link target. Full clean Win64x Release application rebuild with GUI-built static package libraries PASSED (exit 0) without the archive batch.
- Created MapManager-All.groupproj for the GUI, building TUTPackageNative.dproj, MapManagerArchiveNative.dproj, VirtualTreesCR.cbproj and Project1.cbproj in sequence. Aggregate Build PASSED (exit 0).
- Manual GUI instructions in COMPONENT_BUILD_GUIDE.md supersede prior Win64x batch instructions. Runtime application features remain untested.

### Manual component IDE projects and IDE-stable archive linkage - 29 October 2026

- Added standalone RAD Studio Delphi package .dproj/.dpk pairs for TUTPackageNative and MapManagerArchiveNative plus MapManager-Components.groupproj pointing to existing third-party VirtualTreesCR.cbproj. Both packages and the aggregate group pass Win64x Release builds.
- The IDE had saved Project1.cbproj and dropped MMArchiveEngine.o from its ObjFiles, while keeping sevenzip.o. That exactly explained the missing archive facade symbols in the Win64x linker response.
- Replaced custom Win64x ObjFiles with an IDE-native static COFF MMArchiveEngine.lib (containing MMArchiveEngine.o and sevenzip.o) built by build/compile-archive-units.cmd. LinkPackageStatics now includes MMArchiveEngine.lib and TUTPackage.lib. A clean application Win64x Release Rebuild with the custom Win64x object inputs removed PASSED (exit 0).
- Introduced harmless TMapFileData.cpp/.h compatibility stubs for an IDE still referencing the historic filename; no duplicate TFileData methods. Canonical methods remain in TFileData.cpp.
- The standalone .dproj projects produce runtime BPLs and are not the static libraries that Map Manager links. See COMPONENT_BUILD_GUIDE.md. GUI/install/undo runtime acceptance remains open.
- Unrelated DEV edits to MapManager.dfm, TBuddie.cpp and TMMCache.cpp were kept untouched.

### Win64 Modern / Release clean build passed - 29 October 2026 (current)

- RAD Studio 37.0 C++ Win64x (Modern) Release **Build and clean Rebuild both PASS**, including a successful complete application link (exit 0, no errors). Valid x64 application: Win64x/Release/Project1.exe (14,949,888 bytes). Actual GUI launch, archive install/undo and persistence remain untested.
- Separate Win64x COFF dependencies are now compiled using dcc64 -jf:coffi; produces MMArchiveEngine.o, sevenzip.o and all four TUTPackage units. TUTPackage.lib created by llvm-lib.exe, instead of trying to link the legacy ELF TUTPackage.a.
- JAM Virtual TreeView C++Builder 13 Win64x Release runtime package compiled and yields VirtualTreesCR.lib and VirtualTreesCR.bpi; application modern configuration uses Win64x Release search paths.
- Project1.cbproj includes explicit Win64x Release COFF object/link/header paths, without altering the legacy Win64 or Win32 paths. build/compile-archive-units.cmd now generates these modern dependencies before linker dependency analysis.
- Modern compiler strict C++ requires removing TMMCache:: qualification from an in-class MakeListViewTable declaration (corrected).
- The historical TMapFileData.cpp/.h were redundant copies defining the same TFileData methods; their one extra DecodeMapInfoString helper was preserved in primary TFileData.cpp before deleting the duplicates. This prevents accidental duplicate classes from being compiled by stale IDE project settings; history remains in Git.
- A fresh Win64x / Release Rebuild previously failed to find Project1.res because the toolchain cleaned it without reconstructing it. The project now stages the checked-in source resource if the output is absent before linking. The existing app resource pipeline can subsequently write its generated resource.
- The project post-link step stages the installed official 64-bit 7z.dll into Win64x/Release when available from C:\Program Files\7-Zip\7z.dll; verified both application and DLL PE architecture x64 (0x8664).
- RAD Studio was open before some project-file changes. If the IDE reports the historical ELF/archive or TFileData duplicate errors, close and reopen Project1.cbproj to reload the actual modern project settings. Do not open historical Project1.bpr or Project1.bdsproj.
- Verified log: C:\Temp\MapManagerDeps\mapmanager-win64x-release-clean-rebuild.log. Still needs Win64x GUI/runtime and functional acceptance; compiler warnings are tracked separately.


### IDE stale-project diagnosis and duplicate-source cleanup - 29 October 2026

- The reported linker errors (unresolved TMMArchiveEngine vtable and duplicate TFileData) match the older pre-fix project configuration. On DEV, RAD Studio bds.exe started at 13:20, before Project1.cbproj's 14:36 modifications. The IDE later recompiled TMapFileData.o at 14:45 although the on-disk cbproj no longer includes TMapFileData.cpp. This strongly indicates an IDE instance holding the older in-memory project configuration.
- The on-disk Project1.cbproj includes platform-scoped ObjFiles for MMArchiveEngine and sevenzip, a LibFiles reference for Win64 TUTPackage.a, and a before-link dependency compilation target. A command-line Win64 Debug build previously passed with these settings. Reload Project1.cbproj in RAD Studio to load them; opening legacy Project1.bdsproj or Project1.bpr is not equivalent.
- TMapFileData.cpp and TMapFileData.h were historical duplicate definitions of TFileData. Their unique method, DecodeMapInfoString, was preserved in canonical TFileData.cpp as a delegating method. The redundant source/header have now been deleted (recoverable through Git history), preventing future duplication.
- No change was made to RAD Studio's running process or unsaved IDE state. A reloaded IDE is required; otherwise the old project remains resident and may continue generating obsolete object files.

# Map Manager — recovery checkpoint

**Date:** 29 October 2026  
**Current phase:** Win64 build recovered; runtime and Win32 integration validation outstanding
**Build status:** Win64 Debug C++Builder build passes (normal and forced-link). **Release readiness:** no runtime-validated release.

### Win64 Debug linker resolved - 29 October 2026 (latest)

- Win64 Debug C++Builder 37.0 full build PASSED (MSBuild exit 0). Win64/Debug/Project1.exe exists and is a valid x64 PE image (~54 MB). App startup has NOT been tested.
- MMArchiveEngine.o and sevenzip.o existed but were not linked. New ObjFiles entries in Project1.cbproj include both platform-specific Win64 .o and Win32 .obj outputs.
- An earlier ILINK_AdditionalLibs override disabled RAD Studio's default C++ runtime and Windows import libraries. TUTPackage.a now uses LibFiles, retaining the defaults.
- Duplicate TMapFileData.cpp was already excluded from CppCompile, and its stale Win64 Debug .o and .d were removed. The source file remains untouched.
- Archive Delphi compilation hook now executes before _CheckLinkDependencies, not after dependency determination.
- Win32 full build, Win64 GUI startup, and all archive installer/rollback acceptance tests remain open. Warning cleanup and portable dependency paths remain future work.
- Latest detailed checkpoint: ARCHIVE_MIGRATION.md.

## Baseline and preservation

- Recovery workspace selected from the 2017-era `mm-setup2` C++Builder/VCL source.
- Original source/archives were preserved separately; the public repository holds a curated development copy, not all historical backups.
- Recovered modules include map, archive, installer, package, multimedia, settings/XML, file and log support. Features require runtime validation after a clean build.

## Verified results

| Gate | Result |
| --- | --- |
| Virtual TreeView C++Builder 13 Win32 runtime `VirtualTreesCR` | **PASS** — RAD Studio 37.0 |
| Virtual TreeView design-time `VirtualTreesCD` and registration | **PASS** on DEV |
| TUTPackage Win32 `ut_packages`, `ut_umods`, `ut_uz`, `utpkgnat_ut2004` | **PASS** — source compilation |
| TUTPackage Win32 `TUTPackage.lib` | **PASS** — static archive built |
| d7zip `sevenzip.pas` Delphi 37.0 Win32 | **PASS** — source compilation / generated `sevenzip.hpp` |
| ZIP and 7z archive listing and extraction using native in-process DLL | **PASS** — standalone tests |
| Legacy RAR reading/extraction using in-process DLL | **PASS** — 34 entries enumerated, 30 files extracted to memory (604,898 uncompressed bytes) |
| ZIP and 7z creation, reopen and read-back using d7zip API | **PASS** |
| RAR5 with a real fixture | **NOT TESTED** |
| Full Map Manager Win32 application compilation | **FAIL** — compiler/Windows SDK/generated-header errors |
| Application startup, UI, archive integration and installation/rollback | **NOT TESTED** |
| XML-to-SQLite initialization/import/parity | **INCOMPLETE** |

**Scope note:** the d7zip proof was built as a separate native Delphi program. It does not prove Map Manager uses the library yet.

## Active blockers

1. `Project1.cbproj` mixes older and modern C++Builder settings. Modern Win32 compilation encounters `Winapi.ShlObj.hpp` and `PROPVARIANT`/Windows SDK incompatibilities. The project still contains machine-specific paths.
2. Old ZipBuilder and TDFUnRar libraries and calls are still active in `TMMArchives`, `TMMFileInfoThread` and `TMMInstallThread`. Replace them with d7zip *before* removing them.
3. TUTPackage compiled units are not yet linked and exercised through a functioning application.
4. The SQLite implementation lacks verified schema creation/default inserts/legacy XML import.
5. Full historical features cannot be accepted without a clean application start and regression tests.

## Next work (in order)

1. Fix Win32 compiler, generated-header and package/project path issues. Achieve application startup.
2. Implement and integrate one safe **in-process** d7zip archive API for ZIP, RAR4, RAR5, 7z; support enumeration, extraction, passwords, cancellation/progress, secure staging and rollback.
3. Replace old ZIP/RAR component calls and remove those libraries only after parity passes.
4. Finish versioned SQLite creation and migration from XML; prove data and functionality parity.
5. Test UI, map/package handling, multimedia, installs, failures, recovery and delivery; prepare Win32 development release.

## Constraints

- Never launch external archive apps (`7z.exe`, WinRAR) from Map Manager.
- Never publish personal settings, development binaries or proprietary game assets.
- Preserve third-party MPL 1.1 attribution and upstream licensing.
- Test changes against a bounded list and update statuses after each meaningful test batch.

Dependency details and project roadmap are in [README.md](README.md).

## SDK and Win64 evidence — 29 October 2026

- RAD Studio 37.0 accepts only Windows SDK header builds 10.0.26100.4948, .4654 and .4188; the installed 10.0.26100.0 directory's header revision is rejected by the official SDK patch tool. 10.0.28000.0 is not supported by RAD Studio's current sdk.versions file.
- Official Microsoft 10.0.26100.4654 SDK installer downloaded and digital signature verified at C:\Temp\MapManagerDeps\WindowsSDK-26100-4654\winsdksetup.exe. **NOT installed**. No installed SDKs removed or system headers patched.
- Removed the recovery-specific 10.0.19041.0 forced SDK header include paths from Project1.cbproj. This avoids mixing old SDK headers with RAD Studio-managed patched SDK once it is set up.
- d7zip and all four recovered TUTPackage units compile on Win64. A Win64 TUTPackage.a static archive was built. 64-bit d7zip successfully listed/extracted ZIP/7z/RAR and created/read-back ZIP/7z using the 64-bit 7z.dll.
- Generated Win64 headers staged under TUTPackage/generated/Win64 and ThirdParty/d7zip/generated/Win64. The Win64 Virtual TreeView C++ package compilation remains blocked on unsupported SDK header stralign.h after Delphi units compile.
- Full application build and Win64 IDE design-time package registration are **not** completed.

Detailed instructions: [RAD Studio SDK and Win64 setup](RAD_STUDIO_SDK_AND_WIN64.md).

### SDK remediation update — 29 October 2026

- Installed SDK .4654 now matches required CRC32, RAD patchsdk exit 0; patched headers copied into RAD Studio 37.0 SDK folder (excpt.h preserved).
- MapManager Win32 build advances beyond SDK errors but remains blocked by DFUnRar.hpp, ZipBuilder.h and TUTPackage C++ header paths.
- Virtual TreeView Win64 C++ runtime package now builds; VirtualTreesCR.a, VirtualTreesCR.bpi and VirtualTreesCR.bpl generated locally.
- GUI SDK wizard not independently retested; SDK 28000 remains installed and must not be selected. Select 26100.0 in IDE if prompted.

### Archive component replacement — 29 October 2026

- Removed ZipBuilder and TDFUnRar includes, types, allocations, callbacks, link libraries, and obsolete include paths from active application source. ZIP/RAR/7z now use in-process 7z.dll via MMArchiveEngine.pas and d7zip/sevenzip.pas.
- Updated two archive listing paths, file-information thread and two installer generations. The newer TMMArchives::Install code path was already disabled, and is still disabled.
- Extraction rejects directory traversal, ADS, drive-absolute paths, and Windows reserved names, validates reparse-point ancestry, and stages members before promotion. ZIP/7z/RAR4 native smoke tests pass on Win32 and Win64; ZIP-SFX smoke test passes Win32; Win32 malformed path tests pass.
- Win32 and Win64 MapManagerArchiveDelphiObjects MSBuild targets pass. Full C++ app builds remain blocked by pre-existing TMMSettings.cpp Clang-incompatible try blocks, outside archiver migration.
- RAR5, encrypted/multipart archives, UI progress/cancellation, and end-to-end installer/undo/log behavior remain unverified. Full integration cannot be marked accepted.
- Details: ARCHIVE_MIGRATION.md.

### RAD Studio 37.0 exception syntax fix and Win64 linking — 29 October 2026

- Replaced nine active SEH __try keywords with standard C++ try in TMMSettings.cpp, retaining their existing catch (Exception& E) handlers unchanged. Original file backed up to C:\Temp\MapManagerDeps\TMMSettings-before-catch-fix-20261029.cpp.
- Win64 compilation confirmed it passes the previous E35/E2595 errors at lines 232, 569, 601, 645, 711, 751, 797, 841, 885.
- Adjusted Win64 Debug library search to prefer VirtualTreeView Win64 Release .bpi; full Win64 link confirmed the previous invalid Win32 VirtualTreesCR.bpi error is no longer present.
- Detected duplicate TFileData definitions in TFileData.cpp and TMapFileData.cpp; excluded TMapFileData.cpp from the project build without deleting source. Linked Win64 TUTPackage.a as a separate static library, resolving earlier Ut_packages/Ut_umods symbols.
- Full Win64 application build remains BLOCKED at linker by multiple missing standard runtime/Windows import symbols (GetModuleHandleW, C++ exception / standard library support, etc.). No application runtime acceptance. Build evidence: C:\Temp\MapManagerDeps\mm-archive-migration-win64.log. Current changes remain local/uncommitted.
