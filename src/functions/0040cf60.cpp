// Adapted from pc_decomp_backup/src/functions/FUN_0040CF60.cpp
// Historical source SHA256: 660df84b88c390e5b2a8565b70298116cbbbfb0695765266edf1f022241d1354
extern "C" {
extern "C" void __cdecl FUN_00419B80(void**, int);
extern "C" void __cdecl FUN_004195D0(int, int, int, int);

extern "C" { extern int DAT_00456018_gex_Init_unk; }
extern "C" { extern int FUN_004A2A7C; }
extern "C" { extern int FUN_004A2994; }
extern "C" { extern int DAT_004a2a04; }
extern "C" { extern void* FUN_004A281C; }
extern "C" { extern int DAT_004561f8; }
extern "C" { extern int CAMERA_YPos_004a2a1c; }
extern "C" { extern int CAMERA_XPos_004a2a38; }
extern "C" { extern int DAT_00462c64; }
extern "C" { extern int DAT_00462c60; }
extern "C" { extern int DAT_00462c74; }
extern "C" { extern int DAT_004561f4; }
extern "C" { extern int DAT_00456208; }
extern "C" { extern void* FUN_004A2AD4; }
extern "C" { extern void** FUN_004A27FC; }

extern "C" void __cdecl GEX_Target(void** gOb)
{
    DAT_00456018_gex_Init_unk = 1;
    FUN_004A2A7C = 1;
    FUN_004A2994 = 0;
    DAT_004a2a04 = 0;
    gOb[0x27] = (void*)0x0;
    gOb[0x28] = (void*)0x0;
    gOb[0x26] = (void*)0x1;
    gOb[0x29] = FUN_004A281C;
    gOb[0x1f] = (void*)(DAT_004561f8 + CAMERA_YPos_004a2a1c + 0x200000);
    gOb[0x1e] = (void*)(CAMERA_XPos_004a2a38 + 0xc60000);
    gOb[0x2c] = (void*)0x640000;
    gOb[0x15] = (void*)0xffffffff;
    gOb[0x2b] = (void*)0x0;
    FUN_00419B80(gOb, 4);
    DAT_00462c64 = 0;
    DAT_00462c60 = 0x25;
    DAT_00462c74 = 9;
    gOb[0x2a] = (void*)0x0;
    DAT_004561f4 = 0x1999;
    FUN_004195D0(1, 0x640000, DAT_00456208, (int)FUN_004A2AD4);
    FUN_004A27FC[0x1b] = (void*)((unsigned int)FUN_004A27FC[0x1b] | 0x80000000);
}
}
