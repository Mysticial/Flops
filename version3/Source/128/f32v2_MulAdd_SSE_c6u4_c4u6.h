/* f32v2_MulAdd_SSE_c6u4_c4u6.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/27/2017
 * Last Modified    : 03/27/2017
 * 
 */

#ifndef _flops_f32v2_MulAdd_SSE_c6u4_c4u6_H
#define _flops_f32v2_MulAdd_SSE_c6u4_c4u6_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <xmmintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f64v1_Reduce_SSE2.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f32v2_MulAdd_SSE_c6u4_c4u6 : public Benchmark{
public:
    f32v2_MulAdd_SSE_c6u4_c4u6()
        : Benchmark(48 * 4)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m128 mul0 = _mm_set1_ps(1.4142135623730950488f);
        const __m128 mul1 = _mm_set1_ps(0.70710678118654752440f);

        //  6 multiply chains and 4 add chains
        __m128 r0 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r1 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r2 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r3 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r4 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r5 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r6 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r7 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r8 = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 r9 = _mm_set1_ps((float)(rdtsc() % 256));
        do{
            r0 = _mm_mul_ps(r0, mul0);
            r6 = _mm_add_ps(r6, mul0);
            r1 = _mm_mul_ps(r1, mul0);
            r7 = _mm_add_ps(r7, mul0);
            r2 = _mm_mul_ps(r2, mul0);
            r8 = _mm_add_ps(r8, mul0);
            r3 = _mm_mul_ps(r3, mul0);
            r9 = _mm_add_ps(r9, mul0);
            r4 = _mm_mul_ps(r4, mul0);
            r6 = _mm_sub_ps(r6, mul0);
            r5 = _mm_mul_ps(r5, mul0);
            r7 = _mm_sub_ps(r7, mul0);

            r0 = _mm_mul_ps(r0, mul1);
            r8 = _mm_sub_ps(r8, mul0);
            r1 = _mm_mul_ps(r1, mul1);
            r9 = _mm_sub_ps(r9, mul0);
            r2 = _mm_mul_ps(r2, mul1);
            r6 = _mm_add_ps(r6, mul1);
            r3 = _mm_mul_ps(r3, mul1);
            r7 = _mm_add_ps(r7, mul1);
            r4 = _mm_mul_ps(r4, mul1);
            r8 = _mm_add_ps(r8, mul1);
            r5 = _mm_mul_ps(r5, mul1);
            r9 = _mm_add_ps(r9, mul1);

            r0 = _mm_mul_ps(r0, mul0);
            r6 = _mm_sub_ps(r6, mul1);
            r1 = _mm_mul_ps(r1, mul0);
            r7 = _mm_sub_ps(r7, mul1);
            r2 = _mm_mul_ps(r2, mul0);
            r8 = _mm_sub_ps(r8, mul1);
            r3 = _mm_mul_ps(r3, mul0);
            r9 = _mm_sub_ps(r9, mul1);
            r4 = _mm_mul_ps(r4, mul0);
            r6 = _mm_add_ps(r6, mul0);
            r5 = _mm_mul_ps(r5, mul0);
            r7 = _mm_add_ps(r7, mul0);

            r0 = _mm_mul_ps(r0, mul1);
            r8 = _mm_add_ps(r8, mul0);
            r1 = _mm_mul_ps(r1, mul1);
            r9 = _mm_add_ps(r9, mul0);
            r2 = _mm_mul_ps(r2, mul1);
            r6 = _mm_sub_ps(r6, mul0);
            r3 = _mm_mul_ps(r3, mul1);
            r7 = _mm_sub_ps(r7, mul0);
            r4 = _mm_mul_ps(r4, mul1);
            r8 = _mm_sub_ps(r8, mul0);
            r5 = _mm_mul_ps(r5, mul1);
            r9 = _mm_sub_ps(r9, mul0);
        }while (--iterations);

        r0 = _mm_add_ps(r0, r5);
        r1 = _mm_add_ps(r1, r6);
        r2 = _mm_add_ps(r2, r7);
        r3 = _mm_add_ps(r3, r8);
        r4 = _mm_add_ps(r4, r9);

        r0 = _mm_add_ps(r0, r3);
        r1 = _mm_add_ps(r1, r4);

        r0 = _mm_add_ps(r0, r1);
        r0 = _mm_add_ps(r0, r2);
        return reduce(r0);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
