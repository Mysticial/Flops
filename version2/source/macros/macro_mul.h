/* macro_mul.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 */

#ifndef _flops_macro_mul_H
#define _flops_macro_mul_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#define flops_mul_chains8_ops16(    \
    vmul,   \
    mul0,mul1,  \
    r0,r1,r2,r3,r4,r5,r6,r7 \
){  \
    r0 = vmul(r0,mul0); \
    r1 = vmul(r1,mul0); \
    r2 = vmul(r2,mul0); \
    r3 = vmul(r3,mul0); \
    r4 = vmul(r4,mul0); \
    r5 = vmul(r5,mul0); \
    r6 = vmul(r6,mul0); \
    r7 = vmul(r7,mul0); \
    r0 = vmul(r0,mul1); \
    r1 = vmul(r1,mul1); \
    r2 = vmul(r2,mul1); \
    r3 = vmul(r3,mul1); \
    r4 = vmul(r4,mul1); \
    r5 = vmul(r5,mul1); \
    r6 = vmul(r6,mul1); \
    r7 = vmul(r7,mul1); \
}
#define flops_mul_chains12_ops24(   \
    vmul,   \
    mul0,mul1,  \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    r0 = vmul(r0,mul0); \
    r1 = vmul(r1,mul0); \
    r2 = vmul(r2,mul0); \
    r3 = vmul(r3,mul0); \
    r4 = vmul(r4,mul0); \
    r5 = vmul(r5,mul0); \
    r6 = vmul(r6,mul0); \
    r7 = vmul(r7,mul0); \
    r8 = vmul(r8,mul0); \
    r9 = vmul(r9,mul0); \
    rA = vmul(rA,mul0); \
    rB = vmul(rB,mul0); \
    r0 = vmul(r0,mul1); \
    r1 = vmul(r1,mul1); \
    r2 = vmul(r2,mul1); \
    r3 = vmul(r3,mul1); \
    r4 = vmul(r4,mul1); \
    r5 = vmul(r5,mul1); \
    r6 = vmul(r6,mul1); \
    r7 = vmul(r7,mul1); \
    r8 = vmul(r8,mul1); \
    r9 = vmul(r9,mul1); \
    rA = vmul(rA,mul1); \
    rB = vmul(rB,mul1); \
}
////////////////////////////////////////////////////////////////////////////////
#define flops_mul_chains8_unroll2_ops32(    \
    vmul,   \
    mul0,mul1,  \
    r0,r1,r2,r3,r4,r5,r6,r7 \
){  \
    flops_mul_chains8_ops16(vmul,mul0,mul1,r0,r1,r2,r3,r4,r5,r6,r7);    \
    flops_mul_chains8_ops16(vmul,mul0,mul1,r0,r1,r2,r3,r4,r5,r6,r7);    \
}
#define flops_mul_chains12_unroll2_ops48(   \
    vmul,   \
    mul0,mul1,  \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    flops_mul_chains12_ops24(vmul,mul0,mul1,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);   \
    flops_mul_chains12_ops24(vmul,mul0,mul1,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);   \
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
