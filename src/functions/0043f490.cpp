extern "C" {
extern int DAT_0046a650, DAT_0046a654, DAT_0046a64c;
extern int DAT_0046a660, DAT_0046a65c, DAT_0046a658;
extern int DAT_0046a648, DAT_0046a644, DAT_0046a640;
extern unsigned char DAT_004a2afa, DAT_004a2af8, DAT_004a2af9;
extern int DAT_004a2afc, DAT_004a2b00;

void __cdecl GEX_Target(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
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
        return;
    }
    unsigned char r = (unsigned char)(DAT_0046a660 >> 16);
    unsigned char g = (unsigned char)(DAT_0046a65c >> 16);
    unsigned char b = (unsigned char)(DAT_0046a658 >> 16);
    DAT_004a2afa = r;
    DAT_004a2af9 = g;
    DAT_004a2af8 = b;
    DAT_004a2afc = r + (((b << 8) + g) << 8);
}
}
