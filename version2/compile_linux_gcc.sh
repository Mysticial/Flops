mkdir "binaries-linux" #
#
basepath="binaries-linux/x64-" #
flags="-std=c++0x -static -fopenmp -O2" #
#
g++ source/*.c source/*.cpp -o "${basepath}Core2.out"       $flags -march=core2      -D "ArchCore2" #
g++ source/*.c source/*.cpp -o "${basepath}SandyBridge.out" $flags -march=corei7-avx -D "ArchSandyBridge" #
g++ source/*.c source/*.cpp -o "${basepath}Bulldozer.out"   $flags -march=bdver1     -D "ArchBulldozer" #
g++ source/*.c source/*.cpp -o "${basepath}Piledriver.out"  $flags -march=bdver2     -D "ArchPiledriver" #
g++ source/*.c source/*.cpp -o "${basepath}Haswell.out"     $flags -march=core-avx2  -D "ArchHaswell" #
#