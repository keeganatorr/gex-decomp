// Adapted from pc_decomp_backup/src/functions/FUN_004120C0.cpp
// Historical source SHA256: 5184bd033fe2be4ecdd71f58eac8bc4f4e4485cd8d68d9af6e79b3b9d012670b
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_00411E40(void**);
extern "C" { extern int DAT_00457f68; }
extern "C" { extern int DAT_004583e8; }
extern "C" { extern int DAT_00458488; }
extern int FUN_004A2990;
extern "C" void __cdecl GEX_Target(void** param1) {
    FUN_00420BC0(param1);
    param1[0x26] = 0;
    unsigned int uVar3 = ((unsigned int)param1[0x1b] & 0x80000000) >> 0x1c | (int)param1[0x31] >> 0x15;
    param1[0x15] = 0;
    param1[0x1c] = (void*)0x42;
    param1[0x14] = (void*)0x51;
    void* pGVar1 = param1[0x1e];
    param1[0x1e] = (void*)((unsigned int)pGVar1 & 0xffe00000);
    void* pGVar4 = (void*)(*(unsigned int*)((int)&DAT_00457f68 + uVar3 * 8) | ((unsigned int)pGVar1 & 0xffe00000));
    param1[0x1f] = (void*)((int)param1[0x1f] + 0x1000);
    param1[0x1e] = pGVar4;
    param1[0x1e] = (void*)((int)pGVar4 + ((-(unsigned int)(uVar3 == 4) & 0xfffe0000) - 0x1c));
    FUN_00421560_DrawCharacter(FUN_004A2990, param1);
    pGVar1 = param1[0x1f];
    param1[0x1e] = pGVar4;
    param1[0x1f] = (void*)((int)pGVar1 + -0xc00);
    param1[0x1e] = (void*)((int)pGVar4 + *(int*)((int)&DAT_004583e8 + ((int)param1[0x15] + *(int*)((int)&DAT_00458488 + uVar3 * 8) * 5 + -0x1c) * 4) + -0x1c);
    int iVar2 = *(int*)((int)&DAT_004583e8 + ((int)param1[0x15] + *(int*)((int)&DAT_00458488 + 4 + uVar3 * 8) * 5 + -0x1c) * 4);
    param1[0x2a] = 0;
    param1[0x1f] = (void*)((int)param1[0x1f] + iVar2 + -0x1c);
    param1[0x2b] = 0;
    FUN_00411E40(param1);
}
}
