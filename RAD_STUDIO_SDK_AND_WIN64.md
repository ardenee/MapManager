# RAD Studio 37.0 — Windows SDK and Win64 recovery

Verified on DEV (game-amd): 29 October 2026.

## Windows SDK mismatch confirmed

RAD Studio's error is: "Unable to determine SDK version. Supported SDK versions: 10.0.26100.4948, 10.0.26100.4654, 10.0.26100.4188."

Installed Windows Kits folders include 10.0.19041.0, 10.0.26100.0 and 10.0.28000.0, but the installed 26100 headers do not match one of the supported servicing versions. Folder naming 10.0.26100.0 does NOT prove the header servicing level.

The official RAD Studio patches SDK headers into its own SDK directory. An isolated test of C:\Program Files (x86)\Embarcadero\Studio\37.0\bin\windows\patchsdk\patchsdk.exe using the installed 26100 SDK was rejected (exit 1, same error), without modifying RAD Studio. The built-in RAD staging folder at include\windows\sdk currently contains only excpt.h.

## Recommended SDK repair (not yet executed)

1. Close RAD Studio and any SDK wizard.
2. Install the supported Windows 11 SDK 10.0.26100.4654 (July 2025), rather than 10.0.28000. Embarcadero confirms this as its preferred SDK.
3. The official installer has been DOWNLOADED and signature-verified, but NOT RUN:
   C:\Temp\MapManagerDeps\WindowsSDK-26100-4654\winsdksetup.exe
   Product version 10.1.26100.4654; Authenticode status Valid; signed Microsoft Corporation.
   SHA256 383B0581F8F1A5C58A8C22E9126869A4858632DFD996AFE640EFD077FA57C8BE
4. Embarcadero instructs users to uninstall existing conflicting SDK installations before installing a supported SDK. This can affect other projects: no SDK uninstallation has been performed. Do not wipe SDK versions without first checking projects relying on them.
5. Choose SDK for Desktop C++ x86 Apps and amd64 Apps, as Embarcadero recommends.
6. Run the 32-bit RAD Studio IDE elevated for the initial header-patching step. First create and build a NEW minimal C++Builder VCL Win32 app. Approve the SDK copy/patch prompts. Check that BDS include\windows\sdk is now populated and that the blank app builds.
7. Then build the recovered Map Manager. The recovery-specific explicit 10.0.19041.0 header directories were removed from Project1.cbproj, to avoid mixing SDK revisions. Other historical paths and source compatibility issues may remain.
8. Only if official automatic setup fails with the now-supported SDK, follow Embarcadero's documented manual patch procedure with an IDE SDK folder backup. Never fake the checksum in sdk.versions.

Official references:
https://docwiki.embarcadero.com/RADStudio/Florence/en/Windows_SDK_Installation
https://docwiki.embarcadero.com/Support/en/Manually_installing_Windows_SDK
https://learn.microsoft.com/en-us/windows/apps/windows-sdk/downloads

## Verified platform support

| Check | Win32 | Win64 |
| --- | --- | --- |
| d7zip sevenzip.pas compiles | PASS | PASS, dcc64 |
| TUTPackage ut_packages, ut_umods, ut_uz, utpkgnat_ut2004 compile | PASS | PASS, dcc64 |
| TUTPackage static library | PASS, TUTPackage.lib | PASS, TUTPackage.a |
| d7zip ZIP/7z/RAR list/extract using in-process 7z.dll | PASS | PASS |
| d7zip ZIP/7z creation and read-back | PASS | PASS |
| Virtual TreeView C++ runtime package | PASS | BLOCKED BY SDK |
| Full C++Builder Map Manager | BLOCKED | BLOCKED |

The Win64 Pascal compilers and archive tests succeeded with RAD Studio 37.0 and official 7-Zip 26.05 64-bit DLL. The Win64 Virtual TreeView package compiled its Delphi units, then failed on Windows Kits 26100 stralign.h while compiling the C++ package wrapper.

Win64 compiled objects and TUTPackage.a are kept locally under C:\Temp\MapManagerDeps\Win64-units. Platform-specific generated headers are copied to TUTPackage\generated\Win64 and ThirdParty\d7zip\generated\Win64. This does not establish that Map Manager itself can currently link or run in Win64.

For 64-bit operation, use a 64-bit 7z.dll (never the 32-bit DLL). Native code/packages must target the same bitness and ABI. RAD Studio 13 can use the modern Win64x (BCC64X) C++ toolchain, but it requires compatible C++ packages; the older Win64 (BCC64) and modern Win64x (BCC64X) toolchains are distinct. The 64-bit IDE supports Win64 targets; use the 32-bit IDE for Win32 targets.

Official references:
https://docwiki.embarcadero.com/RADStudio/Florence/en/64-bit_IDE
https://docwiki.embarcadero.com/RADStudio/Florence/en/BCC64X

Next acceptance gates: supported SDK installation; new blank Win32 C++ VCL build; Virtual TreeView C++ Win64 package build; Map Manager Win32 clean build and runtime; independent Win64 app integration/acceptance.
