/* flops_FMA3.h - FMA3 Benchmarks
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 12/30/2013
 * Last Modified    : 12/30/2013
 * 
 * 
 * 
 * And of course... The typical copyright stuff...
 * 
 *      Redistribution of this program in both source or binary, regardless of
 *  form, with or without modification is permitted as long as the following
 *  conditions are met:
 *          1.  This copyright notice is maintained either inline in the source
 *              or distributed with the binary.
 *          2.  A list of all contributing authors along with their contributions
 *              is included either inline in the source or distributed with the
 *              binary.
 *          3.  The following disclaimer is maintained either inline in the
 *              source or distributed with the binary.
 * 
 *  Disclaimer:
 *  This software is provided "as is", without any guarantee made to its
 *  suitability or fitness for any particular use. It may contain bugs so use
 *  of this program is at your own risk. I take no responsibility for any
 *  damage that may unintentionally be caused through its use.
 */

#ifndef _FMA3_h
#define _FMA3_h
#include <immintrin.h>
#include <ammintrin.h>

//#define _mm256_macc_pd(a, b, c) _mm256_add_pd(_mm256_mul_pd(a, b), c)
//#define _mm256_msub_pd(a, b, c) _mm256_sub_pd(_mm256_mul_pd(a, b), c)

#ifndef _WIN32
#include <x86intrin.h>
#endif

