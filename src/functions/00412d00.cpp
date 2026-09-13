// Adapted from pc_decomp_backup/src/functions/FUN_00412D00.cpp
// Historical source SHA256: cd070960194e244bbc65e9b7ae68ac7d9f6289c82b79ccdb39be9d5eb4cef60d
extern "C" {
extern "C" { extern int DAT_00462E80; }
extern "C" { extern int DAT_00458798; }
extern "C" { extern int DAT_0045879C; }
extern "C" { extern int DAT_004587A0; }
extern "C" { extern int DAT_004587A4; }
extern "C" { extern int DAT_004A0218; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_00423A50(void**);
extern "C" void __cdecl FUN_00412B50(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int iVar4, iVar5, iVar6;
    void** pGVar1;
    void** pGVar2;

    FUN_00420BC0(param_1);
    DAT_00462E80 = (int)param_1[0x31];
    param_1[0x1c] = (void*)0x34;
    param_1[0x26] = 0;
    pGVar1 = (void**)param_1[0x1e];
    pGVar2 = (void**)param_1[0x1f];
    param_1[0x14] = (void*)0x45;
    iVar6 = ((((unsigned int)(param_1[0x31]) + 0x1000) & 0xc00000) >> 0x16) * 0x10;
    param_1[0x15] = (void*)0x3;
    iVar4 = *(int*)((int)&DAT_00458798 + iVar6);
    iVar5 = *(int*)((int)&DAT_0045879C + iVar6);
    do {
        param_1[0x1e] = (void*)((int)((void**)((int***)pGVar1)[0])[0] + iVar4 + -0x1c);
        param_1[0x1f] = (void*)((int)((void**)((int***)pGVar2)[0])[0] + iVar5 + -0x1c);
        int iVar3 = FUN_00423A50(param_1);
        if (iVar3 != 0) break;
        iVar4 = iVar4 + *(int*)((int)&DAT_004587A0 + iVar6);
        iVar5 = iVar5 + *(int*)((int)&DAT_004587A4 + iVar6);
    } while (iVar4 != 0 || iVar5 != 0);
    param_1[0x2a] = pGVar1;
    param_1[0x2b] = pGVar2;
    DAT_004A0218 = 0x67;
    FUN_00412B50(param_1);
}
}
