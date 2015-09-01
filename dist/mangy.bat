@ECHO OFF
pushd %~dp0
set VAR = ""
FOR /F "delims=" %%I IN ('main.exe %1 %2 %3 %4 %5 %6 %7 %8 %9') do set VAR=%%I & ECHO %%I
type log.txt
popd
%VAR% 2>nul