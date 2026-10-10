@echo off
if not exist gamebox.exe (
    echo Executable not found. Compiling first...
    call build.bat
)
if exist gamebox.exe (
    gamebox.exe
)
