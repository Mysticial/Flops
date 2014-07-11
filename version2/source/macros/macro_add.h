/* macro_add.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/10/2014
 * Last Modified    : 07/10/2014
 * 
 */

#ifndef _flops_macro_add_H
#define _flops_macro_add_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#define flops_add_chains4_ops8( \
    vadd,vsub,  \
    add0,sub0,  \
    r0,r1,r2,r3 \
){  \
    r0 = vadd(r0,add0); \
    r1 = vadd(r1,add0); \
    r2 = vadd(r2,add0); \
    r3 = vadd(r3,add0); \
    r0 = vsub(r0,sub0); \
    r1 = vsub(r1,sub0); \
    r2 = vsub(r2,sub0); \
    r3 = vsub(r3,sub0); \
}
#define flops_add_chains8_ops16(    \
    vadd,vsub,  \
    add0,sub0,  \
    r0,r1,r2,r3,r4,r5,r6,r7 \
){  \
    r0 = vadd(r0,add0); \
    r1 = vadd(r1,add0); \
    r2 = vadd(r2,add0); \
    r3 = vadd(r3,add0); \
    r4 = vadd(r4,add0); \
    r5 = vadd(r5,add0); \
    r6 = vadd(r6,add0); \
    r7 = vadd(r7,add0); \
    r0 = vsub(r0,sub0); \
    r1 = vsub(r1,sub0); \
    r2 = vsub(r2,sub0); \
    r3 = vsub(r3,sub0); \
    r4 = vsub(r4,sub0); \
    r5 = vsub(r5,sub0); \
    r6 = vsub(r6,sub0); \
    r7 = vsub(r7,sub0); \
}
#define flops_add_chains12_ops24(    \
    vadd,vsub,  \
    add0,sub0,  \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    r0 = vadd(r0,add0); \
    r1 = vadd(r1,add0); \
    r2 = vadd(r2,add0); \
    r3 = vadd(r3,add0); \
    r4 = vadd(r4,add0); \
    r5 = vadd(r5,add0); \
    r6 = vadd(r6,add0); \
    r7 = vadd(r7,add0); \
    r8 = vadd(r8,add0); \
    r9 = vadd(r9,add0); \
    rA = vadd(rA,add0); \
    rB = vadd(rB,add0); \
    r0 = vsub(r0,sub0); \
    r1 = vsub(r1,sub0); \
    r2 = vsub(r2,sub0); \
    r3 = vsub(r3,sub0); \
    r4 = vsub(r4,sub0); \
    r5 = vsub(r5,sub0); \
    r6 = vsub(r6,sub0); \
    r7 = vsub(r7,sub0); \
    r8 = vsub(r8,sub0); \
    r9 = vsub(r9,sub0); \
    rA = vsub(rA,sub0); \
    rB = vsub(rB,sub0); \
}
////////////////////////////////////////////////////////////////////////////////
#define flops_add_chains4_unroll2_ops16(    \
    vadd,vsub,  \
    add0,sub0,  \
    r0,r1,r2,r3 \
){  \
    flops_add_chains4_ops8(vadd,vsub,add0,sub0,r0,r1,r2,r3);    \
    flops_add_chains4_ops8(vadd,vsub,add0,sub0,r0,r1,r2,r3);    \
}
#define flops_add_chains8_unroll2_ops32(    \
    vadd,vsub,  \
    add0,sub0,  \
    r0,r1,r2,r3,r4,r5,r6,r7 \
){  \
    flops_add_chains8_ops16(vadd,vsub,add0,sub0,r0,r1,r2,r3,r4,r5,r6,r7);   \
    flops_add_chains8_ops16(vadd,vsub,add0,sub0,r0,r1,r2,r3,r4,r5,r6,r7);   \
}
#define flops_add_chains12_unroll2_ops48(    \
    vadd,vsub,  \
    add0,sub0,  \
    r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB \
){  \
    flops_add_chains12_ops24(vadd,vsub,add0,sub0,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);  \
    flops_add_chains12_ops24(vadd,vsub,add0,sub0,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,rA,rB);  \
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
