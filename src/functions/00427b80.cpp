// Repaired from pc_decomp_backup/src/functions/FUN_00427B80.cpp analysis
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" { extern unsigned char DAT_004A0282; }
extern "C" void __cdecl FUN_00414890(void**);
extern "C" void __cdecl FUN_00427A50(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    if (DAT_004A0282 != 0) {
        FUN_00414890(param_1);
        return;
    }
    int state = (int)param_1[0x1c];
    if (state == 0x16 || state == 0x18) {
        param_1[0x29] = (void*)1;
    } else {
        param_1[0x29] = 0;
    }
    param_1[0x1c] = (void*)0x25;
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x28] = 0;
    param_1[0x22] = 0;
    param_1[0x14] = (void*)0x2d;
    FUN_00427A50(param_1);
}
