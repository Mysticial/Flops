/* 2017_KnightsLanding.ipp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/04/2017
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <iostream>

#include "../128/f32v2_Add_SSE_c8x4.h"
#include "../128/f64v1_Add_SSE2_c8x4.h"
#include "../128/f32v2_Mul_SSE_c12x4.h"
#include "../128/f64v1_Mul_SSE2_c12x4.h"
#include "../128/f32v2_MulAdd_SSE_c6u4_c4u6.h"
#include "../128/f64v1_MulAdd_SSE2_c6u4_c4u6.h"
#include "../128/f32v2_FMA_FMA3_c12x4.h"
#include "../128/f64v1_FMA_FMA3_c12x4.h"

#include "../256/f32v3_Add_AVX_c8x4.h"
#include "../256/f64v2_Add_AVX_c8x4.h"
#include "../256/f32v3_Mul_AVX_c12x4.h"
#include "../256/f64v2_Mul_AVX_c12x4.h"
#include "../256/f32v3_MulAdd_AVX_c6u4_c4u6.h"
#include "../256/f64v2_MulAdd_AVX_c6u4_c4u6.h"
#include "../256/f32v3_FMA_FMA3_c12x4.h"
#include "../256/f64v2_FMA_FMA3_c12x4.h"

#include "../512/f32v4_Add_AVX512_c16x4.h"
#include "../512/f64v3_Add_AVX512_c16x4.h"
#include "../512/f32v4_Mul_AVX512_c24x4.h"
#include "../512/f64v3_Mul_AVX512_c24x4.h"
#include "../512/f32v4_MulAdd_AVX512_c12u8_c8u12.h"
#include "../512/f64v3_MulAdd_AVX512_c12u8_c8u12.h"
#include "../512/f32v4_FMA_AVX512_c24x4.h"
#include "../512/f64v3_FMA_AVX512_c24x4.h"

namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void run(size_t threads){
#ifdef x64_2017_SkylakePurley
	std::cout << "Running Skylake Purley tuned binary with ";
#else
	std::cout << "Running Knights Landing tuned binary with ";
#endif
	if (threads == 1){
		std::cout << "1 thread..." << std::endl;
	}else{
		std::cout << threads << " thread(s)..." << std::endl;
	}
	std::cout << std::endl;


    f32v2_Add_SSE_c8x4().run("Single-Precision - 128-bit AVX - Add/Sub", threads);
    f64v1_Add_SSE2_c8x4().run("Double-Precision - 128-bit AVX - Add/Sub", threads);

    f32v2_Mul_SSE_c12x4().run("Single-Precision - 128-bit AVX - Multiply", threads);
    f64v1_Mul_SSE2_c12x4().run("Double-Precision - 128-bit AVX - Multiply", threads);

    f32v2_MulAdd_SSE_c6u4_c4u6().run("Single-Precision - 128-bit AVX - Multiply + Add", threads);
    f64v1_MulAdd_SSE2_c6u4_c4u6().run("Double-Precision - 128-bit AVX - Multiply + Add", threads);

    f32v2_FMA_FMA3_c12x4().run("Single-Precision - 128-bit FMA3 - Fused Multiply Add", threads);
    f64v1_FMA_FMA3_c12x4().run("Double-Precision - 128-bit FMA3 - Fused Multiply Add", threads);


    f32v3_Add_AVX_c8x4().run("Single-Precision - 256-bit AVX - Add/Sub", threads);
    f64v2_Add_AVX_c8x4().run("Double-Precision - 256-bit AVX - Add/Sub", threads);

    f32v3_Mul_AVX_c12x4().run("Single-Precision - 256-bit AVX - Multiply", threads);
    f64v2_Mul_AVX_c12x4().run("Double-Precision - 256-bit AVX - Multiply", threads);

    f32v3_MulAdd_AVX_c6u4_c4u6().run("Single-Precision - 256-bit AVX - Multiply + Add", threads);
    f64v2_MulAdd_AVX_c6u4_c4u6().run("Double-Precision - 256-bit AVX - Multiply + Add", threads);

    f32v3_FMA_FMA3_c12x4().run("Single-Precision - 256-bit FMA3 - Fused Multiply Add", threads);
    f64v2_FMA_FMA3_c12x4().run("Double-Precision - 256-bit FMA3 - Fused Multiply Add", threads);


    f32v4_Add_AVX512_c16x4().run("Single-Precision - 512-bit AVX512 - Add/Sub", threads);
    f64v3_Add_AVX512_c16x4().run("Double-Precision - 512-bit AVX512 - Add/Sub", threads);

    f32v4_Mul_AVX512_c24x4().run("Single-Precision - 512-bit AVX512 - Multiply", threads);
    f64v3_Mul_AVX512_c24x4().run("Double-Precision - 512-bit AVX512 - Multiply", threads);

    f32v4_MulAdd_AVX512_c12u8_c8u12().run("Single-Precision - 512-bit AVX512 - Multiply + Add", threads);
    f64v3_MulAdd_AVX512_c12u8_c8u12().run("Double-Precision - 512-bit AVX512 - Multiply + Add", threads);

    f32v4_FMA_AVX512_c24x4().run("Single-Precision - 512-bit AVX512 - Fused Multiply Add", threads);
    f64v3_FMA_AVX512_c24x4().run("Double-Precision - 512-bit AVX512 - Fused Multiply Add", threads);

	std::cout << std::endl;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
