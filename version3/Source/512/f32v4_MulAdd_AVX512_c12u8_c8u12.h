/* f32v4_MulAdd_AV512X_c12u8_c8u12.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/27/2017
 * Last Modified    : 03/27/2017
 * 
 */

#ifndef _flops_f32v4_MulAdd_AVX512_c12u8_c8u12_H
#define _flops_f32v4_MulAdd_AVX512_c12u8_c8u12_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f32v4_Reduce_AVX512.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f32v4_MulAdd_AVX512_c12u8_c8u12 : public Benchmark{
public:
    f32v4_MulAdd_AVX512_c12u8_c8u12()
        : Benchmark(96 * 16)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512 mul0 = _mm512_set1_ps(1.4142135623730950488f);
        const __m512 mul1 = _mm512_set1_ps(0.70710678118654752440f);

        //  12 multiply chains and 8 add chains
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
        do{
            r00 = _mm512_mul_ps(r00, mul0);
            r06 = _mm512_add_ps(r06, mul0);
            r01 = _mm512_mul_ps(r01, mul0);
            r07 = _mm512_add_ps(r07, mul0);
            r02 = _mm512_mul_ps(r02, mul0);
            r08 = _mm512_add_ps(r08, mul0);
            r03 = _mm512_mul_ps(r03, mul0);
            r09 = _mm512_add_ps(r09, mul0);
            r04 = _mm512_mul_ps(r04, mul0);
            r06 = _mm512_sub_ps(r06, mul0);
            r05 = _mm512_mul_ps(r05, mul0);
            r07 = _mm512_sub_ps(r07, mul0);
            r10 = _mm512_mul_ps(r10, mul0);
            r16 = _mm512_add_ps(r16, mul0);
            r11 = _mm512_mul_ps(r11, mul0);
            r17 = _mm512_add_ps(r17, mul0);
            r12 = _mm512_mul_ps(r12, mul0);
            r18 = _mm512_add_ps(r18, mul0);
            r13 = _mm512_mul_ps(r13, mul0);
            r19 = _mm512_add_ps(r19, mul0);
            r14 = _mm512_mul_ps(r14, mul0);
            r16 = _mm512_sub_ps(r16, mul0);
            r15 = _mm512_mul_ps(r15, mul0);
            r17 = _mm512_sub_ps(r17, mul0);

            r00 = _mm512_mul_ps(r00, mul1);
            r08 = _mm512_sub_ps(r08, mul0);
            r01 = _mm512_mul_ps(r01, mul1);
            r09 = _mm512_sub_ps(r09, mul0);
            r02 = _mm512_mul_ps(r02, mul1);
            r06 = _mm512_add_ps(r06, mul1);
            r03 = _mm512_mul_ps(r03, mul1);
            r07 = _mm512_add_ps(r07, mul1);
            r04 = _mm512_mul_ps(r04, mul1);
            r08 = _mm512_add_ps(r08, mul1);
            r05 = _mm512_mul_ps(r05, mul1);
            r09 = _mm512_add_ps(r09, mul1);
            r10 = _mm512_mul_ps(r10, mul1);
            r18 = _mm512_sub_ps(r18, mul0);
            r11 = _mm512_mul_ps(r11, mul1);
            r19 = _mm512_sub_ps(r19, mul0);
            r12 = _mm512_mul_ps(r12, mul1);
            r16 = _mm512_add_ps(r16, mul1);
            r13 = _mm512_mul_ps(r13, mul1);
            r17 = _mm512_add_ps(r17, mul1);
            r14 = _mm512_mul_ps(r14, mul1);
            r18 = _mm512_add_ps(r18, mul1);
            r15 = _mm512_mul_ps(r15, mul1);
            r19 = _mm512_add_ps(r19, mul1);

            r00 = _mm512_mul_ps(r00, mul0);
            r06 = _mm512_sub_ps(r06, mul1);
            r01 = _mm512_mul_ps(r01, mul0);
            r07 = _mm512_sub_ps(r07, mul1);
            r02 = _mm512_mul_ps(r02, mul0);
            r08 = _mm512_sub_ps(r08, mul1);
            r03 = _mm512_mul_ps(r03, mul0);
            r09 = _mm512_sub_ps(r09, mul1);
            r04 = _mm512_mul_ps(r04, mul0);
            r06 = _mm512_add_ps(r06, mul0);
            r05 = _mm512_mul_ps(r05, mul0);
            r07 = _mm512_add_ps(r07, mul0);
            r10 = _mm512_mul_ps(r10, mul0);
            r16 = _mm512_sub_ps(r16, mul1);
            r11 = _mm512_mul_ps(r11, mul0);
            r17 = _mm512_sub_ps(r17, mul1);
            r12 = _mm512_mul_ps(r12, mul0);
            r18 = _mm512_sub_ps(r18, mul1);
            r13 = _mm512_mul_ps(r13, mul0);
            r19 = _mm512_sub_ps(r19, mul1);
            r14 = _mm512_mul_ps(r14, mul0);
            r16 = _mm512_add_ps(r16, mul0);
            r15 = _mm512_mul_ps(r15, mul0);
            r17 = _mm512_add_ps(r17, mul0);

            r00 = _mm512_mul_ps(r00, mul1);
            r08 = _mm512_add_ps(r08, mul0);
            r01 = _mm512_mul_ps(r01, mul1);
            r09 = _mm512_add_ps(r09, mul0);
            r02 = _mm512_mul_ps(r02, mul1);
            r06 = _mm512_sub_ps(r06, mul0);
            r03 = _mm512_mul_ps(r03, mul1);
            r07 = _mm512_sub_ps(r07, mul0);
            r04 = _mm512_mul_ps(r04, mul1);
            r08 = _mm512_sub_ps(r08, mul0);
            r05 = _mm512_mul_ps(r05, mul1);
            r09 = _mm512_sub_ps(r09, mul0);
            r10 = _mm512_mul_ps(r10, mul1);
            r18 = _mm512_add_ps(r18, mul0);
            r11 = _mm512_mul_ps(r11, mul1);
            r19 = _mm512_add_ps(r19, mul0);
            r12 = _mm512_mul_ps(r12, mul1);
            r16 = _mm512_sub_ps(r16, mul0);
            r13 = _mm512_mul_ps(r13, mul1);
            r17 = _mm512_sub_ps(r17, mul0);
            r14 = _mm512_mul_ps(r14, mul1);
            r18 = _mm512_sub_ps(r18, mul0);
            r15 = _mm512_mul_ps(r15, mul1);
            r19 = _mm512_sub_ps(r19, mul0);
        }while (--iterations);

        r00 = _mm512_add_ps(r00, r10);
        r01 = _mm512_add_ps(r01, r11);
        r02 = _mm512_add_ps(r02, r12);
        r03 = _mm512_add_ps(r03, r13);
        r04 = _mm512_add_ps(r04, r14);
        r05 = _mm512_add_ps(r05, r15);
        r06 = _mm512_add_ps(r06, r16);
        r07 = _mm512_add_ps(r07, r17);
        r08 = _mm512_add_ps(r08, r18);
        r09 = _mm512_add_ps(r09, r19);

        r00 = _mm512_add_ps(r00, r05);
        r01 = _mm512_add_ps(r01, r06);
        r02 = _mm512_add_ps(r02, r07);
        r03 = _mm512_add_ps(r03, r08);
        r04 = _mm512_add_ps(r04, r09);

        r00 = _mm512_add_ps(r00, r03);
        r01 = _mm512_add_ps(r01, r04);

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
