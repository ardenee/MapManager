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
package was subsequently reported to build successfully by the user in RAD Studio 37.0 Win64 Modern / Release.

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
legacy library. The user subsequently confirmed the IDE build is working.

## Native VirtualTreesCR Delphi compiler corrections (29 October 2026)

The earlier native project emitted an E2029 compile error due to an incorrect
ENDIF closing an IF conditional in VirtualTrees.BaseTree.pas. This was fixed
to IFEND. An E2250 Synchronize overload ambiguity in
VirtualTrees.WorkerThread.pas was addressed by passing a typed TThreadProcedure
to TThread.Synchronize. The native Delphi project define no longer appends
an empty DCC_Define (avoiding a doubled semicolon in the compiler command).

All fixes are included in build/patches/VirtualTreesCR-Native-Win64x.patch.
The user subsequently reported the Win64 Modern / Release component and application builds working. Full runtime behavior remains to be validated separately.


## Pinned external dependencies for a new DEV checkout

For a fresh standalone Virtual TreeView clone at JAM-Software upstream revision
2a8aef8, apply MapManager's build/patches/VirtualTreesCR-Native-Win64x.patch
from the Virtual-TreeView root before loading the RAD Studio project group.
This patch adds VirtualTreesCR.dproj/.dpk and the Pascal source corrections.

For a fresh d7zip clone at geoffsmith82 upstream revision 38bee12, apply
MapManager's build/patches/d7zip-MapManagerArchiveNative-RAD37.patch from the
d7zip root. The patch adds MapManagerArchiveNative.dproj/.dpk and removes
the redundant Delphi PLATFORM annotation in sevenzip.pas. Both patch files
have been checked against the unchanged upstream Git indexes.

TUTPackage is currently **local-only** in the sibling folder; its source
files are not tracked in the MapManager repository and are ignored in the
unrelated parent Git working tree. Thus this GitHub sync preserves the
MapManager code and the two third-party integrations, but does not yet
make a clean machine capable of rebuilding without access to TUTPackage.
Do not commit the generated binary .lib/.bpl/.hpp files.
