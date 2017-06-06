mkdir "binaries-linux" #
#
basepath="binaries-linux/x64-" #
flags="-std=c++0x -static -fopenmp -O2" #
#
g++ source/*.c source/*.cpp -o "${basepath}Core2.out"          $flags -march=core2          -D "ArchCore2" #
g++ source/*.c source/*.cpp -o "${basepath}SandyBridge.out"    $flags -march=sandybridge    -D "ArchSandyBridge" #
g++ source/*.c source/*.cpp -o "${basepath}Bulldozer.out"      $flags -march=bdver1         -D "ArchBulldozer" #
g++ source/*.c source/*.cpp -o "${basepath}Piledriver.out"     $flags -march=bdver2         -D "ArchPiledriver" #
g++ source/*.c source/*.cpp -o "${basepath}Haswell.out"        $flags -march=haswell        -D "ArchHaswell" #
g++ source/*.c source/*.cpp -o "${basepath}KnightsLanding.out" $flags -march=knl            -D "ArchKnightsLanding" #
g++ source/*.c source/*.cpp -o "${basepath}SkylakePurley.out"  $flags -march=skylake-avx512 -D "ArchKnightsLanding" #
#