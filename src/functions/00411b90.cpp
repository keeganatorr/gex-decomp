extern "C" {
extern int DAT_00457F68;
extern int DAT_00457F6C;
extern int DAT_004580A8;
extern int DAT_00458148;
extern int DAT_0045814C;
extern void __cdecl FUN_00420BC0(void**);
extern void __cdecl FUN_00411A90(void**);

void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar1;
    unsigned int pGVar2;
    unsigned int pGVar3;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x3e;
    param_1[0x14] = (void*)0x4f;
    uVar1 = (((unsigned int)param_1[0x1b] & 0x80000000) ? 8 : 0) | ((int)param_1[0x31] >> 0x15);
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
    param_1[0x1e] = (void*)(pGVar3 + *(int*)((int)&DAT_004580A8 + *(int*)((int)&DAT_00458148 + uVar1 * 8) * 0x14));
    param_1[0x1f] = (void*)(pGVar2 + *(int*)((int)&DAT_004580A8 + *(int*)((int)&DAT_0045814C + uVar1 * 8) * 0x14));
    FUN_00411A90(param_1);
}
}