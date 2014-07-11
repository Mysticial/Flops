gcc source/*.c -o "flops_SSE2_gcc.out" -lm -fopenmp -msse2 -O2 -D "x86_SSE2" #
gcc source/*.c -o "flops_AVX_gcc.out"  -lm -fopenmp -mavx  -O2 -D "x86_AVX"  #
gcc source/*.c -o "flops_FMA4_gcc.out" -lm -fopenmp -mfma4 -O2 -D "x86_FMA4"  #
