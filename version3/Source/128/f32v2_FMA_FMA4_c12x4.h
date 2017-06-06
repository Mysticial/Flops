/* f32v2_FMA_FMA4_c12x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/29/2017
 * Last Modified    : 03/29/2017
 * 
 */

#ifndef _flops_f32v2_FMA_FMA4_c12x4_H
#define _flops_f32v2_FMA_FMA4_c12x4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#ifndef _WIN32
#include <x86intrin.h>
#endif
#include <xmmintrin.h>
#include <ammintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f64v1_Reduce_SSE2.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f32v2_FMA_FMA4_c12x4 : public Benchmark{
public:
    f32v2_FMA_FMA4_c12x4()
        : Benchmark(48 * 2 * 4)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m128 mul0 = _mm_set1_ps(1.4142135623730950488f);
        const __m128 mul1 = _mm_set1_ps(1.7320508075688772935f);

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
        __m128 rA = _mm_set1_ps((float)(rdtsc() % 256));
        __m128 rB = _mm_set1_ps((float)(rdtsc() % 256));
        do{
            r0 = _mm_macc_ps(mul0, mul1, r0);
            r1 = _mm_macc_ps(mul0, mul1, r1);
            r2 = _mm_macc_ps(mul0, mul1, r2);
            r3 = _mm_macc_ps(mul0, mul1, r3);
            r4 = _mm_macc_ps(mul0, mul1, r4);
            r5 = _mm_macc_ps(mul0, mul1, r5);
            r6 = _mm_macc_ps(mul0, mul1, r6);
            r7 = _mm_macc_ps(mul0, mul1, r7);
            r8 = _mm_macc_ps(mul0, mul1, r8);
            r9 = _mm_macc_ps(mul0, mul1, r9);
            rA = _mm_macc_ps(mul0, mul1, rA);
            rB = _mm_macc_ps(mul0, mul1, rB);

            r0 = _mm_nmacc_ps(mul0, mul1, r0);
            r1 = _mm_nmacc_ps(mul0, mul1, r1);
            r2 = _mm_nmacc_ps(mul0, mul1, r2);
            r3 = _mm_nmacc_ps(mul0, mul1, r3);
            r4 = _mm_nmacc_ps(mul0, mul1, r4);
            r5 = _mm_nmacc_ps(mul0, mul1, r5);
            r6 = _mm_nmacc_ps(mul0, mul1, r6);
            r7 = _mm_nmacc_ps(mul0, mul1, r7);
            r8 = _mm_nmacc_ps(mul0, mul1, r8);
            r9 = _mm_nmacc_ps(mul0, mul1, r9);
            rA = _mm_nmacc_ps(mul0, mul1, rA);
            rB = _mm_nmacc_ps(mul0, mul1, rB);

            r0 = _mm_macc_ps(mul0, mul1, r0);
            r1 = _mm_macc_ps(mul0, mul1, r1);
            r2 = _mm_macc_ps(mul0, mul1, r2);
            r3 = _mm_macc_ps(mul0, mul1, r3);
            r4 = _mm_macc_ps(mul0, mul1, r4);
            r5 = _mm_macc_ps(mul0, mul1, r5);
            r6 = _mm_macc_ps(mul0, mul1, r6);
            r7 = _mm_macc_ps(mul0, mul1, r7);
            r8 = _mm_macc_ps(mul0, mul1, r8);
            r9 = _mm_macc_ps(mul0, mul1, r9);
            rA = _mm_macc_ps(mul0, mul1, rA);
            rB = _mm_macc_ps(mul0, mul1, rB);

            r0 = _mm_nmacc_ps(mul0, mul1, r0);
            r1 = _mm_nmacc_ps(mul0, mul1, r1);
            r2 = _mm_nmacc_ps(mul0, mul1, r2);
            r3 = _mm_nmacc_ps(mul0, mul1, r3);
            r4 = _mm_nmacc_ps(mul0, mul1, r4);
            r5 = _mm_nmacc_ps(mul0, mul1, r5);
            r6 = _mm_nmacc_ps(mul0, mul1, r6);
            r7 = _mm_nmacc_ps(mul0, mul1, r7);
            r8 = _mm_nmacc_ps(mul0, mul1, r8);
            r9 = _mm_nmacc_ps(mul0, mul1, r9);
            rA = _mm_nmacc_ps(mul0, mul1, rA);
            rB = _mm_nmacc_ps(mul0, mul1, rB);
        }while (--iterations);

        r0 = _mm_add_ps(r0, r6);
        r1 = _mm_add_ps(r1, r7);
        r2 = _mm_add_ps(r2, r8);
        r3 = _mm_add_ps(r3, r9);
        r4 = _mm_add_ps(r4, rA);
        r5 = _mm_add_ps(r5, rB);

        r0 = _mm_add_ps(r0, r3);
        r1 = _mm_add_ps(r1, r4);
        r2 = _mm_add_ps(r2, r5);

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
