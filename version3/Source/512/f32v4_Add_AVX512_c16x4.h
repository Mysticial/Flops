/* f32v4_Add_AVX512_c16x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/05/2017
 * 
 */

#ifndef _flops_f32v4_Add_AVX512_c16x4_H
#define _flops_f32v4_Add_AVX512_c16x4_H
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
class f32v4_Add_AVX512_c16x4 : public Benchmark{
public:
    f32v4_Add_AVX512_c16x4()
        : Benchmark(64 * 16)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512 add0 = _mm512_set1_ps(1.4142135623730950488f);
        const __m512 sub0 = _mm512_set1_ps(1.414213562373095f);

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
        do{
            r00 = _mm512_add_ps(r00, add0);
            r01 = _mm512_add_ps(r01, add0);
            r02 = _mm512_add_ps(r02, add0);
            r03 = _mm512_add_ps(r03, add0);
            r04 = _mm512_add_ps(r04, add0);
            r05 = _mm512_add_ps(r05, add0);
            r06 = _mm512_add_ps(r06, add0);
            r07 = _mm512_add_ps(r07, add0);
            r08 = _mm512_add_ps(r08, add0);
            r09 = _mm512_add_ps(r09, add0);
            r10 = _mm512_add_ps(r10, add0);
            r11 = _mm512_add_ps(r11, add0);
            r12 = _mm512_add_ps(r12, add0);
            r13 = _mm512_add_ps(r13, add0);
            r14 = _mm512_add_ps(r14, add0);
            r15 = _mm512_add_ps(r15, add0);

            r00 = _mm512_sub_ps(r00, sub0);
            r01 = _mm512_sub_ps(r01, sub0);
            r02 = _mm512_sub_ps(r02, sub0);
            r03 = _mm512_sub_ps(r03, sub0);
            r04 = _mm512_sub_ps(r04, sub0);
            r05 = _mm512_sub_ps(r05, sub0);
            r06 = _mm512_sub_ps(r06, sub0);
            r07 = _mm512_sub_ps(r07, sub0);
            r08 = _mm512_sub_ps(r08, sub0);
            r09 = _mm512_sub_ps(r09, sub0);
            r10 = _mm512_sub_ps(r10, sub0);
            r11 = _mm512_sub_ps(r11, sub0);
            r12 = _mm512_sub_ps(r12, sub0);
            r13 = _mm512_sub_ps(r13, sub0);
            r14 = _mm512_sub_ps(r14, sub0);
            r15 = _mm512_sub_ps(r15, sub0);

            r00 = _mm512_add_ps(r00, add0);
            r01 = _mm512_add_ps(r01, add0);
            r02 = _mm512_add_ps(r02, add0);
            r03 = _mm512_add_ps(r03, add0);
            r04 = _mm512_add_ps(r04, add0);
            r05 = _mm512_add_ps(r05, add0);
            r06 = _mm512_add_ps(r06, add0);
            r07 = _mm512_add_ps(r07, add0);
            r08 = _mm512_add_ps(r08, add0);
            r09 = _mm512_add_ps(r09, add0);
            r10 = _mm512_add_ps(r10, add0);
            r11 = _mm512_add_ps(r11, add0);
            r12 = _mm512_add_ps(r12, add0);
            r13 = _mm512_add_ps(r13, add0);
            r14 = _mm512_add_ps(r14, add0);
            r15 = _mm512_add_ps(r15, add0);

            r00 = _mm512_sub_ps(r00, sub0);
            r01 = _mm512_sub_ps(r01, sub0);
            r02 = _mm512_sub_ps(r02, sub0);
            r03 = _mm512_sub_ps(r03, sub0);
            r04 = _mm512_sub_ps(r04, sub0);
            r05 = _mm512_sub_ps(r05, sub0);
            r06 = _mm512_sub_ps(r06, sub0);
            r07 = _mm512_sub_ps(r07, sub0);
            r08 = _mm512_sub_ps(r08, sub0);
            r09 = _mm512_sub_ps(r09, sub0);
            r10 = _mm512_sub_ps(r10, sub0);
            r11 = _mm512_sub_ps(r11, sub0);
            r12 = _mm512_sub_ps(r12, sub0);
            r13 = _mm512_sub_ps(r13, sub0);
            r14 = _mm512_sub_ps(r14, sub0);
            r15 = _mm512_sub_ps(r15, sub0);
        }while (--iterations);

        r00 = _mm512_add_ps(r00, r08);
        r01 = _mm512_add_ps(r01, r09);
        r02 = _mm512_add_ps(r02, r10);
        r03 = _mm512_add_ps(r03, r11);
        r04 = _mm512_add_ps(r04, r12);
        r05 = _mm512_add_ps(r05, r13);
        r06 = _mm512_add_ps(r06, r14);
        r07 = _mm512_add_ps(r07, r15);

        r00 = _mm512_add_ps(r00, r04);
        r01 = _mm512_add_ps(r01, r05);
        r02 = _mm512_add_ps(r02, r06);
        r03 = _mm512_add_ps(r03, r07);

        r00 = _mm512_add_ps(r00, r02);
        r01 = _mm512_add_ps(r01, r03);

        r00 = _mm512_add_ps(r00, r01);
        return reduce(r00);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
