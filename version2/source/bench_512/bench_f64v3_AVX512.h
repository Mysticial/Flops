/* bench_f64v3_AVX512.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/11/2014
 * 
 *      f64     =   Double Precision
 *      v3      =   Vectorize by 8
 *      AVX512  =   AVX512 Instruction Set
 * 
 * 
 *      This file is currently untested since the processor doesn't exist yet.
 * 
 */

#ifndef _flops_bench_f64v3_AVX512_H
#define _flops_bench_f64v3_AVX512_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <immintrin.h>
#include "../globals.h"
#include "../macros/macro_reduce.h"
#include "../macros/macro_add.h"
#include "../macros/macro_mul.h"
#include "../macros/macro_mac.h"
#include "../macros/macro_fma.h"
namespace flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Reduction
double reduce_f64v3_AVX512(__m512d x){
    return _mm512_reduce_add_pd(x);
}
////////////////////////////////////////////////////////////////////////////////
//  Add
class bench_add_f64v3_AVX512_chains4 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 512-bit AVX512 - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 4" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512d add0 = _mm512_set1_pd(TEST_ADD_ADD);
        const __m512d sub0 = _mm512_set1_pd(TEST_ADD_SUB);

        __m512d r0 = _mm512_set1_pd(1.0);
        __m512d r1 = _mm512_set1_pd(1.1);
        __m512d r2 = _mm512_set1_pd(1.2);
        __m512d r3 = _mm512_set1_pd(1.3);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains4_unroll2_ops16(
                _mm512_add_pd,_mm512_sub_pd,
                add0,sub0,
                r0,r1,r2,r3
            );
        }
        flops_reduce_chains4(
            _mm512_add_pd,
            r0,r1,r2,r3
        );
        result = reduce_f64v3_AVX512(r0);

        //  (8 ops / vector) * (16 ops / macro)
        return iterations * 8 * 16;
    }
};
class bench_add_f64v3_AVX512_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 512-bit AVX512 - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512d add0 = _mm512_set1_pd(TEST_ADD_ADD);
        const __m512d sub0 = _mm512_set1_pd(TEST_ADD_SUB);

        __m512d r0 = _mm512_set1_pd(1.0);
        __m512d r1 = _mm512_set1_pd(1.1);
        __m512d r2 = _mm512_set1_pd(1.2);
        __m512d r3 = _mm512_set1_pd(1.3);
        __m512d r4 = _mm512_set1_pd(1.4);
        __m512d r5 = _mm512_set1_pd(1.5);
        __m512d r6 = _mm512_set1_pd(1.6);
        __m512d r7 = _mm512_set1_pd(1.7);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains8_unroll2_ops32(
                _mm512_add_pd,_mm512_sub_pd,
                add0,sub0,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm512_add_pd,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f64v3_AVX512(r0);

        //  (8 ops / vector) * (32 ops / macro)
        return iterations * 8 * 32;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply
class bench_mul_f64v3_AVX512_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 512-bit AVX512 - Multiply:" << endl;
        cout << "    Dependency Chains = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512d mul0 = _mm512_set1_pd(TEST_MUL_MUL);
        const __m512d mul1 = _mm512_set1_pd(TEST_MUL_DIV);

        __m512d r0 = _mm512_set1_pd(1.0);
        __m512d r1 = _mm512_set1_pd(1.1);
        __m512d r2 = _mm512_set1_pd(1.2);
        __m512d r3 = _mm512_set1_pd(1.3);
        __m512d r4 = _mm512_set1_pd(1.4);
        __m512d r5 = _mm512_set1_pd(1.5);
        __m512d r6 = _mm512_set1_pd(1.6);
        __m512d r7 = _mm512_set1_pd(1.7);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains8_unroll2_ops32(
                _mm512_mul_pd,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm512_add_pd,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f64v3_AVX512(r0);

        //  (8 ops / vector) * (32 ops / macro)
        return iterations * 8 * 32;
    }
};
class bench_mul_f64v3_AVX512_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 512-bit AVX512 - Multiply:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512d mul0 = _mm512_set1_pd(TEST_MUL_MUL);
        const __m512d mul1 = _mm512_set1_pd(TEST_MUL_DIV);

        __m512d r0 = _mm512_set1_pd(1.0);
        __m512d r1 = _mm512_set1_pd(1.1);
        __m512d r2 = _mm512_set1_pd(1.2);
        __m512d r3 = _mm512_set1_pd(1.3);
        __m512d r4 = _mm512_set1_pd(1.4);
        __m512d r5 = _mm512_set1_pd(1.5);
        __m512d r6 = _mm512_set1_pd(1.6);
        __m512d r7 = _mm512_set1_pd(1.7);
        __m512d r8 = _mm512_set1_pd(1.8);
        __m512d r9 = _mm512_set1_pd(1.9);
        __m512d rA = _mm512_set1_pd(2.0);
        __m512d rB = _mm512_set1_pd(2.1);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains12_unroll2_ops48(
                _mm512_mul_pd,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm512_add_pd,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f64v3_AVX512(r0);

        //  (8 ops / vector) * (48 ops / macro)
        return iterations * 8 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply + Add
class bench_mac_f64v3_AVX512_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 512-bit AVX512 - Multiply + Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512d add0 = _mm512_set1_pd(TEST_ADD_ADD);
        const __m512d sub0 = _mm512_set1_pd(TEST_ADD_SUB);
        const __m512d mul0 = _mm512_set1_pd(TEST_MUL_MUL);
        const __m512d mul1 = _mm512_set1_pd(TEST_MUL_DIV);

        __m512d r0 = _mm512_set1_pd(1.0);
        __m512d r1 = _mm512_set1_pd(1.1);
        __m512d r2 = _mm512_set1_pd(1.2);
        __m512d r3 = _mm512_set1_pd(1.3);
        __m512d r4 = _mm512_set1_pd(1.4);
        __m512d r5 = _mm512_set1_pd(1.5);
        __m512d r6 = _mm512_set1_pd(1.6);
        __m512d r7 = _mm512_set1_pd(1.7);
        __m512d r8 = _mm512_set1_pd(1.8);
        __m512d r9 = _mm512_set1_pd(1.9);
        __m512d rA = _mm512_set1_pd(2.0);
        __m512d rB = _mm512_set1_pd(2.1);
        for (size_t i = 0; i < iterations; i++){
            flops_muladd_chains12_unroll2_ops48(
                _mm512_add_pd,_mm512_sub_pd,_mm512_mul_pd,
                add0,sub0,mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm512_add_pd,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f64v3_AVX512(r0);

        //  (8 ops / vector) * (48 ops / macro)
        return iterations * 8 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Fused Multiply Add
class bench_fma_linear_f64v3_AVX512_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Double-Precision - 512-bit AVX512 - Fused Multiply Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512d mul0 = _mm512_set1_pd(TEST_FMA_LINEAR_MUL0);
        const __m512d mul1 = _mm512_set1_pd(TEST_FMA_LINEAR_MUL1);

        __m512d r0 = _mm512_set1_pd(1.0);
        __m512d r1 = _mm512_set1_pd(1.1);
        __m512d r2 = _mm512_set1_pd(1.2);
        __m512d r3 = _mm512_set1_pd(1.3);
        __m512d r4 = _mm512_set1_pd(1.4);
        __m512d r5 = _mm512_set1_pd(1.5);
        __m512d r6 = _mm512_set1_pd(1.6);
        __m512d r7 = _mm512_set1_pd(1.7);
        __m512d r8 = _mm512_set1_pd(1.8);
        __m512d r9 = _mm512_set1_pd(1.9);
        __m512d rA = _mm512_set1_pd(2.0);
        __m512d rB = _mm512_set1_pd(2.1);
        for (size_t i = 0; i < iterations; i++){
            flops_fma_linear_chains12_unroll2_ops48(
                _mm512_fmadd_pd,_mm512_fnmadd_pd,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm512_add_pd,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f64v3_AVX512(r0);

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
