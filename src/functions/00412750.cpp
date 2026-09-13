// Adapted from pc_decomp_backup/src/functions/FUN_00412750.cpp
// Historical source SHA256: 930a4afe4efb7c7f4b47ab2438f5349f6160f023f6a6f1898d5aed95ca669462
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00412630(void**);
extern "C" int __cdecl FUN_00420c40_CheckWallCollision(int, unsigned int, unsigned int);
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int FUN_004A2864; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar1;
    unsigned int uVar2;
    
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x47;  
    param_1[0x14] = (void*)0x4e;
    uVar2 = ((unsigned int)param_1[0x1b] & 0x80000000) >> 0x1c | (int)param_1[0x31] >> 0x15;
    param_1[0x26] = (void*)0;
    param_1[0x27] = (void*)0;
    param_1[0x15] = (void*)0;
    if ((((int)param_1[0x31] >> 0x15 & 1U) == 0) && (FUN_004A2864 == 0)) {
        uVar1 = FUN_00420c40_CheckWallCollision(
            FUN_004A2990,
            (unsigned int)((int)param_1[0x1e] + *(int*)((int*)0x004586d8 + uVar2 * 2) * 0x1680),
            (unsigned int)((int)param_1[0x1f] + *(int*)((int*)0x004586dc + uVar2 * 2) * 0x1680));
        if (uVar1 == 0x15) {
            param_1[0x27] = (void*)(uVar2 | 0x10);
        }
    }
    FUN_00412630(param_1);
}
}
