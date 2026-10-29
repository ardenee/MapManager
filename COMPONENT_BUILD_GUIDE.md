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
