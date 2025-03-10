@echo off
cd DASM
set SrcFile=%1.asm
set OutFile=../bin/%1.bin
@echo on
dasm.exe %SrcFile% -f3 -o%OutFile%

@echo off
cd ..