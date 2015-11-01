/* macro_mac.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 */

#ifndef _flops_macro_mac_H
#define _flops_macro_mac_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#define flops_muladd_chains12_ops24(    \
    vadd, vsub, vmul, \
    add0, sub0, mul0, mul1,    \
    r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB \
){  \
    r6 = vmul(r6, mul0); \
    r0 = vadd(r0, add0); \
    \
    r7 = vmul(r7, mul0); \
    r1 = vadd(r1, add0); \
    \
    r8 = vmul(r8, mul0); \
    r2 = vadd(r2, add0); \
    \
    r9 = vmul(r9, mul0); \
    r3 = vadd(r3, add0); \
    \
    rA = vmul(rA, mul0); \
    r4 = vadd(r4, add0); \
    \
    rB = vmul(rB, mul0); \
    r5 = vadd(r5, add0); \
    \
    r6 = vmul(r6, mul1); \
    r0 = vsub(r0, sub0); \
    \
    r7 = vmul(r7, mul1); \
    r1 = vsub(r1, sub0); \
    \
    r8 = vmul(r8, mul1); \
    r2 = vsub(r2, sub0); \
    \
    r9 = vmul(r9, mul1); \
    r3 = vsub(r3, sub0); \
    \
    rA = vmul(rA, mul1); \
    r4 = vsub(r4, sub0); \
    \
    rB = vmul(rB, mul1); \
    r5 = vsub(r5, sub0); \
}
////////////////////////////////////////////////////////////////////////////////
#define flops_muladd_chains12_unroll2_ops48(    \
    vadd, vsub, vmul, \
    add0, sub0, mul0, mul1,    \
    r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB \
){  \
    flops_muladd_chains12_ops24(vadd, vsub, vmul, add0, sub0, mul0, mul1, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB);    \
    flops_muladd_chains12_ops24(vadd, vsub, vmul, add0, sub0, mul0, mul1, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, rA, rB);    \
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
