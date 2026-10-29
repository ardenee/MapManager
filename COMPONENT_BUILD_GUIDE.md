# MapManager components - RAD Studio 37.0

## Active development source layout

- Application: `C:\Users\arden\source\repos\MapManager`
- Unreal package reader: `C:\Users\arden\source\repos\TUTPackage`
- Archive wrapper: `C:\Users\arden\source\repos\d7zip`
- Virtual TreeView: `C:\Users\arden\source\repos\Virtual-TreeView`

Open **MapManager-All.groupproj** for application and components, or
**MapManager-Components.groupproj** for only dependencies, in RAD Studio.
Choose **Win64 Modern / Release**.

## Active Win64 Modern project group

| Project | GUI project |
| --- | --- |
| Unreal package reader | `..\TUTPackage\TUTPackageNative.dproj` |
| Archive wrapper | `..\d7zip\MapManagerArchiveNative.dproj` |
| Virtual TreeView runtime | `..\Virtual-TreeView\Packages\CBuilder 13\VirtualTreesCR.dproj` |
| MapManager | `Project1.cbproj` |

The Virtual TreeView runtime now uses a **native Delphi** .dproj and .dpk,
not the older VirtualTreesCR.cbproj C++Builder runtime wrapper. The native
package is named VirtualTreesCR, includes the exact 22 original Pascal units
and requires rtl, vcl, vclx and vclimg. C/C++ file generation is enabled
for the required BPL, BPI, LIB and HPP outputs.

Why: the C++Builder wrapper's RAD Studio Win64x GUI build consistently failed
to generate 22 Delphi object files before linking; object-path and build-order
workarounds did not resolve it. The native Delphi package uses the same
package format that works for TUTPackage and d7zip. The new native VTV
package is not yet build-verified; the user will test from the IDE.

The older VirtualTreesCR.cbproj and VirtualTreesCD.cbproj remain in the
Virtual TreeView source tree, untouched by this switch, for other targets.

## Output locations

- TUTPackage and d7zip: their source project output and RAD Studio's default
  shared DCP/BPL folders.
- Native VTV generated headers and DCUs: under
  `Virtual-TreeView\Packages\CBuilder 13\Win64x\Release`.
- Shared package BPL/BPI and Delphi package static LIB:
  `C:\Users\Public\Documents\Embarcadero\Studio\37.0\Bpl\Win64x`
  and `...\Dcp\Win64x`.
- MapManager: `MapManager\Win64x\Release\Project1.exe`.

MapManager's Win64x compiler include path includes the native VTV header
output directory. The VirtualTreesCR package name is unchanged, so the
existing references to VirtualTreesCR.lib and VirtualTreesCR.bpi remain.

## Fresh checkout

Virtual TreeView is a separate Git checkout. From the clean Virtual
TreeView root, apply MapManager's
`build/patches/VirtualTreesCR-Native-Win64x.patch` if the native project
is missing. Do not apply this patch to DEV, where the files already exist.

TUTPackage is local-only; d7zip and Virtual TreeView have separate Git
histories. MapManager's GitHub push does not push external upstream repos.

## Static project validation

From the MapManager root, use `py -3 build\validate-rad-projects.py` to
check that the Delphi projects have exactly one Base, Debug and Release
configuration, C/C++ output enabled, the native VTV group references, and
all 22 VTV source units present. This is not a build test.

Save any source edits individually, then close and reopen
MapManager-All.groupproj to load the new project structure in RAD Studio.


## Native Virtual TreeView generated header and linker names (29 October 2026)

The native Delphi VirtualTreesCR package defines MAPMANAGER_VTV_NATIVE under
its Base compiler settings. Source/VirtualTrees.BaseTree.pas emits
VirtualTreesCR instead of the upstream Delphi package's VirtualTreesR
auto-link pragma when this symbol is present. This prevents Project1 from
implicitly requesting an unbuilt VirtualTreesR.lib after the linker already
selects VirtualTreesCR.lib.

Pascal unit names/imports were also normalized to Vcl rather than VCL for
VirtualTrees.AncestorVcl and VirtualTrees.BaseAncestorVcl, matching the
physical source and generated header filenames. MapManager.h uses this
same casing. The source changes, plus the native Delphi package project,
are stored in build/patches/VirtualTreesCR-Native-Win64x.patch for a
fresh Virtual TreeView checkout; do not apply it again on the active DEV.

Generated .hpp files must be refreshed by rebuilding the native Delphi
VirtualTreesCR package before building Project1. Do not edit generated
headers or work around the missing VirtualTreesR.lib by adding an unrelated
legacy library. These changes are statically validated, not yet GUI tested.
