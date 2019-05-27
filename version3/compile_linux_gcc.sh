# set the default compiler to g++, but let the user override it by setting CXX in
# case they want to use a different compiler version
CXX=${CXX:-g++}

echo "using CXX = $CXX"

mkdir -p "binaries-linux" #
#
basepath="binaries-linux/" #
flags="-O2 -pthread -std=c++11" #
#flags="-O2 -static -Wl,--whole-archive -lpthread -Wl,--no-whole-archive -std=c++11" #
#
$CXX Source/*.cpp -o "${basepath}2006-Core2"           $flags -march=core2          -D "x64_2006_Core2" & #
$CXX Source/*.cpp -o "${basepath}2011-SandyBridge"     $flags -march=sandybridge    -D "x64_2011_SandyBridge" & #
$CXX Source/*.cpp -o "${basepath}2011-Bulldozer"       $flags -march=bdver1         -D "x64_2011_Bulldozer" & #
$CXX Source/*.cpp -o "${basepath}2012-Piledriver"      $flags -march=bdver2         -D "x64_2012_Piledriver" & #
$CXX Source/*.cpp -o "${basepath}2013-Haswell"         $flags -march=haswell        -D "x64_2013_Haswell" & #
$CXX Source/*.cpp -o "${basepath}2017-Zen"             $flags -march=znver1         -D "x64_2017_Zen" & #
$CXX Source/*.cpp -o "${basepath}2016-KnightsLanding"  $flags -march=knl            -D "x64_2016_KnightsLanding" & #
$CXX Source/*.cpp -o "${basepath}2017-SkylakePurley"   $flags -march=skylake-avx512 -D "x64_2017_SkylakePurley" & #
wait
exit $?
#
