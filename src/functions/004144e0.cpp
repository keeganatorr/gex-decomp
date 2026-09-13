// Adapted from pc_decomp_backup/src/functions/FUN_004144E0.cpp
// Historical source SHA256: 80fbbbc63e7e416180f02d941fe2ef1cbab37cbcd3fa9e714cfdf1a6af3ccd08
extern "C" {
extern "C" { extern int DAT_0045A6D0; }
extern "C" { extern int DAT_004A025C; }
extern "C" { extern int DAT_004A0280; }
extern "C" { extern int DAT_004A0264; }
extern "C" void __cdecl FUN_00420BC0(void**);
extern "C" void __cdecl FUN_00420960(void**);
extern "C" void __cdecl FUN_004143B0(void**);

extern "C" void __cdecl GEX_Target(void** param_1)
{
    FUN_00420BC0(param_1);
    param_1[0x15] = 0;
    param_1[0x26] = 0;
    param_1[0x1c] = (void*)0x39;
    param_1[0x14] = (void*)0x5a;
    param_1[0x25] = (void*)0x14000;
    param_1[0x24] = (void*)0xe0000;
    param_1[0x21] = (void*)DAT_0045A6D0;
    param_1[0x37] = (void*)0xffe00000;
    DAT_004A025C = 0xffe00000;
    param_1[0x23] = (void*)0x20000;
    param_1[0x20] = 0;
    if (*(unsigned char*)&DAT_004A0280 == 0) {
        if (*(unsigned char*)((int)&DAT_004A0280 + 1) != 0) {
            param_1[0x20] = (void*)0x40000;
        }
    } else {
        param_1[0x20] = (void*)0xfffc0000;
    }
    if (*(unsigned char*)((int)&DAT_004A0280 + 2) == 0) {
        if (*(unsigned char*)((int)&DAT_004A0280 + 3) != 0) {
            param_1[0x23] = (void*)0x40000;
        }
    } else {
        param_1[0x23] = (void*)0x80000;
    }
    if (DAT_004A0264 != 0) {
        param_1[0x20] = (void*)(((int)param_1[0x20] >> 8) * 0x180);
        param_1[0x23] = (void*)(((int)param_1[0x23] >> 8) * 0x180);
    }
    param_1[0x2a] = param_1[0x20];
    param_1[0x2b] = param_1[0x23];
    *(unsigned char*)((int)&DAT_004A0280 + 4) = 0;
    FUN_00420960(param_1);
    FUN_004143B0(param_1);
}
}
