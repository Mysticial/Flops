/* main.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 */

#if 0
#elif ArchKnightsLanding
#include "arch/arch_2016_KnightsLanding.h"
#elif ArchHaswell
#include "arch/arch_2013_Haswell.h"
#elif ArchPiledriver
#include "arch/arch_2012_Piledriver.h"
#elif ArchBulldozer
#include "arch/arch_2011_Bulldozer.h"
#elif ArchSandyBridge
#include "arch/arch_2011_SandyBridge.h"
#elif ArchCore2
#include "arch/arch_2006_Core2.h"
#endif

using namespace Flops;

int main(){
    run_benchmark(1000000000, omp_get_max_threads());

#ifdef _WIN32
    system("pause");
#endif
}
