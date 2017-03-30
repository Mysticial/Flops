/* f32v3_Add_AVX_c8x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/27/2017
 * Last Modified    : 03/27/2017
 * 
 */

#ifndef _flops_f32v3_Add_AVX_c8x4_H
#define _flops_f32v3_Add_AVX_c8x4_H
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
class f32v3_Add_AVX_c8x4 : public Benchmark{
public:
    f32v3_Add_AVX_c8x4()
        : Benchmark(32 * 8)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m256 add0 = _mm256_set1_ps(1.4142135623730950488f);
        const __m256 sub0 = _mm256_set1_ps(1.414213562373095f);

        __m256 r0 = _mm256_set1_ps(1.0f);
        __m256 r1 = _mm256_set1_ps(1.1f);
        __m256 r2 = _mm256_set1_ps(1.2f);
        __m256 r3 = _mm256_set1_ps(1.3f);
        __m256 r4 = _mm256_set1_ps(1.4f);
        __m256 r5 = _mm256_set1_ps(1.5f);
        __m256 r6 = _mm256_set1_ps(1.6f);
        __m256 r7 = _mm256_set1_ps(1.7f);
        do{
            r0 = _mm256_add_ps(r0, add0);
            r1 = _mm256_add_ps(r1, add0);
            r2 = _mm256_add_ps(r2, add0);
            r3 = _mm256_add_ps(r3, add0);
            r4 = _mm256_add_ps(r4, add0);
            r5 = _mm256_add_ps(r5, add0);
            r6 = _mm256_add_ps(r6, add0);
            r7 = _mm256_add_ps(r7, add0);

            r0 = _mm256_sub_ps(r0, sub0);
            r1 = _mm256_sub_ps(r1, sub0);
            r2 = _mm256_sub_ps(r2, sub0);
            r3 = _mm256_sub_ps(r3, sub0);
            r4 = _mm256_sub_ps(r4, sub0);
            r5 = _mm256_sub_ps(r5, sub0);
            r6 = _mm256_sub_ps(r6, sub0);
            r7 = _mm256_sub_ps(r7, sub0);

            r0 = _mm256_add_ps(r0, add0);
            r1 = _mm256_add_ps(r1, add0);
            r2 = _mm256_add_ps(r2, add0);
            r3 = _mm256_add_ps(r3, add0);
            r4 = _mm256_add_ps(r4, add0);
            r5 = _mm256_add_ps(r5, add0);
            r6 = _mm256_add_ps(r6, add0);
            r7 = _mm256_add_ps(r7, add0);

            r0 = _mm256_sub_ps(r0, sub0);
            r1 = _mm256_sub_ps(r1, sub0);
            r2 = _mm256_sub_ps(r2, sub0);
            r3 = _mm256_sub_ps(r3, sub0);
            r4 = _mm256_sub_ps(r4, sub0);
            r5 = _mm256_sub_ps(r5, sub0);
            r6 = _mm256_sub_ps(r6, sub0);
            r7 = _mm256_sub_ps(r7, sub0);
        }while (--iterations);

        r0 = _mm256_add_ps(r0, r4);
        r1 = _mm256_add_ps(r1, r5);
        r2 = _mm256_add_ps(r2, r6);
        r3 = _mm256_add_ps(r3, r7);

        r0 = _mm256_add_ps(r0, r2);
        r1 = _mm256_add_ps(r1, r3);

        r0 = _mm256_add_ps(r0, r1);

        __m128 x = _mm_add_ps(_mm256_castps256_ps128(r0), _mm256_extractf128_ps(r0, 1));
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
