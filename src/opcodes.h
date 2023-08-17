#ifndef OPCODES_H
#define OPCODES_H

enum Opcode
{
    /* Load - Store operations */

    //LDA
    op_lda_imm = 0xa9,
    op_lda_zp = 0xa5,
    op_lda_zpx = 0xb5,
    op_lda_ab = 0xad,
    op_lda_abx = 0xbd,
    op_lda_aby = 0xb9,
    op_lda_inx = 0xa1,
    op_lda_iny = 0xb1

    //
};

#endif // OPCODES_H
