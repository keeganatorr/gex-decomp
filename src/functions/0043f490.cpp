// Adapted from pc_decomp_backup/src/functions/FUN_0043F490.cpp
// Historical source SHA256: 44eac587d8a43fa30d7289f4cfcb6939f576bc3223b144b32b359c43732ff2d8
extern "C" {
extern "C" { extern int DAT_0046a650; }
extern "C" { extern int DAT_0046a654; }
extern "C" { extern int DAT_0046a64c; }
extern "C" { extern int DAT_0046a660; }
extern "C" { extern int DAT_0046a65c; }
extern "C" { extern int DAT_0046a658; }
extern "C" { extern int DAT_0046a648; }
extern "C" { extern int DAT_0046a644; }
extern "C" { extern int DAT_0046a640; }
extern "C" { extern unsigned char DAT_004a2afa; }
extern "C" { extern unsigned char DAT_004a2af8; }
extern "C" { extern unsigned char DAT_004a2af9; }
extern "C" { extern int DAT_004a2afc; }
extern "C" { extern int DAT_004a2b00; }
extern "C" void __cdecl GEX_Target(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
    DAT_004a2b00 = 1;
    if (p3 < p2) p3 = p2;
    if (p5 < p4) p5 = p4;
    if (p7 < p6) p7 = p6;
    DAT_0046a660 = (p2 + p3 + 1) * 0x8000;
    DAT_0046a65c = (p4 + p5 + 1) * 0x8000;
    DAT_0046a658 = (p6 + p7 + 1) * 0x8000;
    if (p1 != 0) {
        DAT_0046a650 = (DAT_0046a660 - DAT_0046a648) / p1;
        DAT_0046a654 = (DAT_0046a65c - DAT_0046a644) / p1;
        DAT_0046a64c = (DAT_0046a658 - DAT_0046a640) / p1;
    } else {
        DAT_004a2afa = (unsigned char)((unsigned int)DAT_0046a660 >> 0x10);
        DAT_004a2af8 = (unsigned char)((unsigned int)DAT_0046a658 >> 0x10);
        DAT_004a2af9 = (unsigned char)((unsigned int)DAT_0046a65c >> 0x10);
        DAT_004a2afc = (unsigned int)DAT_004a2afa + (((unsigned int)DAT_004a2af8 * 0x100 + (unsigned int)DAT_004a2af9) * 0x100);
    }
}
}
