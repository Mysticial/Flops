/* macro_fma.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 */

#ifndef _flops_macro_fma_H
#define _flops_macro_fma_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#define flops_fma_linear_chains12_ops24(    \
    vpma,vnma,  \
    mul0,mul1,  \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    r0 = vpma(mul0,mul1,r0);    \
    r1 = vpma(mul0,mul1,r1);    \
    r2 = vpma(mul0,mul1,r2);    \
    r3 = vpma(mul0,mul1,r3);    \
    r4 = vpma(mul0,mul1,r4);    \
    r5 = vpma(mul0,mul1,r5);    \
    r6 = vpma(mul0,mul1,r6);    \
    r7 = vpma(mul0,mul1,r7);    \
    r8 = vpma(mul0,mul1,r8);    \
    r9 = vpma(mul0,mul1,r9);    \
    rA = vpma(mul0,mul1,rA);    \
    rB = vpma(mul0,mul1,rB);    \
    r0 = vnma(mul0,mul1,r0);    \
    r1 = vnma(mul0,mul1,r1);    \
    r2 = vnma(mul0,mul1,r2);    \
    r3 = vnma(mul0,mul1,r3);    \
    r4 = vnma(mul0,mul1,r4);    \
    r5 = vnma(mul0,mul1,r5);    \
    r6 = vnma(mul0,mul1,r6);    \
    r7 = vnma(mul0,mul1,r7);    \
    r8 = vnma(mul0,mul1,r8);    \
    r9 = vnma(mul0,mul1,r9);    \
    rA = vnma(mul0,mul1,rA);    \
    rB = vnma(mul0,mul1,rB);    \
}
#define flops_fma_horner_chains12_ops24(    \
    vpma,vnma,  \
    mul0,add0,mul1,add1,    \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    r0 = vpma(r0,mul0,add0);    \
    r1 = vpma(r1,mul0,add0);    \
    r2 = vpma(r2,mul0,add0);    \
    r3 = vpma(r3,mul0,add0);    \
    r4 = vpma(r4,mul0,add0);    \
    r5 = vpma(r5,mul0,add0);    \
    r6 = vpma(r6,mul0,add0);    \
    r7 = vpma(r7,mul0,add0);    \
    r8 = vpma(r8,mul0,add0);    \
    r9 = vpma(r9,mul0,add0);    \
    rA = vpma(rA,mul0,add0);    \
    rB = vpma(rB,mul0,add0);    \
    r0 = vpma(r0,mul1,add1);    \
    r1 = vpma(r1,mul1,add1);    \
    r2 = vpma(r2,mul1,add1);    \
    r3 = vpma(r3,mul1,add1);    \
    r4 = vpma(r4,mul1,add1);    \
    r5 = vpma(r5,mul1,add1);    \
    r6 = vpma(r6,mul1,add1);    \
    r7 = vpma(r7,mul1,add1);    \
    r8 = vpma(r8,mul1,add1);    \
    r9 = vpma(r9,mul1,add1);    \
    rA = vpma(rA,mul1,add1);    \
    rB = vpma(rB,mul1,add1);    \
}
////////////////////////////////////////////////////////////////////////////////
#define flops_fma_linear_chains12_unroll2_ops48(    \
    vpma,vnma,  \
    mul0,mul1,  \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    flops_fma_linear_chains12_ops24(vpma,vnma,mul0,mul1,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);   \
    flops_fma_linear_chains12_ops24(vpma,vnma,mul0,mul1,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);   \
}
#define flops_fma_horner_chains12_unroll2_ops48(    \
    vpma,   \
    mul0,mul1,  \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    flops_fma_horner_chains12_ops24(vpma,mul0,add0,mul1,add1,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);  \
    flops_fma_horner_chains12_ops24(vpma,mul0,add0,mul1,add1,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);  \
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
