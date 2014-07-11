Flops
=====

How many FLOPS can you achieve?

This is the project referenced from: [How to achieve 4 flops per cycle](http://stackoverflow.com/q/8389648/922184)

The goal of this project is to get as many flops (floating-point operations per second) as possible from an x64 processor.

Modern x86 and x64 processors can theoretically reach a performance on the order of 10s - 100s of GFlops.
However, this can only be achieved through the use of SIMD and very careful programming.
Therefore very few (even numerical) programs can achieve even a small fraction of the theoretical compute power of a modern processor.

This project shows how to achieve >95% of that theoretical performance on some of the current processors of 2010 - 2014.

-----

Version 2 is coming soon...


New Features:
 - Single and Double precision benchmarks.
 - 128-bit and 256-bit FMA

Binaries will target processors instead of instruction sets:
 - Core 2 (SSE2)
 - Sandy Bridge (AVX)
 - Bulldozer (AVX + FMA4)
 - Piledriver (AVX + FMA3 + FMA4)
 - Haswell (AVX + FMA3)
 - Skylake (AVX512)

