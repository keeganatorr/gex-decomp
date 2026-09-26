typedef struct RezColours { unsigned short colour[14]; } RezColours;

extern int DAT_0047edb0_Tiles3;
extern int gTimer_004a2ac8;
extern volatile unsigned short DAT_004610a0[16];
void __cdecl GEX_Target(unsigned short *plut)
{
    unsigned short *header;
    unsigned short first;
    header = plut - 2;
    if (gTimer_004a2ac8 != DAT_0047edb0_Tiles3) {
        DAT_0047edb0_Tiles3 = gTimer_004a2ac8;
        first = DAT_004610a0[0];
        DAT_004610a0[0] = DAT_004610a0[1];
        DAT_004610a0[1] = DAT_004610a0[2];
        DAT_004610a0[2] = DAT_004610a0[3];
        DAT_004610a0[3] = first;
        first = DAT_004610a0[4];
        DAT_004610a0[4] = DAT_004610a0[5];
        DAT_004610a0[5] = DAT_004610a0[6];
        DAT_004610a0[6] = DAT_004610a0[7];
        DAT_004610a0[7] = first;
        first = DAT_004610a0[8];
        DAT_004610a0[8] = DAT_004610a0[9];
        DAT_004610a0[9] = DAT_004610a0[10];
        DAT_004610a0[10] = DAT_004610a0[11];
        DAT_004610a0[11] = first;
        first = DAT_004610a0[12];
        DAT_004610a0[12] = DAT_004610a0[13];
        DAT_004610a0[13] = DAT_004610a0[14];
        DAT_004610a0[14] = DAT_004610a0[15];
        DAT_004610a0[15] = first;
    }
    *(RezColours *)(header + 3) = *(RezColours *)(unsigned short *)DAT_004610a0;
    header[1] = 0xffff;
}
