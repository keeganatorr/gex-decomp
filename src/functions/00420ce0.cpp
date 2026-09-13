// Adapted from pc_decomp_backup/src/functions/FUN_00420CE0.cpp
// Historical source SHA256: 1d28560e4a7d3dff97542eb7c4634438623858869a66b74b21be1ee384d5f4b4
extern "C" {
extern "C" int __cdecl FUN_00420c70_GexWallCollisionInner(void**);
extern "C" { extern int FUN_004A2990; }
extern "C" int __cdecl FUN_0040F170(int, int, int);
extern "C" int __cdecl GEX_Target(void** param1) {
    int uVar1 = FUN_00420c70_GexWallCollisionInner(param1);
    if (uVar1 == 0) return 0;
    int result = 2;
    unsigned int attr = FUN_0040F170(
        FUN_004A2990, (int)param1[0x1e], (int)param1[0x1f]);
    if (attr == 0x52) result = 8;
    return result;
}
}
