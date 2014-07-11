/* tools.c
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 10/21/2011
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

#ifndef _tools_c
#define _tools_c
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  rdtsc
#ifdef _WIN32
#include <windows.h>
uint64 rdtsc(){
    return __rdtsc();
}
#else
#include <sys/time.h>
uint64 rdtsc(){
    unsigned int lo,hi;
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64)hi << 32) | lo;
}
#endif
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  High Precision Timer
#ifdef _WIN32
wclk wclk_now(){
    wclk out;
    if (!QueryPerformanceCounter(&out.time)){
        printf("\n");
        printf("Unable to access CPU cycle counter.");
        printf("\n");
        exit(1);
    }
    return out;
}
double wclk_secs_dif(wclk end,wclk start){
    LARGE_INTEGER freqency;
    if (!QueryPerformanceFrequency(&freqency)){
        printf("\n");
        printf("Unable to access CPU cycle counter.");
        printf("\n");
        exit(1);
    }
    return (double)(end.time.QuadPart - start.time.QuadPart) / freqency.QuadPart;
}
#else
wclk wclk_now(){
    wclk out;
    if (gettimeofday(&out.time,NULL)){
        printf("\n");
        printf("Unable to access clock.");
        printf("\n");
        exit(1);
    }
    return out;
}
double wclk_secs_dif(wclk end,wclk start){
    uint64 isec = (uint64)end.time.tv_sec - (uint64)start.time.tv_sec;
    int usec = end.time.tv_usec - start.time.tv_usec;
    if (usec < 0){
        usec += 1000000;
        isec--;
    }
    return (double)isec + (double)usec * .000001;
}
#endif
double wclk_secs_since(wclk start){
    return wclk_secs_dif(wclk_now(),start);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
