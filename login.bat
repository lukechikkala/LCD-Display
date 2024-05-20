@echo off
setlocal

set username="chikkala"
set IP=192.168.178.46
set PORT=22

:retry
ncat -z %IP% %PORT%
if errorlevel 1 (
    echo Port %PORT% on %IP% is not open, retrying...
    timeout /t 5 > nul
    goto retry
)

echo Connecting to %IP% on port %PORT%...
cls
ssh %username%@%IP%

endlocal
