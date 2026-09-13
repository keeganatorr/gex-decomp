// Adapted from pc_decomp_backup/src/functions/FUN_00440930.cpp
// Historical source SHA256: fe3ff8f49eac4d2a40dfe73d81cb68f5e42424f6ba726e6d19a4f32939cc1f18
extern "C" {
extern "C" int __cdecl FUN_00402fa0_GetFrameTimingValue();
extern "C" void __cdecl FUN_0043eed0_TvStatic();
extern "C" void __cdecl FUN_0043f080_ResetGraphics_Clean1(int);
extern "C" void __cdecl FUN_0041FC40();
extern "C" void __cdecl FUN_00444800_Tiles(void*, int, int, int, int, int, int);
extern "C" void __cdecl FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(int);
extern "C" void __cdecl FUN_0043DB70(int);
extern "C" { extern int DAT_00460F48; }
extern "C" { extern int DAT_00460F4C; }
extern "C" { extern int DAT_0046BCC8; }
extern "C" { extern int DAT_0046BCD4; }
extern "C" { extern int DAT_0046BCE0; }
extern "C" { extern int DAT_0046BCEC; }
extern "C" { extern unsigned char DAT_004A0284; }
extern "C" void __cdecl GEX_Target() {
    int iVar1 = 0x10000;
    do {
        FUN_00402fa0_GetFrameTimingValue();
        FUN_0043eed0_TvStatic();
        FUN_0043f080_ResetGraphics_Clean1(0);
        FUN_0041FC40();
        FUN_00444800_Tiles(&DAT_0046BCC8, 0, 0, 0xa00000, iVar1, DAT_00460F48, 0x1f001f00);
        FUN_00444800_Tiles(&DAT_0046BCD4, 0xa00000, 0, 0xa00000, iVar1, DAT_00460F48, 0x1f001f00);
        FUN_00444800_Tiles(&DAT_0046BCE0, 0, 0xf00000 - iVar1, 0xa00000, iVar1 + 0x10000, DAT_00460F48, 0x1f001f00);
        FUN_00444800_Tiles(&DAT_0046BCEC, 0xa00000, 0xf00000 - iVar1, 0xa00000, iVar1 + 0x10000, DAT_00460F48, 0x1f001f00);
        iVar1 = iVar1 + (0x780000 - iVar1) / DAT_00460F4C;
        if (iVar1 > 0x76ffff) return;
        FUN_0043f2d0_CheckF3ForUnpauseGameDrawWindow(1);
        FUN_0043DB70(1);
    } while (DAT_004A0284 == 0);
}
}
