/* arch_2011_Bulldozer.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 */

#ifndef _WIN32
#include <x86intrin.h>
#endif

//  128-bit
#include "../bench_128/bench_f32v2_SSE.h"
#include "../bench_128/bench_f64v1_SSE2.h"
#include "../bench_128/bench_f32v2_FMA4.h"
#include "../bench_128/bench_f64v1_FMA4.h"

//  256-bit
#include "../bench_256/bench_f32v3_AVX.h"
#include "../bench_256/bench_f64v2_AVX.h"
#include "../bench_256/bench_f32v3_FMA4.h"
#include "../bench_256/bench_f64v2_FMA4.h"

namespace flops{

    void run_benchmark(largeint_t iterations,size_t threads){
        cout << "Running Benchmarks for AMD Bulldozer..." << endl;
        cout << endl;

        //  128-bit
        bench_add_f32v2_SSE_chains8 ().run(iterations,threads);
        bench_mul_f32v2_SSE_chains8 ().run(iterations,threads);
        bench_mac_f32v2_SSE_chains12().run(iterations,threads);
        bench_fma_linear_f32v2_FMA4_chains12().run(iterations,threads);

        bench_add_f64v1_SSE2_chains8 ().run(iterations,threads);
        bench_mul_f64v1_SSE2_chains8 ().run(iterations,threads);
        bench_mac_f64v1_SSE2_chains12().run(iterations,threads);
        bench_fma_linear_f64v1_FMA4_chains12().run(iterations,threads);

        //  256-bit
        bench_add_f32v3_AVX_chains8 ().run(iterations,threads);
        bench_mul_f32v3_AVX_chains8 ().run(iterations,threads);
        bench_mac_f32v3_AVX_chains12().run(iterations,threads);
        bench_fma_linear_f32v3_FMA4_chains12().run(iterations,threads);

        bench_add_f64v2_AVX_chains8 ().run(iterations,threads);
        bench_mul_f64v2_AVX_chains8 ().run(iterations,threads);
        bench_mac_f64v2_AVX_chains12().run(iterations,threads);
        bench_fma_linear_f64v2_FMA4_chains12().run(iterations,threads);
    }

}
