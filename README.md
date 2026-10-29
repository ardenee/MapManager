# Map Manager

**Map Manager** is the recovery and modernization of a Windows C++Builder/VCL
application for browsing, cataloguing, installing and managing Unreal and Unreal
Tournament content: maps, packages, textures, music, demos, screenshots,
favourites, servers, logs and files.

## Current status - 29 October 2026

**Primary target:** RAD Studio 13 / Studio 37.0, **Win64 Modern / Release**
(`Win64x` / `Release`).

The developer has confirmed that the three native Delphi component packages and
the full Map Manager application build in the RAD Studio IDE. This is a
**successful build milestone, not production/runtime certification**.

| Area | State |
| --- | --- |
| Win64 Modern / Release | **IDE build/link reported working** |
| Virtual TreeView | Native Delphi `VirtualTreesCR.dproj` and `VirtualTreesCR.lib` |
| TUTPackage Unreal reader | Native Delphi `TUTPackageNative.dproj` / `TUTPackageNative.lib` |
| d7zip archive integration | Native Delphi `MapManagerArchiveNative.dproj` / `MapManagerArchiveNative.lib` |
| Win32 / legacy Win64 | Historical targets; not the currently certified build configuration |
| SQLite settings | Implementation and migration tests exist; GUI, logs and persistence acceptance remain |
| Functional/release testing | **Incomplete:** install/undo, archive failure handling, UI, fresh deployment and rollback |

See [PROJECT_STATUS.md](PROJECT_STATUS.md) for evidence, [ARCHIVE_MIGRATION.md](ARCHIVE_MIGRATION.md)
for archive changes, and [COMPONENT_BUILD_GUIDE.md](COMPONENT_BUILD_GUIDE.md)
for RAD Studio configuration details.

> **Clean-clone limitation:** The compatible modified `TUTPackage` source and
> `TUTPackageNative.dproj/.dpk` remain in a local development folder and are
> **not yet published to GitHub**. A new contributor must obtain that same
> source tree separately before the complete project can be compiled.
> Cloning just the three Git repositories below is currently insufficient.

## Building on Windows - Win64 Modern / Release

### Prerequisites

