/* Benchmark.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/27/2017
 * Last Modified    : 03/27/2017
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <vector>
#include <chrono>
#include <atomic>
#include <thread>
#include <iostream>
#include "Benchmark.h"
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class Benchmark::BenchThread{
public:
    BenchThread(Benchmark& benchmark, std::atomic<int>& signal)
        : m_benchmark(benchmark)
        , m_thread(&Benchmark::BenchThread::run, this, std::ref(signal))
    {}

    void run(std::atomic<int>& signal){
        size_t block_size = m_benchmark.m_block_size;

        //  Wait for start.
        while (signal.load(std::memory_order_acquire) == 0);

        //  Run
        double sum = 0;
        uint64_t iterations = 0;
        while (signal.load(std::memory_order_acquire) == 1){
            sum += m_benchmark.run_kernel(block_size);
            iterations++;
        }

        m_fp_ops = iterations * m_benchmark.m_flops_per_iteration * block_size;
        m_sum = sum;
    }

    Benchmark& m_benchmark;
    uint64_t m_fp_ops;
    double m_sum;
    std::thread m_thread;
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
Benchmark::Benchmark(uint64_t flops_per_iteration)
    : m_flops_per_iteration(flops_per_iteration)
    , m_block_size(1000000)
{}
Result Benchmark::bench(double seconds){
    std::chrono::duration<double> duration(seconds);
    auto start = std::chrono::system_clock::now();
    double sum = 0;
    uint64_t iterations = 0;
    std::chrono::duration<double> clock;
    do{
        sum += run_kernel(m_block_size);
        iterations++;
        clock = std::chrono::system_clock::now() - start;
    }while (clock < duration);
    return Result{iterations * m_flops_per_iteration * m_block_size / seconds, sum};
}
Result Benchmark::bench(double seconds, size_t threads){
    std::vector<BenchThread> handles;
    handles.reserve(threads);

    std::atomic<int> signal(0);
    for (size_t c = 0; c < threads; c++){
        handles.emplace_back(*this, signal);
    }

    auto start = std::chrono::system_clock::now();
    signal.store(1, std::memory_order_release);
    std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
    signal.store(2, std::memory_order_release);
    auto end = std::chrono::system_clock::now();
    auto secs = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    uint64_t fp_ops = 0;
    double sum = 0;

    for (BenchThread& thread : handles){
        thread.m_thread.join();
        fp_ops += thread.m_fp_ops;
        sum += thread.m_sum;
    }

    return Result{(double)fp_ops / secs.count(), sum};
}
void Benchmark::run(const char* label, size_t threads, double seconds){
    std::cout << label << std::endl;
    Result result = bench(seconds, threads);
    std::cout << "    GFlops = " << result.flops / 1000000000 << std::endl;
    std::cout << "    Result = " << result.sum << std::endl;
    std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
