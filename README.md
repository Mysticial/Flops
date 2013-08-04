Flops
=====

How many FLOPS can you achieve?

Related: How to Achieve 4 Flops per Cycle (http://stackoverflow.com/a/8391601/922184)

The goal of this project is to get as many flops (floating-point operations per second) as possible from an x64 processor.

Modern x86 and x64 processors can typically achieve performance on the order of 10s - 100s of GFlops.
However, this can only be achieve through the use of SIMD and very careful programming.
Therefore very few (even numerical) programs can achieve even a small fraction of the theoretical compute power of a modern processor.

This project shows how to achieve >95% of that theoretical performance on some of the current processors of 2010 - 2013.

-----

**How to Compile:**

Windows - Visual Studio:
 - Launch the VS build environment.
 - Run `compile_windows_cl.cmd` from the directly it is in. (or just double-click it)

Windows - Intel Compiler
 - Launch the ICC build environment.
 - Run `compile_windows_icc.cmd` from the directly it is in. (or just double-click it)

Linux - GCC
 - Run `compile_linux_gcc.sh`.

A Visual Studio project has already been setup for users with MSVC 2012 or later.
