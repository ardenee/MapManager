# MapManager - build components in RAD Studio 37.0

## Repositories and locations

The active app source is `C:\Users\arden\source\repos\MapManager`.
Its GitHub origin remains `https://github.com/ardenee/MapManager.git`.

| Component | GUI project file |
| --- | --- |
| TUTPackage (local source, no standalone GitHub) | `C:\Users\arden\source\repos\TUTPackage\TUTPackageNative.dproj` |
| d7zip, patched for MapManager | `C:\Users\arden\source\repos\d7zip\MapManagerArchiveNative.dproj` |
| JAM Virtual TreeView | `C:\Users\arden\source\repos\Virtual-TreeView\Packages\CBuilder 13\VirtualTreesCR.cbproj` |
| MapManager app | `C:\Users\arden\source\repos\MapManager\Project1.cbproj` |

Open `C:\Users\arden\source\repos\MapManager\MapManager-All.groupproj` in RAD Studio.
Choose **Win64 Modern / Release** and select Build All Projects. The
`MapManager-Components.groupproj` group builds only the dependencies.
You may also open and build each component project independently.

## Generated files

- TUTPackage Pascal object/DCU/HPP: `TUTPackage\Win64x\Release`.
- d7zip Pascal object/DCU/HPP: `d7zip\Win64x\Release`.
- Virtual TreeView: its own `Packages\CBuilder 13\Win64x\Release`.
- RAD Studio default shared outputs: `C:\Users\Public\Documents\Embarcadero\Studio\37.0\hpp`, `Bpl`, and `Dcp`.
- Package link libraries `TUTPackageNative.lib` and `MapManagerArchiveNative.lib`: Embarcadero shared `Dcp\Win64x`.
- MapManager application `Win64x\Release\Project1.exe` and its C++ objects: the MapManager project folder.

The temporary MapManagerDeps and MapManagerAudit directories are not needed for
builds and were removed after build verification. Win64x uses COFF libraries,
not old Win64 ELF .a libraries. The legacy Win32/Win64 helper
`build\compile-archive-units.cmd` has also been updated for sibling sources.

## Notes about separate projects

Virtual TreeView and d7zip are separate upstream Git checkouts, with local RAD Studio
modifications preserved. Their upstream remotes were not pushed.
TUTPackage is local-only without its own Git repository.

MapManager's own Git history still contains the earlier copies of those sources;
the current checkout references the sibling trees, so a fresh clone requires
setting them up on the new machine. The patch in external d7zip's `sevenzip.pas`
and its MapManager-specific `.dproj` / `.dpk` belong to that local checkout.

Keep the application DelphiCompile entries for `MMArchiveEngine.pas` and
`..\d7zip\sevenzip.pas`. Removing them previously caused linker failures.

## Correct GUI build configurations and project-saving

All three components in the project group are configured for **Win64 Modern (Win64x) / Release**.
TUTPackageNative.dproj and MapManagerArchiveNative.dproj use standard RAD Studio
BuildConfiguration entries (Base, Debug, Release) and Delphi project metadata.
VirtualTreesCR.cbproj defaults to Win64x and builds VirtualTreesCR.bpl with no
version suffix, matching its runtime output.

If the IDE previously showed Base/Win64x for Delphi packages, Win32/Release for
Virtual TreeView, VirtualTreesCR370.bpl missing, or crashed while saving a Delphi
project in Xml.XMLIniFile, close and reopen the project group so RAD Studio
reloads the corrected project files. Save modified .cpp/.pas/.dfm source files
individually before closing any IDE session with unsaved edits.

Win64x Release component-group and full-application group MSBuild builds passed,
but the *IDE's own Save All action* still needs interactive confirmation.

If the IDE shows Duplicate configuration 'Release', close the failed group and
reopen the project group after updating the external Delphi .dproj files. The
previous error arose from two PropertyGroup declarations per Release/Debug
configuration and has been corrected locally on DEV. To validate the projects
before opening RAD Studio, run:

    py -3 build\validate-rad-projects.py

Command-line builds do not test the IDE's own project-loading or Save All path.

## Virtual TreeView Win64 Modern package and static library

The VirtualTreesCR.cbproj project generates VirtualTreesCR.bpl and also
Win64x/Release/VirtualTreesCR.lib, needed by the MapManager executable.
Do not disable the Generate static package library option. RAD Studio
uses its TLIB task (llvm-ar.exe for Win64 Modern) to build the library.

The dependency checkout contains a StageVirtualTreesCRResourceWin64x
pre-link target. It stages the project-root resource compiled by RC
into Win64x/Release/VirtualTreesCR.res, where the Win64x linker expects
it. This fixes a reproducible full-rebuild error.

The full VTV Rebuild and complete MapManager-All group Build passed
in the RAD Studio command-line environment with zero errors, including
the TLIB static library generation. The earlier GUI TLIB exit-code-1
error was not reproduced separately; retry in the IDE to confirm.
If it recurs, preserve the first llvm-ar or tlib stderr line.


For a fresh clone of the standalone Virtual TreeView Git checkout,
apply the MapManager-owned RAD Studio 37.0 integration patch
(build/patches/VirtualTreesCR-Win64x-RAD37.patch) from the clean
Virtual-TreeView source checkout. It captures the default Win64x platform,
the runtime BPL naming fix, local SDK include path and the resource staging
target. Do not reapply it to the already modified DEV checkout.

The Delphi component packages must have Delphi Compiler / Output - C/C++
set to All. RAD Studio's IDE can regenerate the .dproj files during Save All,
so this option is now stored in their Base configuration (the standard
IDE-native location). build/validate-rad-projects.py checks that both
packages still have the setting and their Release/Debug configurations
remain unique. Both .lib files were regenerated in a clean Win64x Release
build on 29 October 2026.
