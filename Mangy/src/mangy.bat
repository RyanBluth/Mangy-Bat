@ECHO OFF
set VAR = ""
FOR /F "delims=" %%I IN ('main.exe %1 %2 %3 %4 %5 %6 %7 %8 %9') do set VAR=%%I
type log.txt
%VAR% 2>nul

