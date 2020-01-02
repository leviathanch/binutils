/* Decode header for iq2000bf.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright 1996-2020 Free Software Foundation, Inc.

This file is part of the GNU simulators.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, see <http://www.gnu.org/licenses/>.

*/

#ifndef IQ2000BF_DECODE_H
#define IQ2000BF_DECODE_H

extern const IDESC *iq2000bf_decode (SIM_CPU *, IADDR,
                                  CGEN_INSN_WORD, CGEN_INSN_WORD,
                                  ARGBUF *);
extern void iq2000bf_init_idesc_table (SIM_CPU *);
extern void iq2000bf_sem_init_idesc_table (SIM_CPU *);
extern void iq2000bf_semf_init_idesc_table (SIM_CPU *);

/* Enum declaration for instructions in cpu family iq2000bf.  */
typedef enum iq2000bf_insn_type {
  IQ2000BF_INSN_X_INVALID, IQ2000BF_INSN_X_AFTER, IQ2000BF_INSN_X_BEFORE, IQ2000BF_INSN_X_CTI_CHAIN
 , IQ2000BF_INSN_X_CHAIN, IQ2000BF_INSN_X_BEGIN, IQ2000BF_INSN_ADD, IQ2000BF_INSN_ADDI
 , IQ2000BF_INSN_ADDIU, IQ2000BF_INSN_ADDU, IQ2000BF_INSN_ADO16, IQ2000BF_INSN_AND
 , IQ2000BF_INSN_ANDI, IQ2000BF_INSN_ANDOI, IQ2000BF_INSN_NOR, IQ2000BF_INSN_OR
 , IQ2000BF_INSN_ORI, IQ2000BF_INSN_RAM, IQ2000BF_INSN_SLL, IQ2000BF_INSN_SLLV
 , IQ2000BF_INSN_SLMV, IQ2000BF_INSN_SLT, IQ2000BF_INSN_SLTI, IQ2000BF_INSN_SLTIU
 , IQ2000BF_INSN_SLTU, IQ2000BF_INSN_SRA, IQ2000BF_INSN_SRAV, IQ2000BF_INSN_SRL
 , IQ2000BF_INSN_SRLV, IQ2000BF_INSN_SRMV, IQ2000BF_INSN_SUB, IQ2000BF_INSN_SUBU
 , IQ2000BF_INSN_XOR, IQ2000BF_INSN_XORI, IQ2000BF_INSN_BBI, IQ2000BF_INSN_BBIN
 , IQ2000BF_INSN_BBV, IQ2000BF_INSN_BBVN, IQ2000BF_INSN_BEQ, IQ2000BF_INSN_BEQL
 , IQ2000BF_INSN_BGEZ, IQ2000BF_INSN_BGEZAL, IQ2000BF_INSN_BGEZALL, IQ2000BF_INSN_BGEZL
 , IQ2000BF_INSN_BLTZ, IQ2000BF_INSN_BLTZL, IQ2000BF_INSN_BLTZAL, IQ2000BF_INSN_BLTZALL
 , IQ2000BF_INSN_BMB0, IQ2000BF_INSN_BMB1, IQ2000BF_INSN_BMB2, IQ2000BF_INSN_BMB3
 , IQ2000BF_INSN_BNE, IQ2000BF_INSN_BNEL, IQ2000BF_INSN_JALR, IQ2000BF_INSN_JR
 , IQ2000BF_INSN_LB, IQ2000BF_INSN_LBU, IQ2000BF_INSN_LH, IQ2000BF_INSN_LHU
 , IQ2000BF_INSN_LUI, IQ2000BF_INSN_LW, IQ2000BF_INSN_SB, IQ2000BF_INSN_SH
 , IQ2000BF_INSN_SW, IQ2000BF_INSN_BREAK, IQ2000BF_INSN_SYSCALL, IQ2000BF_INSN_ANDOUI
 , IQ2000BF_INSN_ORUI, IQ2000BF_INSN_BGTZ, IQ2000BF_INSN_BGTZL, IQ2000BF_INSN_BLEZ
 , IQ2000BF_INSN_BLEZL, IQ2000BF_INSN_MRGB, IQ2000BF_INSN_BCTXT, IQ2000BF_INSN_BC0F
 , IQ2000BF_INSN_BC0FL, IQ2000BF_INSN_BC3F, IQ2000BF_INSN_BC3FL, IQ2000BF_INSN_BC0T
 , IQ2000BF_INSN_BC0TL, IQ2000BF_INSN_BC3T, IQ2000BF_INSN_BC3TL, IQ2000BF_INSN_CFC0
 , IQ2000BF_INSN_CFC1, IQ2000BF_INSN_CFC2, IQ2000BF_INSN_CFC3, IQ2000BF_INSN_CHKHDR
 , IQ2000BF_INSN_CTC0, IQ2000BF_INSN_CTC1, IQ2000BF_INSN_CTC2, IQ2000BF_INSN_CTC3
 , IQ2000BF_INSN_JCR, IQ2000BF_INSN_LUC32, IQ2000BF_INSN_LUC32L, IQ2000BF_INSN_LUC64
 , IQ2000BF_INSN_LUC64L, IQ2000BF_INSN_LUK, IQ2000BF_INSN_LULCK, IQ2000BF_INSN_LUM32
 , IQ2000BF_INSN_LUM32L, IQ2000BF_INSN_LUM64, IQ2000BF_INSN_LUM64L, IQ2000BF_INSN_LUR
 , IQ2000BF_INSN_LURL, IQ2000BF_INSN_LUULCK, IQ2000BF_INSN_MFC0, IQ2000BF_INSN_MFC1
 , IQ2000BF_INSN_MFC2, IQ2000BF_INSN_MFC3, IQ2000BF_INSN_MTC0, IQ2000BF_INSN_MTC1
 , IQ2000BF_INSN_MTC2, IQ2000BF_INSN_MTC3, IQ2000BF_INSN_PKRL, IQ2000BF_INSN_PKRLR1
 , IQ2000BF_INSN_PKRLR30, IQ2000BF_INSN_RB, IQ2000BF_INSN_RBR1, IQ2000BF_INSN_RBR30
 , IQ2000BF_INSN_RFE, IQ2000BF_INSN_RX, IQ2000BF_INSN_RXR1, IQ2000BF_INSN_RXR30
 , IQ2000BF_INSN_SLEEP, IQ2000BF_INSN_SRRD, IQ2000BF_INSN_SRRDL, IQ2000BF_INSN_SRULCK
 , IQ2000BF_INSN_SRWR, IQ2000BF_INSN_SRWRU, IQ2000BF_INSN_TRAPQFL, IQ2000BF_INSN_TRAPQNE
 , IQ2000BF_INSN_TRAPREL, IQ2000BF_INSN_WB, IQ2000BF_INSN_WBU, IQ2000BF_INSN_WBR1
 , IQ2000BF_INSN_WBR1U, IQ2000BF_INSN_WBR30, IQ2000BF_INSN_WBR30U, IQ2000BF_INSN_WX
 , IQ2000BF_INSN_WXU, IQ2000BF_INSN_WXR1, IQ2000BF_INSN_WXR1U, IQ2000BF_INSN_WXR30
 , IQ2000BF_INSN_WXR30U, IQ2000BF_INSN_LDW, IQ2000BF_INSN_SDW, IQ2000BF_INSN_J
 , IQ2000BF_INSN_JAL, IQ2000BF_INSN_BMB, IQ2000BF_INSN__MAX
} IQ2000BF_INSN_TYPE;

