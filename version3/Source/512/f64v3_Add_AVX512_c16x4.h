/* f64v3_Add_AVX512_c16x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/04/2017
 * 
 */

#ifndef _flops_f64v3_Add_AVX512_c16x4_H
#define _flops_f64v3_Add_AVX512_c16x4_H
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
class f64v3_Add_AVX512_c16x4 : public Benchmark{
public:
    f64v3_Add_AVX512_c16x4()
        : Benchmark(64 * 8)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512d add0 = _mm512_set1_pd(1.4142135623730950488);
        const __m512d sub0 = _mm512_set1_pd(1.414213562373095);

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
        do{
            r00 = _mm512_add_pd(r00, add0);
            r01 = _mm512_add_pd(r01, add0);
            r02 = _mm512_add_pd(r02, add0);
            r03 = _mm512_add_pd(r03, add0);
            r04 = _mm512_add_pd(r04, add0);
            r05 = _mm512_add_pd(r05, add0);
            r06 = _mm512_add_pd(r06, add0);
            r07 = _mm512_add_pd(r07, add0);
            r08 = _mm512_add_pd(r08, add0);
            r09 = _mm512_add_pd(r09, add0);
            r10 = _mm512_add_pd(r10, add0);
            r11 = _mm512_add_pd(r11, add0);
            r12 = _mm512_add_pd(r12, add0);
            r13 = _mm512_add_pd(r13, add0);
            r14 = _mm512_add_pd(r14, add0);
            r15 = _mm512_add_pd(r15, add0);

            r00 = _mm512_sub_pd(r00, sub0);
            r01 = _mm512_sub_pd(r01, sub0);
            r02 = _mm512_sub_pd(r02, sub0);
            r03 = _mm512_sub_pd(r03, sub0);
            r04 = _mm512_sub_pd(r04, sub0);
            r05 = _mm512_sub_pd(r05, sub0);
            r06 = _mm512_sub_pd(r06, sub0);
            r07 = _mm512_sub_pd(r07, sub0);
            r08 = _mm512_sub_pd(r08, sub0);
            r09 = _mm512_sub_pd(r09, sub0);
            r10 = _mm512_sub_pd(r10, sub0);
            r11 = _mm512_sub_pd(r11, sub0);
            r12 = _mm512_sub_pd(r12, sub0);
            r13 = _mm512_sub_pd(r13, sub0);
            r14 = _mm512_sub_pd(r14, sub0);
            r15 = _mm512_sub_pd(r15, sub0);

            r00 = _mm512_add_pd(r00, add0);
            r01 = _mm512_add_pd(r01, add0);
            r02 = _mm512_add_pd(r02, add0);
            r03 = _mm512_add_pd(r03, add0);
            r04 = _mm512_add_pd(r04, add0);
            r05 = _mm512_add_pd(r05, add0);
            r06 = _mm512_add_pd(r06, add0);
            r07 = _mm512_add_pd(r07, add0);
            r08 = _mm512_add_pd(r08, add0);
            r09 = _mm512_add_pd(r09, add0);
            r10 = _mm512_add_pd(r10, add0);
            r11 = _mm512_add_pd(r11, add0);
            r12 = _mm512_add_pd(r12, add0);
            r13 = _mm512_add_pd(r13, add0);
            r14 = _mm512_add_pd(r14, add0);
            r15 = _mm512_add_pd(r15, add0);

            r00 = _mm512_sub_pd(r00, sub0);
            r01 = _mm512_sub_pd(r01, sub0);
            r02 = _mm512_sub_pd(r02, sub0);
            r03 = _mm512_sub_pd(r03, sub0);
            r04 = _mm512_sub_pd(r04, sub0);
            r05 = _mm512_sub_pd(r05, sub0);
            r06 = _mm512_sub_pd(r06, sub0);
            r07 = _mm512_sub_pd(r07, sub0);
            r08 = _mm512_sub_pd(r08, sub0);
            r09 = _mm512_sub_pd(r09, sub0);
            r10 = _mm512_sub_pd(r10, sub0);
            r11 = _mm512_sub_pd(r11, sub0);
            r12 = _mm512_sub_pd(r12, sub0);
            r13 = _mm512_sub_pd(r13, sub0);
            r14 = _mm512_sub_pd(r14, sub0);
            r15 = _mm512_sub_pd(r15, sub0);
        }while (--iterations);

        r00 = _mm512_add_pd(r00, r08);
        r01 = _mm512_add_pd(r01, r09);
        r02 = _mm512_add_pd(r02, r10);
        r03 = _mm512_add_pd(r03, r11);
        r04 = _mm512_add_pd(r04, r12);
        r05 = _mm512_add_pd(r05, r13);
        r06 = _mm512_add_pd(r06, r14);
        r07 = _mm512_add_pd(r07, r15);

        r00 = _mm512_add_pd(r00, r04);
        r01 = _mm512_add_pd(r01, r05);
        r02 = _mm512_add_pd(r02, r06);
        r03 = _mm512_add_pd(r03, r07);

        r00 = _mm512_add_pd(r00, r02);
        r01 = _mm512_add_pd(r01, r03);

        r00 = _mm512_add_pd(r00, r01);
        return reduce(r00);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
