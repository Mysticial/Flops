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

Here is a list of recommended binaries for each processor line.

 - `x64-Core2`
    - Intel Core 2 (2006)
    - Intel Nehalem (2008)
    - Intel Westmere (2010)

 - `x64-SandyBridge`
    - Intel Sandy Bridge (2011)
    - Intel Ivy Bridge (2012)

 - `x64-Bulldozer`
    - AMD Bulldozer (2011)

 - `x64-Piledriver`
    - AMD Piledriver (2012)
    - AMD Steamroller (2014)

 - `x64-Haswell`
    - Intel Haswell (2013)
    - Intel Broadwell (2014)

x64 is strongly recommended, but not required. The benchmark is optimized for 16 SIMD registers and may not compile well on x86.

-----

**How to Compile: (version 2)**

**Windows:**
 1. Have Visual Studio 2013 installed at the default path.
 2. Run (or double-click) on `compile_windows_vsc.cmd`.

**Linux:**
 1. Run `compile_linux_gcc.sh`.

Precompiled binaries can be found in:
 - `binaries-windows/`
 - `binaries-linux/`

-----

The usual copyright stuff...

Redistribution of this program in both source or binary, regardless of
form, with or without modification is permitted as long as the following
conditions are met:

 1.  This copyright notice is maintained either inline in the source or distributed with the binary.
 2.  A list of all contributing authors along with their contributions is included either inline in the source or distributed with the binary.
 3.  The following disclaimer is maintained either inline in the source or distributed with the binary.

Disclaimer:

This software is provided "as is", without any guarantee made to its
suitability or fitness for any particular use. It may contain bugs so use
of this program is at your own risk. I take no responsibility for any
damage that may unintentionally be caused through its use.
