/* bench_f64v1_FMA4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 *      f64     =   Double Precision
 *      v1      =   Vectorize by 2
 *      FMA4    =   FMA4 Instruction Set
 * 
 */

#ifndef _flops_bench_f64v1_FMA4_H
#define _flops_bench_f64v1_FMA4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <ammintrin.h>
#include "../macros/macro_fma.h"
#include "bench_f64v1_SSE2.h"
namespace flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Fused Multiply Add
class bench_fma_linear_f64v1_FMA4_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 128-bit FMA4 - Fused Multiply Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128d mul0 = _mm_set1_pd(TEST_FMA_LINEAR_MUL0);
        const __m128d mul1 = _mm_set1_pd(TEST_FMA_LINEAR_MUL1);

        __m128d r0 = _mm_set1_pd(1.0f);
        __m128d r1 = _mm_set1_pd(1.1f);
        __m128d r2 = _mm_set1_pd(1.2f);
        __m128d r3 = _mm_set1_pd(1.3f);
        __m128d r4 = _mm_set1_pd(1.4f);
        __m128d r5 = _mm_set1_pd(1.5f);
        __m128d r6 = _mm_set1_pd(1.6f);
        __m128d r7 = _mm_set1_pd(1.7f);
        __m128d r8 = _mm_set1_pd(1.8f);
        __m128d r9 = _mm_set1_pd(1.9f);
        __m128d rA = _mm_set1_pd(2.0f);
        __m128d rB = _mm_set1_pd(2.1f);
        for (size_t i = 0; i < iterations; i++){
            flops_fma_linear_chains12_unroll2_ops48(
                _mm_macc_pd,_mm_nmacc_pd,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm_add_pd,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f64v1_SSE2(r0);

        //  (4 ops / vector) * (48 ops / macro)
        return iterations * 4 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
