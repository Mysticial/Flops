/* bench_f32v3_FMA4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 *      f32     =   Single Precision
 *      v3      =   Vectorize by 8
 *      FMA4    =   FMA4 Instruction Set
 * 
 */

#ifndef _flops_bench_f32v3_FMA4_H
#define _flops_bench_f32v3_FMA4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <ammintrin.h>
#include "../macros/macro_fma.h"
#include "bench_f32v3_AVX.h"
namespace flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Fused Multiply Add
class bench_fma_linear_f32v3_FMA4_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 256-bit FMA4 - Fused Multiply Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m256 mul0 = _mm256_set1_ps((float)TEST_FMA_LINEAR_MUL0);
        const __m256 mul1 = _mm256_set1_ps((float)TEST_FMA_LINEAR_MUL1);

        __m256 r0 = _mm256_set1_ps(1.0f);
        __m256 r1 = _mm256_set1_ps(1.1f);
        __m256 r2 = _mm256_set1_ps(1.2f);
        __m256 r3 = _mm256_set1_ps(1.3f);
        __m256 r4 = _mm256_set1_ps(1.4f);
        __m256 r5 = _mm256_set1_ps(1.5f);
        __m256 r6 = _mm256_set1_ps(1.6f);
        __m256 r7 = _mm256_set1_ps(1.7f);
        __m256 r8 = _mm256_set1_ps(1.8f);
        __m256 r9 = _mm256_set1_ps(1.9f);
        __m256 rA = _mm256_set1_ps(2.0f);
        __m256 rB = _mm256_set1_ps(2.1f);
        for (size_t i = 0; i < iterations; i++){
            flops_fma_linear_chains12_unroll2_ops48(
                _mm256_macc_ps,_mm256_nmacc_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm256_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v3_AVX(r0);

        //  (16 ops / vector) * (48 ops / macro)
        return iterations * 16 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
