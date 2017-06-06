/* f32v4_Add_AVX512_c8x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/04/2017
 * 
 */

#ifndef _flops_f32v4_Add_AVX512_c8x4_H
#define _flops_f32v4_Add_AVX_c8x4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Benchmark.h"
#include "f32v4_Reduce_AVX512.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f32v4_Add_AVX512_c8x4 : public Benchmark{
public:
    f32v4_Add_AVX512_c8x4()
        : Benchmark(32 * 16)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512 add0 = _mm512_set1_ps(1.4142135623730950488f);
        const __m512 sub0 = _mm512_set1_ps(1.414213562373095f);

        __m512 r0 = _mm512_set1_ps(1.0f);
        __m512 r1 = _mm512_set1_ps(1.1f);
        __m512 r2 = _mm512_set1_ps(1.2f);
        __m512 r3 = _mm512_set1_ps(1.3f);
        __m512 r4 = _mm512_set1_ps(1.4f);
        __m512 r5 = _mm512_set1_ps(1.5f);
        __m512 r6 = _mm512_set1_ps(1.6f);
        __m512 r7 = _mm512_set1_ps(1.7f);
        do{
            r0 = _mm512_add_ps(r0, add0);
            r1 = _mm512_add_ps(r1, add0);
            r2 = _mm512_add_ps(r2, add0);
            r3 = _mm512_add_ps(r3, add0);
            r4 = _mm512_add_ps(r4, add0);
            r5 = _mm512_add_ps(r5, add0);
            r6 = _mm512_add_ps(r6, add0);
            r7 = _mm512_add_ps(r7, add0);

            r0 = _mm512_sub_ps(r0, sub0);
            r1 = _mm512_sub_ps(r1, sub0);
            r2 = _mm512_sub_ps(r2, sub0);
            r3 = _mm512_sub_ps(r3, sub0);
            r4 = _mm512_sub_ps(r4, sub0);
            r5 = _mm512_sub_ps(r5, sub0);
            r6 = _mm512_sub_ps(r6, sub0);
            r7 = _mm512_sub_ps(r7, sub0);

            r0 = _mm512_add_ps(r0, add0);
            r1 = _mm512_add_ps(r1, add0);
            r2 = _mm512_add_ps(r2, add0);
            r3 = _mm512_add_ps(r3, add0);
            r4 = _mm512_add_ps(r4, add0);
            r5 = _mm512_add_ps(r5, add0);
            r6 = _mm512_add_ps(r6, add0);
            r7 = _mm512_add_ps(r7, add0);

            r0 = _mm512_sub_ps(r0, sub0);
            r1 = _mm512_sub_ps(r1, sub0);
            r2 = _mm512_sub_ps(r2, sub0);
            r3 = _mm512_sub_ps(r3, sub0);
            r4 = _mm512_sub_ps(r4, sub0);
            r5 = _mm512_sub_ps(r5, sub0);
            r6 = _mm512_sub_ps(r6, sub0);
            r7 = _mm512_sub_ps(r7, sub0);
        }while (--iterations);

        r0 = _mm512_add_ps(r0, r4);
        r1 = _mm512_add_ps(r1, r5);
        r2 = _mm512_add_ps(r2, r6);
        r3 = _mm512_add_ps(r3, r7);

        r0 = _mm512_add_ps(r0, r2);
        r1 = _mm512_add_ps(r1, r3);

        r0 = _mm512_add_ps(r0, r1);
        return reduce(r0);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
