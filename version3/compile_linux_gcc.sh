mkdir "binaries-linux" #
#
basepath="binaries-linux/" #
flags="-O2 -static -Wl,--whole-archive -lpthread -Wl,--no-whole-archive" #
#
g++ Source/*.cpp -o "${basepath}2006-Core2"           $flags -march=core2          -D "x64_2006_Core2" #
g++ Source/*.cpp -o "${basepath}2011-SandyBridge"     $flags -march=sandybridge    -D "x64_2011_SandyBridge" #
g++ Source/*.cpp -o "${basepath}2011-Bulldozer"       $flags -march=bdver1         -D "x64_2011_Bulldozer" #
g++ Source/*.cpp -o "${basepath}2012-Piledriver"      $flags -march=bdver2         -D "x64_2012_Piledriver" #
g++ Source/*.cpp -o "${basepath}2013-Haswell"         $flags -march=haswell        -D "x64_2013_Haswell" #
g++ Source/*.cpp -o "${basepath}2017-Zen"             $flags -march=znver1         -D "x64_2017_Zen" #
g++ Source/*.cpp -o "${basepath}2016-KnightsLanding"  $flags -march=knl            -D "x64_2016_KnightsLanding" #
g++ Source/*.cpp -o "${basepath}2017-SkylakePurley"   $flags -march=skylake-avx512 -D "x64_2017_SkylakePurley" #
#