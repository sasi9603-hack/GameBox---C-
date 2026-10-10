@echo off
echo Building GameBox...
g++ -std=c++17 -Wall -g main.cpp tictactoe.cpp numberguess.cpp rps.cpp scores.cpp -o gamebox.exe
if %ERRORLEVEL% EQU 0 (
    echo Build successful! Run .\gamebox.exe or .\run.bat to play.
) else (
    echo Build failed with error code %ERRORLEVEL%.
)
