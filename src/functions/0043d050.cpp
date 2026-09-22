extern "C" int __cdecl FUN_0040FCE0(void**);
extern "C" void* __cdecl FUN_00435D90(void**, void*, void*);
extern "C" void __cdecl FUN_00434260(void**);
extern "C" void __cdecl GEX_Target(void** gOb) {
    gOb[0x35] = gOb[0x1e];
    gOb[0x36] = gOb[0x1f];
    gOb[0x3f] = gOb[0x1b];
    gOb[0x3d] = gOb[0x14];
    gOb[0x3e] = gOb[0x15];
    gOb[0x39] = 0;
    gOb[0x3a] = 0;
    gOb[0x3b] = 0;
    gOb[0x3c] = 0;
    ((unsigned int*)gOb)[0x38] ^= ((((unsigned int*)gOb)[0x38] * 2 ^ ((unsigned int*)gOb)[0x38]) & 0x200);
    ((unsigned int*)gOb)[0x38] &= 0xfffffeff;
    int iVar1 = FUN_0040FCE0(gOb);
    if (iVar1 == 0) {
        if (gOb[4] != 0) *(void**)(gOb + 4) = FUN_00435D90(gOb, gOb + 4, gOb[4]);
        if (gOb[0xc] != 0) *(void**)(gOb + 0xc) = FUN_00435D90(gOb, gOb + 0xc, gOb[0xc]);
        if (gOb[0x26] != 0) {
            void* yVelocity = (void*)((int)gOb[0x23] + (int)gOb[0x26]);
            gOb[0x23] = yVelocity;
            if ((int)yVelocity >= 0x10000) {
                gOb[0x23] = (void*)((int)yVelocity - 0x10000);
                gOb[0x15] = (void*)((int)gOb[0x15] + 1);
            }
        }
        FUN_00434260(gOb);
    }
    if (gOb[0x45] == (void*)-1) gOb[0x44] = 0;
    gOb[0x45] = (void*)-1;
}
