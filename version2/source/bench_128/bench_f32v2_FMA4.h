/* bench_f32v2_FMA4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 *      f32     =   Single Precision
 *      v2      =   Vectorize by 4
 *      FMA4    =   FMA4 Instruction Set
 * 
 */

#ifndef _flops_bench_f32v2_FMA4_H
#define _flops_bench_f32v2_FMA4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <ammintrin.h>
#include "../macros/macro_fma.h"
#include "bench_f32v2_SSE.h"
namespace flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Fused Multiply Add
class bench_fma_linear_f32v2_FMA4_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 128-bit FMA4 - Fused Multiply Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128 mul0 = _mm_set1_ps((float)TEST_FMA_LINEAR_MUL0);
        const __m128 mul1 = _mm_set1_ps((float)TEST_FMA_LINEAR_MUL1);

        __m128 r0 = _mm_set1_ps(1.0f);
        __m128 r1 = _mm_set1_ps(1.1f);
        __m128 r2 = _mm_set1_ps(1.2f);
        __m128 r3 = _mm_set1_ps(1.3f);
        __m128 r4 = _mm_set1_ps(1.4f);
        __m128 r5 = _mm_set1_ps(1.5f);
        __m128 r6 = _mm_set1_ps(1.6f);
        __m128 r7 = _mm_set1_ps(1.7f);
        __m128 r8 = _mm_set1_ps(1.8f);
        __m128 r9 = _mm_set1_ps(1.9f);
        __m128 rA = _mm_set1_ps(2.0f);
        __m128 rB = _mm_set1_ps(2.1f);
        for (size_t i = 0; i < iterations; i++){
            flops_fma_linear_chains12_unroll2_ops48(
                _mm_macc_ps,_mm_nmacc_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v2_SSE(r0);

        //  (8 ops / vector) * (48 ops / macro)
        return iterations * 8 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
