// Adapted from pc_decomp_backup/src/functions/FUN_00414BB0.cpp
// Historical source SHA256: f5603aea2acb38d69b76ff1bf8e4e54f4b28a253e521ce481d5bd10c511a6512
extern "C" {
extern "C" int __cdecl FUN_00421820_pStateUnk_Duck(void**);
extern "C" int __cdecl FUN_00421560_DrawCharacter(int, void**);
extern "C" void __cdecl FUN_004250B0(void**);
extern "C" void __cdecl FUN_00414A30(void**);
extern "C" void __cdecl FUN_00424B80(void**);
extern "C" void __cdecl FUN_00414E20(void**);
extern "C" void __cdecl FUN_00421900(void**);
extern "C" void __cdecl FUN_004213f0_GexMovementLeftandRight(void*);
extern "C" void __cdecl FUN_004213c0(int, void**);
extern "C" { extern unsigned char DAT_004a0293; }   
extern "C" { extern unsigned char DAT_004a0294; }   
extern "C" { extern unsigned char DAT_004a0295; }   
extern "C" { extern int FUN_004A2990; }
extern "C" { extern int FUN_004A284C; }

extern "C" void __cdecl GEX_Target(void** param_1)
{
    int stateResult = FUN_00421820_pStateUnk_Duck(param_1);
    int drawResult = FUN_00421560_DrawCharacter(FUN_004A2990, param_1);
    if (drawResult == 0) { FUN_004250B0(param_1); return; }
    if (DAT_004a0293 != 0 && DAT_004a0295 == 0) { FUN_00414A30(param_1); return; }
    if (stateResult == 0 && DAT_004a0294 != 0 && DAT_004a0295 == 0) { FUN_00424B80(param_1); return; }
    FUN_004A284C = 1;
    int* p26 = (int*)&param_1[0x26];
    int val = *p26 + 0x8000;
    *p26 = val;
    if (val > 0xffff) {
        *p26 = val - 0x10000;
        int* p15 = (int*)&param_1[0x15];
        (*p15)++;
        if (*p15 > 1) { FUN_00414E20(param_1); return; }
        FUN_00421900(param_1);
    }
    FUN_004213f0_GexMovementLeftandRight(param_1);
    FUN_004213c0(FUN_004A2990, param_1);
}
}
