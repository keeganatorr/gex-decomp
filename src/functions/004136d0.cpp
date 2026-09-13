// Adapted from pc_decomp_backup/src/functions/FUN_004136D0.cpp
// Historical source SHA256: d703e2e792bb0058c5901d91d13df3698ab4c91ae448bfb96d82faf97ee920e9
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" int __cdecl FUN_004218a0_CheckWallCollision(void**);
extern "C" int __cdecl FUN_004206b0(int);
extern "C" void __cdecl FUN_00413600(void**);
extern "C" { extern int DAT_004a0218_pState; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    unsigned int uVar1;
    int iVar2;

    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x4c;  
    param_1[0x14] = (void*)0x4c;
    param_1[0x26] = (void*)0;
    uVar1 = FUN_004218a0_CheckWallCollision(param_1);
    param_1[0x15] = (void*)((unsigned int)(uVar1 == 0) - 1 & 3);
    iVar2 = FUN_004206b0(0x47);
    if (iVar2 == 0) {
        DAT_004a0218_pState = 0x66;
    }
    FUN_00413600(param_1);
}
}
