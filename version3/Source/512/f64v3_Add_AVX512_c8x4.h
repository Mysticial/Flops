/* f64v3_Add_AVX512_c8x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/04/2017
 * 
 */

#ifndef _flops_f64v3_Add_AVX512_c8x4_H
#define _flops_f64v3_Add_AVX512_c8x4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Benchmark.h"
#include "f64v3_Reduce_AVX512.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f64v3_Add_AVX512_c8x4 : public Benchmark{
public:
    f64v3_Add_AVX512_c8x4()
        : Benchmark(32 * 8)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512d add0 = _mm512_set1_pd(1.4142135623730950488);
        const __m512d sub0 = _mm512_set1_pd(1.414213562373095);

        __m512d r0 = _mm512_set1_pd(1.0);
        __m512d r1 = _mm512_set1_pd(1.1);
        __m512d r2 = _mm512_set1_pd(1.2);
        __m512d r3 = _mm512_set1_pd(1.3);
        __m512d r4 = _mm512_set1_pd(1.4);
        __m512d r5 = _mm512_set1_pd(1.5);
        __m512d r6 = _mm512_set1_pd(1.6);
        __m512d r7 = _mm512_set1_pd(1.7);
        do{
            r0 = _mm512_add_pd(r0, add0);
            r1 = _mm512_add_pd(r1, add0);
            r2 = _mm512_add_pd(r2, add0);
            r3 = _mm512_add_pd(r3, add0);
            r4 = _mm512_add_pd(r4, add0);
            r5 = _mm512_add_pd(r5, add0);
            r6 = _mm512_add_pd(r6, add0);
            r7 = _mm512_add_pd(r7, add0);

            r0 = _mm512_sub_pd(r0, sub0);
            r1 = _mm512_sub_pd(r1, sub0);
            r2 = _mm512_sub_pd(r2, sub0);
            r3 = _mm512_sub_pd(r3, sub0);
            r4 = _mm512_sub_pd(r4, sub0);
            r5 = _mm512_sub_pd(r5, sub0);
            r6 = _mm512_sub_pd(r6, sub0);
            r7 = _mm512_sub_pd(r7, sub0);

            r0 = _mm512_add_pd(r0, add0);
            r1 = _mm512_add_pd(r1, add0);
            r2 = _mm512_add_pd(r2, add0);
            r3 = _mm512_add_pd(r3, add0);
            r4 = _mm512_add_pd(r4, add0);
            r5 = _mm512_add_pd(r5, add0);
            r6 = _mm512_add_pd(r6, add0);
            r7 = _mm512_add_pd(r7, add0);

            r0 = _mm512_sub_pd(r0, sub0);
            r1 = _mm512_sub_pd(r1, sub0);
            r2 = _mm512_sub_pd(r2, sub0);
            r3 = _mm512_sub_pd(r3, sub0);
            r4 = _mm512_sub_pd(r4, sub0);
            r5 = _mm512_sub_pd(r5, sub0);
            r6 = _mm512_sub_pd(r6, sub0);
            r7 = _mm512_sub_pd(r7, sub0);
        }while (--iterations);

        r0 = _mm512_add_pd(r0, r4);
        r1 = _mm512_add_pd(r1, r5);
        r2 = _mm512_add_pd(r2, r6);
        r3 = _mm512_add_pd(r3, r7);

        r0 = _mm512_add_pd(r0, r2);
        r1 = _mm512_add_pd(r1, r3);

        r0 = _mm512_add_pd(r0, r1);
        return reduce(r0);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
