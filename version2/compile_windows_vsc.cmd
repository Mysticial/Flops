@call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64

mkdir "binaries-windows"
cd    "binaries-windows"

cl ../source/*.c ../source/*.cpp -o "x64-Core2.exe"       /EHsc /openmp /TP /O2           /D "ArchCore2"
cl ../source/*.c ../source/*.cpp -o "x64-SandyBridge.exe" /EHsc /openmp /TP /O2 /arch:AVX /D "ArchSandyBridge"
cl ../source/*.c ../source/*.cpp -o "x64-Bulldozer.exe"   /EHsc /openmp /TP /O2 /arch:AVX /D "ArchBulldozer"
cl ../source/*.c ../source/*.cpp -o "x64-Piledriver.exe"  /EHsc /openmp /TP /O2 /arch:AVX /D "ArchPiledriver"
cl ../source/*.c ../source/*.cpp -o "x64-Haswell.exe"     /EHsc /openmp /TP /O2 /arch:AVX /D "ArchHaswell"

del *.obj

pause
