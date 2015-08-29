@echo off
if %1 == debug (
	bin\Main-debug.exe
) else (
	copy bin\Main.exe C:\tools\mangy\Main.exe /Y
)
pause