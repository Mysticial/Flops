/* f32v2_Reduce_SSE.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/05/2017
 * Last Modified    : 06/05/2017
 * 
 */

#ifndef _flops_f32v2_Reduce_SSE_H
#define _flops_f32v2_Reduce_SSE_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <xmmintrin.h>
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
inline float reduce(__m128 x){
    x = _mm_add_ps(x, _mm_unpackhi_ps(x, x));
    x = _mm_add_ps(x, _mm_shuffle_ps(x, x, 1));
    return _mm_cvtss_f32(x);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif