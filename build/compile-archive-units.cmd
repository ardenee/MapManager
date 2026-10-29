@echo off
setlocal
set PLATFORM=%~1
set CONFIG=%~2
if "%PLATFORM%"=="" set PLATFORM=Win32
if "%CONFIG%"=="" set CONFIG=Debug
set ROOT=%~dp0..
set OUT=%ROOT%\%PLATFORM%\%CONFIG%
if not exist "%OUT%" mkdir "%OUT%"
if /I "%PLATFORM%"=="Win64x" goto WIN64X
if /I "%PLATFORM%"=="Win32" (
 set "COMPILER=C:\Program Files (x86)\Embarcadero\Studio\37.0\bin\dcc32.exe"
) else if /I "%PLATFORM%"=="Win64" (
 set "COMPILER=C:\Program Files (x86)\Embarcadero\Studio\37.0\bin\dcc64.exe"
) else (
 echo MMArchiveEngine unsupported target %PLATFORM%
 exit /b 2
)
"%COMPILER%" -B -JPHNE "-N%OUT%" "-NB%OUT%" "-NH%OUT%" "-NO%OUT%" "-U%ROOT%\..\d7zip" -NSWinapi;System;System.Win;Vcl;Data;Xml;Datasnap --BCB "%ROOT%\MMArchiveEngine.pas"
if errorlevel 1 exit /b 1
if /I "%PLATFORM%"=="Win32" (
 if not exist "%OUT%\MMArchiveEngine.obj" exit /b 3
 if not exist "%OUT%\sevenzip.obj" exit /b 3
) else (
 if not exist "%OUT%\MMArchiveEngine.o" exit /b 3
 if not exist "%OUT%\sevenzip.o" exit /b 3
)
echo MMArchiveEngine generated %PLATFORM% objects
exit /b 0

:WIN64X
rem Win64 Modern bcc64x requires COFF objects and .lib, not legacy Win64 ELF .o/.a.
set "DCC=C:\Program Files (x86)\Embarcadero\Studio\37.0\bin\dcc64.exe"
set "LIBTOOL=C:\Program Files (x86)\Embarcadero\Studio\37.0\bin64\llvm-lib.exe"
pushd "%ROOT%\..\TUTPackage"
for %%U in (ut_packages ut_umods ut_uz utpkgnat_ut2004) do (
 "%DCC%" -B -JPHNE -jf:coffi "-N%OUT%" "-NB%OUT%" "-NH%OUT%" "-NO%OUT%" "-U%OUT%;." -I. -O. -R. -NSWinapi;System;System.Win;Vcl;Data;Xml;Datasnap --BCB %%U.pas
 if errorlevel 1 (popd & exit /b 1)
)
popd
pushd "%ROOT%"
"%DCC%" -B -JPHNE -jf:coffi "-N%OUT%" "-NB%OUT%" "-NH%OUT%" "-NO%OUT%" "-U%OUT%;..\d7zip" -NSWinapi;System;System.Win;Vcl;Data;Xml;Datasnap --BCB MMArchiveEngine.pas
if errorlevel 1 (popd & exit /b 2)
popd
"%LIBTOOL%" /nologo "/out:%OUT%\TUTPackage.lib" "%OUT%\ut_packages.o" "%OUT%\ut_umods.o" "%OUT%\ut_uz.o" "%OUT%\utpkgnat_ut2004.o"
if errorlevel 1 exit /b 3
if not exist "%OUT%\MMArchiveEngine.o" exit /b 4
if not exist "%OUT%\sevenzip.o" exit /b 4
if not exist "%OUT%\TUTPackage.lib" exit /b 4
rem Build an IDE-managed COFF library. RAD Studio may discard custom ObjFiles items
rem when saving Project1.cbproj, but retains LinkPackageStatics project settings.
"%LIBTOOL%" /nologo "/out:%OUT%\MMArchiveEngine.lib" "%OUT%\MMArchiveEngine.o" "%OUT%\sevenzip.o"
if errorlevel 1 exit /b 5
if not exist "%OUT%\MMArchiveEngine.lib" exit /b 6
echo MapManager Win64x COFF archive and TUTPackage objects generated
exit /b 0
