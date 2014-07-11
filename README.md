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

Version 2 is work in progress...

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

-----

Version 2 Pre-Release To-Do List:
 - Move old version into a new folder. **Done**
 - Implement back-end subroutines. **Done**
 - Implement the Windows CPU dispatcher.
 - Write the Windows build scripts.
 - Port the back-end to Linux.
 - Port the CPU dispatcher to Linux.
 - Write the Linux build scripts.

-----

And of course... The typical copyright stuff...

    Redistribution of this program in both source or binary, regardless of
form, with or without modification is permitted as long as the following
conditions are met:
        1.  This copyright notice is maintained either inline in the source
            or distributed with the binary.
        2.  A list of all contributing authors along with their contributions
            is included either inline in the source or distributed with the
            binary.
        3.  The following disclaimer is maintained either inline in the
            source or distributed with the binary.

Disclaimer:
This software is provided "as is", without any guarantee made to its
suitability or fitness for any particular use. It may contain bugs so use
of this program is at your own risk. I take no responsibility for any
damage that may unintentionally be caused through its use.
