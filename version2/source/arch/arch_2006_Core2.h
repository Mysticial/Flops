/* arch_2006_Core2.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 */

//  128-bit
#include "../bench_128/bench_f32v2_SSE.h"
#include "../bench_128/bench_f64v1_SSE2.h"

namespace flops{

    void run_benchmark(largeint_t iterations,size_t threads){
        cout << "Running Benchmarks for Intel Core 2..." << endl;
        cout << endl;

        //  128-bit
        bench_add_f32v2_SSE_chains4().run(iterations,threads);
        bench_mul_f32v2_SSE_chains8().run(iterations,threads);
        bench_mac_f32v2_SSE_chains12().run(iterations,threads);

        bench_add_f64v1_SSE2_chains4().run(iterations,threads);
        bench_mul_f64v1_SSE2_chains8().run(iterations,threads);
        bench_mac_f64v1_SSE2_chains12().run(iterations,threads);
    }

}
