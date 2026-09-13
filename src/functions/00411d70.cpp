// Adapted from pc_decomp_backup/src/functions/FUN_00411D70.cpp
// Historical source SHA256: a88303f8f6ed3b982640942daac9b1e19639652e221bb10d1fe7d5847e0fa1ea
extern "C" {
extern "C" { extern int DAT_00457F68; }
extern "C" { extern int DAT_00457F6C; }
extern "C" { extern int DAT_00458208; }
extern "C" { extern int DAT_004582A8; }
extern "C" { extern int DAT_004582AC; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00411C60(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar3;
    unsigned int pGVar1;
    unsigned int pGVar2;

    uVar3 = ((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c | (int)param_1[0x31] >> 0x15;
    FUN_00420BC0(param_1);
    param_1[0x26] = 0;
    param_1[0x15] = 0;
    param_1[0x1c] = (void*)0x40;
    param_1[0x14] = (void*)0x50;
    pGVar1 = (unsigned int)param_1[0x1e];
    param_1[0x1e] = (void*)(pGVar1 & 0xffe00000);
    pGVar2 = (unsigned int)(*(int*)((int)&DAT_00457F68 + uVar3 * 8) | (pGVar1 & 0xffe00000));
    pGVar1 = (unsigned int)param_1[0x1f];
    param_1[0x1e] = (void*)pGVar2;
    param_1[0x1f] = (void*)(pGVar1 & 0xffe00000);
    pGVar1 = (unsigned int)(*(int*)((int)&DAT_00457F6C + uVar3 * 8) | (pGVar1 & 0xffe00000));
    param_1[0x1f] = (void*)pGVar1;
    param_1[0x1e] = (void*)((int)((void**)((int***)pGVar2)[0])[0] + *(int*)((int)&DAT_00458208 + *(int*)((int)&DAT_004582A8 + uVar3 * 8) * 0x14) + -0x1c);
    param_1[0x1f] = (void*)((int)((void**)((int***)pGVar1)[0])[0] + *(int*)((int)&DAT_00458208 + *(int*)((int)&DAT_004582AC + uVar3 * 8) * 0x14) + -0x1c);
    FUN_00411C60(param_1);
}
}