#include "flops.h"

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
double test_dp_fma_FMA3_internal(double x, double y, size_t iterations){
    register __m256d r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB, rC, rD, rE, rF;

    r0 = _mm256_set1_pd(x);
    r1 = _mm256_set1_pd(y);

    r8 = _mm256_set1_pd(-0.0);

    r2 = _mm256_xor_pd(r0, r8);
    r3 = _mm256_or_pd(r0, r8);
    r4 = _mm256_andnot_pd(r8, r0);
    r5 = _mm256_mul_pd(r1, _mm256_set1_pd(0.37796447300922722721));
    r6 = _mm256_mul_pd(r1, _mm256_set1_pd(0.24253562503633297352));
    r7 = _mm256_mul_pd(r1, _mm256_set1_pd(4.1231056256176605498));
    r8 = _mm256_add_pd(r0, _mm256_set1_pd(0.37796447300922722721));
    r9 = _mm256_add_pd(r1, _mm256_set1_pd(0.24253562503633297352));
    rA = _mm256_sub_pd(r0, _mm256_set1_pd(4.1231056256176605498));
    rB = _mm256_sub_pd(r1, _mm256_set1_pd(4.1231056256176605498));

    rC = _mm256_set1_pd(1.0488088481701515470);
    rD = _mm256_set1_pd(0.95346258924559231545);
//    rE = _mm256_set1_pd(1.1);
    rF = _mm256_set1_pd(0.90909090909090909091);

    uint64 iMASK = 0x800fffffffffffffull;
    __m256d MASK = _mm256_set1_pd(*(double*)&iMASK);
    __m256d vONE = _mm256_set1_pd(1.0);

    size_t c = 0;
    while (c < iterations){
        size_t i = 0;
        while (i < 1000){
            r0 = _mm256_fmadd_pd(r0, rC, rD);
            r1 = _mm256_fmadd_pd(r1, rC, rD);
            r2 = _mm256_fmadd_pd(r2, rC, rD);
            r3 = _mm256_fmadd_pd(r3, rC, rD);
            r4 = _mm256_fmadd_pd(r3, rC, rD);
            r5 = _mm256_fmadd_pd(r4, rC, rD);
            r6 = _mm256_fmadd_pd(r5, rC, rD);
            r7 = _mm256_fmadd_pd(r7, rC, rD);
            r8 = _mm256_fmadd_pd(r8, rC, rD);
            r9 = _mm256_fmadd_pd(r9, rC, rD);
            rA = _mm256_fmadd_pd(rA, rC, rD);
            rB = _mm256_fmadd_pd(rB, rC, rD);

            r0 = _mm256_fmadd_pd(r0, rD, rF);
            r1 = _mm256_fmadd_pd(r1, rD, rF);
            r2 = _mm256_fmadd_pd(r2, rD, rF);
            r3 = _mm256_fmadd_pd(r3, rD, rF);
            r4 = _mm256_fmadd_pd(r4, rD, rF);
            r5 = _mm256_fmadd_pd(r5, rD, rF);
            r6 = _mm256_fmadd_pd(r6, rD, rF);
            r7 = _mm256_fmadd_pd(r7, rD, rF);
            r8 = _mm256_fmadd_pd(r8, rD, rF);
            r9 = _mm256_fmadd_pd(r9, rD, rF);
            rA = _mm256_fmadd_pd(rA, rD, rF);
            rB = _mm256_fmadd_pd(rB, rD, rF);

            r0 = _mm256_fmadd_pd(r0, rC, rD);
            r1 = _mm256_fmadd_pd(r1, rC, rD);
            r2 = _mm256_fmadd_pd(r2, rC, rD);
            r3 = _mm256_fmadd_pd(r3, rC, rD);
            r4 = _mm256_fmadd_pd(r3, rC, rD);
            r5 = _mm256_fmadd_pd(r4, rC, rD);
            r6 = _mm256_fmadd_pd(r5, rC, rD);
            r7 = _mm256_fmadd_pd(r7, rC, rD);
            r8 = _mm256_fmadd_pd(r8, rC, rD);
            r9 = _mm256_fmadd_pd(r9, rC, rD);
            rA = _mm256_fmadd_pd(rA, rC, rD);
            rB = _mm256_fmadd_pd(rB, rC, rD);

            r0 = _mm256_fmadd_pd(r0, rD, rF);
            r1 = _mm256_fmadd_pd(r1, rD, rF);
            r2 = _mm256_fmadd_pd(r2, rD, rF);
            r3 = _mm256_fmadd_pd(r3, rD, rF);
            r4 = _mm256_fmadd_pd(r4, rD, rF);
            r5 = _mm256_fmadd_pd(r5, rD, rF);
            r6 = _mm256_fmadd_pd(r6, rD, rF);
            r7 = _mm256_fmadd_pd(r7, rD, rF);
            r8 = _mm256_fmadd_pd(r8, rD, rF);
            r9 = _mm256_fmadd_pd(r9, rD, rF);
            rA = _mm256_fmadd_pd(rA, rD, rF);
            rB = _mm256_fmadd_pd(rB, rD, rF);

            i++;
        }

        r0 = _mm256_and_pd(r0, MASK);
        r1 = _mm256_and_pd(r1, MASK);
        r2 = _mm256_and_pd(r2, MASK);
        r3 = _mm256_and_pd(r3, MASK);
        r4 = _mm256_and_pd(r4, MASK);
        r5 = _mm256_and_pd(r5, MASK);
        r6 = _mm256_and_pd(r6, MASK);
        r7 = _mm256_and_pd(r7, MASK);
        r8 = _mm256_and_pd(r8, MASK);
        r9 = _mm256_and_pd(r9, MASK);
        rA = _mm256_and_pd(rA, MASK);
        rB = _mm256_and_pd(rB, MASK);
        r0 = _mm256_or_pd(r0, vONE);
        r1 = _mm256_or_pd(r1, vONE);
        r2 = _mm256_or_pd(r2, vONE);
        r3 = _mm256_or_pd(r3, vONE);
        r4 = _mm256_or_pd(r4, vONE);
        r5 = _mm256_or_pd(r5, vONE);
        r6 = _mm256_or_pd(r6, vONE);
        r7 = _mm256_or_pd(r7, vONE);
        r8 = _mm256_or_pd(r8, vONE);
        r9 = _mm256_or_pd(r9, vONE);
        rA = _mm256_or_pd(rA, vONE);
        rB = _mm256_or_pd(rB, vONE);

        c++;
    }

//    wclk end = wclk_now();
//    double secs = wclk_secs_since(start);
//    uint64 ops = 12 * 1000 * c * 2;
//    cout << "Seconds = " << secs << endl;
//    cout << "FP Ops  = " << ops << endl;
//    cout << "FLOPs   = " << ops / secs << endl;

    r0 = _mm256_add_pd(r0, r1);
    r2 = _mm256_add_pd(r2, r3);
    r4 = _mm256_add_pd(r4, r5);
    r6 = _mm256_add_pd(r6, r7);
    r8 = _mm256_add_pd(r8, r9);
    rA = _mm256_add_pd(rA, rB);
    
    r0 = _mm256_add_pd(r0, r2);
    r4 = _mm256_add_pd(r4, r6);
    r8 = _mm256_add_pd(r8, rA);

    r0 = _mm256_add_pd(r0, r4);
    r0 = _mm256_add_pd(r0, r8);

    double out = 0;
    __m256d tmp = r0;
    out += ((double*)&tmp)[0];
    out += ((double*)&tmp)[1];
    out += ((double*)&tmp)[2];
    out += ((double*)&tmp)[3];

    return out;
}
void test_dp_fma_FMA3(int tds, size_t iterations){
    
    printf("Testing FMA3 FMA:\n");
    double *sum = (double*)malloc(tds * sizeof(double));
    wclk start = wclk_now();
    
#pragma omp parallel num_threads(tds)
    {
        double ret = test_dp_fma_FMA3_internal(1.1, 2.1, iterations);
        sum[omp_get_thread_num()] = ret;
    }

    double secs = wclk_secs_since(start);
    uint64 ops = 96 * 1000 * iterations * tds * 4;
    printf("Seconds = %g\n", secs);
    printf("FP Ops  = %llu\n", (unsigned long long)ops);
    printf("FLOPs   = %g\n", ops / secs);

    double out = 0;
    int c = 0;
    while (c < tds){
        out += sum[c++];
    }
    
    printf("sum = %g\n\n", out);

    free(sum);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
