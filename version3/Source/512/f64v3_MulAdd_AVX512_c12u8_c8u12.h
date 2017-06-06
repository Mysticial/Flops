/* f64v3_MulAdd_AVX512_c12u8_c8u12.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/27/2017
 * Last Modified    : 03/27/2017
 * 
 */

#ifndef _flops_f64v3_MulAdd_AVX512_c12u8_c8u12_H
#define _flops_f64v3_MulAdd_AVX512_c12u8_c8u12_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Tools.h"
#include "../Benchmark.h"
#include "f64v3_Reduce_AVX512.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f64v3_MulAdd_AVX512_c12u8_c8u12 : public Benchmark{
public:
    f64v3_MulAdd_AVX512_c12u8_c8u12()
        : Benchmark(96 * 8)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512d mul0 = _mm512_set1_pd(1.4142135623730950488);
        const __m512d mul1 = _mm512_set1_pd(0.70710678118654752440);

        //  12 multiply chains and 8 add chains
        __m512d r00 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r01 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r02 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r03 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r04 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r05 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r06 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r07 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r08 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r09 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r10 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r11 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r12 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r13 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r14 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r15 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r16 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r17 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r18 = _mm512_set1_pd((double)(rdtsc() % 256));
        __m512d r19 = _mm512_set1_pd((double)(rdtsc() % 256));
        do{
            r00 = _mm512_mul_pd(r00, mul0);
            r06 = _mm512_add_pd(r06, mul0);
            r01 = _mm512_mul_pd(r01, mul0);
            r07 = _mm512_add_pd(r07, mul0);
            r02 = _mm512_mul_pd(r02, mul0);
            r08 = _mm512_add_pd(r08, mul0);
            r03 = _mm512_mul_pd(r03, mul0);
            r09 = _mm512_add_pd(r09, mul0);
            r04 = _mm512_mul_pd(r04, mul0);
            r06 = _mm512_sub_pd(r06, mul0);
            r05 = _mm512_mul_pd(r05, mul0);
            r07 = _mm512_sub_pd(r07, mul0);
            r10 = _mm512_mul_pd(r10, mul0);
            r16 = _mm512_add_pd(r16, mul0);
            r11 = _mm512_mul_pd(r11, mul0);
            r17 = _mm512_add_pd(r17, mul0);
            r12 = _mm512_mul_pd(r12, mul0);
            r18 = _mm512_add_pd(r18, mul0);
            r13 = _mm512_mul_pd(r13, mul0);
            r19 = _mm512_add_pd(r19, mul0);
            r14 = _mm512_mul_pd(r14, mul0);
            r16 = _mm512_sub_pd(r16, mul0);
            r15 = _mm512_mul_pd(r15, mul0);
            r17 = _mm512_sub_pd(r17, mul0);

            r00 = _mm512_mul_pd(r00, mul1);
            r08 = _mm512_sub_pd(r08, mul0);
            r01 = _mm512_mul_pd(r01, mul1);
            r09 = _mm512_sub_pd(r09, mul0);
            r02 = _mm512_mul_pd(r02, mul1);
            r06 = _mm512_add_pd(r06, mul1);
            r03 = _mm512_mul_pd(r03, mul1);
            r07 = _mm512_add_pd(r07, mul1);
            r04 = _mm512_mul_pd(r04, mul1);
            r08 = _mm512_add_pd(r08, mul1);
            r05 = _mm512_mul_pd(r05, mul1);
            r09 = _mm512_add_pd(r09, mul1);
            r10 = _mm512_mul_pd(r10, mul1);
            r18 = _mm512_sub_pd(r18, mul0);
            r11 = _mm512_mul_pd(r11, mul1);
            r19 = _mm512_sub_pd(r19, mul0);
            r12 = _mm512_mul_pd(r12, mul1);
            r16 = _mm512_add_pd(r16, mul1);
            r13 = _mm512_mul_pd(r13, mul1);
            r17 = _mm512_add_pd(r17, mul1);
            r14 = _mm512_mul_pd(r14, mul1);
            r18 = _mm512_add_pd(r18, mul1);
            r15 = _mm512_mul_pd(r15, mul1);
            r19 = _mm512_add_pd(r19, mul1);

            r00 = _mm512_mul_pd(r00, mul0);
            r06 = _mm512_sub_pd(r06, mul1);
            r01 = _mm512_mul_pd(r01, mul0);
            r07 = _mm512_sub_pd(r07, mul1);
            r02 = _mm512_mul_pd(r02, mul0);
            r08 = _mm512_sub_pd(r08, mul1);
            r03 = _mm512_mul_pd(r03, mul0);
            r09 = _mm512_sub_pd(r09, mul1);
            r04 = _mm512_mul_pd(r04, mul0);
            r06 = _mm512_add_pd(r06, mul0);
            r05 = _mm512_mul_pd(r05, mul0);
            r07 = _mm512_add_pd(r07, mul0);
            r10 = _mm512_mul_pd(r10, mul0);
            r16 = _mm512_sub_pd(r16, mul1);
            r11 = _mm512_mul_pd(r11, mul0);
            r17 = _mm512_sub_pd(r17, mul1);
            r12 = _mm512_mul_pd(r12, mul0);
            r18 = _mm512_sub_pd(r18, mul1);
            r13 = _mm512_mul_pd(r13, mul0);
            r19 = _mm512_sub_pd(r19, mul1);
            r14 = _mm512_mul_pd(r14, mul0);
            r16 = _mm512_add_pd(r16, mul0);
            r15 = _mm512_mul_pd(r15, mul0);
            r17 = _mm512_add_pd(r17, mul0);

            r00 = _mm512_mul_pd(r00, mul1);
            r08 = _mm512_add_pd(r08, mul0);
            r01 = _mm512_mul_pd(r01, mul1);
            r09 = _mm512_add_pd(r09, mul0);
            r02 = _mm512_mul_pd(r02, mul1);
            r06 = _mm512_sub_pd(r06, mul0);
            r03 = _mm512_mul_pd(r03, mul1);
            r07 = _mm512_sub_pd(r07, mul0);
            r04 = _mm512_mul_pd(r04, mul1);
            r08 = _mm512_sub_pd(r08, mul0);
            r05 = _mm512_mul_pd(r05, mul1);
            r09 = _mm512_sub_pd(r09, mul0);
            r10 = _mm512_mul_pd(r10, mul1);
            r18 = _mm512_add_pd(r18, mul0);
            r11 = _mm512_mul_pd(r11, mul1);
            r19 = _mm512_add_pd(r19, mul0);
            r12 = _mm512_mul_pd(r12, mul1);
            r16 = _mm512_sub_pd(r16, mul0);
            r13 = _mm512_mul_pd(r13, mul1);
            r17 = _mm512_sub_pd(r17, mul0);
            r14 = _mm512_mul_pd(r14, mul1);
            r18 = _mm512_sub_pd(r18, mul0);
            r15 = _mm512_mul_pd(r15, mul1);
            r19 = _mm512_sub_pd(r19, mul0);
        }while (--iterations);

        r00 = _mm512_add_pd(r00, r10);
        r01 = _mm512_add_pd(r01, r11);
        r02 = _mm512_add_pd(r02, r12);
        r03 = _mm512_add_pd(r03, r13);
        r04 = _mm512_add_pd(r04, r14);
        r05 = _mm512_add_pd(r05, r15);
        r06 = _mm512_add_pd(r06, r16);
        r07 = _mm512_add_pd(r07, r17);
        r08 = _mm512_add_pd(r08, r18);
        r09 = _mm512_add_pd(r09, r19);

        r00 = _mm512_add_pd(r00, r05);
        r01 = _mm512_add_pd(r01, r06);
        r02 = _mm512_add_pd(r02, r07);
        r03 = _mm512_add_pd(r03, r08);
        r04 = _mm512_add_pd(r04, r09);

        r00 = _mm512_add_pd(r00, r03);
        r01 = _mm512_add_pd(r01, r04);

        r00 = _mm512_add_pd(r00, r01);
        r00 = _mm512_add_pd(r00, r02);
        return reduce(r00);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
