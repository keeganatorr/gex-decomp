// Adapted from pc_decomp_backup/src/functions/FUN_00423B00.cpp
// Historical source SHA256: 29850df032847913ac1e280a12a74fd26fc45e2e833b526db30a8664cb04a11d
extern "C" {
extern "C" { extern int DAT_004a0244; }
extern "C" int __cdecl FUN_00423ab0_AirToFaceCrawl(void**);
extern "C" int __cdecl FUN_00423190_CollisionIntoJumpTailWhack(void**);
extern "C" int __cdecl FUN_004231c0_JumpTongueLash(void**);
extern "C" int __cdecl GEX_Target(void** param1) {
    if (DAT_004a0244 == 0) {
        int iVar1 = FUN_00423ab0_AirToFaceCrawl(param1);
        if (iVar1 != 0) return 1;
    }
    int iVar1 = FUN_00423190_CollisionIntoJumpTailWhack(param1);
    if (iVar1 == 0) {
        iVar1 = FUN_004231c0_JumpTongueLash(param1);
        if (iVar1 == 0) return 0;
    }
    return 1;
}
}
