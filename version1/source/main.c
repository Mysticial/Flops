/* main.c
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/25/2012
 * Last Modified    : 01/25/2012
 * 
 * 
 * 
 * And of course... The typical copyright stuff...
 * 
 *      Redistribution of this program in both source or binary, regardless of
 *  form, with or without modification is permitted as long as the following
 *  conditions are met:
 *          1.  This copyright notice is maintained either inline in the source
 *              or distributed with the binary.
 *          2.  A list of all contributing authors along with their contributions
 *              is included either inline in the source or distributed with the
 *              binary.
 *          3.  The following disclaimer is maintained either inline in the
 *              source or distributed with the binary.
 * 
 *  Disclaimer:
 *  This software is provided "as is", without any guarantee made to its
 *  suitability or fitness for any particular use. It may contain bugs so use
 *  of this program is at your own risk. I take no responsibility for any
 *  damage that may unintentionally be caused through its use.
 */


#include "flops.h"

#ifdef x86_SSE2
#include "flops_SSE2.h"
#endif

#ifdef x86_AVX
#include "flops_AVX.h"
#endif

#ifdef x86_FMA4
#include "flops_AVX.h"
#include "flops_FMA4.h"
#endif

#ifdef x86_FMA3
#include "flops_AVX.h"
#include "flops_FMA3.h"
#endif

#include "tools.h"
#include "cpuid.h"

void run_flops(int threads, size_t iterations){
#ifdef x86_SSE2
    test_dp_add_SSE2(threads, iterations);
    test_dp_mul_SSE2(threads, iterations);
    test_dp_mac_SSE2(threads, iterations);
#endif
#ifdef x86_AVX
    test_dp_add_AVX(threads, iterations);
    test_dp_mul_AVX(threads, iterations);
    test_dp_mac_AVX(threads, iterations);
#endif
#ifdef x86_FMA4
    test_dp_add_AVX(threads, iterations);
    test_dp_mul_AVX(threads, iterations);
    test_dp_mac_AVX(threads, iterations);
    test_dp_fma_FMA4(threads, iterations);
#endif
#ifdef x86_FMA3
    test_dp_add_AVX(threads, iterations);
    test_dp_mul_AVX(threads, iterations);
    test_dp_mac_AVX(threads, iterations);
    test_dp_fma_FMA3(threads, iterations);
#endif
}

int main(){
    int iterations = 1000000;
    int threads = omp_get_max_threads();

    printf(arch_name);
    printf("\n\n");

    cpuid_print_name();
    cpuid_print_exts();

    run_flops(threads, iterations);

#ifdef WIN32
    int ret = system("pause");
#endif

    return 0;
}
