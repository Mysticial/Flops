/* flops_AVX.h - AVX Benchmarks
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 10/21/2011
 * Last Modified    : 01/25/2012
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

#ifndef _AVX_h
#define _AVX_h
#include <immintrin.h>
#include "flops.h"
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
double test_dp_add_AVX_internal(double x, double y, size_t iterations){
    register __m256d r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB;

    r0 = _mm256_set1_pd(x);
    r1 = _mm256_set1_pd(y);

    r8 = _mm256_set1_pd(-0.0);
    r9 = _mm256_set1_pd(0.5);

    r2 = _mm256_xor_pd(r0, r8);
    r3 = _mm256_or_pd(r0, r8);
    r4 = _mm256_andnot_pd(r8, r0);
    r5 = _mm256_mul_pd(r1, r9);
    r6 = _mm256_add_pd(r1, r9);
    r7 = _mm256_sub_pd(r1, r9);
    r8 = _mm256_add_pd(r0, _mm256_set1_pd(2.3));
    r9 = _mm256_sub_pd(r1, _mm256_set1_pd(2.3));

    uint64 iMASK = 0x800fffffffffffffull;
    __m256d MASK = _mm256_set1_pd(*(double*)&iMASK);
    __m256d vONE = _mm256_set1_pd(1.0);

    rA = _mm256_set1_pd(0.1);
    rB = _mm256_set1_pd(0.1001);

//    wclk start = wclk_now();

    size_t c = 0;
    while (c < iterations){
        size_t i = 0;
        while (i < 1000){
            r0 = _mm256_add_pd(r0, rA);
            r1 = _mm256_add_pd(r1, rA);
            r2 = _mm256_add_pd(r2, rA);
            r3 = _mm256_add_pd(r3, rA);
            r4 = _mm256_add_pd(r4, rA);
            r5 = _mm256_add_pd(r5, rA);
            r6 = _mm256_add_pd(r6, rA);
            r7 = _mm256_add_pd(r7, rA);
            r8 = _mm256_add_pd(r8, rA);
            r9 = _mm256_add_pd(r9, rA);

            r0 = _mm256_sub_pd(r0, rB);
            r1 = _mm256_sub_pd(r1, rB);
            r2 = _mm256_sub_pd(r2, rB);
            r3 = _mm256_sub_pd(r3, rB);
            r4 = _mm256_sub_pd(r4, rB);
            r5 = _mm256_sub_pd(r5, rB);
            r6 = _mm256_sub_pd(r6, rB);
            r7 = _mm256_sub_pd(r7, rB);
            r8 = _mm256_sub_pd(r8, rB);
            r9 = _mm256_sub_pd(r9, rB);

            //r8 = _mm256_add_pd(r0, r1);
            //r9 = _mm256_add_pd(r2, r3);
            //rA = _mm256_add_pd(r4, r5);
            //rB = _mm256_add_pd(r6, r7);

            //r0 = _mm256_sub_pd(r0, r4);
            //r1 = _mm256_sub_pd(r1, r5);
            //r2 = _mm256_sub_pd(r2, r6);
            //r3 = _mm256_sub_pd(r3, r7);

            //r4 = _mm256_add_pd(r4, r8);
            //r5 = _mm256_add_pd(r5, r9);
            //r6 = _mm256_add_pd(r6, rA);
            //r7 = _mm256_add_pd(r7, rB);

            i++;
        }

        //print(r0);
        //print(r1);
        //print(r2);
        //print(r3);
        //print(r4);
        //print(r5);
        //print(r6);
        //print(r7);
        //cout << endl;

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

        c++;
    }

//    wclk end = wclk_now();
//    double secs = wclk_secs_since(start);
//    uint64 ops = 12 * 1000 * c * 4;
//    cout << "Seconds = " << secs << endl;
//    cout << "FP Ops  = " << ops << endl;
//    cout << "FLOPs   = " << ops / secs << endl;

    r0 = _mm256_add_pd(r0, r1);
    r2 = _mm256_add_pd(r2, r3);
    r4 = _mm256_add_pd(r4, r5);
    r6 = _mm256_add_pd(r6, r7);
    r8 = _mm256_add_pd(r8, r9);
    
    r0 = _mm256_add_pd(r0, r2);
    r4 = _mm256_add_pd(r4, r6);

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
void test_dp_add_AVX(int tds, size_t iterations){
    
    printf("Testing AVX Add:\n");
    double *sum = (double*)malloc(tds * sizeof(double));
    wclk start = wclk_now();
    
#pragma omp parallel num_threads(tds)
    {
        double ret = test_dp_add_AVX_internal(1.1, 2.1, iterations);
        sum[omp_get_thread_num()] = ret;
    }

    double secs = wclk_secs_since(start);
    uint64 ops = 20 * 1000 * iterations * tds * 4;
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
double test_dp_mul_AVX_internal(double x, double y, size_t iterations){
    register __m256d r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB;

    r0 = _mm256_set1_pd(x);
    r1 = _mm256_set1_pd(y);

    r8 = _mm256_set1_pd(-0.0);

    r2 = _mm256_xor_pd(r0, r8);
    r3 = _mm256_or_pd(r0, r8);
    r4 = _mm256_andnot_pd(r8, r0);
    r5 = _mm256_mul_pd(r1, _mm256_set1_pd(0.37796447300922722721));
    r6 = _mm256_mul_pd(r1, _mm256_set1_pd(0.24253562503633297352));
    r7 = _mm256_mul_pd(r1, _mm256_set1_pd(4.1231056256176605498));
    r8 = _mm256_add_pd(r0, _mm256_set1_pd(2.3));
    r9 = _mm256_sub_pd(r1, _mm256_set1_pd(2.3));

//    r8 = _mm256_set1_pd(1.4142135623730950488);
//    r9 = _mm256_set1_pd(1.7320508075688772935);
//    rA = _mm256_set1_pd(0.57735026918962576451);
//    rB = _mm256_set1_pd(0.70710678118654752440);

    rA = _mm256_set1_pd(1.4142135623730950488);
    rB = _mm256_set1_pd(0.70710678118654752440);

    uint64 iMASK = 0x800fffffffffffffull;
    __m256d MASK = _mm256_set1_pd(*(double*)&iMASK);
    __m256d vONE = _mm256_set1_pd(1.0);

    size_t c = 0;
    while (c < iterations){
        size_t i = 0;
        while (i < 1000){
            r0 = _mm256_mul_pd(r0, rA);
            r1 = _mm256_mul_pd(r1, rA);
            r2 = _mm256_mul_pd(r2, rA);
            r3 = _mm256_mul_pd(r3, rA);
            r4 = _mm256_mul_pd(r4, rA);
            r5 = _mm256_mul_pd(r5, rA);
            r6 = _mm256_mul_pd(r6, rA);
            r7 = _mm256_mul_pd(r7, rA);
            r8 = _mm256_mul_pd(r8, rA);
            r9 = _mm256_mul_pd(r9, rA);

            r0 = _mm256_mul_pd(r0, rB);
            r1 = _mm256_mul_pd(r1, rB);
            r2 = _mm256_mul_pd(r2, rB);
            r3 = _mm256_mul_pd(r3, rB);
            r4 = _mm256_mul_pd(r4, rB);
            r5 = _mm256_mul_pd(r5, rB);
            r6 = _mm256_mul_pd(r6, rB);
            r7 = _mm256_mul_pd(r7, rB);
            r8 = _mm256_mul_pd(r8, rB);
            r9 = _mm256_mul_pd(r9, rB);

            i++;
        }

        //print(r0);
        //print(r1);
        //print(r2);
        //print(r3);
        //print(r4);
        //print(r5);
        //print(r6);
        //print(r7);
        //cout << endl;
        
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
    
    r0 = _mm256_add_pd(r0, r2);
    r4 = _mm256_add_pd(r4, r6);

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
void test_dp_mul_AVX(int tds, size_t iterations){
    
    printf("Testing AVX Mul:\n");
    double *sum = (double*)malloc(tds * sizeof(double));
    wclk start = wclk_now();
    
#pragma omp parallel num_threads(tds)
    {
        double ret = test_dp_mul_AVX_internal(1.1, 2.1, iterations);
        sum[omp_get_thread_num()] = ret;
    }

    double secs = wclk_secs_since(start);
    uint64 ops = 20 * 1000 * iterations * tds * 4;
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
double test_dp_mac_AVX_internal(double x, double y, size_t iterations){
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

    rC = _mm256_set1_pd(1.4142135623730950488);
    rD = _mm256_set1_pd(1.7320508075688772935);
    rE = _mm256_set1_pd(0.57735026918962576451);
    rF = _mm256_set1_pd(0.70710678118654752440);

    uint64 iMASK = 0x800fffffffffffffull;
    __m256d MASK = _mm256_set1_pd(*(double*)&iMASK);
    __m256d vONE = _mm256_set1_pd(1.0);

    size_t c = 0;
    while (c < iterations){
        size_t i = 0;
        while (i < 1000){
            r0 = _mm256_mul_pd(r0, rC);
            r1 = _mm256_add_pd(r1, rD);
            r2 = _mm256_mul_pd(r2, rE);
            r3 = _mm256_sub_pd(r3, rF);
            r4 = _mm256_mul_pd(r4, rC);
            r5 = _mm256_add_pd(r5, rD);
            r6 = _mm256_mul_pd(r6, rE);
            r7 = _mm256_sub_pd(r7, rF);
            r8 = _mm256_mul_pd(r8, rC);
            r9 = _mm256_add_pd(r9, rD);
            rA = _mm256_mul_pd(rA, rE);
            rB = _mm256_sub_pd(rB, rF);

            r0 = _mm256_add_pd(r0, rF);
            r1 = _mm256_mul_pd(r1, rE);
            r2 = _mm256_sub_pd(r2, rD);
            r3 = _mm256_mul_pd(r3, rC);
            r4 = _mm256_add_pd(r4, rF);
            r5 = _mm256_mul_pd(r5, rE);
            r6 = _mm256_sub_pd(r6, rD);
            r7 = _mm256_mul_pd(r7, rC);
            r8 = _mm256_add_pd(r8, rF);
            r9 = _mm256_mul_pd(r9, rE);
            rA = _mm256_sub_pd(rA, rD);
            rB = _mm256_mul_pd(rB, rC);
            
            r0 = _mm256_mul_pd(r0, rC);
            r1 = _mm256_add_pd(r1, rD);
            r2 = _mm256_mul_pd(r2, rE);
            r3 = _mm256_sub_pd(r3, rF);
            r4 = _mm256_mul_pd(r4, rC);
            r5 = _mm256_add_pd(r5, rD);
            r6 = _mm256_mul_pd(r6, rE);
            r7 = _mm256_sub_pd(r7, rF);
            r8 = _mm256_mul_pd(r8, rC);
            r9 = _mm256_add_pd(r9, rD);
            rA = _mm256_mul_pd(rA, rE);
            rB = _mm256_sub_pd(rB, rF);

            r0 = _mm256_add_pd(r0, rF);
            r1 = _mm256_mul_pd(r1, rE);
            r2 = _mm256_sub_pd(r2, rD);
            r3 = _mm256_mul_pd(r3, rC);
            r4 = _mm256_add_pd(r4, rF);
            r5 = _mm256_mul_pd(r5, rE);
            r6 = _mm256_sub_pd(r6, rD);
            r7 = _mm256_mul_pd(r7, rC);
            r8 = _mm256_add_pd(r8, rF);
            r9 = _mm256_mul_pd(r9, rE);
            rA = _mm256_sub_pd(rA, rD);
            rB = _mm256_mul_pd(rB, rC);

            i++;
        }

        //print(r0);
        //print(r1);
        //print(r2);
        //print(r3);
        //print(r4);
        //print(r5);
        //print(r6);
        //print(r7);
        //print(r8);
        //print(r9);
        //print(rA);
        //print(rB);
        //cout << endl;

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
void test_dp_mac_AVX(int tds, size_t iterations){
    
    printf("Testing AVX Mul + Add:\n");
    double *sum = (double*)malloc(tds * sizeof(double));
    wclk start = wclk_now();
    
#pragma omp parallel num_threads(tds)
    {
        double ret = test_dp_mac_AVX_internal(1.1, 2.1, iterations);
        sum[omp_get_thread_num()] = ret;
    }

    double secs = wclk_secs_since(start);
    uint64 ops = 48 * 1000 * iterations * tds * 4;
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
