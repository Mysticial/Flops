/* f32v4_AddFMA_AVX512_c12x2_c12x2.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 08/25/2023
 * Last Modified    : 08/25/2023
 * 
 */

#ifndef _flops_f32v4_AddFMA_AVX512_c12x2_c12x2_H
#define _flops_f32v4_AddFMA_AVX512_c12x2_c12x2_H
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
class f32v4_AddFMA_AVX512_c12x2_c12x2 : public Benchmark{
public:
    f32v4_AddFMA_AVX512_c12x2_c12x2()
        : Benchmark(2*12 * (16 + 32))
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512 mul0 = _mm512_set1_ps(1.4142135623730950488f);
        const __m512 mul1 = _mm512_set1_ps(1.7320508075688772935f);

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
            r00 = _mm512_fmadd_ps(mul0, mul1, r00);
            r01 = _mm512_add_ps(r01, mul0);
            r02 = _mm512_fmadd_ps(mul0, mul1, r02);
            r03 = _mm512_add_ps(r03, mul1);
            r04 = _mm512_fmadd_ps(mul0, mul1, r04);
            r05 = _mm512_add_ps(r05, mul0);
            r06 = _mm512_fmadd_ps(mul0, mul1, r06);
            r07 = _mm512_add_ps(r07, mul1);
            r08 = _mm512_fmadd_ps(mul0, mul1, r08);
            r09 = _mm512_add_ps(r09, mul0);
            r10 = _mm512_fmadd_ps(mul0, mul1, r10);
            r11 = _mm512_add_ps(r11, mul1);
            r12 = _mm512_fmadd_ps(mul0, mul1, r12);
            r13 = _mm512_add_ps(r13, mul0);
            r14 = _mm512_fmadd_ps(mul0, mul1, r14);
            r15 = _mm512_add_ps(r15, mul1);
            r16 = _mm512_fmadd_ps(mul0, mul1, r16);
            r17 = _mm512_add_ps(r17, mul0);
            r18 = _mm512_fmadd_ps(mul0, mul1, r18);
            r19 = _mm512_add_ps(r19, mul1);
            r20 = _mm512_fmadd_ps(mul0, mul1, r20);
            r21 = _mm512_add_ps(r21, mul0);
            r22 = _mm512_fmadd_ps(mul0, mul1, r22);
            r23 = _mm512_add_ps(r23, mul1);

            r00 = _mm512_fnmadd_ps(mul0, mul1, r00);
            r01 = _mm512_sub_ps(r01, mul0);
            r02 = _mm512_fnmadd_ps(mul0, mul1, r02);
            r03 = _mm512_sub_ps(r03, mul1);
            r04 = _mm512_fnmadd_ps(mul0, mul1, r04);
            r05 = _mm512_sub_ps(r05, mul0);
            r06 = _mm512_fnmadd_ps(mul0, mul1, r06);
            r07 = _mm512_sub_ps(r07, mul1);
            r08 = _mm512_fnmadd_ps(mul0, mul1, r08);
            r09 = _mm512_sub_ps(r09, mul0);
            r10 = _mm512_fnmadd_ps(mul0, mul1, r10);
            r11 = _mm512_sub_ps(r11, mul1);
            r12 = _mm512_fnmadd_ps(mul0, mul1, r12);
            r13 = _mm512_sub_ps(r13, mul0);
            r14 = _mm512_fnmadd_ps(mul0, mul1, r14);
            r15 = _mm512_sub_ps(r15, mul1);
            r16 = _mm512_fnmadd_ps(mul0, mul1, r16);
            r17 = _mm512_sub_ps(r17, mul0);
            r18 = _mm512_fnmadd_ps(mul0, mul1, r18);
            r19 = _mm512_sub_ps(r19, mul1);
            r20 = _mm512_fnmadd_ps(mul0, mul1, r20);
            r21 = _mm512_sub_ps(r21, mul0);
            r22 = _mm512_fnmadd_ps(mul0, mul1, r22);
            r23 = _mm512_sub_ps(r23, mul1);
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
