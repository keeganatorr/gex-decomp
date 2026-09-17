extern "C" {
    extern void* FUN_004A33AC;
    extern int DAT_004a2f74_TilesPixelBlue;
    extern int DAT_004a2f7c_TilesPixelGreen;
    extern int DAT_004a2f80_TilesPixelRed;
    extern int DAT_004a2f70_TilesUnk1;
    extern int DAT_004a2fa0_TilesToDrawPointer[256];
    extern unsigned char DAT_004a2b50_TRUETILESMAYBE[1024];
}

extern "C" int GEX_Target(void)
{
    void** ppv = (void**)FUN_004A33AC;
    for (int n = 0x40000; n != 0; n--) {
        *ppv++ = 0;
    }

    DAT_004a2f74_TilesPixelBlue  = -1;
    DAT_004a2f7c_TilesPixelGreen = -1;
    DAT_004a2f80_TilesPixelRed   = -1;
    DAT_004a2f70_TilesUnk1       = -1;

    int* pu = DAT_004a2fa0_TilesToDrawPointer;
    for (int m = 0x100; m != 0; m--) {
        *pu++ = 0;
    }

    unsigned int u = 0;
    do {
        int val = (int)(u & 0x1f) * ((int)u >> 5);
        val = val / 16;
        if (val >= 0x20) val = 0x1f;
        if (val < 0) val = 0;
        DAT_004a2b50_TRUETILESMAYBE[u] = (unsigned char)val;
        u++;
    } while (u != 0x400);

    return 1;
}
