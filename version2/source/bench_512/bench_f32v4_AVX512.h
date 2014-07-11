/* bench_f32v4_AVX512.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/11/2014
 * 
 *      f32     =   Single Precision
 *      v4      =   Vectorize by 16
 *      AVX512  =   AVX512 Instruction Set
 * 
 * 
 *      This file is currently untested since the processor doesn't exist yet.
 * 
 */

#ifndef _flops_bench_f32v4_AVX512_H
#define _flops_bench_f32v4_AVX512_H
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
float reduce_f32v4_AVX512(__m512 x){
    return _mm512_reduce_add_ps(x);
}
////////////////////////////////////////////////////////////////////////////////
//  Add
class bench_add_f32v4_AVX512_chains4 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 512-bit AVX512 - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 4" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512 add0 = _mm512_set1_ps((float)TEST_ADD_ADD);
        const __m512 sub0 = _mm512_set1_ps((float)TEST_ADD_SUB);

        __m512 r0 = _mm512_set1_ps(1.0f);
        __m512 r1 = _mm512_set1_ps(1.1f);
        __m512 r2 = _mm512_set1_ps(1.2f);
        __m512 r3 = _mm512_set1_ps(1.3f);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains4_unroll2_ops16(
                _mm512_add_ps,_mm512_sub_ps,
                add0,sub0,
                r0,r1,r2,r3
            );
        }
        flops_reduce_chains4(
            _mm512_512_ps,
            r0,r1,r2,r3
        );
        result = reduce_f32v4_AVX512(r0);

        //  (16 ops / vector) * (16 ops / macro)
        return iterations * 16 * 16;
    }
};
class bench_add_f32v4_AVX512_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 512-bit AVX512 - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512 add0 = _mm512_set1_ps((float)TEST_ADD_ADD);
        const __m512 sub0 = _mm512_set1_ps((float)TEST_ADD_SUB);

        __m512 r0 = _mm512_set1_ps(1.0f);
        __m512 r1 = _mm512_set1_ps(1.1f);
        __m512 r2 = _mm512_set1_ps(1.2f);
        __m512 r3 = _mm512_set1_ps(1.3f);
        __m512 r4 = _mm512_set1_ps(1.4f);
        __m512 r5 = _mm512_set1_ps(1.5f);
        __m512 r6 = _mm512_set1_ps(1.6f);
        __m512 r7 = _mm512_set1_ps(1.7f);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains8_unroll2_ops32(
                _mm512_add_ps,_mm512_sub_ps,
                add0,sub0,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm512_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f32v4_AVX512(r0);

        //  (16 ops / vector) * (32 ops / macro)
        return iterations * 16 * 32;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply
class bench_mul_f32v4_AVX512_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 512-bit AVX512 - Multiply:" << endl;
        cout << "    Dependency Chains = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512 mul0 = _mm512_set1_ps((float)TEST_MUL_MUL);
        const __m512 mul1 = _mm512_set1_ps((float)TEST_MUL_DIV);

        __m512 r0 = _mm512_set1_ps(1.0f);
        __m512 r1 = _mm512_set1_ps(1.1f);
        __m512 r2 = _mm512_set1_ps(1.2f);
        __m512 r3 = _mm512_set1_ps(1.3f);
        __m512 r4 = _mm512_set1_ps(1.4f);
        __m512 r5 = _mm512_set1_ps(1.5f);
        __m512 r6 = _mm512_set1_ps(1.6f);
        __m512 r7 = _mm512_set1_ps(1.7f);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains8_unroll2_ops32(
                _mm512_mul_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm512_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f32v4_AVX512(r0);

        //  (16 ops / vector) * (32 ops / macro)
        return iterations * 16 * 32;
    }
};
class bench_mul_f32v4_AVX512_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 512-bit AVX512 - Multiply:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512 mul0 = _mm512_set1_ps((float)TEST_MUL_MUL);
        const __m512 mul1 = _mm512_set1_ps((float)TEST_MUL_DIV);

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
        __m512 rA = _mm512_set1_ps(2.0f);
        __m512 rB = _mm512_set1_ps(2.1f);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains12_unroll2_ops48(
                _mm512_mul_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm512_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v4_AVX512(r0);

        //  (16 ops / vector) * (48 ops / macro)
        return iterations * 16 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply + Add
class bench_mac_f32v4_AVX512_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 512-bit AVX512 - Multiply + Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512 add0 = _mm512_set1_ps((float)TEST_ADD_ADD);
        const __m512 sub0 = _mm512_set1_ps((float)TEST_ADD_SUB);
        const __m512 mul0 = _mm512_set1_ps((float)TEST_MUL_MUL);
        const __m512 mul1 = _mm512_set1_ps((float)TEST_MUL_DIV);

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
        __m512 rA = _mm512_set1_ps(2.0f);
        __m512 rB = _mm512_set1_ps(2.1f);
        for (size_t i = 0; i < iterations; i++){
            flops_muladd_chains12_unroll2_ops48(
                _mm512_add_ps,_mm512_sub_ps,_mm512_mul_ps,
                add0,sub0,mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm512_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v4_AVX512(r0);

        //  (16 ops / vector) * (48 ops / macro)
        return iterations * 16 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Fused Multiply Add
class bench_fma_linear_f32v4_AVX512_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 512-bit AVX512 - Fused Multiply Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m512 mul0 = _mm512_set1_ps((float)TEST_FMA_LINEAR_MUL0);
        const __m512 mul1 = _mm512_set1_ps((float)TEST_FMA_LINEAR_MUL1);

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
        __m512 rA = _mm512_set1_ps(2.0f);
        __m512 rB = _mm512_set1_ps(2.1f);
        for (size_t i = 0; i < iterations; i++){
            flops_fma_linear_chains12_unroll2_ops48(
                _mm512_fmadd_ps,_mm512_fnmadd_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm512_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v4_AVX512(r0);

        //  (32 ops / vector) * (48 ops / macro)
        return iterations * 32 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
