// Adapted from pc_decomp_backup/src/functions/FUN_0042CD90.cpp
// Historical source SHA256: e6558f6d0babd0d59a513a3eaa6c8ba5a6fb14fa005bd47620eeebe5fe5ceeea
extern "C" {
extern "C" int __cdecl FUN_0041CB80(void**, int*);
extern "C" void __cdecl FUN_0042cc70_Object_unk(int, void**);
extern "C" { extern int DAT_00455b90; }
extern "C" { extern void* CAMERA_YPos_004a2a1c; }
extern "C" { extern void* CAMERA_XPos_004a2a38; }
extern "C" int __cdecl GEX_Target(void** param1, void* param2) {
    if (DAT_00455b90 == 0) return 0;
    int local[10];
    int iVar1 = FUN_0041CB80(param1, local);
    if (iVar1 == 0) return 0;
    int local_4 = local[8];
    int local_8 = local[9];
    if ((int)(local_4 - (int)CAMERA_YPos_004a2a1c) > 0xefffff) {
        param1[0x1f] = (void*)((int)param1[0x1f] + local_4 - (int)CAMERA_YPos_004a2a1c - 0xf00001);
        if (param2 != 0) ((void(*)(void**,int))param2)(param1, 0);
        param1[0x3b] = (void*)((int)CAMERA_XPos_004a2a38 + 0xf00000);
        if (param1[0x3c] != 0) FUN_0042cc70_Object_unk(0, param1);
    }
    if ((int)(local_8 - (int)CAMERA_YPos_004a2a1c) < 0) {
        param1[0x1f] = (void*)((int)param1[0x1f] - local_8 + (int)CAMERA_YPos_004a2a1c);
        if (param2 != 0) ((void(*)(void**,int))param2)(param1, 0);
        param1[0x3c] = CAMERA_YPos_004a2a1c;
        if (param1[0x3b] != 0) FUN_0042cc70_Object_unk(0, param1);
    }
    return 0;
}
}
