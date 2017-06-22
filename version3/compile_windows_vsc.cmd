@call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64

mkdir "binaries-windows"
cd    "binaries-windows"

cl ../Source/*.cpp -o "2006-Core2.exe"           /EHsc /fp:precise /TP /MT /O2                /D "x64_2006_Core2"
cl ../Source/*.cpp -o "2011-SandyBridge.exe"     /EHsc /fp:precise /TP /MT /O2 /arch:AVX      /D "x64_2011_SandyBridge"
cl ../Source/*.cpp -o "2011-Bulldozer.exe"       /EHsc /fp:precise /TP /MT /O2 /arch:AVX      /D "x64_2011_Bulldozer"
cl ../Source/*.cpp -o "2012-Piledriver.exe"      /EHsc /fp:precise /TP /MT /O2 /arch:AVX      /D "x64_2012_Piledriver"
cl ../Source/*.cpp -o "2013-Haswell.exe"         /EHsc /fp:precise /TP /MT /O2 /arch:AVX2     /D "x64_2013_Haswell"
cl ../Source/*.cpp -o "2017-Zen.exe"             /EHsc /fp:precise /TP /MT /O2 /arch:AVX2     /D "x64_2017_Zen"

@call "C:\Program Files (x86)\IntelSWTools\compilers_and_libraries_2017.2.187\windows\bin\ipsxe-comp-vars.bat" intel64 vs2015
icl ../Source/*.cpp -o "2016-KnightsLanding.exe" /EHsc /fp:precise /TP /MT /O2 /Qfreestanding /QxMIC-AVX512  /D "x64_2016_KnightsLanding"
icl ../Source/*.cpp -o "2017-SkylakePurley.exe"  /EHsc /fp:precise /TP /MT /O2 /Qfreestanding /QxCORE-AVX512 /D "x64_2017_SkylakePurley"

del *.obj

pause
