 - **Intel Core i7 920 @ 3.5 GHz (overclock)**
 - Windows 7 Ultimate x64
 - Visual Studio 2010 SP1 - x64 Release

```
Seconds = 72.1116
FP Ops  = 7680000000000
FLOPS   = 5.13452e+010
sum = 17.8122
```

Theoretical SSE Peak: (2-way SIMD) * (1 add + 1 mul) * (4 cores) * (3.5 GHz) = **56.0 GFlops**<br>
Actual SSE Peak: **51.3 GFlops**

-----

 - **2 x Intel Xeon X5482 Harpertown @ 3.2 GHz**
 - Ubuntu Linux 10 x64
 - GCC 4.5.2 x64 - (-O2 -msse3 -fopenmp)

```
Seconds = 78.4733
FP Ops  = 7680000000000
FLOPs   = 9.78676e+10
sum = 17.8122
```

Theoretical SSE Peak: (2-way SIMD) * (1 add + 1 mul) * (8 cores) * (3.2 GHz) = **102.4 GFlops**<br>
Actual SSE Peak: **97.9 GFlops**

-----

 - **Intel Core i7 2600K @ 4.4 GHz (overclock)**
 - Windows 7 Ultimate x64
 - Visual Studio 2010 SP1 - x64 Release

```
Seconds = 111.119
FP Ops  = 15360000000000
FLOPs   = 1.3823e+011
sum = 35.6244
```

Theoretical SSE Peak: (4-way SIMD) * (1 add + 1 mul) * (4 cores) * (4.4 GHz) = **140.8 GFlops**<br>
Actual SSE Peak: **138.2 GFlops**

-----

 - **Intel Core i7 4770K @ 4.0 GHz (overclock)**
 - Windows 7 Ultimate x64
 - Visual Studio 2012 - x64 Release

```
Seconds = 126.147
FP Ops  = 30720000000000
FLOPs   = 2.43526e+011
sum = 666.618
```

Theoretical SSE Peak: (4-way SIMD) * (2 FMA) * (2 ops/FMA) * (4 cores) * (4.0 GHz) = **256 GFlops**<br>
Actual SSE Peak: **243.5 GFlops**


