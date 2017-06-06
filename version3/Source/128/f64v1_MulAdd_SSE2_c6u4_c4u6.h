/* f64v1_MulAdd_SSE2_c6u4_c4u6.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/28/2017
 * Last Modified    : 03/28/2017
 * 
 */

#ifndef _flops_f64v1_MulAdd_SSE2_c6u4_c4u6_H
#define _flops_f64v1_MulAdd_SSE2_c6u4_c4u6_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f64v1_Reduce_SSE2.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f64v1_MulAdd_SSE2_c6u4_c4u6 : public Benchmark{
public:
    f64v1_MulAdd_SSE2_c6u4_c4u6()
        : Benchmark(48 * 2)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m128d mul0 = _mm_set1_pd(1.4142135623730950488);
        const __m128d mul1 = _mm_set1_pd(0.70710678118654752440);

        //  6 multiply chains and 4 add chains
        __m128d r0 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r1 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r2 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r3 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r4 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r5 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r6 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r7 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r8 = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d r9 = _mm_set1_pd((double)(rdtsc() % 256));
        do{
            r0 = _mm_mul_pd(r0, mul0);
            r6 = _mm_add_pd(r6, mul0);
            r1 = _mm_mul_pd(r1, mul0);
            r7 = _mm_add_pd(r7, mul0);
            r2 = _mm_mul_pd(r2, mul0);
            r8 = _mm_add_pd(r8, mul0);
            r3 = _mm_mul_pd(r3, mul0);
            r9 = _mm_add_pd(r9, mul0);
            r4 = _mm_mul_pd(r4, mul0);
            r6 = _mm_sub_pd(r6, mul0);
            r5 = _mm_mul_pd(r5, mul0);
            r7 = _mm_sub_pd(r7, mul0);

            r0 = _mm_mul_pd(r0, mul1);
            r8 = _mm_sub_pd(r8, mul0);
            r1 = _mm_mul_pd(r1, mul1);
            r9 = _mm_sub_pd(r9, mul0);
            r2 = _mm_mul_pd(r2, mul1);
            r6 = _mm_add_pd(r6, mul1);
            r3 = _mm_mul_pd(r3, mul1);
            r7 = _mm_add_pd(r7, mul1);
            r4 = _mm_mul_pd(r4, mul1);
            r8 = _mm_add_pd(r8, mul1);
            r5 = _mm_mul_pd(r5, mul1);
            r9 = _mm_add_pd(r9, mul1);

            r0 = _mm_mul_pd(r0, mul0);
            r6 = _mm_sub_pd(r6, mul1);
            r1 = _mm_mul_pd(r1, mul0);
            r7 = _mm_sub_pd(r7, mul1);
            r2 = _mm_mul_pd(r2, mul0);
            r8 = _mm_sub_pd(r8, mul1);
            r3 = _mm_mul_pd(r3, mul0);
            r9 = _mm_sub_pd(r9, mul1);
            r4 = _mm_mul_pd(r4, mul0);
            r6 = _mm_add_pd(r6, mul0);
            r5 = _mm_mul_pd(r5, mul0);
            r7 = _mm_add_pd(r7, mul0);

            r0 = _mm_mul_pd(r0, mul1);
            r8 = _mm_add_pd(r8, mul0);
            r1 = _mm_mul_pd(r1, mul1);
            r9 = _mm_add_pd(r9, mul0);
            r2 = _mm_mul_pd(r2, mul1);
            r6 = _mm_sub_pd(r6, mul0);
            r3 = _mm_mul_pd(r3, mul1);
            r7 = _mm_sub_pd(r7, mul0);
            r4 = _mm_mul_pd(r4, mul1);
            r8 = _mm_sub_pd(r8, mul0);
            r5 = _mm_mul_pd(r5, mul1);
            r9 = _mm_sub_pd(r9, mul0);
        }while (--iterations);

        r0 = _mm_add_pd(r0, r5);
        r1 = _mm_add_pd(r1, r6);
        r2 = _mm_add_pd(r2, r7);
        r3 = _mm_add_pd(r3, r8);
        r4 = _mm_add_pd(r4, r9);

        r0 = _mm_add_pd(r0, r3);
        r1 = _mm_add_pd(r1, r4);

        r0 = _mm_add_pd(r0, r1);
        r0 = _mm_add_pd(r0, r2);
        return reduce(r0);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
