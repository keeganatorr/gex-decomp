extern "C" {
extern void *GEX_pGlob_004a2ad4;
extern int gStartDoorID_00456adc;
extern int LEVELID_00455c40;
extern int level_004a2964;
extern void __cdecl GFX_Init_0043f2f0(void);
extern void __cdecl LoadGex_00409880(void);
extern int __cdecl GX_Resolve_004098d0(void);
extern void __cdecl FUN_0040a990_LoadLevel_Clean1(void);
extern void __cdecl M1_EnsureLevelLoaded_0040aa10(void);
extern void __cdecl FUN_0040ab00_EnterMainLoop(void);
extern void __cdecl M1_FreeLevel_0040aa60(void);
void __cdecl FUN_0040ab60_MainGame_Clean1(void)
{
    if (!GEX_pGlob_004a2ad4) {
        GFX_Init_0043f2f0();
        LoadGex_00409880();
        while (!GX_Resolve_004098d0())
            ;
    }
    if (gStartDoorID_00456adc <= 0 || level_004a2964 != LEVELID_00455c40)
        FUN_0040a990_LoadLevel_Clean1();
    M1_EnsureLevelLoaded_0040aa10();
    FUN_0040ab00_EnterMainLoop();
    if (gStartDoorID_00456adc <= 0 || level_004a2964 != LEVELID_00455c40)
        M1_FreeLevel_0040aa60();
}
}
