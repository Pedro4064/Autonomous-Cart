@echo off
set COMPILER=C:\mingw81\bin\gcc
                set CXXCOMPILER=C:\mingw81\bin\g++
                set COMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set CXXCOMPFLAGS=-c -fexceptions -fno-omit-frame-pointer -m64 -DMATLAB_MEX_FILE  -DMATLAB_MEX_FILE 
                set OPTIMFLAGS=-O2 -fwrapv -DNDEBUG
                set DEBUGFLAGS=-g
                set LINKER=C:\mingw81\bin\gcc
                set CXXLINKER=C:\mingw81\bin\g++
                set LINKFLAGS=-m64 -Wl,--no-undefined -shared -static -L"C:\Program Files\MATLAB\R2024b\extern\lib\win64\mingw64" -llibmx -llibmex -llibmat -lm -llibmwlapack -llibmwblas -Wl,"C:\Program Files\MATLAB\R2024b/extern/lib/win64/mingw64/mexFunction.def"
                set LINKDEBUGFLAGS=-g
                set NAME_OUTPUT=-o "%OUTDIR%%MEX_NAME%%MEX_EXT%"
set PATH=C:\mingw81\bin;C:\Program Files\MATLAB\R2024b\extern\include\win64;C:\Program Files\MATLAB\R2024b\extern\include;C:\Program Files\MATLAB\R2024b\simulink\include;C:\Program Files\MATLAB\R2024b\lib\win64;%MATLAB_BIN%;%PATH%
set INCLUDE=C:\mingw81\include;;%INCLUDE%
set LIB=C:\mingw81\lib;;%LIB%
set LIBPATH=C:\Program Files\MATLAB\R2024b\extern\lib\win64;%LIBPATH%

gmake SHELL="cmd" -f EKF_cgxe.gmk
