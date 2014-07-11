icl source/*.c -o "flops_SSE2_icc.exe" /Qopenmp /TP /O2 /arch:SSE2 /D "x86_SSE2"
icl source/*.c -o "flops_AVX_icc.exe"  /Qopenmp /TP /O2 /Qx:AVX    /D "x86_AVX"