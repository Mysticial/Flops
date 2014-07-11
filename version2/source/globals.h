#include <iostream>
using std::cout;
using std::endl;

#ifndef _flops_globals_H
#define _flops_globals_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include <stdint.h>
#include <string.h>
#include <omp.h>
#include <memory>
#include "tools.h"
namespace flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
typedef uint64_t largeint_t;

const double TEST_ADD_ADD   =   1.4142135623730950488;
const double TEST_ADD_SUB   =   1.414213562373095;

const double TEST_MUL_MUL   =   1.4142135623730950488;
const double TEST_MUL_DIV   =   0.70710678118654752440;

const double TEST_FMA_LINEAR_MUL0   =   1.4142135623730950488;
const double TEST_FMA_LINEAR_MUL1   =   1.7320508075688772935;

const double TEST_FMA_HORNER_MUL0   =   1.4142135623730950488;
const double TEST_FMA_HORNER_ADD0   =   1.7320508075688772935;
const double TEST_FMA_HORNER_MUL1   =   0.70710678118654752440;
const double TEST_FMA_HORNER_ADD1   =   -1.2247448713915890491;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class benchmark{
    virtual void print_meta() const = 0;
    virtual largeint_t run_loop(largeint_t iterations,double &result) const = 0;

public:
    void run(largeint_t iterations) const{
        print_meta();

        double result;
        wclk start = wclk_now();
        iterations = run_loop(iterations,result);
        double seconds = wclk_secs_since(start);

        cout << "    Result     = " << result << endl;
        cout << "    FP Ops     = " << iterations << endl;
        cout << "    seconds    = " << seconds << endl;
        cout << "    GFlops     = " << iterations / seconds / 1.e9 << endl;
        cout << endl;
    }
    void run(largeint_t iterations,size_t threads) const{
        print_meta();

        auto thread_result     = std::unique_ptr<double[]>(new double[threads]);
        auto thread_iterations = std::unique_ptr<largeint_t[]>(new largeint_t[threads]);
        memset(thread_result.get()    ,0,threads * sizeof(double));
        memset(thread_iterations.get(),0,threads * sizeof(largeint_t));

        wclk start = wclk_now();
#pragma omp parallel num_threads((int)threads)
        {
            size_t thread_id = omp_get_thread_num();

            double result;
            thread_iterations[thread_id] = run_loop(iterations,result);
            thread_result[thread_id] = result;
        }
        double seconds = wclk_secs_since(start);

        double result = 0;
        iterations = 0;
        for (size_t i = 0; i < threads; i++){
            result += thread_result[i];
            iterations += thread_iterations[i];
        }

        cout << "    Result     = " << result << endl;
        cout << "    FP Ops     = " << iterations << endl;
        cout << "    seconds    = " << seconds << endl;
        cout << "    GFlops     = " << iterations / seconds / 1.e9 << endl;
        cout << endl;
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
