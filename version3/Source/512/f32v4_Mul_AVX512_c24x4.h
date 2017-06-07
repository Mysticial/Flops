/* f32v4_Mul_AVX512_c24x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/04/2017
 * 
 */

#ifndef _flops_f32v4_Mul_AVX512_c24x4_H
#define _flops_f32v4_Mul_AVX512_c24x4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f32v4_Reduce_AVX512.h"

#if __INTEL_COMPILER && !(defined x64_2016_KnightsLanding) && !(defined x64_2017_SkylakePurley)
#warning "The Intel Compiler does a shit job of optimizing this."
#endif

namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f32v4_Mul_AVX512_c24x4 : public Benchmark{
public:
    f32v4_Mul_AVX512_c24x4()
        : Benchmark(96 * 16)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512 mul0 = _mm512_set1_ps(1.4142135623730950488f);
        const __m512 mul1 = _mm512_set1_ps(0.70710678118654752440f);

        __m512 r00 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r01 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r02 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r03 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r04 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r05 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r06 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r07 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r08 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r09 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r10 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r11 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r12 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r13 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r14 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r15 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r16 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r17 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r18 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r19 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r20 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r21 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r22 = _mm512_set1_ps((float)(rdtsc() % 256));
        __m512 r23 = _mm512_set1_ps((float)(rdtsc() % 256));
        do{
            r00 = _mm512_mul_ps(r00, mul0);
            r01 = _mm512_mul_ps(r01, mul0);
            r02 = _mm512_mul_ps(r02, mul0);
            r03 = _mm512_mul_ps(r03, mul0);
            r04 = _mm512_mul_ps(r04, mul0);
            r05 = _mm512_mul_ps(r05, mul0);
            r06 = _mm512_mul_ps(r06, mul0);
            r07 = _mm512_mul_ps(r07, mul0);
            r08 = _mm512_mul_ps(r08, mul0);
            r09 = _mm512_mul_ps(r09, mul0);
            r10 = _mm512_mul_ps(r10, mul0);
            r11 = _mm512_mul_ps(r11, mul0);
            r12 = _mm512_mul_ps(r12, mul0);
            r13 = _mm512_mul_ps(r13, mul0);
            r14 = _mm512_mul_ps(r14, mul0);
            r15 = _mm512_mul_ps(r15, mul0);
            r16 = _mm512_mul_ps(r16, mul0);
            r17 = _mm512_mul_ps(r17, mul0);
            r18 = _mm512_mul_ps(r18, mul0);
            r19 = _mm512_mul_ps(r19, mul0);
            r20 = _mm512_mul_ps(r20, mul0);
            r21 = _mm512_mul_ps(r21, mul0);
            r22 = _mm512_mul_ps(r22, mul0);
            r23 = _mm512_mul_ps(r23, mul0);

            r00 = _mm512_mul_ps(r00, mul1);
            r01 = _mm512_mul_ps(r01, mul1);
            r02 = _mm512_mul_ps(r02, mul1);
            r03 = _mm512_mul_ps(r03, mul1);
            r04 = _mm512_mul_ps(r04, mul1);
            r05 = _mm512_mul_ps(r05, mul1);
            r06 = _mm512_mul_ps(r06, mul1);
            r07 = _mm512_mul_ps(r07, mul1);
            r08 = _mm512_mul_ps(r08, mul1);
            r09 = _mm512_mul_ps(r09, mul1);
            r10 = _mm512_mul_ps(r10, mul1);
            r11 = _mm512_mul_ps(r11, mul1);
            r12 = _mm512_mul_ps(r12, mul1);
            r13 = _mm512_mul_ps(r13, mul1);
            r14 = _mm512_mul_ps(r14, mul1);
            r15 = _mm512_mul_ps(r15, mul1);
            r16 = _mm512_mul_ps(r16, mul1);
            r17 = _mm512_mul_ps(r17, mul1);
            r18 = _mm512_mul_ps(r18, mul1);
            r19 = _mm512_mul_ps(r19, mul1);
            r20 = _mm512_mul_ps(r20, mul1);
            r21 = _mm512_mul_ps(r21, mul1);
            r22 = _mm512_mul_ps(r22, mul1);
            r23 = _mm512_mul_ps(r23, mul1);

            r00 = _mm512_mul_ps(r00, mul0);
            r01 = _mm512_mul_ps(r01, mul0);
            r02 = _mm512_mul_ps(r02, mul0);
            r03 = _mm512_mul_ps(r03, mul0);
            r04 = _mm512_mul_ps(r04, mul0);
            r05 = _mm512_mul_ps(r05, mul0);
            r06 = _mm512_mul_ps(r06, mul0);
            r07 = _mm512_mul_ps(r07, mul0);
            r08 = _mm512_mul_ps(r08, mul0);
            r09 = _mm512_mul_ps(r09, mul0);
            r10 = _mm512_mul_ps(r10, mul0);
            r11 = _mm512_mul_ps(r11, mul0);
            r12 = _mm512_mul_ps(r12, mul0);
            r13 = _mm512_mul_ps(r13, mul0);
            r14 = _mm512_mul_ps(r14, mul0);
            r15 = _mm512_mul_ps(r15, mul0);
            r16 = _mm512_mul_ps(r16, mul0);
            r17 = _mm512_mul_ps(r17, mul0);
            r18 = _mm512_mul_ps(r18, mul0);
            r19 = _mm512_mul_ps(r19, mul0);
            r20 = _mm512_mul_ps(r20, mul0);
            r21 = _mm512_mul_ps(r21, mul0);
            r22 = _mm512_mul_ps(r22, mul0);
            r23 = _mm512_mul_ps(r23, mul0);

            r00 = _mm512_mul_ps(r00, mul1);
            r01 = _mm512_mul_ps(r01, mul1);
            r02 = _mm512_mul_ps(r02, mul1);
            r03 = _mm512_mul_ps(r03, mul1);
            r04 = _mm512_mul_ps(r04, mul1);
            r05 = _mm512_mul_ps(r05, mul1);
            r06 = _mm512_mul_ps(r06, mul1);
            r07 = _mm512_mul_ps(r07, mul1);
            r08 = _mm512_mul_ps(r08, mul1);
            r09 = _mm512_mul_ps(r09, mul1);
            r10 = _mm512_mul_ps(r10, mul1);
            r11 = _mm512_mul_ps(r11, mul1);
            r12 = _mm512_mul_ps(r12, mul1);
            r13 = _mm512_mul_ps(r13, mul1);
            r14 = _mm512_mul_ps(r14, mul1);
            r15 = _mm512_mul_ps(r15, mul1);
            r16 = _mm512_mul_ps(r16, mul1);
            r17 = _mm512_mul_ps(r17, mul1);
            r18 = _mm512_mul_ps(r18, mul1);
            r19 = _mm512_mul_ps(r19, mul1);
            r20 = _mm512_mul_ps(r20, mul1);
            r21 = _mm512_mul_ps(r21, mul1);
            r22 = _mm512_mul_ps(r22, mul1);
            r23 = _mm512_mul_ps(r23, mul1);
        }while (--iterations);

        r00 = _mm512_add_ps(r00, r12);
        r01 = _mm512_add_ps(r01, r13);
        r02 = _mm512_add_ps(r02, r14);
        r03 = _mm512_add_ps(r03, r15);
        r04 = _mm512_add_ps(r04, r16);
        r05 = _mm512_add_ps(r05, r17);
        r06 = _mm512_add_ps(r06, r18);
        r07 = _mm512_add_ps(r07, r19);
        r08 = _mm512_add_ps(r08, r20);
        r09 = _mm512_add_ps(r09, r21);
        r10 = _mm512_add_ps(r10, r22);
        r11 = _mm512_add_ps(r11, r23);

        r00 = _mm512_add_ps(r00, r06);
        r01 = _mm512_add_ps(r01, r07);
        r02 = _mm512_add_ps(r02, r08);
        r03 = _mm512_add_ps(r03, r09);
        r04 = _mm512_add_ps(r04, r10);
        r05 = _mm512_add_ps(r05, r11);

        r00 = _mm512_add_ps(r00, r03);
        r01 = _mm512_add_ps(r01, r04);
        r02 = _mm512_add_ps(r02, r05);

        r00 = _mm512_add_ps(r00, r01);
        r00 = _mm512_add_ps(r00, r02);
        return reduce(r00);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
