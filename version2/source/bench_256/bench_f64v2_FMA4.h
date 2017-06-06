/* bench_f64v2_FMA4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 *      f64     =   Double Precision
 *      v2      =   Vectorize by 4
 *      FMA4    =   FMA4 Instruction Set
 * 
 */

#ifndef _flops_bench_f64v2_FMA4_H
#define _flops_bench_f64v2_FMA4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <ammintrin.h>
#include "../macros/macro_fma.h"
#include "bench_f64v2_AVX.h"
#include "f64v2_Reduce_AVX.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Fused Multiply Add
class bench_fma_linear_f64v2_FMA4_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 256-bit FMA4 - Fused Multiply Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations, double &result) const{
        const __m256d mul0 = _mm256_set1_pd(TEST_FMA_LINEAR_MUL0);
        const __m256d mul1 = _mm256_set1_pd(TEST_FMA_LINEAR_MUL1);

        __m256d r0 = _mm256_set1_pd(1.0);
        __m256d r1 = _mm256_set1_pd(1.1);
        __m256d r2 = _mm256_set1_pd(1.2);
        __m256d r3 = _mm256_set1_pd(1.3);
        __m256d r4 = _mm256_set1_pd(1.4);
        __m256d r5 = _mm256_set1_pd(1.5);
        __m256d r6 = _mm256_set1_pd(1.6);
        __m256d r7 = _mm256_set1_pd(1.7);
        __m256d r8 = _mm256_set1_pd(1.8);
        __m256d r9 = _mm256_set1_pd(1.9);
        __m256d rA = _mm256_set1_pd(2.0);
        __m256d rB = _mm256_set1_pd(2.1);
        for (size_t i = 0; i < iterations; i++){
            flops_fma_linear_chains12_unroll2_ops48(
                _mm256_macc_pd, _mm256_nmacc_pd,
                mul0, mul1,
                r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB
            );
        }
        flops_reduce_chains12(
            _mm256_add_pd,
            r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB
        );
        result = reduce(r0);

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
