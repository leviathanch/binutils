#as: -mfpu=metac21
#objdump: -dr
#name: metafpu21ext

.*: +file format .*

Disassembly of section \.text:

00000000 <.text>:
.*:	a0 80 00 f0 	FD        ABS       FX\.0,FX\.2
.*:	80 00 18 f0 	F         ABS       FX\.3,FX\.0
.*:	c0 00 31 f0 	FL        ABS       FX\.6,FX\.4
.*:	03 22 00 be 	F         MMOVD     D1Re0,D1Ar1,D1\.7,FX\.0,FX\.1,FX\.2
.*:	82 00 02 be 	F         MMOVD     D0Re0,D0Ar6,FX\.8,FX\.9
.*:	82 a0 00 bf 	F         MMOVL     D0Re0,D0Ar6,D0\.7,FX\.2,FX\.4,FX\.6
.*:	83 00 18 bf 	F         MMOVL     D1Ar1,D1RtP,FX\.0,FX\.2
.*:	03 22 00 ce 	F         MMOVD     FX\.0,FX\.1,FX\.2,D1Re0,D1Ar1,D1\.7
.*:	82 00 02 ce 	F         MMOVD     FX\.8,FX\.9,D0Re0,D0Ar6
.*:	82 a0 00 cf 	F         MMOVL     FX\.2,FX\.4,FX\.6,D0Re0,D0Ar6,D0\.7
.*:	83 00 18 cf 	F         MMOVL     FX\.0,FX\.2,D1Ar1,D1RtP
.*:	20 80 00 f0 	FD        MOV       FX\.0,FX\.2
.*:	00 00 18 f0 	F         MOV       FX\.3,FX\.0
.*:	40 00 31 f0 	FL        MOV       FX\.6,FX\.4
.*:	fb ff 07 f0 	FD        MOV       FX\.0,#0xffff
.*:	81 00 18 f0 	F         MOV       FX\.3,#0x10
.*:	05 78 30 f0 	FL        MOV       FX\.6,#0xf00
.*:	20 81 00 f0 	FD        NEG       FX\.0,FX\.2
.*:	00 01 18 f0 	F         NEG       FX\.3,FX\.0
.*:	40 01 31 f0 	FL        NEG       FX\.6,FX\.4
.*:	80 51 30 f0 	F         PACK      FX\.6,FX\.1,FX\.8
.*:	c0 01 30 f0 	FL        SWAP      FX\.6,FX\.0
.*:	20 80 01 f3 	FD        CMP       FX\.6,FX\.0
.*:	00 80 01 f3 	F         CMP       FX\.6,FX\.0
.*:	40 80 01 f3 	FL        CMP       FX\.6,FX\.0
.*:	20 80 09 f3 	FDA       CMP       FX\.6,FX\.0
.*:	00 80 09 f3 	FA        CMP       FX\.6,FX\.0
.*:	40 80 09 f3 	FLA       CMP       FX\.6,FX\.0
.*:	a0 80 01 f3 	FDQ       CMP       FX\.6,FX\.0
.*:	80 80 01 f3 	FQ        CMP       FX\.6,FX\.0
.*:	c0 80 01 f3 	FLQ       CMP       FX\.6,FX\.0
.*:	a0 80 09 f3 	FDAQ      CMP       FX\.6,FX\.0
.*:	80 80 09 f3 	FAQ       CMP       FX\.6,FX\.0
.*:	c0 80 09 f3 	FLAQ      CMP       FX\.6,FX\.0
.*:	20 81 01 f3 	FD        CMP       FX\.6,#0
.*:	00 81 01 f3 	F         CMP       FX\.6,#0
.*:	40 81 01 f3 	FL        CMP       FX\.6,#0
.*:	a1 04 30 f3 	FD        MAX       FX\.6,FX\.0,FX\.2
.*:	81 0a 19 f3 	F         MAX       FX\.3,FX\.4,FX\.5
.*:	c1 0c 11 f3 	FL        MAX       FX\.2,FX\.4,FX\.6
.*:	21 04 30 f3 	FD        MIN       FX\.6,FX\.0,FX\.2
.*:	01 0a 19 f3 	F         MIN       FX\.3,FX\.4,FX\.5
.*:	41 0c 11 f3 	FL        MIN       FX\.2,FX\.4,FX\.6
.*:	21 41 30 f2 	F         DTOF      FX\.6,FX\.1
.*:	01 81 00 f2 	F         FTOD      FX\.0,FX\.2
.*:	40 03 30 f2 	FL        FTOH      FX\.6,FX\.0
.*:	00 43 19 f2 	F         FTOH      FX\.3,FX\.5
.*:	20 03 10 f2 	F         DTOH      FX\.2,FX\.0
.*:	00 71 30 f2 	FZ        FTOI      FX\.6,FX\.1
.*:	00 21 11 f2 	F         FTOI      FX\.2,FX\.4
.*:	40 21 20 f2 	FL        FTOI      FX\.4,FX\.0
.*:	40 71 19 f2 	FLZ       FTOI      FX\.3,FX\.5
.*:	20 61 30 f2 	F         DTOI      FX\.6,FX\.1
.*:	20 71 30 f2 	FZ        DTOI      FX\.6,FX\.1
.*:	20 23 11 f2 	F         DTOL      FX\.2,FX\.4
.*:	20 33 11 f2 	FZ        DTOL      FX\.2,FX\.4
.*:	00 c6 30 f2 	F         FTOX      FX\.6,FX\.3,#0x3
.*:	40 08 20 f2 	FL        FTOX      FX\.4,FX\.0,#0x4
.*:	20 10 11 f2 	F         DTOX      FX\.2,FX\.4,#0x8
.*:	a0 06 11 f2 	F         DTOXL     FX\.2,FX\.4,#0x6
.*:	21 03 31 f2 	F         HTOD      FX\.6,FX\.4
.*:	41 83 30 f2 	FL        HTOF      FX\.6,FX\.2
.*:	01 03 11 f2 	F         HTOF      FX\.2,FX\.4
.*:	01 61 30 f2 	F         ITOF      FX\.6,FX\.1
.*:	41 21 20 f2 	FL        ITOF      FX\.4,FX\.0
.*:	21 21 11 f2 	F         ITOD      FX\.2,FX\.4
.*:	21 23 11 f2 	F         LTOD      FX\.2,FX\.4
.*:	01 c4 10 f2 	F         XTOF      FX\.2,FX\.3,#0x2
.*:	41 06 30 f2 	FL        XTOF      FX\.6,FX\.0,#0x3
.*:	21 08 11 f2 	F         XTOD      FX\.2,FX\.4,#0x4
.*:	a1 07 11 f2 	F         XLTOD     FX\.2,FX\.4,#0x7
.*:	21 88 00 f1 	FD        ADD       FX\.0,FX\.2,FX\.4
.*:	01 40 18 f1 	F         ADD       FX\.3,FX\.1,FX\.0
.*:	41 04 31 f1 	FL        ADD       FX\.6,FX\.4,FX\.2
.*:	a1 88 00 f1 	FDI       ADD       FX\.0,FX\.2,FX\.4
.*:	81 40 18 f1 	FI        ADD       FX\.3,FX\.1,FX\.0
.*:	c1 04 31 f1 	FLI       ADD       FX\.6,FX\.4,FX\.2
.*:	20 89 00 f1 	FD        MUL       FX\.0,FX\.2,FX\.4
.*:	00 41 18 f1 	F         MUL       FX\.3,FX\.1,FX\.0
.*:	40 05 31 f1 	FL        MUL       FX\.6,FX\.4,FX\.2
.*:	a0 89 00 f1 	FDI       MUL       FX\.0,FX\.2,FX\.4
.*:	80 41 18 f1 	FI        MUL       FX\.3,FX\.1,FX\.0
.*:	c0 05 31 f1 	FLI       MUL       FX\.6,FX\.4,FX\.2
.*:	21 89 00 f1 	FD        SUB       FX\.0,FX\.2,FX\.4
.*:	01 41 18 f1 	F         SUB       FX\.3,FX\.1,FX\.0
.*:	41 05 31 f1 	FL        SUB       FX\.6,FX\.4,FX\.2
.*:	a1 89 00 f1 	FDI       SUB       FX\.0,FX\.2,FX\.4
.*:	81 41 18 f1 	FI        SUB       FX\.3,FX\.1,FX\.0
.*:	c1 05 31 f1 	FLI       SUB       FX\.6,FX\.4,FX\.2
.*:	20 88 00 f6 	FD        MAC       ACF\.0,FX\.2,FX\.4
.*:	00 40 00 f6 	F         MAC       ACF\.0,FX\.1,FX\.0
.*:	24 88 00 f6 	FD        MAR       FX\.0,FX\.2,FX\.4
.*:	04 40 18 f6 	F         MAR       FX\.3,FX\.1,FX\.0
.*:	24 89 00 f6 	FD        MARS      FX\.0,FX\.2,FX\.4
.*:	04 41 18 f6 	F         MARS      FX\.3,FX\.1,FX\.0
.*:	28 0c 11 f6 	FD        MAW       FX\.2,FX\.4,FX\.6
.*:	08 0c 08 f6 	F         MAW       FX\.1,FX\.0,FX\.6
.*:	28 0d 11 f6 	FD        MAWS      FX\.2,FX\.4,FX\.6
.*:	08 0d 08 f6 	F         MAWS      FX\.1,FX\.0,FX\.6
.*:	29 0c 01 f6 	FD        MAW1      FX\.4,FX\.6
.*:	09 0c 00 f6 	F         MAW1      FX\.0,FX\.6
.*:	29 0d 01 f6 	FD        MAWS1     FX\.4,FX\.6
.*:	09 0d 00 f6 	F         MAWS1     FX\.0,FX\.6
.*:	20 88 00 f5 	FD        MXA       FX\.0,FX\.2,FX\.4
.*:	00 40 18 f5 	F         MXA       FX\.3,FX\.1,FX\.0
.*:	40 04 31 f5 	FL        MXA       FX\.6,FX\.4,FX\.2
.*:	a0 88 00 f5 	FDI       MXA       FX\.0,FX\.2,FX\.4
.*:	80 40 18 f5 	FI        MXA       FX\.3,FX\.1,FX\.0
.*:	c0 04 31 f5 	FLI       MXA       FX\.6,FX\.4,FX\.2
.*:	20 89 00 f5 	FD        MXAS      FX\.0,FX\.2,FX\.4
.*:	00 41 18 f5 	F         MXAS      FX\.3,FX\.1,FX\.0
.*:	40 05 31 f5 	FL        MXAS      FX\.6,FX\.4,FX\.2
.*:	a0 89 00 f5 	FDI       MXAS      FX\.0,FX\.2,FX\.4
.*:	80 41 18 f5 	FI        MXAS      FX\.3,FX\.1,FX\.0
.*:	c0 05 31 f5 	FLI       MXAS      FX\.6,FX\.4,FX\.2
.*:	21 88 00 f5 	FD        MXA1      FX\.0,FX\.2,FX\.4
.*:	01 40 18 f5 	F         MXA1      FX\.3,FX\.1,FX\.0
.*:	41 04 31 f5 	FL        MXA1      FX\.6,FX\.4,FX\.2
.*:	a1 88 00 f5 	FDI       MXA1      FX\.0,FX\.2,FX\.4
.*:	81 40 18 f5 	FI        MXA1      FX\.3,FX\.1,FX\.0
.*:	c1 04 31 f5 	FLI       MXA1      FX\.6,FX\.4,FX\.2
.*:	21 89 00 f5 	FD        MXAS1     FX\.0,FX\.2,FX\.4
.*:	01 41 18 f5 	F         MXAS1     FX\.3,FX\.1,FX\.0
.*:	41 05 31 f5 	FL        MXAS1     FX\.6,FX\.4,FX\.2
.*:	a1 89 00 f5 	FDI       MXAS1     FX\.0,FX\.2,FX\.4
.*:	81 41 18 f5 	FI        MXAS1     FX\.3,FX\.1,FX\.0
.*:	c1 05 31 f5 	FLI       MXAS1     FX\.6,FX\.4,FX\.2
.*:	30 88 00 f6 	FD        MUZ       FX\.0,FX\.2,FX\.4
.*:	10 4c 21 f6 	F         MUZ       FX\.4,FX\.5,FX\.6
.*:	50 04 31 f6 	FL        MUZ       FX\.6,FX\.4,FX\.2
.*:	b0 88 00 f6 	FDI       MUZ       FX\.0,FX\.2,FX\.4
.*:	90 4c 21 f6 	FI        MUZ       FX\.4,FX\.5,FX\.6
.*:	d0 04 31 f6 	FLI       MUZ       FX\.6,FX\.4,FX\.2
.*:	32 88 00 f6 	FDQ       MUZ       FX\.0,FX\.2,FX\.4
.*:	12 4c 21 f6 	FQ        MUZ       FX\.4,FX\.5,FX\.6
.*:	52 04 31 f6 	FLQ       MUZ       FX\.6,FX\.4,FX\.2
.*:	b2 88 00 f6 	FDIQ      MUZ       FX\.0,FX\.2,FX\.4
.*:	92 4c 21 f6 	FIQ       MUZ       FX\.4,FX\.5,FX\.6
.*:	d2 04 31 f6 	FLIQ      MUZ       FX\.6,FX\.4,FX\.2
.*:	30 89 00 f6 	FD        MUZS      FX\.0,FX\.2,FX\.4
.*:	10 4d 21 f6 	F         MUZS      FX\.4,FX\.5,FX\.6
.*:	50 05 31 f6 	FL        MUZS      FX\.6,FX\.4,FX\.2
.*:	31 88 00 f6 	FD        MUZ1      FX\.0,FX\.2,FX\.4
.*:	11 4c 21 f6 	F         MUZ1      FX\.4,FX\.5,FX\.6
.*:	51 04 31 f6 	FL        MUZ1      FX\.6,FX\.4,FX\.2
.*:	31 89 00 f6 	FD        MUZS1     FX\.0,FX\.2,FX\.4
.*:	11 4d 21 f6 	F         MUZS1     FX\.4,FX\.5,FX\.6
.*:	51 05 31 f6 	FL        MUZS1     FX\.6,FX\.4,FX\.2
.*:	20 80 00 f7 	FD        RCP       FX\.0,FX\.2
.*:	00 40 18 f7 	F         RCP       FX\.3,FX\.1
.*:	40 00 31 f7 	FL        RCP       FX\.6,FX\.4
.*:	a0 80 00 f7 	FDI       RCP       FX\.0,FX\.2
.*:	80 40 18 f7 	FI        RCP       FX\.3,FX\.1
.*:	c0 00 31 f7 	FLI       RCP       FX\.6,FX\.4
.*:	20 84 00 f7 	FDZ       RCP       FX\.0,FX\.2
.*:	00 44 18 f7 	FZ        RCP       FX\.3,FX\.1
.*:	40 04 31 f7 	FLZ       RCP       FX\.6,FX\.4
.*:	a0 84 00 f7 	FDIZ      RCP       FX\.0,FX\.2
.*:	80 44 18 f7 	FIZ       RCP       FX\.3,FX\.1
.*:	c0 04 31 f7 	FLIZ      RCP       FX\.6,FX\.4
.*:	20 82 00 f7 	FDQ       RCP       FX\.0,FX\.2
.*:	00 42 18 f7 	FQ        RCP       FX\.3,FX\.1
.*:	40 02 31 f7 	FLQ       RCP       FX\.6,FX\.4
.*:	a0 82 00 f7 	FDIQ      RCP       FX\.0,FX\.2
.*:	80 42 18 f7 	FIQ       RCP       FX\.3,FX\.1
.*:	c0 02 31 f7 	FLIQ      RCP       FX\.6,FX\.4
.*:	20 81 00 f7 	FD        RSQ       FX\.0,FX\.2
.*:	00 41 18 f7 	F         RSQ       FX\.3,FX\.1
.*:	40 01 31 f7 	FL        RSQ       FX\.6,FX\.4
.*:	a0 81 00 f7 	FDI       RSQ       FX\.0,FX\.2
.*:	80 41 18 f7 	FI        RSQ       FX\.3,FX\.1
.*:	c0 01 31 f7 	FLI       RSQ       FX\.6,FX\.4
.*:	20 85 00 f7 	FDZ       RSQ       FX\.0,FX\.2
.*:	00 45 18 f7 	FZ        RSQ       FX\.3,FX\.1
.*:	40 05 31 f7 	FLZ       RSQ       FX\.6,FX\.4
.*:	a0 85 00 f7 	FDIZ      RSQ       FX\.0,FX\.2
.*:	80 45 18 f7 	FIZ       RSQ       FX\.3,FX\.1
.*:	c0 05 31 f7 	FLIZ      RSQ       FX\.6,FX\.4
.*:	20 83 00 f7 	FDQ       RSQ       FX\.0,FX\.2
.*:	00 43 18 f7 	FQ        RSQ       FX\.3,FX\.1
.*:	40 03 31 f7 	FLQ       RSQ       FX\.6,FX\.4
.*:	a0 83 00 f7 	FDIQ      RSQ       FX\.0,FX\.2
.*:	80 43 18 f7 	FIQ       RSQ       FX\.3,FX\.1
.*:	c0 03 31 f7 	FLIQ      RSQ       FX\.6,FX\.4
.*:	00 04 31 f4 	FL        ADDRE     FX\.6,FX\.4,FX\.2
.*:	80 04 31 f4 	FLI       ADDRE     FX\.6,FX\.4,FX\.2
.*:	01 04 31 f4 	FL        MULRE     FX\.6,FX\.4,FX\.2
.*:	81 04 31 f4 	FLI       MULRE     FX\.6,FX\.4,FX\.2
.*:	00 05 31 f4 	FL        SUBRE     FX\.6,FX\.4,FX\.2
.*:	80 05 31 f4 	FLI       SUBRE     FX\.6,FX\.4,FX\.2
