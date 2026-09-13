// Adapted from pc_decomp_backup/src/functions/FUN_00411FF0.cpp
// Historical source SHA256: 227b13076ac6fcf35093227f38422946c4c0755077f33299c3d908cb808d3817
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00411E40(void**);
extern "C" { extern int DAT_00457f68; }
extern "C" { extern int DAT_004583e8; }
extern "C" { extern int DAT_00458488; }
extern "C" void __cdecl GEX_Target(void** param1, int param2, int param3) {
    FUN_00420BC0(param1);
    param1[0x1c] = (void*)0x42;
    param1[0x14] = (void*)0x51;
    unsigned int uVar3 = ((unsigned int)param1[0x1b] & 0x80000000) >> 0x1c | (int)param1[0x31] >> 0x15;
    param1[0x26] = 0;
    param1[0x15] = 0;
    if (param2 == 1) {
        void* pGVar1 = param1[0x1e];
        param1[0x1e] = (void*)((unsigned int)pGVar1 & 0xffe00000);
        param1[0x1e] = (void*)(*(unsigned int*)((int)&DAT_00457f68 + uVar3 * 8) | (unsigned int)param1[0x1e]);
    }
    if (param3 == 1) {
        void* pGVar1 = param1[0x1f];
        param1[0x1f] = (void*)((unsigned int)pGVar1 & 0xffe00000);
        param1[0x1f] = (void*)(*(unsigned int*)((int)&DAT_00457f68 + 4 + uVar3 * 8) | (unsigned int)param1[0x1f]);
    }
    param1[0x1e] = (void*)((int)param1[0x1e] + *(int*)((int)&DAT_004583e8 + *(int*)((int)&DAT_00458488 + uVar3 * 8) * 0x14) + -0x1c);
    int iVar2 = *(int*)((int)&DAT_004583e8 + *(int*)((int)&DAT_00458488 + 4 + uVar3 * 8) * 0x14);
    param1[0x2a] = (void*)param2;
    param1[0x1f] = (void*)((int)param1[0x1f] + iVar2 + -0x1c);
    param1[0x2b] = (void*)param3;
    FUN_00411E40(param1);
}
}
