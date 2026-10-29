@echo off
setlocal
set PLATFORM=%~1
set CONFIG=%~2
if "%PLATFORM%"=="" set PLATFORM=Win32
if "%CONFIG%"=="" set CONFIG=Debug
set ROOT=%~dp0..
set OUT=%ROOT%\%PLATFORM%\%CONFIG%
if not exist "%OUT%" mkdir "%OUT%"
if /I "%PLATFORM%"=="Win32" (
 set "COMPILER=C:\Program Files (x86)\Embarcadero\Studio\37.0\bin\dcc32.exe"
) else if /I "%PLATFORM%"=="Win64" (
 set "COMPILER=C:\Program Files (x86)\Embarcadero\Studio\37.0\bin\dcc64.exe"
) else (
 echo MMArchiveEngine unsupported target %PLATFORM%
 exit /b 2
)
"%COMPILER%" -B -JPHNE "-N%OUT%" "-NB%OUT%" "-NH%OUT%" "-NO%OUT%" "-U%ROOT%\ThirdParty\d7zip" -NSWinapi;System;System.Win;Vcl;Data;Xml;Datasnap --BCB "%ROOT%\MMArchiveEngine.pas"
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
