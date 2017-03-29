@call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64

mkdir "binaries-windows"
cd    "binaries-windows"

cl  ../source/*.c ../source/*.cpp -o "x64-06-Core2.exe"          /EHsc /fp:precise /openmp /TP /MT /O2                /D "ArchCore2"
cl  ../source/*.c ../source/*.cpp -o "x64-11-SandyBridge.exe"    /EHsc /fp:precise /openmp /TP /MT /O2 /arch:AVX      /D "ArchSandyBridge"
cl  ../source/*.c ../source/*.cpp -o "x64-11-Bulldozer.exe"      /EHsc /fp:precise /openmp /TP /MT /O2 /arch:AVX      /D "ArchBulldozer"
cl  ../source/*.c ../source/*.cpp -o "x64-12-Piledriver.exe"     /EHsc /fp:precise /openmp /TP /MT /O2 /arch:AVX      /D "ArchPiledriver"
cl  ../source/*.c ../source/*.cpp -o "x64-13-Haswell.exe"        /EHsc /fp:precise /openmp /TP /MT /O2 /arch:AVX      /D "ArchHaswell"

@call "C:\Program Files (x86)\IntelSWTools\compilers_and_libraries_2017.2.187\windows\bin\ipsxe-comp-vars.bat" intel64 vs2015
icl ../source/*.c ../source/*.cpp -o "x64-16-KnightsLanding.exe" /EHsc /fp:precise /openmp /TP /MT /O2 /QxMIC-AVX512 /D "ArchKnightsLanding"

del *.obj

pause
