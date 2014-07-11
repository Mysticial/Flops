/* bench_f32v2_SSE.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 *      f32     =   Single Precision
 *      v2      =   Vectorize by 4
 *      SSE     =   SSE Instruction Set
 * 
 */

#ifndef _flops_bench_f32v2_SSE_H
#define _flops_bench_f32v2_SSE_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <xmmintrin.h>
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
float reduce_f32v2_SSE(__m128 x){
    union{
        __m128 v;
        float s[4];
    };
    v = x;
    return (s[0] + s[1]) + (s[2] + s[3]);
}
////////////////////////////////////////////////////////////////////////////////
//  Add
class bench_add_f32v2_SSE_chains4 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 128-bit SSE - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 4" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128 add0 = _mm_set1_ps((float)TEST_ADD_ADD);
        const __m128 sub0 = _mm_set1_ps((float)TEST_ADD_SUB);

        __m128 r0 = _mm_set1_ps(1.0f);
        __m128 r1 = _mm_set1_ps(1.1f);
        __m128 r2 = _mm_set1_ps(1.2f);
        __m128 r3 = _mm_set1_ps(1.3f);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains4_unroll2_ops16(
                _mm_add_ps,_mm_sub_ps,
                add0,sub0,
                r0,r1,r2,r3
            );
        }
        flops_reduce_chains4(
            _mm_add_ps,
            r0,r1,r2,r3
        );
        result = reduce_f32v2_SSE(r0);

        //  (4 ops / vector) * (16 ops / macro)
        return iterations * 4 * 16;
    }
};
class bench_add_f32v2_SSE_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 128-bit SSE - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128 add0 = _mm_set1_ps((float)TEST_ADD_ADD);
        const __m128 sub0 = _mm_set1_ps((float)TEST_ADD_SUB);

        __m128 r0 = _mm_set1_ps(1.0f);
        __m128 r1 = _mm_set1_ps(1.1f);
        __m128 r2 = _mm_set1_ps(1.2f);
        __m128 r3 = _mm_set1_ps(1.3f);
        __m128 r4 = _mm_set1_ps(1.4f);
        __m128 r5 = _mm_set1_ps(1.5f);
        __m128 r6 = _mm_set1_ps(1.6f);
        __m128 r7 = _mm_set1_ps(1.7f);
        for (size_t i = 0; i < iterations; i++){
            flops_add_chains8_unroll2_ops32(
                _mm_add_ps,_mm_sub_ps,
                add0,sub0,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f32v2_SSE(r0);

        //  (4 ops / vector) * (32 ops / macro)
        return iterations * 4 * 32;
    }
};
class bench_add_f32v2_SSE_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 128-bit SSE - Add/Sub:" << endl;
        cout << "    Dependency Chains  = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128 add0 = _mm_set1_ps((float)TEST_ADD_ADD);
        const __m128 sub0 = _mm_set1_ps((float)TEST_ADD_SUB);

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
            flops_add_chains12_unroll2_ops48(
                _mm_add_ps,_mm_sub_ps,
                add0,sub0,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v2_SSE(r0);

        //  (4 ops / vector) * (48 ops / macro)
        return iterations * 4 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply
class bench_mul_f32v2_SSE_chains8 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 128-bit SSE - Multiply:" << endl;
        cout << "    Dependency Chains = 8" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128 mul0 = _mm_set1_ps((float)TEST_MUL_MUL);
        const __m128 mul1 = _mm_set1_ps((float)TEST_MUL_DIV);

        __m128 r0 = _mm_set1_ps(1.0f);
        __m128 r1 = _mm_set1_ps(1.1f);
        __m128 r2 = _mm_set1_ps(1.2f);
        __m128 r3 = _mm_set1_ps(1.3f);
        __m128 r4 = _mm_set1_ps(1.4f);
        __m128 r5 = _mm_set1_ps(1.5f);
        __m128 r6 = _mm_set1_ps(1.6f);
        __m128 r7 = _mm_set1_ps(1.7f);
        for (size_t i = 0; i < iterations; i++){
            flops_mul_chains8_unroll2_ops32(
                _mm_mul_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7
            );
        }
        flops_reduce_chains8(
            _mm_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7
        );
        result = reduce_f32v2_SSE(r0);

        //  (4 ops / vector) * (32 ops / macro)
        return iterations * 4 * 32;
    }
};
class bench_mul_f32v2_SSE_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 128-bit SSE - Multiply:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128 mul0 = _mm_set1_ps((float)TEST_MUL_MUL);
        const __m128 mul1 = _mm_set1_ps((float)TEST_MUL_DIV);

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
            flops_mul_chains12_unroll2_ops48(
                _mm_mul_ps,
                mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v2_SSE(r0);

        //  (4 ops / vector) * (48 ops / macro)
        return iterations * 4 * 48;
    }
};
////////////////////////////////////////////////////////////////////////////////
//  Multiply + Add
class bench_mac_f32v2_SSE_chains12 : public benchmark{
    virtual void print_meta() const{
        cout << "Single-Precision - 128-bit SSE - Multiply + Add:" << endl;
        cout << "    Dependency Chains = 12" << endl;
    }
    virtual largeint_t run_loop(largeint_t iterations,double &result) const{
        const __m128 add0 = _mm_set1_ps((float)TEST_ADD_ADD);
        const __m128 sub0 = _mm_set1_ps((float)TEST_ADD_SUB);
        const __m128 mul0 = _mm_set1_ps((float)TEST_MUL_MUL);
        const __m128 mul1 = _mm_set1_ps((float)TEST_MUL_DIV);

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
            flops_muladd_chains12_unroll2_ops48(
                _mm_add_ps,_mm_sub_ps,_mm_mul_ps,
                add0,sub0,mul0,mul1,
                r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
            );
        }
        flops_reduce_chains12(
            _mm_add_ps,
            r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB
        );
        result = reduce_f32v2_SSE(r0);

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
