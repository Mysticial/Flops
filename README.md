Flops
=====

How many FLOPS can you achieve?

This is the project referenced from: [How to achieve 4 flops per cycle](http://stackoverflow.com/q/8389648/922184)<br>
Version 2 of this project is the one that discovered the [AMD Ryzen FMA bug](https://www.digitaltrends.com/computing/ryzen-amd-bios-fix-fma3-crash/).

The goal of this project is to get as many flops (floating-point operations per second) as possible from an x64 processor.

Modern x86 and x64 processors can theoretically reach a performance on the order of 10s - 100s of GFlops.
However, this can only be achieved through the use of SIMD and very careful programming.
Therefore very few (even numerical) programs can achieve even a small fraction of the theoretical compute power of a modern processor.

This project shows how to achieve >95% of that theoretical performance on some of the current processors of 2010 - 2014.

-----

Here is a list of recommended binaries for each processor line.

 - `2006-Core2` (SSE and SSE2)
    - Intel Core 2 (2006)
    - Intel Nehalem (2008)
    - Intel Westmere (2010)

 - `2011-SandyBridge` (AVX)
    - Intel Sandy Bridge (2011)
    - Intel Ivy Bridge (2012)

 - `2011-Bulldozer` (AVX and FMA4)
    - AMD Bulldozer (2011)

 - `2012-Piledriver` (AVX, FMA3, and FMA4)
    - AMD Piledriver (2012)
    - AMD Steamroller (2014)

 - `2013-Haswell` (AVX and FMA3)
    - Intel Haswell (2013)
    - Intel Broadwell (2014)
    - Intel Skylake (2015)
    - Intel Kaby Lake (2017)

 - `2016-KnightsLanding` (AVX512F)
    - Intel Knights Landing (2016)

 - `2017-Zen` (AVX and FMA3)
    - AMD Zen (2017)

 - `2017-SkylakePurley` (AVX512-F and AVX512-VL)
    - Intel Skylake Purley (2017)

x64 is strongly recommended, but not required. The benchmark is optimized for 16 SIMD registers and may not compile well on x86. Likewise, the AVX512 binaries are optimized for 32 SIMD registers.

-----

**How to Compile: (version 3)**

**Windows:**
 1. Have Visual Studio 2017 (15.9.0 or later) installed at the default path.
 2. Run (or double-click) on `compile_windows_vsc.cmd`.
 3. You will need Intel Compiler 2019 to build the "16-KnightsLanding" binary.

**Linux:**
 1. Run `compile_linux_gcc.sh`.

 For some of the newer architectures (Zen1 and Skylake AVX-512), you'll need at least gcc 6 to compile for those architectures. You can override the C++ compiler by setting the `CXX` environment variable, e.g., by running the build script as `CXX=g++-7 compile_linux_gcc.sh`.

Precompiled binaries can be found in:
 - `binaries-windows/`
 - `binaries-linux/`

-----

**A note about the older versions:**
GCC 6.3 (and possibly some earlier releases) are "smart" enough with compiler optimizations defeat most of the benchmarks. So they will report higher than possible FLOPs. This issue has been fixed in version 3, but there is no plan to fix the older versions 1 and 2.