/* Enum declaration for semantic formats in cpu family iq2000bf.  */
typedef enum iq2000bf_sfmt_type {
  IQ2000BF_SFMT_EMPTY, IQ2000BF_SFMT_ADD, IQ2000BF_SFMT_ADDI, IQ2000BF_SFMT_RAM
 , IQ2000BF_SFMT_SLL, IQ2000BF_SFMT_SLMV, IQ2000BF_SFMT_SLT, IQ2000BF_SFMT_SLTI
 , IQ2000BF_SFMT_BBI, IQ2000BF_SFMT_BBV, IQ2000BF_SFMT_BGEZ, IQ2000BF_SFMT_BGEZAL
 , IQ2000BF_SFMT_JALR, IQ2000BF_SFMT_JR, IQ2000BF_SFMT_LB, IQ2000BF_SFMT_LH
 , IQ2000BF_SFMT_LUI, IQ2000BF_SFMT_LW, IQ2000BF_SFMT_SB, IQ2000BF_SFMT_SH
 , IQ2000BF_SFMT_SW, IQ2000BF_SFMT_BREAK, IQ2000BF_SFMT_SYSCALL, IQ2000BF_SFMT_ANDOUI
 , IQ2000BF_SFMT_MRGB, IQ2000BF_SFMT_BCTXT, IQ2000BF_SFMT_LDW, IQ2000BF_SFMT_SDW
 , IQ2000BF_SFMT_J, IQ2000BF_SFMT_JAL
} IQ2000BF_SFMT_TYPE;

/* Function unit handlers (user written).  */

extern int iq2000bf_model_iq2000_u_exec (SIM_CPU *, const IDESC *, int /*unit_num*/, int /*referenced*/);

/* Profiling before/after handlers (user written) */

extern void iq2000bf_model_insn_before (SIM_CPU *, int /*first_p*/);
extern void iq2000bf_model_insn_after (SIM_CPU *, int /*last_p*/, int /*cycles*/);

#endif /* IQ2000BF_DECODE_H */
