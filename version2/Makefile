

# Default compiler and compiler flags
CXX=g++
CXX_FLAGS=-std=c++11 -fopenmp -O2

# Here the binaries will be places
BASEPATH=binaries-linux/x64-

# Binaries
BINS=Core2 SandyBridge Bulldozer Piledriver Haswell


# Default generic instructions
default:	all
all:	$(BINS)
clean:	
	rm -f *.o

Core2:	source/*.c source/*.cpp
	$(CXX) $(CXX_FLAGS)	source/*.c source/*.cpp -o "${BASEPATH}$@.out"       ${flags} -march=core2      -D "Arch$@"

SandyBridge:	source/*.c source/*.cpp
	$(CXX) $(CXX_FLAGS) 	source/*.c source/*.cpp -o "${BASEPATH}$@.out"       ${flags} -march=corei7-avx      -D "Arch$@"

Bulldozer:	source/*.c source/*.cpp
	$(CXX) $(CXX_FLAGS) 	source/*.c source/*.cpp -o "${BASEPATH}$@.out"       ${flags} -march=bdver1      -D "Arch$@"

Piledriver:	source/*.c source/*.cpp
	$(CXX) $(CXX_FLAGS) 	source/*.c source/*.cpp -o "${BASEPATH}$@.out"       ${flags} -march=bdver2      -D "Arch$@"

Haswell:	source/*.c source/*.cpp
	$(CXX) $(CXX_FLAGS) 	source/*.c source/*.cpp -o "${BASEPATH}$@.out"       ${flags} -march=core-avx2      -D "Arch$@"

