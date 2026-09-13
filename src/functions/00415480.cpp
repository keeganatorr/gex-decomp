// Adapted from pc_decomp_backup/src/functions/FUN_00415480.cpp
// Historical source SHA256: 2e74341aad49caee6880bbdf955dcb751cc03990a566dd8d97beeb082c2838c9
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void*);
extern "C" { extern int FUN_00456AE0; }
extern "C" { extern int CAMERA_XPos_004a2a38; }
extern "C" { extern int CAMERA_YPos_004a2a1c; }
extern "C" { extern int DAT_004A280C; }
extern "C" { extern int DAT_004A2810; }
extern "C" { extern int DAT_004A0260; }
extern "C" { extern int DAT_00455BFC; }
extern "C" { extern int DAT_00455C00; }
extern "C" { extern int DAT_00455BF4; }
extern "C" { extern int DAT_00455BE4; }
extern "C" { extern int DAT_00455BF8; }
extern "C" { extern int DAT_00455BF0; }
extern "C" { extern int DAT_004A2948; }
extern "C" void __cdecl FUN_0041A250(void*, int, int);
extern "C" void __cdecl FUN_004153E0(void*);
extern "C" void __cdecl FUN_0043F490(int, int, int, int, int, int, int);
extern "C" void __cdecl FUN_004155C0(void*);
extern "C" void __cdecl FUN_00405390(const char*);
extern "C" { extern const char DAT_00458C04[]; }

extern "C" void __cdecl GEX_Target(void* param_1)
{
    FUN_00420BC0(param_1);
    if (FUN_00456AE0 == 0) {
        DAT_004A0260 = 0;
        *(int*)((char*)param_1 + 0x70) = 1;
        *(int*)((char*)param_1 + 0x54) = 0;
        *(int*)((char*)param_1 + 0x9c) = 0;
        *(int*)((char*)param_1 + 0x50) = 0x30;
        *(int*)((char*)param_1 + 0x98) = 0xd;
        DAT_00455BFC = 0;
        DAT_00455C00 = 0;
        *(int*)((char*)param_1 + 0xa8) = 0;
        *(int*)((char*)param_1 + 0xac) = DAT_00455C00 / -13;
        DAT_00455BF4 = DAT_004A280C - CAMERA_XPos_004a2a38;
        DAT_00455BE4 = 1;
        DAT_00455BF8 = DAT_004A2810 - CAMERA_YPos_004a2a1c;
        DAT_00455BF0 = 0;
        DAT_004A2948 = 1;
        FUN_0041A250(param_1, 0x89, 0x80);
        FUN_004153E0(param_1);
        FUN_0043F490(7, 0, 0xff, 0, 0xff, 0, 0xff);
    } else if (FUN_00456AE0 == 1) {
        DAT_004A0260 = 0;
        FUN_004155C0(param_1);
    } else {
        FUN_00405390(DAT_00458C04);
    }
    FUN_00456AE0 = -1;
}
}
