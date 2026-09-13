// Adapted from pc_decomp_backup/src/functions/FUN_0042B180.cpp
// Historical source SHA256: e7f57379f1520474b2a2b01673920a3d8490e304a8c36a7a79aced143e97ab8f
extern "C" {
extern "C" { extern int DAT_0045ACC8[]; }
extern "C" { extern int DAT_0045ACD0; }
extern "C" { extern int DAT_0045ACF0; }
extern "C" { extern int DAT_0045ACF4; }
extern "C" { extern int DAT_0045AD00; }
extern "C" { extern int DAT_0045AD20; }
extern "C" { extern int DAT_0045AD30[]; }
extern "C" { extern int DAT_0045AD58[]; }
extern "C" { extern int DAT_0045AD80[]; }
extern "C" { extern int DAT_0045ADA8[]; }
extern "C" { extern int DAT_0045ADD0[]; }
extern "C" void __cdecl FUN_0041A360(int, int);
extern "C" unsigned int __cdecl FUN_00428C60(void);
extern "C" void** __cdecl FUN_00429C60(int);
extern "C" void __cdecl FUN_00444590(void**);

extern "C" void __cdecl GEX_Target(void** gOb)
{
    unsigned int uVar2;
    int iVar4;
    void* pGVar1, *pGVar3, *pGVar5;
    void** ppGVar6;

    if ((((unsigned char)(int)gOb[0x2b] & 0xf) == 2) && (((unsigned int)gOb[0x29] & 0xffff) == 0) &&
       ((((int)gOb[0x15] - DAT_0045ACF4) & 7U) == 0)) {
        FUN_0041A360(0x98, 0xff);
    }
    FUN_00444590(gOb);
    uVar2 = (unsigned int)gOb[0x2b] & 0xf;
    if ((uVar2 == 3) || ((uVar2 == 6 && (((unsigned char)((unsigned int)gOb[0x2b] >> 8) & 0xf) == 3)))) {
        pGVar5 = gOb[0x2f];
        pGVar1 = gOb[0x15];
        pGVar3 = (void*)DAT_0045ACC8[((unsigned int)gOb[0x2c] & 0xff3fffff) >> 0x16];
        gOb[0x15] = (void*)0xa5;
        gOb[0x2f] = pGVar3;
        if (gOb[0x26] != (void*)1) gOb[0x15] = (void*)0x97;
        FUN_00444590(gOb);
        pGVar3 = (void*)((int)gOb[0x2c] + 0x8000);
        gOb[0x15] = pGVar1;
        gOb[0x2f] = pGVar5;
        gOb[0x2c] = pGVar3;
        if ((unsigned int)pGVar3 & 0xff000000 > 0x1ffffff) gOb[0x2c] = (void*)((unsigned int)pGVar3 & 0xffff);
    }
    if (((unsigned int)gOb[0x2a] & 0xffff) != 0) {
        pGVar5 = (void*)((int)gOb[0x29] + (((unsigned int)gOb[0x2a] & 0xffff) - 0x1c));
        gOb[0x29] = pGVar5;
        if ((int)((unsigned int)gOb[0x28] & 0xffff0000) < (int)((unsigned int)pGVar5 & 0xffff0000)) {
            pGVar5 = gOb[0x2b];
            uVar2 = (unsigned int)pGVar5 & 0xf;
            if (uVar2 == 2) {
                FUN_0041A360(DAT_0045ADD0[(unsigned int)gOb[0x2c] & 0xf], 0xff);
                gOb[0x2b] = (void*)((unsigned int)gOb[0x2b] & 0xffffff03 | 3);
                pGVar5 = (void*)DAT_0045ACD0;
                gOb[0x29] = pGVar5;
                iVar4 = DAT_0045AD00;
                gOb[0x28] = (void*)((iVar4 + (int)pGVar5 - 0x1d) * 0x10000 | (unsigned int)pGVar5 & 0xffff);
                uVar2 = FUN_00428C60();
                gOb[0x2d] = (void*)((uVar2 & 0x5f) << 0x10);
            } else if (uVar2 == 4) {
                gOb[0x2b] = (void*)((unsigned int)gOb[0x2b] & 0xffffff05 | 5);
                pGVar5 = (void*)DAT_0045ACF0;
                gOb[0x29] = pGVar5;
                iVar4 = DAT_0045AD20 + -0x1d;
                gOb[0x28] = (void*)((iVar4 + (int)pGVar5) * 0x10000 | (unsigned int)pGVar5 & 0xffff);
            } else if (uVar2 == 6) {
                gOb[0x2b] = (void*)((unsigned int)gOb[0x2b] & 0xffffff01 | 1);
                iVar4 = DAT_0045AD00 + DAT_0045ACD0;
                uVar2 = DAT_0045ACD0;
                gOb[0x28] = (void*)((iVar4 + -1) * 0x10000 | uVar2 & 0xffff);
                gOb[0x29] = gOb[0x2d];
                uVar2 = FUN_00428C60();
                gOb[0x2d] = (void*)((uVar2 & 0x5f) << 0x10);
            } else {
                gOb[0x29] = (void*)((int)gOb[0x28] << 0x10);
            }
        }
        if ((((unsigned int)gOb[0x2b] & 0xf) == 3) &&
           (pGVar5 = (void*)((int)gOb[0x2d] - ((unsigned int)gOb[0x2a] & 0xffff)), gOb[0x2d] = pGVar5,
           (int)pGVar5 < (int)((unsigned int)gOb[0x2a] & 0xffff))) {
            ppGVar6 = FUN_00429C60(0xdf);
            if ((((unsigned int)ppGVar6[0x27] ^ (unsigned int)gOb[0x27]) & 0xffff) == 0)
                FUN_0041A360(0x9c, 0xff);
            gOb[0x2d] = gOb[0x29];
            pGVar5 = gOb[0x2b];
            gOb[0x2b] = (void*)((unsigned int)gOb[0x2b] & 0xffffff06 | 6);
            uVar2 = (unsigned int)gOb[0x2c] & 0xf;
            pGVar5 = (void*)(((((int)pGVar5 << 8) ^ (unsigned int)pGVar5) & 0xf00) ^ (unsigned int)pGVar5);
            gOb[0x2b] = pGVar5;
            gOb[0x2b] = (void*)((unsigned int)pGVar5 & 0xffffff06 | 6);
            if (gOb[0x26] == (void*)1) {
                pGVar5 = (void*)DAT_0045AD30[uVar2];
                iVar4 = DAT_0045AD80[uVar2];
            } else {
                pGVar5 = (void*)DAT_0045AD58[uVar2];
                iVar4 = DAT_0045ADA8[uVar2];
            }
            gOb[0x28] = (void*)((iVar4 + (int)pGVar5 - 0x1d) * 0x10000 | (unsigned int)pGVar5 & 0xffff);
        }
        gOb[0x15] = (void*)((int)gOb[0x29] >> 0x10);
    }
}
}
