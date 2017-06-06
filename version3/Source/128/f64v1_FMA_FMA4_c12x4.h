/* f64v1_FMA_FMA4_c12x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/29/2017
 * Last Modified    : 03/29/2017
 * 
 */

#ifndef _flops_f64v1_FMA_FMA4_c12x4_H
#define _flops_f64v1_FMA_FMA4_c12x4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#ifndef _WIN32
#include <x86intrin.h>
#endif
#include <emmintrin.h>
#include <ammintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f64v1_Reduce_SSE2.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f64v1_FMA_FMA4_c12x4 : public Benchmark{
public:
    f64v1_FMA_FMA4_c12x4()
        : Benchmark(48 * 2 * 2)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m128d mul0 = _mm_set1_pd(1.4142135623730950488);
        const __m128d mul1 = _mm_set1_pd(1.7320508075688772935);

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
        __m128d rA = _mm_set1_pd((double)(rdtsc() % 256));
        __m128d rB = _mm_set1_pd((double)(rdtsc() % 256));
        do{
            r0 = _mm_macc_pd(mul0, mul1, r0);
            r1 = _mm_macc_pd(mul0, mul1, r1);
            r2 = _mm_macc_pd(mul0, mul1, r2);
            r3 = _mm_macc_pd(mul0, mul1, r3);
            r4 = _mm_macc_pd(mul0, mul1, r4);
            r5 = _mm_macc_pd(mul0, mul1, r5);
            r6 = _mm_macc_pd(mul0, mul1, r6);
            r7 = _mm_macc_pd(mul0, mul1, r7);
            r8 = _mm_macc_pd(mul0, mul1, r8);
            r9 = _mm_macc_pd(mul0, mul1, r9);
            rA = _mm_macc_pd(mul0, mul1, rA);
            rB = _mm_macc_pd(mul0, mul1, rB);

            r0 = _mm_nmacc_pd(mul0, mul1, r0);
            r1 = _mm_nmacc_pd(mul0, mul1, r1);
            r2 = _mm_nmacc_pd(mul0, mul1, r2);
            r3 = _mm_nmacc_pd(mul0, mul1, r3);
            r4 = _mm_nmacc_pd(mul0, mul1, r4);
            r5 = _mm_nmacc_pd(mul0, mul1, r5);
            r6 = _mm_nmacc_pd(mul0, mul1, r6);
            r7 = _mm_nmacc_pd(mul0, mul1, r7);
            r8 = _mm_nmacc_pd(mul0, mul1, r8);
            r9 = _mm_nmacc_pd(mul0, mul1, r9);
            rA = _mm_nmacc_pd(mul0, mul1, rA);
            rB = _mm_nmacc_pd(mul0, mul1, rB);

            r0 = _mm_macc_pd(mul0, mul1, r0);
            r1 = _mm_macc_pd(mul0, mul1, r1);
            r2 = _mm_macc_pd(mul0, mul1, r2);
            r3 = _mm_macc_pd(mul0, mul1, r3);
            r4 = _mm_macc_pd(mul0, mul1, r4);
            r5 = _mm_macc_pd(mul0, mul1, r5);
            r6 = _mm_macc_pd(mul0, mul1, r6);
            r7 = _mm_macc_pd(mul0, mul1, r7);
            r8 = _mm_macc_pd(mul0, mul1, r8);
            r9 = _mm_macc_pd(mul0, mul1, r9);
            rA = _mm_macc_pd(mul0, mul1, rA);
            rB = _mm_macc_pd(mul0, mul1, rB);

            r0 = _mm_nmacc_pd(mul0, mul1, r0);
            r1 = _mm_nmacc_pd(mul0, mul1, r1);
            r2 = _mm_nmacc_pd(mul0, mul1, r2);
            r3 = _mm_nmacc_pd(mul0, mul1, r3);
            r4 = _mm_nmacc_pd(mul0, mul1, r4);
            r5 = _mm_nmacc_pd(mul0, mul1, r5);
            r6 = _mm_nmacc_pd(mul0, mul1, r6);
            r7 = _mm_nmacc_pd(mul0, mul1, r7);
            r8 = _mm_nmacc_pd(mul0, mul1, r8);
            r9 = _mm_nmacc_pd(mul0, mul1, r9);
            rA = _mm_nmacc_pd(mul0, mul1, rA);
            rB = _mm_nmacc_pd(mul0, mul1, rB);
        }while (--iterations);

        r0 = _mm_add_pd(r0, r6);
        r1 = _mm_add_pd(r1, r7);
        r2 = _mm_add_pd(r2, r8);
        r3 = _mm_add_pd(r3, r9);
        r4 = _mm_add_pd(r4, rA);
        r5 = _mm_add_pd(r5, rB);

        r0 = _mm_add_pd(r0, r3);
        r1 = _mm_add_pd(r1, r4);
        r2 = _mm_add_pd(r2, r5);

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
