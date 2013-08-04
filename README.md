Flops
=====

How many FLOPS can you achieve?

This is the project referenced from: [How to achieve 4 flops per cycle](http://stackoverflow.com/q/8389648/922184)

The goal of this project is to get as many flops (floating-point operations per second) as possible from an x64 processor.

Modern x86 and x64 processors can theoretically reach a performance on the order of 10s - 100s of GFlops.
However, this can only be achieved through the use of SIMD and very careful programming.
Therefore very few (even numerical) programs can achieve even a small fraction of the theoretical compute power of a modern processor.

This project shows how to achieve >95% of that theoretical performance on some of the current processors of 2010 - 2013.

-----

How to Compile:

**Windows - Visual Studio:**
 - Launch the VS build environment.
 - Run `compile_windows_cl.cmd` from the directory it is in. (or just double-click it)

**Windows - Intel Compiler**
 - Launch the ICC build environment.
 - Run `compile_windows_icc.cmd` from the directory it is in. (or just double-click it)
 - *(Note that ICC will not build the FMA4 code-paths.)*

**Linux - GCC**
 - Run `compile_linux_gcc.sh`.

A Visual Studio project has also been setup for users with MSVC 2012 or later.

-----

As of the current version, the project supports:
 - SSE2
 - AVX
 - FMA4 (AMD's flavor of the Fused-Multiply Add instruction set)
