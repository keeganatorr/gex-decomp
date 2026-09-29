// Adapted from pc_decomp_backup/src/functions/FUN_00414890.cpp
// Historical source SHA256: 81fa79cfaa7d17ffb786424b74f029f1e13937629ab50b66030dcdcfe0a789b7
extern "C" {
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00414710(void**);
extern "C" { extern unsigned char DAT_004A0293; }
extern "C" { extern void** DAT_004A2838; }

extern "C" void __cdecl InitPlayerTongueUp_00414890(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x1c] = (void*)0x27;  
    param_1[0x14] = (void*)0x37;
    param_1[0x15] = (void*)2;
    param_1[0x26] = 0;
    if (DAT_004A0293 == 0 && DAT_004A2838 == 0) {
        param_1[0x27] = 0;
    } else {
        param_1[0x27] = (void*)1;
    }
    param_1[0x28] = 0;
    param_1[0x20] = 0;
    param_1[0x22] = 0;
    FUN_00414710(param_1);
}
}
