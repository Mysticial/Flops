cl source/*.c -o "flops_SSE2_vsc.exe" /openmp /TP /O2           /D "WIN32" /D "x86_SSE2"
cl source/*.c -o "flops_AVX_vsc.exe"  /openmp /TP /O2 /arch:AVX /D "WIN32" /D "x86_AVX"
cl source/*.c -o "flops_FMA4_vsc.exe" /openmp /TP /O2 /arch:AVX /D "WIN32" /D "x86_FMA4"
cl source/*.c -o "flops_FMA3_vsc.exe" /openmp /TP /O2 /arch:AVX /D "WIN32" /D "x86_FMA3"