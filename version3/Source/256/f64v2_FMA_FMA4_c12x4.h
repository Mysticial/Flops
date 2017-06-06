/* f64v2_FMA_FMA4_c12x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/29/2017
 * Last Modified    : 03/29/2017
 * 
 */

#ifndef _flops_f64v2_FMA_FMA4_c12x4_H
#define _flops_f64v2_FMA_FMA4_c12x4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#ifndef _WIN32
#include <x86intrin.h>
#endif
#include <immintrin.h>
#include <ammintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f64v2_Reduce_AVX.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f64v2_FMA_FMA4_c12x4 : public Benchmark{
public:
    f64v2_FMA_FMA4_c12x4()
        : Benchmark(48 * 2 * 4)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m256d mul0 = _mm256_set1_pd(1.4142135623730950488);
        const __m256d mul1 = _mm256_set1_pd(1.7320508075688772935);

        __m256d r0 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r1 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r2 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r3 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r4 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r5 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r6 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r7 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r8 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d r9 = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d rA = _mm256_set1_pd((double)(rdtsc() % 256));
        __m256d rB = _mm256_set1_pd((double)(rdtsc() % 256));
        do{
            r0 = _mm256_macc_pd(mul0, mul1, r0);
            r1 = _mm256_macc_pd(mul0, mul1, r1);
            r2 = _mm256_macc_pd(mul0, mul1, r2);
            r3 = _mm256_macc_pd(mul0, mul1, r3);
            r4 = _mm256_macc_pd(mul0, mul1, r4);
            r5 = _mm256_macc_pd(mul0, mul1, r5);
            r6 = _mm256_macc_pd(mul0, mul1, r6);
            r7 = _mm256_macc_pd(mul0, mul1, r7);
            r8 = _mm256_macc_pd(mul0, mul1, r8);
            r9 = _mm256_macc_pd(mul0, mul1, r9);
            rA = _mm256_macc_pd(mul0, mul1, rA);
            rB = _mm256_macc_pd(mul0, mul1, rB);

            r0 = _mm256_nmacc_pd(mul0, mul1, r0);
            r1 = _mm256_nmacc_pd(mul0, mul1, r1);
            r2 = _mm256_nmacc_pd(mul0, mul1, r2);
            r3 = _mm256_nmacc_pd(mul0, mul1, r3);
            r4 = _mm256_nmacc_pd(mul0, mul1, r4);
            r5 = _mm256_nmacc_pd(mul0, mul1, r5);
            r6 = _mm256_nmacc_pd(mul0, mul1, r6);
            r7 = _mm256_nmacc_pd(mul0, mul1, r7);
            r8 = _mm256_nmacc_pd(mul0, mul1, r8);
            r9 = _mm256_nmacc_pd(mul0, mul1, r9);
            rA = _mm256_nmacc_pd(mul0, mul1, rA);
            rB = _mm256_nmacc_pd(mul0, mul1, rB);

            r0 = _mm256_macc_pd(mul0, mul1, r0);
            r1 = _mm256_macc_pd(mul0, mul1, r1);
            r2 = _mm256_macc_pd(mul0, mul1, r2);
            r3 = _mm256_macc_pd(mul0, mul1, r3);
            r4 = _mm256_macc_pd(mul0, mul1, r4);
            r5 = _mm256_macc_pd(mul0, mul1, r5);
            r6 = _mm256_macc_pd(mul0, mul1, r6);
            r7 = _mm256_macc_pd(mul0, mul1, r7);
            r8 = _mm256_macc_pd(mul0, mul1, r8);
            r9 = _mm256_macc_pd(mul0, mul1, r9);
            rA = _mm256_macc_pd(mul0, mul1, rA);
            rB = _mm256_macc_pd(mul0, mul1, rB);

            r0 = _mm256_nmacc_pd(mul0, mul1, r0);
            r1 = _mm256_nmacc_pd(mul0, mul1, r1);
            r2 = _mm256_nmacc_pd(mul0, mul1, r2);
            r3 = _mm256_nmacc_pd(mul0, mul1, r3);
            r4 = _mm256_nmacc_pd(mul0, mul1, r4);
            r5 = _mm256_nmacc_pd(mul0, mul1, r5);
            r6 = _mm256_nmacc_pd(mul0, mul1, r6);
            r7 = _mm256_nmacc_pd(mul0, mul1, r7);
            r8 = _mm256_nmacc_pd(mul0, mul1, r8);
            r9 = _mm256_nmacc_pd(mul0, mul1, r9);
            rA = _mm256_nmacc_pd(mul0, mul1, rA);
            rB = _mm256_nmacc_pd(mul0, mul1, rB);
        }while (--iterations);

        r0 = _mm256_add_pd(r0, r6);
        r1 = _mm256_add_pd(r1, r7);
        r2 = _mm256_add_pd(r2, r8);
        r3 = _mm256_add_pd(r3, r9);
        r4 = _mm256_add_pd(r4, rA);
        r5 = _mm256_add_pd(r5, rB);

        r0 = _mm256_add_pd(r0, r3);
        r1 = _mm256_add_pd(r1, r4);
        r2 = _mm256_add_pd(r2, r5);

        r0 = _mm256_add_pd(r0, r1);
        r0 = _mm256_add_pd(r0, r2);
        return reduce(r0);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
