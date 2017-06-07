
#include <thread>

#if 0
#elif x64_2006_Core2
#include "Arch/2006_Core2.ipp"
#elif x64_2011_SandyBridge
#include "Arch/2011_SandyBridge.ipp"
#elif x64_2011_Bulldozer
#include "Arch/2011_Bulldozer.ipp"
#elif x64_2012_Piledriver
#include "Arch/2012_Piledriver.ipp"
#elif x64_2013_Haswell
#include "Arch/2013_Haswell.ipp"
#elif x64_2016_KnightsLanding
#include "Arch/2016_KnightsLanding.ipp"
#elif x64_2017_Zen
#include "Arch/2017_Zen.ipp"
#elif x64_2017_SkylakePurley
#include "Arch/2016_KnightsLanding.ipp"
#endif



int main(){

    Flops::run(1);
    Flops::run(std::thread::hardware_concurrency());


#if _WIN32
    system("pause");
#endif
}