- [RAD Studio / C++Builder 13 (Studio 37.0)](https://www.embarcadero.com/products/rad-studio),
  including the Win64 Modern C++Builder toolchain, Delphi compiler,
  VCL, XML, dbExpress and DataSnap components referenced by the project.
- A compatible Windows SDK. Development used SDK `10.0.26100.4654` with
  **local SDK compatibility fixes**, detailed in
  [RAD_STUDIO_SDK_AND_WIN64.md](RAD_STUDIO_SDK_AND_WIN64.md). A pristine SDK
  installation on another PC has not been independently confirmed.
- Git and Python 3 (for the project configuration validator).
- A matching **64-bit** `7z.dll` from 7-Zip, available separately.
- The compatible modified `TUTPackage` project and source files.

The RAD Studio project groups rely on the following **sibling layout**. The
workspace itself can be on any drive:

```
workspace/
+-- MapManager/           # This Git repository
+-- TUTPackage/           # Required; unpublished local dependency
|   +-- TUTPackageNative.dproj
|   +-- TUTPackageNative.dpk
|   +-- ut_packages.pas
|   +-- ut_umods.pas
|   +-- ut_uz.pas
|   +-- utpkgnat_ut2004.pas
+-- d7zip/                # Pinned upstream + integration patch
+-- Virtual-TreeView/     # Pinned upstream + integration patch
```

### 1. Clone and patch the external sources

Run in **PowerShell** from a new workspace folder:

```powershell
mkdir MapManager-workspace
cd MapManager-workspace

git clone https://github.com/ardenee/MapManager.git
git clone https://github.com/JAM-Software/Virtual-TreeView.git
git clone https://github.com/geoffsmith82/d7zip.git

# Tested upstream revisions for the integration patches.
git -C Virtual-TreeView checkout 2a8aef8
git -C d7zip checkout 38bee12

# Both patch paths are relative to the dependency repositories.
git -C Virtual-TreeView apply ../MapManager/build/patches/VirtualTreesCR-Native-Win64x.patch
git -C d7zip apply ../MapManager/build/patches/d7zip-MapManagerArchiveNative-RAD37.patch
```

The two patches have been verified to apply against those pinned, unmodified
upstream Git indexes. Do not apply them twice. Newer upstream revisions may
need different patches; do not push Map Manager-specific fixes into the
maintainers' upstream repositories by accident.

**Supply TUTPackage:** Place the compatible source folder beside MapManager
as `workspace/TUTPackage/`. It must include `TUTPackageNative.dproj`,
`TUTPackageNative.dpk`, and the four Pascal files shown above. The original
[UT Packages SourceForge project](https://sourceforge.net/projects/utpackages/)
is useful for source provenance, **not a verified drop-in replacement**
for the modified local RAD Studio 13 package.

### 2. Dependency changes made during modernization

| Dependency | Current integration |
| --- | --- |
| **Virtual TreeView** | The component group now uses `VirtualTreesCR.dproj/.dpk` (all 22 original Pascal units), **not** the old mixed C++Builder `VirtualTreesCR.cbproj` runtime. The patched Delphi package generates the BPL/BPI, static `VirtualTreesCR.lib` and C++ `.hpp` files. |
| **VTV compiler/link fixes** | `MAPMANAGER_VTV_NATIVE` selects `VirtualTreesCR` rather than the obsolete `VirtualTreesR.lib` in generated link directives. The patch also corrects `IF`/`IFEND`, the `Synchronize` callback type, and `VCL`/`Vcl` header-name casing. |
| **d7zip** | The patch adds `MapManagerArchiveNative.dproj/.dpk` for upstream `sevenzip.pas` plus MapManager's `MMArchiveEngine.pas`, and removes its unnecessary `platform` unit annotation. |
| **TUTPackage** | Its local native Delphi package builds the Unreal package/UMOD/UZ readers. **Win64x links `TUTPackageNative.lib`**, never the obsolete Win32 `TUTPackage.lib`. |
| **7-Zip** | The app uses a separate `7z.dll` in-process for ZIP/RAR/7z. It does **not** invoke `7z.exe` to process archives. |

On the tested installation, package `.lib` and `.bpi` outputs are generated
under `C:\Users\Public\Documents\Embarcadero\Studio\37.0\Dcp\Win64x`, and
`.bpl` outputs under `...\Bpl\Win64x`. Native Delphi `.hpp` and `.dcu`
outputs also appear in dependency-local `Win64x\Release` directories.
Do not commit compiled libraries or generated headers.

### 3. Validate and build the projects

From `workspace/MapManager`:

```powershell
py -3 build\validate-rad-projects.py
```

This validates the Delphi project metadata, group references and all 22
Virtual TreeView source-unit paths. **It does not compile any components.**

In RAD Studio:

1. Open `MapManager-All.groupproj` (or `MapManager-Components.groupproj`
   if only rebuilding the dependencies).
2. Set **Win64 Modern / Release** (`Win64x` / `Release`).
3. Build `TUTPackageNative.dproj`, `MapManagerArchiveNative.dproj` and
   `VirtualTreesCR.dproj`, then `Project1.cbproj`. Building the whole
   application group follows that dependency order.
4. The application output is `MapManager\Win64x\Release\Project1.exe`.

After externally editing any `.dproj`, `.cbproj` or `.groupproj` file,
save unsaved source work, close the project group and reopen it so the IDE
does not use stale project metadata.

### 4. Supply the runtime DLL

The `Project1.cbproj` Win64x post-link target attempts to copy
`C:\Program Files\7-Zip\7z.dll` to the application output directory, **only
if that input file exists**. If the DLL was not staged, place the matching
**x64** `7z.dll` beside `Project1.exe` manually. The runtime DLL is not
committed to Git.

### Troubleshooting

| Issue | Diagnosis / action |
| --- | --- |
| Missing `VirtualTreesR.lib` | Stale generated `VirtualTrees.BaseTree.hpp` may still request the old package. Rebuild native `VirtualTreesCR.dproj` and confirm that the header requests `VirtualTreesCR`. Do not patch generated headers by hand. |
| Missing `VirtualTrees.*.o` | The wrong runtime wrapper was built. The current group must reference `VirtualTreesCR.dproj`, not `VirtualTreesCR.cbproj`. |
| Nonportable include-case warnings | Regenerate the patched `VirtualTrees.*.hpp` files; the Pascal `Vcl` unit names must match header filename casing. |
| Missing `TUTPackage.lib` | It is a **Win32 legacy name**. Win64x requires `TUTPackageNative.lib` in the standard RAD Studio DCP search path. |
| Missing `TUTPackageNative.dproj` | The unpublished sibling `TUTPackage` source tree has not been supplied. |
| Missing `7z.dll` | Install/supply the right x64 DLL; the post-link copy only runs if the default source path exists. |
| Command-line build differs from IDE | Reload project group metadata; check actual compiler/linker input paths before applying global SDK or output-directory workarounds. |

## Architecture and remaining work

The source includes game-specific Unreal package readers, VCL forms for
browsing content, a consolidated `MMArchiveEngine.pas` archive layer, and
a partially modernized settings/logging system.

- **Archive handling:** Active source replaced legacy ZipBuilder/TDFUnRar
  integration with d7zip and a 64-bit `7z.dll`. Standalone ZIP, 7z and RAR
  tests have passed. RAR5, hostile archive paths, interactive installation,
  failure recovery, cancellation and uninstall/undo still require acceptance.
- **Settings and persistence:** SQLite settings/cache/logs databases are
  created under `%LOCALAPPDATA%\MapManager`. XML migration, schema/profile
  coverage and isolated persistence tests exist, but interactive GUI
  close/reopen, log migration and clean-machine deployment remain open.
- **Game/UI features:** Map, file, texture, music, demo and screenshot views,
  favourites, servers, file operations, history and caching need application
  regression testing.
- **Release readiness:** A successful Win64x build is only the first gate.
  Functional acceptance, installer verification, error paths, deployment
  and full dependency-source reproducibility are outstanding.

See [Database/MIGRATION.md](Database/MIGRATION.md),
[Database/SCHEMA.md](Database/SCHEMA.md),
[PROJECT_STATUS.md](PROJECT_STATUS.md) and
[ARCHIVE_MIGRATION.md](ARCHIVE_MIGRATION.md).

## Repository contents and licensing

This repository tracks Map Manager source, RAD Studio project groups,
documentation, and **patches for pinned upstream dependencies**.
Developer-specific settings, archives, databases, generated binaries and
compiler outputs are deliberately ignored. The original Virtual TreeView
and d7zip repositories are **not vendored**. The modified TUTPackage source
is not yet publicly backed up by this repository.

- [Virtual TreeView](https://github.com/JAM-Software/Virtual-TreeView):
  use its upstream license and attribution.
- [d7zip](https://github.com/geoffsmith82/d7zip):
  Mozilla Public License 1.1; preserve upstream copyright notices.
- [UT Packages](https://sourceforge.net/projects/utpackages/):
  recovered Pascal source by Antonio Cordero Balcazar and contributors;
  existing local source carries MPL 1.1 licensing.
- [7-Zip](https://www.7-zip.org/):
  separately obtained runtime; heed upstream 7-Zip and RAR/unRAR
  redistribution licensing. Do not commit third-party DLLs without review.
- Unreal game content is not distributed with the source; users must have
  appropriate rights to use or redistribute their own assets.
