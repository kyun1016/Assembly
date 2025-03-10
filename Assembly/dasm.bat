@echo off
set SrcFile=%1.asm
set OutFile=%2.bin
@echo on
dasm.exe %SrcFile% -f3 -o%OutFile%