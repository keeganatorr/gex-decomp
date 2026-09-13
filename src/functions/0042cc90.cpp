// Adapted from pc_decomp_backup/src/functions/FUN_0042CC90.cpp
// Historical source SHA256: c3d18278118cda8de63475bd23374a52f500f1d285fd4c41e5eb80e50ad075a1
extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);
extern "C" { extern int DAT_00455B8C; }
extern "C" { extern int DAT_004A01E4; }
extern int CAMERA_XPos_004a2a38;
extern "C" int __cdecl GEX_Target(void** param1, void (*param2)(void**, int)) {
    if (DAT_00455B8C != 0) {
        int local_28[6];
        int local_10, local_c;
        int iVar1 = FUN_0041CB80(param1, local_28);
        if (iVar1 == 0) return 0;
        if (local_c - CAMERA_XPos_004a2a38 > 0x12fffff) {
            DAT_004A01E4 = 1;
            param1[0x1e] = (void*)((int)param1[0x1e] + (0x12f0000 - (local_c - CAMERA_XPos_004a2a38)));
            if (param2 != 0) param2(param1, 0);
            param1[0x39] = (void*)(CAMERA_XPos_004a2a38 + 0x12f0000);
            if (param1[0x3a] != 0) FUN_0042cc70_Object_unk(0, param1);
        }
        if (local_10 - CAMERA_XPos_004a2a38 < 0x100000) {
            DAT_004A01E4 = 1;
            param1[0x1e] = (void*)((int)param1[0x1e] + (0x110000 - (local_10 - CAMERA_XPos_004a2a38)));
            if (param2 != 0) param2(param1, 0);
            param1[0x3a] = (void*)(CAMERA_XPos_004a2a38 + 0x110000);
            if (param1[0x39] != 0) FUN_0042cc70_Object_unk(0, param1);
        }
    }
    return 0;
}
}
