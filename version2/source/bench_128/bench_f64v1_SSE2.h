/* bench_f64v1_SSE2.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 *      f64     =   Double Precision
 *      v1      =   Vectorize by 2
 *      SSE2    =   SSE2 Instruction Set
 * 
 */

#ifndef _flops_bench_f64v1_SSE2_H
#define _flops_bench_f64v1_SSE2_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <emmintrin.h>
#include "../globals.h"
#include "../macros/macro_reduce.h"
#include "../macros/macro_add.h"
#include "../macros/macro_mul.h"
#include "../macros/macro_mac.h"
#include "f64v1_Reduce_SSE2.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Add
class bench_add_f64v1_SSE2_chains4 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 128-bit SSE2 - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 4" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations, double &result) const{
        const __m128d add0 = _mm_set1_pd(TEST_ADD_ADD);
        const __m128d sub0 = _mm_set1_pd(TEST_ADD_SUB);

        __m128d r0 = _mm_set1_pd(1.0);
        __m128d r1 = _mm_set1_pd(1.1);
        __m128d r2 = _mm_set1_pd(1.2);
        __m128d r3 = _mm_set1_pd(1.3);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains4_unroll2_ops16(
                _mm_add_pd, _mm_sub_pd,
                add0, sub0,
                r0, r1, r2, r3
            );
        }
        flops_reduce_chains4(
            _mm_add_pd,
            r0, r1, r2, r3
        );
        result = reduce(r0);

        //  (2 ops / vector) * (16 ops / macro)
        return iterations * 2 * 16;
    }
};
class bench_add_f64v1_SSE2_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 128-bit SSE2 - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations, double &result) const{
        const __m128d add0 = _mm_set1_pd(TEST_ADD_ADD);
        const __m128d sub0 = _mm_set1_pd(TEST_ADD_SUB);

        __m128d r0 = _mm_set1_pd(1.0);
        __m128d r1 = _mm_set1_pd(1.1);
        __m128d r2 = _mm_set1_pd(1.2);
        __m128d r3 = _mm_set1_pd(1.3);
        __m128d r4 = _mm_set1_pd(1.4);
        __m128d r5 = _mm_set1_pd(1.5);
        __m128d r6 = _mm_set1_pd(1.6);
        __m128d r7 = _mm_set1_pd(1.7);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains8_unroll2_ops32(
                _mm_add_pd, _mm_sub_pd,
                add0, sub0,
                r0, r1, r2, r3, r4, r5, r6, r7
            );
        }
        flops_reduce_chains8(
            _mm_add_pd,
            r0, r1, r2, r3, r4, r5, r6, r7
        );
        result = reduce(r0);

        //  (2 ops / vector) * (32 ops / macro)
        return iterations * 2 * 32;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply
class bench_mul_f64v1_SSE2_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 128-bit SSE2 - Multiply:" << endl;
        cout << "    Dependency Chains = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations, double &result) const{
        const __m128d mul0 = _mm_set1_pd(TEST_MUL_MUL);
        const __m128d mul1 = _mm_set1_pd(TEST_MUL_DIV);

        __m128d r0 = _mm_set1_pd(1.0);
        __m128d r1 = _mm_set1_pd(1.1);
        __m128d r2 = _mm_set1_pd(1.2);
        __m128d r3 = _mm_set1_pd(1.3);
        __m128d r4 = _mm_set1_pd(1.4);
        __m128d r5 = _mm_set1_pd(1.5);
        __m128d r6 = _mm_set1_pd(1.6);
        __m128d r7 = _mm_set1_pd(1.7);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains8_unroll2_ops32(
                _mm_mul_pd,
                mul0, mul1,
                r0, r1, r2, r3, r4, r5, r6, r7
            );
        }
        flops_reduce_chains8(
            _mm_add_pd,
            r0, r1, r2, r3, r4, r5, r6, r7
        );
        result = reduce(r0);

        //  (2 ops / vector) * (32 ops / macro)
        return iterations * 2 * 32;
    }
};
class bench_mul_f64v1_SSE2_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 128-bit SSE2 - Multiply:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations, double &result) const{
        const __m128d mul0 = _mm_set1_pd(TEST_MUL_MUL);
        const __m128d mul1 = _mm_set1_pd(TEST_MUL_DIV);

        __m128d r0 = _mm_set1_pd(1.0);
        __m128d r1 = _mm_set1_pd(1.1);
        __m128d r2 = _mm_set1_pd(1.2);
        __m128d r3 = _mm_set1_pd(1.3);
        __m128d r4 = _mm_set1_pd(1.4);
        __m128d r5 = _mm_set1_pd(1.5);
        __m128d r6 = _mm_set1_pd(1.6);
        __m128d r7 = _mm_set1_pd(1.7);
        __m128d r8 = _mm_set1_pd(1.8);
        __m128d r9 = _mm_set1_pd(1.9);
        __m128d rA = _mm_set1_pd(2.0);
        __m128d rB = _mm_set1_pd(2.1);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains12_unroll2_ops48(
                _mm_mul_pd,
                mul0, mul1,
                r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB
            );
        }
        flops_reduce_chains12(
            _mm_add_pd,
            r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB
        );
        result = reduce(r0);

        //  (2 ops / vector) * (48 ops / macro)
        return iterations * 2 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply + Add
class bench_mac_f64v1_SSE2_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 128-bit SSE2 - Multiply + Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations, double &result) const{
        const __m128d add0 = _mm_set1_pd(TEST_ADD_ADD);
        const __m128d sub0 = _mm_set1_pd(TEST_ADD_SUB);
        const __m128d mul0 = _mm_set1_pd(TEST_MUL_MUL);
        const __m128d mul1 = _mm_set1_pd(TEST_MUL_DIV);

        __m128d r0 = _mm_set1_pd(1.0);
        __m128d r1 = _mm_set1_pd(1.1);
        __m128d r2 = _mm_set1_pd(1.2);
        __m128d r3 = _mm_set1_pd(1.3);
        __m128d r4 = _mm_set1_pd(1.4);
        __m128d r5 = _mm_set1_pd(1.5);
        __m128d r6 = _mm_set1_pd(1.6);
        __m128d r7 = _mm_set1_pd(1.7);
        __m128d r8 = _mm_set1_pd(1.8);
        __m128d r9 = _mm_set1_pd(1.9);
        __m128d rA = _mm_set1_pd(2.0);
        __m128d rB = _mm_set1_pd(2.1);
        for (size_t i = 0; i < iterations; i++){
            flops_muladd_chains12_unroll2_ops48(
                _mm_add_pd, _mm_sub_pd, _mm_mul_pd,
                add0, sub0, mul0, mul1,
                r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB
            );
        }
        flops_reduce_chains12(
            _mm_add_pd,
            r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB
        );
        result = reduce(r0);

        //  (2 ops / vector) * (48 ops / macro)
        return iterations * 2 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
