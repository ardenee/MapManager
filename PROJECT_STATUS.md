# Map Manager — recovery checkpoint

**Date:** 29 October 2026  
**Current phase:** source recovery / Win32 dependency modernization  
**Release readiness:** no buildable or validated application release.

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
