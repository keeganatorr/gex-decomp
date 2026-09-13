// Adapted from pc_decomp_backup/src/functions/FUN_00411B90.cpp
// Historical source SHA256: ef4308a8bedfe65012fffd2efc14d75d5a1de58237e4660d77ca9996cd00e2aa
extern "C" {
extern "C" { extern int DAT_00457F68; }
extern "C" { extern int DAT_00457F6C; }
extern "C" { extern int DAT_004580A8; }
extern "C" { extern int DAT_00458148; }
extern "C" { extern int DAT_0045814C; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00411A90(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar1;
    unsigned int pGVar2;
    unsigned int pGVar3;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x3e;
    param_1[0x14] = (void*)0x4f;
    uVar1 = ((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c | (int)param_1[0x31] >> 0x15;
    param_1[0x26] = 0;
    param_1[0x15] = 0;
    pGVar2 = (unsigned int)param_1[0x1e];
    param_1[0x1e] = (void*)(pGVar2 & 0xffe00000);
    pGVar3 = (unsigned int)(*(int*)((int)&DAT_00457F68 + uVar1 * 8) | (pGVar2 & 0xffe00000));
    pGVar2 = (unsigned int)param_1[0x1f];
    param_1[0x1e] = (void*)pGVar3;
    param_1[0x1f] = (void*)(pGVar2 & 0xffe00000);
    pGVar2 = (unsigned int)(*(int*)((int)&DAT_00457F6C + uVar1 * 8) | (pGVar2 & 0xffe00000));
    param_1[0x1f] = (void*)pGVar2;
    param_1[0x1e] = (void*)((int)((void**)((int***)pGVar3)[0])[0] + *(int*)((int)&DAT_004580A8 + *(int*)((int)&DAT_00458148 + uVar1 * 8) * 0x14) + -0x1c);
    param_1[0x1f] = (void*)((int)((void**)((int***)pGVar2)[0])[0] + *(int*)((int)&DAT_004580A8 + *(int*)((int)&DAT_0045814C + uVar1 * 8) * 0x14) + -0x1c);
    FUN_00411A90(param_1);
}
}
