/* f32v4_MulAdd_AV512X_c6u4_c4u6.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/27/2017
 * Last Modified    : 03/27/2017
 * 
 */

#ifndef _flops_f32v4_MulAdd_AVX512_c6u4_c4u6_H
#define _flops_f32v4_MulAdd_AVX512_c6u4_c4u6_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Benchmark.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f32v4_MulAdd_AVX512_c6u4_c4u6 : public Benchmark{
public:
    f32v4_MulAdd_AVX512_c6u4_c4u6()
        : Benchmark(48 * 16)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512 mul0 = _mm512_set1_ps(1.4142135623730950488f);
        const __m512 mul1 = _mm512_set1_ps(0.70710678118654752440f);

        //  6 multiply chains and 4 add chains
        __m512 r0 = _mm512_set1_ps(1.0f);
        __m512 r1 = _mm512_set1_ps(1.1f);
        __m512 r2 = _mm512_set1_ps(1.2f);
        __m512 r3 = _mm512_set1_ps(1.3f);
        __m512 r4 = _mm512_set1_ps(1.4f);
        __m512 r5 = _mm512_set1_ps(1.5f);
        __m512 r6 = _mm512_set1_ps(1.6f);
        __m512 r7 = _mm512_set1_ps(1.7f);
        __m512 r8 = _mm512_set1_ps(1.8f);
        __m512 r9 = _mm512_set1_ps(1.9f);
        do{
            r0 = _mm512_mul_ps(r0, mul0);
            r6 = _mm512_add_ps(r6, mul0);
            r1 = _mm512_mul_ps(r1, mul0);
            r7 = _mm512_add_ps(r7, mul0);
            r2 = _mm512_mul_ps(r2, mul0);
            r8 = _mm512_add_ps(r8, mul0);
            r3 = _mm512_mul_ps(r3, mul0);
            r9 = _mm512_add_ps(r9, mul0);
            r4 = _mm512_mul_ps(r4, mul0);
            r6 = _mm512_sub_ps(r6, mul0);
            r5 = _mm512_mul_ps(r5, mul0);
            r7 = _mm512_sub_ps(r7, mul0);

            r0 = _mm512_mul_ps(r0, mul1);
            r8 = _mm512_sub_ps(r8, mul0);
            r1 = _mm512_mul_ps(r1, mul1);
            r9 = _mm512_sub_ps(r9, mul0);
            r2 = _mm512_mul_ps(r2, mul1);
            r6 = _mm512_add_ps(r6, mul1);
            r3 = _mm512_mul_ps(r3, mul1);
            r7 = _mm512_add_ps(r7, mul1);
            r4 = _mm512_mul_ps(r4, mul1);
            r8 = _mm512_add_ps(r8, mul1);
            r5 = _mm512_mul_ps(r5, mul1);
            r9 = _mm512_add_ps(r9, mul1);

            r0 = _mm512_mul_ps(r0, mul0);
            r6 = _mm512_sub_ps(r6, mul1);
            r1 = _mm512_mul_ps(r1, mul0);
            r7 = _mm512_sub_ps(r7, mul1);
            r2 = _mm512_mul_ps(r2, mul0);
            r8 = _mm512_sub_ps(r8, mul1);
            r3 = _mm512_mul_ps(r3, mul0);
            r9 = _mm512_sub_ps(r9, mul1);
            r4 = _mm512_mul_ps(r4, mul0);
            r6 = _mm512_add_ps(r6, mul0);
            r5 = _mm512_mul_ps(r5, mul0);
            r7 = _mm512_add_ps(r7, mul0);

            r0 = _mm512_mul_ps(r0, mul1);
            r8 = _mm512_add_ps(r8, mul0);
            r1 = _mm512_mul_ps(r1, mul1);
            r9 = _mm512_add_ps(r9, mul0);
            r2 = _mm512_mul_ps(r2, mul1);
            r6 = _mm512_sub_ps(r6, mul0);
            r3 = _mm512_mul_ps(r3, mul1);
            r7 = _mm512_sub_ps(r7, mul0);
            r4 = _mm512_mul_ps(r4, mul1);
            r8 = _mm512_sub_ps(r8, mul0);
            r5 = _mm512_mul_ps(r5, mul1);
            r9 = _mm512_sub_ps(r9, mul0);
        }while (--iterations);

        r0 = _mm512_add_ps(r0, r5);
        r1 = _mm512_add_ps(r1, r6);
        r2 = _mm512_add_ps(r2, r7);
        r3 = _mm512_add_ps(r3, r8);
        r4 = _mm512_add_ps(r4, r9);

        r0 = _mm512_add_ps(r0, r3);
        r1 = _mm512_add_ps(r1, r4);

        r0 = _mm512_add_ps(r0, r1);
        r0 = _mm512_add_ps(r0, r2);

        __m256 y = _mm256_add_ps(
            _mm512_castps512_ps256(r0),
            _mm256_castsi256_ps(_mm512_extracti64x4_epi64(_mm512_castps_si512(r0), 1))
        );
        __m128 x = _mm_add_ps(_mm256_castps256_ps128(y), _mm256_extractf128_ps(y, 1));
        x = _mm_add_ps(x, _mm_unpackhi_ps(x, x));
        x = _mm_add_ps(x, _mm_shuffle_ps(x, x, 1));
        return _mm_cvtss_f32(x);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
