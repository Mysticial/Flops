/* f64v3_FMA_AVX512_c12x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/04/2017
 * 
 */

#ifndef _flops_f64v3_FMA_AVX512_c12x4_H
#define _flops_f64v3_FMA_AVX512_c12x4_H
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
class f64v3_FMA_AVX512_c12x4 : public Benchmark{
public:
    f64v3_FMA_AVX512_c12x4()
        : Benchmark(48 * 2 * 4)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512d mul0 = _mm512_set1_pd(1.4142135623730950488);
        const __m512d mul1 = _mm512_set1_pd(1.7320508075688772935);

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
        do{
            r0 = _mm512_fmadd_pd(mul0, mul1, r0);
            r1 = _mm512_fmadd_pd(mul0, mul1, r1);
            r2 = _mm512_fmadd_pd(mul0, mul1, r2);
            r3 = _mm512_fmadd_pd(mul0, mul1, r3);
            r4 = _mm512_fmadd_pd(mul0, mul1, r4);
            r5 = _mm512_fmadd_pd(mul0, mul1, r5);
            r6 = _mm512_fmadd_pd(mul0, mul1, r6);
            r7 = _mm512_fmadd_pd(mul0, mul1, r7);
            r8 = _mm512_fmadd_pd(mul0, mul1, r8);
            r9 = _mm512_fmadd_pd(mul0, mul1, r9);
            rA = _mm512_fmadd_pd(mul0, mul1, rA);
            rB = _mm512_fmadd_pd(mul0, mul1, rB);

            r0 = _mm512_fnmadd_pd(mul0, mul1, r0);
            r1 = _mm512_fnmadd_pd(mul0, mul1, r1);
            r2 = _mm512_fnmadd_pd(mul0, mul1, r2);
            r3 = _mm512_fnmadd_pd(mul0, mul1, r3);
            r4 = _mm512_fnmadd_pd(mul0, mul1, r4);
            r5 = _mm512_fnmadd_pd(mul0, mul1, r5);
            r6 = _mm512_fnmadd_pd(mul0, mul1, r6);
            r7 = _mm512_fnmadd_pd(mul0, mul1, r7);
            r8 = _mm512_fnmadd_pd(mul0, mul1, r8);
            r9 = _mm512_fnmadd_pd(mul0, mul1, r9);
            rA = _mm512_fnmadd_pd(mul0, mul1, rA);
            rB = _mm512_fnmadd_pd(mul0, mul1, rB);

            r0 = _mm512_fmadd_pd(mul0, mul1, r0);
            r1 = _mm512_fmadd_pd(mul0, mul1, r1);
            r2 = _mm512_fmadd_pd(mul0, mul1, r2);
            r3 = _mm512_fmadd_pd(mul0, mul1, r3);
            r4 = _mm512_fmadd_pd(mul0, mul1, r4);
            r5 = _mm512_fmadd_pd(mul0, mul1, r5);
            r6 = _mm512_fmadd_pd(mul0, mul1, r6);
            r7 = _mm512_fmadd_pd(mul0, mul1, r7);
            r8 = _mm512_fmadd_pd(mul0, mul1, r8);
            r9 = _mm512_fmadd_pd(mul0, mul1, r9);
            rA = _mm512_fmadd_pd(mul0, mul1, rA);
            rB = _mm512_fmadd_pd(mul0, mul1, rB);

            r0 = _mm512_fnmadd_pd(mul0, mul1, r0);
            r1 = _mm512_fnmadd_pd(mul0, mul1, r1);
            r2 = _mm512_fnmadd_pd(mul0, mul1, r2);
            r3 = _mm512_fnmadd_pd(mul0, mul1, r3);
            r4 = _mm512_fnmadd_pd(mul0, mul1, r4);
            r5 = _mm512_fnmadd_pd(mul0, mul1, r5);
            r6 = _mm512_fnmadd_pd(mul0, mul1, r6);
            r7 = _mm512_fnmadd_pd(mul0, mul1, r7);
            r8 = _mm512_fnmadd_pd(mul0, mul1, r8);
            r9 = _mm512_fnmadd_pd(mul0, mul1, r9);
            rA = _mm512_fnmadd_pd(mul0, mul1, rA);
            rB = _mm512_fnmadd_pd(mul0, mul1, rB);
        }while (--iterations);

        r0 = _mm512_add_pd(r0, r6);
        r1 = _mm512_add_pd(r1, r7);
        r2 = _mm512_add_pd(r2, r8);
        r3 = _mm512_add_pd(r3, r9);
        r4 = _mm512_add_pd(r4, rA);
        r5 = _mm512_add_pd(r5, rB);

        r0 = _mm512_add_pd(r0, r3);
        r1 = _mm512_add_pd(r1, r4);
        r2 = _mm512_add_pd(r2, r5);

        r0 = _mm512_add_pd(r0, r1);
        r0 = _mm512_add_pd(r0, r2);

        __m256d y = _mm256_add_pd(_mm512_castpd512_pd256(r0), _mm512_extractf64x4_pd(r0, 1));
        __m128d x = _mm_add_pd(_mm256_castpd256_pd128(y), _mm256_extractf128_pd(y, 1));
        x = _mm_add_pd(x, _mm_unpackhi_pd(x, x));
        return _mm_cvtsd_f64(x);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
