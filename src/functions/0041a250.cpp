// Adapted from pc_decomp_backup/src/functions/FUN_0041A250.cpp
// Historical source SHA256: 243c9b9199487a8a2aabeb36bff34dccdc91e663e908240f041e571888e57acc
extern "C" {
extern "C" void __cdecl FUN_00401B50(int, int, int, int);
extern "C" { extern void* CAMERA_XPos_004a2a38; }
extern "C" { extern void* CAMERA_YPos_004a2a1c; }
extern "C" void __cdecl GEX_Target(void** gOb, int param2, int param3) {
    int iVar2 = (int)gOb[0x1e] - (int)CAMERA_XPos_004a2a38;
    if ((((-0x600000 < iVar2) && (iVar2 < 0x1a00000)) &&
        (-0x400000 < (int)gOb[0x1f] - (int)CAMERA_YPos_004a2a1c)) &&
       ((int)gOb[0x1f] - (int)CAMERA_YPos_004a2a1c < 0x1500000)) {
        iVar2 = (iVar2 + -0xa00000) >> 0x10;
        if (iVar2 < -0x9f) {
            param3 = iVar2 + 0xa0 + param3;
            if (param3 > 0x500) param3 = 0x80;
        } else if (iVar2 > 0x9f) {
            param3 = param3 + (0xa0 - iVar2);
            if (param3 < 0) param3 = 0;
        }
        int iVar1 = 0;
        if (iVar2 < -0x7f) iVar1 = iVar2 + 0x80;
        else if (iVar2 > 0x7f) iVar1 = iVar2 - 0x80;
        if (param3 != 0) FUN_00401B50(param2, iVar1, 0, param3);
    }
}
}
