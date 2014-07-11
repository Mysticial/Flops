/* bench_f32v3_AVX.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 *      f32     =   Single Precision
 *      v3      =   Vectorize by 8
 *      AVX     =   AVX Instruction Set
 * 
 */

#ifndef _flops_bench_f32v3_AVX_H
#define _flops_bench_f32v3_AVX_H
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
namespace flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Reduction
float reduce_f32v3_AVX(__m256 x){
    union{
        __m256 v;
        float s[8];
    };
    v = x;

    float result = 0;
    for (int c = 0; c < 8; c++){
        result += s[c];
    }
    return result;
}
////////////////////////////////////////////////////////////////////////////////
//  Add
class bench_add_f32v3_AVX_chains4 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 256-bit AVX - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 4" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m256 add0 = _mm256_set1_ps((float)TEST_ADD_ADD);
        const __m256 sub0 = _mm256_set1_ps((float)TEST_ADD_SUB);

        __m256 r0 = _mm256_set1_ps(1.0f);
        __m256 r1 = _mm256_set1_ps(1.1f);
        __m256 r2 = _mm256_set1_ps(1.2f);
        __m256 r3 = _mm256_set1_ps(1.3f);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains4_unroll2_ops16(
                _mm256_add_ps,_mm256_sub_ps,
                add0,sub0,
                r0,r1,r2,r3
            );
        }
        flops_reduce_chains4(
            _mm256_add_ps,
            r0,r1,r2,r3
        );
        result = reduce_f32v3_AVX(r0);

        //  (8 ops / vector) * (16 ops / macro)
        return iterations * 8 * 16;
    }
};
class bench_add_f32v3_AVX_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 256-bit AVX - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m256 add0 = _mm256_set1_ps((float)TEST_ADD_ADD);
        const __m256 sub0 = _mm256_set1_ps((float)TEST_ADD_SUB);

        __m256 r0 = _mm256_set1_ps(1.0f);
        __m256 r1 = _mm256_set1_ps(1.1f);
        __m256 r2 = _mm256_set1_ps(1.2f);
        __m256 r3 = _mm256_set1_ps(1.3f);
        __m256 r4 = _mm256_set1_ps(1.4f);
        __m256 r5 = _mm256_set1_ps(1.5f);
        __m256 r6 = _mm256_set1_ps(1.6f);
        __m256 r7 = _mm256_set1_ps(1.7f);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains8_unroll2_ops32(
                _mm256_add_ps,_mm256_sub_ps,
                add0,sub0,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm256_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f32v3_AVX(r0);

        //  (8 ops / vector) * (32 ops / macro)
        return iterations * 8 * 32;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply
class bench_mul_f32v3_AVX_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 256-bit AVX - Multiply:" << endl;
        cout << "    Dependency Chains = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m256 mul0 = _mm256_set1_ps((float)TEST_MUL_MUL);
        const __m256 mul1 = _mm256_set1_ps((float)TEST_MUL_DIV);

        __m256 r0 = _mm256_set1_ps(1.0f);
        __m256 r1 = _mm256_set1_ps(1.1f);
        __m256 r2 = _mm256_set1_ps(1.2f);
        __m256 r3 = _mm256_set1_ps(1.3f);
        __m256 r4 = _mm256_set1_ps(1.4f);
        __m256 r5 = _mm256_set1_ps(1.5f);
        __m256 r6 = _mm256_set1_ps(1.6f);
        __m256 r7 = _mm256_set1_ps(1.7f);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains8_unroll2_ops32(
                _mm256_mul_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm256_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f32v3_AVX(r0);

        //  (8 ops / vector) * (32 ops / macro)
        return iterations * 8 * 32;
    }
};
class bench_mul_f32v3_AVX_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 256-bit AVX - Multiply:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m256 mul0 = _mm256_set1_ps((float)TEST_MUL_MUL);
        const __m256 mul1 = _mm256_set1_ps((float)TEST_MUL_DIV);

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
            flops_mul_chains12_unroll2_ops48(
                _mm256_mul_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm256_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v3_AVX(r0);

        //  (8 ops / vector) * (48 ops / macro)
        return iterations * 8 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply + Add
class bench_mac_f32v3_AVX_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 256-bit AVX - Multiply + Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m256 add0 = _mm256_set1_ps((float)TEST_ADD_ADD);
        const __m256 sub0 = _mm256_set1_ps((float)TEST_ADD_SUB);
        const __m256 mul0 = _mm256_set1_ps((float)TEST_MUL_MUL);
        const __m256 mul1 = _mm256_set1_ps((float)TEST_MUL_DIV);

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
            flops_muladd_chains12_unroll2_ops48(
                _mm256_add_ps,_mm256_sub_ps,_mm256_mul_ps,
                add0,sub0,mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm256_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v3_AVX(r0);

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
